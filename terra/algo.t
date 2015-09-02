local C = terralib.includec("stdlib.h")
local Cio = terralib.includec("stdio.h")
local math = terralib.includec("math.h")
local time = terralib.includec("sys/time.h")
local jansson = terralib.includec("jansson.h")
local Cstd = terralib.includec("unistd.h")

struct Point { x : double, y : double }

terra Point:add(p2 : Point) : Point
    return Point{self.x + p2.x, self.y + p2.x}
end

terra Point:minus(p2 : Point) : Point
    return Point{self.x - p2.x, self.y - p2.x}
end

terra Point:div(den : double) : Point
    return Point{ (self.x / den), (self.y / den)}
end

terra Point:modulus() : double
	return math.hypot(self.x, self.y)
end

terra Point:equals(p: Point): bool
	return ((self.x == p.x) and (self.y == p.y))
end

struct PointArray { points : &Point; size : int; }

terra PointArray:init(size : int)
	self.points = [&Point](C.malloc(sizeof(Point)*size))
	self.size = size
end

terra PointArray:trim(size: int)
	self.size = size
end

terra PointArray:get(i : int)
	return self.points[i]
end

terra PointArray:set(i : int, p : Point)
	self.points[i] = p
end

terra PointArray:average()
	var temp: Point = Point{0,0}
	for i = 0, self.size do
		temp = temp:add(self.points[i])
	end
	return temp:div(self.size)
end

struct PointMap { keys: &Point; points: &Point, indices: &int; keys_size : int; elems_size : int; }

terra PointMap:init(keys_size : int, elems_size: int)
	self.keys = [&Point](C.malloc(sizeof(Point)*keys_size))
	self.indices = [&int](C.malloc(sizeof(int)*keys_size))
	self.points = [&Point](C.malloc(sizeof(Point)*keys_size*elems_size))
	self.keys_size = keys_size
	self.elems_size = elems_size
end

terra PointMap:get(p: Point)
	for i = 0, self.keys_size do
		if self.keys[i]:equals(p) then
			var tmp: PointArray
			tmp:init(self.indices[i])
			for k = 0, self.indices[i] do
				tmp:set(k, self.points[i*self.elems_size+k])
			end
			tmp:trim(self.indices[i])
			return tmp
		end
	end
end

terra PointMap:setKeys(keys: PointArray)
	for i = 0, keys.size do
		self.keys[i] = keys:get(i)
	end
end

terra PointMap:add(k: Point, p : Point)
	for i = 0, self.keys_size do
		if self.keys[i]:equals(k) then
			self.points[i*self.elems_size+self.indices[i]] = p
			self.indices[i] = self.indices[i] + 1
			break
		end
	end
end


terra dist(p1: Point, p2: Point): double
	return p1:minus(p2):modulus()
end

terra closest(p: Point, pa: PointArray): Point
	var minValue = 0
	var minDist = dist(p, pa:get(0))
	for i = 1, pa.size do
		var thisDist = dist(p, pa:get(i))
		if (thisDist < minDist) then
			minValue = i
			minDist = thisDist
		end
	end
	return pa:get(minValue)
end

terra clusters(xs: PointArray, centroids: PointArray)
	var hm: PointMap
	hm:init(centroids.size, xs.size)
	hm:setKeys(centroids)
	for i = 0, xs.size do
		var p = xs:get(i)
		var clo = closest(p, centroids)
		hm:add(clo, p)
	end
	return hm
end

terra run(xs: PointArray, centroids: PointArray)

	var clus = clusters(xs, centroids)
	for i = 0, centroids.size do
		var ps = clus:get(centroids:get(i))
		var average = ps:average()
		centroids:set(i, average)
		C.free(ps.points)
	end

	return centroids
end

terra main()
    Cio.printf("hello, world\n")
    var p1 = Point{10,11}
    var p2 = Point{1,2}

    var p3 = p1:add(p2)

    --Cio.printf("%f \n", p3.x)
    --Cio.printf("%f \n", p3:modulus())
    --Cio.printf("%f \n", dist(p1,p2))
    --[[
    var pa : PointArray
    pa:init(3)
    pa:set(0, Point{1,1})
    pa:set(1, Point{2,2})
    pa:set(2, Point{3,3})

    var pa2 : PointArray
    pa2:init(3)
    pa2:set(0, Point{0.5,1})
    pa2:set(1, Point{1.5,2})
    pa2:set(2, Point{2.5,3})

    Cio.printf("%f %f %f\n", pa:get(0).x, pa:get(1).x, pa:get(2).x)

    run(pa2, pa)
	]]--

	var file = Cio.fopen("/Users/andrea/workspace/kmeans/points.json", "r")
	var json = jansson.json_loadf(file, 0, nil)

	
	
    var tval_before: &time.timeval = [&time.timeval](C.malloc(sizeof(time.timeval)))
    var tval_after : &time.timeval = [&time.timeval](C.malloc(sizeof(time.timeval)))
    
    time.gettimeofday(tval_before, nil)
    
    time.gettimeofday(tval_after, nil)
    var after_ms = (tval_after.tv_sec*1000) + (tval_after.tv_usec/1000)
    var before_ms = (tval_before.tv_sec*1000) + (tval_before.tv_usec/1000)
    
    var ms = after_ms - before_ms
    Cio.printf("time: %d\n", ms)

    --Cio.printf("%f \n",os.clock())

	--Cio.printf("%f %f %f\n", pa:get(0).x, pa:get(1).x, pa:get(2).x)
end

terralib.saveobj("kmeans", { main = main }) 
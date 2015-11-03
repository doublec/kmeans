use "time"
use "collections"

actor Kmeans
  var xs: Array[Point]
  var centroids: Array[Point]

  new create() =>
    xs = Array[Point]
    centroids = Array[Point]

  fun dist(p1: Point, p2: Point): F64 =>
    (p1 - p2).modulus()

  fun ref average(ys: Array[Point]): Point =>
    var tmp = Point(0,0)
    for p in ys.values() do
      tmp = tmp + p
    end 
    tmp / ys.size().f64()

  fun closest(x: Point, choices: Array[Point]): Point =>
    var tmp = Point(0, 0)
    var min: F64 = U32.max_value().f64()
    for p in choices.values() do
      let tmp_dist = dist(p, x)
      if tmp_dist < min then
        min = tmp_dist
        tmp = p
      end
    end
    tmp

  fun ref clusters(): Map[Point, Array[Point]] =>
    let hm: Map[Point, Array[Point]] = hm.create()
    for c in centroids.values() do
      hm(c) = Array[Point]()
    end

    for p in xs.values() do
      let clo = closest(p, centroids)
      try
        hm.update(clo, hm(clo).push(p))
      else
        hm(clo) = Array[Point]().push(p)
      end
    end

    hm

  be push(p: Point) =>
    xs.push(consume p)

  be run(n: U64, iters: U64, env: Env) =>
    centroids = Array[Point]()
    var j: U64 = 0
    var i: U64 = 0
    while i < n do
      try
        centroids.push(xs(i))
      end
      i = i + 1
    end

    i = 1
    while i <= iters do
      let m = clusters()
      j = 0
      let newCentroids = Array[Point]()
      while j < n do
        try
          newCentroids.push(average(m(centroids(j))))
        end
        j = j + 1
      end

      centroids = newCentroids
      /*
      //To print
      env.out.print("Centroids at step "+i.string())
      for p in centroids.values() do
        env.out.print(p.string())
      end
      env.out.print("\n")
      */
      i = i + 1
    end

  be finish(before: U64, iters: U64, env: Env) =>
    let after = Time.millis()

    env.out.print("Final centroids")
    for p in centroids.values() do
      env.out.print(p.string())
    end

    let t = (after - before) / iters
    env.out.print("Average time is "+ t.string())


use "collections"

class val Point is (Hashable & Equatable[Point])
  let x: F64
  let y: F64

  new val create(x': F64, y': F64) =>
    x = x'
    y = y'

  fun string(): String =>
    "Point{ x: "+x.string( where prec = 16)+", y: "+y.string( where prec = 16)+"}"

  fun add(p: Point): Point =>
    Point(x + p.x, y + p.y)

  fun sub(p: Point): Point => Point(x - p.x, y - p.y)

  fun div(d: F64): Point => Point(x / d , y / d)
    
  fun _sq(v: F64): F64 => v*v

  fun modulus(): F64 => (_sq(x) + _sq(y)).sqrt()

  fun hash(): U64 =>
    x.hash() xor y.hash()

  fun eq(that: Point box): Bool =>
    (x == that.x) and
    (y == that.y)

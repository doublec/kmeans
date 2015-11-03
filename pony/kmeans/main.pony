use "time"
use "json"
use "files"

actor Main
  new create(env: Env) =>
    let kmeans = Kmeans

    let caps = recover val FileCaps.set(FileRead).set(FileStat) end

    var fileString = ""
    try
      with file = OpenFile(FilePath(env.root, "../points.json", caps)) as File do
        for line in file.lines() do
          fileString = fileString + line
        end
      end
    end

    let doc: JsonDoc = JsonDoc
    try
      doc.parse(fileString)

      for el in (doc.data as JsonArray).data.values() do
        let x = ((el as JsonArray).data(0) as F64)
        let y = ((el as JsonArray).data(1) as F64)
        kmeans.push(Point(x, y))
      end
    end

    let n: U64 = 10
    let iters: U64 = 15

    //must be increased to 100
    let iterations: U64 = 100
    let before = Time.millis()

    var i: U64 = 0
    while i < (iterations - 1) do
      kmeans.run(n, iters, env)
      i = i + 1
    end
    kmeans.run(n, iters, env)

    kmeans.finish(before, iterations, env)


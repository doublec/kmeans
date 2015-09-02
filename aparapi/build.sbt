
name := "try_aparapi"

organization := "eu.unicredit"

scalaVersion := "2.11.7"

javaOptions += "-Djava.library.path=./native"

javacOptions += "-g"

fork in run := true

libraryDependencies ++= Seq(
  "org.json4s" %% "json4s-jackson" % "3.2.11"
)

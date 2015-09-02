name := "kmeans-chisel"

organization := "eu.unicredit"

scalaVersion := "2.11.7"

scalacOptions ++= Seq("-feature", "-language:_")

libraryDependencies += "edu.berkeley.cs" %% "chisel" % "2.3-SNAPSHOT"

javaOptions ++= Seq("-Xmx5G", "-Xms1G")

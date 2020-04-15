# Lem-in

This program finds the shortest path from `start` vertice to `end` vertice in a graph.

## Getting Started

### Compiling
Clone the repository
```
git clone --recurse-submodules -j8 git@github.com:zshanabek/lem-in.git 
```
Enter project
```
cd lem-in
```
Compile using Makefile
```
make
```

### Usage

Lem-in reads on STDIN so you can just launch it and write your map:
```
./lem-in
```
or you can redirect an existing map:
```
./lem-in < maps/simple
```

## Example

A map looks like this:
```
3
##start
a 0 0
b 1 1
c 2 0
##end
d 3 1
a-b
b-c
d-e
```

It is composed of three parts:
* **Number of ants**. In this case 3 is number of ants
* **Rooms**. `a` and `b` are rooms
* **Links**. `a-b` is the edge between rooms `a` and `b`



`##start` The beginning of path. In this case `a` is a start room

`##end` The exit from path. In this case `d` is a start room

Comments can be anywhere but you have to specify the start and end rooms by putting the commands `##start` and `##end` before declaring the room.

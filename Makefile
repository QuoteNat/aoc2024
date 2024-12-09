TARGETS := day1a
CXX = g++
CXXFLAGS = -Wall -g
obj_filfes = helper.o
day1a: input
	g++ ${CXXFLAGS} src/day1a.cpp -o build/$@

input:
	cp -r src/input build

build_folder:
	mkdir build

all: ${TARGETS}

run: day1a input
	./build/day1a
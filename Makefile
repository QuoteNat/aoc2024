TARGETS := day1a day1b
CXX = g++
CXXFLAGS = -Wall -g
obj_files = $(wildcard *.c)
day1a: input
	g++ ${CXXFLAGS} src/day1a.cpp -o build/$@

day1b: input
	g++ ${CXXFLAGS} src/$@.cpp -o build/$@

input:
	cp -r src/input build

build_folder:
	mkdir build
%: %.o input build_folder

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

all: ${TARGETS}

run: day1a input
	./build/day1a
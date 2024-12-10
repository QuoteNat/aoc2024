TARGETS := day1a day1b
CXX = g++
CXXFLAGS = -Wall -g
obj_files = $(wildcard *.c)
RUN = day1a
input:
	cp -r src/input build

build_folder:
	mkdir -p build

$(TARGETS): build_folder input
	$(CXX) $(CXXFLAGS) src/$@.cpp src/helper.cpp -o build/$@

all: $(TARGETS) input build_folder

run: $(RUN) input
	./build/$(RUN)
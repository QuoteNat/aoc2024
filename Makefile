TARGETS := day1a day1b day2a day2b day3a
CXX = g++
CXXFLAGS = -Wall -g
RUN = day1a
input:
	cp -r src/input build

build_folder:
	mkdir -p build

$(TARGETS): build_folder input
	$(CXX) $(CXXFLAGS) src/$@.cpp src/helper.cpp -o build/$@

all: $(TARGETS) input build_folder

run: $(RUN) input
	cd build; pwd; ./$(RUN)
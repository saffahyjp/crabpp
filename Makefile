CXX = g++
CXXFLAGS = -std=c++23 -O3 -Iinclude

SOURCES = $(wildcard examples/*.cpp)
EXECUTABLES = $(SOURCES:examples/%.cpp=build/%.exe)

all: $(EXECUTABLES)

.PHONY: all

build/%.exe: examples/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

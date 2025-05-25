# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

# Find all .cpp files
SOURCES := $(wildcard *.cpp)

# Create executables by removing .cpp extension
EXECUTABLES := $(SOURCES:.cpp=)

# Default target
all: $(EXECUTABLES)

# Rule to build each executable from its corresponding .cpp file
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean rule
clean:
	rm -f $(EXECUTABLES)


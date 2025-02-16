# TODO: Continue from : https://www.tutorialspoint.com/cplusplus/index.htm

OBJECTS = virtual-destructor string allocator function

.phony: all clean
all: $(OBJECTS)

virtual-destructor: virtual-destructor.cpp
	g++ -o virtual-destructor virtual-destructor.cpp	

string: string.cpp
	g++ -o string string.cpp

allocator: allocator.cpp
	g++ -o allocator allocator.cpp

function: function.cpp
	g++ -o function function.cpp

clean:
	rm -f $(OBJECTS)
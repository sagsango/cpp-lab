# TODO: Continue from : https://www.tutorialspoint.com/cplusplus/index.htm
CC=g++
OBJECTS = virtual-destructor string allocator function file cast

.phony: all clean
all: $(OBJECTS)

virtual-destructor: virtual-destructor.cpp
	$(CC) -o virtual-destructor virtual-destructor.cpp	

string: string.cpp
	$(CC) -o string string.cpp

allocator: allocator.cpp
	$(CC) -o allocator allocator.cpp

function: function.cpp
	$(CC) -o function function.cpp

file: file.cpp
	$(CC) -o file file.cpp

clean:
	rm -f $(OBJECTS)

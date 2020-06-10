flags = -Wall -Werror

all: bin build bin/geometry

bin/geometry: build/main.o build/circle.o 
	gcc build/main.o build/circle.o -o bin/geometry -lm

build/main.o: src/main.c
	gcc $(flags) -c src/main.c -o build/main.o

build/circle.o: src/circle.c
	gcc $(flags) -c src/circle.c -o build/circle.o

bin:
	mkdir -p bin

build:
	mkdir -p build

clean:
	rm -rf bin/geometry build/.*o

.PHONY: all clean


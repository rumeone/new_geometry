FLAGS = -Wall -Werror


all: bin build bin/geometry bin/test

#src

bin/geometry: build/src/main.o build/src/circle.o build/src/triangle.o build/src/intersection.o
	gcc $(FLAGS) build/src/main.o build/src/circle.o build/src/triangle.o build/src/intersection.o -o bin/geometry -lm

build/src/main.o: src/main.c
	gcc $(FLAGS) -c src/main.c -o build/src/main.o

build/src/circle.o: src/circle.c
	gcc $(FLAGS) -c src/circle.c -o build/src/circle.o

build/src/triangle.o: src/triangle.c
	gcc $(FLAGS) -c src/triangle.c -o build/src/triangle.o

build/src/intersection.o: src/intersection.c
	gcc $(FLAGS) -c src/intersection.c -o build/src/intersection.o

#test

bin/test: build/test/main.o build/test/test.o build/src/circle.o 
	gcc $(FLAGS) build/test/main.o build/test/test.o build/src/circle.o -o bin/test -lm

build/test/main.o: test/main.c
	gcc $(FLAGS) -c test/main.c -o build/test/main.o

build/test/test.o: test/test.c
	gcc $(FLAGS) -c test/test.c -o build/test/test.o

bin:
	mkdir -p bin
	mkdir -p bin

build:
	mkdir -p build/test
	mkdir -p build/src

run: all
	./bin/geometry
	./bin/test

.PHONY: clean all run

clean:
	rm -rf build bin
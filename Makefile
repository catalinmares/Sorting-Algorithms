# The executable file that will be created at the end                 
EXE1 = algo
EXE2 = testbuilder
# The flags to use for compilation                                    
CFLAGS = -Wall -g
# The code compiler to use for compilation                            
CC = g++

INCLUDES = ./includes

all: test

build: build_best

test: $(EXE2)

build_best: build-heap

build_2nd_best: build-tree

build_3rd_best: build-count

$(EXE2): testbuilder.o
	$(CC) $(CFLAGS) $^ -o $(EXE2)

testbuilder.o: testbuilder.cpp
	$(CC) $(CFLAGS) -c $<

build-heap: main-heap algo.o
	$(CC) $(CFLAGS) main.o algo.o -o $(EXE1)

build-count: main-count algo2.o
	$(CC) $(CFLAGS) main.o algo2.o -o $(EXE1)

build-tree: main-tree algo3.o
	$(CC) $(CFLAGS) main.o algo3.o -o $(EXE1)

main-heap: main.cpp
	$(CC) $(CFLAGS) -c $< -DHEAP -I $(INCLUDES)

main-count: main.cpp
	$(CC) $(CFLAGS) -c $< -DCOUNT -I $(INCLUDES)

main-tree: main.cpp
	$(CC) $(CFLAGS) -c $< -DTREE -I $(INCLUDES)

algo.o: algo.cpp
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES)

algo2.o: algo2.cpp
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES)

algo3.o: algo3.cpp
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES)

run:
	./$(EXE1) 0
	./$(EXE1) 1
	./$(EXE1) 2
	./$(EXE1) 3
	./$(EXE1) 4
	./$(EXE1) 5
	./$(EXE1) 6

run-test:
	./$(EXE2)

clean:
	rm -rf *.o $(EXE1) $(EXE2) $(EXE3) $(EXE4)
	rm in/*.in
	rm out/*.out
	rm ref/*.ref
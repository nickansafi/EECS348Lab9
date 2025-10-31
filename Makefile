CC = g++
all: problem1 problem2 problem3 problem4 problem5 problem6 problem7
problem1: problem1.cpp
	$(CC) problem1.cpp -o problem1
problem2: problem2.cpp
	$(CC) problem2.cpp -o problem2
problem3: problem3.cpp
	$(CC) problem3.cpp -o problem3
problem4: problem4.cpp
	$(CC) problem4.cpp -o problem4
problem5: problem5.cpp
	$(CC) problem5.cpp -o problem5
problem6: problem6.cpp
	$(CC) problem6.cpp -o problem6
problem7: problem7.cpp
	$(CC) problem7.cpp -o problem7
clean:
	rm -rf problem1 problem2 problem3 problem4 problem5 problem6 problem7
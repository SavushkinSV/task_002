GC=gcc
FLAGS=-Wall -Wextra -Werror
BUILD=../bin/

all: pascal_triangle pascal_matrix clean

pascal_triangle: pascal_triangle.c
	$(GC) $(FLAGS) pascal_triangle.c -o $(BUILD)pascal_triangle

pascal_matrix: pascal_matrix.c
	$(GC) $(FLAGS) pascal_matrix.c -o $(BUILD)pascal_matrix -lm -g
clean: 
	rm -f *.o

rebuild:
	clean all
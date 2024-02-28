CFLAGS=-Werror -Wextra -Wall 
CC=gcc
FSAN=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector

all: pascal_triangle pascal_matrix

rebuild: clean pascal_matrix

pascal_triangle: pascal_triangle.c
	gcc $(CFLAGS) pascal_triangle.c -o ../bin/pascal_triangle

pascal_matrix: pascal_matrix.c
	gcc $(CFLAGS) pascal_matrix.c -o ../bin/pascal_matrix	

build_fsanitize:
	# gcc $(CFLAGS) $(FSAN) roman_to_arabic.c -o roman_to_arabic.out
	gcc $(CFLAGS) $(FSAN) universal_convert.c -o universal_convert.out

clean:
	rm -rf *.o *.out

check:
	clang-format -n *.c
	# clang-format -n *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	valgrind --tool=memcheck --leak-check=yes ../bin/pascal_matrix

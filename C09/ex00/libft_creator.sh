#!/bin/bash
gcc -Wall -Werror -Wextra -c *.c
ar rcs libft.a *.o
ranlib libft.a

# Imagine your static library (libmylib.a) as a bookshelf:

# Each object file (file1.o, file2.o, etc.) is a book.
# The ar command helps you add or remove books from this shelf.
# The ranlib command creates an index, so you can quickly find the book (object file) you need.

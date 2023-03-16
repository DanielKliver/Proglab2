SRC_DIR = src
LIB_NAME = IntVector.c
APP_NAME = main.c
CC = gcc
CFLAGS = -Wall -o main
all:
		gcc -Wall -o main src/*.c -g

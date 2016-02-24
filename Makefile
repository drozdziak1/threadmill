CC=gcc

CFLAGS=-Wall -g -std=c99

objs=1

all: $(objs)

1: CFLAGS+= -pthread

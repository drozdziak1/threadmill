CC=gcc

CFLAGS=-Wall -g -std=c99

objs=diner

all: $(objs)

diner: CFLAGS+= -pthread -lncurses

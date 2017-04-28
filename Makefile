CC=gcc
CFLAGS=-Wall -O0

all: float_to_fixed_point

float_to_fixed_point: float_to_fixed_point.c
	gcc $(CFLAGS) float_to_fixed_point.c -o float_to_fixed_point

.PHONY clean:
	-rm float_to_fixed_point

C_SOURCES = $(wildcard src/*.c res/*.c)
OBJ = ${C_SOURCES:.c=.o}
CC=~/Programs/gbdk/bin/lcc

all : gb_harvest.gb

build : all

run : all
	mGBA gb_harvest.gb

gb_harvest.gb : $(OBJ)
	$(CC) -Wm-yC -o $@ $^

%.o : %.c
	$(CC) -c -o $@ $<

clean:
	rm res/*.asm
	rm res/*.lst
	rm res/*.sym
	rm res/*.o
	rm src/*.asm
	rm src/*.lst
	rm src/*.sym
	rm src/*.o
	rm *.gb
	rm *.ihx

C_SOURCES = $(wildcard src/*.c res/*.c)
OBJ = ${C_SOURCES:.c=.o}
CC=~/Programs/gbdk/bin/lcc

all : gb_harvest.gbc gb_harvest.pocket

build : all

run : gb_harvest.gbc
	mGBA gb_harvest.gbc

gb_harvest.gbc : $(OBJ)
	$(CC) -Wm-yC -o $@ $^

gb_harvest.pocket : $(OBJ)
	$(CC) -Wm-yC -msm83:ap -o $@ $^

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
	rm *.gbc
	rm *.pocket
	rm *.ihx
	rm *.sav

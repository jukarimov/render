
CC = cc
CFLAGS = -Wall -g
LFLAGS = -lGL -lGLU -lglut

OBJS = \
	butts.o \
	calc.o \
	display.o \
	glutil.o \
	init.o \
	input.o \
	strtools.o

all: main

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LFLAGS)

clean:
	test -f main && rm main *.o || rm *.o

debug:
	gdb ./main --batch --eval-command='run ../shapes/cube.txt'

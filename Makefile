#
# ****Makefile includes switch case CHAPTER*****
#
#

include sources.mk

OBJS = $(SOURCES:.c=.o)
CC = clang #gcc
CFLAGS = -g -Werror
TARGET = program

%.o: %.c
	$(CC) -c -g $< $(INCLUDES) -o $@

program: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET)

#exercise.o: exercise.c create_array.c
#	gcc -c exercise.c create_array.c #exercise.h 


clean:
	rm -f $(OBJS) *.out program

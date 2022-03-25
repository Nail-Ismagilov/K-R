#
#The MAkefile includes switch case CHAPTER
#
#

include sources.mk

OBJS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -g -Werror

%.o: %.c
	$(CC) -c $< $(INCLUDES) -o $@

program: $(OBJS)
	$(CC) -o program $(CFLAGS)  $(INCLUDES) $(OBJS)

#exercise.o: exercise.c create_array.c
#	gcc -c exercise.c create_array.c #exercise.h 


clean:
	rm -f $(OBJS) *.out program

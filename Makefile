#
# ****Makefile includes switch case CHAPTER=* ****
#
#

include sources.mk

OBJS = $(SOURCES:.c=.o)
CC = gcc #clang #gcc
CFLAGS = -g -Werror
TARGET = program
ifeq ($(TARGETS), debug)
TARGET = debug/debug
endif




%.o: %.c
	$(CC) -c -g $< $(INCLUDES) -o $@


build: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET).exe

#exercise.o: exercise.c create_array.c
#	gcc -c exercise.c create_array.c #exercise.h 

.PHONY:clean
clean: 
	rm -f $(OBJS) *.out $(TARGET).exe src/$(CHAPTER)/*.o src/$(CHAPTER)/*.exe


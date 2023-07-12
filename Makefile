#
# ****Makefile includes switch case CHAPTER=* ****
#
#

include sources.mk

OBJS = $(SOURCES:.c=.o)
PRPS = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)

#compiler flags
CC = gcc #clang #gcc
CFLAGS = -Wall -O0 -std=c99 -g
LDFLAGS = -Wl,-Map=$(TARGET).map
TARGET = program
SIZE = size
OBJDUMP = objdump
ifeq ($(TARGETS), debug)
	TARGET = debug/debug
endif



#Build targets
%.i : %.c
	$(CC) -E $< $(CFLAGS) $(INCLUDES)  -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

%.asm : %.c
	$(CC) -S $<  $(CFLAGS) $(INCLUDES)  -o $@

%.d : %.c
	$(CC) -M $< $(CFLAGS) $(INCLUDES)  -o $@


build: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET).exe

.PHONY: all
all: $(OBJS) $(DEPS) $(TARGET).out $(TARGET).asm

$(TARGET).out: $(SOURCES)
	$(CC) $(SOURCES) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $< >> $@

#exercise.o: exercise.c create_array.c
#	gcc -c exercise.c create_array.c #exercise.h 

.PHONY:clean
clean: 
	rm -f src/$(CHAPTER)/$(OBJS) src/$(CHAPTER)/$(PRPS) src/$(CHAPTER)/$(ASMS) src/$(CHAPTER)/$(DEPS) *.out $(TARGET).exe \
	$(TARGET).asm $(TARGET).map src/$(CHAPTER)/*.o src/$(CHAPTER)/*.exe


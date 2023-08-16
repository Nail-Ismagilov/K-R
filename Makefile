#
# ****Makefile includes switch case CHAPTER=* ****
#
# that switch with help "CHAPTER==<CHAPTER_NUMBER>" option
#
# Use: make [CHAPTER_NUMBER]
#
# Build Targets:
#      <FILE>.i - Builds <FILE>.i preprocessor files
#      <FILE>.o - Builds <FILE>.o object files
#      <FILE>.asm - Builds <FILE>.asm assembly files
#      <FILE>.d - Builds <FILE>.d dependency files
#      build - compile all object files and link into a final executable
#      compile-all - compile all object files, but do not link
#      clean - removes all compiled objects,
#              preprocessed outputs, assembly outputs, executibale
#              files and output files
#
#------------------------------------------------------------------------------

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



.PHONY: build
build: $(OBJS) $(DEPS) $(TARGET).out $(TARGET).asm $(TARGET).exe

$(TARGET).out: $(SOURCES)
	$(CC) $(SOURCES) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@
#	$(SIZE) $@

$(TARGET).exe: $(SOURCES)
	$(CC) $(SOURCES) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(TARGET).asm: $(TARGET).exe
	$(OBJDUMP) -d $< >> $@

.PHONY: compile-all
compile-all: $(OBJS) $(PRPS) $(ASMS)

.PHONY:clean
clean: 
	rm -f src/$(CHAPTER)/$(OBJS) src/$(CHAPTER)/$(PRPS) src/$(CHAPTER)/$(ASMS) src/$(CHAPTER)/$(DEPS) *.out $(TARGET).exe \
	$(TARGET).asm $(TARGET).map src/$(CHAPTER)/*.o src/$(CHAPTER)/*.exe

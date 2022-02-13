#Compiler Flags
GCC = gcc
CPPFLAGS = -Wall -Werror -O0  -g
TARGET = demo

%.o: %.c
	$(GCC) -C $< $(CPPFLAGS) -o $@


.PHONY: build
	build: $(TARGET).out

$(TARGET).out: demo.c
	$(GCC) -C $< $(CPPFLAGS) -o $@

.PHONY: clean
clean:
	rm -f demo.out


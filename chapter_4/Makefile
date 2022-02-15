include sources.mk

OBJS = $(SOURCES:.c=.o)


%.o: %.c
	gcc -c $< $(INCLUDES) -o $@

program: $(OBJS)
	gcc -o program $(INCLUDES) $(OBJS)

#exercise.o: exercise.c create_array.c
#	gcc -c exercise.c create_array.c #exercise.h 


clean:
	rm -f $(OBJS) *.out program

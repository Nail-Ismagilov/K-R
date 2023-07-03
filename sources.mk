# Source file
ifeq ($(CHAPTER), 3)
SOURCES = src/chapter3/3-1_binary_search.c\
	  src/chapter3/3-2_switch.c \
	  src/chapter3/3-3_expand.c \
	  src/chapter3/3-4_itoa.c

# Include path
INCLUDES = -I includes/chapter4
endif


ifeq ($(CHAPTER), 4)
SOURCES = 	src/chapter4/main.c \
	  		src/chapter4/create_array.c \
	 		src/chapter4/strrindex.c \
	  		src/chapter4/atof.c \
	  		src/chapter4/polish_calc.c \
	  		src/chapter4/getop.c \
	  		src/chapter4/stack.c \
	  		src/chapter4/reverse.c

# Include path
INCLUDES = -I includes/chapter4 \
			  includes/chapter5
endif

ifeq ($(CHAPTER), 5)
SOURCES = 	src/chapter5/5_1_getint.c \
			src/chapter5/5_2_getfloat.c \
			src/chapter5/exercise_5_3-strcat.c \
			src/chapter5/exercise_5_8.c \
			src/chapter5/getch.c \
			src/chapter5/5_6_Pointer_Arrays.c \
			src/chapter5/allocbuf.c \
			src/chapter5/main.c
	  		 


# Include path
INCLUDES = -I includes/chapter5
endif





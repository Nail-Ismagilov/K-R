# Source file

ifeq ($CHAPTER, 4)
SOURCES = src/chapter4/main.c \
	  src/chapter4/create_array.c \
	  src/chapter4/strrindex.c \
	  src/chapter4/atof.c

# Include path
INCLUDES = -I includes/chapter4
endif

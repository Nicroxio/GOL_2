OBJS = main.c

CC = gcc

COMPILER_FLAGS = -w

LINKER_FLAGS = 

OBJ_NAME = Main

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

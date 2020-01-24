OBJS = main.cpp Controller.cpp Sprite.cpp Graphic.cpp
CC = g++
# -w suppresses all warnings
COMPILER_FLAGS = -std=c++11 -g
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

OBJ_NAME = animation


compile : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run : compile
	./$(OBJ_NAME)

all : compile

debug : compile
	gdb -tui ./$(OBJ_NAME)


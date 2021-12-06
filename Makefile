SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)


all : bin/2048
	./bin/2048

bin/2048 : $(OBJ)
	g++ $^ -o $@ -I include/SDL2 -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

src/%.o : src/%.cpp
	g++ -c $< -o $@ -I include/SDL2 -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
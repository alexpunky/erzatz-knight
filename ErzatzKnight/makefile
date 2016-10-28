CFLAGS=-W -Wall -ansi -pedantic
LIBS=-lsfml-graphics-d -lsfml-window-d -lsfml-system-d -lsfml-audio-d
#LIBS_PATH=-L ../../SFML-2.1/lib
EXEC=ErzatzKnight
BUILD_FOLDER=build
SRC_ROOT=src
SFML_FOLDER=../../SFML-2.1/include
BOOST_FOLDER=../../boost_1_56_0
INC=-I src -I $(SFML_FOLDER) -I $(BOOST_FOLDER)
CC=g++ -Wall -g -std=c++11 $(INC)

all: erzatzKnight

erzatzKnight: ErzatzKnight.o Game.o
	$(CC) -o $(EXEC) $(BUILD_FOLDER)/*.o $(LIBS)

Game.o: $(SRC_ROOT)/Game/Game.cpp SoundEngine.o MenuMode.o ExplorationMode.o
	$(CC) -o $(BUILD_FOLDER)/Game.o $(BUILD_FOLDER)/SoundEngine.o $(BUILD_FOLDER)/MenuMode.o $(BUILD_FOLDER)/ExplorationMode.o -c $(SRC_ROOT)/Game/Game.cpp $(LIBS)

ErzatzKnight.o: Game.o $(SRC_ROOT)/ErzatzKnight.cpp
	$(CC) -o $(BUILD_FOLDER)/ErzatzKnight.o $(BUILD_FOLDER)/Game.o -c $(SRC_ROOT)/ErzatzKnight.cpp  $(LIBS)

MenuMode.o: $(SRC_ROOT)/Game/Modes/MenuMode.cpp
	$(CC) -o $(BUILD_FOLDER)/MenuMode.o -c $(SRC_ROOT)/Game/Modes/MenuMode.cpp $(LIBS)

ExplorationMode.o: Map.o $(SRC_ROOT)/Game/Modes/ExplorationMode.cpp
	$(CC) -o $(BUILD_FOLDER)/ExplorationMode.o $(BUILD_FOLDER)/Map.o -c $(SRC_ROOT)/Game/Modes/ExplorationMode.cpp $(LIBS)

Map.o: Cell.o Character.o ResourceManager.o $(SRC_ROOT)/Game/Exploration/Map.cpp
	$(CC) -o $(BUILD_FOLDER)/Map.o $(BUILD_FOLDER)/Cell.o $(BUILD_FOLDER)/Character.o $(BUILD_FOLDER)/ResourceManager.o -c $(SRC_ROOT)/Game/Exploration/Map.cpp $(LIBS)

Cell.o: $(SRC_ROOT)/Game/Exploration/Cell.cpp
	 $(CC) -o $(BUILD_FOLDER)/Cell.o -c $(SRC_ROOT)/Game/Exploration/Cell.cpp $(LIBS)

Character.o: AnimatedSprite.o Animation.o $(SRC_ROOT)/Game/Characters/Character.cpp
	$(CC) -o $(BUILD_FOLDER)/Character.o $(BUILD_FOLDER)/AnimatedSprite.o $(BUILD_FOLDER)/Animation.o -c $(SRC_ROOT)/Game/Characters/Character.cpp $(LIBS)

SoundEngine.o: $(SRC_ROOT)/Sound/SoundEngine.cpp
	$(CC) -o $(BUILD_FOLDER)/SoundEngine.o -c $(SRC_ROOT)/Sound/SoundEngine.cpp $(LIBS)

ResourceManager.o: $(SRC_ROOT)/Resources/ResourceManager.cpp
	$(CC) -o $(BUILD_FOLDER)/ResourceManager.o -c $(SRC_ROOT)/Resources/ResourceManager.cpp $(LIBS)

Animation.o: $(SRC_ROOT)/Graphics/Animation.cpp
	$(CC) -o $(BUILD_FOLDER)/Animation.o -c $(SRC_ROOT)/Graphics/Animation.cpp $(LIBS)

AnimatedSprite.o: Animation.o $(SRC_ROOT)/Graphics/AnimatedSprite.cpp
	$(CC) -o $(BUILD_FOLDER)/AnimatedSprite.o -c $(SRC_ROOT)/Graphics/AnimatedSprite.cpp $(LIBS)

clean:
	rm -rf $(BUILD_FOLDER)/*.o

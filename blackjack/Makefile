CC = g++
CFLAGS = -Wall -Werror -g -std=c++11
CPP_FILES = card.cpp deck.cpp game.cpp genericplayer.cpp \
			hand.cpp house.cpp main.cpp player.cpp
OBJ_FILES = card.o deck.o game.o genericplayer.o hand.o \
			house.o main.o player.o
HEADER_FILES = card.h common.h deck.h game.h genericplayer.h \
			   hand.h house.h main.h player.h

all: blackjack

# Depend on all cpp files and all header files so we can recompile in case of changes
blackjack: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o blackjack $(OBJ_FILES)

%.o: %.cpp $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o blackjack

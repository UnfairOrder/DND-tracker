# THE NAME OF YOUR EXECUTABLE
TARGET = FinalProject
# ALL CPP COMPILABLE IMPLEMENTATION FILES THAT MAKE UP THE PROJECT
SRC_FILES = main.cpp Character.cpp PlayerClass.cpp DiceRoller.cpp Classes.cpp MeleeWeapon.cpp RangedWeapon.cpp

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++
CXXFLAGS = -Wextra -Werror -pedantic-errors
CXXFLAGS_DEBUG = -g
CXXVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(OS),Windows_NT)
	TARGET := $(TARGET).exe
	DEL = del
	Q =

	INC_PATH = Z:/CSCI200/include/
	LIB_PATH = Z:/CSCI200/lib/

	ARCH = 
	RPATH =
else
	DEL = rm -f
	Q = "

	INC_PATH = /usr/local/include/
	LIB_PATH = /usr/local/lib/

	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CXXFLAGS += -D LINUX
		RPATH =
	endif
	ifeq ($(UNAME_S),Darwin)
		TARGET_MAKEFILE = Makefile.osx
		CXXFLAGS += -D OSX
		RPATH = -Wl,-rpath,/Library/Frameworks
	endif

	UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		ARCH = 
	endif
	ifneq ($(filter %86,$(UNAME_P)),)
		ARCH = 
	endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		ARCH = 
	endif
endif

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(ARCH) -o $@ $^ $(RPATH) -L$(LIB_PATH) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(ARCH) -o $@ -c $< -I$(INC_PATH)

clean:
	$(DEL) $(TARGET) $(OBJECTS)
	
depend:
	@sed -i.bak '/^# DEPENDENCIES/,$$d' Makefile
	@$(DEL) sed*
	@echo $(Q)# DEPENDENCIES$(Q) >> Makefile
	@$(CXX) -MM $(SRC_FILES) >> Makefile

.PHONY: all clean depend

# DEPENDENCIES 
main.o: main.cpp DiceRoller.h Classes.h PlayerClass.h ItemList.hpp \
 MeleeWeapon.h IWeapon.h Item.h RangedWeapon.h Character.h
Character.o: Character.cpp Character.h PlayerClass.h DiceRoller.h
PlayerClass.o: PlayerClass.cpp PlayerClass.h DiceRoller.h
DiceRoller.o: DiceRoller.cpp DiceRoller.h
Classes.o: Classes.cpp Classes.h PlayerClass.h DiceRoller.h
MeleeWeapon.o: MeleeWeapon.cpp MeleeWeapon.h IWeapon.h Item.h
RangedWeapon.o: RangedWeapon.cpp RangedWeapon.h IWeapon.h Item.h

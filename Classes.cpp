#include "Classes.h"

//These should be structs, but I already did all this before learning about them so oh well.

PlayerClass Bard = PlayerClass(
    "Bard",
    "An entertainer by trade and an all around charismatic individual",
    "1d8",
    {"simple weapons"},
    {"light armor"},
    {"any 3"},
    {"Dexterity","Charisma"},
    {"any 3"}
);

PlayerClass Barbarian = PlayerClass(
    "Barbarian",
    "A powerful, feral, and rage driven character.",
    "1d12",
    {"simple weapons","martial weapons"},
    {"light armor","medium armor","sheilds"},
    {},
    {"Strength","Constitution"},
    {"Animal Handling","Athletics"} //This should be pick 2, but I'm just putting this here for now
);

std::vector<PlayerClass> ClassList {Bard,Barbarian};
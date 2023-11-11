#include "Classes.h"



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

std::vector<PlayerClass> ClassList {Bard};
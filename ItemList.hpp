
//Idk if it's possible to put all of these into a single folder and only have to do one include or something
#include "MeleeWeapon.h"
#include "RangedWeapon.h"


extern MeleeWeapon dagger = MeleeWeapon("dagger","A small knife, potentially good for stabbing","finesse","1d4",1.0);
extern RangedWeapon longbow = RangedWeapon("longbow","A bow, longer than average.","Two Handed","1d8",2.0,150,600);
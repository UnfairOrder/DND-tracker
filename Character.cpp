#include "Character.h"

//Race might be replaced with a pbr class
 Character::Character(std::string _name, std::string _race, float _height, int _str, int _dex, int _con, int _wis, int _int, int _level,PlayerClass *Character_Class){
     name = _name;
    race = _race; // This is a possible canidate for a inheritence.
    height = _height;
    setStrength(_str);
    setDexterity(_dex);
    setConstitution(_con);
    setWisdom(_wis);
    setIntelligence(_int);
    int level = _level; //TODO set level function
    //TODO figure out if I'm using the right style guides

    set_max_hp(calculate_max_hp());
}
Character::Character(std::string _name, std::string _race, float _height, bool randomStats = true){
    std::string name = _name;
    std::string race = _race;
    float height = _height;

    //TODO random stats
    //TODO set stats
    level=1;
}
Character::Character(){
    //Initializes the Character as 'an average joe'
    std::string name = "Joe";
    std::string race = "Human";
    float height = 5.5;
    int strength = 10;
    int dexterity = 10;
    int constitution = 10;
    int wisdom = 10;
    int intelligence = 10;    
    level = 1;
    
}

std::string Character::getName()const{
    return name;
}

void Character::setName(std::string _name){
    name = _name;
}

//Strength Getter and Setters

int Character::getStrength()const{
    return strength;
}

void Character:: setStrength(int _str){
    verifyStat(_str);
    strength = _str;
}

int Character::getStr_mod()const{
    return (strength-10)/2;
}

//Dexterity getters and setters

int Character::getDexterity()const{
    return dexterity;
}
void Character::setDexterity(int _dex){
    verifyStat(_dex);
    dexterity = _dex;
}
int Character::getDex_mod()const{
    return (dexterity-10)/2;
}

//Constitution Getters and Setters

int Character::getConstitution() const{
    return constitution;
}
void Character::setConstitution(int _con){
    verifyStat(_con);
    constitution = _con;
}
int Character:: getCon_mod()const{
    return (constitution-10)/2;
}

//Wisdom Getters and Setters

int Character::getWisdom()const{
    return wisdom;
}
void Character::setWisdom(int _wis){
    verifyStat(_wis);
    wisdom = _wis;
}
int Character::getWis_mod()const{
    return (wisdom-10)/2;
}

//Intelligence getters and setters

int Character::getIntelligence()const{
    return intelligence;
}
void Character::setIntelligence(int _int){
    verifyStat(_int);
    intelligence = _int;
}



std::vector<int> generate_stats(){
    srand(time(0));
    rand();
    
    std::vector<int> stats;

    for (int i=0; i<5;i++){ //for five stats
        int stat_total = 0;
        int lowest_roll = 7;

        for(int i=0; i<4; i++){        //roll 4 d6
            int roll = rand()%6 +1;
            if (roll<lowest_roll){
                lowest_roll = roll;
            }
            stat_total+=roll;       // add them up
        }
        stat_total =stat_total-lowest_roll;    // drop the lowest roll

        stats.push_back(stat_total);
    }

}

void verifyStat(int & stat){
    if (stat>30){
        stat=30;
    }
    else if(stat<0){
        stat=0;
    }
}

int Character::calculate_max_hp()const{
    if (level ==1){
        return this->getCon_mod()+CharacterClass.calculate_class_hitpoints(level);
    }
    else{
        return level*this->getCon_mod()+CharacterClass.calculate_class_hitpoints(level);
    }
}

void Character::set_max_hp(int hp){
    if (hp<=0){
        max_hp=1;
    }
    else{
        max_hp=hp;
    }
}

//TODO implement setPlayerClass so that hitpoints are updated whenplayerclass is set.
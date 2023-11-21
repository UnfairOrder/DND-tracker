#include "Character.h"

//Race might be replaced with a pbr class
 Character::Character(std::string _name, std::string _race, float _height, int _str, int _dex, int _con, int _wis, int _int, int _cha, int _level,PlayerClass& _CharacterClass){
    name = _name;
    race = _race; // This is a possible canidate for a inheritence.
    height = _height;
    setStrength(_str);
    setDexterity(_dex);
    setConstitution(_con);
    setWisdom(_wis);
    setIntelligence(_int);
    setCharisma(_cha);
    level = _level; //TODO set level function
    //TODO figure out if I'm using the right style guides
    character_class = _CharacterClass;
    set_max_hp(calculate_max_hp());

    //      CALCULATE PROFICIENCY BONUS
    set_prof_bonus(proficiency_bonus());

    //      POPULATE SKILL LIST
    skill_list["Athletics"] = getStr_mod();
    skill_list["Acrobatics"] = getDex_mod();
    skill_list["Sleight of Hand"] = getDex_mod();
    skill_list["Stealth"] = getDex_mod();
    skill_list["Arcana"] = getInt_mod();
    skill_list["History"] = getInt_mod();
    skill_list["Investigation"] = getInt_mod();
    skill_list["Nature"] = getInt_mod();
    skill_list["Religion"] = getInt_mod();
    skill_list["Animal Handling"] = getWis_mod();
    skill_list["Insight"] = getWis_mod();
    skill_list["Medicine"] = getWis_mod();
    skill_list["Perception"] = getWis_mod();
    skill_list["Survival"] = getWis_mod();
    skill_list["Deception"] = getCha_mod();
    skill_list["Intimidation"] = getCha_mod();
    skill_list["Performance"] = getCha_mod();
    skill_list["Persuasion"] = getCha_mod(); 

    //     SKILL PROFICIENCIES
    // This might be good to make into a function, so that on level up this can be done sepratley
    for (size_t i =0; i<skill_prof.size();i++){
        std::string key = skill_prof[i];
        if (skill_list.count(key)){
            skill_list[key] = skill_list[key] + prof_bonus;
        }
    }

}
Character::Character(std::string _name, std::string _race, float _height, std::vector<int> stat_vector, int _level, PlayerClass& _CharacterClass){
    name = _name;
    race = _race; // This is a possible canidate for a inheritence.
    height = _height;
    setStrength(stat_vector[0]);
    setDexterity(stat_vector[1]);
    setConstitution(stat_vector[2]);
    setWisdom(stat_vector[3]);
    setIntelligence(stat_vector[4]);
    setCharisma(stat_vector[5]);
    level = _level; //TODO set level function
    //TODO figure out if I'm using the right style guides

    character_class = _CharacterClass;


    set_max_hp(calculate_max_hp());


        //      CALCULATE PROFICIENCY BONUS

    set_prof_bonus(proficiency_bonus());

    //      POPULATE SKILL LIST
    skill_list["Athletics"] = getStr_mod();
    skill_list["Acrobatics"] = getDex_mod();
    skill_list["Sleight of Hand"] = getDex_mod();
    skill_list["Stealth"] = getDex_mod();
    skill_list["Arcana"] = getInt_mod();
    skill_list["History"] = getInt_mod();
    skill_list["Investigation"] = getInt_mod();
    skill_list["Nature"] = getInt_mod();
    skill_list["Religion"] = getInt_mod();
    skill_list["Animal Handling"] = getWis_mod();
    skill_list["Insight"] = getWis_mod();
    skill_list["Medicine"] = getWis_mod();
    skill_list["Perception"] = getWis_mod();
    skill_list["Survival"] = getWis_mod();
    skill_list["Deception"] = getCha_mod();
    skill_list["Intimidation"] = getCha_mod();
    skill_list["Performance"] = getCha_mod();
    skill_list["Persuasion"] = getCha_mod(); 

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

Character::Character(const Character& player){
    name = player.getName();
    race = player.get_race(); // This is a possible canidate for a inheritence.
    height = player.get_height();
    setStrength(player.getStrength());
    setDexterity(player.getDexterity());
    setConstitution(player.getConstitution());
    setWisdom(player.getWisdom());
    setIntelligence(player.getIntelligence());
    setCharisma(player.getCharisma());
    set_level( player.get_level() ); 
    //TODO figure out if I'm using the right style guides

    set_max_hp(player.get_max_hp());
}

Character& Character::operator=(const Character& player){

    if(this==&player)return *this;
    // because there's no pointers, copy constructor should work
    *this = Character(player);  //use copy constructor b/c no cleanup required here
    return *this;
}

Character::~Character(){
    //Nothing needed in here.
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
int Character::getInt_mod()const{
    return (intelligence-10)/2;
}

//Charisma getters and setters

int Character::getCharisma()const{
    return charisma;
}

void Character::setCharisma(int _cha){
    verifyStat(_cha);
    charisma = _cha;
}

int Character::getCha_mod()const{
    return(charisma-10)/2;
}


void Character::set_level(int new_level){
    if (new_level<1){
        level = 1;
    }
    else if (new_level>20){
        level=20;
    }
    else{
        level = new_level;
    }
}

void Character::set_prof_bonus(int bonus){
    if (bonus<0){
        bonus=0;
    }
    prof_bonus=bonus;
}



std::vector<int> generate_stats(){
    srand(time(0));
    rand();
    
    std::vector<int> stats;

    for (int i=0; i<6;i++){ //for five stats
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
    return stats;
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

        return (int)(this->getCon_mod())+character_class.calculate_class_hitpoints(level);
    }
    else{
        return level*(this->getCon_mod())+character_class.calculate_class_hitpoints(level);
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

std::string Character::save(){
    std::ofstream saveFile;
    saveFile.open(this->name+".txt");
    if(!saveFile.is_open()){
        std::cerr<<"Failed to open or create savefile";
        return "";
    }
    //      WRITE DATA TO FILE

    saveFile<<this->name<<'\n';
    saveFile<<this->race<<'\n';
    saveFile<<this->height<<'\n';
    saveFile<<this->strength<<'\n';
    saveFile<<this->dexterity<<'\n';
    saveFile<<this->constitution<<'\n';
    saveFile<<this->wisdom<<'\n';
    saveFile<<this->intelligence<<'\n';
    saveFile<<this->charisma<<'\n';
    saveFile<<this->level<<'\n';
    saveFile<<this->character_class.get_name()<<'\n';   //this will need to be populated in load with an if statement

    saveFile.close();

    return this->name;

}
Character* load_Character(std::ifstream& fin){
    std::string name;
    fin>>name;

    std::string race;
    fin >> race;

    float height;
    fin>>height;

    int strength;
    fin >>strength;

    int dexterity;
    fin >> dexterity;

    int constitution;
    fin>>constitution;

    int wisdom;
    fin>>wisdom;

    int intelligence;
    fin>>intelligence;

    int charisma;
    fin>>charisma;

    int level;
    fin>>level;

    PlayerClass PC_char_class;
    std::string character_class;
    fin>>character_class;

    for (size_t i=0; i<ClassList.size();i++){
        if(ClassList[i].get_name()==character_class){
            PC_char_class = ClassList[i];
        }
    }

    Character* character = new Character(name, race, height, strength, dexterity, constitution, wisdom, intelligence, charisma, level, PC_char_class);
    return character;

}

//TODO implement setPlayerClass so that hitpoints are updated whenplayerclass is set.

//Save Character to file
    //if file with character's filename is found, open that.
        //clear out previous contents, write new contents in.
    //if no file is found, create a new file
        //write character information to file

//information to write to file
    //character constructor information
        // name, race, stats, level
            //new line for each, so type conversion is easy
    // other information
        // selected abilities - maybe integer reference to full ability list??
        // money - ints, easy enough
        // inventory - same as selected abilities
        // proficiencies, thought it might be more space efficient to store each individual skill as an int than to create a string that loads each time.
#include <cstdlib>
#include <ctime>
#include <string>



/**
 * @brief calculates a the total of rolling a sided dice 'times' times
 * 
 * @param times number of times the dice is rolled
 * @param sides number of sides on the dice
 * @param advantage boolean for if advantage should be given for each roll. default is false.
 * @return int total number of all dice rolled.
 */
int roll_dice(const int times, const int sides, const bool advantage, const bool dis_adv);
int roll(std::string roll_descriptor);
/**
 * @brief takes a string of form 'xdy' and rolls a y sided dice x times, returning the total
 * 
 * @param roll_descriptor 
 * @return int 
 */
int roll(std::string roll_descriptor, const bool advantage, const bool dis_adv);
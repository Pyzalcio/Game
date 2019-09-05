#ifndef GAME_H
#define GAME_H

#include <string>

void draw_monster(int &hp, int &att, int &def, int lvl);
int draw_action();
void wait_box();
void empty_box();
void super_box();
int run_away(int speed);
bool fight(int &hp, int att, int def, int &char_hp, int char_att, int char_def, int &pkt, std::string name, int &level);
int monster(int &char_hp, int char_att, int char_def, int &point, std::string name, int &lvl, int speed);

int game(int &char_hp, int char_att, int char_def, int &points, std::string name, int &level, bool &finish, int speed);


#endif // GAME_H

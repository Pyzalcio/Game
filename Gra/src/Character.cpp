#include "Character.h"

Character::Character()
{
    //ctor
}

Character::~Character()
{
    //dtor
}

Wizard::Wizard(string n)
{
    type="(czarodziej)";
    name=n;
    maxhp=80;
    hp=maxhp;
    att=8;
    def=5;
    luck=10;
    esc=5;
}

Wizard::~Wizard()
{

}

Strong::Strong(string n)
{
    type="(silny)";
    name=n;
    maxhp=100;
    hp=maxhp;
    att=10;
    def=8;
    luck=2;
    esc=2;
}

Strong::~Strong()
{

}

Clever::Clever(string n)
{
    type="(sprytny)";
    name=n;
    maxhp=90;
    hp=maxhp;
    att=5;
    def=5;
    luck=5;
    esc=10;
}

Clever::~Clever()
{

}

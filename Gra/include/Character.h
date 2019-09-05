#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character
{
    public:

        int maxhp, hp, att, def, luck, esc, level=0;
        string name, type;

        Character();
        virtual ~Character();

    protected:

    private:
};

class Wizard : public Character
{
    public:
    Wizard(string n);
    ~Wizard();
};

class Strong : public Character
{
    public:
    Strong(string n);
    ~Strong();
};

class Clever : public Character
{
    public:
    Clever(string n);
    ~Clever();
};

#endif // CHARACTER_H

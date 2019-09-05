#include "game.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void draw_monster(int &hp, int &att, int &def, int lvl)
{
    srand(time(NULL));
    hp = (rand()%50)+50+lvl*5;
    //hp=140;
    att = (rand()%10)+1+lvl;
    //att=6;
    def = (rand()%10)+1+lvl;
    //def=11;
    cout<<"Twoj przeciwnik:"<<endl;
    cout<<"Wytrzymalosc: "<<hp<<"hp"<<endl;
    cout<<"Sila ataku: "<<att<<endl;
    cout<<"Samoobrona: "<<def<<endl;
}
int draw_action()
{
    srand(time(NULL));
    return rand()%3;
}
void wait_box()
{
    int t = (rand()%4)+1;
    srand(time(NULL));
    for(int i=0; i<t; i++)
    {
        cout<<"Otwieranie skrzyni."<<endl;
        Sleep(300);
        system("cls");
        cout<<"Otwieranie skrzyni.."<<endl;
        Sleep(300);
        system("cls");
        cout<<"Otwieranie skrzyni..."<<endl;
        Sleep(300);
        system("cls");
    }
}
void empty_box()
{
    cout<<"Znaleziono skrzynie skarbow!"<<endl;
    Sleep(1000);
    wait_box();
    cout<<endl<<"Skrzynia pusta..."<<endl;
    getch();
    system("cls");
}
void super_box(int &point)
{
    cout<<"Znaleziono skrzynie skarbow!"<<endl;
    Sleep(1000);
    wait_box();
    cout<<endl<<"Zebrano 1 punkt treningu !"<<endl;
    point++;
    getch();
    system("cls");
}
int run_away(int speed)
{
    srand(time(NULL));
    int t = (rand()%6)+1;
    int success=1;
    for(int i=0; i<t; i++)
    {
        cout<<"Proba ucieczki."<<endl;
        Sleep(300);
        system("cls");
        cout<<"Proba ucieczki.."<<endl;
        Sleep(300);
        system("cls");
        cout<<"Proba ucieczki..."<<endl;
        Sleep(300);
        system("cls");
    }
    t=rand()%(speed/2);
    if(t!=0)
        cout<<"Udalo sie uciec !"<<endl;
    else
    {
        cout<<"Ucieczka nie udana. Nie zyjesz..."<<endl;
        success=0;
    }

    Sleep(1000);
    getch();
    return success;
}
bool fight(int &hp, int att, int def, int &char_hp, int char_att, int char_def, int &pkt, string name, int &level)
{
    system("cls");
    int power;
    srand(time(NULL));
    int t = rand()%2;
    bool win=true;
    while(hp>0 && char_hp>0)
    {
        cout<<"\t\tTwoj przeciwnik\t\tvs\t"<<name<<endl;
        cout<<"Wytrzymalosc:\t\t"<<hp<<"hp\t\t\t"<<char_hp<<"hp"<<endl;
        cout<<"Sila ataku:\t\t"<<att<<"\t\t\t"<<char_att<<endl;
        cout<<"Samoobrona:\t\t"<<def<<"\t\t\t"<<char_def<<endl;

        if(char_att<=def && att<=char_def)
        {
            int x=def-char_att;
            int y=char_def-att;
            if(x>y)
            {
               char_hp-=3;
               hp-=2;
            }
            else
            {
                hp-=3;
                char_hp-=2;
            }
        }
        if(t==0)
        {
            power=att-char_def;
            if(power>0)
                char_hp-=power;
            if(char_hp<=0)
            {
                char_hp=0;
                win=false;
            }
            t=1;
        }
        else if(t==1)
        {
            power=char_att-def;
            if(power>0)
                hp-=char_att;
            if(hp<=0)
            {
                hp=0;
                win=true;
            }
            t=0;
        }
        Sleep(200);
        system("cls");
    }
    cout<<"\t\tTwoj przeciwnik\t\tvs\t"<<name<<endl;
    cout<<"Wytrzymalosc:\t\t"<<hp<<"hp\t\t\t"<<char_hp<<endl;
    cout<<"Sila ataku:\t\t"<<att<<"\t\t\t"<<char_att<<endl;
    cout<<"Samoobrona:\t\t"<<def<<"\t\t\t"<<char_def<<endl;

    if(hp==0 && char_hp>0)
    {
        cout<<endl<<"Wygrana!"<<endl;
        cout<<"Zdobywasz 1 punkt treningu!"<<endl;
        pkt++;
        level++;
        win=true;
    }
    else if(char_hp==0 && hp>0)
    {
        cout<<endl<<"Przerales..."<<endl;
        cout<<"Nie zyjesz. Koniec gry."<<endl;
        win=false;
    }
    else
    {
        cout<<"Chyba zostaliscie przyjaciolmi... graj dalej..."<<endl;
        win=true;
    }

    Sleep(2000);
    getch();
    return win;
}
int monster(int &char_hp, int char_att, int char_def, int &point, string name, int &lvl, int speed)
{
    int m_hp, m_att, m_def;
    int finish=0;
    char to_do=5;
    bool what_do=false;
    draw_monster(m_hp, m_att, m_def, lvl);
    Sleep(1000);
    cout<<endl<<"Chcesz walczyc z potworem?"<<endl;
    cout<<"1. Tak, walczmy!"<<endl;
    cout<<"2. Nie, uciekam!"<<endl;
    while(!what_do)
    {
        to_do=getch();
        switch(to_do)
        {
        case '1':
            if(!fight(m_hp, m_att, m_def, char_hp, char_att, char_def, point, name, lvl))
            {
                finish=1;
            }
            what_do=true;
            break;
        case '2':
            if(run_away(speed)==0)
            {
                finish=1;
            }
            what_do=true;
            break;
        default:
            cout<<"Musisz wybrac opcje 1 lub 2 !"<<endl;
            break;
        }
    }

    system("cls");
    return finish;
}
int game(int &char_hp, int char_att, int char_def, int &points, string name, int &level, bool &finish, int speed)
{
    finish=false;
    char esc=0;
    int i=0;
    while(!finish && esc!=27)
    {
        cout<<"Nacisnij przycisk, aby szukac skarbow"<<endl;
        cout<<"Aby zakonczyc poszukiwania, wcisnij klawisz 'ESC'"<<endl;
        esc=getch();
        if(esc==27) break;
        system("cls");
        //switch(draw_action())
        switch(2)
        {
        case 0:
            empty_box();
            break;
        case 1:
            super_box(points);
            break;
        case 2:
            if(monster(char_hp, char_att, char_def, points, name, level, speed)==1)
            {
                finish=true;
            }
            break;
        }
    }

    //return 0;
}

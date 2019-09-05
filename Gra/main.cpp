#include <iostream>
#include <conio.h>
#include <windows.h>

#include "Character.h",
#include "game.h"

using namespace std;

Character **character = new Character*[3];

void start(char &x)
{
    while(x!='0' && x!='1' && x!='2' && x!='3')
    {
        system("cls");
        cout<<"Wybierz swoja postac:"<<endl;
        cout<<"1. Czarodziej"<<endl;
        cout<<"2. Silacz"<<endl;
        cout<<"3. Spryciarz"<<endl;
        cout<<"0. Wyjscie"<<endl<<endl;

        x=getch();
        if(x=='1' || x=='2' || x=='3')  cout<<"Wybrano: ";
        switch(x)
        {
        case '1':
            cout<<"Czarodziej"<<endl;
            Sleep(1000);
            break;
        case '2':
            cout<<"Silacz"<<endl;
            Sleep(1000);
            break;
        case '3':
            cout<<"Sprytny"<<endl;
            Sleep(1000);
            break;
        case '0':
            cout<<"Koniec gry"<<endl;
            Sleep(1000);
            break;
        default:
            cout<<"Porsze wybrac postac (1-3) lub wyjsc z gry (0)"<<endl;
            Sleep(1000);
            break;
        }
    }
    system("cls");
}
void new_char(char &x)
{
    int maxhp, att, def, luck, esc;
    string name;
    cout<<"Podaj imie postaci: ";
    cin>>name;
    cout<<endl<<name<<" ";
    switch(x)
    {
    case '1':
        character[0] = new Wizard(name);

        break;
    case '2':
        character[0] = new Strong(name);
        break;
    case '3':
        character[0] = new Clever(name);
        break;
    }
    cout<<character[0]->type<<" - statystyki:"<<endl;
    cout<<"Maksymalne zycie: "<<character[0]->maxhp<<"hp"<<endl;
    cout<<"Atak: "<<character[0]->att<<endl;
    cout<<"Obrona: "<<character[0]->def<<endl;
    cout<<"Szczescie: "<<character[0]->luck<<endl;
    cout<<"Ucieczka: "<<character[0]->esc<<endl;

    cout<<endl<<"Wcisnij przycisk, aby kontynuowac";
    getch();
    system("cls");
}

void training(int &n)
{
    int x=1;

    while(x!='0')
    {
        cout<<character[0]->name<<" "<<character[0]->type<<" - statystyki:"<<endl;
        cout<<"Maksymalne zycie: "<<character[0]->maxhp<<"hp"<<endl;
        cout<<"Atak: "<<character[0]->att<<endl;
        cout<<"Obrona: "<<character[0]->def<<endl;
        cout<<"Szczescie: "<<character[0]->luck<<endl;
        cout<<"Ucieczka: "<<character[0]->esc<<endl;
        cout<<"Liczba punktow: "<<n<<endl<<endl;

        cout<<"1. Trenuj wytrzymalosc (hp)"<<endl;
        cout<<"2. Trenuj sile ataku"<<endl;
        cout<<"3. Trenuj samoobrone"<<endl;
        cout<<"4. Trenuj szybkosc (ucieczka)"<<endl;
        cout<<"0. Powrot"<<endl;

        x=getch();
        switch(x)
        {
        case '1':
            if(n!=0)
            {
                n--;
                character[0]->maxhp+=5;
                cout<<"Wytrzymalosc wzrosla do "<<character[0]->maxhp<<"hp!"<<endl;
            }
            else    cout<<endl<<"Nie masz wystarczajacej ilosci punktow treningu!"<<endl;

            Sleep(1000);
            getch();
            break;
        case '2':
            if(n!=0)
            {
                n--;
                character[0]->att+=1;
                cout<<"Sila ataku wzrosla do "<<character[0]->att<<"!"<<endl;
            }
            else    cout<<endl<<"Nie masz wystarczajacej ilosci punktow treningu!"<<endl;

            Sleep(1000);
            getch();
            break;
        case '3':
            if(n!=0)
            {
                n--;
                character[0]->def+=1;
                cout<<"Samoobrona wzrosla do "<<character[0]->def<<"!"<<endl;
            }
            else    cout<<endl<<"Nie masz wystarczajacej ilosci punktow treningu!"<<endl;

            Sleep(1000);
            getch();
            break;
        case '4':
            if(n!=0)
            {
                n--;
                character[0]->esc+=1;
                cout<<"Szybkosc wzrosla do "<<character[0]->esc<<"!"<<endl;
            }
            else    cout<<endl<<"Nie masz wystarczajacej ilosci punktow treningu!"<<endl;

            Sleep(1000);
            getch();
            break;
        case '0':
            break;
        default:
            cout<<"Porsze wybrac postac (1-3) lub wyjsc z gry (0)"<<endl;
            Sleep(1000);
            break;
        }
        system("cls");
    }
}
void rest()
{
    char exit;
    for(int i=character[0]->hp; i<character[0]->maxhp; i++)
    {
        cout<<"Wytrzymalosc: "<<character[0]->hp<<endl;
        cout<<"Wcisnij 'ESC' aby zakonczyc odpoczynek"<<endl;
        if (kbhit())
        {
            exit = getch();
            if (exit == 27) break;
        }
        character[0]->hp++;
        Sleep(1000);
        system("cls");
    }
}
void stats(int &pts)
{
    int x=1;
    while(x!='0')
    {
        cout<<character[0]->name<<" "<<character[0]->type<<" - statystyki:"<<endl;
        cout<<"Poziom: "<<character[0]->level<<endl;
        cout<<"Maksymalne zycie: "<<character[0]->maxhp<<"hp"<<endl;
        cout<<"Atak: "<<character[0]->att<<endl;
        cout<<"Obrona: "<<character[0]->def<<endl;
        cout<<"Szczescie: "<<character[0]->luck<<endl;
        cout<<"Ucieczka: "<<character[0]->esc<<endl;
        cout<<"Liczba punktow: "<<pts<<endl;

        cout<<endl<<"1. Trenuj postac"<<endl;
        cout<<"0. Powrot"<<endl;
        x=getch();
        switch(x)
        {
        case '1':
            system("cls");
            training(pts);
            system("cls");
            break;
            break;
        case '0':
            Sleep(1000);
            break;
        }
    }
}

void admin()
{
    string password="";
    int sil, obr, szyb, spr, lvl, xhp;
    cout<<"Podaj haslo: ";
    cin>>password;
    if(password=="Polska123")
    {
        cout<<"Sila: ";
        cin>>sil;
        cout<<"Obrona: ";
        cin>>obr;
        cout<<"Szybkosc: ";
        cin>>szyb;
        cout<<"Szczescie: ";
        cin>>spr;
        cout<<"Poziom: ";
        cin>>lvl;
        cout<<"Max hp: ";
        cin>>xhp;
        character[0]->att=sil;
        character[0]->def=obr;
        character[0]->luck=spr;
        character[0]->esc=szyb;
        character[0]->level=lvl;
        character[0]->maxhp=xhp;
    }
}
void menu()
{
    int points=2;
    char x='1';
    bool game_over=false;
    while(x!='0')
    {
        cout<<"1. Poszukiwania skarbow"<<endl;
        cout<<"2. Sprawdz statystyki"<<endl;
        cout<<"3. Odpocznij, aby zregenerowac sily"<<endl;
        cout<<"0. Wyjscie z gry"<<endl;

        x=getch();
        switch(x)
        {
        case '1':
            system("cls");
            game(character[0]->hp, character[0]->att, character[0]->def, points, character[0]->name, character[0]->level, game_over, character[0]->esc);
            if(game_over)
            {
                x='0';
            }
            break;
        case '2':
            system("cls");
            stats(points);
            break;
        case '3':
            system("cls");
            rest();
            break;
        case '9':
            system("cls");
            admin();
            break;
        case '0':
            system("cls");
            char y;
            cout<<"Czy na pewno chcesz wyjsc z gry? Niezapisany postep zostanie skasowany"<<endl;
            cout<<"1. Tak, koncze gre"<<endl;
            cout<<"2. Nie, gram dalej"<<endl;
            y=getch();
            if(y=='1')
            {
                system("cls");
                cout<<"Koniec gry"<<endl;
                Sleep(1000);
            }
            else x=1;
            break;
        default:
            cout<<"Porsze wybrac opcje 1-2 lub wyjsc z gry (0)"<<endl;
            Sleep(1000);
            break;
        }
        system("cls");
    }
}
int main()
{
    char my_choose=5;
    start(my_choose);
    new_char(my_choose);
    menu();

    system("cls");
    cout<<"Koniec gry. Koncowe statystyki:"<<endl<<endl;
    cout<<character[0]->name<<" "<<character[0]->type<<" - statystyki:"<<endl;
    cout<<"Poziom: "<<character[0]->level<<endl;
    cout<<"Maksymalne zycie: "<<character[0]->maxhp<<"hp"<<endl;
    cout<<"Atak: "<<character[0]->att<<endl;
    cout<<"Obrona: "<<character[0]->def<<endl;
    cout<<"Szczescie: "<<character[0]->luck<<endl;
    cout<<"Ucieczka: "<<character[0]->esc<<endl;

    getch();

    return 0;
}

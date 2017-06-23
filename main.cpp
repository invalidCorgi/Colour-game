#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace sf;
using namespace std;

#include "postac.h"
#include "plansza.h"
#include "napis.h"
#include "licz_czasu.h"
#include "struktury_funkcje.h"

int main()
{
    #include "deklaracje.h"

    while(window.isOpen())
    {
        #include "eventy.h"

        switch(proba)
        {
        case 0: //pomoc
            #include "case0.h"
        case 1: //gra
            #include "case1.h"
        case 2: //koniec gry
            #include "case2.h"
        case 3: //1 menu - wejscie do gry
            #include "case3.h"
        case 4: //2 menu - pomoc
            #include "case4.h"
        case 5: //3 menu - opcje
            #include "case5.h"
        case 6: //4 menu - najlepsze wyniki
            #include "case6.h"
        case 7: //5 menu - wyjscie z gry
            #include "case7.h"
        case 8: //opcje - 1 opcja - dzwiek
            #include "case8.h"
        case 9: //opcje - 2 opcja - trudnosc si
            #include "case9.h"
        case 20: //najlepsze wyniki - 1 opcja
            #include "case20.h"
        case 30: //wejscie do gry - 1 opcja - pojedynczy gracz
            #include "case30.h"
        case 31: //wejscie do gry - 2 opcja - przeciwko si
            #include "case31.h"
        }
        spacja=0;   //odwolanie nacisniecia spacji wykorzystywanej podczas gry
    }
}

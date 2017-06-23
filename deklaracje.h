using namespace sf;
using namespace std;

SoundBuffer buffer1;
if (!buffer1.loadFromFile("beep.wav"))
    return -1;

Sound sound1;
sound1.setBuffer(buffer1);  //dzwiek przy zdobyciu punktu

SoundBuffer buffer2;
if (!buffer2.loadFromFile("Sad_Trombone.wav"))
    return -1;

Sound sound2;
sound2.setBuffer(buffer2);  //dzwiek przy przegranej

srand(time(0)); //zerowanie czasu preprocesora

Wynik wyniki[5];
for(int i=0; i<5; i++)
{
    wyniki[i].imie="non-user";
    wyniki[i].wynik=0;
}

int bestPosition[2];
float bestDistance=100;
int kolor=rand()%7; //inicjowanie zmiennych calkowitych
int score=0;
int postacXplansza; //na ktorej czesci planszy stoi postac
int postacYplansza;
int postacSIXplansza; //na ktorej czesci planszy stoi SI
int postacSIYplansza;
int szerOkna=800;
int wysOkna=600;
int previousState=0;    //ostatnio nacisniety przycisk na klawiaturze
int bscore=0;
int bescore=0;
int tempScore;
int proba=3;
int iDzwiek=1;
int difficulty=3;
bool spacja=0;
bool SI=1;
bool gameWithSi;

Sprite menu;
Texture tekstura0;
tekstura0.loadFromFile("menu.png");
menu.setTexture(tekstura0);

Sprite strzalki;
Texture tekstura6;
tekstura6.loadFromFile("strzalki.png");
strzalki.setTexture(tekstura6);

Color purple(128,0,128);    //inicjowanie dodatkowych kolorow
Color grey(155,155,155);
Color rozowy(255,0,255);
Color brown(150,75,0);
//Color grey2(55,55,55);
Color grey2(0,0,0);

string napisy[7]; //tablica nazw kolorow wyswietlanych na gornym pasku
string str;
string imie="";
string smieci;
ostringstream ss;

napisy[0]="GREEN";
napisy[1]="PURPLE";
napisy[2]="YELLOW";
napisy[3]="BLUE";
napisy[4]="RED";
napisy[5]="WHITE";
napisy[6]="BROWN";

Postac postac(355,505,grey);
Postac postacSI(405,505,Color::Black);

Napis napis(napisy[kolor],350,0,rozowy);    //napis do gory z aktualnym kolorem
Napis wynik("Wynik: 0",350,50,rozowy);      //napis pod gornym zawierajacy aktualny wynik
Napis rekord2("Najlepszy wynik tej gry: 0", 400, 555, Color::White);    //najlepszy wynik aktualnej gry w prawym dolnym rogu

fstream plik;
plik.open("hs.txt", ios::in);   //plik z najlepszym wynikiem
string rekord="0";
if(plik.good())
{
    plik>>rekord;   //wczytanie rekordu z pliku
    bescore = atoi(rekord.c_str());
    plik>>smieci;
    plik>>smieci;
    for(int i=0; i<5; i++)
    {
        plik>>wyniki[i].imie;   //wczytanie wynikow
        smieci="";
        plik>>smieci;
        wyniki[i].wynik = atoi(smieci.c_str());
    }
}
plik.close();
//bscore=wyniki[1].wynik;

plik.open("settings.txt", ios::in);   //plik z ustawieniami
string dzwiek;
string sDifficult="3";
if(plik.good())
{
    plik>>dzwiek;   //wczytanie ustawien dzwieku
    iDzwiek = atoi(dzwiek.c_str());
    plik>>smieci;
    plik>>sDifficult;      //wczytanie ustawien poziomu trudnosci
    difficulty = atoi(sDifficult.c_str());
}
plik.close();

//----------------------------napisy

Napis bestScores("Najlepsze wyniki", 75,20, Color::White);
bestScores.zmienRozmiar(52);
Napis nImie(imie, 100,400, Color::White);
Napis imie1("1   -   "+wyniki[0].imie, 100,150, Color::White);
imie1.zmienRozmiar(25);
ostringstream ss1;
ss1 << wyniki[0].wynik;
Napis wynik1(ss1.str(), 500,150, Color::White);
wynik1.zmienRozmiar(25);
Napis imie2("2   -   "+wyniki[1].imie, 100,225, Color::White);
imie2.zmienRozmiar(25);
ostringstream ss2;
ss2 << wyniki[1].wynik;
Napis wynik2(ss2.str(), 500,225, Color::White);
wynik2.zmienRozmiar(25);
Napis imie3("3   -   "+wyniki[2].imie, 100,300, Color::White);
imie3.zmienRozmiar(25);
ostringstream ss3;
ss3 << wyniki[2].wynik;
Napis wynik3(ss3.str(), 500,300, Color::White);
wynik3.zmienRozmiar(25);
Napis imie4("4   -   "+wyniki[3].imie, 100,375, Color::White);
imie4.zmienRozmiar(25);
ostringstream ss4;
ss4 << wyniki[3].wynik;
Napis wynik4(ss4.str(), 500,375, Color::White);
wynik4.zmienRozmiar(25);
Napis imie5("5   -   "+wyniki[4].imie, 100,450, Color::White);
imie5.zmienRozmiar(25);
ostringstream ss5;
ss5 << wyniki[4].wynik;
Napis wynik5(ss5.str(), 500,450, Color::White);
wynik5.zmienRozmiar(25);

Napis menu1("Rozpocznij", 312,100, Color::White);
Napis menu2("Pomoc", 350,200, Color::White);
Napis menu3("Opcje", 350,300, Color::White);
Napis menu4("Najlepsze wyniki", 275,400, Color::White);
Napis menu5("Wyjscie", 340,500, Color::White);
menu1.zmienRozmiar(20);
menu2.zmienRozmiar(20);
menu3.zmienRozmiar(20);
menu4.zmienRozmiar(20);
menu5.zmienRozmiar(20);

Napis rekord1("Najlepszy wynik: "+rekord, 0, 555, Color::White);
Napis help1("Gra polega na poruszaniu sie szarym kwadratem", 0,50, Color::White);
Napis help2("za pomoca strzalek lub klawisz W, S, A, D.", 0,100, Color::White);
Napis help3("Zdobywasz punkt gdy stoisz szarym kwadratem na polu", 0,150, Color::White);
Napis help4("o kolorze podanym w gornej czesci programu", 0,200, Color::White);
Napis help5("w momencie gdy konczy sie czas wskazywany", 0,250, Color::White);
Napis help6("przez poruszajacy sie pasek. Czas na zmiane pozycji", 0,300, Color::White);
Napis help7("szarego kwadratu zmniejsza sie z kazdym uzyskanym", 0,350, Color::White);
Napis help8("punktem. Po uzyskaniu 5 punktow zadany kolor", 0,400, Color::White);
Napis help9("jest pokazywany tylko przez angielski napis u gory.", 0,450, Color::White);

Napis exitMenu("Aby wrocic do menu nacisnij Escape", 0,550, Color::White);

Napis koniec1("Koniec gry, aby przejsc do menu nacisnij Escape.", 50,250, Color::White);
Napis koniec2("Wpisz swoje imie, aby zapisac swoj wynik:", 75,300, Color::White);
Napis koniecWin("Wygrales z SI, gratulacje!!!", 50,100, Color::White);
Napis koniecLose("Przegrales z SI, nastepnym razem bedzie lepiej", 50,100, Color::White);
Napis options("Ustawienia", 198,20, Color::White);

Napis wyborGry1("Pojedynczy gracz", 280,100, Color::White);
menu1.zmienRozmiar(20);
Napis wyborGry2("Przeciwko SI", 320,200, Color::White);
menu1.zmienRozmiar(20);

options.zmienRozmiar(52);
Napis options1("Dzwiek: tak", 330,150, Color::White);
if(iDzwiek==0)
    options1.zmienNapis("Dzwiek: nie");
Napis options2("Trudnosc SI  "+sDifficult, 305,200, Color::White);

//-------------------------------koniec napisow

Licznik licznik;
licznik.changeColor(kolor,purple,brown);    //przesuwajacy sie kolorowy pasek wskazujacy pozostaly czas

Clock stoper;
Clock stoperSI; //stopery

postacSIXplansza=postacSI.obl_XPl();    //obliczenie na ktorym klocku stoi SI
postacSIYplansza=postacSI.obl_YPl();
Plansza* kwadrat[15][15];
for(int i=0; i<=11; i++)
    for(int j=0; j<=7; j++)
    {
        kwadrat[i][j] = new Plansza(i,j);
        kwadrat[i][j]->changeColor(purple, brown);  //inicjalizacja planszy z wylosowaniem kazdej czesci koloru
        if(kwadrat[i][j]->getColor()==kolor)        //jesli wylosowany kolor jest zadanym
        {
            float distance = sqrt(pow(i-postacSIXplansza,2)+pow(j-postacSIYplansza,2)); //oblicz odleglosc SI od klocka
            if(distance<bestDistance)   //jesli odleglosc jest mniejsza niz najmniejsza
            {
                bestDistance=distance;  //zrob ja najlepsza
                bestPosition[0]=i;      //zapamietaj dokad ma pojsc SI
                bestPosition[1]=j;
            }
        }
    }

RenderWindow window;        //tworzenie okna
window.create(VideoMode(szerOkna,wysOkna), "Play with colours - Wojciech Regulski", Style::Close);
//window.setFramerateLimit(60);   //ograniczenie do 60 fps
window.setVerticalSyncEnabled(true);    //ograniczenie klatek do odswiezania monitora

window.setKeyRepeatEnabled(false);

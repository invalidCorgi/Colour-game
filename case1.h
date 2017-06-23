using namespace sf;
using namespace std;

//poruszanie znacznikiem postac
if(!kilkaPrzyciskow())
{
    if ( (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && previousState!=1 )
    {
        postac.moveLeft();
        previousState=1;
    }
    if ( (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && previousState!=2 )
    {
        postac.moveRight(szerOkna);
        previousState=2;
    }
    if ( (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && previousState!=3 )
    {
        postac.moveUp();
        previousState=3;
    }
    if ( (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && previousState!=4 )
    {
        postac.moveDown(wysOkna);
        previousState=4;
    }
}

if(SI ==1 && stoperSI.getElapsedTime().asSeconds()>=0.5-0.05*difficulty)  //SI porusza sie o jedno miejsce co okreslony czas
{
    bool already=0;     //przy kazdym przejsciu przesuwaj sie tylko o 1 klocek
    stoperSI.restart(); //liczenie czasu od nowa
    if(bestPosition[0]<postacSIXplansza && !already)
    {
        postacSI.moveLeft();
        postacSIXplansza--;
        already=1;
    }
    if(bestPosition[0]>postacSIXplansza && !already)
    {
        postacSI.moveRight(szerOkna);
        postacSIXplansza++;
        already=1;
    }
    if(bestPosition[1]<postacSIYplansza && !already)
    {
        postacSI.moveUp();
        postacSIYplansza--;
        already=1;
    }
    if(bestPosition[1]>postacSIYplansza && !already)
    {
        postacSI.moveDown(wysOkna);
        postacSIYplansza++;
        already=1;
    }
}

if(stoper.getElapsedTime().asSeconds()>=oblCzas(score) || spacja)   //gdy uplynie czas(im wiekszy wynik tym krotszy) lub nacisnieta zostanie spacja
{
    spacja=0;
    stoper.restart();   //liczenie czasu od nowa
    postacXplansza=postac.obl_XPl();    //obliczenie na ktorym klocku stoi postac
    postacYplansza=postac.obl_YPl();
    postacSIXplansza=postacSI.obl_XPl();    //obliczenie na ktorym klocku stoi SI
    postacSIYplansza=postacSI.obl_YPl();
    if(postacXplansza>=0 && postacXplansza<=11 && postacYplansza>=0 && postacYplansza<=7)   //jesli stoi na planszy
    {
        if(kolor==kwadrat[postacXplansza][postacYplansza]->getColor())  //i na dobrym polu
        {
            score++;
            if(iDzwiek==1)
                sound1.play();
        }
        else    //a jak na zlym
        {
            tempScore=score;    //zapisz uzyskany wynik do pozniejszego przetwarzania
            if(iDzwiek==1)
                sound2.play();
            if(score>=5)
            {
                score=5;
                wynik.zmienNapis("Wynik: 5");
            }
            else
            {
                score=0;
                wynik.zmienNapis("Wynik: 0");
            }
            proba++;
            imie="";
            postac.zmienPozycje(Vector2f(355,505));     //do pozycji poczatkowycj
            postacSI.zmienPozycje(Vector2f(405,505));
            postacSIXplansza=postacSI.obl_XPl();    //obliczenie na ktorym klocku stoi SI, zeby po rozpoczeciu nowej gry byl w dobrym miejscu
            postacSIYplansza=postacSI.obl_YPl();

            break;
        }
    }
    else
    {
        tempScore=score;
        if(iDzwiek==1)
            sound2.play();
        if(score>=5)
        {
            score=5;
            wynik.zmienNapis("Wynik: 5");
        }
        else
        {
            score=0;
            wynik.zmienNapis("Wynik: 0");
        }   //gra od nowa, gdy postac stoi na zlym klocku
        proba++;
        imie="";
        postac.zmienPozycje(Vector2f(355,505));
        postacSI.zmienPozycje(Vector2f(405,505));
        postacSIXplansza=postacSI.obl_XPl();    //obliczenie na ktorym klocku stoi SI, zeby po rozpoczeciu nowej gry byl w dobrym miejscu
        postacSIYplansza=postacSI.obl_YPl();

        break;
    }
    if(SI==1 && postacSIXplansza>=0 && postacSIXplansza<=11 && postacSIYplansza>=0 && postacSIYplansza<=7)  //jesli SI zyje
    {
        if(kolor==kwadrat[postacSIXplansza][postacSIYplansza]->getColor())
        {
            //gdy SI stoi na dobrym klocku
        }
        else
        {
            SI=0;
            postacSI.zmienPozycje(Vector2f(405,505));
        }
    }
    else
    {
        SI=0;
        postacSI.zmienPozycje(Vector2f(405,505));
    }
    kolor=rand()%7; //wylosownie nowego koloru, na ktorym trzeba stanac
    if(score<5)licznik.changeColor(kolor,purple,brown);
    else licznik.changeColor(grey2);
    napis.zmienNapis(napisy[kolor]);
    ostringstream ss;   //zmiana liczbowego wyniku na napisowy
    ss << score;
    str = "Wynik: "+ss.str();
    wynik.zmienNapis(str);
    bestDistance=100;
    for(int i=0; i<=11; i++)
        for(int j=0; j<=7; j++)
        {
            kwadrat[i][j]->changeColor(purple,brown);   //wylosowanie na nowo planszy
            if(kwadrat[i][j]->getColor()==kolor)
            {
                float distance = sqrt(pow(i-postacSIXplansza,2)+pow(j-postacSIYplansza,2));
                if(distance<bestDistance)
                {
                    bestDistance=distance;
                    bestPosition[0]=i;
                    bestPosition[1]=j;
                }
            }
        }

    if(bscore<score)
    {
        bscore=score;
        rekord2.zmienNapis("Najlepszy wynik tej gry: "+ss.str());
    }
    if(bescore<score)
    {
        bescore=score;
        rekord1.zmienNapis("Najlepszy wynik: "+ss.str());
    }
}

//rysowanie sceny

window.clear();

window.draw(menu);

for(int i=0; i<=11; i++)
    for(int j=0; j<=7; j++)
        window.draw(kwadrat[i][j]->getShape()); //rysowanie planszy

if(SI==1)window.draw(postacSI.getShape());
window.draw(postac.getShape());

licznik.changeSize(stoper.getElapsedTime().asSeconds(),score);
window.draw(licznik.getShape());
window.draw(napis.getText());
window.draw(wynik.getText());
window.draw(rekord1.getText());
window.draw(rekord2.getText());
window.display();
break;

using namespace sf;
using namespace std;

window.clear();
window.draw(menu);
nImie.zmienNapis(imie);
if(gameWithSi)
{
    if(SI)  //jesli SI przezyl do konca gry
    {
        window.draw(koniecLose.getText());
    }
    else
    {
        window.draw(koniecWin.getText());
    }
}
window.draw(koniec1.getText());
window.draw(koniec2.getText());
window.draw(nImie.getText());
window.display();
if(Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Return))
{
    proba=3;
    previousState=1;

    if(imie.length()==0)
        imie="noname";

    int index=5;
    for(int i=4; i>=0; i--) //poszukaj na ktorym miejscu w tabeli bedzie aktualny wynik
    {
        if(tempScore>wyniki[i].wynik)
            index=i;
    }

    for(int i=4; i>index; i--)  //przesun wszystkie ponizej o jeden w dol
    {
        wyniki[i].wynik=wyniki[i-1].wynik;
        wyniki[i].imie=wyniki[i-1].imie;
    }

    if(index!=5)    //wstaw w odpowiednie miejsce
    {

        wyniki[index].imie=imie;
        wyniki[index].wynik=tempScore;
    }

    plik.open("hs.txt", ios::out);
    plik<<bescore;
    plik<<" //highest score";
    for(int i=0; i<5; i++)
    {
        ostringstream ss;       //zapisz do pliku zaktualizowana historie wynikow
        ss<<wyniki[i].wynik;
        plik<<" "+wyniki[i].imie;
        plik<<" "+ss.str();
    }
    plik.close();

    imie1.zmienNapis("1   -   "+wyniki[0].imie);    //zaktualizuj widok najlepszych wynikow
    ostringstream ss1;
    ss1 << wyniki[0].wynik;
    wynik1.zmienNapis(ss1.str());

    imie2.zmienNapis("1   -   "+wyniki[1].imie);
    ostringstream ss2;
    ss2 << wyniki[1].wynik;
    wynik2.zmienNapis(ss2.str());

    imie3.zmienNapis("1   -   "+wyniki[2].imie);
    ostringstream ss3;
    ss3 << wyniki[2].wynik;
    wynik3.zmienNapis(ss3.str());

    imie4.zmienNapis("1   -   "+wyniki[3].imie);
    ostringstream ss4;
    ss4 << wyniki[3].wynik;
    wynik4.zmienNapis(ss4.str());

    imie5.zmienNapis("1   -   "+wyniki[4].imie);
    ostringstream ss5;
    ss5 << wyniki[4].wynik;
    wynik5.zmienNapis(ss5.str());
}
break;

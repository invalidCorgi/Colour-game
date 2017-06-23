using namespace sf;
using namespace std;

if(Keyboard::isKeyPressed(Keyboard::Escape))
{
    proba=5;
}
window.clear();

window.draw(menu);
window.draw(options.getText());
window.draw(options1.getText());
window.draw(options2.getText());
strzalki.setPosition(Vector2f(0,170));
window.draw(strzalki);
window.draw(exitMenu.getText());
window.display();
if(Keyboard::isKeyPressed(Keyboard::Down) && previousState!=1)
{
    proba--;
    previousState=1;
}
if(Keyboard::isKeyPressed(Keyboard::Up) && previousState!=1)
{
    proba--;
    previousState=1;
}
if(Keyboard::isKeyPressed(Keyboard::Left) && previousState!=1)
{
    previousState=1;
    if(difficulty>1)    //jesli nacisnieto strzalke w lewo, a trudnosc nie jest minimalna
    {
        difficulty--;   //to zmniejsz i zapisz zmienione ustawienia do pliku
        plik.open("settings.txt", ios::out);
        plik<<iDzwiek;
        plik<<" //sound ";
        plik<<difficulty;
        plik<<" //difficulty_1-6";
        plik.close();
        ostringstream ss;
        ss << difficulty;
        options2.zmienNapis("Trudnosc SI  "+ss.str());
    }
}
if(Keyboard::isKeyPressed(Keyboard::Right) && previousState!=1)
{
    previousState=1;
    if(difficulty<6)    //jesli nacisnieto strzalke w prawo, a trudnosc nie jest maksymalna
    {
        difficulty++;   //to zwieksz i zapisz zmienione ustawienia do pliku
        plik.open("settings.txt", ios::out);
        plik<<iDzwiek;
        plik<<" //sound ";
        plik<<difficulty;
        plik<<" //difficulty_1-6";
        plik.close();
        ostringstream ss;
        ss << difficulty;
        options2.zmienNapis("Trudnosc SI  "+ss.str());
    }
}
break;

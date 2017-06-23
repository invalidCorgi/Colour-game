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
strzalki.setPosition(Vector2f(0,120));
window.draw(strzalki);
window.draw(exitMenu.getText());
window.display();
if(Keyboard::isKeyPressed(Keyboard::Down) && previousState!=1)
{
    proba++;
    previousState=1;
}
if(Keyboard::isKeyPressed(Keyboard::Up) && previousState!=1)
{
    proba++;
    previousState=1;
}
if((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Return)) && previousState!=1)
{
    //zmiena opcji dzwieku
    previousState=1;
    if(iDzwiek==1)
    {
        iDzwiek=0;
        plik.open("settings.txt", ios::out);    //zapis zmienionych ustawien do pliku
        plik<<iDzwiek;
        plik<<" //sound ";
        plik<<difficulty;
        plik<<" //difficulty_1-6";
        plik.close();
        options1.zmienNapis("Dzwiek: nie");
    }
    else
    {
        iDzwiek=1;
        plik.open("settings.txt", ios::out);
        plik<<iDzwiek;
        plik<<" //sound ";
        plik<<difficulty;
        plik<<" //difficulty_1-6";
        plik.close();
        options1.zmienNapis("Dzwiek: tak");
    }
}
break;

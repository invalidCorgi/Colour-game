using namespace sf;
using namespace std;

if(Keyboard::isKeyPressed(Keyboard::Escape))
{
    proba=6;
}

window.clear();

window.draw(menu);
window.draw(bestScores.getText());
window.draw(imie1.getText());
window.draw(wynik1.getText());
window.draw(imie2.getText());
window.draw(wynik2.getText());
window.draw(imie3.getText());
window.draw(wynik3.getText());
window.draw(imie4.getText());
window.draw(wynik4.getText());
window.draw(imie5.getText());
window.draw(wynik5.getText());
window.draw(exitMenu.getText());
window.display();
break;

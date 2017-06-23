using namespace sf;
using namespace std;

window.clear();
window.draw(menu);
window.draw(menu1.getText());
window.draw(menu2.getText());
window.draw(menu3.getText());
window.draw(menu4.getText());
window.draw(menu5.getText());
strzalki.setPosition(Vector2f(0,70));
window.draw(strzalki);
window.display();

if(Keyboard::isKeyPressed(Keyboard::Down) && previousState!=1)
{
    proba++;
    previousState=1;
}
if(Keyboard::isKeyPressed(Keyboard::Up) && previousState!=1)
{
    proba=7;
    previousState=1;
}
if(Keyboard::isKeyPressed(Keyboard::Return) && previousState!=1)
{
    proba=30;           //przejdz do wyboru trybu gry
    previousState=1;
}
break;

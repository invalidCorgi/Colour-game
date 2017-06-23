using namespace sf;
using namespace std;

window.clear();
window.draw(menu);
window.draw(wyborGry1.getText());
window.draw(wyborGry2.getText());
window.draw(exitMenu.getText());
strzalki.setPosition(Vector2f(0,170));
window.draw(strzalki);
window.display();
//if ( event.type == Event::KeyReleased )
//previousState=0;
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
if(Keyboard::isKeyPressed(Keyboard::Escape))
{
    proba=3;
}
if(Keyboard::isKeyPressed(Keyboard::Return) && previousState!=1)
{
    proba=1;
    SI=1;
    gameWithSi=1;   //zacznij gre z SI
    stoper.restart();
    stoperSI.restart();
}
break;

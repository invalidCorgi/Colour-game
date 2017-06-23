using namespace sf;
using namespace std;

if(Keyboard::isKeyPressed(Keyboard::Escape))
{
    proba=4;
}

window.clear();
window.draw(menu);
window.draw(help1.getText());
window.draw(help2.getText());
window.draw(help3.getText());
window.draw(help4.getText());
window.draw(help5.getText());
window.draw(help6.getText());
window.draw(help7.getText());
window.draw(help8.getText());
window.draw(help9.getText());
window.draw(exitMenu.getText());
window.display();
break;

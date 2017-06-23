using namespace sf;
using namespace std;

Event event;
while(window.pollEvent(event))
{
    if(event.type==Event::Closed)
        window.close();
    if( event.type == Event::KeyPressed && event.key.code == Keyboard::Space )
        spacja=1;
    if ( event.type == Event::KeyReleased )
        previousState=0;    //wyzerowanie zmiennej dzieki ktorej jest mozliwe poruszanie sie o tylko jeden kwadrat
    if (event.type == sf::Event::TextEntered)
    {
        if ((event.text.unicode >= 65 || event.text.unicode <= 90 || event.text.unicode >= 97 || event.text.unicode <= 122 ) && imie.length()<10)   //jesli znakiem jest litera i imie nie przekracza maksymalnej dlugosci
        {
            imie += static_cast<char>(event.text.unicode);
            if(imie.length()>0 && !imie.substr(imie.length()-1,1).compare(" ")) //jesli niepusty napis ze spacja na koncu (ostatnio wpisana spacja)
            {
                imie=imie.substr(0,imie.length()-1);    //skroc napis o spacje
                imie+=",";                              //zastap ja przecinkiem(przecinek wyswietlany jako spacja)
            }
        }
        if(event.text.unicode == 8)
        {
            imie=imie.substr(0,imie.length()-2);    //usun ostatni znak przy backspace
        }
    }
}

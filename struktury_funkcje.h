bool kilkaPrzyciskow()
{
    if(  ( ( Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S) ) &&   //warunek uniemozliwiajacy poruszanie sie przy nacisnieciu kilku klawiszy
            ( Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A) ) ) ||
            ( ( Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S) ) &&
              ( Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D) ) ) ||
            ( ( Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) ) &&
              ( Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A) ) ) ||
            ( ( Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) ) &&
              ( Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D) ) ) )
        return 1;
    else
        return 0;
}

struct Wynik
{
    string imie;
    int wynik;
};

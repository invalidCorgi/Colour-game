#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
using namespace std;

class Postac
{
public:
    Postac(int startX, int startY, Color color);
    ~Postac();

    FloatRect getPosition();
    RectangleShape getShape();
    void moveLeft();
    void moveUp();
    void moveRight(int szerOkna);
    void moveDown(int wysOkna);
    void update();
    int obl_XPl();
    int obl_YPl();
    void zmienPozycje(Vector2f);
    Vector2f getPos();
    Texture tekstura;

private:
    Vector2f position;
    RectangleShape hero;
};

Postac::Postac(int startX, int startY, Color color)
{
    position.x=startX;
    position.y=startY;

    hero.setSize(Vector2f(40,40));
    hero.setPosition(position);
    hero.setFillColor(color);
}

Postac::~Postac()
{
}

FloatRect Postac::getPosition()
{
    return hero.getGlobalBounds();
}

RectangleShape Postac::getShape()
{
    return hero;
}

void Postac::moveLeft()
{
    if(position.x>=50)
    position.x-=50;
    update();
}

void Postac::moveUp()
{
    if(position.y>=150)
    position.y-=50;
    update();
}

void Postac::moveRight(int szerOkna)
{
    if(position.x<=szerOkna-50)
    position.x+=50;
    update();
}

void Postac::moveDown(int wysOkna)
{
    if(position.y<=wysOkna-100)
    position.y+=50;
    update();
}

void Postac::update()
{
    hero.setPosition(position);
}

int Postac::obl_XPl()
{
    int x=position.x-5;
    int x2=x/50;
    int wynik=x2-2;
    return wynik;
}

int Postac::obl_YPl()
{
    int y=position.y-5;
    int y2=y/50;
    int wynik=y2-2;
    return wynik;
}

void Postac::zmienPozycje(Vector2f konPoz)
{
    position=konPoz;
    update();
}

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
using namespace std;

class Plansza
{
public:
    Plansza(int, int);
    ~Plansza();

    FloatRect getPosition();
    RectangleShape getShape();
    void update();
    void changeColor(Color, Color);
    int getColor();
    int losColor();

private:
    Vector2f position;
    RectangleShape sq;
    int color;

};

Plansza::Plansza(int startX=0, int startY=0)
{
    position.x=startX*51+100-startX;
    position.y=startY*51+100-startY;

    sq.setSize(Vector2f(49,49));
    sq.setPosition(position);
}

Plansza::~Plansza()
{
}

FloatRect Plansza::getPosition()
{
    return sq.getGlobalBounds();
}

RectangleShape Plansza::getShape()
{
    return sq;
}

void Plansza::changeColor(Color purple, Color brown)
{
    color=losColor();
    if(color==0)
        sq.setFillColor(Color::Green);
    if(color==1)
        sq.setFillColor(purple);
    if(color==2)
        sq.setFillColor(Color::Yellow);
    if(color==3)
        sq.setFillColor(Color::Blue);
    if(color==4)
        sq.setFillColor(Color::Red);
    if(color==5)
        sq.setFillColor(Color::White);
    if(color==6)
        sq.setFillColor(brown);
}

int Plansza::getColor()
{
    return color;
}

int Plansza::losColor()
{
    int color=rand()%7;
    return color;
}


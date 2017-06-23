#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace sf;
using namespace std;

float pot(float, float);
float oblCzas(int score);

class Licznik
{
public:
    Licznik();
    ~Licznik();

    FloatRect getPosition();
    RectangleShape getShape();
    void changeSize(float, int);
    void changeColor(int, Color, Color);
    void changeColor(Color);

private:
    Vector2f position;
    RectangleShape licznik;
};

Licznik::Licznik()
{
    position.x=0;
    position.y=0;

    licznik.setSize(Vector2f(800,100));
    licznik.setPosition(position);
}

Licznik::~Licznik()
{
}

FloatRect Licznik::getPosition()
{
    return licznik.getGlobalBounds();
}

RectangleShape Licznik::getShape()
{
    return licznik;
}

void Licznik::changeSize(float sec, int score)
{
    float czas=oblCzas(score);
    float temp1=czas-sec;
    float temp2=temp1/czas;
    licznik.setSize(Vector2f(800*temp2,100));
}

void Licznik::changeColor(int color, Color purple, Color brown)
{
    if(color==0)
        licznik.setFillColor(Color::Green);
    if(color==1)
        licznik.setFillColor(purple);
    if(color==2)
        licznik.setFillColor(Color::Yellow);
    if(color==3)
        licznik.setFillColor(Color::Blue);
    if(color==4)
        licznik.setFillColor(Color::Red);
    if(color==5)
        licznik.setFillColor(Color::White);
    if(color==6)
        licznik.setFillColor(brown);
}

void Licznik::changeColor(Color grey2)
{
    licznik.setFillColor(grey2);
}

float pot(float x, float y)
{
    float wynik=1;
    for(;y>0;y--)
        wynik*=x;
    return wynik;
}

float oblCzas(int score)
{
    float czas;
    czas=3*(pot(0.98,score));
    return czas;
}


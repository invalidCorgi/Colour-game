#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Napis
{
public:
    Napis(string text, int, int, Color);
    ~Napis();

    Text getText();
    void getFont();
    Text napis;
    FloatRect getPosition();
    void zmienNapis(string xx);
    void zmienRozmiar(unsigned int rozmiar);

private:
    Font czcionka;
};

Napis::Napis(string text, int x, int y, Color kolor)
{
    napis.setString(text);
    napis.setFont(czcionka);
    napis.setColor(kolor);

    getFont();
    napis.setPosition(x,y);
    napis.setCharacterSize(18);
    napis.scale(1,1.6);
}

Napis::~Napis()
{

}

Text Napis::getText()
{
    return napis;
}
void Napis::getFont()
{
    czcionka.loadFromFile("ka1.ttf");
}
FloatRect Napis::getPosition()
{
    return napis.getGlobalBounds();
}

void Napis::zmienNapis(string xx)
{
    napis.setString(xx);
}

void Napis::zmienRozmiar(unsigned int rozmiar)
{
    napis.setCharacterSize(rozmiar);
}

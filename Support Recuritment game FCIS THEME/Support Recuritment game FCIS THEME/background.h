#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<Windows.h>
#include<fstream>
using namespace std;
using namespace sf;
class background {
public:
    background(string imgDirectory) {
        if (!Back.loadFromFile(imgDirectory)) {
            cerr << "Error\n";
        }
        back.setTexture(Back);
    }
    void drawBack(RenderWindow& window) {
        window.draw(back);
    }
    void back22() {
        Back2.loadFromFile("background2.png");
        back.setTexture(Back2);
        back.setTextureRect(IntRect(0, 0, 626, 250));
        back.setScale(2.06, 2.6);
    }
private:
    Texture Back;
    Texture Back2;
    Sprite back;
};


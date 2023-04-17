#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<Windows.h>
#include<fstream>

using namespace std;
using namespace sf;


class Story {
public:
    Texture pTexture;
    Sprite pSprite;
    Story(string imgDirectory) {
        if (!pTexture.loadFromFile(imgDirectory)) {
            cerr << "Error\n";
        }
        pSprite.setTexture(pTexture);
        pSprite.setTextureRect(IntRect(0, 0, 612, 903));
        pSprite.setScale(0.1, 0.1);
        pSprite.setPosition(1200, 600);


    }

    void drawPlayer(RenderWindow& window) {
        window.draw(pSprite);
    }

    void movePlayer(char direction, float moveSpeed, float movespeed) {

        if (direction == 'l') {
            pSprite.move(moveSpeed, movespeed);
            cntrY = 1;
            cntrX++;

        }
        else if (direction == 'r') {
            pSprite.move(moveSpeed, movespeed);
            cntrY = 0;
            cntrX++;

        }


    }
    void posi1() {

        if (pSprite.getPosition().x > 180) {
            pSprite.move(-5, 0);
            cntrX++;
            cntrY = 1;
        }
        cntrX %= 15;
        pSprite.setTextureRect(IntRect(cntrX * 612, cntrY * 903, 612, 903));

    }

    void posi2() {

        if (pSprite.getPosition().x > 180) {
            pSprite.move(-5, -0.6);
            cntrX++;
            cntrY = 1;
        }
        cntrX %= 15;
        pSprite.setTextureRect(IntRect(cntrX * 612, cntrY * 903, 612, 903));

    }
    void posi3() {

        if (pSprite.getPosition().x > 120) {
            pSprite.move(4, -1.6);
            cntrX++;
            cntrY = 0;
        }

        cntrX %= 15;
        pSprite.setTextureRect(IntRect(cntrX * 612, cntrY * 903, 612, 903));

    }




private:

    int cntrX = 0;
    int cntrY = 0;


};


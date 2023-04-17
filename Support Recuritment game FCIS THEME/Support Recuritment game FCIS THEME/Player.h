#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<Windows.h>
#include<fstream>

using namespace std;
using namespace sf;


class Player {
public:

    Texture pTexture;
    Sprite pSprite;

    Player(string imgDirectory) {
        if (!pTexture.loadFromFile(imgDirectory)) {
            cerr << "Error\n";
        }
        pSprite.setTexture(pTexture);
        pSprite.setTextureRect(IntRect(0, 0, 612, 903));
        pSprite.setScale(0.12, 0.12);
        pSprite.setPosition(200, 550);
    }

    void drawPlayer(RenderWindow& window) {
        window.draw(pSprite);
    }

    void movePlayer(char direction, float moveSpeed) {

        if (direction == 'l') {
            if (pSprite.getPosition().x > 0)
                pSprite.move(moveSpeed, 0);
            cntrY = 1;
            cntrX++;

        }
        else if (direction == 'r') {
            if (pSprite.getPosition().x < 1200)
                pSprite.move(moveSpeed, 0);
            cntrY = 0;
            cntrX++;

        }
        cntrX %= 15;
        pSprite.setTextureRect(IntRect(cntrX * 612, cntrY * 903, 612, 903));

    }



private:
    int cntrY = 0;
    int cntrX = 0;

};


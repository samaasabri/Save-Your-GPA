#include <SFML/Graphics.hpp>
#include <iomanip>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<Windows.h>
#include<vector>
#include<fstream>
#include"Player.h"
#include"Story.h"
#include"Menu.h"
//#include"Projectile.h"
#include"background.h"
using namespace std;
using namespace sf;

int numPage = 3;

int main()
{
    while (true)
    {

        RenderWindow windowMenu(VideoMode(1280, 720), "Menu", Style::Close);
        Menu menu(1280, 720);
        Texture t;
        t.loadFromFile("lab.png");
        Sprite s;
        s.setTexture(t);
        while (windowMenu.isOpen())
        {
            Event event;
            while (windowMenu.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    windowMenu.close();
                    
                }

                if (event.type == Event::KeyReleased)
                {
                    if (event.key.code == Keyboard::Up)
                    {
                        menu.moveUp();
                        break;
                    }

                    if (event.key.code == Keyboard::Down)
                    {
                        menu.moveDown();
                        break;
                    }
                    if (event.key.code == Keyboard::Return)
                    {

                        if (menu.MenuPressed() == 0)
                        {
                            windowMenu.close();
                            numPage = 0;
                        }
                        if (menu.MenuPressed() == 1)
                        {
                            windowMenu.close();
                            numPage = 1;
                        }
                        if (menu.MenuPressed() == 2)
                        {
                            windowMenu.close();
                            numPage = 2;
                        }

                    }
                    if (event.key.code == Keyboard::Escape)
                    {
                        numPage = 3;
                    }
                }
            }
            windowMenu.clear();
            windowMenu.draw(s);
            menu.draw(windowMenu);
            windowMenu.display();
        }




        if (numPage == 0)
        {
            int yspeed = 3;
            RenderWindow window(VideoMode(1280, 720), "Welcome FCIS");
            window.setFramerateLimit(60);
            Player myPlayer("walking1.png");
            background myback("back.png");
            //vector<string>v(4);
            vector<Texture>v(4);
            vector<Texture>v2(4);
            for (int i = 0; i < 4; ++i) {
                string s;
                s = "good" + to_string(i) + ".png";
                v2[i].loadFromFile(s);
            }

            for (int i = 0; i < 4; ++i) {
                string s;
                s = "bad" + to_string(i) + ".png";
                v[i].loadFromFile(s);
            }

            Texture emm;
            //emm.loadFromFile("unknown.png");
            RectangleShape enemy;
            //enemy.setTexture(&emm);
            RectangleShape abonus;
            abonus.setSize(Vector2f(100, 50.f));
            enemy.setSize(Vector2f(100, 50.f));
            vector<RectangleShape> enemies;
            vector<RectangleShape> bonus;
            enemy.setTexture(&v[rand() % 4]);
            enemies.push_back(enemy);
            abonus.setTexture(&v[rand() % 4]);
            bonus.push_back(abonus);
            int gpa = 2, gpb = 0;

            int enemyTimer = 0;
            Text text, score, gp, h, m, youWIN, youLOSE;
            Font foont;
            foont.loadFromFile("OpenSans-Bold.ttf");
            score.setFont(foont);
            score.setString("GPA:");
            score.setCharacterSize(20);
            score.setPosition(0, 0);
            score.setFillColor(Color::Black);
            score.setStyle(Text::Bold);

            h.setFont(foont);
            h.setString("08:");
            h.setCharacterSize(20);
            h.setPosition(1180, 20);
            h.setFillColor(Color::Red);
            h.setStyle(Text::Bold);

            m.setFont(foont);
            m.setFillColor(Color::Red);
            m.setCharacterSize(20);
            m.setStyle(Text::Bold);
            m.setPosition(1210, 20);

            text.setFont(foont);
            text.setFillColor(Color::Black);
            text.setCharacterSize(20);
            text.setStyle(Text::Bold);
            text.setPosition(120, 0);


            text.setFont(foont);
            text.setFillColor(Color::Black);
            text.setCharacterSize(20);
            text.setStyle(Text::Bold);
            text.setPosition(120, 0);

            youWIN.setFont(foont);
            youWIN.setString("CONGRATS :) YOU GRADUATED");
            youWIN.setFillColor(Color::Black);
            youWIN.setCharacterSize(60);
            youWIN.setStyle(Text::Bold);
            youWIN.setPosition(1200, 3000);


            gp.setFont(foont);
            gp.setFillColor(Color::Black);
            gp.setCharacterSize(20);
            gp.setStyle(Text::Bold);
            gp.setPosition(135, 0);

            Music music;
            music.openFromFile("Donkey Kong.wav");
            music.setVolume(50);
            music.setLoop(true);
            music.play();


            Story MyPlayer("walking1.png");
            Texture Back;
            Back.loadFromFile("s1.png");
            Sprite back(Back);
            back.setScale(1, 0.78);
            Texture Back2;
            Back2.loadFromFile("s2.png");
            Sprite back2(Back2);
            back2.setScale(1, 1);
            Texture Back3;
            Back3.loadFromFile("s3.png");
            Sprite back3(Back3);
            back3.setScale(1.35, 1);
            int cnt = 1;
            int time = 0;

            int c = 1;


            bool gameEnded = false;
            while (window.isOpen())
            {
                Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        window.close();

                }
                if (Keyboard::isKeyPressed(Keyboard::Key::Right))
                {

                    myPlayer.movePlayer('r', 7);


                }
                else  if (Keyboard::isKeyPressed(Keyboard::Key::Left))
                {

                    myPlayer.movePlayer('l', -7);

                }

                String st = to_string(gpa) + ".", str = to_string(gpb), h1, m1 = to_string(int((60 * c) - time / 60));

                text.setString(st);
                gp.setString(str);
                m.setString(m1);
                if (enemyTimer < 100)
                    enemyTimer++;

                if (enemyTimer >= 50)

                {
                    if (!gameEnded) {
                        int x = rand() % 4;
                        enemy.setPosition(((rand() % 6) * 200) + 150, 0);
                        enemy.setTexture(&v[x]);
                        abonus.setTexture(&v2[x]);
                        if (x == 0)
                            enemy.setTextureRect(IntRect(0, 0, 586, 539)), abonus.setTextureRect(IntRect(0, 0, 1038, 1038));
                        if (x == 1)
                            enemy.setTextureRect(IntRect(0, 0, 579, 416)), abonus.setTextureRect(IntRect(0, 0, 1038, 1038));
                        if (x == 2)
                            enemy.setTextureRect(IntRect(0, 0, 860, 680)), abonus.setTextureRect(IntRect(0, 0, 860, 680));
                        if (x == 3)
                            enemy.setTextureRect(IntRect(0, 0, 860, 680)), abonus.setTextureRect(IntRect(0, 0, 539, 408));


                        enemies.push_back(enemy);
                        abonus.setPosition(((rand() % 6) * 200) + 150, 0);


                        bonus.push_back(abonus);
                        enemyTimer = 0;
                    }
                }
                for (size_t i = 0; i < enemies.size(); i++)
                {
                    enemies[i].move(0.f, yspeed * 2);
                    if (enemies[i].getPosition().y > window.getSize().y - 100)
                        enemies.erase(enemies.begin() + i);
                }


                for (size_t j = 0; j < enemies.size(); j++)
                {
                    if (myPlayer.pSprite.getGlobalBounds().intersects(enemies[j].getGlobalBounds()) && gpa < 4) {
                        gpb--;
                        enemies.erase(enemies.begin() + j);

                    }
                }
                for (size_t i = 0; i < bonus.size(); i++)
                {
                    bonus[i].move(0.f, yspeed);
                    if (bonus[i].getPosition().y > window.getSize().y - 100) {
                        bonus.erase(bonus.begin() + i);
                        gpb--;
                    }
                }

                for (size_t i = 0; i < enemies.size(); i++)
                {
                    for (size_t j = 0; j < bonus.size(); j++)
                    {
                        if (enemies[i].getGlobalBounds().intersects(bonus[j].getGlobalBounds())) {
                            bonus.erase(bonus.begin() + j);
                        }
                    }
                }
                for (size_t j = 0; j < bonus.size(); j++)
                {
                    if (myPlayer.pSprite.getGlobalBounds().intersects(bonus[j].getGlobalBounds())) {
                        gpb++;
                        bonus.erase(bonus.begin() + j);
                    }
                }
                time++;
                if (time > 3600) {
                    myback.back22();
                    c = 2;
                }
                if (gpb < 0 && gpa < 4) {
                    gpb = 9;
                    gpa--;
                }
                else if (gpb > 9) {
                    gpa++;
                    gpb = 0;
                }
                if (gpa >= 4) {
                    music.stop();
                    gameEnded = true;
                    youWIN.setPosition(200, 300);
                    gpa = 4;
                    gpb = 0;

                }
                if (gpa < 0) {

                    gpa = 0;
                    gpb = 0;
                    //for (int i = 0; i < 10000000; i++) Willy
                    //{
                    //    window.close();
                    //}
                    gameEnded = true;
                    window.close();

                }
                if (cnt == 1) {
                    MyPlayer.posi1();
                }

                if (cnt == 2) {
                    MyPlayer.posi2();
                }

                if (cnt == 3) {
                    MyPlayer.posi3();
                }

                if (MyPlayer.pSprite.getPosition().x < 360 && cnt == 1) {
                    cnt++;
                    MyPlayer.pSprite.setPosition(1200, 450);

                }
                else if (MyPlayer.pSprite.getPosition().x < 300 && cnt == 2) {
                    cnt++;
                    MyPlayer.pSprite.setPosition(130, 600);
                }
                else if (MyPlayer.pSprite.getPosition().x > 700 && cnt == 3) {
                    MyPlayer.pSprite.setPosition(200, 550);
                    cnt++;
                }

                window.clear();
                if (cnt == 1) {
                    window.draw(back);
                    MyPlayer.drawPlayer(window);
                }
                else if (cnt == 2) {
                    window.draw(back2);
                    MyPlayer.drawPlayer(window);

                }
                else if (cnt == 3) {
                    window.draw(back3);
                    MyPlayer.drawPlayer(window);
                }
                else {
                    myback.drawBack(window);
                    for (size_t i = 0; i < enemies.size(); i++)
                    {
                        window.draw(enemies[i]);
                    }
                    for (size_t i = 0; i < bonus.size(); i++)
                    {
                        window.draw(bonus[i]);
                    }
                    window.draw(score);
                    window.draw(gp);
                    window.draw(text);
                    window.draw(h);
                    window.draw(m);
                    myPlayer.drawPlayer(window);
                    window.draw(youWIN);
                }

                window.display();
            }

        }
        if (numPage == 1)
        {
            RenderWindow inst(VideoMode(1280, 720), "Instructions", Style::Close);
            Texture t;
            t.loadFromFile("lab.png");
            Sprite s;
            s.setTexture(t);

            Text instruct[3];
            Font foont;
            foont.loadFromFile("OpenSans-Bold.ttf");
            for (int i = 0; i < 3; i++)
            {
                instruct[i].setFont(foont);
                if (i == 0)
                {
                    instruct[i].setString("Help the player with his gpa to graduate.");
                    instruct[i].setPosition(50, 100);
                }
                if (i == 1)
                {
                    instruct[i].setString("Collect support ,books and A+ sheets .");
                    instruct[i].setPosition(50, 200);
                }
                if (i == 2)
                {
                    instruct[i].setString("Press Right and left to move the player ");
                    instruct[i].setPosition(50, 300);
                }
                instruct[i].setCharacterSize(50);
                instruct[i].setFillColor(Color::Magenta);
                instruct[i].setStyle(Text::Bold);
            }
            while (inst.isOpen())
            {
                Event evnt;
                while (inst.pollEvent(evnt))
                {
                    if (evnt.type == Event::Closed)
                        inst.close();
                }

                inst.clear();
                inst.draw(s);
                for (int i = 0; i < 3; i++)
                    inst.draw(instruct[i]);
                inst.display();
            }
        }
        if (numPage == 2)
        {
            break;
        }
    }
    return 0;
}

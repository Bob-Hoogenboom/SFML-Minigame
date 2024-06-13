#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "mainMenu.h"
#include "ball.h"
#include "paddle.h"

int main()
{
    sf::VideoMode VM(1280, 720);
    sf::RenderWindow menu(VM, "MainMenu", sf::Style::Default);
    sf::Clock clock;

    mainMenu myMainMenu(menu.getSize().x, menu.getSize().y);
    ball myBall(VM.width/2, 1, 10, 10);
    paddle myPaddle(VM.width/2, 700, 100,7);

    //Get the font file
    sf::Font font;
    font.loadFromFile("Fonts/PixelEmulator.ttf");

    //# Seperate health class but works for now*
    sf::Text fontLives;
    fontLives.setFont(font);
    fontLives.setPosition(15, 10);
    fontLives.setCharacterSize(30);
    fontLives.setFillColor(sf::Color(139, 172, 15)); //Dark green Gameboy color
    fontLives.setOutlineThickness(3);
    fontLives.setFillColor(sf::Color(48, 98, 48));

    int lives = 4;
    std::stringstream ssLives;
    ssLives << "Lives: " << lives;
    fontLives.setString(ssLives.str());

    //# Seperate point class but works for now*
    sf::Text fontPoints;
    fontPoints.setFont(font);
    fontPoints.setPosition(300, 10);
    fontPoints.setCharacterSize(30);
    fontPoints.setFillColor(sf::Color(139, 172, 15)); //Dark green Gameboy color
    fontPoints.setOutlineThickness(3);
    fontPoints.setFillColor(sf::Color(48, 98, 48));

    int points = 0;
    std::stringstream ssPoints;
    ssPoints << "Points: " << points;
    fontPoints.setString(ssPoints.str());

    //# Seperate highScore class but works for now*
    sf::Text fontHighScore;
    fontHighScore.setFont(font);
    fontHighScore.setPosition(VM.width/2, VM.height/2);
    fontHighScore.setCharacterSize(30);
    fontHighScore.setFillColor(sf::Color(139, 172, 15)); //Dark green Gameboy color
    fontHighScore.setOutlineThickness(3);
    fontHighScore.setFillColor(sf::Color(48, 98, 48));

    int highScorePoints = 0;
    std::stringstream ssHighScore;
    ssHighScore << "HighScore: " << highScorePoints;
    fontHighScore.setString(ssHighScore.str());


    sf::Time deltaTime;
    sf::Event event;

    float bounceTimer = 0.10f;

    while (menu.isOpen()) 
    {
        //Makes the window closable by pressing the X on the top right;
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
                menu.close();
            } 

            if (event.type == sf::Event::KeyReleased) 
            {
                if (event.key.code == sf::Keyboard::Up) 
                {
                    myMainMenu.moveUp();
                    break;
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    myMainMenu.moveDown();
                    break;
                }    

                if (event.key.code == sf::Keyboard::Return) 
                {
                    sf::RenderWindow play(VM, "She Ping on my Pong till I C++");
                    sf::RenderWindow highScore(VM, "HighScore");
                    
                    int x = myMainMenu.mainMenuPressed();
                    if (x == 0)
                    {
                        //Reset the game on play
                        lives = 4;
                        points = 0;

                        //Update lives and score in the same loop
                        ssLives.str("");
                        ssLives << "Lives: " << lives;
                        fontLives.setString(ssLives.str());

                        ssPoints.str("");
                        ssPoints << "Points: " << points;
                        fontPoints.setString(ssPoints.str());

                        while (play.isOpen())
                        {
                            deltaTime = clock.restart();
                            bounceTimer -= deltaTime.asSeconds();

                            if (myBall.getPosition().intersects(myPaddle.getPosition()))
                            {
                                if (bounceTimer < 0)
                                {
                                    myBall.hitBottomVoid();
                                    bounceTimer = 0.10f;
                                    points++;
                                    ssPoints.str("");
                                    ssPoints << "Points: " << points;
                                    fontPoints.setString(ssPoints.str());
                                }
                            }

                            sf::Event playEvent;
                            while (play.pollEvent(playEvent))
                            {
                                if (playEvent.type ==sf::Event::Closed)
                                {
                                    play.close();
                                }

                                if (playEvent.type == sf::Event::KeyPressed)
                                {
                                    if (playEvent.key.code == sf::Keyboard::Escape)
                                    {
                                        play.close();
                                    }
                                }
                            }


                            //Makes the window closable by pressing the Escape key;
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || lives < 1)
                            {
                                if (points > highScorePoints) {
                                    highScorePoints = points;
                                }

                                play.close();
                            }

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                            {
                                myPaddle.moveLeft();
                            }
                            else
                            {
                                myPaddle.stopLeft();
                            }

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                            {
                                myPaddle.moveRight();
                            }
                            else
                            {
                                myPaddle.stopRight();
                            }


                            //When the ball position is beyond 0 in the X axis or the screen width then it changes the X direction;
                            if (myBall.getPosition().left < 0 || myBall.getPosition().left + myBall.getPosition().width > VM.width)
                            {
                                myBall.bounceSided();
                            }

                            //When the ball position goes beyond 0 in the Y axis it changes the Y direction;
                            if (myBall.getPosition().top < 0 && bounceTimer < 0)
                            {
                                myBall.bounceTop();
                                bounceTimer = 0.10f;
                            }

                            //When the ball position goes beyond the screen height it goes back to the top of the screen;
                            if (myBall.getPosition().top + myBall.getPosition().height > VM.height)
                            {
                                myBall.hitBottomVoid();
                                lives--;
                                ssLives.str("");
                                ssLives << "Lives: " << lives;
                                fontLives.setString(ssLives.str());
                            }

                            play.clear(sf::Color(139, 172, 15));
                            highScore.close();

                            //Update gameObjects
                            myBall.update(deltaTime);
                            myPaddle.update(deltaTime);

                            //Draw all gameObjects
                            play.draw(myBall.getShape());
                            play.draw(myPaddle.getShape());
                            play.draw(fontLives);
                            play.draw(fontPoints);

                            play.display();
                        }
                    }

                    if (x == 1)
                    {
                        ssHighScore.str("");
                        ssHighScore << "HighScore: " << highScorePoints;
                        fontHighScore.setString(ssHighScore.str());

                        while (highScore.isOpen())
                        {

                            sf::Event highScoreEvent;
                            while (highScore.pollEvent(highScoreEvent))
                            {
                                if (highScoreEvent.type == sf::Event::Closed)
                                {
                                    highScore.close();
                                }

                                if (highScoreEvent.type == sf::Event::KeyPressed)
                                {
                                    if (highScoreEvent.key.code == sf::Keyboard::Escape)
                                    {
                                        highScore.close();
                                    }
                                }
                            }
                            play.close();
                            highScore.clear(sf::Color(139, 172, 15));

                            highScore.draw(fontHighScore);

                            highScore.display();
                        }
                    }

                    if (x == 2)
                    {
                        menu.close();
                        break;
                    }
                }
            }
        }
        //Refresh the menu
        menu.clear(sf::Color(155,188,15));
        myMainMenu.draw(menu);
        menu.display();
    }
    return 0;
}
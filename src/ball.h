// Author: Ben Knisley [Benknisley@gmail.com]
// Date: Jul 21, 2015
// Description: Header file for ball game objects, where the structures
// of objects relating to the game are defined.
#include <QPainter>
#include <QString>
#include <iostream>
using namespace std;

// Defines the background object.
class gameBackground{
  public:
    int width; // Holds how wide the background is
    int height; // Holds how tall the background is
    explicit gameBackground(void); // Construtor
    void draw(QPainter* painter); // The Draw Function
    void resize(int x, int y); // The resize function
};

// Defines the ball object.
class ballObj{
  public:
    int radius; // Holds size of ball
    int xPos; // Holds x position of ball
    int yPos; // Holds y position of ball
    int xVelo; // Holds how far ball moves per tick, x
    int yVelo; // Hold how far ball moves per tick, y
    explicit ballObj( void ); // Construtor
    void move(gameBackground background); // Move Function
    void draw(QPainter* painter); // Draw Function
};

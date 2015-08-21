#include "ball.h"

gameBackground::gameBackground(void){
  gameBackground::width = 600;
  gameBackground::height = 600;
}


void gameBackground::draw(QPainter *painter){
    painter->setPen( QPen(Qt::black) );
    painter->setBrush( QBrush(Qt::black) );
    painter->drawRect(0, 0, gameBackground::width, gameBackground::height );
}

void gameBackground::resize(int x, int y){
  gameBackground::height = y;
  gameBackground::width = x;
}


ballObj::ballObj(){
  ballObj::radius = 10;
  ballObj::xPos = 0;
  ballObj::yPos = 100;
  ballObj::xVelo = 5;
  ballObj::yVelo = 1;
}

void ballObj::move(gameBackground background){
  // Move Ball
  ballObj::xPos += ballObj::xVelo;
  ballObj::yPos += ballObj::yVelo;

  //
  if( (ballObj::xPos <= 0) || (ballObj::xPos + (ballObj::radius * 2) >= background.width) ){
      // Flip X direction
      ballObj::xVelo = (0 - ballObj::xVelo);
  }
  if( (ballObj::yPos <= 0) || (ballObj::yPos + (ballObj::radius * 2) >= background.height) ){
      // Flip X direction
      ballObj::yVelo = (0 - ballObj::yVelo);
  }
}


void ballObj::draw(QPainter* painter){
    painter->setBrush( QBrush(Qt::red, Qt::SolidPattern) );
    painter->drawEllipse(xPos, yPos, (ballObj::radius * 2), (ballObj::radius * 2) );

    painter->setPen( QPen(Qt::green) );
    QString posString = QString::number(xPos) + ", " + QString::number(yPos);
    painter->drawText( (xPos + 20) , (yPos + 10), posString);
}

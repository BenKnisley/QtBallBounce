// Author: Ben Knisley [Benknisley@gmail.com]
// Date: Jul 21, 2015
// Description: Impliments..

#include "mainWindow.h"

void yolo(QPainter* p){
  p->setBrush(QBrush(Qt::black, Qt::SolidPattern));
  p->drawRect(0, 0, 100, 100);
}


MainWindow::MainWindow( void ){
  // Set Window Properties
  resize(500, 400);
  MainWindow::Background.resize(500, 400);
  setWindowTitle("Ball Bounce");

  timer->start(25);
  connect( timer, SIGNAL( timeout() ), this, SLOT( timeout() ) );
}

void MainWindow::paintEvent(QPaintEvent *event){
  QPainter painter(this);
  painter.setPen( QPen(Qt::black) );


  painter.setRenderHint(QPainter::Antialiasing, true);
  MainWindow::Background.draw(&painter);

  MainWindow::ballTrailx.push_back( MainWindow::ball.xPos + MainWindow::ball.radius );
  MainWindow::ballTraily.push_back( MainWindow::ball.yPos + MainWindow::ball.radius );


  // Deletes old elements from trail vectors
  if(ballTrailx.size() > 5000){
    ballTrailx.erase( ballTrailx.begin() );
    ballTraily.erase( ballTraily.begin() );
  }

  // Draw Trail
  for(int i = 0; i != ballTrailx.size(); ++i){
    painter.setPen( QPen(Qt::green) );
    painter.drawPoint( ballTrailx.at(i), ballTraily.at(i) );
  }
  painter.setPen( QPen(Qt::black) );




  MainWindow::ball.draw(&painter);
}


void MainWindow::resizeEvent(QResizeEvent *event){
  MainWindow::Background.resize( width(), height() );
}



void MainWindow::timeout(){
  MainWindow::ball.move(MainWindow::Background);
  update();
}

// Author: Ben Knisley [Benknisley@gmail.com]
// Date: Jul 21, 2015
// Description: Header file for MainWindow, where the structure
// of MainWindow is defined.
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <vector>
#include "ball.h"
using namespace std;

class MainWindow : public QWidget{
  Q_OBJECT
  public:
    // Game Objects
    gameBackground Background;
    ballObj ball;

    // Pair of vectors holding points for trail
    vector<int> ballTrailx;
    vector<int> ballTraily;

    // Timer object for game ticks
    QTimer* timer = new QTimer;

    // Constructor
    explicit MainWindow( void );

    // Reimplipmented paintEvent
    void paintEvent(QPaintEvent *event);
    // Reimplipmented resizeEvent
    void resizeEvent(QResizeEvent *event);

  public slots:
    // Slot for game tick timer
    void timeout();
};

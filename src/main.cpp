// Author: Ben Knisley [Benknisley@gmail.com]
// Date: Jul 21, 2015
// Description: Holds the program's main function, where the QT
// QApplication is created, and MainWindow is launched.

#include <QApplication>
#include "mainWindow.h"
using namespace std;

int main(int argc, char* argv[]){
		QApplication app(argc, argv);
		MainWindow main;
    main.show();
    return app.exec();
}

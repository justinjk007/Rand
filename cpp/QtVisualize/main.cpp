#include <QApplication>
#include <QString>
#include "externalClass.hpp"
#include "mainwindow.h"

using namespace std;
using namespace QtCharts;

// This macro disables the extra cmd window popup when in Microsoft windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    externalClass test;

    QObject::connect(&test, SIGNAL(contentChanged(content)), &w, SLOT(updatePentagonInfo(content)));

    // Window settings
    w.setWindowTitle("Pentagonal Tiling - Visulization");
    w.setWindowIcon(QIcon("favicon.ico"));
    w.setStyleSheet("QMainWindow {background: rgb(147,161,161);}");  // Set background color

    // Update the info about pentagons
    QString side1 = QString::number(23);
    QString content =
        QString("<span style=\" font-size:18pt; font-weight:300; font-family:Hack,Arial;\"\\>") +
        "Sides: " + side1 + "</span>";
    w.updatePentagonInfo(content);  // Update data

    // Update the fitness graph
    w.updateFitnessGraph();  // Update data

    // Update tiling generation

    // After all this time
	test.generateRandom();
    w.show();
    
    return a.exec();
}

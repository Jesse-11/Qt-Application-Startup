// mainwindow.cpp
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Simple E-Health Portal");
    resize(800, 600);  // Set a default size
}

MainWindow::~MainWindow()
{
}
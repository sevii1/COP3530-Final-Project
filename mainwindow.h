#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HashTable.h"
#include "RedBlackTree/redblacktree.h"

#pragma once

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, bool h = true);
    ~MainWindow();
    void initialize();
    bool validateInput();
    bool checkMovie(Movie movie);
    bool checkDecade(int year);
    bool checkGenre(vector<string> genres);
    bool checkRuntime(int runtime);
    bool checkRating(float rating);
    void printMovies(vector<Movie> movies, int index);

private slots:

    void showEvent(QShowEvent *ev);
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    bool isHash;
    HashTable movieTable;
    RBT movieTree;
};
#endif // MAINWINDOW_H

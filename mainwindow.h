#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
};
#endif // MAINWINDOW_H

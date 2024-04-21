#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Movie {
    string title;
    int year;
    int runtime;
    vector<string> genre;
    float rating;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool validateInput();
    bool checkMovie(Movie movie);
    bool checkDecade(int year);
    bool checkGenre(vector<string> genres);
    bool checkRuntime(int runtime);
    bool checkRating(float rating);
    void printMovies(vector<Movie> movies, int index);

private slots:

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

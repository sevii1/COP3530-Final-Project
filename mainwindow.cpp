#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{
    vector<Movie> movieList;
    movieList.push_back({"The Empire Strikes Back", 1980, 124, {"Action", "Adventure", "Fantasy"}, 8.7f});
    movieList.push_back({"Look Back in Anger", 1985, 127, {"Fantasy"}, 8.7f});
    movieList.push_back({"A New Hope", 1979, 123, {"Action", "Adventure", "Fantasy"}, 7.8f});
    /*ui->testLabel->setText("The test was successful!"
                           "\nThe decade is " + ui->comboBox->currentText() +
                           "\nThe genre is " + ui->comboBox_2->currentText() +
                           "\nThe minimum runtime is " + QVariant(ui->minRuntime->displayText().size()).toString() +
                           "\nThe maximum runtime is " + ui->maxRuntime->displayText());*/
    vector<Movie> foundList;
    ui->RuntimeErrorLabel->setText("");
    ui->RatingErrorLabel->setText("");
    if(validateInput()) {
        for (int i = 0; i < movieList.size(); i++) {
            if(checkMovie(movieList[i])) {
                foundList.push_back(movieList[i]);
            }
        }
        int index = 0;
        printMovies(foundList, index);
    }
}

bool MainWindow::validateInput() {
    bool valid = true;
    if(!ui->minRuntime->displayText().toInt() || !ui->maxRuntime->displayText().toInt()) {
        ui->RuntimeErrorLabel->setText("Error! Please enter a valid integer");
        valid = false;
    }
    else if(ui->minRuntime->displayText().toInt() >= ui->maxRuntime->displayText().toInt()) {
        ui->RuntimeErrorLabel->setText("Error! Minimum must be less than maximum");
        valid = false;
    }
    if(!ui->minRating->displayText().toFloat() || !ui->maxRating->displayText().toFloat()) {
        ui->RatingErrorLabel->setText("Error! Please enter a valid float");
        valid = false;
    }
    else if(ui->minRating->displayText().toFloat() >= ui->maxRating->displayText().toFloat()) {
        ui->RatingErrorLabel->setText("Error! Minimum must be less than maximum");
        valid = false;
    }
    else if(ui->minRating->displayText().toFloat() > 10.0f || ui->maxRating->displayText().toFloat() > 10.0f) {
        ui->RatingErrorLabel->setText("Error! Rating must be between 0 and 10.");
        valid = false;
    }
    if (valid) {
        return true;
    }
    return false;
}

bool MainWindow::checkMovie(Movie movie) {
    if(!checkDecade(movie.year)){
        return false;
    }
    if(!checkGenre(movie.genre)) {
        return false;
    }
    if(!checkRuntime(movie.runtime)) {
        return false;
    }
    if(!checkRating(movie.rating)) {
        return false;
    }
    return true;
}

bool MainWindow::checkDecade(int year){
    if (year >= ui->comboBox->currentText().toInt() && year < ui->comboBox->currentText().toInt() + 10) {
        return true;
    }
    return false;
}

bool MainWindow::checkGenre(vector<string> genres) {
    for(int i  = 0; i < genres.size(); i++) {
        if(genres[i] == ui->comboBox_2->currentText().toStdString()){
            return true;
        }
    }
    return false;
}

bool MainWindow::checkRuntime(int runtime) {
    if(runtime >= ui->minRuntime->displayText().toInt() && runtime <= ui->maxRuntime->displayText().toInt()) {
        return true;
    }
    return false;
}

bool MainWindow::checkRating(float rating) {
    if(rating >= ui->minRating->displayText().toFloat() && rating <= ui->maxRuntime->displayText().toFloat()) {
        return true;
    }
    return false;
}

void MainWindow::printMovies(vector<Movie> movies, int index) {
    //deletes all existing widgets in the movie list, if any
    if(ui->MovieBox->layout() != NULL) {
        QLayoutItem* tempItem;
        while((tempItem = ui->MovieBox->layout()->takeAt(0)) != NULL) {
            delete tempItem->widget();
            delete tempItem;
        }
    }

    if (movies.size() != 0) {
        while(index < movies.size()) {
            QLabel *tempLabel = new QLabel;
            tempLabel->setText("Title: " + QString::fromStdString(movies[index].title) +
                               "\nRelease Year: " + QVariant(movies[index].year).toString() +
                               "\nRating: " + QVariant(movies[index].rating).toString() +
                               "\nRuntime: " + QVariant(movies[index].runtime).toString() + "minutes");
            tempLabel->setAlignment(Qt::AlignTop);
            ui->MovieBox->addWidget(tempLabel);
            if (index == 5) {
                break;
            }
            index++;
        }
    } else {
        QLabel* errorLabel = new QLabel;
        errorLabel->setText("No movies found\nmatching this criteria.");
        errorLabel->setAlignment(Qt::AlignTop);
        ui->MovieBox->addWidget(errorLabel);
    }
}

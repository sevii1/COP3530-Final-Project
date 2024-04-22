#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "HashTable.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <locale>

using namespace std;



//default constructor and destructor were created with template
MainWindow::MainWindow(QWidget *parent, bool h)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isHash = h;
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Helper functions to handle conversions safely
// Originally written by Waleed, Maddy had to move them to a different file
int safeStoi(const std::string& str, int defaultVal = 0) {
    try {
        return std::stoi(str);
    } catch (...) {
        return defaultVal;
    }
}

float safeStof(const std::string& str, float defaultVal = 0.0f) {
    try {
        return std::stof(str);
    } catch (...) {
        return defaultVal;
    }
}


void MainWindow::initializeTable() {
    //This function was primarily written by Waleed, minorly tweaked by Maddy to make it work with UI
    std::locale::global(std::locale("C"));  // Ensure correct numeric formatting
    string filename = R"(C:\Users\1upjl\OneDrive\Documents\DSA Project 3\untitled\Project3DatabaseMOVIESONLY.csv)";
    std::ifstream file(filename);
    std::string line, word;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }

    std::getline(file, line);  // Skip the header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Movie movie;
        std::string genreWord;
        std::string tempGenre;

        std::getline(ss, word, ','); // Skip titleType
        std::getline(ss, movie.title, ','); //Register the primary title as the one that saves
        std::getline(ss, word, ','); // Read original title
        std::getline(ss, word, ','); movie.year = safeStoi(word);
        std::getline(ss, word, ','); movie.runtime = safeStoi(word);
        std::getline(ss, genreWord, ',');
        if(genreWord[0] == '"'){
            std::getline(ss, tempGenre, '"');
            genreWord.erase(0,1);
            genreWord += "," + tempGenre;
            std::getline(ss, word, ',');
        }
        std::getline(ss, word, ','); movie.rating = safeStof(word);

        // Parse genres
        std::stringstream genreStream(genreWord);
        while (std::getline(genreStream, word, ',')) {
            movie.genre.push_back(word);
        }

        movieTable.insert(movie);  // Use primary title as key
    }

    file.close();
}

//this function runs once the main window is open
void MainWindow::showEvent(QShowEvent *ev) {
    //initializes based on what structure it's using
    //this will do actual stuff later!!!
    if(isHash) {
        ui->structureUsed->setText("Structure in use: Hash Map");
        initializeTable();
    } else {
        ui->structureUsed->setText("Structure in use: B Tree");
    }
    //hides the test label, comment out if things need to be tested
    ui->testLabel->hide();
}



//activates whenever search button is clicked
void MainWindow::on_searchButton_clicked()
{



    //this is just temporary. Used for testing parsing and all that until the other two
    //finish their structures
    vector<Movie> movieList;
    movieList.push_back({"The Empire Strikes Back", 1980, 124, {"Action", "Adventure", "Fantasy"}, 8.7});
    movieList.push_back({"Look Back in Anger", 1985, 127, {"Fantasy"}, 8.7});
    movieList.push_back({"A New Hope", 1979, 123, {"Action", "Adventure", "Fantasy"}, 7.8});

    //was previously used for a test label to make sure I was reading user input correctly
    /*ui->testLabel->setText("The test was successful!"
                           "\nThe decade is " + ui->comboBox->currentText() +
                           "\nThe genre is " + ui->comboBox_2->currentText() +
                           "\nThe minimum runtime is " + QVariant(ui->minRuntime->displayText().size()).toString() +
                           "\nThe maximum runtime is " + ui->maxRuntime->displayText());*/
    vector<Movie> foundList;
    //sets the error labels to empty text, e
    ui->RuntimeErrorLabel->setText("");
    ui->RatingErrorLabel->setText("");
    //check for valid input in the text boxes. Can't have invalid input in dropdowns so no need to validate
    if(validateInput()) {
        //if all user input is valid, then go through the list of movies and put anything that meets criteria in there
        //this will very likely be changed later

        //test code

        /*
        for (int i = 0; i < movieList.size(); i++) {
            if(checkMovie(movieList[i])) {
                foundList.push_back(movieList[i]);
            }
        }*/

        if (isHash) {

            for(int i = 0; i < movieTable.getCap(); i++) {
                for(auto iter : movieTable.table[i]) {
                    if(checkMovie(iter)) {
                        foundList.push_back(iter);
                    }
                }
            }
        }
        //set index to 0 here instead of in function because I think I'm gonna try to make separate pages soon so I need to do it out of the function
        //I think
        int index = 0;
        printMovies(foundList, index);
    }
}

bool MainWindow::validateInput() {
    //this function ensures user input is all valid
    bool valid = true;
    //if minRuntime or maxRuntime contain a non-integer (or 0 strangely enough) then display an error message
    if(!ui->minRuntime->displayText().toInt() || !ui->maxRuntime->displayText().toInt()) {
        ui->RuntimeErrorLabel->setText("Error! Please enter a valid integer");
        valid = false;
    }
    //if minRuntime is greater than or equal to maxRuntime display an error message
    else if(ui->minRuntime->displayText().toInt() >= ui->maxRuntime->displayText().toInt()) {
        ui->RuntimeErrorLabel->setText("Error! Minimum must be less than maximum");
        valid = false;
    }
    //if minRating or maxRating isn't a float (or again 0) display an error
    //whatever a movie can't be 0 minutes or have a rating of 0 anyway it doesn't matter I think
    if(!ui->minRating->displayText().toFloat() || !ui->maxRating->displayText().toFloat()) {
        ui->RatingErrorLabel->setText("Error! Please enter a valid float");
        valid = false;
    }
    //if minRating is greater than or equal to maxRating display an error message
    else if(ui->minRating->displayText().toFloat() >= ui->maxRating->displayText().toFloat()) {
        ui->RatingErrorLabel->setText("Error! Minimum must be less than maximum");
        valid = false;
    }
    //if either of them are greater than 10 display an error. I can't really stop the user from inputting bigger numbers with the-
    //textbox itself like I did with runtime so whatever you get an error if you want a movie with an 11/10 on IMDB
    else if(ui->minRating->displayText().toFloat() > 10.0f || ui->maxRating->displayText().toFloat() > 10.0f) {
        ui->RatingErrorLabel->setText("Error! Rating must be between 0 and 10.");
        valid = false;
    }
    //if any of these were caught then return false
    if (valid) {
        return true;
    }
    return false;
}


// !!THIS STUFF WILL VERY LIKELY GET CHANGED BUT IT MAKES SENSE FOR NOW!!
// if all of this is true then it is in fact, a valid movie
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

//if the year of the movie is within the decade return TRUE
bool MainWindow::checkDecade(int year){
    if (year >= ui->comboBox->currentText().toInt() && year < ui->comboBox->currentText().toInt() + 10) {
        return true;
    }
    return false;
}

//if the user inputted genre is in the movie's list of genres return TRUE
bool MainWindow::checkGenre(vector<string> genres) {
    for(int i  = 0; i < genres.size(); i++) {
        if(genres[i] == ui->comboBox_2->currentText().toStdString()){
            return true;
        }
    }
    return false;
}

//if the movie's runtime is in the range the user submitted return TRUE
bool MainWindow::checkRuntime(int runtime) {
    if(runtime >= ui->minRuntime->displayText().toInt() && runtime <= ui->maxRuntime->displayText().toInt()) {
        return true;
    }
    return false;
}

//same thing but for rating
bool MainWindow::checkRating(float rating) {
    if(rating >= ui->minRating->displayText().toFloat() && rating <= ui->maxRuntime->displayText().toFloat()) {
        return true;
    }
    return false;
}

//truncates down to one decimal
double truncate(double rating) {
    int i = rating * 10;
    double trunc = (double)i / 10;
    return trunc;
}

//YEAAAAAH this is the one where the fun stuff happens
//sorry my comments are getting increasingly more unhinged I am very tired right now
void MainWindow::printMovies(vector<Movie> movies, int index) {
    //deletes all existing widgets in the movie list, if any
    //based on a code snippet from someone on stackoverflow I'll find the link tomorrow
    if(ui->MovieBox->layout() != NULL) {
        QLayoutItem* tempItem;
        while((tempItem = ui->MovieBox->layout()->takeAt(0)) != NULL) {
            delete tempItem->widget();
            delete tempItem;
        }
    }

    //enter this loop if there are actually any movies to display. Not always the case for this very very small test set I have
    //but very likely will be when we implement the data structures with like 400k elements in them
    if (movies.size() != 0) {
        while(index < movies.size()) {
            //have to create new labels for these programatically because Qt is weird and LAME!!!
            //(it actually makes perfect sense I'm just tired and this took me a while to figure out sorry qt I love you I'll never insult you again)
            QLabel *tempLabel = new QLabel;
            string genres = movies[index].genre[0];
            for (int i = 1; i < movies[index].genre.size(); i++) {
                genres += (", " + movies[index].genre[i]);
            }
            //set the label to all the info in the movie...
            tempLabel->setText("Title: " + QString::fromStdString(movies[index].title) +
                               "\nRelease Year: " + QVariant(movies[index].year).toString() +
                               "\nRating: " + (QVariant(truncate(movies[index].rating))).toString() + "/10" +
                               "\nRuntime: " + QVariant(movies[index].runtime).toString() + " minutes" +
                               "\nGenres: " + QString::fromStdString(genres));
            //...align it to the top...
            tempLabel->setAlignment(Qt::AlignTop);
            //...and then add it to the widget I made for the movie list
            ui->MovieBox->addWidget(tempLabel);
            //I only wanna display the top 5 movies. Any more gets to be too overwhelming I think. Parsing through
            //a 400k element list all to get 5 movies seems to be a bit unnecessary but oh well

            //also for some reason it would always just go out of index if I put this in the while loop so I used a break instead
            //maybe fix this in a later commit
            if (index == 4) {
                break;
            }
            index++;
        }
    } else {
        //this chunk exists if there are no movies in foundList
        //just displays a message saying that nothing's there, it's as shrimple as that
        QLabel* errorLabel = new QLabel;
        errorLabel->setText("No movies found\nmatching this criteria.");
        errorLabel->setAlignment(Qt::AlignTop);
        ui->MovieBox->addWidget(errorLabel);
    }
}

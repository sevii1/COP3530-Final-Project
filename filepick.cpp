#include "filepick.h"
#include "ui_filepick.h"
#include "mainwindow.h"


//This screen lets the user (me) select which structure I want to test with
FilePick::FilePick(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FilePick)
{
    ui->setupUi(this);
}

FilePick::~FilePick()
{
    delete ui;
}


void FilePick::on_HM_clicked()
{
    MainWindow *w= new MainWindow(nullptr, true);
    w->show();
    FilePick::close();
}


void FilePick::on_BT_clicked()
{
    MainWindow *w= new MainWindow(nullptr, false);
    w->show();
    FilePick::close();
}


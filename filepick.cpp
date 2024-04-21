#include "filepick.h"
#include "ui_filepick.h"

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

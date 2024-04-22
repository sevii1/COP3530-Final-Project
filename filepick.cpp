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


bool FilePick::on_HM_clicked()
{
    return true;
}


bool FilePick::on_BT_clicked()
{
    return false;
}


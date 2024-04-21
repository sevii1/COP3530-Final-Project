#ifndef FILEPICK_H
#define FILEPICK_H

#include <QDialog>

namespace Ui {
class FilePick;
}

class FilePick : public QDialog
{
    Q_OBJECT

public:
    explicit FilePick(QWidget *parent = nullptr);
    ~FilePick();

private:
    Ui::FilePick *ui;
};

#endif // FILEPICK_H

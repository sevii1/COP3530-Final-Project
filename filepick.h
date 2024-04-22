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
    bool returnStruct();

private slots:

    bool on_HM_clicked();

    bool on_BT_clicked();

private:
    Ui::FilePick *ui;
};

#endif // FILEPICK_H

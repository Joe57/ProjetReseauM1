#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void majNumeroOption(char* num);

public slots :
    void on_btnOk_clicked();
    void on_radioButton_1_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <QMessageBox>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOk_clicked(){
    std::string numeroOption = ui->numeroOption->text().toStdString();
    std::string valeurOption = ui->valeurOption->text().toStdString();

    if((numeroOption.compare("") == 0) || (valeurOption.compare("") == 0))
        QMessageBox::warning(this, "Attention", "Il faut choisir une option et entrer une valeur pour continuer");
    else {
        int f = fork();
        if(f < 0)
            this->close();
        else if(f == 0) {
            system("gnome-terminal -x sh -c './client'");
            exit(1);
        }
        else {
            std::string commande = "gnome-terminal -x sh -c './serveur " + numeroOption + " " + valeurOption + "'";
            system(commande.c_str());
        }
    }

}

void MainWindow::on_radioButton_1_clicked(){
    this->ui->valeurOption->setText("1");
    this->majNumeroOption("1");
}

void MainWindow::on_radioButton_2_clicked(){
    this->majNumeroOption("2");
}

void MainWindow::on_radioButton_3_clicked(){
    this->majNumeroOption("3");
}

void MainWindow::on_radioButton_4_clicked(){
    this->majNumeroOption("4");
}

void MainWindow::on_radioButton_5_clicked(){
    this->majNumeroOption("5");
}

void MainWindow::on_radioButton_6_clicked(){
    this->majNumeroOption("6");
}

void MainWindow::on_radioButton_7_clicked(){
    this->majNumeroOption("7");
}

void MainWindow::on_radioButton_8_clicked(){
    this->majNumeroOption("8");
}

void MainWindow::majNumeroOption(char* num){
    ui->numeroOption->setText(QString(num));
}

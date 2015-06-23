#include "mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
  dialog = new QFileDialog();
  dialog->show();
  selectedFiles = dialog->selectedFiles();
}

void MainWindow::on_pushButton_3_clicked()
{
  QListWidgetItem *newItem = new QListWidgetItem;
  newItem->setText(ui->lineEdit->text());
  ui->listWidget->insertItem(0, newItem);
}

void MainWindow::on_pushButton_clicked()
{
  QFile* file = new QFile(selectedFiles.first());
  file->open(QIODevice::ReadWrite);
  file->readLine();
}

void MainWindow::InsertIncludes()
{

}

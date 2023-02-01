#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

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


void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName();
        if (path.isEmpty())return;
        QFile file(path);
        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray ba = file.readAll();
            QString text(ba);
            ui->plainTextEdit->setPlainText(text);

        }
}


void MainWindow::on_pushButton_2_clicked()
{

QStringList data = getData(???);// что сюда передать???
ui->plainTextEdit->setPlainText(data[0]);
ui->plainTextEdit_2->setPlainText(data[1]);
ui->plainTextEdit_3->setPlainText(data[2]);
}

QStringList MainWindow::getData(const QString &html)
{
    QStringList list;
    QRegularExpression regex("(span calss=\"inite-stocks__value_inner\">([\\d,]+)(выражение для температуры)(<\span>)");
    int lastPos = 0;
    while((lastPos = regex.indexIn(html,lastPos))!=-1)
    {
        lastPos+=regex.matchedLength();
        list.append(regex.cap(3));
    }
    return list;
}

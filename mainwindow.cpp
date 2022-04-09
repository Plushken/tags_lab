#include "mainwindow.h"
#include "tags.h"
#include <QPicture>
#include <QMessageBox>
#include "ui_mainwindow.h"

Tags tg;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nullWidgets();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerShow()));
    timer->start(1);
    for (auto i = 0; i < 4; i++)
    {
        ui->twTags->setColumnWidth(i, 70);
        ui->twTags->setRowHeight(i, 70);
    }

    for (int i=0; i<16; i++)
        {
        itTags[i] = new QTableWidgetItem;
        itTags[i]->setBackground(QBrush(Qt::green));
        itTags[i] -> setTextAlignment(Qt::AlignCenter);
        }
    itTags[0] -> setText("1");
    itTags[1] -> setText("2");
    itTags[2] -> setText("3");
    itTags[3] -> setText("4");
    itTags[4] -> setText("5");
    itTags[5] -> setText("6");
    itTags[6] -> setText("7");
    itTags[7] -> setText("8");
    itTags[8] -> setText("9");
    itTags[9] -> setText("10");
    itTags[10] -> setText("11");
    itTags[11] -> setText("12");
    itTags[12] -> setText("13");
    itTags[13] -> setText("14");
    itTags[14] -> setText("15");
    itTags[15] -> setText(" ");

    showTable();
}

void MainWindow::showTable()
{

    for (auto i = 0; i < 4; i++)
        for (auto j = 0; j < 4; j++)
        {
            int value = tg.getItem(i,j);
            ui->twTags->setItem(i, j, new QTableWidgetItem(*itTags[value]));
        }
    MovesShow();
}

void MainWindow::nullWidgets()
{
    moves=0;
    ms=0;
    s=0;
    m=0;
}

void MainWindow::on_twTags_cellClicked(int row, int column)
{
    if(tg.reCalc(row, column))
        moves++;
    showTable();
    if(tg.isFinished())
    {
        QMessageBox::information(this, "Статистика", "Количестов ходов - "+QString::number(moves)+"\nВремя - "+QString::number(m)+":"+QString::number(s));
        if(QMessageBox::question(this, "Игра закончена!", "Победа! Желаете сыграть ещё раз?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
            QApplication::quit();
        else
        {
            nullWidgets();
            tg.startGame();
            showTable();
        }
    }
}

void MainWindow::on_mnuNewGame_triggered()
{
    nullWidgets();
    tg.startGame();
    showTable();
}

void MainWindow::on_mnuRestart_triggered()
{
    nullWidgets();
    tg.restartGame();
    showTable();
}

void MainWindow::on_mnuExit_triggered()
{
    QApplication::quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerShow()
{
    ms++;
    if(ms>=1000)
    {
        ms = 0;
        s++;
    }
    if(s>=60)
    {
        s = 0;
        m++;
    }
    ui->timeLabel->setText(QString::number(m) + ":" + QString::number(s));
}

void MainWindow::MovesShow()
{
    ui->movesLabel->setText(QString::number(moves));
}

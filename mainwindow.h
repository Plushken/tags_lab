#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void TimerShow();

    void on_twTags_cellClicked(int row, int column);

    void on_mnuRestart_triggered();

    void on_mnuExit_triggered();

    void on_mnuNewGame_triggered();

    void MovesShow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int s, m, ms;
    int moves;
    void showTable();
    void nullWidgets();

    QTableWidgetItem *itTags[15];
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
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


    void on_btnrun_clicked();

private:
    Ui::MainWindow *ui;

    const QVector<QString> NamesOfAlgos = {
         "mergesort",
        "quicksort",
        "heapsort",
        "countingsort",
        "radixsort",
        "insertionsort",
        "bucketsort",
        "horspool",
        "boyermoor"
    };

    bool areValidNumbers(const QVector<QString>&listofnumbers, const QRegularExpression& expr);



};
#endif // MAINWINDOW_H

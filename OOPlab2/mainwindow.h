#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include "facade.h"
#include "algoslib.h"
#include <memory>
#include <functional>

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

    void on_algoselector_currentIndexChanged(int index);



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

    template <typename T>
      static bool comparatorAscend(T a ,  T b)
      {
          if(a >=b)
              return true;

          return false;
      }

      template <typename T>
        bool comparatorDescend(T a ,  T b)
        {
            if(a <=b)
                return true;

            return false;
        }

    Facade* facade = nullptr;
    algorithm* algorithm_;
   // std::unique_ptr<algorithm> algorithm_ = nullptr;
};
#endif // MAINWINDOW_H

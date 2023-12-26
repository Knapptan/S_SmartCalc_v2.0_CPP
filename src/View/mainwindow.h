#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QRegularExpression>
#include <QWidget>
#include <cstdlib>

#include "../Controller/CalculatorController.h"
#include "credit.h"
#include "deposit.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  QString tmp_str;

 private slots:
  void input_button_clicked();
  void deleteLastCharacter();
  void on_equal_Button_clicked();
  void on_graph_Button_clicked();
  void on_credit_Button_clicked();
  void on_deposit_Button_clicked();

  void on_info_Button_clicked();

 private:
  Ui::MainWindow *ui;
  s21::CalculatorController controller;
  Graph graph;
  Credit credit;
  Deposit deposit;
};
#endif  // MAINWINDOW_H

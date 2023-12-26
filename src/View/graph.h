#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QVector>
#include <QWidget>

#include "../Controller/CalculatorController.h"

namespace Ui {
class Graph;
}

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();

  QVector<double> x, y;
  void setExpression(QString expression);
  void defaultExpression();
  void open_sets();

 private slots:
  void on_plot_Button_clicked();
  void on_stock_Button_clicked();
  void on_clear_Button_clicked();

 private:
  Ui::Graph *ui;
  s21::CalculatorController controller;
  double xBegin, xEnd, h, X;
  int N;
};

#endif  // GRAPH_H

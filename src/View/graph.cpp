#include "graph.h"

#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QWidget(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
}

Graph::~Graph() { delete ui; }

void Graph::on_plot_Button_clicked() {
  std::string expressionStd = ui->label_funk->text().toStdString();
  double x_min = ui->min_edit_x->text().toDouble();
  double x_max = ui->max_edit_x->text().toDouble();
  double y_min = ui->min_edit_y->text().toDouble();
  double y_max = ui->max_edit_y->text().toDouble();

  if (x_min >= x_max || y_min >= y_max || x_min < -1000000 || x_max > 1000000 ||
      y_min < -1000000 || y_max > 1000000) {
    ui->widget->clearGraphs();
    QMessageBox::critical(this, "Error", "Enter valid values");
    return;
  }

  x.clear();
  y.clear();

  if (!expressionStd.empty()) {
    if (expressionStd.find("x") != std::string::npos) {
      for (double x_value = x_min; x_value < x_max; x_value += 0.1) {
        try {
          double result =
              controller.GrafCalculateExpression(expressionStd, x_value);
          x.push_back(x_value);
          y.push_back(result);
        } catch (const std::exception &e) {
          QMessageBox::critical(this, "Error", e.what());
          return;
        }
      }
    } else {
      for (double x_value = x_min; x_value < x_max; x_value += 0.01) {
        try {
          double result =
              controller.GrafCalculateExpression(expressionStd, x_value);
          x.push_back(x_value);
          y.push_back(result);
        } catch (const std::exception &e) {
          QMessageBox::critical(this, "Error", e.what());
          return;
        }
      }
    }

    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(x_min, x_max);
    ui->widget->yAxis->setRange(y_min, y_max);
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->replot();
  } else {
    QMessageBox::critical(this, "Error", "Enter valid function");
  }
}

void Graph::setExpression(QString expression) {
  ui->label_funk->setText(expression);
}

void Graph::defaultExpression() { ui->label_funk->setText("Ваша функция"); }

void Graph::open_sets() {
  x.clear();
  y.clear();
  ui->widget->clearGraphs();
  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-5, 5);
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}

void Graph::on_stock_Button_clicked() {
  ui->min_edit_x->setText("-10");
  ui->max_edit_x->setText("10");
  ui->min_edit_y->setText("-5");
  ui->max_edit_y->setText("5");
}

void Graph::on_clear_Button_clicked() {
  x.clear();
  y.clear();
  ui->label_funk->setText("");
  ui->widget->clearGraphs();
  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-5, 5);
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}

#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->zero_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->one_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->two_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->tree_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->four_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->five_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->six_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->seven_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->eight_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->nine_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->plus_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->minus_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->mult_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->divide_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->dot_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->open_br_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->close_br_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->x_Button, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->mod_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->exp_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->sin_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->asin_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->cos_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->acos_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->tan_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->atan_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->ln_Button, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->log_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->sqrt_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->delete_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->clear_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->line_input, SIGNAL(returnPressed()), this,
          SLOT(on_equal_Button_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::input_button_clicked() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());

  if (button) {
    QString btn_text = button->text();

    if (btn_text == "C") {
      ui->line_input->clear();
      ui->result->clear();
      ui->x_input->setText("0");
    } else if (btn_text == "⌫") {
      deleteLastCharacter();
    } else if (btn_text.contains(QRegularExpression("[0-9x+\\-()^.*]"))) {
      ui->line_input->setText(ui->line_input->text() + btn_text);
    } else if (btn_text.contains("√")) {
      ui->line_input->setText(ui->line_input->text() + "sqrt(");
    } else if (btn_text.contains("÷")) {
      ui->line_input->setText(ui->line_input->text() + "/");
    } else if (btn_text.contains("%")) {
      ui->line_input->setText(ui->line_input->text() + " mod ");
    } else {
      ui->line_input->setText(ui->line_input->text() + btn_text + "(");
    }
  }
}

void MainWindow::deleteLastCharacter() {
  QString currentText = ui->line_input->text();

  if (!currentText.isEmpty()) {
    currentText.chop(1);
    ui->line_input->setText(currentText);
  }
}

void MainWindow::on_equal_Button_clicked() {
  std::string expressionStd = ui->line_input->text().toStdString();
  std::string xStd = ui->x_input->text().toStdString();
  try {
    double result = controller.CalculateExpression(expressionStd, xStd);
    ui->result->setText(QString::number(result));
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Error", e.what());
    ui->result->setText("");
  }
}

void MainWindow::on_graph_Button_clicked() {
  QString expression = ui->line_input->text();
  if (!expression.isEmpty())
    graph.setExpression(expression);
  else
    graph.defaultExpression();
  graph.open_sets();
  graph.show();
}

void MainWindow::on_credit_Button_clicked() { credit.show(); }

void MainWindow::on_deposit_Button_clicked() { deposit.show(); }

void MainWindow::on_info_Button_clicked() {
  system("open ../documentation.md");
}

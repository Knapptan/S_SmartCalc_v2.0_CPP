#ifndef CREDIT_H
#define CREDIT_H

#include <QButtonGroup>
#include <QDialog>
#include <QMessageBox>
#include <QWidget>

#include "../Controller/CalculatorController.h"

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();
  void SetMonthly(double monthly);
  void SetOverpayment(double overpayment);
  void SetTotal(double total);

 private slots:
  void on_clear_Button_clicked();
  void on_calculate_Button_clicked();

 private:
  Ui::Credit *ui;
  QButtonGroup *termButtons;
  QButtonGroup *typeButtons;
  s21::CalculatorController controller;
};

#endif  // CREDIT_H

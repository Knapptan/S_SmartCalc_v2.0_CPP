#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QButtonGroup>
#include <QDialog>
#include <QMessageBox>
#include <QWidget>

#include "../Controller/CalculatorController.h"

namespace Ui {
class Deposit;
}

class Deposit : public QWidget {
  Q_OBJECT

 public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();
  void SetResult(double result);
  void SetTaxWith(double tax_with);
  void SetAccruedInterest(double accrued_interest);

 private slots:
  void on_pushButton_res_clicked();
  void on_clear_Button_clicked();

 private:
  Ui::Deposit *ui;
  s21::CalculatorController controller;
};

#endif  // DEPOSIT_H

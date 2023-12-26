#include "CalculatorController.h"

#include "../View/credit.h"
#include "../View/deposit.h"

namespace s21 {
double CalculatorController::CalculateExpression(const std::string& expression,
                                                 const std::string& x) {
  model_.CalculateAnswer(expression, x);
  return model_.GetAnswer();
}

double CalculatorController::GrafCalculateExpression(
    const std::string& expression, const double x) {
  model_.GrafCalculateAnswer(expression, x);
  return model_.GetAnswer();
}

void CalculatorController::CalculateCredit(bool isDifferentiated, double amount,
                                           double interest, double term,
                                           Credit* credit_window) {
  CreditCalculator calculator(amount, interest, term);
  calculator.calculate_credit(isDifferentiated);
  credit_window->SetMonthly(calculator.get_monthly());
  credit_window->SetOverpayment(calculator.get_overpayment());
  credit_window->SetTotal(calculator.get_total());
}

void CalculatorController::CalculateDeposit(
    double summ, double n, double interest_rate, double tax_rate,
    int periodicity_payments, int capitalization, int count_add, double add,
    int count_sub, double sub, Deposit* deposit_window) {
  DepositCalculator calculator(summ, n, interest_rate, tax_rate,
                               periodicity_payments, capitalization, count_add,
                               add, count_sub, sub);
  calculator.calculate_deposit();
  deposit_window->SetResult(calculator.get_result());
  deposit_window->SetTaxWith(calculator.get_tax_with());
  deposit_window->SetAccruedInterest(calculator.get_accrued_interest());
}
}  // namespace s21

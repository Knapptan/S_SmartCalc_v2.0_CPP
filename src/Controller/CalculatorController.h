#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "../Model/CalculatorModel.h"
#include "../Model/CreditCalculator.h"
#include "../Model/DepositCalculator.h"

class Credit;
class Deposit;
namespace s21 {
class CalculatorController {
 public:
  CalculatorController()
      : credit_(0, 0, 0), deposit_(0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {}
  ~CalculatorController() {}
  double CalculateExpression(const std::string& expression,
                             const std::string& x);
  double GrafCalculateExpression(const std::string& expression, const double x);
  void CalculateCredit(bool isDifferentiated, double amount, double interest,
                       double term, Credit* credit_window);
  void CalculateDeposit(double summ, double n, double interest_rate,
                        double tax_rate, int periodicity_payments,
                        int capitalization, int count_add, double add,
                        int count_sub, double sub, Deposit* deposit_window);

 private:
  CalculatorModel model_;
  CreditCalculator credit_;
  DepositCalculator deposit_;
};
}  // namespace s21

#endif  // CALCULATORCONTROLLER_H

#ifndef DEPOSIT_CALCULATOR_H
#define DEPOSIT_CALCULATOR_H

#include <cmath>
#include <sstream>

namespace s21 {
class DepositCalculator {
 public:
  DepositCalculator() = default;
  ~DepositCalculator() = default;
  DepositCalculator(double summ, double n, double interest_rate,
                    double tax_rate, int periodicity_payments,
                    int capitalization, int count_add, double add,
                    int count_sub, double sub)
      : summ_(summ),
        n_(n),
        interest_rate_(interest_rate),
        tax_rate_(tax_rate),
        periodicity_payments_(periodicity_payments),
        capitalization_(capitalization),
        count_add_(count_add),
        add_(add),
        count_sub_(count_sub),
        sub_(sub) {}

  void calculate_deposit();
  double get_result() const;
  double get_tax_with() const;
  double get_accrued_interest() const;

 private:
  double summ_;
  double n_;
  double interest_rate_;
  double tax_rate_;
  int periodicity_payments_;
  int capitalization_;
  int count_add_;
  double add_;
  int count_sub_;
  double sub_;

  double result_ = 0.0;
  double tax_with_ = 0.0;
  double accrued_interest_ = 0.0;

  void process_add_and_sub();
  void calculate_tax();
};
}  // namespace s21

#endif  // DEPOSIT_CALCULATOR_H
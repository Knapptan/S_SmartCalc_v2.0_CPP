#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <cmath>
#include <stdexcept>

namespace s21 {
class CreditCalculator {
 public:
  CreditCalculator() = default;
  ~CreditCalculator() = default;
  CreditCalculator(double credit_sum, double interest_rate, double credit_time);

  void calculate_credit(bool flagDiff);
  double get_monthly() const;
  double get_overpayment() const;
  double get_total() const;

 private:
  double credit_sum_;
  double interest_rate_;
  double credit_time_;

  double monthly_ = 0.0;
  double overpayment_ = 0.0;
  double total_ = 0.0;

  double annuity_calc() const;
  double diff_calc(double &total) const;
};
}  // namespace s21

#endif  // CREDIT_CALCULATOR_H

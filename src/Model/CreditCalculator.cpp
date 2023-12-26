#include "CreditCalculator.h"

namespace s21 {
CreditCalculator::CreditCalculator(double credit_sum, double interest_rate,
                                   double credit_time)
    : credit_sum_(credit_sum),
      interest_rate_(interest_rate),
      credit_time_(credit_time) {}

void CreditCalculator::calculate_credit(bool flagDiff) {
  if (credit_sum_ < 0 || interest_rate_ < 0 || credit_time_ < 0)
    throw std::logic_error("Calculation error: negative input");
  else if (!flagDiff) {
    monthly_ = annuity_calc();
    total_ = get_monthly() * credit_time_;
  } else {
    monthly_ = diff_calc(total_);
  }
  overpayment_ = get_total() - credit_sum_;

  if (get_monthly() < 0.0 || get_overpayment() < 0.0 || get_total() < 0.0) {
    throw std::logic_error("Calculation error: negative result");
  }
}

double CreditCalculator::annuity_calc() const {
  double rate = interest_rate_ / 1200.0;
  return credit_sum_ * rate / (1 - std::pow(1 + rate, 0 - credit_time_));
}

double CreditCalculator::diff_calc(double &total) const {
  double res = 0;
  double start_credit_sum = credit_sum_;
  double sd = credit_sum_ / credit_time_;
  int i = 0;
  double first = 0, last = 0;
  double days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while (start_credit_sum > 0.001) {
    last = sd + (start_credit_sum * (interest_rate_ / 100.0) * days[i]) / 365.0;
    last = std::round(last * 100) / 100;
    if (!i) first = last;
    if (i == 11)
      i = 0;
    else
      i++;
    start_credit_sum -= sd;
    total += last;
  }
  res = (first + last) / 2;
  return res;
}

double CreditCalculator::get_monthly() const { return monthly_; }

double CreditCalculator::get_overpayment() const { return overpayment_; }

double CreditCalculator::get_total() const { return total_; }

}  // namespace s21

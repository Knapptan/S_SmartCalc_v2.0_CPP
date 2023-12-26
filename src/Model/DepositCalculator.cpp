#include "DepositCalculator.h"

namespace s21 {
void DepositCalculator::calculate_deposit() {
  int flag = 0;
  if (summ_ < 0 || n_ < 0 || interest_rate_ < 0 || interest_rate_ < 0 ||
      tax_rate_ < 0 || periodicity_payments_ < 0 || capitalization_ < 0 ||
      count_add_ < 0 || add_ < 0 || count_sub_ < 0 || sub_ < 0)
    throw std::logic_error("Calculation error: negative input");
  if (capitalization_ == 2) {
    for (int i = 0; i < n_ && !flag; i++) {
      process_add_and_sub();
      double month_per = (summ_ * interest_rate_ / 36500) * 30;
      accrued_interest_ += month_per;
    }
    result_ = summ_ + accrued_interest_;
    calculate_tax();
  } else if (capitalization_ == 1 && periodicity_payments_ == 2) {
    double month_per = 0;
    for (int i = 0; i < n_ && !flag; i++) {
      process_add_and_sub();
      month_per = (summ_ * interest_rate_ / 36500) * 30;
      accrued_interest_ += month_per;
    }
    result_ = summ_ + month_per;
    calculate_tax();
  } else if (capitalization_ == 1 && periodicity_payments_ == 1) {
    double month_per = 0;
    for (int i = 0; i < n_ && !flag; i++) {
      process_add_and_sub();
      month_per = (summ_ * interest_rate_ / 36500) * 30;
      accrued_interest_ += month_per;
    }
    result_ = summ_ + accrued_interest_;
    calculate_tax();
  }
}

double DepositCalculator::get_result() const { return result_; }

double DepositCalculator::get_tax_with() const { return tax_with_; }

double DepositCalculator::get_accrued_interest() const {
  return accrued_interest_;
}

void DepositCalculator::process_add_and_sub() {
  int flag = 0;

  if (count_add_ && count_sub_)
    summ_ = summ_ + add_ - sub_;
  else if (!count_add_ && count_sub_)
    summ_ = summ_ - sub_;
  else if (count_add_ && !count_sub_)
    summ_ = summ_ + add_;

  if (summ_ < 0) flag = 1;
  if (flag) throw std::logic_error("Calculation error: negative result");
}

void DepositCalculator::calculate_tax() {
  if (accrued_interest_ >= 75000)
    tax_with_ = accrued_interest_ * (tax_rate_ / 100);
  else
    tax_with_ = 0;
}
}  // namespace s21

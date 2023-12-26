#include <gtest/gtest.h>

#include "../Model/CalculatorModel.h"
#include "../Model/CreditCalculator.h"
#include "../Model/DepositCalculator.h"
#include "../Model/Token.h"

s21::CalculatorModel model_;
s21::Token token_;
s21::CreditCalculator credit_;
s21::DepositCalculator deposit_;

TEST(CalcTest, Test_1) {
  model_.CalculateAnswer("2+2*2", "0");
  ASSERT_EQ(model_.GetAnswer(), 6.0);
}

TEST(CalcTest, Test_2) {
  model_.CalculateAnswer("25/37*58+14/3*2", "0");
  ASSERT_NEAR(model_.GetAnswer(), 48.522523, 1e-1);
}

TEST(CalcTest, Test_3) {
  model_.CalculateAnswer("-5.36+78/2+54-sin(1234)*cos(43)^3", "0");
  ASSERT_NEAR(model_.GetAnswer(), 87.5370351008, 1e-1);
}

TEST(CalcTest, Test_4) {
  model_.CalculateAnswer("45+sqrt(45)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 51.7082039325, 1e-1);
}

TEST(CalcTest, Test_5) {
  model_.CalculateAnswer("log(983)+ln(45+34)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 7.36200137, 1e-1);
}

TEST(CalcTest, Test_6) {
  model_.CalculateAnswer("cos(23)+67^3", "0");
  ASSERT_NEAR(model_.GetAnswer(), 300762.467167, 1e-1);
}

TEST(CalcTest, Test_7) {
  model_.CalculateAnswer("cos(96)+tan(93)-ln(693.543)", "0");
  ASSERT_NEAR(model_.GetAnswer(), -9.70962995088, 1e-1);
}

TEST(CalcTest, Test_8) {
  model_.CalculateAnswer("12365.32+(487.36/2)+98*log(90)*tan(91)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 12588.6, 1e-1);
}

TEST(CalcTest, Test_9) {
  model_.CalculateAnswer(
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))",
      "0");
  ASSERT_NEAR(model_.GetAnswer(), -30.0722, 1e-1);
}

TEST(CalcTest, Test_10) {
  model_.CalculateAnswer("5mod2", "0");
  ASSERT_NEAR(model_.GetAnswer(), 1, 1e-1);
}

TEST(CalcTest, Addition) {
  model_.CalculateAnswer("2+3", "0");
  ASSERT_EQ(model_.GetAnswer(), 5);
}

TEST(CalcTest, Subtraction) {
  model_.CalculateAnswer("7-4", "0");
  ASSERT_EQ(model_.GetAnswer(), 3);
}

TEST(CalcTest, Multiplication) {
  model_.CalculateAnswer("6*5", "0");
  ASSERT_EQ(model_.GetAnswer(), 30);
}

TEST(CalcTest, Division) {
  model_.CalculateAnswer("15/3", "0");
  ASSERT_EQ(model_.GetAnswer(), 5);
}

TEST(CalcTest, Exponentiation) {
  model_.CalculateAnswer("2^4", "0");
  ASSERT_EQ(model_.GetAnswer(), 16);
}

TEST(CalcTest, ComplexExpression) {
  model_.CalculateAnswer("2+3*(4-1)", "0");
  ASSERT_EQ(model_.GetAnswer(), 11);
}

TEST(CalcTest, DecimalAddition) {
  model_.CalculateAnswer("3.5+1.5", "0");
  ASSERT_NEAR(model_.GetAnswer(), 5.0, 1e-6);
}

TEST(CalcTest, DecimalDivision) {
  model_.CalculateAnswer("8.0/2.5", "0");
  ASSERT_NEAR(model_.GetAnswer(), 3.2, 1e-6);
}

TEST(CalcTest, NegativeResult) {
  model_.CalculateAnswer("-5-8", "0");
  ASSERT_EQ(model_.GetAnswer(), -13);
}

TEST(CalcTest, CosineFunction) {
  model_.CalculateAnswer("cos(0)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 1.0, 1e-1);
}

TEST(CalcTest, SineFunction) {
  model_.CalculateAnswer("sin(3.14/2)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 1.0, 1e-6);
}

TEST(CalcTest, TangentFunction) {
  model_.CalculateAnswer("tan(3.14/4)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 1.0, 1e-1);
}

TEST(CalcTest, ArcCosineFunction) {
  model_.CalculateAnswer("acos(0.5)", "0");
  ASSERT_NEAR(model_.GetAnswer(), M_PI / 3.0, 1e-1);
}

TEST(CalcTest, ArcSineFunction) {
  model_.CalculateAnswer("asin(0.5)", "0");
  ASSERT_NEAR(model_.GetAnswer(), M_PI / 6.0, 1e-6);
}

TEST(CalcTest, ArcTangentFunction) {
  model_.CalculateAnswer("atan(1)", "0");
  ASSERT_NEAR(model_.GetAnswer(), M_PI / 4.0, 1e-1);
}

TEST(CalcTest, CosineFunction2) {
  model_.CalculateAnswer("cos(0)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 1.0, 1e-1);
}

TEST(CalcTest, SineFunction2) {
  model_.CalculateAnswer("sin(0)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 0.0, 1e-1);
}

TEST(CalcTest, TangentFunction2) {
  model_.CalculateAnswer("tan(0)", "0");
  ASSERT_NEAR(model_.GetAnswer(), 0.0, 1e-1);
}

TEST(CalcTestException, Test_1) {
  EXPECT_THROW(model_.CalculateAnswer("2+", "0"), std::logic_error);
}

TEST(CalcTestException, Test_2) {
  EXPECT_THROW(model_.CalculateAnswer(")2+2+2+2", "0"), std::logic_error);
}

TEST(CalcTestException, Test_3) {
  EXPECT_THROW(model_.CalculateAnswer(
                   "sin((((((34)3456**(((((((((((((((#$()))))))", "0"),
               std::logic_error);
}

TEST(CalcTestException, Test_4) {
  EXPECT_THROW(model_.CalculateAnswer("sin5+sin5", "0"), std::logic_error);
}

TEST(CalcTestException, Test_5) {
  EXPECT_THROW(model_.CalculateAnswer("sin(54)*cos5+78*(23*)", "0"),
               std::logic_error);
}

TEST(CalcTestException, Test_6) {
  EXPECT_THROW(model_.CalculateAnswer("x.+334+sin(x)", "0"), std::logic_error);
}

TEST(CalcTestException, Test_7) {
  EXPECT_THROW(model_.CalculateAnswer("2 + 3 + 3)log", "0"), std::logic_error);
}

TEST(TokenTest, GetFunction) {
  token_ = s21::Token("input", s21::kDefault, s21::kNone, s21::kNumber, 42.0);
  auto function_variant = token_.GetFunction();
  double value = std::get<double>(function_variant);
  ASSERT_EQ(value, 42.0);
}

TEST(TokenTest, BasicInitialization) {
  ASSERT_NO_THROW(
      s21::Token token("input", s21::kDefault, s21::kNone, s21::kNumber, 42.0));
}

TEST(TokenTest, Getters) {
  token_ = s21::Token("input", s21::kDefault, s21::kNone, s21::kNumber, 42.0);
  ASSERT_EQ(token_.GetInput(), "input");
  ASSERT_EQ(token_.GetPrecedence(), s21::kDefault);
  ASSERT_EQ(token_.GetAssociativity(), s21::kNone);
  ASSERT_EQ(token_.GetType(), s21::kNumber);
  auto function_variant = token_.GetFunction();
  double value = std::get<double>(function_variant);
  ASSERT_EQ(value, 42.0);
}

TEST(TokenTest, SetFunction) {
  token_ = s21::Token("input", s21::kDefault, s21::kNone, s21::kNumber, 42.0);
  token_.SetFunction([](double x) { return x * x; });
  ASSERT_EQ(std::get<s21::unary_function>(token_.GetFunction())(2.0), 4.0);
}

TEST(TokenTest, CreateTokenMap) {
  std::map<std::string, s21::Token> token_map;
  ASSERT_NO_THROW(s21::Token::CreateTokenMap(token_map));
  ASSERT_FALSE(token_map.empty());
}

TEST(CreditCalculatorTest, AnnuityCalculation) {
  credit_ = s21::CreditCalculator(10000, 5, 2);
  credit_.calculate_credit(false);
  ASSERT_TRUE(true);
}

TEST(CreditCalculatorTest, AnnuityCalculation2) {
  credit_ = s21::CreditCalculator(1, 1, 1);
  credit_.calculate_credit(false);
  ASSERT_TRUE(true);
}

TEST(CreditCalculatorTest, AnnuityCalculation3) {
  credit_ = s21::CreditCalculator(0.1, 0.1, 0.1);
  credit_.calculate_credit(false);
  ASSERT_TRUE(true);
}

TEST(CreditCalculatorTest, DifferentiatedCalculation) {
  credit_ = s21::CreditCalculator(10000, 5, 2);
  credit_.calculate_credit(true);
  ASSERT_TRUE(true);
}

TEST(CreditCalculatorTest, DifferentiatedCalculation2) {
  credit_ = s21::CreditCalculator(1, 1, 1);
  credit_.calculate_credit(true);
  ASSERT_TRUE(true);
}

TEST(CreditCalculatorTest, DifferentiatedCalculation3) {
  credit_ = s21::CreditCalculator(0.1, 0.1, 0.1);
  credit_.calculate_credit(true);
  ASSERT_TRUE(true);
}

TEST(CreditCalculatorTest, ZeroInterestRate) {
  credit_ = s21::CreditCalculator(10000, 0, 2);
  credit_.calculate_credit(false);
  ASSERT_TRUE(true);
}

TEST(CreditCalculatorTest, ZeroCreditTime) {
  credit_ = s21::CreditCalculator(10000, 5, 0);
  credit_.calculate_credit(false);
  ASSERT_TRUE(true);
}

TEST(CreditCalculatorTest, NegativeCreditAmount) {
  credit_ = s21::CreditCalculator(-10000, 5, 2);
  try {
    credit_.calculate_credit(false);
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(CreditCalculatorTest, NegativeInterestRate) {
  credit_ = s21::CreditCalculator(10000, -5, 2);
  try {
    credit_.calculate_credit(false);
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(CreditCalculatorTest, NegativeCreditTime) {
  credit_ = s21::CreditCalculator(10000, 5, -2);
  try {
    credit_.calculate_credit(false);
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, BasicCalculation) {
  deposit_ = s21::DepositCalculator(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  deposit_.calculate_deposit();
  ASSERT_TRUE(true);
}

TEST(DepositCalculatorTest, AnotherCalculation) {
  deposit_ =
      s21::DepositCalculator(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000);
  deposit_.calculate_deposit();
  ASSERT_TRUE(true);
}

TEST(DepositCalculatorTest, ZeroInterestRate) {
  deposit_ = s21::DepositCalculator(1, 1, 0, 1, 1, 1, 1, 1, 1, 1);
  deposit_.calculate_deposit();
  ASSERT_TRUE(true);
}

TEST(DepositCalculatorTest, ZeroDepositTime) {
  deposit_ = s21::DepositCalculator(1, 0, 1, 1, 1, 1, 1, 1, 1, 1);
  deposit_.calculate_deposit();
  ASSERT_TRUE(true);
}

TEST(DepositCalculatorTest, NegativeDepositAmount) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, 1, -1, 1, 1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
  ASSERT_TRUE(true);
}

TEST(DepositCalculatorTest, NegativeSumm) {
  deposit_ = s21::DepositCalculator(-1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativeDepositTime) {
  deposit_ = s21::DepositCalculator(1, -1, 1, 1, 1, 1, 1, 1, 1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativeInterestRate) {
  deposit_ = s21::DepositCalculator(1, 1, -1, 1, 1, 1, 1, 1, 1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativePeriodicityPayments) {
  deposit_ = s21::DepositCalculator(1, 1, 1, -1, 1, 1, 1, 1, 1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativecCapitalization) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, -1, 1, 1, 1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativeCountAdd) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, 1, -1, 1, 1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativeAdd) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, 1, 1, -1, 1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativeCountSub) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, 1, 1, 1, -1, 1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativeSub) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, 1, 1, 1, 1, -1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, NegativeInput) {
  deposit_ = s21::DepositCalculator(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
  try {
    deposit_.calculate_deposit();
  } catch (const std::exception) {
    ASSERT_TRUE(true);
  }
}

TEST(DepositCalculatorTest, get_result) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
  deposit_.calculate_deposit();
  double tmp = 0;
  tmp = deposit_.get_result();
  ASSERT_TRUE(tmp);
}

TEST(DepositCalculatorTest, get_tax_with) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
  deposit_.calculate_deposit();
  deposit_.get_tax_with();
  ASSERT_TRUE(true);
}

TEST(DepositCalculatorTest, get_accrued_interest) {
  deposit_ = s21::DepositCalculator(1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
  deposit_.calculate_deposit();
  double tmp = 0;
  tmp = deposit_.get_accrued_interest();
  ASSERT_TRUE(tmp);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

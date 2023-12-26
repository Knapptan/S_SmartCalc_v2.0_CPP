#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <math.h>

#include <cstring>
#include <iostream>
#include <queue>
#include <regex>
#include <sstream>
#include <stack>
#include <string>

#include "Token.h"

namespace s21 {
class CalculatorModel {
 public:
  CalculatorModel() = default;
  ~CalculatorModel() = default;
  CalculatorModel(const CalculatorModel&) = default;
  CalculatorModel(CalculatorModel&&) noexcept = default;
  CalculatorModel& operator=(const CalculatorModel&) = default;
  CalculatorModel& operator=(CalculatorModel&&) noexcept = default;

  double GetAnswer();
  void CalculateAnswer(const std::string& input_expression,
                       const std::string& input_x);
  void GrafCalculateAnswer(const std::string& input_expression,
                           const double input_x);

 private:
  void Tokenize(const std::string& expression);
  std::string ReadWord(const std::string& expression, size_t& start_index);
  double ReadNumber(const std::string& expression, size_t& start_index);
  std::string ReadSingleChar(const std::string& expression,
                             size_t& start_index);
  void TryToPushToken(std::string token);
  void ConvertInfixToPostfix();
  void MoveTokenFromInputToOutput();
  void MoveTokenFromInputToStack();
  void MoveTokenFromStackToOutput();
  void ModifyQueue();
  void ValidateQueue();
  double PostfixExpressionCalculate(double x_value);
  void PushToResult(const function_variant& value);
  double PopFromResult();
  std::string toLowerCase(const std::string& str);
  bool CheckBrackets(const std::string& expression);

  std::queue<Token> input_;
  std::queue<Token> output_;
  std::stack<Token> stack_;
  std::stack<double> result_;
  double answer_ = 0.0;

  std::map<std::string, Token> token_map_;
  static constexpr bool kAdjacencyMatrix[kNumTokenTypes][kNumTokenTypes] = {
      {0, 1, 0, 1, 0, 0, 1}, {1, 0, 1, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 0}, {1, 0, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 1},
  };
};
}  // namespace s21
#endif  // CALCULATORMODEL_H

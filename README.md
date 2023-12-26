## Отчет о выполненной работе

### Общая информация

**Название проекта:** SmartCalc v2.0

**Язык программирования:** C++17

**Структура проекта:**
- Весь код программы размещен в папке `src`.
- Собранный код и исполняемый файл находятся в папке `build`.
- Makefile содержит правила для сборки программы, проведения тестирования и формирования отчетов о покрытии.

### Реализованные возможности

1. **Арифметические операторы и функции:**
   - Поддержка скобочных арифметических выражений в инфиксной нотации.
   - Поддержка операторов: `+`, `-`, `*`, `/`, `^`, `mod` (остаток от деления).
   - Унарные операторы: унарный `+` и унарный `-`.
   - Поддержка функций: `cos`, `sin`, `tan`, `acos`, `asin`, `atan`, `sqrt`, `ln`, `log`.

2. **Графический интерфейс пользователя (GUI):**
   - Используется GUI-библиотека Qt для построения графического интерфейса.
   - Реализована модель-представление-контроллер (MVC) архитектура.
   - Пользователь может вводить выражения, видеть результат вычислений и построение графиков.

3. **Вычисление выражений:**
   - Программа поддерживает вычисление выражений с использованием переменной `x`.
   - Возможность вычисления произвольных скобочных арифметических выражений с переменной `x`.
   - Поддержка чисел в различных форматах, включая вещественные числа и запись в экспоненциальной форме.

4. **График функций:**
   - Реализовано построение графика функции, заданной выражением в инфиксной нотации с переменной `x`.
   - Отображение координатных осей, масштабной линейки и адаптивной сетки.
   - Возможность указания области определения и области значений для функций.

### Тестирование

1. **Unit-тесты:**
   - Использована библиотека Google Test (GTest) для написания unit-тестов.
   - Тесты покрывают основные арифметические операторы, функции и вычисление выражений.

2. **Покрытие кода тестами:**
   - Для оценки покрытия кода тестами использован инструмент `lcov`.
   - Сгенерирован отчет о покрытии кода, исключены системные и тестовые файлы из отчета.

### Кредитный калькулятор (дополнительно, Part 2)

1. **Реализация кредитного калькулятора:**
   - Добавлен специальный режим "кредитный калькулятор".
   - Входные данные: общая сумма кредита, срок, процентная ставка, тип кредита (аннуитетный, дифференцированный).
   - Выходные данные: ежемесячный платеж, переплата по кредиту, общая выплата.

### Депозитный калькулятор (дополнительно, Part 3)

1. **Реализация депозитного калькулятора:**
   - Добавлен специальный режим "калькулятор доходности вкладов".
   - Входные данные: сумма вклада, срок размещения, процентная ставка, налоговая ставка, периодичность выплат, капитализация процентов, список пополнений, список частичных снятий.
   - Выходные данные: начисленные проценты, сумма налога, сумма на вкладе к концу срока.

### Замечания

1. **Точность дробной части:**
   - Результаты вычислений предоставляются с минимум 7 знаками после запятой.

## Project Report: SmartCalc v2.0

### General Information

**Project Name:** SmartCalc v2.0

**Programming Language:** C++17

**Project Structure:**
- All code is located in the `src` folder.
- Compiled code and the executable file are in the `build` folder.
- The Makefile contains rules for building the program, running tests, and generating coverage reports.

### Implemented Features

1. **Arithmetic Operators and Functions:**
   - Support for bracketed arithmetic expressions in infix notation.
   - Support for operators: `+`, `-`, `*`, `/`, `^`, `mod` (remainder of division).
   - Unary operators: unary `+` and unary `-`.
   - Support for functions: `cos`, `sin`, `tan`, `acos`, `asin`, `atan`, `sqrt`, `ln`, `log`.

2. **Graphical User Interface (GUI):**
   - Utilizes the Qt GUI library for building the graphical interface.
   - Implements Model-View-Controller (MVC) architecture.
   - Users can input expressions, view calculation results, and visualize function graphs.

3. **Expression Evaluation:**
   - The program supports evaluating expressions using the variable `x`.
   - Ability to evaluate arbitrary bracketed arithmetic expressions with the variable `x`.
   - Support for numbers in various formats, including floating-point numbers and exponential notation.

4. **Function Graphs:**
   - Implements graphing of a function defined by an expression in infix notation with the variable `x`.
   - Displays coordinate axes, scale ruler, and adaptive grid.
   - Allows specifying the domain and range for functions.

### Testing

1. **Unit Tests:**
   - Google Test (GTest) library is used for writing unit tests.
   - Tests cover basic arithmetic operators, functions, and expression evaluation.

2. **Code Coverage:**
   - The `lcov` tool is used to assess code coverage by tests.
   - A coverage report is generated, excluding system and test files.

### Credit Calculator (Additional, Part 2)

1. **Implementation of the Credit Calculator:**
   - Added a special mode for the "credit calculator."
   - Input data: total loan amount, term, interest rate, loan type (annuity, differentiated).
   - Output data: monthly payment, overpayment, total payment.

### Deposit Calculator (Additional, Part 3)

1. **Implementation of the Deposit Calculator:**
   - Added a special mode for the "deposit yield calculator."
   - Input data: deposit amount, placement term, interest rate, tax rate, payment frequency, interest capitalization, list of deposits, list of partial withdrawals.
   - Output data: accrued interest, tax amount, deposit amount at the end of the term.

### Notes

1. **Decimal Precision:**
   - Calculation results are provided with a minimum of 7 decimal places.

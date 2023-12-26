# Implementation of SmartCalc v2.0.

## Instruction for Makefile:

Make all: build an app 
создать приложение

Make uninstall: uninstall an app 
удалить приложение

Make dvi: open this documentation 
открыть эту документацию

Make dist: tar an app 
архивировать приложение

Make tests: run unit tests for model part of an app 
запустить модульные тесты для модельной части приложения

Make gcov_report: run tests and get report about code coverage
запустить тесты и получить отчет о покрытии кода

Make format: check format all code
проверить форматирование всего кода

Make clang-format: reformat all code
переформатировать весь код

Make clean: clear the project of excess
очистить проект от лишнего

## SmartCalc v2.0 by Knapptan


### Описание проекта:

Эта программа представляет собой универсальный калькулятор, который позволяет пользователям выполнять различные вычисления, включая вычисление арифметических выражений, построение графиков функций, расчет кредитов и депозитов.

Программа предоставляет интуитивно понятный пользовательский интерфейс для ввода выражений и просмотра результатов.

Калькулятор предлагает большую гибкость и точность, что делает его пригодным для различных математических расчетов и финансовых расчетов.

Пользователи могут эффективно считать сложные арифметические выражения, визуализировать графики функций и принимать обоснованные финансовые решения, используя режим кредитного и депозитного калькуляторов. 

Программа реализована с использованием паттерна MVC что подразумевает деление программы на 3 части View, Controller, Model.

#### View 
Включает в себя визуальную часть приложения разработанную в прилдожении QT qreator включает в себя 4 окна - основоное mainwindow, которое содержит кнопки и место для ввода выражения, graph окно которое содержит виджет отрисовки график сторонней библиотеки qcustomplot и поля для изменения поля отрисовки.

#### Controller 
Включает в себя класс CalculatorController который находится в пространстве имен s21 и имеет методы для взаимодействия модельной части и визуальной.

#### Model 
Включает в себя модельную часть программы классы: CalculatorModel, Token, CreditCalculator, DepositCalculator которые находятся в пространстве имен s21.

##### CalculatorModel 
Основоной класс модельной части содержащий в себе всю логи вычислительного процесса и также логику постороения графика.

Ход программы можно разбить на несколько этапов:

Tokenize: В этом этапе входное арифметическое выражение разбивается на токены. Каждый токен представляет собой число, букву или одиночный символ оператора. Строка выражения приводится к нижнему регистру, и затем происходит проход по каждому символу, где определяется его тип (буква, цифра, оператор) и вызываются соответствующие методы для обработки токена.

ModifyQueue: На этом этапе происходит модификация очереди токенов. В частности, определяются унарные плюсы и минусы. Если символ "-" следует за числом или закрытой скобкой, то он считается унарным минусом. Также определяется унарный плюс.

ValidateQueue: Здесь происходит валидация очереди токенов. Проверяется, что первый и последний токены соответствуют ожидаемым типам. Также проверяется последовательность токенов на предмет их корректной комбинации.

ConvertInfixToPostfix: Этот этап выполняет преобразование инфиксной записи в постфиксную. Используется стек для временного хранения операторов. В результате работы этого этапа формируется очередь токенов в постфиксной нотации.

PostfixExpressionCalculate: На этом этапе происходит вычисление значения арифметического выражения в постфиксной нотации. Используется стек для хранения промежуточных результатов и операндов. Результат сохраняется в переменной answer_.

GetAnswer: Этот метод предоставляет окончательный результат вычислений.

Весь процесс направлен на преобразование входного арифметического выражения в форму, которую легко вычислить. Это включает в себя разбиение выражения на токены, обработку унарных операторов, проверку корректности выражения, преобразование инфиксной нотации в постфиксную и, наконец, вычисление значения выражения.

##### Token 
Вспомогательный класс CalculatorModel содержит в себе описание типа токен - тип токена - число, бинарный оператор, унарный оператор префиксный/постфиксный, унарная функция, отрытие скобок, закрытие скобок, приоритет, асоциативность. 

##### CreditCalculator 
Класс кредитной модели получает параметры для вычислений в конструкторе, есть методы для возврата ответов.

##### DepositCalculator 
Класс депозитной модели получает параметры для вычислений в конструкторе, есть методы для возврата ответов.

### Вычисление арифметического выражения:

Пользователи могут вводить произвольные арифметические выражения в инфиксной нотации, используя распространенные арифметические операторы, такие как сложение, вычитание, умножение, деление, степень и модуль.

Калькулятор точно вычисляет выражения до 7 знаков после запятой и может обрабатывать выражения до 255 символов.

Он поддерживает математические функции, такие как косинус, синус, тангенс, арккосинус, арксинус, арктангенс, квадратный корень, натуральный логарифм и десятичный логарифм.

### Построение графика:

Пользователи могут строить графики функций, заданных в инфиксной нотации с переменной «x».

Программа предоставляет удобную систему координат с нанесенными шкалами и адаптивной сеткой.

Домен и кодовый домен функции ограничены диапазоном от -1 000 000 до 1 000 000, но пользователь может указать отображаемый домен и кодовый домен для построения графика.

Чтобы создать изображение графика, пользователь должен ввести уравнение, щелкнуть кнопку "GRAPH" и нажать кнопку "Отрисовать" или также есть возможность ввода в окне гафики и вывода по нажатию на энтер.

### Кредитный калькулятор:

В программу включен специальный режим, известный как "Кредитный калькулятор".

Пользователи могут вводить такие данные, как общая сумма кредита, срок (длительность), процентная ставка и тип кредита (аннуитетный или дифференцированный).

На основе введенных данных калькулятор предоставляет такую ​​информацию, как ежемесячный платеж, переплата по кредиту и общая сумма платежа.

### Депозитный калькулятор:

В программу включен специальный режим, известный как "Депозитный калькулятор".

Пользователи могут вводить такие данные, как общая сумма вклада, срок (длительность), процентная ставка, налоговая ставка, переодичность выплат, капитализация и также есть опции пополнения и снятия.

На основе введенных данных калькулятор предоставляет такую ​​информацию, сумма начислений, сумма вклада с процентами и сумма уержанных налогов.


### Description of the project:


This program is a universal calculator that allows users to perform various calculations, including calculating arithmetic expressions, plotting functions, calculating loans and deposits.

The program provides an intuitive user interface for entering expressions and viewing results.

The calculator offers great flexibility and accuracy, making it suitable for a variety of mathematical calculations and financial calculations.

Users can efficiently evaluate complex arithmetic expressions, visualize function graphs, and make informed financial decisions using the loan calculator mode.

With a user-friendly interface and accurate results, the program satisfies a wide range of mathematical and financial needs.

The program is implemented using the MVC pattern, which involves dividing the program into three parts: View, Controller, and Model.

#### View
Includes the visual part of the application developed in the QT Creator application. It consists of four windows - the main window (mainwindow), which contains buttons and a space for entering expressions; the graph window, which includes a widget for drawing graphs from the third-party library QCustomPlot and fields for changing the drawing parameters.

#### Controller
Includes the CalculatorController class, which is located in the namespace s21 and has methods for interacting with both the model and the view.

#### Model
Includes the model part of the program with classes: CalculatorModel, Token, CreditCalculator, and DepositCalculator, all located in the namespace s21.

##### CalculatorModel
The main class of the model part that contains the logic of the computational process and graph plotting.

##### Token
An auxiliary class in CalculatorModel that describes the token type, including number, binary operator, unary operator (prefix/postfix), unary function, opening parenthesis, closing parenthesis, priority, and associativity.

##### CreditCalculator
A class in the credit model that receives parameters for calculations in the constructor and has methods to return results.

##### DepositCalculator
A class in the deposit model that receives parameters for calculations in the constructor and has methods to return results.

### Evaluation of an arithmetic expression:

Users can enter arbitrary arithmetic expressions in square brackets in infix notation using common arithmetic operators such as addition, subtraction, multiplication, division, power, and modulus.

The calculator accurately calculates expressions up to 7 decimal places and can handle expressions up to 255 characters.

It supports math functions such as cosine, sine, tangent, arccosine, arcsine, arctangent, square root, natural logarithm, and decimal logarithm.

### Plotting:

Users can plot functions given in infix notation with the variable "x".

The program provides a convenient coordinate system with applied scales and an adaptive grid.

The function domain and code domain are limited to -1,000,000 to 1,000,000, but the user can specify the display domain and code domain for plotting.

To create a graph image, the user must enter an equation, click the "GRAPH" button and press the "draw" button, or there is also the option to enter in the graph window and output by pressing enter.

### Credit calculator:

The program includes a special mode, known as the "Loan Calculator".

Users can enter data such as total loan amount, term (duration), interest rate, and type of loan (annuity or differentiated).

Based on the data entered, the calculator provides information such as monthly payment, loan overpayment, and total payment amount.

### Deposit calculator:

The program includes a special mode known as "Deposit Calculator".

Users can enter data such as the total amount of the deposit, term (duration), interest rate, tax rate, payment frequency, capitalization, and there are also deposit and withdrawal options.

Based on the data entered, the calculator provides such information, the amount of accruals, the amount of the deposit with interest and the amount of taxes withheld.

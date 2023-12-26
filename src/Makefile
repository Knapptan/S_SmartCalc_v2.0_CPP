G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
APP_ARCHIVE = Archive_SmartCalc_v2.0
CALCULATOR_TESTS_SRCS = Tests/calc_test.cpp
CALCULATOR_HEADERS = Model/CalculatorModel.cpp
CALCULATOR_SRC = Model/CalculatorModel.cpp \
				Model/Token.cpp \
				Model/CreditCalculator.cpp \
				Model/DepositCalculator.cpp
				
OS := $(shell uname)
ifeq ($(OS),Linux)
TEST_FLAGS = -lgtest -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
TEST_FLAGS = -lgtest -lm -lpthread -fprofile-arcs -ftest-coverage
endif
NAME_TESTS = test.cc
NAME_EXE = test


all: clean test install

.PHONY: test

install: uninstall
	mkdir build
	@cd build && qmake -r ../View/View.pro && make
	@rm build/*.cpp
	@rm build/*.o
	@rm build/*.h
	@rm build/*Makefile

uninstall:
	@rm -rf build

dist:
	@rm -rf $(APP_ARCHIVE)/
	@mkdir $(APP_ARCHIVE)
	@mkdir $(APP_ARCHIVE)/src/
	@cp -r build/SmartCalc_v2.0.app $(APP_ARCHIVE)/src/SmartCalc_v2.0.app
	@tar -cvzf $(APP_ARCHIVE).tgz $(APP_ARCHIVE)/
	@rm -rf $(APP_ARCHIVE)

dvi:
	@open documentation.md

tests: $(CALCULATOR_TESTS_SRCS) $(CALCULATOR_HEADERS) $(CALCULATOR_SRC) clean
	@$(G++) -g -c $(CALCULATOR_TESTS_SRCS) $(CALCULATOR_SRC)
	@$(G++) -g *.o $(TEST_FLAGS) -o ./unit_tests
	@./unit_tests

clean:
	@rm -rf *.o *.a a.out *.css *.html gcov_test *.gcda *.gcno info gcovreport.info report test.dSYM 
	@rm -rf build
	@rm -rf unit_tests
	@rm -rf $(APP_ARCHIVE).tgz

format: 
	@clang-format -style=google -i */*.cpp
	@clang-format -style=google -i */*.h

clang-format: 
	@clang-format -style=google -n */*.cpp
	@clang-format -style=google -n */*.h

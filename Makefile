PROJECT_NAME=3DViewer
CPP=g++
GCOV=--coverage
CFLAGS=-Wall -Werror -Wextra
STANDART=-std=c++17
ADD_LIB=-lm
GTEST=-lgtest

OS=$(shell uname -s)

ifeq ($(OS), Linux)
	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes
	OPEN_CMD=xdg-open
else ifeq ($(OS), Darwin)
	LEAK_CHECK=leaks -atExit --
	OPEN_CMD=open
endif

all: clean install

install: clean
	rm -rf temp
	mkdir temp
	mkdir build
	cd temp && qmake ..
	cd temp && make
	mv temp/* build
	rm -rf temp

unistall:
	rm -rf build

dvi:
	firefox dvi/description.html

dist: install
	tar -cvzf $(PROJECT_NAME).tgz build
	rm -rf build

test: clean
	$(CPP) $(STANDART) model/*.cpp tests/*.cpp -o test $(ADD_LIB) $(GTEST)
	./test

gcov_report: clean
	$(CPP) $(STANDART) model/*.cpp tests/*.cpp -o test $(ADD_LIB) $(GTEST) $(GCOV)
	./test
	lcov -c -d . --no-external --ignore-errors mismatch --debug -o test.info
	genhtml -o report test.info
	chmod 777 report/*
	rm *.gcda *.gcno
	$(OPEN_CMD) ./report/index.html

leaks: clean 
	$(CPP) $(STANDART) model/*.cpp tests/*.cpp -o test $(ADD_LIB) $(GTEST)
	$(LEAK_CHECK) ./test

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i \
	model/*.cpp \
	controller/*.cpp \
	front/*.cpp \
	tests/*.cpp
	rm -rf .clang-format

clean:
	@rm -rf \
	build \
	report \
	$(PROJECT_NAME).tgz \
	*.txt *.o *.a *.info
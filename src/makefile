GCC = gcc
FLAGS = -Wextra -Werror -Wall
CFLAG = -c
OFLAG = -o
OBJ = s21_math.a
MAINFILE = s21_math.o
UNAME_S 		:= $(shell uname -s)
CHECKFLAGS = -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include
OPEN_CMD = open
ADD_LIB =

ifeq ($(UNAME_S),Linux)
	CHECKFLAGS = -lcheck
	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lm -lpthread -lrt -lsubunit
	OS = LINUX
endif

all:
	make s21_math.a
	make test
	make gcov_report
s21_math.a:
	make s21_abs.o
	make s21_acos.o
	make s21_asin.o
	make s21_atan.o
	make s21_ceil.o
	make s21_cos.o 
	make s21_divide.o
	make s21_exp.o
	make s21_fabs.o
	make s21_floor.o
	make s21_fmod.o
	make s21_isnan.o
	make s21_log.o 
	make s21_pow.o
	make s21_sin.o
	make s21_sqrt.o
	make s21_tan.o

main.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) main.o main.c
	ar rcs s21_math.a main.o
s21_abs.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_abs.o s21_abs.c
	ar rcs s21_math.a s21_abs.o
s21_acos.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_acos.o s21_acos.c
	ar rcs s21_math.a s21_acos.o
s21_asin.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_asin.o s21_asin.c
	ar rcs s21_math.a s21_asin.o
s21_atan.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_atan.o s21_atan.c
	ar rcs s21_math.a s21_atan.o
s21_ceil.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_ceil.o s21_ceil.c
	ar rcs s21_math.a s21_ceil.o
s21_cos.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_cos.o s21_cos.c
	ar rcs s21_math.a s21_cos.o
s21_divide.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_divide.o s21_divide.c
	ar rcs s21_math.a s21_divide.o
s21_exp.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_exp.o s21_exp.c
	ar rcs s21_math.a s21_exp.o
s21_fabs.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_fabs.o s21_fabs.c
	ar rcs s21_math.a s21_fabs.o
s21_floor.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_floor.o s21_floor.c
	ar rcs s21_math.a s21_floor.o
s21_fmod.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_fmod.o s21_fmod.c
	ar rcs s21_math.a s21_fmod.o
s21_isnan.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_isnan.o s21_isnan.c
	ar rcs s21_math.a s21_isnan.o
s21_log.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_log.o s21_log.c
	ar rcs s21_math.a s21_log.o
s21_pow.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_pow.o s21_pow.c
	ar rcs s21_math.a s21_pow.o
s21_sin.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_sin.o s21_sin.c
	ar rcs s21_math.a s21_sin.o
s21_sqrt.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_sqrt.o s21_sqrt.c
	ar rcs s21_math.a s21_sqrt.o
s21_tan.o:
	$(GCC) $(FLAGS) $(CHECKFLAGS) $(CFLAG) $(OFLAG) s21_tan.o s21_tan.c
	ar rcs s21_math.a s21_tan.o


test:
	$(GCC) $(FLAGS) $(CHECKFLAGS) -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck ./tests/s21_tests.c -L. $(OBJ) $(OFLAG) $(MAINFILE) $(ADD_LIB)
	./$(MAINFILE)
gcov_report:
	$(GCC) $(FLAGS) $(CHECKFLAGS) -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck --coverage *.c ./tests/s21_tests.c -L. $(OBJ) $(OFLAG) rep.o $(ADD_LIB)
	./rep.o
	lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	$(OPEN_CMD) report/index.html

clean:
	rm -rf ./*.o ./*.a ./a.out gcov_test *.html /*.cpp /*.css ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./string_o ./*.dSYM ./test_s21_string


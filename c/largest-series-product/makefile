CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -f *.o *.out

tests.out: test/test_largest_series_product.c src/largest_series_product.c src/largest_series_product.h
	@echo Compiling $@
	@cc $(CFLAGS) src/largest_series_product.c test/vendor/unity.c test/test_largest_series_product.c -o tests.out

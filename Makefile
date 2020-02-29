CC=gcc
# No flags should be required except for debugging and forcing C89 standard
CFLAGS= -Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes -Wstrict-prototypes \
		-Wold-style-definition -O2
SOURCES=tests/basic_tests.c

all: tests

tests: $(SOURCES)
	$(CC) -o microfloat $(SOURCES) $(CFLAGS)
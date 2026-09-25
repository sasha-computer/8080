SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)

main: $(SOURCES) $(HEADERS)
	clang -g -Wall -Wextra $(SOURCES) -o main

.PHONY: run
run: main
	./main

CC = g++
CCFLAGS = -v -Werror -Wall -Wextra -std=c++11

SRC_DIR = src
LIBS_DIR = $(SRC_DIR)/libs

output: target/lists.o target/main.o
	$(CC) $(CCFLAGS) target/main.o target/lists.o -o target/tests.exe

target/lists.o: $(LIBS_DIR)/lists.cpp
	$(CC) -c $(CCFLAGS) $(LIBS_DIR)/lists.cpp -o target/lists.o

target/main.o: src/main.cpp
	$(CC) -c $(CCFLAGS) $(SRC_DIR)/main.cpp -o target/main.o

clean:
	del /s /q target
# Makefile

# Compiler

CXX = g++

# Compiler flags

CXXFLAGS =

# Executable name

TARGET = game

# Source files

SRCS = main.cpp Inventory.cpp Item.cpp load_save.cpp

# Build and run tests

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	./$(TARGET)

# Clean rule

.PHONY: clean

clean:
	rm -f $(TARGET)
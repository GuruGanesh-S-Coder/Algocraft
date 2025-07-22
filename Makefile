CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = algocraft

all: $(TARGET)

$(TARGET): $(OBJ) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJ) main.o $(TARGET)

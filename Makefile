CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

OBJ = main.o RSA.o
BIN = M02

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN)

main.o: main.cpp RSA.h
	$(CXX) $(CXXFLAGS) -c main.cpp

RSA.o: RSA.cpp RSA.h
	$(CXX) $(CXXFLAGS) -c RSA.cpp

clean:
	rm -f $(OBJ) $(BIN)

CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = 
SRC = src/main.cpp src/quiz.cpp src/json_parser.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = quiz

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

CXX = clang++
CXXFLAGS = -O2 -std=c++17 -Wall

SRC = src/main.cpp src/branching_model.cpp src/probability_util.cpp src/histogram.cpp
OBJ = $(SRC:.cpp=.o)

all: statsDecay

statsDecay: $(OBJ)
	$(CXX) $(CXXFLAGS) -o statsDecay $(OBJ)

clean:
	rm -f $(OBJ) statsDecay

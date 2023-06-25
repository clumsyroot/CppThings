CXX ?= g++
CXXFLAGS = -c -Wall

TARGET = tcpcli
SRC = $(wildcard ./socket/*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(TARGET) $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) -o $(OBJ) $(CXXFLAGS) $<

clean:
	rm -f *.o $(TARGET)


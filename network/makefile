CXX ?= g++
CXXFLAGS = -c -Wall

TARGET = tcpcli01
SRC = $(wildcard ./socket/*.cpp tcpcli01.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

clean:
	rm -f *.o $(TARGET)


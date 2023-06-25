CXX ?= g++
CXXFLAGS = -c -Wall

TARGET = tcpserv01
SRC = $(wildcard ./socket/*.cpp tcpserv01.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

clean:
	rm -f *.o $(TARGET)


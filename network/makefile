CXX ?= g++
CXXFLAGS = -c -Wall

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
endif

TARGET = tcpserv01.exec
SRC = $(wildcard ./socket/*.cpp tcpserv01.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

clean:
	rm -f *.o $(TARGET)

CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = studentai
SOURCES = main.cpp funkcijos.cpp zmogus.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -O2 -o $(TARGET) $(OBJECTS)

O1: CXXFLAGS += -O1
O1: clean $(TARGET)

O2: CXXFLAGS += -O2
O2: clean $(TARGET)

O3: CXXFLAGS += -O3
O3: clean $(TARGET)

%.o: %.cpp studentas.h zmogus.h
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean O1 O2 O3
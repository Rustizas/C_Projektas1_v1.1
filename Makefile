CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = studentai
SOURCES = main.cpp funkcijos.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: O2

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

O1: CXXFLAGS += -O1
O1: clean $(TARGET)
	@echo "Compiled with -O1 optimization"

O2: CXXFLAGS += -O2
O2: clean $(TARGET)
	@echo "Compiled with -O2 optimization"

O3: CXXFLAGS += -O3
O3: clean $(TARGET)
	@echo "Compiled with -O3 optimization"

%.o: %.cpp studentas.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET).exe

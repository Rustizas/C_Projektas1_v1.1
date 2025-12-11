CXX = g++
CXXFLAGS = -std=c++17 -Wall
GTEST_DIR = tests/googletest
GTEST_HEADERS = $(GTEST_DIR)/googletest/include
GTEST_SRCS = $(GTEST_DIR)/googletest/src/gtest-all.cc
GTEST_MAIN = $(GTEST_DIR)/googletest/src/gtest_main.cc
TARGET = studentai
SOURCES = main.cpp funkcijos.cpp zmogus.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -O2 -o $(TARGET) $(OBJECTS)

test: test_zmogus test_studentas
	./test_zmogus
	./test_studentas

test_zmogus: tests/test_zmogus.cpp zmogus.cpp funkcijos.cpp
	$(CXX) $(CXXFLAGS) -isystem $(GTEST_HEADERS) -I$(GTEST_DIR)/googletest \
		-pthread tests/test_zmogus.cpp zmogus.cpp funkcijos.cpp \
		$(GTEST_SRCS) $(GTEST_MAIN) -o test_zmogus

test_studentas: tests/test_studentas.cpp zmogus.cpp funkcijos.cpp
	$(CXX) $(CXXFLAGS) -isystem $(GTEST_HEADERS) -I$(GTEST_DIR)/googletest \
		-pthread tests/test_studentas.cpp zmogus.cpp funkcijos.cpp \
		$(GTEST_SRCS) $(GTEST_MAIN) -o test_studentas

docs:
	doxygen Doxyfile

O1: CXXFLAGS += -O1
O1: clean $(TARGET)

O2: CXXFLAGS += -O2
O2: clean $(TARGET)

O3: CXXFLAGS += -O3
O3: clean $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) test_zmogus test_studentas

.PHONY: all clean test docs O1 O2 O3
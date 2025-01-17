CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS =

SRCS = main.cpp symbole.cpp lexer.cpp etat.cpp automate.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = symbole.h lexer.h etat.h automate.h
TARGET = analyzer

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

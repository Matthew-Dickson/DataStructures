# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra
LXXFLAGS = -std=c++11 -Wall -Wextra
# Source files
SRCS = ArrayList.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main

# Default rule
all: $(EXEC)

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Linking
$(EXEC): $(OBJS)
	$(CXX) $(LXXFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) $(EXEC)
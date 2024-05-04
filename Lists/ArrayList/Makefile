# $^ is an automatic variable that represents all of the prerequisites (dependencies) of a rule
# $@ is an automatic variable that represents the target of the rule
# $< is an automatic variable that represents the first prerequisite (dependency) of a rule
# | symbol is used to denote order-only prerequisites

# Compiler
CXX = g++

# Directory paths
BUILD_DIR := build
SRC_DIR := .

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra
LXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = ArrayList.cpp main.cpp
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.o))

# Executable name
EXEC = $(BUILD_DIR)/main

# Default rule
all: $(EXEC)

# Compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Linking
$(EXEC): $(OBJS) #$^ refers to all the object files listed in $(OBJS) and $@ refers to the target $(EXEC)
	$(CXX) $(LXXFLAGS) $^ -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $@

#Clean target
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: clean #.PHONY is a special target that tells make that the target is not actually the name of a file. Instead, it's just a label for a rule.
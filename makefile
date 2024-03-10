CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -include src/pch.hpp

# Directories
SRCDIR := src
BINDIR := bin
UTILSDIR := $(SRCDIR)/Utils
UTILSBIN := $(BINDIR)/Utils

# Source files
SOURCES := $(wildcard $(SRCDIR)/*.cpp) $(SRCDIR)/BinaryInspector.cpp $(SRCDIR)/FileContentScanner.cpp
UTILS_SOURCES := $(wildcard $(UTILSDIR)/*.cpp)

# Object files
SRC_OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)
UTILS_OBJECTS := $(UTILS_SOURCES:$(UTILSDIR)/%.cpp=$(UTILSBIN)/%.o)
ALL_OBJECTS := $(SRC_OBJECTS) $(UTILS_OBJECTS)

# Executable
EXECUTABLE := $(BINDIR)/find_sig

.PHONY: all clean

all: $(EXECUTABLE) print_message

$(EXECUTABLE): $(ALL_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Create the $(BINDIR) and $(UTILSBIN) directories before building object files
$(BINDIR) $(UTILSBIN):
	@mkdir -p $@

$(BINDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/pch.hpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(UTILSBIN)/%.o: $(UTILSDIR)/%.cpp $(SRCDIR)/pch.hpp | $(UTILSBIN)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINDIR)

print_message:
	@echo "Compilation completed. find_sig is here: " $(EXECUTABLE) 
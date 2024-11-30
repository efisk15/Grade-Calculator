CXX = g++
CXXFLAGS = -g -Wall -std=c++11
SHELL = bash

# Default target (compiles the program)
all: main

# Compile the main program
main: main.o college.o
	$(CXX) $(CXXFLAGS) main.o college.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

College.o: college.cpp college.h
	$(CXX) $(CXXFLAGS) -c college.cpp

# Run grade scripts
test: main
	@echo "Running grade scripts..."
	@./gradescript1 && ./gradescript2
	@for script in gradescript*; do \
		echo "Executing $$script"; \
		bash $$script || break; \
	done

# Clean up build artifacts
clean:
	rm -f *.o main

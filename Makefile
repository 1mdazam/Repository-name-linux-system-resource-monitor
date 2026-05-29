CXX=g++
CXXFLAGS=-std=c++17

SRC=src/main.cpp \
    src/cpu_sampler.cpp \
    src/mem_parser.cpp \
    src/proc_table.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o monitor

run:
	./monitor
CXX = g++
CXXFLAGS = -Wall
APPLICATION = grade-school-multiplication-vector

SRC_DIR = src
BIN_DIR = bin

$(APPLICATION):
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$@ $(SRC_DIR)/*

clean: 
	rm -rf $(BIN_DIR)/*

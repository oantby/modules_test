CXXFLAGS = -std=c++14

.PHONY : all
all : dll.so consumer

%.so : %.cpp
	$(CXX) -dynamiclib $^ -o $@
CXXFLAGS = -std=c++14
ifdef DEBUG
	CXXFLAGS += -DDEBUG
endif

.PHONY : all
all : 1.so 2.so 3.so 4.so 5.so consumer

%.so : %.cpp
	$(CXX) $(CXXFLAGS) -dynamiclib $^ -o $@
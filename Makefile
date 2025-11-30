HOMEBREW_PREFIX := $(shell brew --prefix)
LLVM_PREFIX := $(shell brew --prefix llvm)

CXX := $(LLVM_PREFIX)/bin/clang++
CXXFLAGS = -std=c++17 -stdlib=libc++ -Wall -Wextra \
           -I$(LLVM_PREFIX)/include/c++/v1 \
           --sysroot=$(shell xcrun --show-sdk-path)
LDFLAGS = -L$(LLVM_PREFIX)/lib -lc++

SRCDIR = src
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
EXEC = branching_sim 
BINDIR = .

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
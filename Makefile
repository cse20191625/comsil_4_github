.SURFFIXES : .cpp .o
CC = g++

CPPFLAGS = -g

HEDRS = LinkedList.h Stack.h
SRCS = main.cpp
objects = $(SRCS:.cpp=.o)

target = cpp2

all : $(target)

$(target) : $(objects) $(HDRS)
	$(CC) -o $@ $(objects)

clean :
	rm -rf $(objects) $(target)	

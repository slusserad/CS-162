  
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CSSFLAGS += -pendantic-errors
CXXFLAGS += -g

OBJS = main.o Animal.o BankAccount.o Bear.o Penguin.o StringValidation.o Tiger.o Turtle.o Zoo.o

SRCS = main.cpp Animal.cpp BankAccount.cpp Bear.cpp Penguin.cpp StringValidation.cpp Tiger.cpp Turtle.cpp Zoo.cpp

HEADERS = Animal.hpp BankAccount.hpp Bear.hpp Penguin.hpp StringValidation.hpp Tiger.hpp Turtle.hpp Zoo.hpp

zootycoon: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o output

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output
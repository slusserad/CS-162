CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CSSFLAGS += -pendantic-errors
CXXFLAGS += -g

OBJS = main.o Menu.o Barbarian.o Bluemen.o Character.o HarryPotter.o Medusa.o utilities.o Vampire.o

SRCS = main.cpp Menu.cpp Barbarian.cpp Bluemen.cpp Character.cpp HarryPotter.cpp Medusa.cpp utilities.cpp Vampire.cpp

HEADERS = Menu.hpp Barbarian.hpp Bluemen.hpp Character.hpp HarryPotter.hpp Medusa.hpp utilities.hpp Vampire.hpp

zootycoon: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o output

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output
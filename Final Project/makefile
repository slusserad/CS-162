  
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CSSFLAGS += -pendantic-errors
CXXFLAGS += -g

OBJS = main.o Bridge.o CargoBay.o CommonArea.o EngineBay.o Game.o LivingArea.o Outside.o Space.o validation.o

SRCS = main.cpp Bridge.cpp CargoBay.cpp CommonArea.cpp EngineBay.cpp Game.cpp LivingArea.cpp Outside.cpp Space.cpp validation.cpp

HEADERS = Bridge.hpp CargoBay.hpp CommonArea.hpp EngineBay.hpp Game.hpp LivingArea.hpp Outside.hpp Space.hpp validation.hpp

zootycoon: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o output

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output
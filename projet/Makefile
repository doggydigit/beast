SRC = $(wildcard src/*/*.cc)
OBJ = $(SRC:.cc=.o)
CC = g++-4.7

LDFLAGS = $(shell wx-config --libs)
CFLAGS = -Wall -Wextra -Wwrite-strings -Winit-self -Wcast-align \
	-Wpointer-arith -Wformat=2 -Wlogical-op \
	-Wno-unused-variable -Wno-unused-parameter -Wno-unused \
	$(shell wx-config --cxxflags)
#CFLAGS += -Wcast-qual

#Linkage

all: test

test: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

-include $(OBJ:.o=.d)

#Compiling

%.o: %.cc
	$(CC) -c $(CFLAGS) $*.cc -o $*.o
	$(CC) -MM $(CFLAGS) $*.cc > $*.d


clean:
	-rm -f $(OBJ) test

SOURCES=$(wildcard *.c)
HEADERS=$(wildcard *.h)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))
LIBS=tool.so runtime.so
TARGET=mytest
CC=gcc
SOFLAGS=-shared -undefined dynamic_lookup
CFLAGS=-O3

.SECONDARY: $(OBJS)
.PHONY: all

all: $(TARGET)

%.so : %.o
	$(CC) $(SOFLAGS) -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): main.o $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) $(LIBS) $(TARGET)

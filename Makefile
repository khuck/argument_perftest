SOURCES=$(wildcard *.c)
HEADERS=$(wildcard *.h)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))
LIBS=tool.so runtime.so
TARGET=mytest
CC?=gcc

USETOOL=-DUSE_TOOL
#USETOOL=
# Flags for linking on OSX
SOFLAGS=-shared -undefined dynamic_lookup
# Flags for linking on POWER9 with GCC
SOFLAGS=-shared -fPIC
CFLAGS=-O3 -fPIC $(USETOOL)
LDFLAGS=-Wl,--rpath,$(PWD)

.SECONDARY: $(OBJS)
.PHONY: all

all: $(TARGET)

%.so : %.o
	$(CC) $(SOFLAGS) -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): main.o $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^ -lm $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(LIBS) $(TARGET)

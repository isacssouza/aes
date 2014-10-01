CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=aes.c transformations.c util.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=aes

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
		$(CC) $(CFLAGS) $< -o $@

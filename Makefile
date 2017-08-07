APP = main
SOURCES = 
CFLAGS += -DDEBUG

all: main.o my_buffer.o
	$(CC) $(CFLAGS) $^ -o $(APP)

run: all
	./main

clean:
	rm -f $(APP) *.o



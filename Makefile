CC = g++
CFLAGS = -Wall
TARGET = my_program

all: $(TARGET)

$(TARGET): main.o
	$(CC) -o $(TARGET) main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)


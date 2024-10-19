TARGET = hanoi
CC = cc
CFLAGS = -g
OBJ = main.o func.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c hanoi.h
	$(CC) $(CFLAGS) -c -o $@ $<

func.o: func.c func.h hanoi.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o $(TARGET)

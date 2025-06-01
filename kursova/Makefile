all: kurs

kurs: main.o input.o calc.o
	$(CC) -o kurs main.o input.o calc.o -lm

main.o: main.c input.h calc.h
input.o: input.c input.h
calc.o: calc.c calc.h input.h

clean:
	rm -f *.o kurs output.csv
CC=gcc
CFLAGS=-Wall -pedantic -std=c99 -O2
LIBS= '-lm'


kombajn: main.o danexy.o danex.o statystyka.o
	$(CC) -o kombajn main.o danexy.o danex.o statystyka.o $(CFLAGS) $(LIBS)
	
main.o: main.c danexy.h danex.h statystyka.h
	$(CC) -o main.o -c main.c $(CFLAGS)

danexy.o: danexy.c danexy.h danex.h statystyka.h
	$(CC) -o danexy.o -c danexy.c $(CFLAGS)

danex.o: danex.C danex.h danexy.h statystyka.h
	$(CC) -o danex.o -c danex.C $(CFLAGS)
	
	statystyka.o: statystyka.c statystyka.h danex.h danexy.h
	$(CC) -o statystyka.o -c statystyka.c $(CFLAGS)

clean:
	rm *.o

OBJS = LL.o Stack.o Deque.o
CC = g++-4.9
DEBUG = -g
C11 = -std=c++11
LFLAGS = -Wall $(DEBUG) $(C11)
CFLAGS = $(LFLAGS) -c


Lab2: $(OBJS) main.cpp
	$(CC) $(LFLAGS) main.cpp $(OBJS) -o Lab2

LL.o: LL.h
	$(CC) $(CFLAGS) LL.cpp

Stack.o: Stack.h LL.h
	$(CC) $(CFLAGS) Stack.cpp

Deque.o: Deque.h LL.h
	$(CC) $(CFLAGS) Deque.cpp

clean:
	rm -r *.o Lab2 *.dSYM

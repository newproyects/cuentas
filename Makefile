a: main.o
	g++ main.o mycon.o -o a -L/usr/local/lib -lmysqlclient
	rm *.o

main.o: main.cpp mycon.cpp mycon.h
	g++ -c main.cpp -I/usr/include/mysql
	g++ -c  mycon.cpp -I/usr/include/mysql

a: main.o
	g++ main.o -L/usr/local/lib -lmysqlclient
	rm *.o

main.o: main.cpp
	g++ -c main.cpp -I/usr/include/mysql

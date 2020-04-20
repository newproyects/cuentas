a: main.o
	g++ main.o -o a -L/usr/local/lib -lmysqlclient
	rm *.o

main.o: main.cpp
	g++ -c main.cpp -I/usr/include/mysql

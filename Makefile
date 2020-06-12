a: main.o
	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient
	rm *.o

main.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h
	g++ -c main.cpp -I/usr/include/mysql
	g++ -c  mycon.cpp -I/usr/include/mysql
	g++ -c  strutil.cpp -I/usr/include/mysql

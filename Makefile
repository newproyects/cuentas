a: main.o user.o mycon.o strutil.o
	g++ main.o user.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient
	rm *.o

main.o: main.cpp user.cpp user.h mycon.cpp mycon.h strutil.cpp strutil.h
	g++ -c main.cpp -I/usr/include/mysql
	g++ -c user.cpp -I/usr/include/mysql
	g++ -c mycon.cpp -I/usr/include/mysql
	g++ -c strutil.cpp -I/usr/include/mysql

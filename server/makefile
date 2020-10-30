objects = main.o threadfuncs.o server.o otherfuncs.o

server: $(objects)
	g++ $(objects) -lpthread -o server

main.o: main.cpp
	g++ -c main.cpp -o main.o

threadfuncs.o: ThreadFuncs.cpp
	g++ -c ThreadFuncs.cpp -o threadfuncs.o

server.o: Server.cpp
	g++ -c Server.cpp -o server.o

otherfuncs.o: OtherFuncs.cpp
	g++ -c OtherFuncs.cpp -o otherfuncs.o

clean:
	rm server *.o
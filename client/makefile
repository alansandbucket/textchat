objects = main.o otherfuncs.o sighandlers.o connection.o

client: $(objects)
	g++ $(objects) -o client

main.o: main.cpp
	g++ main.cpp -c -o main.o

otherfuncs.o: OtherFuncs.cpp
	g++ OtherFuncs.cpp -c -o otherfuncs.o

sighandlers.o: SigHandlers.cpp
	g++ SigHandlers.cpp -c -o sighandlers.o

connection.o: Connection.cpp
	g++ Connection.cpp -c -o connection.o

clean:
	rm client *.o
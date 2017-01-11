all: serveurtcpcpp clienttcpcpp



serveurtcpcpp: serveurtcpcpp.o

	g++ -o serveurtcpcpp -lnsl serveurtcpcpp.o

serveurtcpcpp.o: serveurtcpcpp.cpp

	g++ -c serveurtcpcpp.cpp



clienttcpcpp: clienttcpcpp.o

	g++ -o clienttcpcpp -lnsl clienttcpcpp.o

clienttcpcpp.o: clienttcpcpp.cpp

	g++ -c clienttcpcpp.cpp



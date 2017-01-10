all: serveurtcp clienttcp



serveurtcp: serveurtcp.o

	gcc -o serveurtcp -lnsl serveurtcp.o

serveurtcp.o: serveurtcp.c

	gcc -c serveurtcp.c



clienttcp: clienttcp.o

	gcc -o clienttcp -lnsl clienttcp.o

clienttcp.o: clienttcp.c

	gcc -c clienttcp.c



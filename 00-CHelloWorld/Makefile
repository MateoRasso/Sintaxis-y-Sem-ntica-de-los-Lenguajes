run: hello
	hello.exe

hello: hello.o
	gcc hello.o -o hello

hello.o: hello.c
	gcc -c hello.c -o hello.o

clean:
	del hello.o
	del hello.exe

#hello: hello.c              De esta forma no nos queda un archivo objeto
#	gcc hello.c -o hello       

# -c solo compila a un archivo objeto, es decir la salida del programa ensamblador.
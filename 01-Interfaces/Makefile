run: TablasDeConversion
	TablasDeConversion.exe

TablasDeConversion: TablasDeConversion.o Conversion.o
	gcc TablasDeConversion.o Conversion.o -o TablasDeConversion

Conversion.o: Conversion.c
	gcc -c Conversion.c -o Conversion.o

TablasDeConversion.o: TablasDeConversion.c
	gcc -c TablasDeConversion.c -o TablasDeConversion.o

clean:
	del TablasDeConversion.o
	del Conversion.o
	del TablasDeConversion.exe
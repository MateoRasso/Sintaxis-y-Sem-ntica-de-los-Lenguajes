start: TablasDeConversion
	TablasDeConversion.exe

test: ConversionTest
	ConversionTest.exe

TablasDeConversion: TablasDeConversion.o Conversion.o
	gcc TablasDeConversion.o Conversion.o -o TablasDeConversion

Conversion.o: Conversion.c
	gcc -c Conversion.c -o Conversion.o

TablasDeConversion.o: TablasDeConversion.c
	gcc -c TablasDeConversion.c -o TablasDeConversion.o

ConversionTest.o: ConversionTest.c
	gcc -c ConversionTest.c -o ConversionTest.o

ConversionTest: ConversionTest.o Conversion.o
	gcc ConversionTest.o Conversion.o -o ConversionTest

clean:
	rm TablasDeConversion.o
	del Conversion.o
	del TablasDeConversion.exe
	del ConversionTest.o
	del ConversionTest.exe
# ------------------- Variables ---------------------------------

# Una variable puede ser cualquier secuencia de caracteres que no contenga ':', '#', '=' o espacios.

# Para reemplazar a una variable por su valor se usa la notacion: ' $(VARIABLE) '. 

HEADER_FILE = Conversion.h

OBJ = TablasDeConversion.o Conversion.o

OBJ_TEST = ConversionTest.o Conversion.o

BIN = TablasDeConversion.exe

BIN_TEST = ConversionTest.exe

RM = cmd //C del

CC = gcc

# Version 18 del lenguaje C 

CFLAGS = -std=c18 

# Usando la variable especial .DEFAULT_GOAL se puede definir que objetivo construir por defecto, si no se especifica que objetivo construir en la linea de comandos.

.DEFAULT_GOAL = start

# ---------- Reglas para TablasDeConversion -------------------

start: $(BIN)
	$(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

Conversion.o: Conversion.c $(HEADER_FILE)
	$(CC) -c Conversion.c -o Conversion.o $(CFLAGS) 

# $(CC) -c archivo.c -o archivo.o $(CFLAGS) | -c Indica compilar a un archivo objeto

TablasDeConversion.o: TablasDeConversion.c $(HEADER_FILE)
	$(CC) -c TablasDeConversion.c -o TablasDeConversion.o $(CFLAGS)

# ----------- Reglas para ConversionTest --------------------------

test: $(BIN_TEST)
	$(BIN_TEST)

$(BIN_TEST): $(OBJ_TEST)
	$(CC) $(OBJ_TEST) -o $(BIN_TEST) $(CFLAGS)

ConversionTest.o: ConversionTest.c $(HEADER_FILE)
	$(CC) -c ConversionTest.c -o ConversionTest.o $(CFLAGS)

# ----------------------------------------------------------------

clean:
	$(RM) $(OBJ) $(OBJ_TEST) $(BIN) $(BIN_TEST)
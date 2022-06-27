# TP 02 Fases de la Traducción y Errores

## Objetivos

Este trabajo tiene como objetivo identificar las fases del proceso de traducción o Build y los posibles errores asociados a cada fase. Para lograr esa identificación se ejecutan las fases de traducción una a una, se detectan y corrigen errores, y se registran las conclusiones en readme.md. No es un trabajo de desarrollo; es más, el programa que usamos como ejemplo es simple, similar a hello.c pero con errores que se deben corregir. La complejidad está en la identificación y comprensión de las etapas y sus productos.

## Compilador utilizado: GCC

## IDE: Microsoft Visual Studio Code

## Secuencia de pasos y resolución

1. Preprocesador

    a. Escribir hello2.c, que es una variante de hello.c

    b. Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su
    contenido. ¿Qué conclusiones saca?

    Comando: 
    
    * gcc -E hello2.c -o hello2.i

    El archivo fuente hello2.c solo es preprocesado, se elimina el comentario en el codigo y  se lo reemplaza por un espacio. La linea _#include <stdio.h>_ es reemplazada por el contenido del archivo encabezado stdio.h . Esto se realiza para poder acceder a las declaraciones de las funciones de la biblioteca estandar. 

    c. Escribir hello3.c, una nueva variante

    d. Investigar e indicar la semántica de la primera línea.

    La primera linea de hello3.c es la declaracion de la funcion _printf_. La funcion _printf_ puede recibir un argumento como mínimo o más de uno. La palabra reservada **int** indica que la funcion _printf_ devuelve un entero, que es la cantidad de caracteres impresos por la función, o tambíén puede devolver un entero negativo en caso de que se haya producido un error. _s_ es un puntero a una constante caracter, es una cadena que contiene caracteres comunes, que seran impresos al flujo de salida (en este caso stdout) y especificadores de conversión. La palabra reservada _restrict_  se usa para indicarle al compilador que no hay otro puntero que apunte al objeto apuntado por _s_.

    e. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias entre hello3.c y hello3.i.

    Comando: 
    
    * gcc -E hello3.c -o hello3.i

    Se mantiene el mismo contenido del archivo hello3.c, solo se agregan cuatro lineas y no el contenido de un archivo encabezado ya que no hay ninguna directiva _#include_  para el preprocesador en el archivo hello3.c

    ----------------------------------------------------------------------------------------------------------------------------

2. Compilación

    a. Compilar el resultado y generar hello3.s, no ensamblar.

    Comando: 
    
    * gcc -S hello3.c -o hello3.s

    Al compilar hello3.i sin ensamblar el compilador indica que hay un error sintáctico en el codigo, por la falta de una llave, y un warning por la llamada a _prontf_ que no está declarada. 

    b. Corregir solo los errores, no los warnings, en el nuevo archivo hello4.c y empezar de nuevo, generar hello4.s, no ensamblar.

    Comando: 
    
    * gcc -S hello4.c -o hello4.s

    Al corregir los errores en el archivo hello4.c el compilador realiza un análisis léxico sintáctico y semántico, al no encontrar errores genera como salida hello4.s . 

    c. Leer hello4.s, investigar sobre el lenguaje ensamblador, e indicar de forma sintética cual es el objetivo de ese código.

    El compilador da como salida al archivo hello4.s escrito en lenguaje ensamblador. Las instrucciones escritas en el archivo fuente hello4.c deben ser traducidas a un lenguaje que entienda la computadora, C es un lenguaje de alto nivel diseñado pára ser comprendido por los humanos, y tiene un nivel de abstracción más alto que el codigo escrito en lenjuaje assembler. Por esto muchas de las instrucciones escritas en C son traducidas a más de una instrucción en assembler, es decir la traduccion no es de uno a uno. Aún asi la computadora no entiende las instrucciones en lenguaje ensablador, por lo que es necesario traducir las mismas a código de máquina, que sí es comprendido por la computadora. La traducción del codigo assembler a código de máquina es casi una traducción de uno a uno. 

    d. Ensamblar hello4.s en hello4.o, no vincular.

    Comando: 
    
    * gcc -c hello4.s -o hello4.o 

    Al ensamblar hello4.s obtenemos como producto un archivo en código objeto.

    ----------------------------------------------------------------------------------------------------------------------------

3. Vinculación

    a. Vincular hello4.o con la biblioteca estándar y generar el ejecutable.

    Comando: 
    
    * gcc hello4.o 

    En la consola se muestra el siguiente error ya que _prontf_  produce un error de vinculación.

    c:/mingw/bin/../lib/gcc/mingw32/9.2.0/../../../../mingw32/bin/ld.exe: hello4.o:hello4.c:(.text+0x1e): undefined reference to `prontf'
    collect2.exe: error: ld returned 1 exit status

    b. Corregir en hello5.c y generar el ejecutable. Solo corregir lo necesario para que vincule.

    Comandos: 
    
    * gcc -c hello5.c -o hello5.o
    
    * gcc hello5.o

    Al corregir _prontf_ en hello5.c volvemos a generar el archivo objeto y luego a partir de este archivo y sin errores de vinculacion, generamos el ejecutable hello5.exe .

    c. Ejecutar y analizar el resultado

    Comando: 
    
    * .\hello5.exe

    Al ejecutar el programa se obtiene por pantalla **'La respuesta es 4200688'** . En el caso de hello5.c la cadena _s_ de _printf_ contiene caracteres ordinarios que son impresos a la salida estandar (**La respuesta es**) y el especificador de conversion _%d_ . Al imprimir por la salida estandar esta cadena, se produce un problema ya que el uso de _%d_ en _printf_ indica que se va a imprimir un entero, pero en _printf_ falta un argumento, es decir, falta agregar la variable _i_ como segundo argumento de _printf_ para que el numero **42** se muestre por pantalla correctamente.

    ----------------------------------------------------------------------------------------------------------------------------

4. Corrección del bug

    a. Corregir en hello6.c y empezar de nuevo; verificar que funciona como se espera.

    Comandos: 
    
    * gcc hello6.c -o hello6
    
    * .\hello6.exe

    Luego de realizar la corrección correspondiente en hello6.c, compilamos y ejecutamos el programa y obtenemos por pantalla la salida correcta **'La respuesta es 42'** .

    ----------------------------------------------------------------------------------------------------------------------------

5. Remoción del prototipo

    a. Escribir hello7.c, una nueva variante.

    b. Explicar porqué funciona.

    Comandos: 
    
    * gcc hello7.c -o hello7 

    hello7.c: In function 'main':
hello7.c:3:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    3 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~
hello7.c:3:2: warning: incompatible implicit declaration of built-in function 'printf'
hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | int main(void){
    
    * .\hello7.exe 

    Salida: **La respuesta es 42**

    Al ejecutar los comandos el programa es compilado y ejecutado con un warning pero sin errores. 
    
    Funciona ya que la función es declarada implicitamente, esto quiere decir que como _printf_ no esta declarada, el compilador (gcc) "asume" que el tipo de dato que retorna la funcion _printf_ es un **int**. El compilador no asume nada respecto a los parámetros y sus tipos de dato, de una funcion no declarada. En el caso de hello7.c la compilacion no falla porque _printf_ devuelve un **int**, pero en el caso de alguna función distinta que no devuelva un **int** la compilación fallaría, se produciría un error.


    Como ejemplo se incluye en la carpeta 03-FasesErrores el archivo devuelveFloat.c en el que se llama desde _main_ a una funcion que devuelve un valor de tipo de dato float. La funcion no esta declarada, solo esta definida abajo de _main_ . Cuando se ejecuta el comando **gcc devuelveFloat.c -o devuelveFloat** obtenemos el warning correspondiente a la declaración implícita y un error, este último no se obtiene para el caso de hello7.c .

    devuelveFloat.c:4:6: warning: implicit declaration of function 'devuelvefloat' [-Wimplicit-function-declaration]
    4 |  i = devuelvefloat();
      |      ^~~~~~~~~~~~~
devuelveFloat.c: At top level:
devuelveFloat.c:7:7: error: conflicting types for 'devuelvefloat'
    7 | float devuelvefloat(){
      |       ^~~~~~~~~~~~~
devuelveFloat.c:4:6: note: previous implicit declaration of 'devuelvefloat' was here
    4 |  i = devuelvefloat();
      |      ^~~~~~~~~~~~~

    
    ----------------------------------------------------------------------------------------------------------------------------

6. Compilación Separada: Contratos y Módulos
        
    a. Escribir studio1.c (sí, studio1, no stdio) y hello8.c.

    b. Investigar como en su entorno de desarrollo puede generar un programa
    ejecutable que se base en las dos unidades de traducción (i.e., archivos fuente, archivos con extensión .c). Luego generar ese ejecutable y probarlo.

    Se puede compilar a un archivo objeto a hello8.c y a studio.c de forma separada y luego enlazar los archivos objeto.
    La ventaja de realizar el proceso de compilacion de esta forma es que, en el caso de que el compilador encuntre un error o warning podemos identificar de manera más fácil cuál es el archivo que causa el problema. En proyectos de mayor complejidad, compilar los archivos fuente a archivos objeto por sepearado y luego enlazarlos podría ahorrar tiempo de compilación.    

    Desde Visual Studio Code, estando posicionado en la carpeta del proyecto (donde se encuentren los archivos ".c") podemos ejecutar los siguientes Comandos:

    Con este comando generamos el archivo objeto hello8SoloCompilado.o

    * gcc -c hello8.c -o hello8SoloCompilado.o

hello8.c: In function 'main':
hello8.c:3:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
    3 |  prontf("La respuesta es %d\n", i);
      |  ^~~~~~

    Con este comando generamos el archivo objeto stdioSoloCompilado.o, 

    * gcc -c studio1.c -o studioSoloCompilado.o 

    studio1.c: In function 'prontf':
studio1.c:2:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    2 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~
studio1.c:2:2: warning: incompatible implicit declaration of built-in function 'printf'
studio1.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | void prontf(const char* s, int i){

    Luego enlazamos ambos archivos objeto para generar el ejecutable

    * gcc hello8SoloCompilado.o studioSoloCompilado.o -o hello8

    y ejecutamos el programa

    * .\hello8.exe 

    Obtenemos por pantalla la salida: **La respuesta es 42**

    Tambien podemos generar el ejecutable a partir de los archivos fuente, sin compilar a archivos objeto por separado como fue realizado anteriormente. De esta forma se obtiene el mismo ejecutable que compilando a archivos objeto por sepearado y luego enlazandolos. 

    * gcc hello8.c studio1.c -o hello8

    Cada vez que generamos un nuevo archivo, sea un archivo objeto o un ejecutable, estos son creados dentro de la misma carpeta en la que se encuentran los archivos ".c"

    c. Responder ¿qué ocurre si eliminamos o agregamos argumentos a la
    invocación de prontf? Justifique.

    1. Agregar un argumento a la invocación de _prontf_

    Comandos:

    * gcc hello8.c studio1.c -o hello8

    hello8.c: In function 'main':
hello8.c:3:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
    3 |  prontf("La respuesta es %d\n", i, 1);
      |  ^~~~~~
studio1.c: In function 'prontf':
studio1.c:2:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    2 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~
studio1.c:2:2: warning: incompatible implicit declaration of built-in function 'printf'
studio1.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | void prontf(const char* s, int i){

    * .\hello8.exe

    Salida: **La respuesta es 42**

    Al agregar un argumento a la invocacion a prontf en hello8.c obtenemos el mismo warning para _prontf_ que en el punto _.b_ 
    Esto sucede ya que al no haber una declaracion para _prontf_ en hello8.c la funcion esta declarada implicitamente, el compilador (gcc) permite declaraciones implicitas y no asume nada respecto a cuáles son los parametros de la función prontf. El compilador genera el ejecutable y nos indica a traves de un _warning_ que no hay una declaración para _prontf_ . La salida que se obtiene por pantalla es la misma que en el punto .b

    2. Eliminar un argumento de la invocación de _prontf_

    Comandos:

    * gcc hello8.c studio1.c -o hello8  

    hello8.c: In function 'main':
hello8.c:3:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
    3 |  prontf("La respuesta es %d\n");
      |  ^~~~~~
studio1.c: In function 'prontf':
studio1.c:2:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    2 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~
studio1.c:2:2: warning: incompatible implicit declaration of built-in function 'printf'
studio1.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | void prontf(const char* s, int i){

    * .\hello.exe  

    Obtenemos por pantalla la salida: **La respuesta es 4200720**

    Al eliminar un argumento, la salida que obtenemos por pantalla es distinta a la del punto _.b_, pero el _warning_ que se obtiene para prontf es el mismo. Esto sucede ya que como se mencionó anteriormente, gcc permite declaraciones implícitas y no asume nada sobre los parametros de una función declarada implícitamente, ni sobre los tipos de dato de esos parámetros. Al no haber una declaración de la función, el compilador no verifica los tipos de dato ni la cantidad de parametros de la definición de la función o de la invocación. Si eliminamos el argumento _i_ , La salida que se obtiene por pantalla es distinta a la del punto .b ya que en la definición de _prontf_ se invoca a _printf_ con _i_ como argumento y como no le pasamos ese parametro a _prontf_, _printf_ imprime un valor basura.

    d. Revisitar el punto anterior, esta vez utilizando un contrato de interfaz en
    un archivo header.
    
        i. Escribir el contrato en studio.h.

        ii. Escribir hello9.c, un cliente que sí incluye el contrato.

        iv. Responder: ¿Qué ventaja da incluir el contrato en los clientes y en el
        proveedor

        La ventaja que da incluir el contrato en los clientes y en el proveedor es que permite que el compilador detecte errores de invocación Incorrecta por parte del consumidor y de definición Incorrecta por parte del proveedor. Usando la Información que da la declaración de una función, el compilador puede verificar la cantidad de parámetros, argumentos y los tipos de dato de cada uno en las Invocaciones y definiciones de una función. A continuación, podemos realizar la prueba.

        1. Eliminando el argumento _i_ en la invocación a _prontf_

        Comando:

        * gcc hello9.c studio2.c -o hello9

        hello9.c: In function 'main':
hello9.c:5:2: error: too few arguments to function 'prontf'
    5 |  prontf("La respuesta es %d\n");
      |  ^~~~~~
In file included from hello9.c:1:
studio.h:3:6: note: declared here
    3 | void prontf(const char*, int);
      |      ^~~~~~


        El compilador detecta menos argumentos de los especificados en el contrato, y por lo tanto se produce un error.

        2. Eliminamos el segundo parámetro en la definición de _prontf_ 

        Comando:

        * gcc hello9.c studio2.c -o hello9

        studio2.c:3:6: error: conflicting types for 'prontf'
    3 | void prontf(const char* s){
      |      ^~~~~~
In file included from studio2.c:1:
studio.h:3:6: note: previous declaration of 'prontf' was here
    3 | void prontf(const char*, int);
      |      ^~~~~~
studio2.c: In function 'prontf':
studio2.c:4:33: error: 'i' undeclared (first use in this function)
    4 |  printf("La respuesta es %d\n", i);
      |                                 ^
studio2.c:4:33: note: each undeclared identifier is reported only once for each function it appears in

        El compilador detecta la definición incorrecta por parte del proveedor. Además indica que _i_ no está declarada debido a que eliminamos el segundo parámetro de la definición de _prontf_.





    


    


        







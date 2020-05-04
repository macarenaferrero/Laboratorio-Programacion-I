/*
 ============================================================================
 Name        : probando.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
// EJERCICIO
// 1 programa que pida unnumero al usuario, despues que pida una operacion (+ - / * )
// y despues que pida otro numero. Segun la operacion ingresada, se llamará a una funcion
// que ejecute la operacion (sumar() restar() multiplicar() dividir())
// y luego mostrar al usuario el resultado. El mostrar resultado NOOOOO puede estar dentro de
// las funciones que crean para hacer la operacion. En la funcion dividir, validar no dividir por
// cero


#include <stdio.h>
#include <stdlib.h>


// prototipos de funciones
int sumar (int operador1,int operador2); // prototipo
int restar (int operador1,int operador2);
int multiplicar (int operador1,int operador2);
float dividir (int operador1,int operador2);


int main(void)
{
	setbuf(stdout,NULL);

    int num1;
    int num2;
    char operacion;
    int resultadoInt;
    float resultadoFloat;


    printf("ingrese un numero\n");

    scanf("%d",&num1);

    printf("ingrese una operacion: [s,r,m,d]\n");
    __fpurge(stdin); //Ahora en linuxxx
    scanf("%c",&operacion);

    printf("ingrese un numero\n");
    __fpurge(stdin);
    scanf("%d",&num2);


    switch(operacion)
	{
    case 's':
    {
    	resultadoInt = sumar(num1,num2);
    	break;
    }
    case 'r':
    {
    	resultadoInt = restar(num1,num2);
    	break;
    }
    case 'm':
    {
    	resultadoInt= multiplicar(num1,num2);
        	break;
    }
    case 'd':
    {
    	resultadoFloat=dividir(num1,num2);
    	break;
    }
	}

    if(operacion=='d')
    {
    printf("El resultado es %f ", resultadoFloat);
    }else
        printf("El resultado es %d ", resultadoInt);


    return EXIT_SUCCESS;
}

int sumar(int operador1,int operador2)
{
	int resultado;

	resultado = operador1 + operador2;

	return resultado;
}

int restar (int operador1,int operador2)
{
	int resultado;

	resultado=operador1 - operador2;

	return resultado;
}

int multiplicar (int operador1,int operador2)
{
	int resultado;

	resultado= operador1*operador2;

	return resultado;
}


float dividir (int operador1, int operador2)
{
	float resultado;
	if(operador2!=0)
	{
	resultado = (float)operador1 / operador2;
	}else{
		printf("Error. Estas dividiendo por cero.\n");
	}
	return resultado;
}


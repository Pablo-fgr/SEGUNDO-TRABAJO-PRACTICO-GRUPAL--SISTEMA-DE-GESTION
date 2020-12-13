/*En este ejemplo recibo por teclado una cadena para verificar el apartado e
El cual dice: NO DEBE TENER DOS CARACTERES CONSECUTIVO QUE REFIERAN A LETRA ALFABETICA
CONSECUTIVA (ASCENDENTE)*/

#include <stdio.h>
#include <ctype.h>   //biblioteca que tiene funciones para caracteres.
#include <conio.h>
#include <stdlib.h>

main(){
	char cad[10];		//esta vector de 10 elemento recibe lo que se ingrese por teclado.
	int i=0;
	printf("Ingrese la contraseña: ");
	
	cad[0]=getch();	//guardo el valor de la tecla presionada en la posicion 0 del vector.
							//uso getch() esta funcion recibe la tecla presionada pero no muestra 
							//el caracter ingresado por pantalla ni avanza un espacio.
	
	while(i<10 ){
		printf("*"); 	//en la misma posicion muestro el "*"
		i++;
		cad[i]=getch();
		if(cad[i]==13){
			cad[i]='\0'; 	//Cierro la cadena.
			break;			//termino el ciclo de carga. rompiendo la estructura repetitiva
		}
	}

	/* Ahora verifico que dos valores alfabetico no sean consecutivos*/
	/* Ten en cueta que las mayusculas van del 65 al 90    */
	/* las minusculas van del 97 al 122                   */
	/* eso significa que debere igualar el codigo a mayuscula o a minuscula */
	i=0;
	char letra0,letra1;
	bool band = true;			// si es verdadera la contraseña cumple con la regla. Si es falsa no cumple con la regla.
	
	while(i<10 || cad[i] != '\0')
	{
		if(isalpha(cad[i]) && isalpha(cad[i+1])
		{ 	//determino si es alfabetico, es decir una letra.
			letra0=toupper(cad[i]);			//convierto la letra a mayuscula si esta en mayuscula no hace nada.
			letra1=toupper(cad[i+1]);		//convierto la letra Siguiente a mayuscula si esta en mayuscula no hace nada.
			if(letra0+1==letra1){			//Verifico que no sea dos consecutiva.
				band = false;					//indicaria que no cumple con la regla.
				break;							// termino el ciclo.
			}
		}
		i++;
	}
	if(band)
		printf("\t\n\n Cumple con la regla");
	else
		printf("\t\n\n NOOO cumple con la regla");

}

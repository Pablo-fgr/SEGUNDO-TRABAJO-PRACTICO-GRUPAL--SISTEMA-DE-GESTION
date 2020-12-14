#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>

struct Usuarios{
	char Usuario[10];
	char password[32];
	char Contrasenia[32];
	char Apellido_y_Nombre[60]; 
};

int main()
{
	Usuarios reg;
	setlocale(LC_ALL, "");
	int i,l,a,digi=0,up=0,low=0,schar=0;
	int band=0, mayus=0, minus=0, digitos=0;
	printf("\nIngrese su nombre de usuario: ");
	gets(reg.Usuario);
	l = strlen(reg.Usuario);
	while(band==0)
	{
		if(l<6)
		{
			printf("\nError: su nombre de usuario no puede tener menos de 6 caracteres.\n");
		}
		if(l>10)
		{
		printf("\nError: su nombre de usuario no puede tener mas de 10 caracteres.\n");
		}
		else
		{
			for(int j=0; reg.Usuario[j]!=NULL; j++)
			{
				if(reg.Usuario[j]>='A' && reg.Usuario[j]<='Z')

					mayus++;

				if(reg.Usuario[0]>='a' && reg.Usuario[0]<='z')

					minus = 1;

				if(reg.Usuario[j]>='0' && reg.Usuario[j]<='9')

					digitos++;
			}
		}
		if(mayus>=2 && minus==1 && digitos<=3 && l>6 && l<10)
		{
			band = 1;
		}
			
		else{
			printf("\nError: el nombre de usuario no cumple con los requisitos.\n");
			printf("\nRequisitos: \n");
			printf("===========\n");
			printf("1.- Debe tener al menos 2 mayusculas\n");
			printf("2.- Debe iniciar con una letra minuscula\n");
			printf("3.- Debe tener 3 digitos como maximo\n");
			band = 0;
			getchar();
			system("cls");
			printf("\nIngrese un nombre de usuario v�lido: ");
			gets(reg.Usuario);
			l = strlen(reg.Usuario);
		}
	}
	
// conrase�a
	system("cls");
	//ahora usaremos un do while
	char valorNumerico;
	char letraActual;
	int numero_letra1=0, numero_letra2=0;
	
	do{
		//volvemos a 0 a todas las variables
		
	int i=0,l=0,j=0,digi=0,up=0,low=0,schar=0;
	int mayus=0, minus=0, digitos=0;
	int BvaloresAlfanumerico=0,CaracteresConsecutivos=0,BcaracteresSeguidos=0;

	_flushall();
	printf("Creacion de contrase�a");
	printf("\nIntroduzca la contrase�a correspondiente al ususario\n");
	printf("\nRecuende que debe cumlir con los siguientes requicitos:\n");
	printf("\n1 - Debe contener una letra mayuscula, una letra minuscula y un numero.\n");
	printf("\n2 - Solo deben ser caracteres alfanumericos.\n");
	printf("\n3 - Tener una longirud de entre 6 y 32 caracteres.\n");
	printf("\n4 - No debe tener mas de tres caracteres numericos consecutivos.\n");
	printf("\n5 - No debe tener 2 caracteres consecutivos que refieran a letras alfab�ticamente consecutivas.\n");
	
	printf("CONTRASENIA:  ");
	gets(reg.Contrasenia);
	
	//sacamos la longitud
	l=strlen(reg.Contrasenia);
	
	if(l>=6 and l<=32){
		i++;
	}
	else{
		printf("\nSu contrasenia no cumple con la longitud deseada. Vuelva a ingresarla por favor.\n");	
	}
	
	//se revisa los numeros consecutivos
	for(j=0;j<l;j++){  
		valorNumerico=reg.Contrasenia[j];
		
		if(valorNumerico>47 and valorNumerico<58){
			CaracteresConsecutivos++;
		
		}else{
			CaracteresConsecutivos=0;
		}
		
		if(CaracteresConsecutivos==3){
			j=l;
			i=0;
			printf("\nLa contrasenia ingresada tiene 3 numeros consecutivos. Vuelva a ingresarla por favor.\n");
		}
		
	}
	if(CaracteresConsecutivos<3){  
	     i++;
	 }
	     
	 //verificamos si son alfanumericos    
	for(j=0;j<l;j++){
		if((reg.Contrasenia[j]>47 and reg.Contrasenia[j]<56) or (reg.Contrasenia[j]>54 and reg.Contrasenia[j]<91) or (reg.Contrasenia[j]>96 and reg.Contrasenia[j]<123)){
			
		}
		else{
			printf("\nLa clave que usted introdujo posee un caracter que no es alfanumerico. Vuelva a ingresala por favor. \n");
			j=l;
			BvaloresAlfanumerico=1;
		}
	}
	if(BvaloresAlfanumerico==0){
		i++;
	}
	
	//letras mayusculas,minusculas y numeros
	for(j=0;j<l;j++){
		
		letraActual=reg.Contrasenia[j];
		
		if(letraActual==toupper(letraActual)){
			mayus++;
		}
		if(letraActual==tolower(letraActual)){
			minus++;
		}
		if(letraActual>47 and letraActual<58){
			digitos++;
		}
	}
	if(digitos>0 and minus>0 and mayus>0){
		i++;
	}
	else{
		printf("\nSu contrase�a carece de letras mayusculas/minusculas o algun numero. Vuelva a ingresar la clave por favor .\n");
		i=0;
	}
	
	i++;
	for(j=0;j<l-1;j++){
		numero_letra1= toupper(reg.Contrasenia[j]);
		numero_letra2= toupper(reg.Contrasenia[j+1]);
		
		if(numero_letra2==numero_letra1+1 and (reg.Contrasenia[j]>64 and reg.Contrasenia[j+1]<90)){
			printf("\nSu clave posee dos letras que son consecutivas. Escriba otra vez la vlave por favor \n");
			j=l;
			i=0;
		}
	}

    if(i==5){
    	system("pause");
	}
	else{
		system("pause");
		system("cls");
	}

	}while(i==5);

	printf("\nUsuario registrado con exito\n");
	_flushall();
	
 
	getch();
}
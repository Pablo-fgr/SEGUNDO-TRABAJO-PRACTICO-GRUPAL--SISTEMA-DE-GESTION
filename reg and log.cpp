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
			printf("\nIngrese un nombre de usuario válido: ");
			gets(reg.Usuario);
			l = strlen(reg.Usuario);
		}
	}
	
	system("cls");
	printf("Hola %s!, Ingrese su contraseña:\n",reg.Usuario);
	reg.Contrasenia[0] = getch();
	i=0;
	while(i<32)
	{
		printf("*");
		i++;
		reg.Contrasenia[i]=getch();
		if(reg.Contrasenia[i]==13)
		{
			reg.Contrasenia[i] = '\0';
			break;
		}
	}
	
	i=0;
	char letra0, letra1;
		bool bandera = true;			// si es verdadera la contraseña cumple con la regla. Si es falsa no cumple con la regla.
	
	while(i<32 || reg.Contrasenia[i] != '\0')
	{
		if(isalpha(reg.Contrasenia[i]) && isalpha(reg.Contrasenia[i+1]))
		{ 	//determino si es alfabetico, es decir una letra.
			letra0=toupper(reg.Contrasenia[i]);			//convierto la letra a mayuscula si esta en mayuscula no hace nada.
			letra1=toupper(reg.Contrasenia[i+1]);		//convierto la letra Siguiente a mayuscula si esta en mayuscula no hace nada.
			if(letra0+1==letra1){			//Verifico que no sea dos consecutiva.
				bandera = false;					//indicaria que no cumple con la regla.
				break;							// termino el ciclo.
			}
		}
		i++;
	}
	if(bandera)
		printf("\t\n\n Cumple con la regla");
	else
		printf("\t\n\n NOOO cumple con la regla");
	
	
	//gets(reg.Contrasenia);
	a=strlen(reg.Contrasenia);
	int band2=0;
	while(band2==0)
	{
		if(a<6)
		{
			printf("Error: su contraseña no puede tener menos de 6 caracteres ");
		}
		else if(a>32)
		{
			printf("Error: Contraseña no puede exceder de los 32 caracteres ");
		}
		else
		{
			for(i=0;reg.Contrasenia[i]!=NULL;i++)
			{	
				if(reg.Contrasenia[i]>='A' && reg.Contrasenia[i]<='Z')

					up++;

				if(reg.Contrasenia[i]>='a' && reg.Contrasenia[i]<='z')

					low++;

				if(reg.Contrasenia[i]>='0' && reg.Contrasenia[i]<='9')

					digi++;

				if(reg.Contrasenia[i]==','||reg.Contrasenia[i]=='.'||reg.Contrasenia[i]==';'||reg.Contrasenia[i]==':'||reg.Contrasenia[i]=='?')

					schar++;
			}
		}
	
		
		if(up==0)
			printf("Debe haber al menos una letra mayuscula en su contraseña\n");

		if(low==0)
			printf("Debe haber al menos una letra minuscula en su contraseña\n");

		if(digi==0)
			printf("Debe haber al menos un digito en su contraseña\n");

		if(schar>0)
			printf("No puede haber signos de puntuacion en su contraseña");
			
		else
		band2=1;
	}
	
	int band3=0;
	while(band3==0)
	{
		printf("Confirmar contraseña\n");
			gets(reg.password);

			if(strcmp(reg.Contrasenia,reg.password)==0)
			{
				printf("Bienvenido\a %s!, se a registrado correctamente",reg.Usuario);
				band3=1;
			}else{
				
			printf("No coincidio la contraseña\n");
			band3=0;
		}
	}
	
	getch();
}

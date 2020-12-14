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
	
	
		printf("\n\t                 CREACION DE USUARIO                          ");
		printf("\n\t                 -------------------                        \n");	
		
		printf("\tRequisitos\n");
		printf("\t----------\n");		  
		printf("\n\tEl nombre de usuario debe:\n\n\t-Tener entre 6 y 10 caracteres entre letras, numeros y/o simbolos \n\t  del conjunto {+,-,/,*,?,¿,!,¡}\n\n\t-Comenzar con una letra minuscula\n\n\t-Tener al menos 2 letras mayusculas\n\n\t-Tener como maximo 3 numeros\n\t");
	
  
				 printf("\n\n\n");
				_flushall();
/*uSUARIO*/		printf("\n\tIngrese su Usuario:\n");
				printf("\t--->Usuario: ");
		  		gets(reg.Usuario);
		  		

	l = strlen(reg.Usuario);
	while(band==0)
	{
		if(l<6)
		{
			printf("\n\n\tERROR-> el nombre de usuario no puede tener menos de 6 caracteres.\n\n\n");
			
		}
		if(l>10)
		{
			printf("\n\n\tERROR-> el nombre de usuario no puede tener mas de 10 caracteres.\n");
			
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
			printf("\t              -NO CUMPLE LAS CONDICIONES- ");
			printf("\n\t                    -REINTENTE-   \n");
			printf("\n\tRequisitos\n");
			printf("\t----------\n");		  
			printf("\n\tEl nombre de usuario debe:\n\n\t-Tener entre 6 y 10 caracteres entre letras, numeros y/o simbolos \n\t  del conjunto {+,-,/,*,?,¿,!,¡}\n\n\t-Comenzar con una letra minuscula\n\n\t-Tener al menos 2 letras mayusculas\n\n\t-Tener como maximo 3 numeros\n\t");
	
			band = 0;
			
			
			printf("\n\n\n");
			printf("\n\tIngrese un usuario valido:\n\t--->");
			gets(reg.Usuario);
			l = strlen(reg.Usuario);
		}
	}
	
// conraseña
	system("cls");
	//ahora usaremos un do while
	char valorNumerico;
	char letraActual;
	int numero_letra1=0, numero_letra2=0;
	
	do{
		//volvemos a 0 a todas las variables
		
	int i=0,j=0,l=0;
	int mayus=0, minus=0, digitos=0;
	int BvaloresAlfanumericos=0,CaracteresConsecutivos=0,BcaracteresSeguidos=0;

	_flushall();
		printf("\n\t                 CREACION DE CONTRASEÑA                            ");
		printf("\n\t                -------------------------                        \n");	
		
		printf("\tRequisitos\n");
		printf("\t----------\n");

		printf("\n\t1 - Debe contener una letra mayuscula, una letra minuscula y un numero.\n");
		printf("\n\t2 - Solo deben ser caracteres alfanumericos.\n");
		printf("\n\t3 - Tener una longirud de entre 6 y 32 caracteres.\n");
		printf("\n\t4 - No debe tener mas de tres caracteres numericos consecutivos.\n");
		printf("\n\t5 - No debe tener 2 caracteres consecutivos que refieran a letras\n\t alfabéticamente consecutivas.\n");
		
		printf("\n\n\tIngrese su Contrasena:\n");
		printf("\t--->Contrasena: ");
		gets(reg.Contrasenia);
	
	//sacamos la longitud
	l=strlen(reg.Contrasenia);
	
	if(l>=6 and l<=32){
		i++;
	}
	else{
		printf("\n\n\tLa contrasenia debe tener entre 6 y 32 caracteres.\n\t                  Reintente.\n");	
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
			printf("\n\n\tLa contrasenia ingresada tiene 3 o mas numeros consecutivos.\n\t                   Reintente.\n");
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
			printf("\n\n\tLa clave posee un caracter que no es alfanumerico.\n\t                  Reintente.\n");
			j=l;
			BvaloresAlfanumericos=1;
		}
	}
	if(BvaloresAlfanumericos==0){
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
		printf("\n\n\tLa contraseña carece de letras mayusculas/minusculas o algun numero.\n\t                  Reintente.\n");
		i=0;
	}
	
	i++;
	for(j=0;j<l-1;j++){
		numero_letra1= toupper(reg.Contrasenia[j]);
		numero_letra2= toupper(reg.Contrasenia[j+1]);
		
		if(numero_letra2==numero_letra1+1 and (reg.Contrasenia[j]>64 and reg.Contrasenia[j+1]<90)){
			printf("\n\n\tLa clave no puede poseer dos letras consecutivas.\n\t                  Reintente.\n");
			j=l;
			i=0;
		}
	}

    if(i==5)
	{
    	printf("\n\n\t       ------Usuario registrado con exito------     \n");
		_flushall();
		system("pause");
		exit(1);
		
		//aqui va el fwrite en el archivo
	}
	else
	{
		
		system("pause");
		system("cls");
	}

		
	}while(i!=5);

	
	
 
	getch();
}

/*-------------Librerias----------------*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include <wchar.h>
#include <locale.h> 
#include <ctype.h> 


/*------------------Estructuras----------------*/

struct usuarios
{
	char usuario[10];
	char contrasena[32];
	char ApellidoNombre[60];
};

struct veterinarios
{
	char usuario[10];
	char contrasena[32];
	char ApellidoNombre[60];
	int Matricula;
	int Dni;
	char Telefono[25];
};

struct Fecha
{
	int Dia;
	int Mes;
	int Anio;
	
};

struct turnos
{
    int Matricula;
    Fecha fecha;
    int Dni_Dueno;
    char DetalleDeAtencion[380];
};

struct mascota
{
	char ApellidoNombre[60];
	char Domicilio[60];
	int DNI_duenio;
	char Localidad[60];
	Fecha FechaNacimiento;
	float Peso;
	char Telefono[25];
};

struct TOP
{
	char ApellidoNomb[60];
	int N;
};

/*------------------------Prototipos de funciones------------------------*/

void CargaUsuarios(FILE *p,int n);
void IniciarSesion(int &n);

main()
{
	setlocale(LC_CTYPE,"Spanish");
	
	system("COLOR 3F");	
	
	FILE *p;
	
	int n=0;
	
	p=fopen("Usuarios.dat","rb");
     
    if(p==NULL)
	{
  		system("CLS");
		printf("\n\n\n\t                        B I E N V E N I D O                          ");
		printf("\n\t                    ---------------------------               \n\n\n\n\n");
		
		printf("\n\t          Deberas crear tu usuario por ser la primera vez               ");    
		printf("\n\t       ------------------------------------------------------      \n\n\t");
		printf("\n\n\n\t                       ------------------>                       \n");
		printf("\t                       ------------------>                       \n");
		printf("\t                       ------------------>                       \n\n\t");
		system("pause");
   		fclose(p);

    	CargaUsuarios(p,n);  //sirve para crear al primer usuario (que seria el administrador)
    }
    
    else
	{
     	fclose(p);
     	
	 }
     system("cls");
	
     do{//en si el programa 
     	IniciarSesion(n);
     	
     	
     	
     	
     	switch(n)
		{
     		case(1):;break;
     		
			case(2):;break;
     	
		 	case(3):;break;
     		
			case(4):printf("\n\n\n\n\n\t************************************************************\n");
	    				  printf("\t**                                                        **\n");
	    				  printf("\t**              SALIENDO DEL PROGRAMA...                  **\n");
	    				  printf("\t**                                                        **\n");
	    				  printf("\t**              QUE TENGA UN LINDO DIA!                   **\n");
	    				  printf("\t**                                                        **\n");
	    				  printf("\t************************************************************\n\n\n\n\n");
						  system("pause");
						  break;
		}
     	
     	
     	
	 }	while(n!=4);
	
	
	
	
	
	
	
	return 0;
}

/*----------------------------------------------------Funcion para cargar usuario--------------------------------------------------*/

void CargaUsuarios(FILE *p, int n)
{
	
	system("COLOR B0");
   
   	int i=0,ContadorDeMayuscula=0,ContadorDeDigitos=0;
    FILE *P;
    
    usuarios pp;
    veterinarios PP;
    char Nombre[10],NombreAUX[10];
    char Letraminuscula,LetraMayuscula;
     

    
     
    system("cls");
     
     
    do{
     	
     	ContadorDeMayuscula=0;
     	ContadorDeDigitos=0;
     	i=0;
     		printf("\n\t Crea tu nombre de usuario\n");
   			printf("\t-----------------------------\n\n");
     	
     		printf("\tRequisitos\n");
			printf("\t----------\n");
				  
			printf("\n\t(1) - El nombre de usuario debe:\n\n\t(2) - Tener entre 6 y 10 caracteres entre letras, numeros y/o simbolos \n\t del conjunto {+,-,/,*,?,¿,!,¡}\n\n\t(3) - Comenzar con una letra minuscula\n\n\t(4) - Tener al menos 2 letras mayusculas\n\n\t(5) - Tener como maximo 3 numeros\n\t");
		  		
     		printf("\n\t(0) - Para salir-\n\n");
     		
			printf("\t--->Usuario: ");
     	
		 	_flushall();
     		
			gets(Nombre);
     		
     		Letraminuscula=Nombre[0];
     		
     		if(Letraminuscula=='0'){
     			system("cls");
     			return ;
			 }
			 
     		if(strlen(Nombre)<=10){            
     			
     			
     			if(Letraminuscula==tolower(Letraminuscula)){  //Verificamos si la primera letra es una minuscula
     				
     				
     				
     				for(i=0;i<strlen(Nombre);i++){
     					LetraMayuscula=toupper(Nombre[i]);
     					
     					if(!isalpha(Nombre[i])){   //Sirve para que las letras que comparemos sean letras y no simbolos (que el programa
     						                       // Concidera como mayusculas)
						 }
     					else{   
						 
     					if(Nombre[i]==LetraMayuscula){  //Buscamos para ver si se cumple la minima cantidad de mayusculas
     						ContadorDeMayuscula=1+ContadorDeMayuscula;
						 }
     				 }
					 }
					 
					 
     				i=0;
     				if(ContadorDeMayuscula>=2){
     					
     					
     					for(i=0;i<strlen(Nombre);i++){
     						
     						if(isalpha(Nombre[i])){           //Vemos si no se supera la cantidad de digitos
     							
     							
     							
							 }
     						else{
     							
     							ContadorDeDigitos++;
							 }
     						
     						
						 }
     					i=0;
     					
     					
     					if(ContadorDeDigitos<=3)
						{
     						
     						
     						switch(n)
							{
							 
     							case(0):P=fopen("Usuarios.dat","rb");break;
								
								case(1):P=fopen("Veterinarios.dat","rb");break;
     					    }
     							
								if(P!=NULL)
								{
     								
								 
     						
     								switch(n)
									{
								 
     							
										case(0):
     									{
									 
     										while(!feof(P))
											{
     								
     											fread(&pp,sizeof(usuarios),1,P);	
     								
     								
     								
     								
     											if(strcmp(pp.usuario,Nombre)==0)
												{
     												i=i+1;
								 				}
								 			}
								 		
											break;
								 		}
								 
								 		case(1):
								 	
								 		{
									 
     										while(!feof(P))
											{
     								
     											fread(&PP,sizeof(veterinarios),1,P);	
     								
     								
     								
     								
     											if(strcmp(PP.usuario,Nombre)==0)
												{	
     												i=i+1;
												 }
								 			}
								 
								 			break;
								 		}
								 
									}
								  
								}
     					
								 
     							if(i==0)             //Vemos si el nombre no esta repetido
     							{
     								
     							
     								printf("\n\n\t Usuario registrado con exito \n");
									printf("\t -----------------------------------\n");
     								system("pause");
     								system("cls");
     								i=1;
     								
     	
     								
								 	fclose(P);
     								
     								
								 }
								 else
								 {
								 	
								 	printf("\n\n\tERROR-> Nombre de usuario ya registrado en el sistema.\n\tReintente");
									
									system("pause");
								 	
									system("cls");
								 	
									i=0;
								 	
								 }
						}
     						
     				
     						
     						
						 
     					else
						{
     						
     						printf("\n\n\tERROR-> el nombre de usuario tiene mas de 3 digitos numericos\n\n");
							
							system("pause");
     						
							system("cls");
     						
							i=0;
						}
     					
				}
     				else{
     					
     					printf("\n\n\tERROR-> el nombre de usuario debe tener al menos 2 letras mayusculas\n\n");
     				
					 	system("pause");
     					
						system("cls");
     				
					 	i=0;
     				}
     					
					 
     				
		}
			
     			else{
     				
     				printf("\n\n\tERROR-> el nombre de usuario debe comenzar con minuscula.\n\tReintente");system("pause");
     				
					system("cls");
     				
					i=0;
				 }
     			
     			
     	}

     		else{
     		
			 	printf("\n\n\tERROR-> el nombre de usuario no puede tener mas de 10 caracteres.\n\tReintente");
			
				system("pause");
     		
			 	system("cls");
     			
				 i=0;
			 }
     		
     		
		 
     	
     	
     	
     	
	 }while(i==0);
	
	
	
	
	
}
/*-----------------------------------------------Funcion para inicio de sesion del usuario-----------------------------------*/


void IniciarSesion(int &n)
{ 
	do{
		printf("\n\n");
		printf("\n\t**************¡Bienvenido al menu principal!*********************");
		printf("\n\t**                                                             **");    
		printf("\n\t**	              ¿Que cargo posee?                        **");
		printf("\n\t**                                                             **");
		printf("\n\t** (1)  ->  VETERINARIO                                        **");
		printf("\n\t**                                                             **");
		printf("\n\t** (2)  ->  ASISTENTE                                          **");
		printf("\n\t**                                                             **");
		printf("\n\t** (3)  ->  ADMINISTRADOR                    	               **");
		printf("\n\t**                                                             **");
		printf("\n\t** (4)  ->  SALIR                                              **");
		printf("\n\t**                                                             **");																			   
		printf("\n\t*****************************************************************");
		printf("\n\n\tIngrese su opcion:");
		scanf("%d",&n);
		
		
		system("cls");
		
	}while(n<1 or n>4);
}


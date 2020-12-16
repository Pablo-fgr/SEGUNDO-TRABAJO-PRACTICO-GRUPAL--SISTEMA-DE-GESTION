#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct day
{
	char dias[80];
	float horaInicio[80];
	float horaFin[80];
	
};

struct Fecha
{
	int Dia;
	int Mes;
	int Anio;
};

struct Veterinario
{
	char Apellido_y_Nombre[60];
	int Matricula;
	int Dni;
	char Telefono[25];
	   	   
 /*------------------------*/
       /*atenciones:*/

		int cantDias;	   
		day atencion[7];
		 					      
 	   
};

struct Usuarios
{
	char Usuario[10];
	char Contrasenia[10];
	char Apellido_y_Nombre[60]; 
};

struct Turnos
{
	int Matricula_de_veterinario;
	Fecha fecha;
	int DNI_duenio;
	char Detalle_de_atencion[380];
};

void menuprincipal();
void registrarVet();
void registrarAsist();
void registrarAtenciones();
void rankingAtenciones(FILE *arch,Veterinario reg);
bool buscar_veterinario(char apynom[60], int matricula);
bool buscar_usuario(char user[10]);
void validar_contrasenia(char cadena[32]);
bool letras_consecutivas(char contrasenia[32]);
bool numeros_consecutivos(char contrasenia[32]);


main()
{
 	  system("COLOR f3");	
   	  
   	  
   	  
	  menuprincipal();
   	  
 
}
void menuprincipal()
{
 	 	int opcion;
		FILE *arch_veterinarios;	
		Veterinario reg;	 
        
  
	 do
	 {
	   system("CLS");
		printf("\n\t                       B I E N V E N I D O                          ");
		printf("\n\t                      ---------------------                         \n\n");
																							
																																																														   																					
		printf("\n\t********************* MODULO ADMINISTRACION *************************");    
		printf("\n\t**                                                                 **");
		printf("\n\t** (1)  -> REGISTRAR VETERINARIO                                   **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (2)  -> REGISTRAR USUARIO ASISTENTE                             **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (3)  -> ATENCIONES POR VETERINARIOS                             **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (4)  -> RANKING DE VETERINARIOS POR ATENCIONES                  **");
		printf("\n\t**                                                                 **"); 
		printf("\n\t**                                                                 **");
		printf("\n\t** (5)  -> CERRAR LA APLICACION                                    **");
		printf("\n\t**                                                                 **");																			   
		printf("\n\t*********************************************************************");
		printf("\n\n\tIngrese su opcion:");
  		scanf("%d",&opcion);
		
		if(opcion==1)
		{
		 	registrarVet();
			printf("\n");	 		 
	    }
	    if(opcion==2)
		{
		 	registrarAsist();
			printf("\n");	 		 
	    }
		if(opcion==3)
		{
		 	registrarAtenciones();
			printf("\n");	 		 
	    } 
		if(opcion==4)
		{
		 	rankingAtenciones(arch_veterinarios,reg);
			printf("\n");	 		 
	    }
		if(opcion==5)
		{
		 	exit(1);	 		 
	    }   
			
	}while(opcion!= 0);
	

}
void registrarVet()
{
		 system("COLOR A0");
 	     FILE *arch_veterinarios;
	 	 arch_veterinarios = fopen("Veterinarios.dat", "a+b");
		 Veterinario reg;
		  	   
  
		
		system("cls");  	   
        printf("\n\t                      REGISTRO DE VETERINARIOS                          ");
		printf("\n\t                      ------------------------                      \n\n");
		
		_flushall();								    
    	printf("\n\tIngrese los datos del veterinario que desea registrar:\n");
   		printf("\t--------------------------------------------------------");
   		
   		
   		
		
																   													  
			printf("\n\n\t--->Apellido y nombre: ");
			_flushall();						   
  			gets(reg.Apellido_y_Nombre);
  						 
	 		printf("\n\n\t--->Numero de Documento: ");
			_flushall(); 
			scanf("%d",&reg.Dni);
								 					 
  			printf("\n\n\t--->Matricula profesional: ");
			_flushall();
			scanf("%d",&reg.Matricula);
								   
  			printf("\n\n\t--->Telefono: ");
			_flushall();
			gets(reg.Telefono);
  						 
			printf("\n\n\tDatos guardados correctamente-\n\n");
			
						  
		//printf("\n\tPresione enter para crear su usuario--->");			  			   						  				     
		//_flushall();										
		//getchar();								 			   																			   																																										  			   						  				     
					  
		/*system("CLS");	
	 	printf("\n\t                 CREACION DE USUARIO DE VETERINARIOS                          ");
		printf("\n\t                 -----------------------------------                      \n\n");	
		
		printf("\tCONDICIONES\n");		  
		printf("\n\tEl nombre de usuario debe:\n\n\t-Tener entre 6 y 10 caracteres entre letras, numeros y/o simbolos \n\t  del conjunto {+,-,/,*,?,¿,!,¡}\n\n\tTambien debera:\n\n\t-Comenzar con una letra minuscula\n\n\t-Tener al menos 2 letras mayusculas\n\n\t-Tener como maximo 3 numeros\n\t");
		getchar();
  
				 printf("\n\n\n");
				_flushall();
/*uSUARIO*/		//printf("\n\tIngrese su Usuario:\n");
			//	printf("\t--->Usuario: ");
		  	//	gets(reg.userVet);
		  						  
			//	_flushall();  
/*CONTRA*/	//	printf("\n\n\tIngrese su Contrasena:\n");
			//	printf("\t--->Contrasena: ");
		  	//	gets(reg.contraUserVet);
		  		
		  		
		 

 		
	   	fwrite(&reg, sizeof(reg), 1, arch_veterinarios);
		fclose(arch_veterinarios);
 
}
void registrarAsist()
{        	
		 system("COLOR B0");
 	     FILE *arch_usuarios;
	 	 arch_usuarios = fopen("Usuarios.dat", "a+b");
		 Usuarios reg1;
		 
		 bool h;
		 
		 int band = 0, mayuscula = 0, digitos = 0, caracter_invalido = 0;
	   
		
		system("cls");  	   
        printf("\n\t                       REGISTRO DE ASISTENTES                           ");
		printf("\n\t                      ------------------------                      \n\n");
		
		_flushall();								    
    	printf("\n\tIngrese los datos del asistente que desea registrar:\n");
   		printf("\t------------------------------------------------------");
   															  
		printf("\n\n\t--->Apellido y nombre: ");
		_flushall();						   
  		gets(reg1.Apellido_y_Nombre);
  		
		printf("\n\tPresione enter para crear su usuario--->");			  			   						  				     
		_flushall();
		getchar();			
		
		system("cls");  	   
        printf("\n\t                       REGISTRO DE ASISTENTES                           ");
		printf("\n\t                      ------------------------                      \n\n");
		
		printf("\n\n\tIngrese su nuevo usuario.");
		printf("\n\tEste debera cumplir con los siquientes requisitos: \n");
		printf("\t------------------------------------------------------");
		printf("\n\n\t (1) -> El usuario debe tener como minimo 6 caracteres y maximo de 10, los \n\tcuales podran ser letras, numeros y/o simbolos del conjunto {+,-,/,*,?,¿,!,¡}");
		printf("\n\n\t (2) -> Ser unico para cada usuario registrado.");
		printf("\n\n\t (3) -> Comenzar con una letra minuscula");
		printf("\n\n\t (4) -> Tener al menos 2 letras mayusculas");
		printf("\n\n\t (5) -> Tener como maximo 3 digitos.");
		
		do
		{
			printf("\n\n\t--->Ingrese el usuario: ");
			_flushall();
			gets(reg1.Usuario);
			h = buscar_usuario(reg1.Usuario);
			if(h == true)
			{
				printf("\n\t ERROR - ESTE USUARIO YA ESTA REGISTRADO. INTENTE NUEVAMENTE.");
				
			}
			
			
		}while(h == true);
		
		while(band == 0)
		{
			if(strlen(reg1.Usuario)<6)
			{
				printf("\n\n\t ERROR - El usuario no puede tener menos de 6 caracteres");
				band = 1;
			}
			
			if(strlen(reg1.Usuario)>10)
			{
				printf("\n\n\t ERROR - El usuario no puede tener mas de 10 caracteres");
				band = 1;
			}
			
			if(!(reg1.Usuario[0]>='a' && reg1.Usuario[0]<='z'))
			{
				printf("\n\n\t ERROR - El nombre de usuario debe empezar con una minuscula");
				band = 1;
			}
			
			for(int i = 0; i<10 ; i++)
			{
				if(reg1.Usuario[i]>='A' && reg1.Usuario[i]<='Z')
				{
					mayuscula++;
				}
				
				if((reg1.Usuario[i]>='0' && reg1.Usuario[i]<='9')  || (reg1.Usuario[i]== '+') || (reg1.Usuario[i]=='-') || (reg1.Usuario[i]=='/') || (reg1.Usuario[i]=='*') || (reg1.Usuario[i]=='?') || (reg1.Usuario[i]=='¿') || (reg1.Usuario[i]=='!') || (reg1.Usuario[i]=='¡'))
				{
					digitos++;
				}
				
				if(!((reg1.Usuario[i]>='0' && reg1.Usuario[i]<='9') || ((reg1.Usuario[i]>='A' && reg1.Usuario[i]<='Z')) || ((reg1.Usuario[0]>='a' && reg1.Usuario[0]<='z')) ||(reg1.Usuario[i]== '+') || (reg1.Usuario[i]=='-') || (reg1.Usuario[i]=='/') || (reg1.Usuario[i]=='*') || (reg1.Usuario[i]=='?') || (reg1.Usuario[i]=='¿') || (reg1.Usuario[i]=='!') || (reg1.Usuario[i]=='¡')))
				{
					caracter_invalido++;
				}
			}
			
			if(caracter_invalido != 0)
			{
				printf("\n\n\t ERROR - El usuario ingresado tiene caracteres invalidos");
				band = 1;
			}
			if(mayuscula<2)
			{
				printf("\n\n\t ERROR - El usuario debe tener al menos 2 mayusculas");
				band = 1;
			}
			
			if(digitos>3)
			{
				printf("\n\n\t ERROR - El usuario no puede tener mas de 3 digitos");
				band = 1;
			}
			if(band == 1)
			{
				printf("\n\n\t [INGRESE EL USUARIO NUEVAMENTE...]\n\n");
				_flushall();
				gets(reg1.Usuario);
				band = 0; mayuscula = 0; digitos = 0; caracter_invalido = 0;
			}
			else
			{
				break;
			}
				
		}
		
		system("cls");  	   
        printf("\n\t                       REGISTRO DE ASISTENTES                           ");
		printf("\n\t                      ------------------------                      \n\n");
						  
		printf("\n\n\t [Nombre de usuario %s correcto!...]\n", reg1.Usuario);
		printf("\n\t Condiciones para el ingreso de la contrasenia: ");
		printf("\t-------------------------------------------------");
		printf("\n\t (1) Debera contener al menos una letra mayuscula, una letra minuscula y un numero. ");
		printf("\n\t (2) No podra tener ningun caracter de puntuacion, ni acentos, ni espacios. ");
		printf("\tSolo caracteres alfanumericos. ");
		printf("\n\t (3) Debera tener entre 6 y 32 caracteres. ");
		printf("\n\t (4) No debe tener mas de 3 caracteres numericos consecutivos. ");
		printf("\n\t (5) No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendetemente). ");
		printf("\t Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas. ");
		
		printf("\n\n\t --->Ingrese su clave: ");
		_flushall();
		gets(reg1.Contrasenia);
		
		validar_contrasenia(reg1.Contrasenia);  

 
	   	fwrite(&reg1, sizeof(reg1), 1, arch_usuarios);
		fclose(arch_usuarios);
		
	printf("\n\n\t************************************************************\n");
	    printf("\t**                                                        **\n");
	    printf("\t**                                                        **\n");
	    printf("\t**      SE HA REGISTRADO EL USUARIO EXITOSAMENTE!!        **\n");
	    printf("\t**                                                        **\n");
	    printf("\t**                                                        **\n");
	    printf("\t************************************************************\n\n");
	    getch();
 
} 
void registrarAtenciones()
{        
	system("COLOR e0");
				 
	FILE *arch_veterinarios, *arch_turnos;
	arch_veterinarios = fopen("Veterinarios.dat", "rb");
	arch_turnos = fopen("Turnos.dat", "rb");
			 	 
	Veterinario regv;
				
	Turnos regt;
				
				
	if((arch_veterinarios == NULL) || (arch_turnos == NULL))
	{
		printf("\n\n\t ERROR DE ARCHIVOS!!");
		exit(1);
	}
				  	   
	int buscarMat,n;
	int mes, c;
				
		  	   
				system("CLS");
				   	  						     
		        printf("\n\t                    ATENCION DE VETERINARIOS                          ");
				printf("\n\t                    ------------------------                      \n\n");	
		
		
				printf("\n\tIngrese el numero del mes de las atenciones a listar:\n");
		   		printf("\t---------------------------------------------------------");
		   		
				_flushall();   													  
				printf("\n\n\t--->Mes a listar: ");						   
		  		scanf("%d",&mes);
		
				
				system("CLS");	   	  						     
		        printf("\n\t                    ATENCION DE VETERINARIOS                          ");
				printf("\n\t                    ------------------------                      \n\n");
				
				fread(&regv, sizeof(regv), 1, arch_veterinarios);
				
				while(!feof(arch_veterinarios))
				{
					c = 0;
					
					fread(&regt, sizeof(regt),1,arch_turnos);
					
					while(!feof(arch_turnos))
					{
						if(regt.fecha.Mes == mes && regt.Matricula_de_veterinario == regv.Matricula)
						{
							c++;
						}
						
						fread(&regt, sizeof(regt), 1, arch_turnos);
					}
					
					printf("\n\n\t-->El veterinario %s atendio %d mascotas", regv.Apellido_y_Nombre, c);
					
					fread(&regv, sizeof(regv),1,arch_veterinarios);
				}
				
				fclose(arch_veterinarios);
				fclose(arch_turnos);
				getch();
				
				/*if(buscarMat == reg.Matricula)
		  		{
  			 	 		printf("\n\n\n");	 
				   		printf("\n\t°Ingrese la cantidad de dias de atencion: ");
						scanf("%d",&reg.cantDias); 
						getchar();  
						
						_flushall();
						printf("\n\t°A continuacion ingrese los DIAS: \n");							 	   		
						
						for(int i=1; i<=reg.cantDias; i++)
						{
							printf("\n\tDia %d --->",i);
							scanf("%s",reg.atencion[i].dias);
									 				 	   
						}
						 														   									  

						rewind(arch_veterinarios);														   									  
						_flushall();
						printf("\n\n");
						printf("\n\t°Ingrese los horarios de cada dia: \n");							 	   		
						
						for(int i=1; i<=reg.cantDias; i++)
						{
							printf("\n\tDia (%d) %s:",i,reg.atencion[i].dias);
							printf("\n\tHora inicio --->");
							scanf("%f",&reg.atencion[i].horaInicio[i]);
							printf("\tHora fin --->");
							scanf("%f",&reg.atencion[i].horaFin[i]);
							printf("\n\n");
									 				 	   
						}
																				   									  
						
					
					rewind(arch_veterinarios);
					
					printf("\n");		
					_flushall();
					printf("\n\t********************* HORARIOS DE ATENCION *************************");    
					for(int i=1; i<=reg.cantDias; i++)
					{
						 	printf("\n\tDia (%d) %s:",i,reg.atencion[i].dias);
							printf("\n\tDesde %.2f Hasta %.2f hs.",reg.atencion[i].horaInicio[i],reg.atencion[i].horaFin[i]);
							printf("\n\n");
					 				 	   
					}
					printf("\n\t********************************************************************");
					printf("\n");
					
				}
				
				else
				{
		  		 	printf("\n\n\tLa matricula ingresada es incorrecta");				   		   			  	
				}  
		
		   
				system("pause");
																																																																																																							  																										  		  					 													   	   	   		 					       		     	 						   	  		  				   																							 	 		 		      
			fwrite(&reg, sizeof(reg), 1, arch_veterinarios);																																																																																																																																																																																																											  																																																																																																						  																										  		  					 													   	   	   		 					       		     	 						   	  		  				   																							 	 		 		      
			fclose(arch_veterinarios); */
			
}


struct matriculas
{
	int numMatriculas[100];
	int cantidadTurnos[100];
};

struct vets
{
	int vetEnMes;
	matriculas ingresoMatriculas[50]; 	
};


void rankingAtenciones(FILE *arch_veterinarios,Veterinario reg)
{
	    system("CLS");
		system("COLOR 3f");
			
	    arch_veterinarios = fopen("Veterinarios.dat", "r");
		fread(&reg, sizeof(reg), 1, arch_veterinarios); 	   
		rewind(arch_veterinarios);
		
		vets registro;
		int mayor=0;
		int ganadorRanking=0;	 
	
	
		printf("\n\t            Bienvenidos al ranking de veterinarios!\n\t         El nuevo incentivo para nuestros veterinarios");
		printf("\n\t-----------------------------------------------------------------                      \n\n");
	
																		   
		printf("\n\tPara la medicion del ranking del veterinario con mayor atencion \n\ten el periodo debera ingresar la matricula de todos los \n\tveterinarios que trabajaron en el mes.\n\n");
		
		printf("\n\tPrimer paso");
		printf("\n\t-----------\n\n");
		
		printf("\n\tIngrese la cantidad de veterinarios que trabajaron en el mes:");
		scanf("%d",&registro.vetEnMes);
		
		
		_flushall();
		
		for(int i=1 ; i<=registro.vetEnMes ; i++)
		{
			printf("\n\tIngrese la matricula del veterinario %d: ",i);
			scanf("%d",&registro.ingresoMatriculas[i].numMatriculas[i]);
			
			printf("\n\tIngrese la cantidad de turnos atendidos del veterinario %d: ",i);
			scanf("%d",&registro.ingresoMatriculas[i].cantidadTurnos[i]);
			
			printf("\n\n");
			
		}
	
		printf("\n\n\tPor favor espere un momento...\n\t");
		getchar();
		
		
		for(int i=1 ; i<=registro.vetEnMes ; i++)
		{	
			if(registro.ingresoMatriculas[i].cantidadTurnos[i] > mayor)
			{
				mayor = registro.ingresoMatriculas[i].cantidadTurnos[i];
				ganadorRanking = registro.ingresoMatriculas[i].numMatriculas[i];
				
			
			}
		}
			printf("\n\t--->El veterinario con mayor ranking de atenciones es el\n\tque posee la matricula numero: %d",ganadorRanking);
			printf("\n");
		
		printf("\n\n\n");
		
		printf("\n\t******************************************************************");    
		printf("\n\n\t|GANADOR DEL BONO MENSUAL: DOCTOR MATRICULADO CON MATRICULA %d|\n", ganadorRanking);		
		printf("\n\t******************************************************************");
					
		
	 system("pause");

	 fclose(arch_veterinarios);
	
}


/*-------------------------------FUNCION PARA BUSCAR VETERINARIO-----------------------------------------*/

bool buscar_veterinario(char apynom[60], int matricula)
{
	FILE *arch_veterinarios;
	
	Veterinario reg;
	
	arch_veterinarios = fopen("Veterinarios.dat", "ab");
	
	fread(&reg, sizeof(reg), 1, arch_veterinarios);
	
	while(!feof(arch_veterinarios))
	{
		if(strcmp(reg.Apellido_y_Nombre, apynom) == 0 || (matricula == reg.Matricula))
		{
			fclose(arch_veterinarios);
			return true;
		}
		fread(&reg, sizeof(reg), 1, arch_veterinarios);
	}
	fclose(arch_veterinarios);
	return false;
}

/*---------------------------------------FUNCION PARA BUSCAR USUARIO---------------------------------------*/

bool buscar_usuario(char user[10])
{
	FILE *arch_usuarios;
	
	Usuarios reg;
	
	arch_usuarios = fopen("Usuarios.dat", "ab");
	
	fread(&reg, sizeof(reg), 1, arch_usuarios);
	
	while(!feof(arch_usuarios))
	{
		if(strcmp(reg.Usuario, user)==0)
		{
			fclose(arch_usuarios);
			return true;
		}
		fread(&reg, sizeof(reg), 1, arch_usuarios);
	}
	
	
	fclose(arch_usuarios);
	return false;
}


/*----------------------------------FUNCION PARA VALIDAR LA CONTRASEÑA-----------------------------------------*/

void validar_contrasenia(char cadena[32])
{
	int i, n = 0, band = 0, letra_minuscula = 0, letra_mayuscula = 0, caracter_numerico = 0, caracter_invalido1 = 0;
	
	while(band == 0)
	{
		n = strlen(cadena);
		
		for(i = 0; i < n ;i++)
		{
			if(cadena[i]>='A' && cadena[i]<='Z')
			{
				letra_mayuscula++;
			}
			
			if(cadena[i]>='a' && cadena[i]<='z')
			{
				letra_minuscula++;
			}
			
			if(cadena[i]>='0' && cadena[i]<='9')
			{
				caracter_numerico++;
			}
			
			if((cadena[i]=='+') || (cadena[i]==',') || (cadena[i]=='.') || (cadena[i]==';') || (cadena[i]==':') || (cadena[i]=='"')
			|| (cadena[i]==']') || (cadena[i]=='[') || (cadena[i]== '{') || (cadena[i]== '}')|| (cadena[i]=='(') || (cadena[i]==')')|| (cadena[i]=='?') 
			|| (cadena[i]=='-') || (cadena[i]=='_') || (cadena[i]=='!') || (cadena[i]==' '))
			{
				caracter_invalido1++;
			}
		}
		
		if(letra_minuscula < 1)
		{
			printf("\n\n\t ERROR - La contrasenia debe tener al menos una letra minuscula. ");
			band = 1;
		}
		
		if(letra_mayuscula < 1)
		{
			printf("\n\n\t ERROR - La contrasenia debe tener al menos una letra mayuscula. ");
			band = 1;
		}
		
		if(caracter_numerico < 1)
		{
			printf("\n\n\t ERROR - La contrasenia debe tener al menos un caracter numerico. ");
			band = 1;
		}
		
		if(caracter_invalido1 != 0)
		{
			printf("\n\n\t ERROR - La contrasenia no debe contener signos de puntuacion, ni acentos, ni espacios. ");
			band = 1;
		}
		
		if(strlen(cadena) < 6)
		{
			printf("\n\n\t ERROR - La contrasenia debe tener al menos 6 caracteres. ");
			band = 1;
		}
		
		if(strlen(cadena)>32)
		{
			printf("\n\n\t ERROR - La contrasenia no puede tener mas de 32 caracteres. ");
			band = 1;
		}
		
		if(numeros_consecutivos(cadena))
		{
			printf("\n\n\t ERROR - La contrasenia no puede tener mas de 3 caracteres numericos consecutivos. ");
			band = 1;
		}
		
		if(letras_consecutivas(cadena))
		{
			printf("\n\n\t ERROR - La contrasenia no puede tener letras alfabeticamente consecutivas. ");
			band = 1;
		}
		
		if(band == 1)
		{
			_flushall();
			
			printf("\n\n\t--->Ingrese la contrasenia nuevamente: ");
			gets(cadena);
			
			band = 0; letra_minuscula = 0; letra_mayuscula = 0; caracter_numerico = 0; caracter_invalido1 = 0;
		}
		else
		{
			
			break;
			
		}
		
	}
}


/*--------------------------------------------FUNCION LETRAS CONSECUTIVAS-------------------------------------------------*/

bool letras_consecutivas(char contrasenia[32])
{
	int n = 0, i = 0, c = 0, c1 = 0; // c = letra en ASCII
	char letra, letra1, contrasenia2[32];
	
	contrasenia2[32] = contrasenia[32];
	
	n = strlen(contrasenia2);
	
	strlwr(contrasenia2);
	
	while(i < n - 1)
	{
		letra = contrasenia2[i];
		
		if(letra >= 'a' && letra <= 'z')
		{
			c = letra;
			
			letra1 = contrasenia2[i+1];
			
			c1 = letra1; 
			
			if(c+1 == c1) // comparo los consecutivos
			{
				return true;
			}
		}
		
		i++;
	}
	
	return false;
	
}

/*------------------------------FUNCION NUMEROS CONSECUTIVOS-----------------------------------*/

bool numeros_consecutivos(char contrasenia[32])
{
	int n = 0, i = 0, caracter_numerico = 0;
	
	n = strlen(contrasenia);
	
	
	while(i < n - 1);
	{
		if( contrasenia[i]>='0' && contrasenia[i]<='9')
		{
			caracter_numerico++;
		}
		
		if(caracter_numerico>3)
		{
			return true;
		}
		
		i++;
	}
	
	return false;
	
}

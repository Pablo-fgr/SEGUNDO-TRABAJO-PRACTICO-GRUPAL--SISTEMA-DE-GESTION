#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char registroVeterinarios[50];


struct day
{
	char dias[80];
	float horaInicio[80];
	float horaFin[80];
	
};
	
	
struct registrosVeterinarios
{
 	   char userVet[50];
	   char contraUserVet[50];   
 	   char apynom[60];
	   int matricula;
	   int DNI;
	   char telefono[25]; 
	   	   
 /*------------------------*/
       /*atenciones:*/

		int cantDias;	   
		day atencion[7];
		 					      
 	   
};

struct registrosUsuariosAsist
{
 	   char userAsist[10];
	   char contraUserAsist[10];   
 	   char apynom[60];
	   	   
};

void menuprincipal();
void registrarVet();
void registrarAsist();
void registrarAtenciones(FILE *arch, registrosVeterinarios reg);
void rankingAtenciones(FILE *arch,registrosVeterinarios reg);


main()
{
 	  system("COLOR f3");	
   	  
   	  
   	  
	  menuprincipal();
   	  
 
}
void menuprincipal()
{
 	 	int opcion;
		FILE *arch;	
		registrosVeterinarios reg;	 
        
  
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
		 	registrarAtenciones(arch,reg);
			printf("\n");	 		 
	    } 
		if(opcion==4)
		{
		 	rankingAtenciones(arch,reg);
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
 	     FILE *arch;
	 	 arch = fopen("Veterinarios.dat", "a+b");
		 registrosVeterinarios reg;
		  	   
  
		
		system("cls");  	   
        printf("\n\t                      REGISTRO DE VETERINARIOS                          ");
		printf("\n\t                      ------------------------                      \n\n");
		
		_flushall();								    
    	printf("\n\tIngrese los datos del veterinario que desea registrar:\n");
   		printf("\t--------------------------------------------------------");
   															  
		printf("\n\n\t--->Apellido y nombre: ");
		_flushall();						   
  		gets(reg.apynom);
  						 
	 	printf("\n\n\t--->Numero de Documento: ");
		_flushall(); 
		scanf("%d",&reg.DNI);
							 					 
  		printf("\n\n\t--->Matricula profesional: ");
		_flushall();
		scanf("%d",&reg.matricula);
								   
  		printf("\n\n\t--->Telefono: ");
		_flushall();
		scanf("%c",&reg.telefono);
  						 
		printf("\n\n\tDatos guardados correctamente-\n\n");
						  
		printf("\n\tPresione enter para crear su usuario--->");			  			   						  				     
		_flushall();										
		getchar();								 			   																			   																																										  			   						  				     
					  
		system("CLS");	
	 	printf("\n\t                 CREACION DE USUARIO DE VETERINARIOS                          ");
		printf("\n\t                 -----------------------------------                      \n\n");	
		
		printf("\tCONDICIONES\n");		  
		printf("\n\tEl nombre de usuario debe:\n\n\t-Tener entre 6 y 10 caracteres entre letras, numeros y/o simbolos \n\t  del conjunto {+,-,/,*,?,¿,!,¡}\n\n\tTambien debera:\n\n\t-Comenzar con una letra minuscula\n\n\t-Tener al menos 2 letras mayusculas\n\n\t-Tener como maximo 3 numeros\n\t");
		getchar();
  
				 printf("\n\n\n");
				_flushall();
/*uSUARIO*/		printf("\n\tIngrese su Usuario:\n");
				printf("\t--->Usuario: ");
		  		gets(reg.userVet);
		  						  
				_flushall();  
/*CONTRA*/		printf("\n\n\tIngrese su Contrasena:\n");
				printf("\t--->Contrasena: ");
		  		gets(reg.contraUserVet);
		  		
		  		
		  

 
	   	fwrite(&reg, sizeof(reg), 1, arch);
		fclose(arch);
 
}
void registrarAsist()
{        
		 system("COLOR B0");
 	     FILE *arch1;
	 	 arch1 = fopen("Usuarios.dat", "a+b");
		 registrosUsuariosAsist reg1;
	   
		
		system("cls");  	   
        printf("\n\t                       REGISTRO DE ASISTENTES                           ");
		printf("\n\t                      ------------------------                      \n\n");
		
		_flushall();								    
    	printf("\n\tIngrese los datos del asistente que desea registrar:\n");
   		printf("\t------------------------------------------------------");
   															  
		printf("\n\n\t--->Apellido y nombre: ");
		_flushall();						   
  		gets(reg1.apynom);
  						 
  						 
		printf("\n\n\n\tDatos guardados-\n\n");
						  
		printf("\n\tPresione enter para crear su usuario--->");			  			   						  				     
		_flushall();
		getchar();
																			 			   																			   																																										  			   						  				     
					  
		system("CLS");	
	 	printf("\n\t                  CREACION DE USUARIO DE ASISTENTES                           ");
		printf("\n\t                 -----------------------------------                      \n\n");	
		
		printf("\tCONDICIONES\n");		  
		printf("\n\tEl nombre de usuario debe:\n\n\t-Tener entre 6 y 10 caracteres entre letras, numeros y/o simbolos \n\t  del conjunto {+,-,/,*,?,¿,!,¡}\n\n\tTambien debera:\n\n\t-Comenzar con una letra minuscula\n\n\t-Tener al menos 2 letras mayusculas\n\n\t-Tener como maximo 3 numeros\n\t");
		getchar();
  
		 printf("\n\n\n");
		 				   
                _flushall();
/*uSUARIO*/		printf("\n\tIngrese su Usuario:\n");
				printf("\t--->Usuario: ");
		  		gets(reg1.userAsist);
		  						  
		  						  
				_flushall();  
/*CONTRA*/				printf("\n\n\tIngrese su Contrasena:\n");
				printf("\t--->Contrasena: ");
		  		gets(reg1.contraUserAsist);
		  

 
	   	fwrite(&reg1, sizeof(reg1), 1, arch1);
		fclose(arch1);
 
} 
void registrarAtenciones(FILE *arch,registrosVeterinarios reg)
{        
				 system("COLOR e0");
			 	 arch = fopen("Veterinarios.dat", "a+b");
				 fread(&reg, sizeof(reg), 1, arch); 	   
				 rewind(arch);
				  	   
				int buscarMat,n;
				
		  	   
				system("CLS");	   	  						     
		        printf("\n\t                    ATENCION DE VETERINARIOS                          ");
				printf("\n\t                    ------------------------                      \n\n");	
		
		
				printf("\n\tIngrese la matricula del veterinario para cargar sus dias de atencion:\n");
		   		printf("\t-----------------------------------------------------------------------");
		   		
				_flushall();   													  
				printf("\n\n\t--->Matricula: ");						   
		  		scanf("%d",&buscarMat);
		
		
		
				if(buscarMat == reg.matricula)
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
						 														   									  

						rewind(arch);														   									  
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
																				   									  
						
					
					rewind(arch);
					
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
																																																																																																							  																										  		  					 													   	   	   		 					       		     	 						   	  		  				   																							 	 		 		      
			fwrite(&reg, sizeof(reg), 1, arch);																																																																																																																																																																																																											  																																																																																																						  																										  		  					 													   	   	   		 					       		     	 						   	  		  				   																							 	 		 		      
			fclose(arch); 
			
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


void rankingAtenciones(FILE *arch,registrosVeterinarios reg)
{
	    system("CLS");
		system("COLOR 3f");
			
	    arch = fopen("Veterinarios.dat", "r");
		fread(&reg, sizeof(reg), 1, arch); 	   
		rewind(arch);
		
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

	 fclose(arch);
	
}

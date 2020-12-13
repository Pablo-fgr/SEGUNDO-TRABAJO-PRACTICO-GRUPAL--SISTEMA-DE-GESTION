#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char registroVeterinarios[50];


struct day
{
	char dayLaborable[80];
	
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
void registrarAtenciones(FILE *arch, registrosVeterinarios reg, arreglo day[7]);


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
        arreglo day[7];
  
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
		 	registrarAtenciones(arch,reg,day);
			printf("\n");	 		 
	    }    
			
	}while(opcion!= 0);
	

}
void registrarVet()
{
		 system("COLOR A0");
 	     FILE *arch;
	 	 arch = fopen("veterinarios.dat", "a+b");
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
	 	 arch1 = fopen("usuarios.dat", "a+b");
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
void registrarAtenciones(FILE *arch,registrosVeterinarios reg,arreglo day[7])
{        
		 system("COLOR e0");
	 	 arch = fopen("veterinarios.dat", "a+b");
		 fread(&reg, sizeof(reg), 1, arch); 	   
		 rewind(arch);
		  	   
		int buscarMat,n;
		  	   
		system("CLS");	   	  						     
        printf("\n\t                    ATENCION DE VETERINARIOS                          ");
		printf("\n\t                    ------------------------                      \n\n");	
		
		while(!feof(arch))
		{
			    printf("\n\tIngrese la matricula del veterinario para cargar sus dias de atencion:\n");
		   		printf("\t------------------------------------------------------------------------");
		   		
				_flushall();   													  
				printf("\n\n\t--->Matricula: ");						   
		  		scanf("%d",&buscarMat);
		
				if(buscarMat == reg.matricula)
		  		{
  			 	 		printf("\n\n\n");	 
				   		printf("\n\tIngrese la cantidad de días de atencion: ");
						scanf("%d",&reg.cantDias); 
						getchar();  
						
						_flushall();
						printf("\n\tA continuacion ingrese los DIAS: \n");							 	   		
						
						for(int i=1; i<reg.cantDias; i++)
						{
							printf("\n\tDia %d --->",i);
							scanf("%s",&day[i]);
							
									 				 	   
						}
						 														   									  
					
						 rewind(arch);														   									  
						_flushall();
						
						system("PAUSE");																										  		 													   
						printf("\n\n\tLos dias son:");
						for(int i=1; i<reg.cantDias; i++)
						{
						 	printf("\n\tDIA %d: ",i);
							printf("%s",day[i]);		 				 	   
						}	 				  
		  		}
				else
				{
		  		 	printf("\n\n\tLa matricula ingresada es incorrecta");				   		   			  	
				}  
										 	 	     		   	 			   		 		 		      
	 	}
																																																																																																							  																										  		  					 													   	   	   		 					       		     	 						   	  		  				   																							 	 		 		      
		fwrite(&reg, sizeof(reg), 1, arch);																																																																																																																																																																																																											  																																																																																																						  																										  		  					 													   	   	   		 					       		     	 						   	  		  				   																							 	 		 		      
		fclose(arch); 
}

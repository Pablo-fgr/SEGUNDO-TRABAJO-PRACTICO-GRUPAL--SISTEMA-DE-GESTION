#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>


typedef char registroVeterinarios[50];
typedef char user[10];



struct day
{
	char dias[80];
	float horaInicio[80];
	float horaFin[80];
	
};
	
	
struct registrosVeterinarios
{
 	   int  UsuarioVet;
	   char ContraUsuarioVet[50];   
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
 	   char UsuarioAsistente[10];
	   char ContraUsuarioAsistente[10];   
 	   char apynom[60];
	   	   
};

void menuprincipal();
void registrarVet();
void registrarAsist();
void registrarAtenciones(FILE *arch, registrosVeterinarios reg);
void rankingAtenciones(FILE *arch,registrosVeterinarios reg);
bool buscar_usuario(char user[10]);
bool validacion(int aux,FILE *arch,registrosVeterinarios reg);



main()
{
 	  system("COLOR 6F");	
   	  
   	  
   	  
	  menuprincipal();
   	  
 
}
void menuprincipal()
{
 	 	int opcion;
		FILE *arch;	
		FILE *arch1;
		registrosVeterinarios reg;
		
		if((arch==NULL) || (arch1==NULL))
		{
		printf("\n\n\t Archivo inexistente.....\n");
		system("PAUSE");
		exit(1);
		}
			 
        
  
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
		 system("COLOR B0");
 	     FILE *arch;
	 	 arch = fopen("Veterinarios.dat", "a+b");
		 registrosVeterinarios reg;
		 
		 int aux;

		 bool h;
		  	   
  
		
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
		
	
				
		aux=reg.matricula;
		reg.UsuarioVet = aux;
			  
		printf("\n\tSu nombre de usuario es coincidente con su matricula--->%d",reg.UsuarioVet);	
		
				  			   						  				     								
		getch();								 			   																			   																																										  			   						  				     
					  
		

	int i;

	do{
				printf("\n\n");
				printf("\n\t                 CREEE LA CONTRASENIA               ");
				printf("\n\t              -------------------------           \n");	
				
				printf("\tRequisitos\n");
				printf("\t----------\n");
		
				printf("\n\t(1) - Debe contener una letra mayuscula, una letra minuscula y un numero.\n");
				printf("\n\t(2) - Solo deben ser caracteres alfanumericos.\n");
				printf("\n\t(3) - Tener una longitud de entre 6 y 32 caracteres.\n");
				printf("\n\t(4) - No debe tener mas de tres caracteres numericos consecutivos.\n");
				printf("\n\t(5) - No debe tener 2 caracteres consecutivos que refieran a letras\n\t   alfabeticamente consecutivas.\n");
				  		
		  						  
				_flushall();  
/*CONTRA*/		printf("\n\n\tIngrese su Contrasenia:\n");
				printf("\t--->Contrasena: ");
		  		gets(reg.ContraUsuarioVet);
		  		
		  		
/*Comienza verificacion de requisitos*/		  		
			 
			 /*Declaracion de variables necesarias*/ 		
			  	char valorNumerico;
				char letraActual;
				int numero_letra1=0, numero_letra2=0;		
				int i=0,j=0,l=0;
				int mayus=0, minus=0, digitos=0;
				int BvaloresAlfanumericos=0,CaracteresConsecutivos=0,BcaracteresSeguidos=0;
			  /* ------------------------------------------------------------------------*/		
		  		
		  		
		  		l=strlen(reg.ContraUsuarioVet);
	
				if(l>=6 and l<=32){
					i++;
				}
				else{
					printf("\n\n\tLa contrasenia debe tener entre 6 y 32 caracteres.\n\t                  Reintente.\n");	
				}
				
				//se revisa los numeros consecutivos
				for(j=0;j<l;j++){  
					valorNumerico=reg.ContraUsuarioVet[j];
					
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
					if((reg.ContraUsuarioVet[j]>47 and reg.ContraUsuarioVet[j]<56) or (reg.ContraUsuarioVet[j]>54 and reg.ContraUsuarioVet[j]<91) or (reg.ContraUsuarioVet[j]>96 and reg.ContraUsuarioVet[j]<123)){
						
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
					
					letraActual=reg.ContraUsuarioVet[j];
					
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
					numero_letra1= toupper(reg.ContraUsuarioVet[j]);
					numero_letra2= toupper(reg.ContraUsuarioVet[j+1]);
					
					if(numero_letra2==numero_letra1+1 and (reg.ContraUsuarioVet[j]>64 and reg.ContraUsuarioVet[j+1]<90)){
						printf("\n\n\tLa clave no puede poseer dos letras consecutivas.\n\t                  Reintente.\n");
						j=l;
						i=0;
					}
				}
			
			    if(i==5)
				{
			    	printf("\n\n\tContrasenia registrada con exito  :)\n");
					printf("\t-----------------------------------\n");
					_flushall();
			
					
					printf("\n\n\t           ------¡Usuario creado con exito!------     \n");
			    	printf("\n\n\t                  ------Gracias------      \n");
					
					fwrite(&reg, sizeof(reg), 1, arch);
					system("pause");
					
				}
				else
				{
					
					system("pause");
					system("cls");
				}
			
					
		}while(i==5);
				
		  		
		  		
/*Termina verificacion de requisitos de usuario*/

			    	
			    	
	   	fwrite(&reg, sizeof(reg), 1, arch);
		fclose(arch);
 
}
void registrarAsist()
{        
		 system("COLOR 3F");
 	     FILE *arch1;
	 	 arch1 = fopen("Usuarios.dat", "a+b");
		 registrosUsuariosAsist reg1;
		 
		bool h;
		int i,l,a,digi=0,up=0,low=0,schar=0;
		int band=0, mayus=0, minus=0, digitos=0;

	   
		
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
																			 			   																			   																																										  			   						  				     
					  
		system("CLS\n\n");	
	 	printf("\n\t                      CREE EL NOMBRE DE USUARIO                             ");
		printf("\n\t                   -------------------------------                        \n");	
		
		printf("\tRequisitos\n");
		printf("\t----------\n");		  
		printf("\n\t(1) - El nombre de usuario debe:\n\n\t(2) - Tener entre 6 y 10 caracteres entre letras, numeros y/o simbolos \n\t      del conjunto {+,-,/,*,?,¿,!,¡}\n\n\t(4) - Comenzar con una letra minuscula\n\n\t(5) - Tener al menos 2 letras mayusculas\n\n\t(6) - Tener como maximo 3 numeros\n\t");
		
		printf("\n\n\n");
		 				   
/*uSUARIO*/		
					printf("\n\n\tIngrese el usuario: ");
					printf("\n\t---->");
			
		  		do
				{
				
					_flushall();
					gets(reg1.UsuarioAsistente);
					h = buscar_usuario(reg1.UsuarioAsistente);
					l = strlen(reg1.UsuarioAsistente);
					
					if(h == true)
					{
						printf("\n\n\t ERROR - ESTE USUARIO YA ESTA REGISTRADO. INTENTE NUEVAMENTE.\n\n");
						
					}
					
					
				}while(h == true);

		  		
/*Comienza verificacion de requisitos*/
						  		
		  		
		  		
		  	l = strlen(reg1.UsuarioAsistente);
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
					for(int j=0; reg1.UsuarioAsistente[j]!=NULL; j++)
					{
						if(reg1.UsuarioAsistente[j]>='A' && reg1.UsuarioAsistente[j]<='Z')
		
							mayus++;
		
						if(reg1.UsuarioAsistente[0]>='a' && reg1.UsuarioAsistente[0]<='z')
		
							minus = 1;
		
						if(reg1.UsuarioAsistente[j]>='0' && reg1.UsuarioAsistente[j]<='9')
		
							digitos++;
					}
				}
				if(mayus>=2 && minus==1 && digitos<=3 && l>6 && l<10)
				{
					band = 1;
					printf("\n\n\tUsuario registrado con exito :)\n");
					printf("\t-----------------------------------\n");
					fwrite(&reg1, sizeof(reg1), 1, arch1);
					
				}
					
				else{
					printf("\n\n\t              -NO CUMPLE LAS CONDICIONES- ");
					printf("\n\t                       -REINTENTE-   \n");
					printf("\n\tRequisitos\n");
					printf("\t----------\n");		  
					printf("\n\tEl nombre de usuario debe:\n\n\t-Tener entre 6 y 10 caracteres entre letras, numeros y/o simbolos \n\t  del conjunto {+,-,/,*,?,¿,!,¡}\n\n\t-Comenzar con una letra minuscula\n\n\t-Tener al menos 2 letras mayusculas\n\n\t-Tener como maximo 3 numeros\n\t");
			
					band = 0;
					
					
					printf("\n\n\n");
					printf("\n\tIngrese un usuario valido:\n\t--->");
					gets(reg1.UsuarioAsistente);
					l = strlen(reg1.UsuarioAsistente);
				}
			}

/*Termina verificacion de requisitos de usuario*/

		  		
		  		
do{
				printf("\n\n");
				printf("\n\t                 CREEE LA CONTRASENIA               ");
				printf("\n\t              -------------------------           \n");	
				
				printf("\tRequisitos\n");
				printf("\t----------\n");
		
				printf("\n\t(1) - Debe contener una letra mayuscula, una letra minuscula y un numero.\n");
				printf("\n\t(2) - Solo deben ser caracteres alfanumericos.\n");
				printf("\n\t(3) - Tener una longirud de entre 6 y 32 caracteres.\n");
				printf("\n\t(4) - No debe tener mas de tres caracteres numericos consecutivos.\n");
				printf("\n\t(5) - No debe tener 2 caracteres consecutivos que refieran a letras\n\t alfabéticamente consecutivas.\n");
				  		
		  						  
				_flushall();  
/*CONTRA*/		printf("\n\n\tIngrese su Contrasenia:\n");
				printf("\t--->Contrasenia: ");
		  		gets(reg1.ContraUsuarioAsistente);
		  		
		  		
/*Comienza verificacion de requisitos*/		  		
			 
			 /*Declaracion de variables necesarias*/ 		
			  	char valorNumerico;
				char letraActual;
				int numero_letra1=0, numero_letra2=0;		
				int i=0,j=0,l=0;
				int mayus=0, minus=0, digitos=0;
				int BvaloresAlfanumericos=0,CaracteresConsecutivos=0,BcaracteresSeguidos=0;
			  /* ------------------------------------------------------------------------*/		
		  		
		  		
		  		l=strlen(reg1.ContraUsuarioAsistente);
	
				if(l>=6 and l<=32){
					i++;
				}
				else{
					printf("\n\n\tLa contrasenia debe tener entre 6 y 32 caracteres.\n\t                  Reintente.\n");	
				}
				
				//se revisa los numeros consecutivos
				for(j=0;j<l;j++){  
					valorNumerico=reg1.ContraUsuarioAsistente[j];
					
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
					if((reg1.ContraUsuarioAsistente[j]>47 and reg1.ContraUsuarioAsistente[j]<56) or (reg1.ContraUsuarioAsistente[j]>54 and reg1.ContraUsuarioAsistente[j]<91) or (reg1.ContraUsuarioAsistente[j]>96 and reg1.ContraUsuarioAsistente[j]<123)){
						
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
					
					letraActual=reg1.ContraUsuarioAsistente[j];
					
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
					printf("\n\n\tLa contrasenia carece de letras mayusculas/minusculas o algun numero.\n\t                  Reintente.\n");
					i=0;
				}
				
				i++;
				for(j=0;j<l-1;j++)
				{
					numero_letra1= toupper(reg1.ContraUsuarioAsistente[j]);
					numero_letra2= toupper(reg1.ContraUsuarioAsistente[j+1]);
					
					if((numero_letra2 == (numero_letra1 +1)) and (reg1.ContraUsuarioAsistente[j]>64 and reg1.ContraUsuarioAsistente[j+1]<90)){
						printf("\n\n\tLa clave no puede poseer dos letras consecutivas.\n\t                  Reintente.\n");
						j=l;
						i=0;
					}
				}
			
			    if(i==5)
				{
			    	printf("\n\n\tContrasenia registrada con exito  :)\n");
					printf("\t-----------------------------------\n");
					_flushall();
			
					
					printf("\n\n\t           ------¡Usuario creado con exito!------     \n");
			    	printf("\n\n\t                  ------Gracias------      \n");
					
					fwrite(&reg1, sizeof(reg1), 1, arch1);
					system("pause");
					
				}
				else
				{
					
					system("pause");
					system("cls");
				}
			
					
		}while(i==5);
				
		  		
		  		
/*Termina verificacion de requisitos de usuario*/
 
	   	fwrite(&reg1, sizeof(reg1), 1, arch1);
		fclose(arch1);
 
} 
void registrarAtenciones(FILE *arch,registrosVeterinarios reg)
{        
				 system("COLOR e0");
			 	 arch = fopen("Veterinarios.dat", "a+b");
			 	 
			 	 FILE *arch_turnos;
	
				 arch_turnos = fopen ("Turnos.dat", "ab");
			 	 				  				  			 	 
				 fread(&reg, sizeof(reg), 1, arch); 	   
				 rewind(arch);
				 
				 int i;
				  	   
				int buscarMat,op;
				
		  	   
				system("CLS");	   	  						     
		        printf("\n\t                    ATENCION DE VETERINARIOS                          ");
				printf("\n\t                    ------------------------                      \n\n");	
		
		
		do
		{
			
				printf("\n\tIngrese la matricula del veterinario para ver los dias de atencion:\n");
		   		printf("\t-----------------------------------------------------------------------");
		   		
				_flushall();   													  
				printf("\n\n\t--->Matricula: ");						   
		  		scanf("%d",&buscarMat);
		  		
		  						  		  		
		
				
				if(buscarMat = reg.matricula)
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
					
					fwrite(&reg, sizeof(reg), 1, arch);
					
					printf("\n\n\tDesea cargar dias de atencion de otro veterinario?\n");
					printf("\n\t(1)---> SI\n\t(2)---> NO");
					printf("\n\tIngrese su opcion: ");
					scanf("%d",&op);
					printf("\n\n\n");
					
					
					if(op!=1)
					{
						printf("\n\n\tGracias");
						exit(1);
					}
					fwrite(&reg, sizeof(reg), 1, arch);
					
				}
				
				else
				{
		  		 	printf("\n\n\tLa matricula ingresada es incorrecta\n\t");				   		   			  	
				}  
		
	
		}while(!feof(arch));
		   
				
				
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
		bool h;
		int aux;
		
	

		printf("\n\t            Bienvenidos al ranking de veterinarios!\n\t         El nuevo incentivo para nuestros veterinarios");
		printf("\n\t-----------------------------------------------------------------                      \n\n");
	
																		   
		printf("\n\tPara la medicion del ranking del veterinario con mayor atencion \n\ten el periodo debera ingresar la matricula de todos los \n\tveterinarios que trabajaron en el mes.\n\n");
		
		printf("\n\tPrimer paso");
		printf("\n\t-----------\n\n");
		
		printf("\n\tIngrese la cantidad de veterinarios que trabajaron en el mes:");
		scanf("%d",&registro.vetEnMes);
		printf("\n\n");
		
		_flushall();
		fread(&reg, sizeof(reg), 1, arch);
		
		for(int i=1 ; i<=registro.vetEnMes ; i++)
		{
			printf("\t------------------------------------------------------------");			
			printf("\n\tIngrese la matricula del veterinario %d: ",i);
			scanf("%d",&registro.ingresoMatriculas[i].numMatriculas[i]);
			
			aux=registro.ingresoMatriculas[i].numMatriculas[i];
			 
				do
				{
					h= validacion(aux,arch,reg);
					if(h == true)
					{
						printf("\n\n\t\t -MATRICULA RECONOCIDA- \n\n");
						getch();
						
						
						printf("\tIngrese la cantidad de turnos atendidos del veterinario %d: ",i);
						scanf("%d",&registro.ingresoMatriculas[i].cantidadTurnos[i]);
						printf("\t------------------------------------------------------------");
						printf("\n\n");
						
					}else
					{
						printf("\n\n\t\t -MATRICULA NO RECONOCIDA- \n\n");
						printf("\n\n\tSaliendo...");
						getch();
						exit(1);
					}
					
					
				}while(h == false);
			
			
			
		
			
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
		printf("\n\n\t*|GANADOR DEL BONO MENSUAL: DOCTOR MATRICULADO CON MATRICULA %d|*\n", ganadorRanking);		
		printf("\n\t******************************************************************\n\t");
					


		fclose(arch);
	    system("pause");  


																																																																																																																																																																																																												  																																																																																																						  																										  		  					 													   	   	   		 					       		     	 						   	  		  				   																							 	 		 		      
		 
	
}
bool buscar_usuario(char user[10])
{
	FILE *arch1;
	arch1 = fopen("Usuarios.dat", "rb");
	
	registrosUsuariosAsist reg1;
	
	
	rewind(arch1);
	
	fread(&reg1, sizeof(reg1), 1, arch1);
	
	while(!feof(arch1))
	{
		
		if(strcmp(reg1.UsuarioAsistente, user)==0)
		{
			fclose(arch1);
			return true;
		}
		fread(&reg1, sizeof(reg1), 1, arch1);
	}
	
	
	fclose(arch1);
	return false;
}

bool validacion(int aux,FILE *arch,registrosVeterinarios reg)
{

	vets registro;
	
	arch = fopen("Veterinarios.dat", "rb");
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
	
	while(!feof(arch))
	{
		
		if(aux == reg.matricula)
		{
			fclose(arch);
			return true;
		}
		fread(&reg, sizeof(reg), 1, arch);
	}
	fclose(arch);
	return false;
}



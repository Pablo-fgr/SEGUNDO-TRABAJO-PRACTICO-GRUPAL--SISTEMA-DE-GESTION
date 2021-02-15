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

void CargaContrasenia(char Nombre[10],int n);

void IniciarSesion(int &n);

void MenuAdministrador(int n);

void MenuAsistente(int n);

void IniciarSesionAsistente(usuarios &PP,int &i);

void RegistrarMascota(usuarios PP,mascota &Oscar,int i);

void RegistrarTurno(usuarios PP,mascota Oscar,int i);

void ListarAtencion(usuarios PP,int i);

void AtencionesDeterminadoMes(int n);

void TopVeterinarios(int n);

void MenuVeterinario(int n);

void IniciarSeccion(veterinarios vet,int &b);

void VisualizarListaDeEspera(turnos turn,veterinarios vet,int &k);

void CargarInforme(turnos turn,veterinarios vet,int k);

/*------------------------------------------Funcion principal--------------------------------------------*/

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
		printf("\t                       ------------------>                       \n\n\n\n\t");
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
     		case(1):MenuVeterinario(n);break;
     		
			case(2):MenuAsistente(n);break;
     	
		 	case(3):MenuAdministrador(n);break;
     		
			case(4):printf("\n\n\n\n\n\t************************************************************\n");
	    				  printf("\t**                                                        **\n");
	    				  printf("\t**                     SALIENDO ...                       **\n");
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
	
	system("COLOR A0");
   
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
     								
     								CargaContrasenia(Nombre,n); //Vamos a crear la contraseña que acompaña al usuario
     								
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


/*------------------------------Funcion para cargar la contraseña del usuario---------------------------*/

void CargaContrasenia(char Nombre[10],int n)
{
	
	system("COLOR E0");
	int i=0,c=0,LetrasMayuscula=0,LetraMinuscula=0,Numero=0,BValoresalfanumericos=0,Longitud=0,CaracteresNumericosConsecutivos=0,BcaracteresSeguidos=0;
	
	char Contrasenias[32],ApeNom[60];
	
	char ValorNumerico;
	
	char LetraActual;
	
	int Numero_Letra1=0,Numero_Letra2=0;
	
	
	do
	{
		///////////////////Volvemos ceros a todas las banderas y contadores para evitar problemas/////////////////////////////////////////////////////
		i=0;c=0;LetrasMayuscula=0;LetraMinuscula=0;Numero=0;BValoresalfanumericos=0;Longitud=0;CaracteresNumericosConsecutivos=0;BcaracteresSeguidos=0;
		Numero_Letra1=0,Numero_Letra2=0;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		_flushall();
		printf("\n\n");
		printf("\n\t            CREEE LA CONTRASENIA DE %s \n",Nombre);
		printf("\n\t          --------------------------------------           \n");	
	
	
		printf("\tRequisitos\n");
		printf("\t----------\n");
		
		printf("\n\t(1) - Debe contener una letra mayuscula, una letra minuscula y un numero.\n");
		printf("\n\t(2) - Solo deben ser caracteres alfanumericos.\n");
		printf("\n\t(3) - Tener una longitud de entre 6 y 32 caracteres.\n");
		printf("\n\t(4) - No debe tener mas de tres caracteres numericos consecutivos.\n");
		printf("\n\t(5) - No debe tener 2 caracteres consecutivos que refieran a letras\n\t   alfabeticamente consecutivas.\n");
				  		
		  						  
		_flushall();  
		printf("\n\n\tIngrese su Contrasenia:\n");
		printf("\t--->Contrasena: ");
		gets(Contrasenias);
	
		//////////////////////////////////////////////////////////////////////
		Longitud=strlen(Contrasenias);  //La longitud de la contraseña
		if(Longitud>=6 and Longitud<=32)
		{
			i++;
		
		}else{
			
			printf("\n\n\tLa contrasenia debe tener entre 6 y 32 caracteres.\n\t                  Reintente.\n");	
				
		}
		/////////////////////////////////////////////////////////////////////
	
	
		///////////////////////////////////////////////////////////
		for(c=0;c<Longitud;c++){    //Vemos si hay tres numeros consecutivos
		
			ValorNumerico=Contrasenias[c];
		
			if(ValorNumerico>47 and ValorNumerico<58)
			{
				CaracteresNumericosConsecutivos++;
			
			
			}else{
				CaracteresNumericosConsecutivos=0;
			
			}
			if(CaracteresNumericosConsecutivos>3)
			{
				c=Longitud;
				i=0;
				printf("\n\n\tLa contrasenia ingresada tiene 3 numeros consecutivos.\n\t                   Reintente.\n");
					
			
			}
		
		}
		
		if(CaracteresNumericosConsecutivos<=3){
			i++;
		}
		/////////////////////////////////////////////////////////////////////////////////////
		
		////////////////////////////////////////////////////////////////////////////////////
		for(c=0;c<Longitud;c++){//Verificamos si todos los valores son alfanumericos
		
			if((Contrasenias[c]>47 and Contrasenias[c]<58)  or (Contrasenias[c]>64 and Contrasenias[c]<91) or (Contrasenias[c]>96 and Contrasenias[c]<123)){
			
			
			}
			else{
				printf("\n\n\tLa clave posee un caracter que no es alfanumerico.\n\t                  Reintente.\n");
				c=Longitud;
				BValoresalfanumericos=1;
			}
		
		}
		
		if(BValoresalfanumericos==0){
			i++;
		}
		//////////////////////////////////////////////////////////////////////////////////////////
	
	
		///////////////////////////////////////////////////////////////////////////////////
		for(c=0;c<Longitud;c++){////////////////vemos si hay una letra mayuscula, una minuscula y un numero
		
			LetraActual=Contrasenias[c];
		
			if(LetraActual==toupper(LetraActual)){
			
				LetrasMayuscula++;
			}
			if(LetraActual==tolower(LetraActual)){
				LetraMinuscula++;
			}
			if(LetraActual>47 and LetraActual<58){
				Numero++;
			}
		
		}
	
		if(Numero>0 and LetraMinuscula>0 and LetrasMayuscula>0){
			i++;
		}
		else{
			printf("\n\n\tLa contrasenia carece de letras mayusculas/minusculas o algun numero.\n\t                  Reintente.\n");
			i=0;
		}
		////////////////////////////////////////////////////////////////////////////////////
	
		//////////////////////////////////////////////////////////////////////////////////////
		i++;
		for(c=0;c<Longitud-1;c++){
		
			Numero_Letra1=toupper(Contrasenias[c]);
		
	   		Numero_Letra2=toupper(Contrasenias[c+1]);
		
		
		
			if(Numero_Letra2==Numero_Letra1+1 and (Contrasenias[c]>64 and Contrasenias[c+1]<90)){
				printf("\n\n\tLa clave no puede poseer dos letras consecutivas.\n\t                  Reintente.\n");			
				i=0;
				c=Longitud;
			}
		}
	
		////////////////////////////////////////////////////////////////////////////////////////
		if(i==5){
			system("cls");
		}else{
		
	
			system("pause");
			system("cls");
		}
	
	}while(i!=5);
  
    	printf("\n\n\tContrasenia registrada con exito  \n");
		printf("\t-----------------------------------\n");
	
		printf("\n\n\tIndique su nombre y apellido---> ");
		_flushall();
   	    gets(ApeNom);
  
   		printf("\n\n\t           ------¡Usuario creado con exito!------     \n");
		printf("\n\n\t                  ------Gracias------      \n");
		
		system("pause\n\t");
		system("cls");
   

   	FILE *p;
   
   
  	 switch(n)
	{
   	
  	 	case(0)://Cargamos al administrador o a un asistente
   				usuarios pp;
   
  			 	p=fopen("Usuarios.dat","a+b");
   	
				strcpy(pp.usuario,Nombre);
   	
				strcpy(pp.contrasena,Contrasenias);
   	
				strcpy(pp.ApellidoNombre,ApeNom);
   
  			 	fwrite(&pp,sizeof(usuarios),1,p);
  	 			fclose(p);
   
   				system("CLS");
   
				system("CLS");
   				printf("\n\t              B I E N V E N I D O  %s\n",ApeNom);
				printf("\n\t           ---------------------------------------------    \n\n");
   
  		break;
   
   		case(1): //cargamos un veterinario con sus datos
   		veterinarios v;
   		
   	
   				printf("\n\tDatos del veterinario a registrar\n");
   				printf("\t--------------------------------------");
   						
				printf("\n\n\t--->Matricula profesional: ");
				scanf("%d",&v.Matricula);									  
   	
   				printf("\n\n\t--->Numero de Documento: ");
   				scanf("%d",&v.Dni);
   	
   				printf("\n\n\t--->Telefono: ");
				_flushall();
				gets(v.Telefono);
				
				printf("\n\n\t       -Veterinario cargado correctamente!- \n\n");
				system("pause");
   	
   				strcpy(v.usuario,Nombre);
   				strcpy(v.contrasena,Contrasenias);
  	 			strcpy(v.ApellidoNombre,ApeNom);
   	
   				p=fopen("Veterinarios.dat","a+b");
   
   
   				fwrite(&v,sizeof(veterinarios),1,p);
   				fclose(p);
  				
   		break;
   
   	
   	
   }
   
   system("cls");
   

   
}

/*-----------------------------------------------Funcion para inicio de sesion del usuario-----------------------------------*/


void IniciarSesion(int &n)
{ 
	system("COLOR 3F");
	do{
		printf("\n\n");
		printf("\n\t**************¡Bienvenido al menu principal!*********************");
		printf("\n\t**                                                             **");    
		printf("\n\t**                ¿Que cargo posee?                            **");
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


/*-------------------------------Funcion del Menu del administrador---------------------------------------*/

void MenuAdministrador(int n)
{
	system("COLOR F5");
	n=0;
	
	char USUARIO[10],CONTRASENIA[32];
	
	usuarios P;
	
	FILE *p;
	
	p=fopen("Usuarios.dat","rb");
	
	fread(&P,sizeof(usuarios),1,p);
	
	while(n==0)
	{
		
		printf("\n");
		printf("\n\t--------------------- MODULO ADMINISTRACION -------------------------");
		printf("\n\t---------------------------------------------------------------------\n\n");				
		
		
		_flushall();
		printf("\n\tUsuario---> ");
		gets(USUARIO);
			
	    _flushall();
		printf("\n\n\tContrasenia---> ");
		gets(CONTRASENIA);
		
		if(strcmp(USUARIO,"0")==0 and strcmp(CONTRASENIA,"0")==0){
			system("cls");
			return;
		}
		
		if(strcmp(P.usuario,USUARIO)==0 and strcmp(P.contrasena,CONTRASENIA)==0){
			
			system("COLOR b0");
			printf("\n\n\n\t---------------------    BIENVENIDO   ----------------------------\n\n");
			n=1;
             
	         
		}
		else{
			printf("\n\n\n\tUsuario o clave Incorrecta, verifique y reintente.\n\t");
			n=0;
			system("pause");
			system("cls");
		}
	}

	fclose(p);
	do
	{
	

		do
		{
			system("cls");
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
			printf("\n\t** (5)  -> VOLVER AL MENU PRINCIPAL                                **");
			printf("\n\t**                                                                 **");																			   
			printf("\n\t*********************************************************************");
			printf("\n\n\tIngrese su opcion:");
			scanf("%d",&n);
			system("cls");
		
		}while(n>5 or n<1);
	
		switch(n)
		{
			case(1):CargaUsuarios(p,n);break;
			
			case(2):n=0;CargaUsuarios(p,n);break;
			
			case(3):AtencionesDeterminadoMes(n);break;
			
			case(4):TopVeterinarios(n);break;
		}
	
	
	
    }while(n!=5);
	
	
	
}


/*---------------------Funcion del menu del asistente-------------------*/

void MenuAsistente(int n)
{
	system("COLOR E2");
	system("cls");
	
	mascota Oscar;
	
	usuarios PP;

	int i=0;
	
	do
	{
	
		do
		{
			system("cls");
			printf("\n\t*********************** MODULO ASISTENTE ****************************");    
			printf("\n\t**                                                                 **");
			printf("\n\t** (1)  -> INICIAR SESION                                          **");
			printf("\n\t**                                                                 **");
			printf("\n\t** (2)  -> REGISTRAR MASCOTA                                       **");
			printf("\n\t**                                                                 **");
			printf("\n\t** (3)  -> REGISTRAR TURNO                                         **");
			printf("\n\t**                                                                 **");
			printf("\n\t** (4)  -> LISTADO DE ATENCIONES POR VETERINARIO Y FECHA           **");
			printf("\n\t**                                                                 **");
			printf("\n\t**                                                                 **");
			printf("\n\t** (5)  -> VOLVER AL MENU PRINCIPAL                                **");
			printf("\n\t**                                                                 **");																			   
			printf("\n\t*********************************************************************");
			printf("\n\n\tIngrese su opcion:");
			scanf("%d",&n);
			system("cls");
			
		}while(n<1 or n>5);
	
		switch(n)
		{
			case(1):IniciarSesionAsistente(PP,i);break;
		
			case(2):RegistrarMascota(PP,Oscar,i);break;
		
			case(3):RegistrarTurno(PP,Oscar,i);break;
		
			case(4):ListarAtencion(PP,i);break;
		
		}
	
	
	
	}while(n!=5);
	
	
}


/*------------------------Funcion para el inicio de sesion del asistente-----------------------*/

void IniciarSesionAsistente(usuarios &PP,int &i)
{
	system("COLOR 7");
	FILE *p;
	
	
	char NombreAUX[10],Contrasenia[32];
	
	
	//EMPEZAMOS CON LA VERIFICACIÓN//
	p=fopen("Usuarios.dat","rb");
	
	while(!feof(p))
	{
		i=i+1;
		fread(&PP,sizeof(usuarios),1,p);
		
	}

	
	fclose(p);
    
	if(i==2)
	{
    	printf("\n\n\n\n\n\n\n\n\t      Error - no hay asistentes registrados en el sistema\n\n\n\t    ");
    	system("pause");system("cls");
    	return;
	}
	
	 i=0;
	 
    do
	{
      
	  printf("\n");
	  printf("\n\t--------------------- Inicio de sesion asistentes -------------------");
	  printf("\n\t---------------------------------------------------------------------\n\n");				
	  printf("\n\tIntroduzca el usuario del asistente--->");
	  _flushall();	
      gets(NombreAUX);
    	
    	if(strcmp(NombreAUX,"0")==0)
		{
    		system("cls");i=0;
    		return;
		}
    	
    	p=fopen("Usuarios.dat","rb");
    	fread(&PP,sizeof(usuarios),1,p);//lo hago dos veces pues el primer lugar queda reservado para el administrador
    	fread(&PP,sizeof(usuarios),1,p);
    	
    	
    	while(!feof(p) and i!=1)
		{
    		if(strcmp(PP.usuario,NombreAUX)==0)
			{
    			
    			i=1;  //Buscamos si el nombrea aparece
			}else{
			
				fread(&PP,sizeof(usuarios),1,p);}
		}
		
		fclose(p);
		
		system("cls");
		
    	if(i==1)
		{
    		do
			{
				
    			printf("\n\tBienvenido, introduce tu contraseña!\n");
    			printf("\n\n\t--->Contraseña: ");
    			_flushall();
    			gets(Contrasenia);
    			
    			if(strcmp("0",Contrasenia)==0){         //verificacion para ver si la contraseña es la correcta
    				system("cls");i=0;
    				return;
				}
    		
    			if(strcmp(Contrasenia,PP.contrasena)==0){
    				printf("\n\n\tIniciaste sesion correctamente-\n\n\t");
    				i=2;
				}
				else{
					printf("\n\tContraseña incorrecta\n\t");i=0;
				}
				
    			system("pause");
    			
				system("cls");
    		
			}while(i==1);
		}
    	else{
    		
			printf("\n\tError - usuario no encontrado\n\tReintenta.\n\n\t");
    		
			system("pause");
    		
			system("cls");
		}
    	
	}while(i!=2);
	
	////////////////////////////////
}


/*------------------------------------Funcion para el registro de mascotas------------------------------------*/


void RegistrarMascota(usuarios PP,mascota &Oscar,int i)
{
	system("COLOR 71");
	int n=0;
	
	if(i==0)
	{
		printf("\n\n\n\n\n\t---------------------------------------------------------------------\n\n");
		printf("\n\t        Para utilizar esta opcion primero debes iniciar sesion.\n\t");
		printf("\n\t---------------------------------------------------------------------\n\n");
		system("pause");system("cls");return;
	}
	else{
		printf("\n\t--------------------- Informacion de mascotas --------------------------");
		printf("\n\t---------------------------------------------------------------------\n\n");	
	
	}
	
	do
	{
		do{ //Verificamos si el usuario desea cargar datos
		
			printf("\n\n\tDesea cargar datos?(1) SI (2) NO\n\t");
			printf("---> ");
			scanf("%d",&n);
		if(n==2){
			system("cls");
			return;
		}
		
		}while(n!=1);
	
		n=0;
	
		system("cls");
	
		//CARGA DE LOS DATOS//
		printf("\n\tIngrese el apellido y nombre del dueño de la mascota");
	
		printf("\n\t=====>");
	
		_flushall();gets(Oscar.ApellidoNombre);
	
		printf("\n\tIngrese el DNI del dueño");
		printf("\n\t=====>");
		scanf("%d",&Oscar.DNI_duenio);
	
		_flushall();
		printf("\n\tTelefono");
		printf("\n\t=====>");
		gets(Oscar.Telefono);
	
		printf("\n\tDomicilio");
		printf("\n\t=====>");
		_flushall();gets(Oscar.Domicilio);

	
		printf("\n\tLocalidad");
		printf("\n\t=====>");
		_flushall();gets(Oscar.Localidad);
	
		printf("\n\tFecha de nacimiento de la mascota\n");
		do
		{

			printf("\n\tDia---> ");
	
			scanf("%d",&Oscar.FechaNacimiento.Dia);
		
			if(Oscar.FechaNacimiento.Dia < 1 || Oscar.FechaNacimiento.Dia > 31)
			{
				
				printf("\n\n\t---> [Por favor, reingrese el dia, [valor entre 1 y 31] gracias.]");
		
			}
		
		}while(Oscar.FechaNacimiento.Dia < 1 || Oscar.FechaNacimiento.Dia > 31);
		
		do
		{
			printf("\n\tMes---> ");
	
			scanf("%d",&Oscar.FechaNacimiento.Mes);
		
			if(Oscar.FechaNacimiento.Mes < 1 || Oscar.FechaNacimiento.Mes > 12)
			{
			
				printf("\n\n\t---> [Por favor, reingrese el mes, [valor entre 1 y 12] gracias.]");
			
			}
	
		}while(Oscar.FechaNacimiento.Mes < 1 || Oscar.FechaNacimiento.Mes > 12);
		
		
		printf("\n\tAnio---> ");scanf("%d",&Oscar.FechaNacimiento.Anio);
	
		printf("\n\n\tPeso de la mascota (KG)");
		printf("\n\t=====>");
		scanf("%f",&Oscar.Peso);
	

		//FIN DE CARGA DE DATOS//
	
		//VERIFICAMOS SI LOS DATOS SON CORRECTOS//
		do
		{
			system("cls");
			printf("\n\n");
			printf("\t********************************************************\n");
			printf("\t**                 MASCOTA REGISTRADA!!               **\n");
			printf("\t********************************************************\n");
	
	
	
			printf("\n\tApellido y nombre del dueño---> %s",Oscar.ApellidoNombre);
			printf("\n\tDomicilio---> %s",Oscar.Domicilio);
			printf("\n\tLocalidad---> %s",Oscar.Localidad);
			printf("\n\tDNI del dueño---> %d",Oscar.DNI_duenio);
			printf("\n\tTelefono--->%s",Oscar.Telefono);
			printf("\n\tFecha de nacimiento mascota--->%d/%d/%d",Oscar.FechaNacimiento.Dia,Oscar.FechaNacimiento.Mes,Oscar.FechaNacimiento.Anio);
			printf("\n\tPeso---> %.2f",Oscar.Peso);
			printf("\n");
			printf("\n\n\tLos datos son correctos? (1) SI (2) NO ---> ");
			scanf("%d",&n);
	
		}while(n!=1 and n!=2);
		
		system("cls");
	
	
	}while(n!=1);

	FILE *p;
	
	p=fopen("Mascotas.dat","a+b");
	
	fwrite(&Oscar,sizeof(mascota),1,p);
	
	fclose(p);


	printf("\n\n\n\n\n\t---------------------------------------------------------------------\n\n");
	printf("\n\t    Datos cargados existosamente... volviendo al menú de asistente.\n\t");
	printf("\n\t---------------------------------------------------------------------\n\n");
	
	
	system("pause");system("cls");
}


/*---------------------------------------------Funcion para el registro de los turnos--------------------------------------*/


void RegistrarTurno(usuarios PP,mascota Oscar,int i)
{
	system("COLOR F0");
   FILE *p;
   
   int n=0,DNI=0,N=0;
  
   mascota PET;
  
   turnos turn;
   //vemos si el usuario inicio sesion
   	printf("\n\t                       REGISTRO DE TURNOS                           ");
	printf("\n\t                      --------------------                      \n\n");
  
   if(i==0)
   {
   		printf("\n\n\n\n\n\t---------------------------------------------------------------------\n\n");
		printf("\n\t        Para utilizar esta opcion primero debes iniciar sesion.\n\t");
		printf("\n\t---------------------------------------------------------------------\n\n");
   		system("pause");system("cls");return;
   }
	else{
		printf("\n\tBIENVENIDO %s.\n\n",PP.ApellidoNombre);
		printf("\n\t--------------------------------------------\n\n");
		system("pause");system("cls");
	}
	
	p=fopen("Mascotas.dat","rb");
	
	//vemos si la lista de mascota esta vacia//
	if(p==NULL)
	{
		printf("\n\tLa lista de mascotas esta vacia, debe ser cargada por un asistente.\n");
		system("pause");system("cls");return;
	}
	///////////////////////////////////////////
	fclose(p);
	
	do
	{
		do
		{
			
			printf("\n\tDesea cargar un turno?(1) SI (2) NO.\n");
			printf("\t--->");
			scanf("%d",&n);
			N=0;
		}while(n!=1 and n!=2);
		
		if(n==1)
		{
		 	printf("\n\tIngrese los datos correspondientes para el turno a registrar :\n");
    
   			printf("\t----------------------------------------------------------------");
			
			printf("\n\n\tDNI del dueño--->");
			
			scanf("%d",&DNI);
		
			p=fopen("Mascotas.dat","rb");
			
			fread(&PET,sizeof(mascota),1,p);
		
			while(!feof(p) and N==0){ //Verificamos si el dni del dueño esta en el sistema
			
			
				if(DNI==PET.DNI_duenio)
				{
					N=1;
					turn.Dni_Dueno=DNI;
				}
				else{
					fread(&PET,sizeof(mascota),1,p);
				}
			
			}
			fclose(p);
		
		
		
		
			if(N==1)
			{
				printf("\n\t--->Mascota encontrada en el archivo!\n\n\t¿Cuando desea que sea su turno?\n");
			
				do
				{
	
					printf("\n\tDia---> ");
	
					scanf("%d",&turn.fecha.Dia);
		
					if(turn.fecha.Dia < 1 || turn.fecha.Dia > 31)
					{
				
						printf("\n\n\t---> [Por favor, reingrese el dia, [valor entre 1 y 31] gracias.]");
		
					}
		
				}while(turn.fecha.Dia < 1 || turn.fecha.Dia > 31);
			
			
				do
				{
	
					printf("\n\tMes---> ");
	
					scanf("%d",&turn.fecha.Mes);
		
					if(turn.fecha.Mes < 1 || turn.fecha.Mes > 12)
					{
			
						printf("\n\n\t---> [Por favor, reingrese el mes, [valor entre 1 y 12] gracias.]");
			
					}
	
				}while(turn.fecha.Mes < 1 || turn.fecha.Mes > 12);
		
				printf("\n\tAño---> ");scanf("%d",&turn.fecha.Anio);
			
				system("cls");
				
				turn.Matricula=0;
			
				strcpy(turn.DetalleDeAtencion,"\n\tNada aun.");
			
			
				printf("\n\n\t************************************************************\n");
	    		printf("\t**                                                        **\n");
	    		printf("\t**       SE HA REGISTRADO EL TURNO EXITOSAMENTE!!         **\n");
	    		printf("\t**                                                        **\n");
	    		printf("\t************************************************************\n\n");
		
			}else{
					printf("\n\n\t    ¡¡Dueño de la mascota no encontrado!!\n\t    Verifique su DNI porfavor.\n\n");
					system("pause");system("cls");
				}
		
				p=fopen("Turnos.dat","a+b");
				fwrite(&turn,sizeof(turnos),1,p);
				fclose(p);	
		}
		
	}while(n!=2);
	
}

/*----------------------------Funcion para el listado de las atenciones------------------------*/

void ListarAtencion(usuarios PP,int i)
{
	system("COLOR d0");
	FILE *p,*pp;
	
	turnos turn;
	veterinarios vet;
	
	p=fopen("Veterinarios.dat","rb");

	pp=fopen("TurnosAtendidos.dat","rb");
	
	if(p==NULL or pp==NULL)
	{
		printf("\n\t---> ERROR primero debe cargar veterinarios o turnos atendidos\n");
		system("pause");system("cls");
	}
	
	
	
	
	if(i==0){
		printf("\n\n\n\n\n\t---------------------------------------------------------------------\n\n");
		printf("\n\t        Para utilizar esta opcion primero debes iniciar sesion.\n\t");
		printf("\n\t---------------------------------------------------------------------\n\n");
   		
		system("pause");system("cls");return;
	}
	
		printf("\n\t                                *** ATENCIONES ***                                    "); 
	
	
	
	fread(&vet, sizeof(veterinarios), 1, p);
	while(!feof(p))
	{
		fread(&turn, sizeof(turnos), 1, pp);
		printf("\n\t---> Veterinario %s ",vet.ApellidoNombre);
		while(!feof(pp))
		{
			printf("\n\n\t\tDia---> %d",turn.fecha.Dia);
			printf("\n\n\t\tMes---> %d",turn.fecha.Mes);
			printf("\n\n\t\tAño---> %d",turn.fecha.Anio);
			printf("\n\n\t-------------------------------------------------------------------------------------------------------------\n");
			
			fread(&turn, sizeof(turnos), 1, pp);
			
		}
		fread(&vet, sizeof(veterinarios), 1, p);
	}
	
	
	
	fclose(p);
	system("pause");
}


/*----------------------------------Funcion para las atenciones de un mes determinado-------------------------------------*/

void AtencionesDeterminadoMes(int n)
{
	system("COLOR B0");
	n=0;int i=0;
	
	FILE *p,*pp;
	
	veterinarios vet;
	
	turnos turn;
	
	
	pp=fopen("Veterinarios.dat","rb");
	p=fopen("TurnosAtendidos.dat","rb");
	
	if(pp==NULL or p==NULL)
	{
		printf("\n\n\t---> El archivo de los veterinarios o el de los turnos atendidos esta vacio, por favor carguelos y reintente\n");
		system("pause");system("cls");fclose(p);fclose(pp);return;
	}
	
	
	
	do
	{
		printf("\n\t**************BUSQUEDA DE ATENCIONES********************"); 
		printf("\n\t¿Que mes desea analizar las atenciones? : ");
		scanf("%d",&n);
		system("cls");
	
    }while(n<1 and n>12);
	

	pp=fopen("Veterinarios.dat","rb");
	p=fopen("TurnosAtendidos.dat","rb");
	
	while(!feof(p))
	{
	
		
		fread(&vet,sizeof(veterinarios),1,p);
		pp=fopen("Veterinarios.dat","rb");
		while(!feof(pp))
		{
			fread(&turn,sizeof(turnos),1,pp);
			
			if(turn.fecha.Mes==n and turn.Matricula==vet.Matricula){
				i++;
			}
			if(i>0){
				printf("\n\n\t||El veterinario %s atendio %d mascotas el mes %d\n",vet.ApellidoNombre,i,turn.fecha.Mes);
				
			}
			i=0;
		}
		fclose(pp);
	}
	
	printf("\n\n\t************************************************************\n");
	    printf("\t**                                                        **\n");
	    printf("\t**                  CARGANDO...                           **\n");
	    printf("\t**                                                        **\n");
	    printf("\t************************************************************\n\n");
	fclose(p);
	system("pause");
	system("cls");
}

/*----------------------------Funcion para el top de atenciones de los veterinarios------------------*/
struct matriculas
{
	int numMatriculas;
	int cantidadTurnos;
};

struct vets
{
	int vetEnMes;
	matriculas ingresoMatriculas; 	
};


void TopVeterinarios(int n)
{
	system("COLOR F5");
	n=0;
	
	TOP top,top2,top3;	

	FILE *p;

	turnos turn;

	veterinarios vete;
	vets registro;
		
		int mayor=0;
		int ganadorRanking;
		int bandera;
	
	p=fopen("Veterinarios.dat","rb");
	
	if(p==NULL)
	{																						
	printf("\n\n\n\tError, para utilizar esta opcion deben estar cargador los archivos de\n\t'Turnos' y 'veterinarios'."); 
	system("pause");system("cls");return;
	}
	
	

	
	while(!feof(p))
	{
	
		printf("\n\t            Bienvenidos al ranking de veterinarios!\n\t         El nuevo incentivo para nuestros veterinarios");
		printf("\n\t-----------------------------------------------------------------                      \n\n");
	
																		   
		printf("\n\tPara la medicion del ranking del veterinario con mayor atencion \n\ten el periodo debera ingresar la matricula de todos los \n\tveterinarios que trabajaron en el mes.\n\n");
		
		printf("\n\tPrimer paso");
		printf("\n\t-----------\n\n");
		
		printf("\n\t---> Ingrese la cantidad de veterinarios que trabajaron en el mes:");
		scanf("%d",&registro.vetEnMes);
		printf("\n\n");
		
	
		
		for(int i=1 ; i<=registro.vetEnMes ; i++)
		{
			printf("\t------------------------------------------------------------");			
			printf("\n\tIngrese la matricula del veterinario: ");
			scanf("%d",&registro.ingresoMatriculas.numMatriculas);
			
			int auxiliar;
			auxiliar = registro.ingresoMatriculas.numMatriculas;
			 	
			 	
			 	
			 	do
			 	{	rewind(p);
			 		
						if(auxiliar=vete.Matricula)
						{
							printf("\n\n\t\t     -MATRICULA RECONOCIDA- \n\n");
							getch();
							
							
							printf("\tIngrese la cantidad de turnos atendidos del veterinario n°%d ->",i);
							scanf("%d",&registro.ingresoMatriculas.cantidadTurnos);
							printf("\t----------------------------------------------------------------\n\n");
							printf("\n\n");
							bandera=1;
							
							
						}else
						{
							printf("\n\n\t\t     -MATRICULA NO RECONOCIDA- \n\n");
							printf("\n\n\tReintente...\n\n\t");
							bandera=1;
							getch();
							
							
						}
					
				}while(bandera!=1);
			
		}
	
		
		while(!feof(p))
		{
		
			if(bandera==1)
			{
				printf("\n\n\tPor favor espere un momento...\n\t");
				getchar();
			
				for(int i=1 ; i<=registro.vetEnMes ; i++)
				{	
					if(registro.ingresoMatriculas.cantidadTurnos > mayor)
					{
						mayor = registro.ingresoMatriculas.cantidadTurnos;
						ganadorRanking = registro.ingresoMatriculas.numMatriculas;
		
					}
				}
			
	
				printf("\n\n\t--->El veterinario con mayor ranking de atenciones es el\n\tque posee la matricula numero: %d",ganadorRanking);
				printf("\n");
		
				
				printf("\n\n\n\n");
				
				printf("\n\t******************************************************************");    
				printf("\n\n\t*|GANADOR DEL BONO MENSUAL: DOCTOR MATRICULADO CON MATRICULA %d|*\n", ganadorRanking,vete.ApellidoNombre);		
				printf("\n\t******************************************************************\n\t");
				system("pause");
				exit(1);
				
			}
					
		}
	    system("pause");  


	}

	fclose(p);



	/*while(!feof(p))
	{
		
		fread(&vet,sizeof(veterinarios),1,p);
		
		
		while(!feof(pp))
		{
			fread(&turn,sizeof(turnos),1,pp);
			
			if(turn.Matricula==vet.Matricula)
			{
				n++;
			}
			
		}
		top.N=n;
		n=0;
		strcpy(top.ApellidoNomb,vet.ApellidoNombre);
		fwrite(&top,sizeof(TOP),1,ppp);
		
	}
	
	
	do{
	
	
		n=0;
	
	
		while(!feof(ppp))
		{
		
			fread(&top,sizeof(TOP),1,ppp);
			fread(&top2,sizeof(TOP),1,ppp);
		
			if(top.N<top2.N)
			{
				top3=top2;
				top2=top;
				top=top3;
				n=1;
			}
		
		}
	
	}while(n==0);
	

	
	
	printf("\n\t*************************** TOP DE ATENCIONES********************************");
	
	printf("\n\n\t---> El top de atenciones por veterinarios es:\n\n");
	
	while(!feof(ppp))
	{
		fread(&top,sizeof(TOP),1,ppp);
	
		printf("\n\t--->%d)%s con %d atenciones totales",n+1,top.ApellidoNomb,top.N);
		
		n++;
	}
	

	
	//remove("TOP.dat");
	
	system("pause");
	
	system("cls");*/
	
}


/*------------------------------------Funcion para el menu del veterinario---------------------------------*/

void MenuVeterinario(int n){

system("COLOR E1");
	veterinarios vet;
	
	turnos turn;
	
	int k=0,b=0;

	n=0;
	
	do
	{
	
		do
		{
			system("cls");
			printf("\n\t                       B I E N V E N I D O                          ");
			printf("\n\t                      ---------------------                         \n\n");
   			printf("\n\t********************* MODULO DEL VETERINARIO ************************");    
			printf("\n\t**                                                                 **");
			printf("\n\t**                                                                 **");
			printf("\n\t** (1)  -> INICIAR SESION                                          **");
			printf("\n\t**                                                                 **");
			printf("\n\t**                                                                 **");
			printf("\n\t** (2)  -> VISUALIZAR LISTA DE ESPERA                              **");
			printf("\n\t**                                                                 **");
			printf("\n\t**                                                                 **");
			printf("\n\t** (3)  -> REGISTRAR EVOLUCION DE MASCOTA                          **");
			printf("\n\t**                                                                 **");
			printf("\n\t**                                                                 **"); 
			printf("\n\t** (4)  -> CERRAR LA APLICACION                                    **");
			printf("\n\t**                                                                 **");
			printf("\n\t**                                                                 **");																			   
			printf("\n\t*********************************************************************");
			printf("\n\n\tIngrese su opcion:");
			scanf("%d",&n);
		
		}while(n<1 and n>4);
	
	
	
		if(n==1)
		{
		
				system("cls");
				printf("\n\n\n\n\n\t---------------------------------------------------------------------\n\n");
				printf("\n\t        Para utilizar esta opcion primero debes iniciar sesion.\n\t");
				printf("\n\t---------------------------------------------------------------------\n\n");
   		
			IniciarSeccion(vet,b);		
	
		}
		
		if(b==1 and n==2 )
		{
			system("cls");
			VisualizarListaDeEspera(turn,vet,k);
		}
		
		if(b==0 and n==2)
		{
			system("cls");
				printf("\n\n\n\n\n\t---------------------------------------------------------------------\n\n");
				printf("\n\t        Para utilizar esta opcion primero debes iniciar sesion.\n\t");
				printf("\n\t---------------------------------------------------------------------\n\n");
   		
			system("pause");system("cls");
		}
		
		if(b==1 and n==3)
		{
			system("cls");
			CargarInforme(turn,vet,k);
		}
		
		if(b==0 and n==3)
		{
			system("cls");
				printf("\n\n\n\n\n\t---------------------------------------------------------------------\n\n");
				printf("\n\t        Para utilizar esta opcion primero debes iniciar sesion.\n\t");
				printf("\n\t---------------------------------------------------------------------\n\n");
   		
			system("pause");system("cls");
		}
		
		if(n==4)
		{
			system("cls");
		
			return ;
		}
		
	}while(n!=4);
}


/*----------------------------------------------Funcion para el inicio de sesion de veterinarios ------------------------------------------*/

void IniciarSeccion(veterinarios vet,int &b)
{
	system("COLOR 0F");
	system("cls");
	
	int n=0;
	
	char iniusuario[10];
	
	char inicontrasenia[32];
	
	FILE *P;
	
	int Bandera=0;
	
	veterinarios p;
	
	while(n==0)
	{
		
		printf("\n\t           INICIO DE SESION PARA VETERINARIOS                          ");
		printf("\n\t         --------------------------------------                      \n\n");
									    

		
		_flushall();
		printf("\n\tIntroduzca el usuario del Veterinario---> ");
		gets(iniusuario);
		
			if(strcmp(iniusuario,"0")==0 )
			{
				system("cls");
				return;
			}
		
		P=fopen("Veterinarios.dat","rb");
	    fread(&p,sizeof(veterinarios),1,P);
	    
	    
	    
		while(!feof(P) and Bandera==0)
		{
			
			
			if(strcmp(p.usuario,iniusuario)==0)
			{
				Bandera=1;
				printf("\n\n\t\t  -----Usuario encontrado!-----\n\n");
				system("pause");
				
			}
			else
			{
				system("cls");
				fread(&p,sizeof(veterinarios),1,P);
			}
			
		}
		fclose(P);
		
		
		if(Bandera==1)
		{
		
		
			do
			{
				
		
				_flushall();
				system("cls");
				printf("\n\t           INICIO DE SESION PARA VETERINARIOS                          ");
				printf("\n\t         --------------------------------------                      \n\n");
				printf("\n\n\tIntroduzca La contraseña del usuario: %s \n\tContraseña---> ",iniusuario);
				gets(inicontrasenia);
		
				if(strcmp(inicontrasenia,"0")==0)
				{
					system("cls");b=0;return;
				}
		
				if(strcmp(p.contrasena,inicontrasenia)==0)
				{
					printf("\n\n\t\t  -----Contraseña correcta!-----\n\n"); 
					b=1;
					return;
				}
				
				else
				{
						printf("\n\n\t\t  -----Contraseña incorrecta!-----\n\n"); 
						system("cls");
				}
				system("pause");
				system("cls");
				
			}while(Bandera==1);
		}
		
		else
		{
				printf("\n\n\t\t  -----Usuario no encontrado-----\n\n"); 
				system("pause");system("cls");
		}
	}
}


/*-----------------------------------------Funcion para mostrar la lista de espera de los turnos-------------------------------*/


void VisualizarListaDeEspera(turnos turn,veterinarios vet,int &k)
{
	system("COLOR 0E");
	system("cls");
	
	FILE *p;
	
	int n=0,TurnosTotales=0;
	
	p=fopen("Turnos.dat","rb");
	
	fread(&turn,sizeof(turnos),1,p);
	
	printf("\n\t           LISTA DE ESPERA                          ");
	printf("\n\t         -------------------                      \n\n");
	
	while(!feof(p))
	{
		TurnosTotales++;
			printf("\n\n\tDNI del dueño---> %d",turn.Dni_Dueno);
			printf("\n\n\tFecha del turno---> %d/%d/%d",turn.fecha.Dia,turn.fecha.Mes,turn.fecha.Anio);
			printf("\n");
			printf("         ----------------------------------            \n\n");
			fread(&turn,sizeof(turnos),1,p);
	}
	do
	{
		printf("\n\n\n\tDesea elegir un turno para atender?(1) SI (2) NO\n");
		printf("\t--->");
		scanf("%d",&n);
	}while(n!=1 and n!=2);
	
	if(n==1)
	{
		do{
			printf("\n\n\tTurno a elegir---> ");scanf("%d",&k);
			fclose(p);
			system("CLS");	
		}while(k<1 or k>TurnosTotales);
	}
	system("cls");
}

/*-------------------------------------------Funcion para cargar el informe---------------------------------------------*/


void CargarInforme(turnos turn,veterinarios vet,int k)
{
	system("COLOR f2");
	FILE *p,*pp,*ppp;
	
	p=fopen("Turnos.dat","rb");
	
	if(p==NULL)
	{
		fclose(p);
		printf("\n\n\tError - primero debe cargar 'turnos'.\n");
		system("pause");system("cls");return;
	}
	
	fclose(p);
	
	if(k==0)
	{
		printf("-------------------------------------------------------------------------\n");
		printf("\tPara registrar la evolucion de una mascota primero debe seleccionar que\n\tturno desea antender (opcion 2).");printf("\n\n");system("PAUSE");system("CLS");
		printf("-------------------------------------------------------------------------\n");
		return;
	}
	
	p=fopen("Turnos.dat","rb");
	
	for(int i=0;i<k;i++)
	{
		fread(&turn,sizeof(turnos),1,p);
	}

	fclose(p);
	
	pp=fopen("Veterinarios.dat","rb");
	
	turn.Matricula=vet.Matricula;
	system("CLS");
	
	printf("\n\t                       REGISTRO DEL INFORME                          ");
	printf("\n\t                      ----------------------                      \n\n");
									    
    printf("\n\n\tUsted seleccionó el turno: %d",k);

	
	printf("\n\n\tDNI del dueño---> %d",turn.Dni_Dueno);

	printf("\n\n\tDescriba la evolución de la mascota-> ");
	
	_flushall();

	gets(turn.DetalleDeAtencion);

	printf("\n\n\tINFORME REGISTRADO\n\n\n\tSALIENDO...");
	system("pause");
	system("cls");

	fclose(pp);
	
	p=fopen("Turnos.dat","r+b");// turnos totales

	pp=fopen("Turnos2.dat","a+b");// turnos sin 

	ppp=fopen("TurnosAtendidos.dat","a+b");//turnos atendidos

	fread(&turn,sizeof(turnos),1,p);
	
	while(!feof(p))
	{
		if(turn.Matricula == vet.Matricula)
		{
			printf("hola");
			fwrite(&turn,sizeof(turnos),1,ppp);
		}
		else
		{
			fwrite(&turn,sizeof(turnos),1,pp);
		}
		
		fread(&turn,sizeof(turnos),1,p);
	}
	
	fclose(p);
	
	fclose(pp);
	
	fclose(ppp);
	
	remove("Turnos.dat");

	rename("Turnos2.dat","Turnos.dat");
}



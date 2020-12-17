#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

struct Fecha{
	int Dia;
	int Mes;
	int Anio;
};


struct Veterinario{
	char Apellido_y_Nombre[60];
	int Matricula;
	int Dni;
	char Telefono[25];
	char ContraUsuarioVet[50];
};

struct Mascota{
	char Apellido_y_Nombre[60];
	char Domicilio[60];
	int DNI_duenio;
	char Localidad[60];
	Fecha Fecha_de_Nacimiento;
	float Peso;
	char Telefono[25];
};

struct Turnos{
	int Matricula_de_veterinario;
	Fecha fecha;
	int DNI_duenio;
	char Detalle_de_atencion[380];
};

struct Usuarios{
	char Usuario[10];
	char password[32];
	char Contrasenia[32];
	char Apellido_y_Nombre[60]; 
};

	
void menuprincipal();
void InicioSesion();
void ListaDeEspera();
void datosMascota();
void baja(char buscar_nombre[30]);



main()
{
	
	
 	  system("COLOR f3");	
   	  
   	  
	  menuprincipal();
   	  
 
}
void menuprincipal()
{
 	 	int opcion;
		  	
		
 do
    {	 
	  system("CLS");
		printf("\n\t                       B I E N V E N I D O                          ");
		printf("\n\t                      ---------------------                         \n\n");
																							
																																																														   																					
		printf("\n\t********************* MODULO ADMINISTRACION *************************");    
		printf("\n\t**                                                                 **");
		printf("\n\t** (1)  -> INICIAR SECCION                                         **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (2)  -> VISUALIZAR LISTA DE ESPERA DE TURNOS (informe)          **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (3)  -> REGISTRAR EVOLUCION DE LA MASCOTA                       **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (4)  -> CERRAR LA APLICACION                                    **");
		printf("\n\t**                                                                 **"); 
		printf("\n\t**                                                                 **");																			   
		printf("\n\t*********************************************************************");
		printf("\n\n\tIngrese su opcion:");
  		scanf("%d",&opcion);
        switch (opcion)
        {
        	case 1:
            system("cls");
            InicioSesion();
            break;

        	case 2:
            system("cls");
            ListaDeEspera();
            break;
        
        	case 3:
            system("cls");
            datosMascota();
            break;

        	case 4:
            printf("\n\n\tSaliendo del programa....\n\n\n");
            break;

        	default: printf("\nERROR - No se reconoce la opcion\n");
            break;
        }
    } while (opcion != 4);   
    
}
			
	
void InicioSesion()
{
	
	
Veterinario reg;

 
  int aux_matricula;
  char aux_contrasenia[32];
  FILE *arch_veterinarios = fopen("Veterinarios.dat", "r+b");
  
  system("cls");
  printf("\n\t INICIAR SESION\n\t ");
  _flushall();
  printf("\n\t Ingrese su matricula =====> "); scanf("%d",&aux_matricula);
  _flushall();
  printf("\n\t Ingrese la contrase%ca =====> ",164);  gets(aux_contrasenia); //codico para poder poner la ñ
  
  fread(&reg, sizeof(reg), 1, arch_veterinarios);
  while(!feof(arch_veterinarios))
  {
  	if((aux_matricula==reg.Matricula)and(strcmp(aux_contrasenia,reg.ContraUsuarioVet)==0))
  	{
  	    printf("\n\t se encontro el Veterinario");
  		getch();
		break;
  	
	}
	  else{
	    printf("\n\t no se encontro el Veterinario");
		printf("\nvalor de la matricula %d",reg.Matricula);
		printf("\nValor que ingresamos de la matricula %d",aux_matricula);	
		getch();
		break;

	    }
	    
	  fread(&reg, sizeof(reg), 1, arch_veterinarios); 
  }
  
  

  fclose(arch_veterinarios); 

}

void ListaDeEspera()
{
	system("COLOR A0");
	
		 
	FILE *arch_turnos = fopen("Turnos.dat", "rb");
	FILE *arch_veterinarios = fopen("Veterinarios.dat", "rb");
	
	Turnos turnos;
	Veterinario reg;
	
	
	if(arch_turnos == NULL)
	{
		printf("\n\n\t Error - no se registro ningun turno. ");
		getch();
		exit(1);
		
	}
	if(arch_veterinarios == NULL)
	
	{
		printf("\n\n\t Error - No existe el archivo de veterinario. ");
		getch();
		exit(1);
	}
	else
	{
	
		printf("\n\t*************************** LISTADO ********************************");    
					
		fread(&turnos, sizeof(turnos), 1, arch_turnos);
		
		
												
		while(!feof(arch_turnos))
		{
			printf("\n\n\t--->Matricula: %d", turnos.Matricula_de_veterinario);
						
						
						
			fread(&reg, sizeof(reg), 1, arch_veterinarios);
						
			while(!feof(arch_veterinarios))
			{
							
				if(turnos.Matricula_de_veterinario == reg.Matricula)
				{
					printf("\n\n\t--->Apellido y nombre del veterinario: %s", reg.Apellido_y_Nombre);
								
					break;
										
				}
				
							
				fread(&reg, sizeof(reg), 1, arch_veterinarios);
							
			}
						
			printf("\n\n\t--->Fecha: %d/%d/%d", turnos.fecha.Dia, turnos.fecha.Mes, turnos.fecha.Anio);
						
						
			fread(&turnos, sizeof(Turnos), 1, arch_turnos);
						
						
			printf("\n\n\t********************************************************************\n");
						
		}
	
	}
	fclose(arch_turnos);
	fclose(arch_veterinarios);	
 
}
void datosMascota()
{
	
	char buscar_nombre[30];
	int o;
	char nombre_guardado[40];
	int a;
	
	
	_flushall();
	system("COLOR B0");
	Mascota pet;
	Turnos historiaclinica;
	
	FILE *arch_mascotas;
	
	arch_mascotas = fopen ("Mascotas.dat", "a+b");
	
	/*fread(&pet, sizeof(pet), 1, arch_mascotas);*/
	

	
	
	printf("\n\t                        DATOS DE LA MASCOTA                            ");
	printf("\n\t                      -----------------------                      \n\n");
									    
    printf("\n\n");
   	rewind(arch_mascotas);
	   fread(&pet, sizeof(pet), 1,arch_mascotas);
	   printf("\t\t");
while(!feof(arch_mascotas))
{
													  
	_flushall();
	printf("\n\tMascota---> %s",pet.Apellido_y_Nombre);
	printf("\n\tFecha de nacimiento---> %d / %d / %d",pet.Fecha_de_Nacimiento.Dia,pet.Fecha_de_Nacimiento.Mes,pet.Fecha_de_Nacimiento.Anio);
	printf("\n\tPeso---> %f",pet.Peso);
	printf("\n\tDNI del dueño---> %d",pet.DNI_duenio);
	printf("\n\tDomicilio---> %s",pet.Domicilio);
	printf("\n\tLocalidad---> %s",pet.Localidad);
	printf("\n\tTelefono---> %s",pet.Telefono);
	fread(&pet, sizeof(Mascota),1,arch_mascotas);
	
	system("pause");
}
	//buscar mascota

	rewind(arch_mascotas);
	

	fread(&nombre_guardado, sizeof(char), 1,arch_mascotas);

while ( !feof(arch_mascotas) ) 
{	
	printf("\n\t Ingrese el nombre y apellido de la mascota:");
	printf("\n\t=====>");
	_flushall();
	gets(buscar_nombre);
	
		if(strcmp(pet.Apellido_y_Nombre,buscar_nombre)==0)
	    {
		//en caso de encontrar la mascota se escribe la historia clinica
		printf("\n\tSE ENCONTRO LA MASCOTA INGRESASA");
		printf("\n\tIngrese (1) para crear historia clinica--->");
    	scanf("%d",&o);
	
	   if(o==1)
    	{
			printf("\n\t     HISTORIA CLINICA DE %s",pet.Apellido_y_Nombre);
			printf("\n\t-----------------------------------------\n\n");
			
			_flushall();
			printf("\n\t------>");gets(historiaclinica.Detalle_de_atencion);
			
			printf("\n\n\n\tHistoria clinica creada con exito-\n");
			
			fclose(arch_mascotas);
			remove("Mascotas.dat");
			printf("\n\n.....BORRADO CON EXITO") ;
			baja(buscar_nombre);
			

			getch();	
			printf("\n\t Quiere cargar otra historia clinica?. [1]si , [2]no");
			printf("\n\t =====> ");
			scanf("%d",&a);
			
			if((a==1) or (a==2)){
				if(a==2)
				{
					printf("\n\tSALIENDO...");
					exit(1);
				}
			}
			
    	}
    	else
    	{// si se apreta cualquier otro boton que no sea 1 sale del programa
		exit(1);
		
    	 }
 
	}
	else
	{ // en caso de no encontrar la mascota pide si vuleve a ingresar la mascota o si quiere salir del programa
		printf("\n\tNO SE ENCONTRO LA MASCOTA INGRESADA");
		printf("\n\t PRESIONE [1] PARA VOLVER A INTENTARLO");
	    printf("\n\t PRESIONE [2] PARA SALIR DEL PROGRAMA");
	    printf("\n\t======> ");
	    int p=0;
	    scanf("%d",&p);
	    if(p==2)
	    {
	    	printf("\n\tSALIENDO....");
	        exit(1);
		}
		if(p==1)
		{
			system("cls");
		}
	}
}
	getch();
	
	fclose(arch_mascotas);
}

void baja(char buscar_nombre[30])
{
	bool borrado;
	bool band;	
	_flushall();
	system("COLOR B0");
	
	Mascota pet;
	
	FILE *arch_mascotas;
	
	arch_mascotas = fopen ("Mascotas.dat", "a+b");
	
	fread(&pet,sizeof(Mascota),1,arch_mascotas);
    
	band=false;

 while(feof(arch_mascotas)==0 && band==false)
 {
 if ((strcmp(pet.Apellido_y_Nombre,buscar_nombre)==0) && borrado==false)
 {
 borrado=true;
 fseek(arch_mascotas,- sizeof(pet),SEEK_CUR);
 fwrite(&pet,sizeof(pet),1,arch_mascotas);
 printf("Registro dado de baja\n\n");
 getch();
 band=true;
 }
 else
 {
 fread(&pet,sizeof(pet),1,arch_mascotas);
 }
 }

 rewind(arch_mascotas);
 fread(&pet,sizeof(pet),1,arch_mascotas);
 
 while(!feof(arch_mascotas))
 {
 if (borrado==false)
 {
    printf("\n\tMascota---> %s",pet.Apellido_y_Nombre);
	printf("\n\tFecha de nacimiento---> %d / %d / %d",pet.Fecha_de_Nacimiento.Dia,pet.Fecha_de_Nacimiento.Mes,pet.Fecha_de_Nacimiento.Anio);
	printf("\n\tPeso---> %f",pet.Peso);
	printf("\n\tDNI del dueño---> %d",pet.DNI_duenio);
	printf("\n\tDomicilio---> %s",pet.Domicilio);
	printf("\n\tLocalidad---> %s",pet.Localidad);
	printf("\n\tTelefono---> %s",pet.Telefono);
 }
 fread(&pet,sizeof(pet),1,arch_mascotas);
 }
 fclose(arch_mascotas);
}

	

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

struct Usuarios{
	char Usuario[10];
	char Contrasenia[10];
	char Apellido_y_Nombre[60]; 
};

struct Veterinario{
	char Apellido_y_Nombre[60];
	int Matricula;
	int Dni;
	char Telefono[25];
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
	
void menuprincipal();
//void InicioSesion();
void ListaDeEspera();
void datosMascota();



main()
{
 	  system("COLOR f3");	
   	  
   	  
	  menuprincipal();
   	  
 
}
void menuprincipal()
{
 	 	int opcion;
		  	 
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
		
 do
    {
        switch (opcion)
        {
        	case 1:
            system("cls");
            //InicioSesion();
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
			
	

void ListaDeEspera()
{
	system("COLOR A0");
		 
	FILE *arch_turnos = fopen("Turnos.dat", "rb");
	FILE *arch_veterinarios = fopen("Veterinarios.dat", "rb");
	
	
	Turnos turnos;
	Veterinario reg;
	_flushall();
	rewind(arch_turnos);
	rewind(arch_veterinarios);
	
	printf("\n\t*************************** LISTADO ********************************");    
					
					fread(&turnos, sizeof(turnos), 1, arch_turnos);
					fread(&reg, sizeof(reg), 1, arch_veterinarios);
					while(!feof(arch_turnos) && !feof(arch_veterinarios))
					{
						
						printf("\n\tFecha: %d/%d/%d", turnos.fecha.Dia, turnos.fecha.Mes, turnos.fecha.Anio);
						printf("\n\tVeterinario: %s", reg);	
						fread(&turnos, sizeof(Turnos), 1, arch_turnos);
						fread(&reg, sizeof(Veterinario), 1, arch_veterinarios);
					}
					getch();
					printf("\n\t********************************************************************");
					printf("\n");
	
	
	fclose(arch_turnos);
	fclose(arch_veterinarios);	
 
}
void datosMascota()
{
	_flushall();
	system("COLOR B0");
	Mascota pet;
	Turnos historiaclinica;
	
	FILE *arch_mascotas;
	
	arch_mascotas = fopen ("Mascotas.dat", "rb");
	fread(&pet, sizeof(pet), 1, arch_mascotas);
	
	int o;
	
	
	printf("\n\t                        DATOS DE LA MASCOTA                            ");
	printf("\n\t                      -----------------------                      \n\n");
									    
    printf("\n\n");
   															  
	_flushall();
	printf("\n\tMascota---> %s",pet.Apellido_y_Nombre);
	printf("\n\tFecha de nacimiento---> %d / %d / %d",pet.Fecha_de_Nacimiento.Dia,pet.Fecha_de_Nacimiento.Mes,pet.Fecha_de_Nacimiento.Anio);
	printf("\n\tPeso---> %f",pet.Peso);
	printf("\n\tDNI del dueño---> %d",pet.DNI_duenio);
	printf("\n\tDomicilio---> %s",pet.Domicilio);
	printf("\n\tLocalidad---> %s",pet.Localidad);
	printf("\n\tTelefono---> %s",pet.Telefono);
	
	
	printf("\n\tIngrese (1) para crear historia clinica");
	scanf("%d",&o);
	
	if(o==1)
	{
			printf("\n\tHISTORIA CLINICA DE %s",pet.Apellido_y_Nombre);
			printf("\n\t-----------------------------------------\n\n");
			
			gets(historiaclinica.Detalle_de_atencion);
			
			printf("\n\n\n\tHistoria clinica creada con exito-\n");
	}
	else
	{
		exit(1);
		
	}
	
	
	getch();
	
	fclose(arch_mascotas);
}


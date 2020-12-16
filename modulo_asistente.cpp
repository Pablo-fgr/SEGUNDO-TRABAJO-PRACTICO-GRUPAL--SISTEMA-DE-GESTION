/*-----------------Librerias----------------*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h> //Libreria para caracteres
#include <locale.h> //Libreria para caracteres

/*--------Declaracion de registros------*/

/*---------Registro Fecha----------*/
struct Fecha
{
	int Dia;
	int Mes;
	int Anio;
};

/*-------Registro Datos de usuario-----*/

struct Usuarios
{
	char Usuario[10];
	char Contrasenia[10];
	char Apellido_y_Nombre[60]; 
};

/*-----Registro Datos de Veterinarios-----*/

struct Veterinario
{
	char Apellido_y_Nombre[60];
	int Matricula;
	int Dni;
	char Telefono[25];
};

/*-------Registro Datos de Mascotas------*/

struct Mascota
{
	char Apellido_y_Nombre[60];
	char Domicilio[60];
	int DNI_duenio;
	char Localidad[60];
	Fecha Fecha_de_Nacimiento;
	float Peso;
	char Telefono[25];
};


/*---------Registro Datos de Turnos---------*/

struct Turnos
{
	int Matricula_de_veterinario;
	Fecha fecha;
	int DNI_duenio;
	char Detalle_de_atencion[380];
};

/*-------------------Prototipo de funciones----------------*/
void menu();

void InicioSesion();

void RegistarMascota();

void RegistrarTurno();

void ListadoAtenciones();


/*-------------------Funcion principal------------------*/

int main()
{
	setlocale(LC_ALL, ""); //Declaracion para admision de caracteres como � con las librerias comentadas
	
    menu();
	
	
    return 0;
}

/*-------------------------Funcion Iniciar Sesion------------------------------*/

void InicioSesion()
{
	FILE *arch_usuarios = fopen("Usuarios.dat", "rb");
	
	printf("\n\t                       B I E N V E N I D O                          ");
	printf("\n\t                      ---------------------                         \n\n");
   	printf("\n\t*********************** INCIO DE SESION ****************************");  
	
	if(arch_usuarios == NULL)
	{
		printf("\n\n\t ERROR - No se registro ningun usuario. ");
		exit(1);
	}
	
	Usuarios reg1;
	
	char usuario1[10];
	   
	printf("\n\n\t--->Ingrese el usuario: ");
	_flushall();
	gets(usuario1);
	
	
	
	do
	{
		rewind(arch_usuarios);
	
		fread(&reg1, sizeof(reg1), 1, arch_usuarios);
		while(!feof(arch_usuarios))
		{
			if(strcmp(usuario1, reg1.Usuario)==0)
			{
				printf("\n\n\t [ Usuario Correcto!...]");
				getch();
				break;
			}	
			else
			{
				printf("\n\n\t [ Error de Usuario! ]");
				getch();
			}
			
		
			fread(&reg1, sizeof(reg1), 1, arch_usuarios);
		}  
		
	}while(strcmp(usuario1, reg1.Usuario) == 0);
	
	
	fclose(arch_usuarios);
}

/*--------------------------Funcion Registro de Mascota------------------------------*/

void RegistrarMascota()
{
	_flushall();
	
	system("COLOR B0"); 
	
	FILE *arch_mascotas;
	
	arch_mascotas = fopen ("Mascotas.dat", "ab");
	
	Mascota pet;
	
	
	printf("\n\t                       REGISTRO DE MASCOTAS                           ");
	printf("\n\t                      -----------------------                      \n\n");
									    
    printf("\n\tIngrese los datos de la mascota que desea registrar:\n");
    
   	printf("\t------------------------------------------------------");
   															  
	printf("\n\n\t--->Apellido y nombre: ");
	
	_flushall();
	
	gets(pet.Apellido_y_Nombre);
	
	printf("\n\n\t--->Domicilio: ");
	
	_flushall();
	
	gets(pet.Domicilio);
	
	printf("\n\n\t--->DNI del due�o: ");
	
	scanf("%d", &pet.DNI_duenio);
	
	printf("\n\n\t--->Localidad: ");
	
	_flushall();
	
	gets(pet.Localidad);
	
	printf("\n\n\t--->Fecha de nacimiento: ");
	
	printf("\n\n\t\t--->Dia: ");
	
	scanf("%d", &pet.Fecha_de_Nacimiento.Dia);
	
	printf("\n\t\t--->Mes: ");
	
	scanf("%d", &pet.Fecha_de_Nacimiento.Mes);
	
	printf("\n\t\t--->A�o: ");
	
	scanf("%d", &pet.Fecha_de_Nacimiento.Anio);
	
	printf("\n\n\t--->Peso en kg: ");
	
	scanf("%f", &pet.Peso);
	
	printf("\n\n\t--->Telefono: ");
	
	_flushall();
	
	gets(pet.Telefono);
	
	
	
	fwrite(&pet, sizeof(Mascota),1,arch_mascotas);
	
	
	
	printf("\n\n\t************************************************************\n");
	    printf("\t**                                                        **\n");
	    printf("\t**                                                        **\n");
	    printf("\t**      SE HA REGISTRADO LA MASCOTA EXITOSAMENTE!!        **\n");
	    printf("\t**                                                        **\n");
	    printf("\t**                                                        **\n");
	    printf("\t************************************************************\n\n");
	    
	    
	getch();
	
	fclose(arch_mascotas);
}

/*-----------------------------Funcion Registro de turnos-----------------------------*/

void RegistrarTurno()
{
	system("COLOR F5");
	
	FILE *arch_turnos, *arch_veterinarios;
	
	arch_turnos = fopen ("Turnos.dat", "ab");
	
	arch_veterinarios = fopen("Veterinarios.dat", "rb");
	
	Turnos turnos;
	
	Veterinario reg;
	
	
	
	printf("\n\t                       REGISTRO DE TURNOS                           ");
	printf("\n\t                      --------------------                      \n\n");
									    
    printf("\n\tIngrese los datos correspondientes para el turno a registrar :\n");
    
   	printf("\t----------------------------------------------------------------");
   		
		   
		   													  
	printf("\n\n\t--->Matricula del veterinario: ");
	
	scanf("%d", &turnos.Matricula_de_veterinario);
	
	
	fread(&reg, sizeof(reg), 1, arch_veterinarios);
	

	
	while(!feof(arch_veterinarios))
	{
		if(turnos.Matricula_de_veterinario == reg.Matricula)
		{
			
			printf("\n\t[ Matricula encontrada!...]");
			
		}
		
		fread(&reg, sizeof(reg), 1, arch_veterinarios);
	}
	
	
	
	printf("\n\n\t--->Fecha: ");
	
	do
	{
	
		printf("\n\n\t\t->Dia: ");
	
		scanf("%d", &turnos.fecha.Dia);
		
		if(turnos.fecha.Dia < 1 || turnos.fecha.Dia > 31)
		{
			
			printf("\n\n\t---> [Por favor, Reingrese el dia, [Valor entre 1 y 31] gracias.]");
		
		}
		
	}while(turnos.fecha.Dia < 1 || turnos.fecha.Dia > 31);
	
	do
	{
	
		printf("\n\t\t->Mes: ");
	
		scanf("%d", &turnos.fecha.Mes);
		
		if(turnos.fecha.Mes < 1 || turnos.fecha.Mes > 12)
		{
			
			printf("\n\n\t---> [Por favor, Reingrese el mes, [Valor entre 1 y 12] gracias.]");
			
		}
	
	}while(turnos.fecha.Mes < 1 || turnos.fecha.Mes > 12);
	
	printf("\n\t\t->A�o: ");
	
	scanf("%d", &turnos.fecha.Anio);
	
	printf("\n\n\t--->DNI del due�o: ");
	
	scanf("%d", &turnos.DNI_duenio);
	
	printf("\n\n\t--->Detalle de atenci�n: ");
	
	_flushall();
	
	gets(turnos.Detalle_de_atencion);
	
	
	
	printf("\n\n\t************************************************************\n");
	    printf("\t**                                                        **\n");
	    printf("\t**                                                        **\n");
	    printf("\t**       SE HA REGISTRADO EL TURNO EXITOSAMENTE!!         **\n");
	    printf("\t**                                                        **\n");
	    printf("\t**                                                        **\n");
	    printf("\t************************************************************\n\n");
	
	
	fwrite(&turnos, sizeof(turnos), 1, arch_turnos);
	
	
	getch();
	
	fclose(arch_veterinarios);
	
	fclose(arch_turnos);
	
}

/*-----------------------------------Funcion Listar las Atenciones------------------------------------*/

void ListadoAtenciones()
{
	FILE *arch_turnos = fopen("Turnos.dat", "rb");
	
	FILE *arch_veterinarios = fopen("Veterinarios.dat", "rb");
	
	
	Turnos turnos;
	
	
	Veterinario reg;
	
	
	if(arch_turnos == NULL || arch_veterinarios== NULL)
	{
		printf("\n\n\tERROR - NO EXISTE EL ARCHIVO!!\n\n");
		
		system("pause");
		
		exit(1);
	}
	else
	{
		
		printf("\n\t*************************** LISTADO DE ATENCIONES********************************");    
		
		
					
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
					
	getch();
					
	printf("\n\t********************************************************************");
					
	printf("\n");
	
	
	fclose(arch_turnos);
	
	fclose(arch_veterinarios);
	
}

/*-----------------------------------------------------Funcion Menu Principal------------------------------------------------------*/

void menu()
{
	
    int opcion;
    
    
    do
    {
    	
    	system("cls");
    	
    	system("COLOR E0");
    	
    	printf("\n\t                       B I E N V E N I D O                          ");
		printf("\n\t                      ---------------------                         \n\n");
   		printf("\n\t*********************** MODULO ASISTENTE ****************************");    
		printf("\n\t**                                                                 **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (1)  -> INICIAR SESION                                          **");
		printf("\n\t**                                                                 **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (2)  -> REGISTRAR MASCOTA                                       **");
		printf("\n\t**                                                                 **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (3)  -> REGISTRAR TURNO                                         **");
		printf("\n\t**                                                                 **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (4)  -> LISTADO DE ATENCIONES POR VETERINARIO Y FECHA           **");
		printf("\n\t**                                                                 **"); 
		printf("\n\t**                                                                 **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (5)  -> CERRAR LA APLICACION                                    **");
		printf("\n\t**                                                                 **");
		printf("\n\t**                                                                 **");																			   
		printf("\n\t*********************************************************************");
		printf("\n\n\tIngrese su opcion:");
		
  		scanf("%d", &opcion);
  		
        switch (opcion)
        {
        	
        	case 1:
        		
            system("cls");
            
            InicioSesion();
            
            break;

        	case 2:
        		
            system("cls");
            
            RegistrarMascota();
            
            break;
        
        	case 3:
        		
            system("cls");
            
            RegistrarTurno();
            
            break;

        	case 4:
        		
            	system("cls");
            
            	ListadoAtenciones();
            
            	break;

        	case 5:
        		
        		system("cls");
        		
        		printf("\n\n\n\n\n\t************************************************************\n");
	    				  printf("\t**                                                        **\n");
	    				  printf("\t**              SALIENDO DEL PROGRAMA...                  **\n");
	    				  printf("\t**                                                        **\n");
	    				  printf("\t**              QUE TENGA UN LINDO DIA!                   **\n");
	    				  printf("\t**                                                        **\n");
	    				  printf("\t************************************************************\n\n\n\n\n");
            	
            
            	break;

        	default: printf("\nERROR - NO SE RECONOCE LA OPCION INGRESADA\n\n");
        	
            	break;
        }
        
        
    } while (opcion != 5);
    
    
}

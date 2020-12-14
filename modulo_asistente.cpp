#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

struct Fecha
{
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

void menu();
void InicioSesion();
void RegistarMascota();
void RegistrarTurno();
void ListadoAtenciones();


int main()
{
	setlocale(LC_ALL, "");
    menu();
	
	
    return 0;
}

void InicioSesion()
{
	FILE *arch_usuarios = fopen("Usuarios.dat", "ab");
	
	printf("\nIngrese el nombre de usuario: ");
	
	
	fclose(arch_usuarios);
}

void RegistrarMascota()
{
	_flushall();
	system("COLOR B0");
	
	FILE *arch_mascotas;
	
	arch_mascotas = fopen ("Mascotas.dat", "a+b");
	
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
	
	printf("\n\n\t--->DNI del dueño: ");
	scanf("%d", &pet.DNI_duenio);
	
	printf("\n\n\t--->Localidad: ");
	_flushall();
	gets(pet.Localidad);
	
	printf("\n\n\t--->Fecha de nacimiento: ");
	printf("\n\n\t\t--->Dia: ");
	scanf("%d", &pet.Fecha_de_Nacimiento.Dia);
	printf("\n\t\t--->Mes: ");
	scanf("%d", &pet.Fecha_de_Nacimiento.Mes);
	printf("\n\t\t--->Año: ");
	scanf("%d", &pet.Fecha_de_Nacimiento.Anio);
	
	printf("\n\n\t--->Peso en kg: ");
	scanf("%f", &pet.Peso);
	
	printf("\n\n\t--->Telefono: ");
	_flushall();
	gets(pet.Telefono);
	
	getch();
	
	fwrite(&pet, sizeof(Mascota),1,arch_mascotas);
	
	fclose(arch_mascotas);
}

void RegistrarTurno()
{
	system("COLOR F5");
	
	FILE *arch_turnos;
	
	arch_turnos = fopen ("Turnos.dat", "a+b");
	
	Turnos turnos;
	
	printf("\n\t                       REGISTRO DE TURNOS                           ");
	printf("\n\t                      --------------------                      \n\n");
									    
    printf("\n\tIngrese los datos correspondientes para el turno a registrar :\n");
   	printf("\t----------------------------------------------------------------");
   															  
	printf("\n\n\t--->Matricula del veterinario: ");
	scanf("%d", &turnos.Matricula_de_veterinario);
	
	printf("\n\n\t--->Fecha: ");
	printf("\n\n\t\t->Dia: ");
	scanf("%d", &turnos.fecha.Dia);
	printf("\n\t\t->Mes: ");
	scanf("%d", &turnos.fecha.Mes);
	printf("\n\t\t->Año: ");
	scanf("%d", &turnos.fecha.Anio);
	
	printf("\n\n\t--->DNI del dueño: ");
	scanf("%d", &turnos.DNI_duenio);
	
	printf("\n\n\t--->Detalle de atención: ");
	_flushall();
	gets(turnos.Detalle_de_atencion);
	getch();
	
	fwrite(&turnos, sizeof(Turnos), 1, arch_turnos);
	fclose(arch_turnos);
}

void ListadoAtenciones()
{
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
		printf("\n\t** (1)  -> INICIAR SESION                                          **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (2)  -> REGISTRAR MASCOTA                                       **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (3)  -> REGISTRAR TURNO                                         **");
		printf("\n\t**                                                                 **");
		printf("\n\t** (4)  -> LISTADO DE ATENCIONES POR VETERINARIO Y FECHA           **");
		printf("\n\t**                                                                 **"); 
		printf("\n\t**                                                                 **");
		printf("\n\t** (5)  -> CERRAR LA APLICACION                                    **");
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
            printf("\n\n\tSaliendo del programa....\n\n\n");
            break;

        	default: printf("\nERROR - No se reconoce la opcion\n");
            break;
        }
    } while (opcion != 5);
    
}

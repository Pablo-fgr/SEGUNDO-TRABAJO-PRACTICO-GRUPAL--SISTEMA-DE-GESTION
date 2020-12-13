#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

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

void menu();
void InicioSesion();
void RegistarMascota();

int main()
{
    FILE *arch_usuarios = fopen("Usuarios.dat", "ab");
    FILE *arch_veterinarios = fopen("Veterinarios.dat", "ab");
    FILE *arch_mascotas = fopen ("Mascotas.dat", "ab");
    FILE *arch_turnos = fopen("Turnos.dat", "ab");

    menu();
	
	
	fclose(arch_usuarios);
	fclose(arch_veterinarios);
	fclose(arch_mascotas);
	fclose(arch_turnos);
	
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
	system("COLOR B0");
	
	FILE *arch_mascotas;
	
	arch_mascotas = fopen ("Mascotas.dat", "ab");
	
	Mascota pet;
	
	printf("\n\t                       REGISTRO DE ASISTENTES                           ");
	printf("\n\t                      ------------------------                      \n\n");
									    
    printf("\n\tIngrese los datos del asistente que desea registrar:\n");
   	printf("\t------------------------------------------------------");
   															  
	printf("\n\n\t--->Apellido y nombre: ");
	
	
	fclose(arch_mascotas);
}

void menu()
{
	system("COLOR A1");
    int opcion;
    
    
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
	printf("\n\t** (4)  -> LISTADO DE ATENCIONES POR VETERINARIO Y FECH            **");
	printf("\n\t**                                                                 **"); 
	printf("\n\t**                                                                 **");
	printf("\n\t** (5)  -> CERRAR LA APLICACION                                    **");
	printf("\n\t**                                                                 **");																			   
	printf("\n\t*********************************************************************");
	printf("\n\n\tIngrese su opcion:");
    scanf("%d", &opcion);
    do
    {
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
            break;

        case 4:
            system("cls");
            break;

        case 5:
            printf("\n\n\tSaliendo del programa....\n\n\n");
            break;

        default: printf("\nERROR - No se reconoce la opcion\n");
            break;
        }
    } while (opcion != 5);
    
}

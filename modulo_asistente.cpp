#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

int main()
{
    FILE *arch_usuarios = fopen("Usuarios.dat", "a+b");
    FILE *arch_veterinarios = fopen("Veterinarios.dat", "a+b");
    FILE *arch_mascotas = fopen ("Mascotas.dat", "a+b");
    FILE *arch_turnos = fopen("Turnos.dat", "a+b");

    menu();
	
	
	fclose(arch_usuarios);
	fclose(arch_veterinarios);
	fclose(arch_mascotas);
	fclose(arch_turnos);
	
    return 0;
}

void InicioSesion()
{
	
}

void menu()
{
    int opcion;
    printf("\t\tModulo del asistente\n");
    printf("\t\t=============================\n");
    printf("\t\t 1.- Iniciar sesion\n");
    printf("\t\t 2.- Registrar mascota\n");
    printf("\t\t 3.- Registrar turno\n");
    printf("\t\t 4.- Listado de Atenciones por Veterinario y Fecha\n");
    printf("\t\t 5.- Cerrar la aplicacion\n\n");
    printf("\t\t Ingrese una opcion: ");
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
            break;
        
        case 3:
            system("cls");
            break;

        case 4:
            system("cls");
            break;

        case 5:
            printf("\n\nSaliendo del programa....\n\n\n");
            break;

        default: printf("\nERROR - No se reconoce la opcion\n");
            break;
        }
    } while (opcion != 5);
    
}

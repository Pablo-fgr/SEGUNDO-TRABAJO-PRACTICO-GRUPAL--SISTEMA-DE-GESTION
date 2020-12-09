#include <stdio.h>
#include <stdlib.h>

void menu();

int main()
{
    FILE *arch_usuarios;
    FILE *arch_veterinarios;

    arch_usuarios = fopen("Usuarios.dat", "a+b");

    menu();


    return 0;
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

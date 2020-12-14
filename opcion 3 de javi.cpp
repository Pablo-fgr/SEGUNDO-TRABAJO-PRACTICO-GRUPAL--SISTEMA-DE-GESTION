#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

void datosMascota();

main()
{
	//opcion 3 del menu
	datosMascota();
	
}


void datosMascota()
{
	_flushall();
	system("COLOR B0");
	Mascota pet;
	historiaClinica Turnos;
	
	FILE *arch_mascotas;
	
	arch_mascotas = fopen ("Mascotas.dat", "a+b");
	fread(&pet, sizeof(pet), 1, arch_mascotas);
	
	int o;
	
	
	printf("\n\t                        DATOS DE LA MASCOTA                            ");
	printf("\n\t                      -----------------------                      \n\n");
									    
    printf("\n\n");
   															  
	_flushall();
	printf("\n\tMascota---> %s",pet.Apellido_y_Nombre);
	printf("\n\tFecha de nacimiento---> &d / &d / &d",pet.Fecha_de_Nacimiento.Dia,pet.Fecha_de_Nacimiento.Mes,pet.Fecha_de_Nacimiento.Anio);
	printf("\n\tPeso---> %f",pet.Peso);
	printf("\n\tDNI del dueño---> %d",pet.DNI_duenio);
	printf("\n\tDomicilio---> %s",pet.Domicilio);
	printf("\n\tLocalidad---> %s",pet.Localidad);
	printf("\n\tTelefono---> %s",pet.Telefono);
	
	
	printf("\n\tIngrese (1) para crear historia clinica");
	scanf("%d",&o);
	
	if(o==1)
	{
			printf("\n\t                HISTORIA CLINICA DE %s",pet.Apellido_y_Nombre                             ");
			printf("\n\t                -----------------------------------------                      \n\n");
			
			gets(Turnos.Detalle_de_atencion);
			
			printf("\n\n\n\tHistoria clinica creada con exito-\n");
	}
	else
	{
		exit(1);
		
	}
	
	
	getch();

	
	fclose(arch_mascotas);
}

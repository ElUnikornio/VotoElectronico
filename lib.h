//Estructuras
struct Personas
{
	char nombre[10],
		apellidoP[10],
		apellidoM[10],
		nacionalidad[4],
		contrasena[16],
		voto,
		antecedentes;
	int edad;
};

struct Administrador
{
	char ususario[20],
		contrasena[10];
};

struct Candidato
{
	char partido[10],
		nombre[35];
	int votos;
};

//  Define
#define rutaVotantes "Votantes.txt"
#define rutaAdmin "Admin.txt"
#define rutaCandidato "Candidato.txt"

//  prototipos de funciones
void admin(char *Votacion);
void comprobacionArchivos();
void registrarVotante();
int votantesRegistrados();
void registrarCandidato();

// Funciones
void comprobacionArchivos()
{
	FILE *f;

	f = fopen(rutaVotantes, "r");
	if (f == NULL)
	{
		f = fopen(rutaVotantes, "w");
	}

	f = fopen(rutaAdmin, "r");
	if (f == NULL)
	{
		f = fopen(rutaAdmin, "w");
	}

	f = fopen(rutaCandidato, "r");
	if (f == NULL)
	{
		f = fopen(rutaCandidato, "w");
	}
}

void admin(char *Votacion)
{
	int op;
	FILE *fichero;

	do
	{
		//system("CLS");
		printf("\nSISTEMA DE VOTO ELECTR%cNICO", 224);
		printf("\n\t1)Registrar votante.");
		printf("\n\t2)Ver lista nominal de nombres.");
		printf("\n\t3)Ver resultados de las elecciones.");
		printf("\n\t4)Registrar candidato.");
		printf("\n\t5)Abrir votaciones.");
		printf("\n\t6)Cerrar votaciones.");
		printf("\n\t7)Cambiar clave.");
		printf("\n\t8)Salir.\n");
		scanf("%i", &op);

		switch (op)
		{
		case 1:
			printf("\n\t1)Registrar votante.");
			registrarVotante();
			break;

		case 2:
			printf("\n\t2)Ver lista nominal de votantes.");

			struct Personas Datos;
			votantesRegistrados();

			break;

		case 3:
			printf("\n\t3)Ver resultados de las elecciones.");
			break;

		case 4:
			printf("\n\t4)Registrar candidato.");
			registrarCandidato();
			break;

		case 5:
			printf("\n\t5)Abrir votaciones.");
			*Votacion = 's';
			break;

		case 6:
			printf("\n\t6)Cerrar votaciones.");
			*Votacion = 'n';
			break;

		case 7:
			printf("\n\t7)Cambiar clave.");
			break;

		case 8:
			printf("\n\t8)Salir.\n");
			break;

		default:
			printf("Usa una opci%cn v%clida", 162, 160);
			break;
		}
	} while (op != 8);
}

void registrarVotante()
{
	struct Personas votantes;
	FILE *ficheroVotantes = fopen(rutaVotantes, "a");
	char contra[16] = {"n"};

	if (ficheroVotantes != NULL)
	{
		fflush(stdin);
		//system("CLS");
		printf("Escriba el nombre del votante\n");
		gets(votantes.nombre);

		printf("Escriba el apellido paterno del votante\n");
		gets(votantes.apellidoP);

		printf("Escriba el apellido materno del votante\n");
		gets(votantes.apellidoM);

		printf("Escriba la nacionalidad abreviada del votante abreviada ejemplo(MEX)\n");
		gets(votantes.nacionalidad);

		printf("El votante tiene antecedentes penales s/n\n");
		scanf(" %c", &votantes.antecedentes);

		printf("Escriba la edad del votante\n");
		scanf("%i", &votantes.edad);

		// printf("%s", votantes.nombre);
		// printf("\n%s", votantes.apellidoM);
		// printf("\n%s", votantes.apellidoP);
		// printf("\n%s", votantes.nacionalidad);
		// printf("\n%c", votantes.antecedentes);
		// printf("\n%i", votantes.edad);

		if (strcmp(votantes.nacionalidad, "MEX") == 0 || strcmp(votantes.nacionalidad, "mex") == 0 && votantes.edad >= 18 && votantes.antecedentes == 'n' || votantes.antecedentes == 'N')
		{
			printf("\nCumple con los requisitos para votar");

			do
			{
				if (strcmp(contra, "n") != 0)
					printf("\nLa contrase%ca no coinside, reintente\n", 164);

				fflush(stdin);
				printf("\nEstablesca una contrase%ca: ", 164);
				gets(contra);

				printf("Escriba de nuevo la contrase%ca: ", 164);
				gets(votantes.contrasena);

			} while (strcmp(contra, votantes.contrasena) != 0);

			printf("Contrase%ca establecida con %cxito", 164, 0233);
			fwrite(&votantes, sizeof(votantes), 1, ficheroVotantes);
		}
		else
		{
			if (strcmp(votantes.nacionalidad, "MEX") != 0 && strcmp(votantes.nacionalidad, "mex") != 0)
			{
				printf("La nacionalidad debe de ser MEX para poder votar\n");
				// printf("%i", strcmp(votantes.nacionalidad, "MEX"));
				// printf("%i", strcmp(votantes.nacionalidad, "mex"));
			}

			if (votantes.edad < 18)
			{
				printf("El votante debe de ser mayor de edad\n");
			}

			if (votantes.antecedentes == 's' || votantes.antecedentes == 'S')
			{
				printf("No puede votar si tiene antecedentes penales\n");
			}
		}
	}
	fclose(ficheroVotantes);
}

int votantesRegistrados()
{
	FILE *ficheroVotantes = fopen(rutaVotantes, "r");
	int i = 0;
	struct Personas Datos;

	while (!feof(ficheroVotantes))
	{
		//printf("\n%i\n", i);
		i++;
		fread(&Datos, sizeof(Datos), 1, ficheroVotantes);
	}
	i--;
	fseek(ficheroVotantes, 0, SEEK_SET);

	for (int x = 0; x < i; x++)
	{
		fread(&Datos, sizeof(Datos), 1, ficheroVotantes);

		printf("\n%i) %s  ", x + 1, Datos.nombre);
		printf("%s  ", Datos.apellidoP);
		printf("%s", Datos.apellidoM);
	}
	fclose(ficheroVotantes);

	return i;
}

void registrarCandidato()
{
	FILE *ficheroCandidatos;
	struct Candidato candidato;

	ficheroCandidatos = fopen(rutaCandidato, "a");

	if (ficheroCandidatos != NULL)
	{
		fflush(stdin);
		//system("CLS");
		printf("\nEscriba el partido del candidato\n");
		gets(candidato.partido);

		printf("Escriba el nombre de el candidato\n");
		gets(candidato.nombre);

		candidato.votos = 0;

		printf("%s %s", candidato.partido, candidato.nombre);
		fwrite(&candidato, sizeof(candidato), 1, ficheroCandidatos);
	}
	fclose(ficheroCandidatos);
}
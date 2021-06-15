//Estructuras
struct Personas
{
	char nombre[10],
		apellidoP[10],
		apellidoM[10],
		nacionalidad[4],
		contrasena[16],
		antecedentes;
	int edad, votoid;
};

struct Administrador
{
	char ususario[20],
		contrasena[16];
};

struct Candidato
{
	char partido[10],
		nombre[35];
	int votos, votoid;
};

//  Define
#define rutaVotantes "Votantes.txt"
#define rutaAdmin "Admin.txt"
#define rutaCandidato "Candidato.txt"

//  prototipos de funciones
char inicioSesion();
char comprobacionArchivos();
void admin(char *Votacion);
void registrarVotante();
int votantesRegistrados();
void registrarCandidato();

// Funciones
char inicioSesion()
{
	struct Personas Datos;
	char usuario[20], contra[16], val = 'n';
	FILE *fichero = fopen(rutaVotantes, "r");
	//system("CLS");
	fflush(stdin);
	printf("\nIngrese su ususario: ");
	gets(usuario);
	printf("\nIngrese su contrase%ca: ", 164);
	gets(contra);

	while (!feof(fichero))
	{
		fread(&Datos, sizeof(Datos), 1, fichero);
		if (strcmp(Datos.nombre, usuario) == 0 && strcmp(Datos.contrasena, contra) == 0)
		{
			printf("\nNombre: %s", Datos.nombre);
			printf("\nApellido Paterno: %s", Datos.apellidoP);
			printf("\nApellido Materno: %s", Datos.apellidoM);
			printf("\nTelefono: %s", Datos.contrasena);
			val = 'v';
		}
	}
	if (val != 'v')
	{
		struct Administrador Datos;
		fichero = fopen(rutaAdmin, "r");
		while (!feof(fichero))
		{
			fread(&Datos, sizeof(Datos), 1, fichero);
			if (strcmp(Datos.ususario, usuario) == 0 && strcmp(Datos.contrasena, contra) == 0)
			{
				printf("\ncorroto");
				val = 'a';
			}
		}
	}

	return val;
}

char comprobacionArchivos()
{
	FILE *f;
	char cod = 'n';
	char a = 'n';
	char c = 'n';

	f = fopen(rutaVotantes, "r");
	if (f == NULL)
	{
		f = fopen(rutaVotantes, "w");
		printf("\nCreando archivo votantes");

		a = 's';
	}

	f = fopen(rutaAdmin, "r");
	if (f == NULL)
	{
		printf("\nCreando archivo administrador");
		printf("\nUsuario y contrase%ca por defecto: admin", 164);
		system("PAUSE");
		f = fopen(rutaAdmin, "w");
		struct Administrador admin;

		strcpy(admin.ususario, "admin");
		strcpy(admin.contrasena, "admin");
		fwrite(&admin, sizeof(admin), 1, f);
	}

	f = fopen(rutaCandidato, "r");
	if (f == NULL)
	{
		printf("\nCreando archivo candidatos");
		f = fopen(rutaCandidato, "w");

		c = 's';
	}

	if (a == 's' || c == 's')
	{
		cod = 'a';
	}

	fclose(f);
	return cod;
}

void admin(char *Votacion)
{
	int op;

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
			registrarVotante();
			break;

		case 2:
			votantesRegistrados();

			break;

		case 3:
			printf("\n\t3)Ver resultados de las elecciones.");
			break;

		case 4:
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

			printf("Contrase%ca establecida con %cxito", 164, 130);
			votantes.votoid = 0;
			strcpy(votantes.nacionalidad, "MEX");
			strcpy(votantes.antecedentes, "N");
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

	fclose(ficheroVotantes);
	ficheroVotantes = fopen(rutaVotantes, "r");

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
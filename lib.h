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
		contrasena[16],
		votacion;
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
int inicioSesion();
void comprobacionArchivos();
void admin(char *Votacion);
void registrarVotante();
int votantesRegistrados(int mostrar);
void registrarCandidato();
void cambiarClave();
void resultadoElecciones();
int totalVotos();

// Funciones
int inicioSesion()
{
	struct Personas Datos;
	char usuario[20], contra[16];
	int val = 0, x = 0;
	FILE *fichero = fopen(rutaVotantes, "r");

	fflush(stdin);
	printf("\nIngrese su ususario: ");
	gets(usuario);
	printf("\nIngrese su contrase%ca: ", 164);
	gets(contra);

	fread(&Datos, sizeof(Datos), 1, fichero);
	while (!feof(fichero) && x != -2)
	{
		if (x != -2)
			x++;
		if (strcmp(Datos.nombre, usuario) == 0 && strcmp(Datos.contrasena, contra) == 0)
		{
			// printf("\nNombre: %s", Datos.nombre);
			// printf("\nApellido Paterno: %s", Datos.apellidoP);
			// printf("\nApellido Materno: %s", Datos.apellidoM);
			// printf("\nTelefono: %s", Datos.contrasena);
			// printf("\nVotoID: %i", Datos.votoid);

			val = x;
			x = -2;
		}
		fread(&Datos, sizeof(Datos), 1, fichero);
	}

	//printf("%i", val);

	if (x != -2)
	{
		struct Administrador Datos;
		fichero = fopen(rutaAdmin, "r");
		fread(&Datos, sizeof(Datos), 1, fichero);
		while (!feof(fichero))
		{
			if (strcmp(Datos.ususario, usuario) == 0 && strcmp(Datos.contrasena, contra) == 0)
			{
				val = 0;
			}
			else
			{
				val = -1;
			}

			fread(&Datos, sizeof(Datos), 1, fichero);
		}
	}
	return val;
}

void comprobacionArchivos()
{
	FILE *f;
	int i = 0;

	f = fopen(rutaVotantes, "r");
	if (f == NULL)
	{
		f = fopen(rutaVotantes, "w");
		system("CLS");
		printf("\nCreando archivo votantes\n");
		fclose(f);

		i++;
	}

	f = fopen(rutaCandidato, "r");
	if (f == NULL)
	{
		printf("\nCreando archivo candidatos\n");
		f = fopen(rutaCandidato, "w");
		fclose(f);
		i++;
	}

	f = fopen(rutaAdmin, "r");
	if (f == NULL)
	{
		printf("\nCreando archivo administrador");
		printf("\nUsuario por defecto: admin \ncontrase%ca por defecto: admin\n", 164);
		f = fopen(rutaAdmin, "w");
		struct Administrador admin;

		strcpy(admin.ususario, "admin");
		strcpy(admin.contrasena, "admin");
		admin.votacion = 'n';
		fwrite(&admin, sizeof(admin), 1, f);
		fclose(f);
	}
	if (i > 0)
	{
		system("PAUSE");
	}
}

void admin(char *Votacion)
{
	struct Administrador ad;
	FILE *f;
	int op;

	do
	{
		system("CLS");
		printf("\nSISTEMA DE VOTO ELECTR%cNICO", 224);
		printf("\n\t1)Registrar votante.");
		printf("\n\t2)Ver lista nominal de votantes.");
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
			f = fopen(rutaVotantes, "r");
			if (feof(f))
			{
				fclose(f);
				system("color 04");
				system("CLS");
				printf("No hay votantes registrados");

				system("color 0F");
			}
			else
			{
				fclose(f);
				votantesRegistrados(1);
				printf("\n");
				system("PAUSE");
			}

			break;

		case 3:
			system("CLS");
			printf("RESULTADO DE LAS ELECCIONES");
			resultadoElecciones(1);
			printf("\n");
			system("PAUSE");

			break;

		case 4:
			registrarCandidato();
			break;

		case 5:
			system("CLS");
			printf("Las votaciones se han abierto.\n");
			system("PAUSE");

			*Votacion = 's';
			f = fopen(rutaAdmin, "r+");
			fread(&ad, sizeof(ad), 1, f);
			ad.votacion = 's';

			fseek(f, 0, SEEK_SET);
			fwrite(&ad, sizeof(ad), 1, f);
			fclose(f);
			break;

		case 6:
			system("CLS");
			printf("Las votaciones se han cerrado.\n");
			system("PAUSE");

			*Votacion = 'n';
			f = fopen(rutaAdmin, "r+");
			fread(&ad, sizeof(ad), 1, f);
			ad.votacion = 'n';

			fseek(f, 0, SEEK_SET);
			fwrite(&ad, sizeof(ad), 1, f);
			fclose(f);
			break;

		case 7:
			cambiarClave();
			break;

		case 8:
			printf("\nAdios administrador.\n");
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
		system("CLS");
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
			system("CLS");
			//verde
			system("color 02");

			printf("\nCumple con los requisitos para votar\n");
			system("PAUSE");
			system("color 0F");

			do
			{
				if (strcmp(contra, "n") != 0)
				{
					system("CLS");
					system("color 04");

					printf("\nLa contrase%ca no coinside, reintente\n", 164);
					system("PAUSE");

					system("color 0F");
				}

				fflush(stdin);
				printf("\nEstablesca una contrase%ca: ", 164);
				gets(contra);

				printf("Escriba de nuevo la contrase%ca: ", 164);
				gets(votantes.contrasena);

			} while (strcmp(contra, votantes.contrasena) != 0);

			system("CLS");
			system("color 02");

			printf("Contrase%ca establecida con %cxito\n", 164, 130);
			system("PAUSE");
			system("color 0F");

			votantes.votoid = 0;
			votantes.nacionalidad[0] = 'M';
			votantes.nacionalidad[1] = 'E';
			votantes.nacionalidad[2] = 'X';
			votantes.antecedentes = 'N';
			fwrite(&votantes, sizeof(votantes), 1, ficheroVotantes);
		}
		else
		{
			system("CLS");
			//rojo
			system("color 04");
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
			//nornal
			system("PAUSE");
			system("color 0F");
		}
	}
	fclose(ficheroVotantes);
}

int votantesRegistrados(int mostrar)
{
	FILE *ficheroVotantes = fopen(rutaVotantes, "r");
	int i = 0;
	struct Personas Datos;

	fread(&Datos, sizeof(Datos), 1, ficheroVotantes);
	while (!feof(ficheroVotantes))
	{
		//printf("\n%i\n", i);
		if (mostrar)
		{
			printf("\n%i) %s  ", i + 1, Datos.nombre);
			printf("%s  ", Datos.apellidoP);
			printf("%s ", Datos.apellidoM);
		}
		fread(&Datos, sizeof(Datos), 1, ficheroVotantes);
		i++;
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
		system("CLS");
		fflush(stdin);
		printf("\nEscriba el partido del candidato\n :");
		gets(candidato.partido);

		printf("Escriba el nombre de el candidato\n :");
		gets(candidato.nombre);

		candidato.votos = 0;

		candidato.votoid = rand();

		//printf("%s %s %i", candidato.partido, candidato.nombre, candidato.votoid);
		fwrite(&candidato, sizeof(candidato), 1, ficheroCandidatos);
	}
	fclose(ficheroCandidatos);
}

void cambiarClave()
{
	FILE *fichero;
	int totalVotantes = 0, op;
	struct Administrador Datos;

	system("CLS");
	printf("Seleccione una opci%cn", 162);
	printf("\n\ta)Usuario");
	printf("\n\tb)Administrador\n\t :");
	fflush(stdin);
	switch (getchar())
	{
	case 'a':

		system("CLS");
		printf("\nUSUARIOS REGISTRADOS ");
		totalVotantes = votantesRegistrados(1);
		fflush(stdin);
		printf("\n\tSeleccione un n%cmero de usuario :", 163);
		scanf("%i", &op);

		if (op > 0 && op <= totalVotantes)
		{
			struct Personas Datos;
			fichero = fopen(rutaVotantes, "r+");

			fseek(fichero, (op - 1) * sizeof(Datos), SEEK_SET);
			fread(&Datos, sizeof(Datos), 1, fichero);

			system("CLS");
			printf("\nusuario actual: %s\ncontrase%ca actual: %s", Datos.nombre, 164, Datos.contrasena);

			fflush(stdin);
			printf("\ningrese una nueva contrase%ca: ", 164);
			gets(Datos.contrasena);

			fseek(fichero, (op - 1) * sizeof(Datos), SEEK_SET);
			fwrite(&Datos, sizeof(Datos), 1, fichero);
		}
		else
		{
			system("CLS");
			printf("Selecciona una opci%cn v%clida.", 162, 160);
			system("PAUSE");
		}

		break;
	case 'b':
		fichero = fopen(rutaAdmin, "r+");

		fread(&Datos, sizeof(Datos), 1, fichero);

		printf("\nusuario actual: %s\n contrase%ca actual: %s \n\n", Datos.ususario, 164, Datos.contrasena);

		fflush(stdin);
		printf("ingrese una nueva contrase%ca", 164);
		gets(Datos.contrasena);

		fseek(fichero, 0, SEEK_SET);
		fwrite(&Datos, sizeof(Datos), 1, fichero);
		break;

	default:
		break;
	}

	fclose(fichero);
}

void resultadoElecciones(int mostrar)
{

	FILE *fCan = fopen(rutaCandidato, "r");
	struct Candidato cand;
	int c = 1;
	//int totalvot = totalVotos();
	fread(&cand, sizeof(cand), 1, fCan);
	//system("CLS");
	//printf("Resultado de las elecciones");
	while (!feof(fCan))
	{
		printf("\n\t%i) %s \t %s\t\t\t", c, cand.partido, cand.nombre);
		if (mostrar)
		{
			for (int i = 0; i < cand.votos; i++)
			{
				printf("#");
			}
			printf("\t\t %i votos", cand.votos /*, ((float)cand.votos * 100 / (float)totalvot), 37*/);
		}
		c++;
		fread(&cand, sizeof(cand), 1, fCan);
	}
	//printf("\n");
	fclose(fCan);
}

int totalVotos()
{
	int votos = 0;
	int op = votantesRegistrados(0);

	FILE *fichero = fopen(rutaVotantes, "r");
	struct Personas Datos;

	for (int i = 0; i < op; i++)
	{
		fread(&Datos, sizeof(Datos), 1, fichero);
		if (Datos.votoid > 0)
		{
			votos++;
		}
	}

	fclose(fichero);
	//printf("%i", votos);

	return votos;
}
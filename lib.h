//Estructuras
struct Personas
{
    char nombre[10],
        apellidoP[10],
        apellidoM[10],
        nacionalidad[15],
        contrasena[10],
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
        nombre[25];
    int votos;
};

//  Define
#define rutaVotantes "Votantes.txt"
#define rutaAdmin "Admin.txt"
#define rutaCandidato "Candidato.txt"

//  prototipos de funciones
void admin(int **Votacion);
void comprobacionArchivos();

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

void admin(int **Votacion)
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
            printf("\n\t1)Registrar votante.");
            break;

        case 2:
            printf("\n\t2)Ver lista nominal de nombres.");
            break;

        case 3:
            printf("\n\t3)Ver resultados de las elecciones.");
            break;

        case 4:
            printf("\n\t4)Registrar candidato.");
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
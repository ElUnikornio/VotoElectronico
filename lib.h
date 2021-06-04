//Estructuras
struct Personas
{
    char nombre[10];
    char apellidoP[10];
    char apellidoM[10];
    int edad;
    char nacionalidad[15];
    char contrasena[10];
    char voto;
    char antecedentes;
};

struct Administrador
{
    char ususario[20];
    char contrasena[10];
};

struct Candidato
{
    char partido[10];
    char nombre[25];
    int votos;
};

//  prototipos de funciones
int admin();

// Funciones
int admin()
{
    system("CLS");
    printf("SISTEMA DE VOTO ELECTR%cNICO", 224);
    printf("\n\t1)Registrar votante.");
    printf("\n\t2)Ver lista nominal de nombres.");
    printf("\n\t3)Ver resultados de las elecciones.");
    printf("\n\t4)Registrar candidato.");
    printf("\n\t5)Abrir votaciones.");
    printf("\n\t6)Cerrar votaciones.");
    printf("\n\t7)Cambiar clave.");
    printf("\n\t8)Salir.");

    fflush(stdin);
    return getchar();
}
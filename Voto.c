#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int haVotado(int op);
int anularVoto(int op, int id);
void elegirCandidato(int op);

int mai()
{
    resultadoElecciones(0);

    return 0;
}

int main()
{
    char VotacionActiva = 's';
    srand(getpid());
    comprobacionArchivos();
    //admin(&VotacionActiva);
    int op, id;
    //inicializarVotos();

    do
    {
        system("CLS");
        printf("\tSISTEMA DE VOTO ELECTRONICO\n\t---------------------------");
        op = inicioSesion();
        if (op > 0)
        {
            if (VotacionActiva == 's')
            {
                //printf("Usuario N %i", op);
                id = haVotado(op);
                if (id)
                {
                    anularVoto(op, id);
                }
                system("CLS");
                printf("Selecciona una opcion");
                resultadoElecciones(0);
                printf("\n\t0) Anular voto\n\t :");
                elegirCandidato(op);
            }
            else
            {
                system("CLS");
                printf("\nLas votaciones no se han habilitado");
            }
        }
        else if (op == 0)
        {
            printf("admin");
            admin(&VotacionActiva);
        }
        else
        {
            printf("No se encontro");
        }

        printf("\nQuiere continuar s/n\n\t:");
        fflush(stdin);
    } while (getchar() == 's');

    //admin(&VotacionActiva);
    return 0;
}

int haVotado(int op)
{
    int id = 0;
    FILE *fichero = fopen(rutaVotantes, "r");
    struct Personas Datos;

    fseek(fichero, (op - 1) * sizeof(Datos), SEEK_SET);
    fread(&Datos, sizeof(Datos), 1, fichero);

    if (Datos.votoid > 0)
    {
        id = Datos.votoid;
    }

    fclose(fichero);

    return id;
}

int anularVoto(int op, int id)
{
    int pos = -1, c = 0;
    FILE *fVot = fopen(rutaVotantes, "r+");
    FILE *fCan = fopen(rutaCandidato, "r+");

    struct Personas Datos;
    struct Candidato cand;

    fseek(fVot, (op - 1) * sizeof(Datos), SEEK_SET);
    fread(&Datos, sizeof(Datos), 1, fVot);

    fread(&cand, sizeof(cand), 1, fCan);
    while (!feof(fCan))
    {
        if (Datos.votoid == cand.votoid)
        {
            pos = c;
        }

        if (pos == -1)
            c++;

        fread(&cand, sizeof(cand), 1, fCan);
    }

    if (pos != -1)
    {
        fseek(fCan, (pos) * sizeof(cand), SEEK_SET);
        fread(&cand, sizeof(cand), 1, fCan);
        cand.votos--;
        fseek(fCan, (pos) * sizeof(cand), SEEK_SET);
        fwrite(&cand, sizeof(cand), 1, fCan);
        printf("\nYa voto\n");
    }

    fseek(fVot, (op - 1) * sizeof(Datos), SEEK_SET);
    Datos.votoid = 0;
    fwrite(&Datos, sizeof(Datos), 1, fVot);

    fclose(fVot);
    fclose(fCan);
}

void elegirCandidato(int op)
{
    int i = 0;
    FILE *fVot = fopen(rutaVotantes, "r+");
    FILE *fCan = fopen(rutaCandidato, "r+");

    struct Personas Datos;
    struct Candidato cand;

    fflush(stdin);
    scanf("%i", &i);

    fseek(fVot, (op - 1) * sizeof(Datos), SEEK_SET);
    fread(&Datos, sizeof(Datos), 1, fVot);

    fseek(fCan, (i - 1) * sizeof(cand), SEEK_SET);
    fread(&cand, sizeof(cand), 1, fCan);

    Datos.votoid = cand.votoid;
    cand.votos++;

    fseek(fVot, (op - 1) * sizeof(Datos), SEEK_SET);
    fwrite(&Datos, sizeof(Datos), 1, fVot);

    fseek(fCan, (i - 1) * sizeof(cand), SEEK_SET);
    fwrite(&cand, sizeof(cand), 1, fCan);

    fclose(fCan);
    fclose(fVot);
}

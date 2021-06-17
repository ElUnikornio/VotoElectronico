#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void voto();

int main()
{
    char VotacionActiva = 'n';
    comprobacionArchivos();
    //admin(&VotacionActiva);
    int op;

    do
    {
        op = inicioSesion();
        if (op > 0)
        {
            printf("Usuario N %i", op);
            voto(op);
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

        printf("\nQuiere continuar s/n");
        fflush(stdin);
    } while (getchar() == 's');

    //admin(&VotacionActiva);
    return 0;
}

void voto(int op)
{
    FILE *ficheroVot = fopen(rutaVotantes, "r+");
    FILE *ficheroCan = fopen(rutaCandidato, "r");
    int i = 0;

    struct Personas votante;
    struct Candidato candidato;

    printf("\nSeleccione una opcion\n");
    fread(&candidato, sizeof(candidato), 1, ficheroCan);
    while (!feof(ficheroCan))
    {
        //printf("\n%i\n", i);
        printf("\t%i) %s  \n", i + 1, candidato.nombre);
        i++;
        fread(&candidato, sizeof(candidato), 1, ficheroCan);
    }
    /*
    scanf("%i", &i);
    fseek(ficheroCan, (i - 1) * sizeof(candidato), SEEK_SET);
    fread(&candidato, sizeof(candidato), 1, ficheroCan);

    fseek(ficheroVot, (op) * sizeof(votante), SEEK_SET);
    fread(&votante, sizeof(candidato), 1, ficheroVot);
    votante.votoid = candidato.votoid;
    fseek(ficheroVot, (op) * sizeof(votante), SEEK_SET);
    //fwrite(&votante, sizeof(votante), 1, ficheroVot);

    printf("%s\t%i\t%i", votante.nombre, votante.votoid, candidato.votoid);*/
}
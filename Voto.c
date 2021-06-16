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
    int op = inicioSesion();

    if (op == 0)
    {
        admin(&VotacionActiva);
    }
    else
    {
        do
        {
            if (op > 0)
            {
                void voto();
            }
            else if (op == -1)
            {
                printf("El Usuario o crontrase%ca soin incorrectos", 164);
            }
            printf("\n quiere continuar s/n\n");
        } while (getchar() == 's');
    }

    // //admin(&VotacionActiva);
    return 0;
}

void voto();
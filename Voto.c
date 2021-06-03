#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int op;
    char VotacionActiva = 'n';

    printf("\nSelecciona una opci%cn", 162);
    printf("\n\ta)Soy administrador");
    printf("\n\tb)Soy votante");
    printf("\n\ts)Salir\n");

    switch (getchar())
    {
    case 'a':
        printf("\tadmin\n");
        admin();
        break;

    case 'b':
        printf("votante\n");
        if (VotacionActiva == 's')
        {
            /* code */
        }
        else
        {
            printf("Las votaciones a%cn no est%cn habilitadas\nEl administrador debe habilitarlas.", 163, 160);
        }

        break;

    case 's':
        printf("Adios");
        op = -1;
        break;

    default:
        printf("Usa una opci%cn v%clida", 162, 160);

        break;
    }
    return 0;
}
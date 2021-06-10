#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    comprobacionArchivos();
    char VotacionActiva = 'n', op;
    do
    {
        //system("CLS");
        printf("\nSISTEMA DE VOTO ELECTR%cNICO", 224);
        printf("\nSelecciona una opci%cn", 162);
        printf("\n\ta)Soy administrador");
        printf("\n\tb)Soy votante");
        printf("\n\ts)Salir\n");
        fflush(stdin);
        scanf("%c", &op);

        switch (op)
        {
        case 'a':
            //printf("\tadmin\n");
            admin(&VotacionActiva);
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
                system("PAUSE");
            }

            break;

        case 's':
            printf("Adios");
            break;

        default:
            printf("Usa una opci%cn v%clida", 162, 160);

            break;
        }
    } while (op != 's');
    return 0;
}
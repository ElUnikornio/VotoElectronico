#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    char VotacionActiva = 'n', op = comprobacionArchivos();
    /*
    if (op == 'a')
    {
        admin(&VotacionActiva);
    }
    else
    {
        do
        {
            op = inicioSesion();
            if (op == 'a')
            {
                admin(&VotacionActiva);
            }
            else if (op == 'v')
            {
                printf("votante");
            }
            printf("\n quiere continuar s/n\n");
        } while (getchar() == 's');
    }
*/
    admin(&VotacionActiva);
    return 0;
}
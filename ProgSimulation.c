#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lib/libgraphique.h"

int main(void)
{
ouvrir_fenetre(800, 600);

actualiser();

attendre_clic();
fermer_fenetre();
return 0 ;
}

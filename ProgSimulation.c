#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lib/libgraphique.h"
#include "lib/lib_foule.c"

int main(void)
{
int plan[80][60];
ouvrir_fenetre(800, 600);
charge_plan("data/plan.txt", plan);
actualiser();

attendre_clic();
fermer_fenetre();
return 0 ;
}

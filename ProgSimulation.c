/////////////////////////////////Directives préprocesseur///////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lib/libgraphique.h"
#include "lib/lib_foule.h"

////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	int plan[80][60];	/*Création d'un tableau representant le plan*/
	int cpt, cpt2;		/*Création des variables pour compteurs*/
	Point p1 = { 0, 0 };	/*Point qui sert à dessiner les obstacles( rectangles )*/

	ouvrir_fenetre(800, 600);
	charge_plan("data/plan.txt", plan);	

//////////////////////////////////Affichage plan graphique//////////////////////////////////

	for (cpt2 = 0; cpt2 < 60; cpt2++ )	/*Teste les colonnes*/
	{
		p1.y = p1.y+10;

		for (cpt = 0; cpt < 80; cpt++ )		/*Teste les lignes*/
		{
			if ( plan[cpt][cpt2]== 1 )
			{
				dessiner_rectangle( p1, 10, 10, forestgreen );
			}

		p1.x = p1.x+10;
		}
		p1.x = 0;	/*Initialise à 0 pour rétourner à la ligne*/
		printf("\n\n");
	}
/////////////////////////////////////////////////////////////////////////////////////////////
//Portes//
/////////////////////////////////////////////////////////////////////////////////////////////


	Point Prt1 = { 50, 80 };
	Point Prt2 = { 400, 100 };
	Point Prt3 = { 670, 350 };

	dessiner_rectangle( Prt1, 10, 10, gris );
	dessiner_rectangle( Prt2, 10, 10, gris );
	dessiner_rectangle( Prt3, 10, 10, gris );

/////////////////////////////////////////////////////////////////////////////////////////////

	actualiser();
	attendre_clic();
	fermer_fenetre();
	return 0 ;
}

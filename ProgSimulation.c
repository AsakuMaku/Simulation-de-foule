/////////////////////////////////Directives préprocesseur///////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lib/libgraphique.h"
#include "lib/lib_foule.h"

#define NPIXEL 10

////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 
{
	Point position;
	Point destination;
} Joueur;

int main(void)
{
	int plan[80][60];	/*Création d'un tableau representant le plan*/
	int cpt, cpt2;		/*Création des variables pour compteurs*/
	Point p1 = { 0, 0 };	/*Point qui sert à dessiner les obstacles( rectangles )*/

	ouvrir_fenetre(80*NPIXEL, 60*NPIXEL);
	charge_plan("data/plan.txt", plan);

//////////////////////////////////Affichage plan graphique//////////////////////////////////

//Plan//

	for (cpt2 = 0; cpt2 < 60; cpt2++ )	/*Teste les colonnes*/
	{
		for (cpt = 0; cpt < 80; cpt++ )		/*Teste les lignes*/
		{
			if ( plan[cpt][cpt2]== 1 )
			{
				dessiner_rectangle( p1, NPIXEL, NPIXEL, forestgreen );
			}
			p1.x = p1.x+NPIXEL;
		}
		p1.x = 0;	/*Initialise à 0 pour rétourner à la ligne*/
		p1.y = p1.y+NPIXEL;
	}

//Portes//


	Point prt1 = { 5*NPIXEL, 8*NPIXEL };
	Point prt2 = { 40*NPIXEL, 10*NPIXEL };
	Point prt3 = { 67*NPIXEL, 35*NPIXEL };

	dessiner_rectangle( prt1, NPIXEL, NPIXEL, gris );
	dessiner_rectangle( prt2, NPIXEL, NPIXEL, gris );
	dessiner_rectangle( prt3, NPIXEL, NPIXEL, gris );

//Joueurs//

	Joueur j1 = { prt1, prt3 };
	dessiner_rectangle( j1.position, NPIXEL, NPIXEL, red );

	actualiser();
	attendre_clic();

	while ( j1.position.x != j1.destination.x || j1.position.y != j1.destination.y )
	{

		if ( j1.position.x < j1.destination.x )
		{
			j1.position.x = j1.position.x+NPIXEL;
		}
		else if ( j1.position.x > j1.destination.x )
		{
			j1.position.x = j1.position.x-NPIXEL;
		}
		else 
		{
			if ( j1.position.y < j1.destination.y )
			{
				j1.position.y = j1.position.y+NPIXEL;
			}
			else if ( j1.position.y > j1.destination.y )
			{
				j1.position.y = j1.position.y-NPIXEL;
			}
			else 
			{
		
			}
		}
		dessiner_rectangle( j1.position, NPIXEL, NPIXEL, red );
		actualiser();
		attente(120);
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////

	actualiser();
	attendre_clic();
	fermer_fenetre();
	return 0;
}

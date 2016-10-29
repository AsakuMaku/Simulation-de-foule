/////////////////////////////////Directives préprocesseur///////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lib/libgraphique.h"
#include "lib/lib_foule.h"

#define NPIXEL 10	/*Tailles des entités en pixel*/

////////////////////////////////////////////////////////////////////////////////////////////
/*Le joueur a une position et une destination*/
typedef struct 
{
	Point position;
	Point destination;
} Joueur;

/*Prototypes de fonctions*/
void afficher_plan(int plan[80][60]);
void afficher_joueur(Joueur j);

int main(void)
{
	int plan[80][60];	/*Création d'un tableau representant le plan*/
	charge_plan("data/plan.txt", plan);
	
	ouvrir_fenetre(80*NPIXEL, 60*NPIXEL);

//////////////////////////////////Affichage graphique//////////////////////////////////

//Plan//

	afficher_plan(plan);

//Joueurs//

	Point prt1 = { 5*NPIXEL, 8*NPIXEL };
	Point prt2 = { 40*NPIXEL, 10*NPIXEL };
	Point prt3 = { 67*NPIXEL, 35*NPIXEL };
	
	Joueur j1 = { prt2, prt3 };
	afficher_joueur(j1);

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
		afficher_plan(plan);
		afficher_joueur(j1);
		actualiser();
		attente(80);
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////

	actualiser();
	attendre_clic();
	fermer_fenetre();
	return 0;
}


void afficher_plan(int plan[80][60])	/*Affiche le plan avec les portes*/
{
	int cpt, cpt2;		/*Création des variables pour compteurs*/
	Point p1 = { 0, 0 };	/*Point qui sert à dessiner les obstacles ( rectangles )*/
	
	/*Determine et affiche les obstacles dans le plan*/
	for (cpt2 = 0; cpt2 < 60; cpt2++ )	/*Parcours les colonnes*/
	{
		for (cpt = 0; cpt < 80; cpt++ )		/*Parcours les lignes*/
		{
			if ( plan[cpt][cpt2] == 1 )	/*Vérifie si la valeur correspond à un obstacle*/
			{
				dessiner_rectangle( p1, NPIXEL, NPIXEL, forestgreen );
			}
			else	/*Affiche le fond du plan*/
			{
				dessiner_rectangle( p1, NPIXEL, NPIXEL, black );
			}
			p1.x = p1.x+NPIXEL;
		}
		p1.x = 0;	/*Initialise à 0 pour rétourner à la ligne*/
		p1.y = p1.y+NPIXEL;
	}

	/*Portes*/
	Point prt1 = { 5*NPIXEL, 8*NPIXEL };
	Point prt2 = { 40*NPIXEL, 10*NPIXEL };
	Point prt3 = { 67*NPIXEL, 35*NPIXEL };
	
	dessiner_rectangle( prt1, NPIXEL, NPIXEL, gris );
	dessiner_rectangle( prt2, NPIXEL, NPIXEL, gris );
	dessiner_rectangle( prt3, NPIXEL, NPIXEL, gris );
}

void afficher_joueur(Joueur j)
{
	dessiner_rectangle( j.position, NPIXEL, NPIXEL, red );
}

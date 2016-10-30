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
Joueur deplacer_joueur(int plan[80][60], Joueur j);
int anti_mur( int plan[80][60], Joueur j, char direction);
void charger_joueurs(char *fjoueurs, Joueur joueurs[50]);


int main(void)
{
	int plan[80][60];	/*Création d'un tableau representant le plan*/
	charge_plan("data/plan.txt", plan);
	
	Joueur joueurs[50];	/*Création d'un tableau representant le plan*/
	charger_joueurs("data/joueurs", joueurs);
	
	ouvrir_fenetre(80*NPIXEL, 60*NPIXEL);

//////////////////////////////////Affichage graphique//////////////////////////////////

//Plan//

	afficher_plan(plan);

//Joueurs//

	Point prt1 = { 5*NPIXEL, 8*NPIXEL };
	Point prt2 = { 40*NPIXEL, 10*NPIXEL };
	Point prt3 = { 67*NPIXEL, 35*NPIXEL };
	printf("%d %d %d %d\n", joueurs[0].position.x, joueurs[0].position.y, joueurs[0].destination.x, joueurs[0].destination.y);
	
	//Joueur j1 = { prt2, prt3 };
	//j1.position.y += NPIXEL*2;
	Joueur j1 = joueurs[5];
	afficher_joueur(j1);

	actualiser();
	attendre_clic();

	while ( j1.position.x != j1.destination.x || j1.position.y != j1.destination.y )
	{
		j1 = deplacer_joueur( plan, j1 );
		
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
				dessiner_rectangle( p1, NPIXEL, NPIXEL, sarcelle );
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

Joueur deplacer_joueur(int plan[80][60], Joueur j)
{
	if ( j.position.x < j.destination.x && anti_mur(plan, j, 'd' ))
	{
		j.position.x = j.position.x+NPIXEL;
	}
	else if ( j.position.x > j.destination.x )
	{
		j.position.x = j.position.x-NPIXEL;
	}
	else 
	{
		if ( j.position.y < j.destination.y )
		{
			j.position.y = j.position.y+NPIXEL;
		}
		else if ( j.position.y > j.destination.y )
		{
			j.position.y = j.position.y-NPIXEL;
		}
		else 
		{
	
		}
	}
	return j;
}

int anti_mur( int plan[80][60], Joueur j, char direction )
{
	int vertical = 0, horizontal = 0;
	
	if ( direction == 'h' )
	{
		vertical = -NPIXEL;
	}
	else if ( direction == 'b' )
	{
		vertical = +NPIXEL;
	}
	else if ( direction == 'g' )
	{
		horizontal = -NPIXEL;
	}
	else if ( direction == 'd' )
	{
		horizontal = +NPIXEL;
	}

	if ( plan[(j.position.x+horizontal)/NPIXEL][(j.position.y+vertical)/NPIXEL] == 1 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void charger_joueurs( char *fjoueurs, Joueur joueurs[50] )
{
    FILE *f = fopen( fjoueurs,"r" );
    int nbJoueur, i, j;
    char c;

    if( !f )
    {
        printf( "Fichier '%s': ouverture impossible\n",fjoueurs );
        exit( 1 );
    }

    fscanf( f,"%d\n",&nbJoueur );
    if( nbJoueur!=50 )
    {
        printf( "Fichier '%s': dimensions du tableau lues dans incorrectes\n",fjoueurs );
        exit( 1 );
    }

    for( j=0; j!=nbJoueur; j++ )
    {
    	int t;
    	// position.x
    	fscanf( f,"%d",&joueurs[j].position.x);
    	fscanf( f,"%c",&c);
    	// position.y
    	fscanf( f,"%d",&joueurs[j].position.y);
    	fscanf( f,"%c",&c);
    	// destination.x
    	fscanf( f,"%d",&joueurs[j].destination.x);
    	fscanf( f,"%c",&c);
    	// destination.y
    	fscanf( f,"%d",&joueurs[j].destination.y);
    	fscanf( f,"%c",&c);
    	
    	// Multiplie par la taille en pixel
    	joueurs[j].position.x *= NPIXEL;
    	joueurs[j].position.y *= NPIXEL;
    	joueurs[j].destination.x *= NPIXEL;
    	joueurs[j].destination.y *= NPIXEL;
    }
    fclose(f);
}

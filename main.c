/*
 ============================================================================
 Name        : seance_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

SEANCE 1 : QUESTIONS SUR L'AFFICHAGE D'UN ENTIER AU FORMAT BINAIRE

TAILLE DES ENTIERS

1) Si un entier unsigned dépasse sa valeur maximale ça renvoie 0, si c'est pas unsigned on décalera les bits sur le bit de signe et donc on aura un entier négatif

2) Pour déterminer la taille de atester on le fait dépasser sa valeur

3) Le compteur sert à déterminer sa taille car il indiquera le nombre de bit parcourus avant d'avoir dépassé la limite

4) C'est pas les mêmes types d'entiers (un en 32 bits et l'autre en 64 bits (le long long)) donc on n'utilise pas le même format d'affichage

5) sur code

6) On peut le remplacer par atester=*2

7) sur code

8) sur code




int main()
{
    unsigned long atester=1;
    unsigned compteur=1;
    while (atester!=0) {
        printf("%u\t%lu\n",compteur++,atester);
        atester*=2;
    }
    return 0;
}




TRANSCODAGE BINAIRE

1) atoi : ascii to integer : prend un nombre en string et le renvoie en int

2) La structure ternaire permet de faire des if else en une seule ligne

3) Separateur de quartet : à chaque 4 bits print (tout les 4 modulos de j) on met un espace

4) L'affichage exadécimal permet de condenser l'info, moins de caractères pour des nombres plus longs

5) Sur code



#include <stdio.h>
#include <stdlib.h>

#define size 12

int main(int argc, char **argv)
{
    int i,j,valeur;
    for (i=1;i<argc;i++) {
        valeur=atoi(argv[i]);
        printf("%12d = ",valeur);
        if (valeur >= -2048 && valeur <= 4095) {
        	for (j=size-1;j>=0;j--) {
        		printf("%c",((valeur & (1<<j))==0)?'0':'1');
        		if (j%4==0) // séparateur de quartets
                    {printf(" ");
                    }
        	}
        }
        else { printf("XXX "); }


        printf("= %08x\n",valeur);
    }
    exit(EXIT_SUCCESS);
}


 */




// EXERCICE MORPION



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void){

	int num_case=0;
	int num_joueur=1 ;
	int val_joueur;
	uint32_t etat_grille=0;

	if (!victoire(etat_grille)){

		printf("Joueur %u ? ",num_joueur);
		val_joueur = scanf("%u",&num_case);
		if (val_joueur == 1)
			printf("%u \n",num_case);

			affichage();
			(num_joueur==1) ? num_joueur=2 : num_joueur=1 ;

	}
	else {
		printf("le gagnant est le joueur %u", victoire(etat_grille));
	}
	return 0;


}


// fonction pour récupérer la valeur d'une case enregistrée dans le nombre etat_grille

int extraction_bits(int num_case, uint32_t etat_grille){
	uint8_t valeur_recuperee = (etat_grille >> (2*num_case)) & 3 ;
	return valeur_recuperee;
}


// fonction pour calculer à chaque fois si on est dans une victoire

int victoire(uint32_t etat_grille){

	if (!extraction_bits(0,etat_grille)){
		if(extraction_bits(0,etat_grille) == extraction_bits(1,etat_grille) == extraction_bits(2,etat_grille)){
			return extraction_bits(0,etat_grille);
		}

	}

	if (!extraction_bits(3,etat_grille)){
			if(extraction_bits(3,etat_grille) == extraction_bits(4,etat_grille) == extraction_bits(5,etat_grille)){
				return extraction_bits(3,etat_grille);
			}

		}

	if (!extraction_bits(6,etat_grille)){
			if(extraction_bits(6,etat_grille) == extraction_bits(7,etat_grille) == extraction_bits(8,etat_grille)){
				return extraction_bits(6,etat_grille);
			}

		}

	if (!extraction_bits(0,etat_grille)){
				if(extraction_bits(0,etat_grille) == extraction_bits(3,etat_grille) == extraction_bits(6,etat_grille)){
					return extraction_bits(0,etat_grille);
				}

			}

	if (!extraction_bits(1,etat_grille)){
				if(extraction_bits(1,etat_grille) == extraction_bits(4,etat_grille) == extraction_bits(7,etat_grille)){
					return extraction_bits(1,etat_grille);
				}

			}

	if (!extraction_bits(2,etat_grille)){
				if(extraction_bits(2,etat_grille) == extraction_bits(5,etat_grille) == extraction_bits(8,etat_grille)){
					return extraction_bits(2,etat_grille);
				}

			}

	if (!extraction_bits(0,etat_grille)){
				if(extraction_bits(0,etat_grille) == extraction_bits(4,etat_grille) == extraction_bits(8,etat_grille)){
					return extraction_bits(0,etat_grille);
				}

			}

	if (!extraction_bits(2,etat_grille)){
				if(extraction_bits(2,etat_grille) == extraction_bits(4,etat_grille) == extraction_bits(6,etat_grille)){
					return extraction_bits(2,etat_grille);
				}

			}

	return 0;


}


// fonction pour donner directement quoi afficher dans chaque case en conftion de etat_grille

int attribution_case(int n, char case_){
	if (extraction_bits(n,etat_grille) == 0){
		case_ = " ";}
	else if (extraction_bits(n,etat_grille) == 1){
		case_ = "0";}
	else {case_ = "X";}
	return 0;
}


// fonction pour print a chaque coup l'état du morpion

int affichage(void){
	char case_0,case_1,case_2,case_3,case_4,case_5,case_6,case_7,case_8 ;

	attribution_case(0,case_0);
	attribution_case(1,case_1);
	attribution_case(2,case_2);
	attribution_case(3,case_3);
	attribution_case(4,case_4);
	attribution_case(5,case_5);
	attribution_case(6,case_6);
	attribution_case(7,case_7);
	attribution_case(8,case_8);



	printf("%u | %u | %u\n---------\n"
			"%u | %u | %u\n---------\n"
			"%u | %u | %u\n---------\n", case_6,case_7,case_8,case_3,case_4,case_5,case_0,case_1,case_2);

	return 0;
}







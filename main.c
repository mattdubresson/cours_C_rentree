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




// SEANCE 2

/*


#include <stdlib.h>
#include <stdint.h>

int extraction_bits(int num_case, uint32_t etat_grille);
uint32_t poser_jeton(uint32_t etat_grille, int num_case, int joueur);
int victoire(uint32_t etat_grille);
char attribution_case(int n, uint32_t etat_grille);
void affichage(uint32_t etat_grille);

int main(void){

int num_case = 0;
int num_joueur = 1;
int val_joueur;
uint32_t etat_grille = 0;
int nb_coups = 0;

while (victoire(etat_grille) == -1 && nb_coups < 9) {
    affichage(etat_grille);
    printf("Joueur %d ? ", num_joueur);
    val_joueur = scanf("%d", &num_case);

    if (val_joueur == 1 && num_case >= 1 && num_case <= 9) {
        int pos = num_case - 1;
        if (extraction_bits(pos, etat_grille) == 0) {
            etat_grille = poser_jeton(etat_grille, pos, num_joueur);
            nb_coups++;
            if (num_joueur == 1) {
                num_joueur = 2;
            } else {
                num_joueur = 1;
            }
        } else {
            printf("Case deja occupee !\n");
        }
    } else {
        while (getchar() != '\n');
        printf("Saisie invalide !\n");
    }
}

affichage(etat_grille);
int res = victoire(etat_grille);
if (res != -1) {
    printf("le gagnant est le joueur %d\n", res);
} else {
    printf("Match nul !\n");
}

return 0;

}

// fonction pour récupérer la valeur d'une case enregistrée dans le nombre etat_grille

int extraction_bits(int num_case, uint32_t etat_grille){
uint8_t valeur_recuperee = (etat_grille >> (2*num_case)) & 3 ;
return valeur_recuperee;
}

// fonction pour modifier la valeur d'une case dans etat_grille 

uint32_t poser_jeton(uint32_t etat_grille, int num_case, int joueur){
return etat_grille | (joueur << (2 * num_case));
}

// fonction pour calculer à chaque fois si on est dans une victoire

int victoire(uint32_t etat_grille){

if (extraction_bits(0, etat_grille) != 0){
    if(extraction_bits(0, etat_grille) == extraction_bits(1, etat_grille) && extraction_bits(1, etat_grille) == extraction_bits(2, etat_grille)){
        return extraction_bits(0, etat_grille);
    }
}

if (extraction_bits(3, etat_grille) != 0){
    if(extraction_bits(3, etat_grille) == extraction_bits(4, etat_grille) && extraction_bits(4, etat_grille) == extraction_bits(5, etat_grille)){
        return extraction_bits(3, etat_grille);
    }
}

if (extraction_bits(6, etat_grille) != 0){
    if(extraction_bits(6, etat_grille) == extraction_bits(7, etat_grille) && extraction_bits(7, etat_grille) == extraction_bits(8, etat_grille)){
        return extraction_bits(6, etat_grille);
    }
}

if (extraction_bits(0, etat_grille) != 0){
    if(extraction_bits(0, etat_grille) == extraction_bits(3, etat_grille) && extraction_bits(3, etat_grille) == extraction_bits(6, etat_grille)){
        return extraction_bits(0, etat_grille);
    }
}

if (extraction_bits(1, etat_grille) != 0){
    if(extraction_bits(1, etat_grille) == extraction_bits(4, etat_grille) && extraction_bits(4, etat_grille) == extraction_bits(7, etat_grille)){
        return extraction_bits(1, etat_grille);
    }
}

if (extraction_bits(2, etat_grille) != 0){
    if(extraction_bits(2, etat_grille) == extraction_bits(5, etat_grille) && extraction_bits(5, etat_grille) == extraction_bits(8, etat_grille)){
        return extraction_bits(2, etat_grille);
    }
}

if (extraction_bits(0, etat_grille) != 0){
    if(extraction_bits(0, etat_grille) == extraction_bits(4, etat_grille) && extraction_bits(4, etat_grille) == extraction_bits(8, etat_grille)){
        return extraction_bits(0, etat_grille);
    }
}

if (extraction_bits(2, etat_grille) != 0){
    if(extraction_bits(2, etat_grille) == extraction_bits(4, etat_grille) && extraction_bits(4, etat_grille) == extraction_bits(6, etat_grille)){
        return extraction_bits(2, etat_grille);
    }
}

return -1;

}

// fonction pour donner directement quoi afficher dans chaque case en conftion de etat_grille

char attribution_case(int n, uint32_t etat_grille){
if (extraction_bits(n, etat_grille) == 0){
return ' ';
}
else if (extraction_bits(n, etat_grille) == 1){
return 'O';
}
else {
return 'X';
}
}

// fonction pour print a chaque coup l'état du morpion

void affichage(uint32_t etat_grille){
char case_0 = attribution_case(0, etat_grille);
char case_1 = attribution_case(1, etat_grille);
char case_2 = attribution_case(2, etat_grille);
char case_3 = attribution_case(3, etat_grille);
char case_4 = attribution_case(4, etat_grille);
char case_5 = attribution_case(5, etat_grille);
char case_6 = attribution_case(6, etat_grille);
char case_7 = attribution_case(7, etat_grille);
char case_8 = attribution_case(8, etat_grille);

printf("%c | %c | %c\n---------\n"
       "%c | %c | %c\n---------\n"
       "%c | %c | %c\n---------\n", case_6, case_7, case_8, case_3, case_4, case_5, case_0, case_1, case_2);

}

*/

// SEANCE 3

// LES POINTEURS

/*

#include <stdlib.h>
#include <stdint.h>


int main(){
	uint32_t a='a';
	uint16_t b='b';
	uint8_t c='c';
	uint8_t d='d';
	uint32_t *pa;
	
	printf("%d\n",a);
	printf("%lX\n",pa);
	pa = &a;
	printf("%lX\n",pa);
	printf("%d\n",*pa);
	printf("%lX\n",&a);
	printf("%lX\n",&pa);
	return 0;
	
}

*/

// CRIBLE D'ERATHEUSTENE

/*

#include <stdlib.h>
#include <stdint.h>


int divisible_par(int k, int liste_entiers[], size_t N){
    int c;
    for (size_t i = k; i <= N; i++){
        if (liste_entiers[i]%k == 0 && liste_entiers[i] != k){
            liste_entiers[i] = 0;
        }
    }
    return 0;
}

int eratheustene(int n){
    int liste_entiers[n]={};
    int N = sizeof(liste_entiers)/sizeof(liste_entiers[0]);
	for (int i = 1; i <=(n); i++){
		liste_entiers[i-1] = i;
	}
    for (int i=2; i<=n; i++){
        divisible_par(i, liste_entiers, N);
    }
    for (int i = 0; i < n; i++){
        if (liste_entiers[i]){
            printf("%d ", liste_entiers[i]);
        }
    }
    printf("\n");
    return 0;
}


int main(){
    printf("Les nombres premiers sont :\n");
    eratheustene(181);
    uint32_t e='e';
    uint32_t pe=&e;
    printf("%d %c\n",pe,*pe);
    return 0;
}





// EXERCICE DE GEMINI

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


void min_max_moyenne(const int *tab, int taille, int *min, int *max, double *moyenne){
    *min = tab[0];
    *max = tab[0];
    double somme = 0;
    for (int i = 0; i<taille;i++){
        if (tab[i] < *min){
            *min = tab[i];
        }
        if (tab[i] > *max){
            *max = tab[i];
        }
        somme += tab[i];
    }
    *moyenne = somme / taille;
}

int main() {
    int tab[5] = {5, 2, 9, 1, 7};
    int taille = sizeof(tab) / sizeof(tab[0]);
    int min, max;
    double moyenne;
    min_max_moyenne(tab, taille, &min, &max, &moyenne);
    printf("Min: %d\nMax: %d\nMoyenne: %.2f\n", min, max, moyenne);
    return 0;
}

*/

// Le programme "liste chainée simple" fourni construit une liste chainée simple à partir des arguments passés en ligne de commande ( argv ) :

#include <stdio.h>
#include <stdlib.h>

/* Ce programme est un exemple simple d'utilisation d'une liste chainée
 * dynamique (la taille s'adapte à la quantité de données à traiter)
 *
 * Il utilise les arguments passés dans argv pour les stocker dans la liste
 * quel que soit leur nombre, ensuite cette liste est parcourue pour afficher
 * ses éléments.
 *
 * lors d'un lancement, ne pas oublier les arguments ;-)
 *
 * P. Varoqui, EEA, sept 2012
 */
struct element
{
    int rang;                   // rang de l'argument
    char *valeur;               // valeur de l'argument (chaine)
    struct element *suivant;    // pointeur vers élément suivant
};

typedef struct element element;

int main(int argc, char **argv)
{
    element premier;  // premier est une structure
    element *encours; // encours est un pointeur
    int i;
    if (argc) {
        // on démarre avec le premier
        premier.rang=1;
        premier.valeur=argv[1];
        premier.suivant=NULL;
        encours=&premier;
        // remplissage des valeurs suivantes
        for (i=2;i<argc;i++) {
            (*encours).suivant=malloc(sizeof(element)); // nouvel element
            encours=(*encours).suivant; // devient l'élément courant
            (*encours).rang=i;
            (*encours).valeur=argv[i];
            (*encours).suivant=NULL; // valeur initiale
        }
        // liste du contenu
        encours=&premier;
        do {
            printf("%d -> %s\n",(*encours).rang,(*encours).valeur);
            if ((*encours).suivant!=NULL)
                encours=(*encours).suivant;
            else
                break;
        } while (1);
    } else {
        // lancé sans arguments, le programme est sans objet
        printf("pas d'arguments à traiter :-(");
    }
    exit(EXIT_SUCCESS);
}



/*
En commentaire, en tête du code, expliquer le principe d'une liste chainée.
Vérifier le fonctionnement du code proposé et corriger le bug du cas sans argument

Insertion et tri

Modifier ce code pour classer les mots par ordre alphabétique lors de l'insertion d'une nouvelle valeur dans la liste (tri par insertion).
Attention, on ne déplace ni les données ni les rangs (on imagine que valeur est de grande taille), on modifie seulement les valeurs des pointeurs "suivant".
La fonction srtcmp de string.h peut être utile.


Liste à double chainage
Modifier le code précédent pour introduire un chainage arrière qui permettra de parcourir la liste dans les deux sens. Afficher le résultat du classement en ordre croissant et décroissant.

*/


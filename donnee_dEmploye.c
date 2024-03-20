/*Écrire une fonction qui remplit les différents champs de la structure employé. Cette
fonction doit aussi générer la valeur du champ code. Ce dernier est une chaine de cinq
caractères composée par la concaténation du 1er caractère du nom, du 1er caractère du
prénom et des trois premiers caractères du service. Le code doit être générer avec des
caractères majuscule.
struct Date
{
                int j;
                int M;
                int ANN;
};
typedef struct Date date;

struct personne
{
                char *nom;
                char *prenom;
                char *service;
                date DateEmb;
                char *code;
};
typedef struct personne employe;
*/
#include <stdio.h>
#include <stdlib.h>

struct Date
{
                int j;
                int M;
                int ANN;
};
typedef struct Date date;

struct personne
{
                char *nom;
                char *prenom;
                char *service;
                date DateEmb;
                char *code;
};
typedef struct personne employe;

char* saisir_chaine()
{
                int i = 0;
                char *chaine,c;
                chaine = (char*)malloc(sizeof(char));
                while((c=getchar())!= '\n')
                {
                                chaine[i] = c;
                                i++;
                                chaine = (char*)realloc(chaine, (i+1)*sizeof(char));
                }
                chaine[i] = '\0';
                return (chaine);
}
void afficher_chaine(char *chaine)
{
                for(int i = 0; chaine[i] != '\0';i++)
                {
                                printf("%c", chaine[i]);
                }
}

void majuscule(char* chaine)
{
                int i = 0;
                while(chaine[i] != '\0')
                {
                                if(chaine[i]<='z' && chaine[i]>='a')
                                                chaine[i] = chaine[i] +'A' - 'a';
                                i++;
                }
}

employe saisir_employe()
{
                //declaration
                employe X;
                X.code = (char*)malloc(6*sizeof(char));
                printf("nom =  ");
                X.nom = saisir_chaine();
                printf("prenom = ");
                X.prenom = saisir_chaine();
                printf("service =  ");
                X.service = saisir_chaine();
                printf("date d'embauche =  ");
                scanf("%d %d %d", &(X.DateEmb.j),&(X.DateEmb.M), &(X.DateEmb.ANN));
                //generation du code
                X.code[0] = X.nom[0];
                X.code[1] = X.prenom[0];
                X.code[2] = X.service[0];
                X.code[3] = X.service[1];
                X.code[4] = X.service[2];
                X.code[5] = '\0';
                majuscule(X.code);
                return X;
}

void afficher_employe(employe X)
{
                afficher_chaine(X.code);
                printf("        ");
                afficher_chaine(X.nom);
                printf("        ");
                afficher_chaine(X.prenom);
                printf("        ");
                afficher_chaine(X.service);
                printf("        ");
                printf("%d-%d-%d",X.DateEmb.j, X.DateEmb.M, X.DateEmb.ANN);
                printf("\n");
}

int main()
{
                employe X;
                X = saisir_employe();
                afficher_employe(X);
}


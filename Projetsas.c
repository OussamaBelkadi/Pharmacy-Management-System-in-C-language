#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void tp();
//------_____-------__ PRINCIPALE

int main ()
{
	
typedef struct{
	int jour;
	int  mois;
	int annee;
}date;
	
typedef struct 
{
	char code[12];
	char nom[15];
	int quan;
	float prix;
	date dat;
	int squa;
	
}produit;
date dat;
int nbr;
produit P[1000];
static int i;
int index=0;
produit A[1000];
int indexA=0;
produit Z;
produit E;
///-----------------------FONCTION POUR AJOUTER UN SEUL PRODUIT
void ajop ()
{
	i=index;
	
	
		printf("\n----------------------------------------------------------\n");
		printf("\tVeullier entrer le code du produit: ");
		scanf (" %s",&P[i].code);	
		fflush(stdin);
				
		printf("\tVeuiller entrer le nom du produit: ");
		scanf(" %s",&P[i].nom);
		fflush(stdin);
		
		printf("\tVeuiller entrer la quantitee de produit:");
		scanf("%d",&P[i].quan);
		fflush(stdin);
		
		printf("\tVeuiller entrer le prix de produit:");
		fflush(stdin);
		scanf(" %f",&P[i].prix);
		printf("\n-----------------------------------------------\n");
		P[i].prix=P[i].prix+(P[i].prix*0.15);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("  Le produit %s a ete ajouter\n",P[i].nom);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		index++;
		printf("\n-----------------------------------------------\n");

}

//------------------------FONCTION D'AJOUTER PLUSIEUR PRODUITS
	
void ajoplp ()
{
	do{
	printf("\n\n\n--------------------------------------------------------\n");
	printf("\tVeuiller entrer le nombre de produit a ajouter: ");
	scanf(" %d",&nbr);
	printf("\n--------------------------------------------------------\n");
		}while(nbr<0);
	nbr=nbr+index;
	
		for(i=index;i<nbr;i++)
		{
			printf("\n-----------------------------------------------\n");	
			printf("\tVeuiller entrer le code du produit: ");
			scanf (" %s",&P[i].code);
			fflush(stdin);
			
			printf("\tVeuiller entrer le nom du produit: ");
			scanf(" %s",&P[i].nom);
			fflush(stdin);
			
			printf("\tVeuiller entrer la quantitee de produit : ");
			scanf("%d",&P[i].quan);
			fflush(stdin);
			
			printf("\tVeuiller entrer le prix de produit : ");
			scanf("%f",&P[i].prix);
			fflush(stdin);
			printf("\n-----------------------------------------------\n");
			P[i].prix=P[i].prix+(P[i].prix*0.15);
		
			printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("  Le produit %s a ete ajouter\n",P[i].nom);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			index++;
		}
	
	
	
}

//-------------------------FONCTION D'AFFICHAGE 
void aff()
{
	
	    for(i=0;i<index;i++)
	    {
	    	printf ("\n\nLe produit num %d:\n\n",i+1);
	       	printf("Le nom de produit: %s\n",P[i].nom);
	       	printf("Le code de produit : %s\n",P[i].code);
	       	printf("Le prix du produit : %.2f\n",P[i].prix);
	       	printf("Le quan du produit : %d",P[i].quan);
	    }
	
}


//------------------LE TRI PAR ORDRE ALPHABITIQUE CROISSANT 
void tria()
{
	int j,test;
	i=0;
	for(i=0;i<index;i++){
        for(j=i+1;j<index;j++){
            if(strcmp(P[i].nom,P[j].nom)>0){

                Z=P[i];
                P[i]=P[j];
                P[j]=Z;
            }
        }
    }
	for (j=0;j<index;j++){
		printf("\n-----------------------------------------------\n");
		printf("\n \t\t\t\tLe produit num %d \n " ,j+1);
		printf("\n \t\t\t\tLe code est: %s \n",P[j].code);
		printf("\n \t\t\t\tLe nom est: %s \n",P[j].nom);
		printf("\n \t\t\t\tLa quantite est: %d\n",P[j].quan);
		printf("\n \t\t\t\tLe prix est: %.2f\n",P[j].prix);
		printf("\n-----------------------------------------------\n");	
		printf("\n");
	}

}

//------------------LE TRI PAR ORDRE DE PRIX D'ECROITION
void trip()
{
	int j;
	for (i=0;i<index;i++){
		for(j=i+1;j<index;j++){
		
			if(P[i].prix<P[j].prix)
			{
				E=P[i];
				P[i]=P[j];
				P[j]=E;
			}
		}
	}

	for (i=0;i<index;i++){
		printf("\n-----------------------------------------------\n");
		printf("\n \t\t\t\tLe produit num %d  \n" ,i+1);
		printf("\n \t\t\t\tLe code est: %s \n",P[i].code);
		printf("\n \t\t\t\tLe nom est: %s \n",P[i].nom);
		printf("\n \t\t\t\tLa quantite est: %d \n",P[i].quan);
		printf("\n \t\t\t\tLe prix est: %.2f \n",P[i].prix);
		printf("\n-----------------------------------------------\n");	
		printf("\n");
	}

}


//--------------------------FONCTION QUI LISTE TOUS LES PRODUITS
void tri()
{
	int choix;
	do{
		printf("\n----------------------------------------------------------------------------------\n");	
		printf("\t\tVeuiller entre le choix de trie du tableau \n");
		printf("\n----------------------------------------------------------------------------------\n");	
		printf("\n----------------------------------------------------------------------------------\n");	
		printf("\t\t1-trie par ordre alphabetique croissant du nom. \n\t\t 2-trie par ordre decroissant du prix \n");
		printf("\t\t0-Quiter\n");
		printf("\n----------------------------------------------------------------------------------\n");	
		printf("\n Choix: ");
		scanf("%d",&choix);
		
		switch(choix)
		{
			case 1:
				tria();
			break;
			case 2:
				trip();
			break;
			case 0:
				printf(" ");
			break;
			default:
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("\t\tretour au menu principal.");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
			break;
		}
	}while(choix!=0);
}

//-----------------FONCTION DE RECHERCHE PAR QUANTITE
void  rechq ()
{
	int quan;
	printf("\n-------------------------------------------------\n");
	printf("Veuiller entrer la quantite du produit rechercher ");
	fflush(stdin);
	scanf("%d",&quan);	
	printf("\n-------------------------------------------------\n");
	
	for(i=0;i<index;i++)
	{
		if(P[i].quan==quan)
		{
			printf("\nle code: %s \n",P[i].code);
			printf("le nom: %s \n",P[i].nom);
			printf("la quantite: %d \n",P[i].quan);
			printf("le prix: %.2f \n",P[i].prix);
		}
	}
	if(P[i].quan!=quan){
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\tCette quantite n'existe pas");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
}

//-----------------FONCTION DE RECHERCHE PAR CODE
int  rechc ()
{
	int test=0;
	char code[10];
	printf("\n----------------------------------------------------------------------------------\n");	
	printf("\t\tVeuiller entrer le code de produit rechercher: ");
	scanf("%s",&code);
	printf("\n----------------------------------------------------------------------------------\n");	
	for(i=0;i<index;i++)
	{
		if(strcmp(code,P[i].code)==0)
		{
			printf("\nle code: %s \n",P[i].code);
			printf("le nom: %s \n",P[i].nom);
			printf("le quantite: %d \n",P[i].quan);
			printf("le prix: %.2f \n",P[i].prix);
			test=1;
			return i;
		}
		
	}
		if(test==0)
		{
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Le produit inexistant ! ");
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			return -1;
		}
}


 //---------------------------FONCTION DE LA RECHERCHE
void rech ()
{
	
	int n;
	do{
	printf("\n------------------Methode de Recherche-------------------\n");
	printf("\t\t1-recherche d un produit par quantite  \n   ");
	printf("\t\t2-recherche d un produit par code  \n   ");
	printf("                       0-Quiter                        ");
	printf("\n---------------------------------------------------------\n");
	printf("\n \t\t\t Entrer votre choix: ");
	scanf("%d",&n);
	
	  	
		switch(n){
			case 1:
				rechq();
			break;
			
			case 2:
				rechc();
			break;
			case 0:
				printf(" ");
			break;
				
			default:
				printf("\n----------------------------------------------------------------------------------\n");	
				printf("\n\t\tVeuiller entrer un choix convenable.");
				printf("\n----------------------------------------------------------------------------------\n");	
			break;
		}
	}while(n!=0);
}


//-----------------FONCTION DE SUPRITION DE PRODUIT
void supr()
{
	
	int flag=0;
	char code[10];
	int res=rechc();
		for(i=0;i=index;i++)
		{
			if(res!=-1)
			{
				P[res]=P[res+1];
				flag=1;
				index--;
			}
		
		}	
			if(flag==1)
			{
				printf("\n----------------------------------------------------------------------------------\n");	
				printf("\n\t\tle produit est suprimer");
				printf("\n----------------------------------------------------------------------------------\n");	
			}	
}



//-------------------------FONCTION QUI AFFICHE L'ETAT DE STOCK
void estock()
{
	
	for (i=0;i<index;i++)
	{
		if(P[i].quan<3)
		{
			printf("%s \t\t %s \t\t %d \t\t%.2f",P[i].code,P[i].nom,P[i].quan,P[i].prix);
			printf("\n");
		}
	}
	if(P[i].quan>3)
	{
		printf("\n----------------------------------------------------------------------------------\n");	
		printf("\t\tLes produits dont la quantite est inferieure a 3 \n");
		printf("-------------------------------------------------------------------------------------\n");
		}
}

//-------------------------FONCTION POUR L'ALIMENTATTION DE STOCK
void alstock()
{
	int rec,Q ;
	rec=rechc();
	printf("\n----------------------------------------------------------------------------------\n");	
	printf("\n\t\tVeuiller entrer a quantite a ajouter: ");
	scanf("%d",&Q);
	printf("\n----------------------------------------------------------------------------------\n");	
	if(rec!=-1){
		P[rec].quan+=Q;
		printf("\n----------------------------------------------------------------------------------\n");	
		printf("\t\tle produit est alimenter");
		printf("\n----------------------------------------------------------------------------------\n");	
	}
}

//-------------------------FONCTION QUI AFFICHE L'ETAT DE STOCK
void Achat()
{
	int nbrp,rech;
	float prix;
	rech=rechc();
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	printf("\n----------------------------------------------------------------------------------\n");	
	printf("\n\t\tVeuiller entrer la quantiter a achte : ");
	scanf("%d",&nbrp);
	printf("\n----------------------------------------------------------------------------------\n");	
	
	if (rech!=-1)
	{ 
	
		if(nbrp>P[rech].quan || nbrp<0)
		{
			printf("\n----------------------------------------------------------------------------------\n");	
			printf("\t\tDesole entre la quantite convenables ");
			printf("\n----------------------------------------------------------------------------------\n");	
			
		}else{
			A[indexA].dat.jour = tm.tm_mday;
            A[indexA].dat.mois = tm.tm_mon + 1;
            A[indexA].dat.annee = tm.tm_year + 1900;
			A[indexA].prix=P[rech].prix*nbrp;
			strcpy(A[indexA].nom,P[rech].nom);
			printf("le prix TTC du produit est: %.2f\n",A[indexA].prix);
			printf("la date de venteest: %d-%d-%d",A[indexA].dat.jour,A[indexA].dat.mois,A[indexA].dat.annee);
			P[rech].quan-=nbrp;
			printf("\nAchat reussie");
			indexA++;
			A[indexA].quan+=nbrp;
			
		}  
    }
	if(rech==-1)
    {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	printf("\t\tLe produit inexistant! ");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	}
}

//----------Afficher le total des prix des produits vendus en journée courante
void Tp()
{
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	int j,m,a;
	j=tm.tm_mday;
	m=tm.tm_mon + 1;
	a=tm.tm_year + 1900;
	float Mt=0;
	for(i=0;i<indexA;i++)
	{
		if(A[i].dat.jour==j && A[i].dat.mois==m && A[i].dat.annee==a)
		{
				Mt+=A[i].prix;
				
		}
	}
	printf("Le prix des produits vendus en journee courante %.2f",Mt);

}

//----------Afficher le moyenne des prix des produits vendus en journée courante
void MPrix(){
        int j , m , a;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
		float MP;
        j=tm.tm_mday;
		m=tm.tm_mon + 1;
		a=tm.tm_year + 1900;
		
        float d;
        float sumP = 0;
        int sumQty=0;
        for(i=0; i<=indexA; i++){
            if(A[i].dat.jour==j && A[i].dat.mois==m && A[i].dat.annee==a){
                sumP+=A[i].prix;
                sumQty+=A[i].quan;
            }

        }
        	MP=sumP/sumQty;

        printf("\nla moyenne des prix des produits vendus en journee courante %.2f",MP);
    }


void MaxPrix(){
        float maxP = A[0].prix;

        for(i=0; i<=indexA; i++){
            if(maxP < A[i].prix){
                maxP = A[i].prix;
            }
        }
        printf("\nle Max des prix des produits vendus en journee courante : %.2f",maxP);
    }

    void MinPrix(){
        float minP = A[0].prix;

        for(i=0; i<=indexA; i++){
            if(minP > A[i].prix){
                minP = A[i].prix;
            }
        }
        printf("\nle Min des prix des produits vendus en journee courante : %.2f",minP);
    }

//---------------------STATISTIQUE DE VENTE 
void stat()
{
	int choix;
	do{
		printf("\n------------------Statistique-------------------\n");
		printf("\t\t1-Afficher le total des prix des produits vendus en journee courante  \n   ");
		printf("\t\t2-Afficher la moyenne des prix des produits vendus en journee courante\n   ");
		printf("\t\t3-Afficher le Max des prix des produits vendus en journee courante \n   ");
		printf("\t\t4-Afficher le Min des prix des produits vendus en journee courante\n   ");
		printf("                       0-Quiter                        ");
		printf("\n---------------------------------------------------------\n");
		printf("\n \t\t\t Entrer votre choix: ");
		scanf("%d",&choix);
		switch(choix){
					case 1:
						Tp();
					break;
					
					case 2:
						MPrix();
					break;
					
					case 3:
						MaxPrix();
					break;
					
					case 4:
						MinPrix();
					break;
					
					case 0:
						printf(" ");
					break;
						
					default:
						printf("\n----------------------------------------------------------------------------------\n");	
						printf("\n\t\tVeuiller entrer un choix convenable.");
						printf("\n----------------------------------------------------------------------------------\n");	
					break;
		}
	}while(choix!=0);
}

	
	int choix;
	do
	{
	
	printf("\n\n\n\t\t------------------------ Menu Principal------------------------\n");
	
	puts("\t\t\t\t1-Ajouter un nouveau produit\n");
	puts("\t\t\t\t2-Ajouter plusieurs nouveaux produits\n");
	puts("\t\t\t\t3-Affichage\n");
	puts("\t\t\t\t4-Lister tous les produits\n");
	puts("\t\t\t\t5-Rechercher les produits\n");
	puts("\t\t\t\t6-Etat du stock\n");
	puts("\t\t\t\t7-Alimenter le stock\n");
	puts("\t\t\t\t8-Supprimer un produit\n");
	puts("\t\t\t\t9-Acheter produit\n");
	puts("\t\t\t\t10-Statistique de vente\n");
	puts("\t\t\t\t0-Quiter");
		
		do
		{	
			printf("\n\t    Entrer votre choix: ");
			scanf("%d",&choix);
			
			if(choix>10 || choix<0)
			{
				printf("Entrer un choix entre 1 et 11. \n");
		
			}		
		}while(choix>10 || choix<0);
		
		switch(choix)
		{
			case 1:{
				
				ajop();
			}break;
				break;
			case 2:{
				
				ajoplp();
				getch();
			}
				break;
			case 3:{
				
				aff();
			}
				break;
			case 4: {
				
				tri();
			}
				break;
			case 5:{
				
				rech();
			}
				break;
			case 6:{
				estock();
			}
				break;
			case 7:{
				
				alstock();
			}
				break;	
			case 8:{
				supr ();
			}
				break;
			case 9:{
				Achat();
			}
				break;
			case 10:{
				stat();
			}
				break;
			case 0:{
				
				printf("\n\n\n\n\n\n\n\n\n\n");
				printf("\t\t\t\tMerci d'etuliser mon programme");
				exit(0);
			}
				break;
			
			default:{
				printf("\n \t\t\t Erreur, entrer un choix entre 1 et 10");
			}
				break;			
		}
		
	}while(choix !=11);
	
	
}

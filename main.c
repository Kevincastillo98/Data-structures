#include <stdio.h>
#include <stdlib.h>
#include "MenuLS.h"
#include "listas_estatico.h"
#include "listas_dobles.h"
#include "Listas_Dobles_Estatico.h"
#include "listas_circulares_din.h"
#include "listas_circulares_estatico.h"
#include "pilas.h"
#include "pilas_estatico.h"
#include "colas.h"
#include "colas_estatico.h"
#include "colas_prio.h"
#include "colasprio_static.h"
#include "bicola_dinamico.h"
#include "staticBiColas.h"
#include  "arboles.h"
#include "grafos.h"
void main()
{
	int r,op,a;
	printf("\n\t\t      MENU PRINICIPAL     \n");
	printf("\n\t\t\t1. LISTAS\n\t\t\t2. PILAS\n\t\t\t3. COLAS\n\t\t\t4. ARBOLES\n\t\t\t5. GRAFOS\n");
	printf("\t\t\t5.SALIR\n");
	printf("\t\t\t\nOPCION:");
	scanf("%d",&r);
	system("cls");
	switch(r)
	{
		case 1:
			printf("\n\t    LISTAS    \n\n");
			printf(" 1. SIMPLES\n 2.DOBLES\n 3.CIRCULARES\n");
			printf("\nOPCION:");
			scanf("%d",&op);
			system("cls");
			switch(op)
			{
				case 1: //simples
				printf("\n\t   MENU LISTAS SIMPLES     \n\n");
				printf (" 1. DINAMICAS\n 2. ESTATICAS\n");
				printf("\nOPCION:");
				scanf("%d",&a);
				system("cls");
				switch(a)
				{
					case 1:menu_simples();break;
					case 2: menu_simples_estatico();break;
				}
				break;
				case 2: //dobles
				printf("\n\t\tMENU LISTAS DOBLEMENTE LIGADAS\n");
				printf(" 1.DINAMICAS\n 2.ESTATICAS\n");
				printf("\nOPCION:");
				scanf("%d",&a);
				system("cls");
				switch(a)
				{
					case 1: menu_listas_dobles();break;
					case 2: MenuLDL_Estatica();break;
				}
				break;
				case 3: //circulares
					printf("\nMENU LISTAS CIRCULARES\n\n");
					printf (" 1.DINAMICAS\n 2.ESTATICAS\n");
					printf("\nOPCION:");
					scanf("%d",&a);
					system("cls");
					switch(a)
					{
						case 1:	menuListasCirDin();break;
						case 2: menu_circulares_estatico();break;

					}
					break;
			}
			break;
		case 2:
			printf("\n\t\tMENU PILAS\n");
			printf(" 1.DINAMICAS\n 2.ESTATICAS\n");
			printf("\nOPCION:");
			scanf("%d",&op);
			system("cls");
			switch(op)
			{
				case 1: menu_pilas();break;
				case 2: menu_pilas_estatico();break;
			}
			break;
		case 3:
				printf("\n\t\tMENU COLAS\n");
				printf(" 1.COLAS SIMPLES\n 2.COLAS DOBLES\n 3.COLAS CON PRIORIDAD\n");
				printf("\nOPCION:");
				scanf("%d",&a);
				system("cls");
				switch(a)
				{
					case 1: //colas simples
							printf("\n\t\tMENU COLAS SIMPLES\n");
							printf(" 1.DINAMICO\n 2.ESTATICO\n");
                            printf("\nOPCION:");
							scanf("%d",&op);
							system("cls");
							switch(op)
							{
								case 1:	menu_colas();break;
								case 2:	menu_colas_estatico();break;
							}
						break;
					case 2: //colas dobles o bicolas
							printf("\n\t\tMENU COLAS DOBLEMENTE LIGADAS\n");
							printf(" 1.DINAMICO\n 2.ESTATICO\n");
							printf("\nOPCION:");
							scanf("%d",&op);
							system("cls");
							switch(op)
							{
								case 1:	menu_bicolas();break;
								case 2:	BiColasStaticMen();break;
							}
						break;
					case 3: //colas con prioridad
							printf("\n\t\tMENU COLAS CON PRIORIDAD\n");
							printf(" 1) DINAMICO\n 2.ESTATICO\n");
							printf("\nOPCION;");
							scanf("%d",&op);
							system("cls");
							switch(op)
							{
								case 1:	menu_colas_prio();break;
								case 2:	menu_colasprio_estatico();break;
							}
						break;
					case 5: exit(0);
					case 6: main();break;
				}
		case 4: printf("\nARBOLES\n");
		    menuArbBin();
		break;
		printf("\t\tGRAFOS\n");
		case 5:
		    menu_grafos();break;

	}
}

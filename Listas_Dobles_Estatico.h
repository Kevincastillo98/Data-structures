#include<string.h>

struct LDL
{
	struct LDL* LigaI;
	struct LDL* LigaD;
	char Info[200];
};
struct LDL_E
{
	int LigaI;
	int LigaD;
	char Info[200];
};
struct C
{
	char info;
	struct C* LigaI;
	struct C* LigaD;
};
void MenuLDL_Estatica();

void Algoritmo_1_E(int *c,struct LDL_E *p);
void Algoritmo_2_E(struct LDL_E* p,int c);
void Algoritmo_3_E(struct LDL_E* p,int *c);
void Algoritmo_4_E(struct LDL_E* p,int *c);
void Algoritmo_5_E(struct LDL_E* p,int *c);
void Algoritmo_6_E(struct LDL_E* p,int *c);
void Algoritmo_7_E(struct LDL_E* p,int *c);
void Algoritmo_8_E();



void MenuLDL_Estatica()
{
	struct LDL_E P[100];
	int Opcion,Contador=0,resp;

	do
	{
		printf("\t\tLISTAS DOBLEMENTE LIGADAS\n");
		printf("\t\tMEMORIA ESTATICA\n\n");
		printf("1.ALGORITMO QUE CREA UNA LDL INSERTANDO CADA ELEMENTO POR EL FINAL\n");
		printf("2.ALGORITMO QUE IMPRIME UNA LDL DE PRINCIPIO A FIN\n");
		printf("3.ALGORITMO QUE ELIMINA UN ELEMENTO CON INFORMACION DADA\n");
		printf("4.ALGORITMO QUE INSERTE UN ELEMENTO EN UNA LDL POR EL PRINCIPIO\n");
		printf("5.ALGORITMO QUE ELIMINE EL ULTIMO  ELEMENTO DE UNA LDL\n");
		printf("6.ALGORITMO QUE ELIMINE UN ELEMENTO ANTES DE UNO DADO COMO REFERENCIA\n");
		printf("7.ALGORITMO QUE INSERTA UN ELEMENTO DESPUES DE UNO DADO COMO REFERENCIA\n");
		printf("8.ALGORITMO QUE IDENTIFIQUE SI UN CONJUNTO DE CAACTERES ES UN PALINDROMO\n");
		printf("9.SALIR\n");
		printf("\nOPCION:");
		scanf("%d",&Opcion);
		system("cls");
		switch (Opcion)
		{
			case 1:
				Algoritmo_1_E(&Contador,P);
				break;
			case 2:
				Algoritmo_2_E(P,Contador);
				break;
			case 3:
				Algoritmo_3_E(P,&Contador);
				break;
			case 4:
				Algoritmo_4_E(P,&Contador);
				break;
			case 5:
				Algoritmo_5_E(P,&Contador);
				break;
			case 6:
				Algoritmo_6_E(P,&Contador);
				break;
			case 7:
				Algoritmo_7_E(P,&Contador);
				break;
			case 8:
				Algoritmo_8_E();
				break;
			case 9:
			exit(0);
			break;
		}
		printf("\nDESEA HACER OTRA ACCION? SI=1 N0=2:");
		scanf("%d",&resp);
		system("cls");
	}while(resp==1 || Opcion!=9);

}

void Algoritmo_1_E(int *c,struct LDL_E *p)
{
	int opcion;
	*c=0;

	(*c)++;
	p[0].LigaI=-1;
	p[0].LigaD=-1;
	printf("INGRESAR INFROMACION:");
	fflush(stdin);gets(p[0].Info);

	printf("DESEA AGREGAR MAS ELEMENTOS? SI=1 NO=2:");
	fflush(stdin);
	scanf("%d",&opcion);
	while (opcion==1)
	{

		p[*c].LigaI=(*c)-1;
		p[*c].LigaD=-1;
		p[(*c)-1].LigaD=*c;
		printf("INGRESAR INFORMACION:");
		fflush(stdin);
		gets(p[*c].Info);
		(*c)++;
		if(*c>=100)
		{
			printf("\nSE LLEGO AL MAXIMO DE ELEMENTOS\n\n\t");
			system("pause");
			break;
		}
		else
		{
			printf("DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=0:");
			fflush(stdin);
			scanf("%d",&opcion);
		}
	}
}

void Algoritmo_2_E(struct LDL_E *p,int c)
{
	int i;
	if (c==0)
	{
		printf("\nLA LISTA ESTA VACIA\n\n");
	}
	else
	{
		for(i=0;i<c;i++)
		{
			printf("%s<->",p[i].Info); //corregido
		}
		printf("<->");
	}
	printf("NULL");
	printf("\n\t");
	system("pause");
}

void Algoritmo_3_E(struct LDL_E* p,int *c)
{
	char Buscar[200];
	int x=0,i,j;
	if(*c==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
		printf("\nELEMENTO A BORRAR:");
		fflush(stdin);gets(Buscar);

		for(i=0;i<*c;i++)
		{
			if(strcmp(p[i].Info,Buscar)==0)
			{
				for(j=i;j<*c;j++)
				{
					p[j]=p[j+1];
					p[j].LigaD--;
					p[j].LigaI--;
				}
				(*c)--;
				p[(*c)-1].LigaD=-1;
				x=1;
				break;
			}
		}
		if(x==0)
		{
			printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
		}
		else
		{
			printf("\nEL ELEMENTO SE BORRO CORRECTAMENTE\n");
		}
	}
	printf("\n\n\t");
	system("pause");
}

void Algoritmo_4_E(struct LDL_E* p,int *c)
{
	int i;

	if (*c==0)
	{
		(*c)++;
		p[0].LigaI=-1;
		p[0].LigaD=-1;
		printf("INSERTAR INFROMACION:");
		fflush(stdin);gets(p[0].Info);
	}
	else
	{
		for(i=(*c)-1;i>=0;i--)
		{
			p[i+1]=p[i];
			p[i+1].LigaD++;
			p[i+1].LigaI++;
		}
		(*c)++;
		p[(*c)-1].LigaD=-1;
		p[0].LigaI=-1;
		p[0].LigaD=1;

		printf("INSERTAR INFROMACION:");
		fflush(stdin);gets(p[0].Info);
	}
	printf("\n ELEMENTO INSERTADO\n\n");
	system("pause");

}

void Algoritmo_5_E(struct LDL_E* p,int *c)
{

	if(*c==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
		(*c)--;
		if(*c!=0)
		{
			p[(*c)-1].LigaD=-1;
		}
		printf("\nULTIMO ELEMENTO BORRADO CORRECTAMENTE\n");
	}
	printf("\n\n\t");
	system("pause");
}

void Algoritmo_6_E(struct LDL_E* p,int *c)
{
	char Buscar[200];
	int x=0,i,j;

	if(*c==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
		printf("\nELEMENTO A BUSCAR:");
		fflush(stdin);gets(Buscar);

		for(i=0;i<*c;i++)
		{
			if(strcmp(p[i].Info,Buscar)==0)
			{
				if(i==0)
				{
					printf("\n NO EXISTE ELEMENTO A ELIMINAR\n");
					x=2;
				}
				else
				{
					for(j=i-1;j<*c;j++)
					{
						p[j]=p[j+1];
						p[j].LigaD--;
						p[j].LigaI--;
					}
					(*c)--;
					p[(*c)-1].LigaD=-1;
					x=1;
					break;
				}
			}
		}
		if(x==0)
		{
			printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
		}
		else
		{
			if(x==1)
			{
				printf("\nELEMENTO BORRADO CORRECTAMENTE\n");
			}
		}
	}
	printf("\n\n\t");
	system("pause");
}

void Algoritmo_7_E(struct LDL_E* p,int *c)
{
	int i,j,x;
	char Buscar[200];

	if(*c==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
		printf("\nELEMENTO A BUSCAR:");
		fflush(stdin);gets(Buscar);

		for(i=0;i<*c;i++)
		{
			if(strcmp(p[i].Info,Buscar)==0)
			{
				for(j=(*c)-1;j>i;j--)
				{
				p[j+1]=p[j];
				p[j+1].LigaD++;
				p[j+1].LigaI++;
				}
				(*c)++;
				p[i+1].LigaI=i;
				p[i+1].LigaD=i+2;

				printf("\nINSERTAR INFROMACION:");
				fflush(stdin);gets(p[i+1].Info);
				p[(*c)-1].LigaD=-1;
				x=1;
				break;
			}
		}
	}
	if(x==0)
	{
		printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
	}
	else
	{
		printf("\nELEMENTO INSERTADO CORRECTAMENTE");
	}
	printf("\n\n\t");
	system("pause");
}

void Algoritmo_8_E()
{
	char palabra[200];
    int i, j;
    int palindromo = 1;
    system("cls");
    printf("INSERTAR CADENA:");
    fflush(stdin);
    gets(palabra);
    j=strlen(palabra)-1;
    for(i=0; i<strlen(palabra)/2; i++, j--) {
        if (*(palabra+i)!=*(palabra+j)) {
            palindromo = 0;
            break;
        }
    }
    if (palindromo)
        printf("\nES UN PALINDROMO\n\n");
    else
        printf("\nNO ES UN PALINDROMO\n\n");
    system("pause");
}

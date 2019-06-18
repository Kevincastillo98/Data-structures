typedef struct nodof
{
	int info;
	struct nodof *liga;
}nod;

void menuListasCirDin();
void Crear_por_el_final();
void borra_elemento_posterior_a_uno_dado();
void elimina_primer_elemento();
void imprime_lista();
void buscar_imprimir_direccion_posterior();
void  inserta_al_principio();
void borrar();
void  inserta_despues();
nod *p=NULL, *q=NULL, *r=NULL, *s=NULL;

void menuListasCirDin(){
	int opc,resp;
	
	
 	
	  do{
	 	printf("\n\t\tLISTAS CIRCULARES\n");
	 	printf("\t\tMEMORIA DINAMICA\n\n");
	    printf(" 1. INSERTAR POR EL FINAL\n");
	    printf(" 2. ELIMINAR UN ELEMENTO DESPUES DE UNA REFERENCIA\n");
	    printf(" 3. ELIMINA PRIMER ELEMENTO\n");
	    printf(" 4. IMPRIMIR\n");
	    printf(" 5. BUSCAR ELEMENTO X E IMPRIMIR LA DIRECCION DEL ELEMENTO ANTECEDENTE Y LA INFO DEL SUCESOR\n");
	    printf(" 6. INSERTAR POR EL INICIO X\n");
	    printf(" 7. ELIMINAR UN ELEMENTO\n");
	    printf(" 8. INSERTAR UN ELEMENTO ANTES DE UNA REFERENCIA X\n"); //REVISAR
	    printf(" 9. SALIR\n\n");
	    printf(" SELECCIONA UNA OPCION: ");
	    scanf("%d",&opc);
	    system("cls");
	    switch(opc)
		  	{
		  		case 1: Crear_por_el_final();
						imprime_lista();
		         break;
		  		case 2: borra_elemento_posterior_a_uno_dado();
						imprime_lista();
		  		break;
		  		case 3: elimina_primer_elemento();
						imprime_lista();
				break;
		  		case 4: imprime_lista(); break;
		  		case 5:buscar_imprimir_direccion_posterior();
					imprime_lista();
		  		break;
				case 6:inserta_al_principio();
				imprime_lista();
				break;
				case 7:borrar();
				imprime_lista();
				break;
				case 8:inserta_despues();
				imprime_lista();
				break;
		  		case 9: exit(0); break;
		  	}
		printf("\nDESEA HACER OTRA ACCION? SI=1 N0=2:");
		scanf("%d",&resp);
		system("cls");
	}while(resp==1 || opc!=9);

}


//1._Algoritmo que crea una lista circular insertando cada elemento por el final
void Crear_por_el_final(){
	int opcion;
	p=(nod*)malloc(sizeof(nod));
	printf("ELEMENTO A INSERTAR:");
	scanf("%d", &p->info);
	p->liga=p;
	q=p;
	printf("DESEAS INSERTAR OTRO ELEMENTO? SI=1 NO=2:");
	scanf("%d", &opcion);
	while(opcion==1)
	{
		q->liga=(nod*)malloc(sizeof(nod));
		q=q->liga;
		printf("ELEMENTO A INSERTAR:");
		scanf("%d", &q->info);
		q->liga=p;
		printf("DESEAS INSERTAR OTRO ELEMENTO? SI=1 NO=2:");
		scanf("%d", &opcion);
	}
}

//2.Algoritmo que borra un elemento posterior a uno dado como referencia
void borra_elemento_posterior_a_uno_dado(){
	int opcion, dato;
	if(p==NULL)
	{
		printf("LA LISTA ESTA VACIA\n");
	}
	else
	{
		printf("ELEMENTO DADO COMO REFERENCIA:");
		scanf("%d", &dato);
		if(p->liga==p && p->info==dato)
		{
			free(p);
			p=NULL;
		}
		else
		{
			q=p;
			while(q->liga!=p && q->info!=dato)
			{
				q=q->liga;
				r=q->liga;
			}
			if(q->info!=dato)
			{
				printf("EL ELEMENTO NO EXISTE\n");
			}
			else
			{
				if(q->liga==p)
				{
					p=r->liga;
					free(r);
					r=NULL;
				}
				else
				{
					q->liga=r->liga;
					free(r);
					r=NULL;
				}
			}
		}
	}
}


//3._Algoritmo que elimina el primer elemento en un alista circular
void elimina_primer_elemento()
{
	if(p==NULL)
	{
		printf("LISTA VACIA\n");
	}
	else
	{
		q=p;
		while(q->liga!=p)
		{
			q=q->liga;
		}
		if(p!=q)
		{
			p=p->liga;
			free(q->liga);
			q->liga=p;
		}
		else
		{
			free(p);
			p=NULL;
		}
	}
}


//4._Algoritmo que imprime una lista circular
void imprime_lista()
{
	if(p==NULL)
	{
		printf("LISTA VACIA\n");
	}
	else
	{
		q=p;
		printf("LISTA\n");
		while(q->liga!=p)
		{

			printf("%d->", q->info);
			q=q->liga;
		}
		printf("%d->PRIMERO\n", q->info);
	}
}

/*5._Algoritmo que busca un elemento con información "X"
e imprime direccion del elemento antecedente e información del
elemento consecuente
*/
void buscar_imprimir_direccion_posterior()
{
	int x;
	if(p==NULL)
	{
		printf("LISTA VACIA\n");
	}
	else
	{
		printf("ELEMENTO A BUSCAR:\n");
		scanf("%d", &x);
		if(p->liga==p && p->info==x)
		{
			printf("DIRECCION:%p\n", p);
			printf("ELEMENTO:%d\n", p->info);
		}
		else
		{
			q=p;
			while(q->info!=x && q->liga!=p)
			{
				r=q;
				q=q->liga;
			}
			if(q->info!=x)
			{
				printf("EL ELEMENTO NO EXISTE\n");
			}
			else
			{
				if(q!=p)
				{
					printf("DIRECCION: %p\n", r);
					printf("ELEMENTO: %d\n", q->liga->info);
				}
				else
				{
					while(q->liga!=p)
					{
						q=q->liga;
					}
					printf("DIRECCION: %p\n", q);
					printf("ELEMENTO: %d\n", p->liga->info);
				}
			}
		}
	}
}


/*6._Algoritmo que inserte un elemento al principio de una lista
circular*/
void  inserta_al_principio()
{
	int opcion;

		if(p==NULL)
		{
			p=(nod*)malloc(sizeof(nod));
			p->liga=p;
			printf("ELEMENTO A INSERTAR: ");
			scanf("%d", &p->info);
		}
		else
		{
			q=p;
			while(q->liga!=p)
			{
				q=q->liga;
			}
			do
			{
			r=(nod*)malloc(sizeof(nod));
			q->liga=r;
			r->liga=p;
			p=r;
			r=NULL;
			printf("ELEMENTO A INSERTAR:");
			scanf("%d", &p->info);
			printf("DESEAS INSERTAR MAS ELEMENTOS? SI=1 NO=2:");
			scanf("%d", &opcion);
			}while(opcion==1);
		}

}


/*7._Algortimo que borre un elemento con información "X" en una
 * lista circular*/

void borrar()
{
	int x;
	printf("ELEMENTO A ELIMINAR:");
	scanf("%d", &x);
	if(p==NULL)
	{
		printf("LISTA VACIA\n");
	}
	else
	{
		if(p->liga==p)
		{
			free(p);
			p=NULL;
		}
		else
		{
			q=p;
			while(q->liga!=p && q->info!=x)
			{
				s=q;
				q=q->liga;
			}
			if(q->info!=x)
			{
				printf("EL ELEMENTO %d NO ESTA EN LA LISTA\n", x);
			}
			else
			{
				if(q->liga==p)
				{
					r=p;
					p=r->liga;
					q->liga=p;
					free(r);
					r=NULL;
				}
				else
				{
					if(q->info==x)
					{
						s->liga=q->liga;
						free(q);
					}
				}
			}
		}
	}
}


/*8._Algoritmo que inserta un elemento después de uno dado como referencia en una
lista circular*/

void  inserta_despues(){
	int opcion, dato;
	if(p==NULL)
	{
		p=(nod*)malloc(sizeof(nod));
		p->liga=p;
		printf("ELEMENTO A INSERTAR:");
		scanf("%d", &p->info);
	}
	else
	{
		printf("ELEMENTO DADO COMO REFERENCIA:");
		scanf("%d", &dato);
		if(p->liga==p)
		{
			q=(nod*)malloc(sizeof(nod));
			q->liga=p;
			p->liga=q;
			printf("ELEMENTO A INSERTAR:");
			scanf("%d", &q->info);
			p=q;
		}
		else
		{
			if(p->info==dato)
			{
				q=p;
				while(q->liga!=p)
				{
					q=q->liga;
				}
				r=(nod*)malloc(sizeof(nod));
				q->liga=r;
				r->liga=p;
				printf("ELEMENTO A INSERTAR:");
				scanf("%d", &r->info);
				p=r;
			}
			else
			{
				q=p;
				while(q->liga!=p && q->info!=dato)
				{
					r=q;
					q=q->liga;
				}
				if(q->info!=dato)
				{
					printf("EL ELEMENTO NO EXISTE\n");
				}
				else
				{
					s=(nod*)malloc(sizeof(nod));
					r->liga=s;
					s->liga=q;
					printf("ELEMENTO A INSERTAR:");
					scanf("%d", &s->info);
				}
			}
		}
	}
}




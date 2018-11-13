	struct nodo
	{
		int info;
		struct nodo *liga;
	};
void eliminarUltimo(struct nodo *nodos);
void menu_simples();
struct nodo* add();
void leerlistadinamico(struct nodo *nodos);
void busqueda(struct nodo *nodos);
struct nodo* insertarAntes(struct nodo *nodos);//9
void insertarDespues(struct nodo *nodos);//10
void inserta_un_elemento_al_final(struct nodo *nodos);
struct nodo* crear_lista_por_el_final();
struct nodo* borra_elemento_final(struct nodo *nodos); //8
struct nodo* eliminar_nodo_antes_dado_uno_como_ref(struct nodo *nodos); //11
void eliminar_nodo_dado_uno_como_ref(struct nodo *nodos);//12
struct nodo* insertarInicio(struct nodo *nodos);

void menu_simples()
{
	struct nodo *S;
	//S=NULL;
	int resp;
	int r;
	do{
		printf("\t\tMENU LISTAS SIMPLES\n");
		printf("\t\tMEMORIA DINAMICA\n\n");
		printf("1.CREAR UNA LISTA AGREGANDO CADA NODO AL INICIO\n");
		printf("2.RECORRER E IMPRIME EL CONTENIDO DE UNA LISTA\n");
		printf("3.BUSCAR UN ELEMENTO CON CIERTA INFORMACION\n");
		printf("4.INSERTA SOLO UN ELEMENTO AL FINAL DE UNA LISTA\n");
		printf("5.ELIMINA EL ULTIMO ELEMENTO DE LA LISTA\n");
		printf("6.INSERTA SOLO UN ELEMENTO POR EL PRINCIPIO\n");
		printf("7.CREA UNA LISTA POR EL FINAL\n");
		printf("8.BORRA UN ELEMENTO POR EL PRINCIPIO\n");
		printf("9.INSERTA UN NODO ANTES DE  UNO DADO COMO REFERENCIA\n");
		printf("10.INSERTA UN NODO DESPUES DE UNO DADO COMO REFERENCIA\n");
		printf("11.ELIMINA  UN NODO ANTES DE UNO DADO COMO REFERENCIA\n");
		printf("12.ELIMINA UN NODO DESPUES DE UNO DADO COMO REFERENCIA\n");
		printf("13.SALIR\n");
		printf("\nOPCION:");
		scanf("%d",&resp);
		system("cls");
		switch(resp)
		{
			case 1: S=add();break;
			case 2: leerlistadinamico(S);break;
			case 3:	busqueda(S);break;
			case 4: inserta_un_elemento_al_final(S);break;
			case 5: eliminarUltimo(S);break;
			case 6: S=insertarInicio(S);break;
			case 7: S=crear_lista_por_el_final();break;
			case 8: S=borra_elemento_final(S);break;
			case 9: S=insertarAntes(S);break;
			case 10: insertarDespues(S);break;
			case 11: S=eliminar_nodo_antes_dado_uno_como_ref(S);break;
			case 12: eliminar_nodo_dado_uno_como_ref(S);break;
			case 13: exit(0);
		}
		printf("\nDESEA HACER OTRA ACCION? SI=1 N0=2:");
		scanf("%d",&r);
		system("cls");

	}while(r==1||resp!=13);
}
//Algoritmo1
struct nodo* add(){
	struct nodo *P,*Q;
	P=NULL;//apunta al primer elemento de la lista
	int resp;

	/*reservamos memoria para el nuevo elemento con malloc*/
	P=(struct nodo *) malloc (sizeof(struct nodo));
	printf("ELEMENTO:"); fflush(stdout);
	scanf("%d",&P->info);
	P->liga=NULL;
	printf("DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=2:");
	fflush(stdin);
	scanf("%d",&resp);
	while(resp==1)
	{
		Q=(struct nodo *) malloc (sizeof(struct nodo));
		printf("ELEMENTO:"); fflush(stdout);
		scanf("%d",&Q->info);
		Q->liga=P;
		P=Q;
		printf("DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=2:" );
		scanf("%d",&resp);
		}
		return P;
}
//Algoritmo 2
void leerlistadinamico(struct nodo *nodos){
	
	if(nodos==NULL) //por alguna razon si no hay elementos me arroja un 1.
	{
		printf("\nLISTA VACIA\n");
	}
	else	
	{
		
		while(nodos!=NULL)
		{
			printf("%d->",nodos->info);
			nodos=nodos->liga;
		}
		printf("NULL\n");
	}
}
//Algoritmo 3
void busqueda(struct nodo *nodos)
{
	struct nodo *P, *a;
	P=nodos;
	int b;

	if(P==NULL){
		printf("\nLISTA VACIA");
		return;
	}
	else{
		printf("\n\nELEMENTO A BUSCAR:");
		scanf("%d",&b);
		a=P;
		while(a->info!=b && (a->liga)!=NULL){
			a=a->liga;
		}
		if(a->info==b){
			printf("\nEL ELEMENTO SI ESTA EN LA LISTA\n");
		}
		else{
			printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
		}
	}
}

void inserta_un_elemento_al_final(struct nodo *nodos){
	struct nodo *P,*a,*Q;
	P=nodos;

	if(nodos==NULL)
	{
		printf("LA LISTA ESTA VACIA\n");
		P=(struct nodo *) malloc (sizeof(struct nodo));
		printf("ELEMENTO:"); fflush(stdout);
		scanf("%d",&P->info);
		P->liga=NULL;
	}
	else
	{
		Q=P;
		while(nodos->liga!=NULL)
	{
		nodos=nodos->liga;
	}
		a=(struct nodo *) malloc (sizeof(struct nodo));
		printf("ELEMENTO:"); fflush(stdout);
		scanf("%d",&a->info);
		a->liga=NULL;
		nodos->liga=a;
	}
}
//Algoritmo 7
struct nodo* crear_lista_por_el_final(){
	struct nodo *P,*Q,*A;
	P=NULL;
	char resp;
	P=(struct nodo *) malloc (sizeof(struct nodo));
	printf("ELEMENTO:"); fflush(stdout);
	scanf("%d",&P->info);
	P->liga=NULL;
	A=P;
	printf("DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=2:");
	fflush(stdin);
	scanf("%d",&resp);
	while(resp==1)
	{
		Q=(struct nodo *) malloc (sizeof(struct nodo));
		printf("ELEMENTO:"); fflush(stdout);
		scanf("%d",&Q->info);
		A->liga=Q;
		A=A->liga;
		Q->liga=NULL;

		printf("DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=2:" );
		scanf("%d",&resp);
		}
		return P;
}
//Algoritmo 12
void eliminar_nodo_dado_uno_como_ref(struct nodo *nodos){
	struct nodo *a,*p,*q;
	p=nodos;
	int b;

	if(p==NULL){
		printf("\nLISTA VACIA\n");
	}
	else{
		printf("\nELEMENTO DADO COMO REFERENCIA:");
		scanf("%d",&b);
		if(p->info==b && p->liga==NULL)
		{
			printf("SOLO HAY UN NODO, NO SE PUEDE ELIMINAR NADA\n");
		}
		else if(p->info==b){
			//es el primero
			a=p->liga;
			p->liga=a->liga;
			free(a);
		}
		else{
			a=p;
		    while(a->info!=b && a->liga!=NULL){
			    a=a->liga;
		    }
		    if(a->info!=b)
		    {
		    	printf("NO SE ENCONTRÓ EL ELEMENTO %d \n",b);
			}
		    if(a->info==b && a->liga==NULL){
			    printf("\n\nNO SE PUEDE ELIMINAR EL SIGUIENTE ELEMENTO PORQUE NO EXISTE\n");
		    }
		    else if(a->info==b && a->liga->liga==NULL){//penultimo
			    q=a;
			    q=q->liga;
			    free(q);
			    a->liga=NULL;
		    }

		}
	}
}
void insertarDespues(struct nodo *nodos)
{
	struct nodo *temp,*P,*Q,*nuevo;
	int a;
	temp = nodos;
	printf("ELEMENTO DADO COMO REFERENCIA:");
	scanf("%d",&a);

	if (nodos == NULL){
		printf("LISTA VACIA\n\n");
	}
	else{

		while( (nodos->liga != NULL) && (nodos->info!=a) )
		{
			Q=nodos;
			nodos=nodos->liga;//no quitar
		}
		if(nodos->info==a)
		{
			printf("ELEMENTO ENCONTRADO\n");
			temp = nodos;
			nuevo=(struct nodo *)malloc(sizeof(struct nodo));
			//guardar nuevos datos
			printf("ELEMENTO:"); fflush(stdout);
			scanf("%d",&nuevo->info);
			nuevo->liga=nodos->liga;
			nodos->liga=nuevo;
		}
		else
		{
			printf("EL ELEMENTO NO ESTA EN LA LISTA\n");
		}
	}
}
//9

struct nodo* insertarAntes(struct nodo *nodos)
{
	struct nodo *nuevo,*Q,*P;
	P=nodos;
	int a;

	if (nodos==NULL){
		printf("LISTA VACIA\n\n");
	}

	else
	{
		printf("ELEMENTO DADO COMO REFERECNIA:");
		scanf("%d",&a);


	if (P->info==a)
	{


		printf("EL ELEMENTO ES EL PRIMERO\n");
		nuevo=(struct nodo *)malloc(sizeof(struct nodo));
		//guardar nuevos datos
		printf("ELEMENTO:"); fflush(stdout);
		scanf("%d",&nuevo->info);
		nuevo->liga=nodos;
		nodos=nuevo;
		return nodos;//nuevo principio
	}

	else{
		while( (P->liga != NULL) && (P->info!=a) )
		{
			Q=P;
			P=P->liga;//no quitar
		}
		if(P->info==a)
		{
			printf("EL ELEMENTO SE ENCONTRO EN LA LISTA\n");
			nuevo=(struct nodo *)malloc(sizeof(struct nodo));
			//guardar nuevos datos
			printf("ELEMENTO:"); fflush(stdout);
			scanf("%d",&nuevo->info);
			nuevo->liga=P;
			Q->liga=nuevo;
		}
		else
		{
			printf("EL ELEMENTO NO ESTA EN LA LISTA\n");
		}
	}
	}
	return nodos;
}
//Algoritmo 8
struct nodo* borra_elemento_final(struct nodo *nodos)
{
	struct nodo *P,*Q,*aux;
	P=nodos;
		if(P!=NULL)
		{

			if(P->liga==NULL)
			{
				free(P);
				printf("SOLO HABIA UN NODO Y AHORA  LA LISTA ESTA VACIA\n\n");
				return NULL;
			}
			else
			{
				aux=P;
				P=P->liga;
				free(aux);
				return P;
			}
		}
		else
		printf("LA LISTA ESTA VACIA\n\n");
	}
//Algoritmo 11
struct nodo* eliminar_nodo_antes_dado_uno_como_ref(struct nodo *nodos){
		struct nodo *P,*A,*aux,*a,*s;
	P=nodos;
	int b;
	if(P==NULL){
		printf("\nLISTA VACIA\n");
		return NULL;
	}
	else{
		printf("\nELEMENTO DADO COMO REFERENCIA:");
		scanf("%d",&b);
		if(P->info==b && P->liga==NULL)
		{
			printf("SOLO HAY UN NODO,NO SE PUEDE ELIMINAR NADA\n");
		}
		else if(P->info==b){
			//es el primero
			printf("ES EL PRIMER NODO, NO SE PUEDE ELIMINAR NADA\n");
		}
		else if(P->liga->info==b) //es el segundo
			{
				aux=P;
				P=P->liga;
				free(aux);
			}
		else
		{
			a=P;
			s=a;
		    while(a->info!=b && a->liga!=NULL){
				s=aux;//para estar antes del auxiliar
		    	aux=a; //para estar antes del nodo
			    a=a->liga;
		    }
			if(a->info!=b)
			{
				printf("NO EXISTE EL ELEMENTO %d\n",b);
			}
			else
			{
				s->liga=a;
		   	free(aux);
					}

		}
	}
		return P;

	}
//Algoritmo 5
void eliminarUltimo(struct nodo *nodos)
{
	struct nodo *P,*Q,*T;
	P=nodos;
	if(P == NULL){
printf("LA LISTA ESTA VACIA\n");
}
else{
Q = P;
		if(P->liga == NULL){
		P = NULL;
	}
		else{
		  while(Q->liga != NULL){
			 T =Q;
			 Q = Q->liga;
		  }
		}
		T->liga = NULL;
 }
free(Q);
}
//Algoritmo 6
struct nodo* insertarInicio(struct nodo *nodos){
	struct nodo *P,*Q;
	P=nodos;
  if(P == NULL){
    printf("LISTA VACIA\n");
  }
  else{
  	Q=(struct nodo *)malloc(sizeof(struct nodo));
    printf("ELEMENTO:"); fflush(stdout);
	scanf("%d",&Q->info);
   	Q->liga=P;
   	P=Q;

  }
}

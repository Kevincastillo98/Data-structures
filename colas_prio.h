//construccion de estructura 
typedef struct nodo_colas_prio{
	int info;
	int prio;
    struct nodo_colas_prio *liga;
}nodo_colas_prio;
//Declaracion de funciones
void leercolaprio(nodo_colas_prio *nodos);
nodo_colas_prio* elimina_cola_prio(nodo_colas_prio *nodos);
nodo_colas_prio* inserta_cola_conprio();
void menu_colas_prio();
//inicio de funciones
nodo_colas_prio* inserta_cola_conprio() //inserta elementos a un nodo y los acomoda con prioridad
{
	nodo_colas_prio *P,*Q,*A,*aux,*F;
	P=NULL; //la iniciamos
	int r;
	int i=0;
	P=(nodo_colas_prio *) malloc (sizeof(nodo_colas_prio));
	printf("ELEMENTO:");
	scanf("%d",&P->info);
	printf("PRIORIDAD:");
	scanf("%d",&P->prio);
	P->liga=NULL;
	F=P; //siempre está al ultimo elemento
	A=P;
	printf("DESEA CONTINUAR? SI=1 NO=2:");
	fflush(stdin);
	r=getchar();
	while(r==1)
	{
		Q=(nodo_colas_prio *) malloc (sizeof(nodo_colas_prio));
		printf("ELEMENTO:");
		scanf("%d",&Q->info);
		printf("PRIORIDAD:");
		scanf("%d",&Q->prio);
		if(Q->prio>P->prio)
		{
			if(P->liga==NULL) //Unico nodo
			{
				P->liga=Q;
				F=Q;
				F->liga=NULL; //apunta al final	
			}
			else 
			{
				if(Q->prio>P->prio && Q->prio>F->prio)//al final
				{
					F->liga=Q;
					F=Q;
					F->liga=NULL;
				}
				if(Q->prio>P->prio && Q->prio<F->prio) //que este entre P y F
				{
					A=P;
					aux=P;
					while(A->prio<Q->prio)
					{
						aux=A;
						A=A->liga; //movemos y leemos
					}
					Q->liga=A;
					aux->liga=Q;					
				}
			}
		
		}
		else
		{
			if(P->liga==NULL) //se inserte al primer elemento
			{
				P=Q;
				Q->liga=A;
			}
			else
			{
				if(Q->prio<P->prio) //que sea menor al primero
				{
					Q->liga=P;
					P=Q;
				}	
			}	
		}
		printf("\n\nDESEA INSERTAR MAS ELEMENTOS? SI=1 NO=0:" );
		fflush(stdin);
		scanf("%d",&r);
	}
	return P;
}

void leercolaprio(nodo_colas_prio *nodos)
{
	nodo_colas_prio *Q;
	Q=nodos;
	if(nodos==NULL) 
	{
		printf("COLAS CON PRIORIDAD VACIA\n");
	}
	else	
	{
		Q=nodos;
		while(nodos!=NULL)
		{
			printf("|%d||%d|->",nodos->info,nodos->prio);
			nodos=nodos->liga;
		}
		printf("NULL\n");
	}
}
nodo_colas_prio* elimina_cola_prio(nodo_colas_prio *nodos){
	nodo_colas_prio *P,*aux;
	P=nodos;
	printf("\t\tELIMINA DESDE EL PRINCIPIO\n");
	if(nodos==NULL) //no hay elementos
	{
		printf("LA COLA ESTA VACIA\n");
	}
	else 
	{
		if (nodos->liga==NULL) //solo hay un elemento
		{
			free(nodos);
			printf("SOLO HAY UN NODO,NO SE PUEDE ELIMINAR\n");
			nodos=NULL;
			return nodos;
		}
		else 
		{
			aux=nodos; //se pone en la primera posicion(el elemento más pequeño)
			nodos=nodos->liga;
			free(aux);
			printf("LA PRIORIDAD MAS PEQUEÑA ELIMINADA\n");
		}
	}

	return nodos; //nuevo principio	
}

void menu_colas_prio()
{
	int resp;
	nodo_colas_prio *S;
	S=NULL; //la inicializamos
	do
	{
		printf("\n\t\tCOLAS CON PRIORIDAD");
		printf("\n\t\tMEMORIA DINAMICA\n\n");	
		printf("1) INSERTAR ELEMENTOS EN UNA COLA CON PRIORIDAD\n");
		printf("2) LEER UNA COLA CON PRIORIDAD\n");
		printf("3) ELIMINAR ELEMENTO EN UNA COLA CON PRIORIDAD\n");
		printf("4) SALIR\n");
		printf("\nOPCION:");
		scanf("%d",&resp);
		system("cls");
		switch(resp)
		{
			case 1: S=inserta_cola_conprio();break;
			case 2:	leercolaprio(S);break;
			case 3:	S=elimina_cola_prio(S);break;
			case 4: exit(0);break;
		}
		system("cls");
	}while( resp!=4);
	
}
	


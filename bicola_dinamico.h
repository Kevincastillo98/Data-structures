typedef struct Listai{
	struct Listai *LigaD;
	int info;
	struct Listai *LigaI;
} nodoi;
void menu_bicolas();
void menu_bsr();
void menu_ber();
nodoi *insertafinal();
nodoi *insertaprincipio();
nodoi *construirNodo2(void);
void imprimirz(nodoi *,nodoi *);
nodoi *popD(nodoi*,nodoi*);
nodoi *popI(nodoi*);

//inicio de funciones
nodoi *insertaprincipio()
{
	nodoi *P,*F,*Q;
	int r;
	P=NULL;
	F=NULL;
	P=construirNodo2(); //creamos a P
	printf("ELEMENTO:");
	scanf("%d",&P->info);
	P->LigaD=NULL; //le decimos que es el final del nodo
	F=P; //P es igual a F
	printf("\nDESEA INSERTAR MAS NODOS? SI=1 NO=0:");
    scanf("%d",&r);
	while(r==1){
	//PUSH	
	Q=construirNodo2(); //creamos a Q
	Q->LigaD = P;
	P->LigaI = Q;
	Q->LigaI  = NULL;
	P = Q;
	printf("ELEMENTO:");
	scanf("%d",&P->info);
	printf("\n DESEA INSERTAR MAS NODOS? SI=1 NO=0:");
    scanf("%d",&r);
	}
	return P;
}
nodoi *insertafinal()
{
	nodoi *P,*F;
	P=NULL;
	F=NULL;	
	int r;
	P=construirNodo2(); //creamos a P
	printf("ELEMENTO:");
	scanf("%d",&P->info);
	P->LigaD=NULL; //le decimos que es el final del nodo
	F=P; //P es igual a F
	printf("\n DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=0:");
    scanf("%d",&r);
	while(r==1){
	//PUSH	
	F->LigaD=construirNodo2(); //creamos a f->LigaD
	F->LigaD->LigaI=F;
	F=F->LigaD;
	F->LigaD=NULL;
	printf("ELEMENTO:");
	scanf("%d",&F->info);
	printf("\nDESEA INSERTAR MAS ELEMENTOS? SI=1 NO=0:");
    scanf("%d",&r);
	}
	return P;
}
void menu_bsr()
{
	nodoi *P,*F;
	int opc1,r;
	do
	{
		system("pause");
		system("cls");
		printf("\n\t\tBICOLAS DE SALIDA RESTRINGIDA\t");
		printf("\n\t\tMEMORIA DINAMICA\n\n");
	    printf(" 1. PUSH \n");
	    printf(" 2. POP\n");
	    printf(" 3. IMPRIMIR\n");
	    printf(" 4. SALIR A MENU PRINCIPAL\n");
	    printf(" 5. SALIR DEL PROGRAMA\n");
	    printf(" SELECCIONA UNA OPCION: ");
	  	scanf("%d",&opc1);
	  	system("cls");
	  	switch(opc1)
	  	{
	  		case 1: 
	  			printf("LA INSERSION SERA POR FRENTE = 1 O FINAL= 2\n");
	  			scanf("%d",&r);
	  			if(r==2)
	  			{
	  				P=insertafinal();
				}
				if(r==1)
				{
					P=insertaprincipio();
				}
			break;
			case 2: P=popI(P);break;
			case 3: imprimirz(P,F);break;
			case 4: menu_bicolas();break;	
		}
	}while(opc1!=5);
}
void imprimirz(nodoi *P, nodoi *F)
{
	nodoi *Q;
	//impresion
	if(P==NULL || F==NULL)
	{
		printf("BICOLA VACIA\n");
	}
	else
	{
		Q=P;
		printf("\n\n  MOSTRANDO BICOLA \n ");
		printf("  |  ");
		while(Q!=NULL){
		printf(" %d  | ",Q->info);
		Q=Q->LigaD;
		}
	printf("\n\n");
	}
}
void menu_ber()
{
		int opc1;
		int r;
		nodoi *P,*F;
		P=NULL;
		F=NULL;
		do
		{
			system("pause");
		  	system("cls");
		  	printf("\n\t\tBICOLAS DE ENTRADA RESTRINGIDA");
		 	printf("\n\t\tMEMORIA DINAMICA\n\n");
		    printf(" 1. PUSH \n");
		    printf(" 2. POP\n");
		    printf(" 3. IMPRIMIR\n");
		    printf(" 4. SALIR A MENU PRINCIPAL\n");
		    printf(" 5. SALIR DEL PROGRAMA\n");
		    printf(" SELECCIONA UNA OPCION: ");
		  	scanf("%d",&opc1);
		  	system("cls");
		  	switch(opc1)
		  	{
		  		case 1: 
						P=construirNodo2(); //creamos a P
						printf("ELEMENTO: ");
						scanf("%d",&P->info);
						P->LigaD=NULL; //le decimos que es el final del nodo
						F=P; //P es igual a F
						printf("\n DESEA INGRESA MAS NODOS? SI=1 NO=0:");
					    scanf("%d",&r);
						while(r==1){
						//PUSH	
						F->LigaD=construirNodo2(); //creamos a f->LigaD
						F->LigaD->LigaI=F;
						F=F->LigaD;
						F->LigaD=NULL;
						printf("ELEMENTO:");
						scanf("%d",&F->info);
						printf("\n DESEA INGRESAR MAS NODOS? SI=1 NO=2:");
					    scanf("%d",&r);
						}
						printf("\n\nPOR DONDE INSERTAR ELEMENTOS? 1=FINAL | 0=PRINCIPIO: ");
						scanf("%d",&r);
					break;
		  		case 2: 
				  if(r==1){
						F=popD(P,F);
					}
					else{
						P=popI(P);	
					}
					break;
				case 3: imprimirz(P,F);
						break;
				case 4: menu_bicolas();break;
			}
	}while(opc1!=5);
}

void menu_bicolas(){
		int opc;
		system("pause");
	  	system("cls");
	  	printf("\n\tBICOLAS");
	 	printf("\n\tMEMORIA DINAMICA\n\n");
	    printf(" 1. BICOLAS DE ENTRADA RESTRINGIDA (BER)\n");
	    printf(" 2. BICOLAS DE SALIDA RESTRINGIDA (BSR)\n");
	    printf(" 3. SALIR\n\n");
	    printf(" SELECCIONA UNA OPCION: ");
	  	scanf("%d",&opc);
	  	switch(opc)
	  	{
	  		case 1: menu_ber();break;
	  		case 2:menu_bsr();break;
	  		case 3:exit(0);
		}
	
}



nodoi *construirNodo2(void){
	nodoi*P;
	P=(nodoi *)malloc(sizeof(nodoi));
	if(P==NULL){
		printf("ERROR\n");
		return 0;
	}
	return P;
}
//elimina desde el final
nodoi *popD(nodoi *P,nodoi *F){
	nodoi *Q;
	if(F==NULL)
	{
		printf("BICOLA VACIA\n");
		return F;
	}
	if(P->LigaD==NULL && P==F)
	{
		printf("SOLO HAY UN ELEMENTO\n");
		free(P);
		printf("ELIMINADO CORRECTAMENTE, BICOLA VACIA\n");
		P=F=NULL;
	}
	else
	{
		Q=F;
		printf("\n SE ELIMINO CORRECTAMENTE EL [%d]\n",Q->info);
		F = Q->LigaI;
		free(Q);
		F->LigaD=NULL;	
	}	
	return F;
}
//elimina desde el principio
nodoi *popI(nodoi *P){
	nodoi *Q;
	if(P==NULL)
	{
		printf("BICOLA VACIA\n");
		return P;
	}
	else if(P->LigaD==NULL)//que solo haya un elemento
	{
		printf("UNICO ELEMENTO\n");
		free(P);
		printf("ELEMENTO ELIMINADO CORRECTAMENTE, BICOLA VACIA\n");
		P=NULL;
	}
	else
	{
		Q=P;
		printf("\n SE ELIMINO CORRECTAMENTE EL [%d]\n",P->info);
		P=P->LigaD;
		free(Q);
	}
	return P;
}

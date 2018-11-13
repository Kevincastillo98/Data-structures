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
	printf("Elemento: ");
	scanf("%d",&P->info);
	P->LigaD=NULL; //le decimos que es el final del nodo
	F=P; //P es igual a F
	printf("\n Desea ingresar mas nodos?   1=Si | 2=No   : ");
    scanf("%d",&r);
	while(r==1){
	//PUSH	
	Q=construirNodo2(); //creamos a Q
	Q->LigaD = P;
	P->LigaI = Q;
	Q->LigaI  = NULL;
	P = Q;
	printf("Elemento: ");
	scanf("%d",&P->info);
	printf("\n Desea ingresar mas nodos?   1=Si | 2=No   : ");
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
	printf("Elemento: ");
	scanf("%d",&P->info);
	P->LigaD=NULL; //le decimos que es el final del nodo
	F=P; //P es igual a F
	printf("\n Desea ingresar mas nodos?   1=Si | 2=No   : ");
    scanf("%d",&r);
	while(r==1){
	//PUSH	
	F->LigaD=construirNodo2(); //creamos a f->LigaD
	F->LigaD->LigaI=F;
	F=F->LigaD;
	F->LigaD=NULL;
	printf("Elemento: ");
	scanf("%d",&F->info);
	printf("\n Desea ingresar mas nodos?   1=Si | 2=No   : ");
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
		printf("\n\t..[        BICOLAS DE SALIDA RESTRINGIDA         ]..");
		printf("\n\t.. [  		  MEMORIA DINAMICA  		 ]..\n\n");
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
	  			printf("La insercion sera por: 1=Frente o 2=Final\n");
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
		  	printf("\n\t..[        BICOLAS DE ENTRADA RESTRINGIDA         ]..");
		 	printf("\n\t.. [  		  MEMORIA DINAMICA  		 ]..\n\n");
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
						printf("Elemento: ");
						scanf("%d",&P->info);
						P->LigaD=NULL; //le decimos que es el final del nodo
						F=P; //P es igual a F
						printf("\n Desea ingresar mas nodos?   1=Si | 2=No   : ");
					    scanf("%d",&r);
						while(r==1){
						//PUSH	
						F->LigaD=construirNodo2(); //creamos a f->LigaD
						F->LigaD->LigaI=F;
						F=F->LigaD;
						F->LigaD=NULL;
						printf("Elemento: ");
						scanf("%d",&F->info);
						printf("\n Desea ingresar mas nodos?   1=Si | 2=No   : ");
					    scanf("%d",&r);
						}
						printf("\n\nPor donde desea eliminar los datos? 1=FINAL | 0=PRINCIPIO: ");
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
void main()
{
	menu_bicolas();
}

void menu_bicolas(){
		int opc;
		system("pause");
	  	system("cls");
	  	printf("\n\t..[        BICOLAS         ]..");
	 	printf("\n\t..[    MEMORIA DINAMICA   ]..\n\n");
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
		printf("Error, no hay memoria disponible.\n");
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

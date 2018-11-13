typedef struct Lista{
	struct Lista *LigaD;
	int info;
	struct Lista *LigaI;
} nodo;

void menu_dobl(void);
nodo *construirNodo(void);
void crearFinalD();
void insertarInicioD(nodo*,int);
void insertarFinalD(nodo * ,int);
void quitarXD(nodo*,nodo*,int);
void imprimirD(nodo*,nodo*,nodo*);
void eliminarInicioD(nodo *,nodo *);
void eliminarUltimoD(nodo*,nodo*);
void eliminarAntesD(nodo*,nodo*,nodo*,int);
void eliminarDespuesD(nodo*,nodo*,nodo*,nodo*,int);
void despuesXD(nodo*,nodo*,nodo*,nodo*,int);
void palindromoD(nodo *P,nodo *F,nodo *Q,nodo *R,int x);


int rr,n,x,resp;
nodo *P,*F,*Q,*R,*T;

void menu_listas_dobles() {
	do{
	printf("\n\t\tLISTAS LIGADAS DOBLES");
 	printf("\n\t\tMEMORIA DINAMICA\n\n");
    printf(" 1. CREAR POR EL FINAL\n");
    printf(" 2. IMPRIME LISTA DE PRINCIPIO A FIN\n");
    printf(" 3. ELIMINAR UN ELEMENTO CON INFORMACION DADA\n ");
    printf("4. INSERTAR UN ELEMENTO  EN UNA LISTA POR EL PRINCIPIO\n");
    printf(" 5. ELIMINAR EL ULTIMO ELEMENTO DE LA LISTA\n");
    printf(" 6. ELIMINAR UN ELEMENTO ANTES DE UNO DADO COMO REFERENCIA\n");
    printf(" 7. INSERTAR UN ELEMENO DESPUES DE UNO DADO COMO REFERENCIA\n");
    printf(" 8. IDENTIFICAR SI UN CONJUNTO DE CARACTERES ES PALINDROMO\n");
    printf(" 9. SALIR\n\n");
    printf ("OPCION: ");
	scanf ("%d", &rr);
	system("cls");

		switch(rr){

			case 1:
				crearFinalD();
				printf("\n\nLA LISTA CREADA ES:\n");
				imprimirD(P,F,Q);
				printf("\n");
				break;
			case 2:
			     printf("\n\n");
				 imprimirD(P,F,Q);
				 printf("\n\n\n");
				break;
			case 3:
					//Agregar ciclo para eliminar mas elementos
				  quitarXD(P,F,x); 
				  printf("\n\n\n");
					break;
			case 4:
					//INSERTA UN ELEMENTO POR EL PRINCIPIO
					insertarInicioD(P, x);
					printf("\n\n\n");
			break;
			case 5:
			       eliminarUltimoD(P,F);
				   printf("\n\n\n");
			break;
			case 6:
			//poner condicional para el 1° elemento
			//falta imprimir
				  eliminarAntesD(P,F,Q,x);
				  printf("\n\n\n");
			break;
			case 7: despuesXD(P,F,Q,R,x);
					 printf("\n\n\n");
					break;
			 case 8:
				   palindromoD(P,F,Q,R,x);
				   printf("\n\n\n");
			 break;
			 case 9: exit(0);break;
		}
		printf("\nDESEA HACER OTRA ACCION? SI=1 N0=2:");
		scanf("%d",&resp);
		system("cls");
	}while(resp == 1 || rr!= 9);		
}

nodo *construirNodoD(void){
	nodo*P;
	P=(nodo *)malloc(sizeof(nodo));
	if(P==NULL){
		printf("\nLISTA VACIA\n");
		return NULL;
	}
	return P;
}


void crearFinalD(){
				P=construirNodoD();
				printf("ELEMENTO:");
				scanf("%d",&P->info);
				P->LigaI=NULL;
				P->LigaD=NULL;
				F=P;
				
				printf("DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=2:");
				scanf("%d",&rr);
				
				while(rr==1){
					F->LigaD=construirNodoD();
					F->LigaD->LigaI=F;
					F=F->LigaD;
					printf("ELEMENTO:");
					scanf("%d",&F->info);
					F->LigaD=NULL;
					printf("DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=2:");
					scanf("%d",&rr);
				}
	
}
void insertarInicioD(nodo *P, int x){
if(P == NULL){
	printf("LISTA VACIA\n\n\n");
	return ;
}	
	else{
		
	Q =(nodo *) malloc(sizeof(nodo));
	printf("ELEMENTO A INSERTAR:");
	scanf("%d",&x);
	Q->info = x;
	Q->LigaD = P;
	P->LigaI = Q;
	Q->LigaI  = NULL;
	P = Q;
	printf("\nEL ELEMENTO INSERTADO FUE:\n");
	printf("[NULL]<->");
	while(P != NULL){
		printf("%d<->",P->info);
		P =P->LigaD;
	}
	printf("[NULL]");
    }
}

void insertarFinalD(nodo *F,int x){
if(F == NULL){
	printf("LISTA VACIA\n\n\n");
	return;
}	
	else{
	Q =(nodo *) malloc(sizeof(nodo));
	printf("ELEMENTO A INSERTAR:");
	scanf("%d",&Q->info);
	F->LigaD = Q;
	Q->LigaI = F;
	Q->LigaD =  NULL;
	F = Q;
	printf("\nEL ELEMENTO INSERTADO FUE:\n");
	printf("[NULL]<->");
	while(P != NULL){
		printf("%d<->",P->info);
		P=P->LigaD;
	}
	printf("[NULL]");
	
	}
}

void imprimirD(nodo *P,nodo *F,nodo *Q){
	if(P==NULL){
		printf("LISTA VACIA\n");
		return ;
	}
	else{
		Q=P;
		printf("[NULL]<->");
		while(Q!=NULL){
			printf(" %d<->",Q->info);
			Q=Q->LigaD;
		}
		printf("[NULL]\n");
	}
}


void quitarXD(nodo *P,nodo *F,int x){
if(P==NULL){
printf("LISTA VACIA\n");
return ;
}
else{
	Q=P;
	printf("INTRODUCE EL ELEMENTO A ELIMINAR:");
	scanf("%d",&x);
	while(Q->info!=x && Q->LigaD!=NULL){
		Q=Q->LigaD;
	}
	if(Q->info!=x){
		printf("\nNO SE ENCONTRO EL ELEMENTO\n");
		return ;
	}else{
		if(Q == P && Q == F){
			free(P);
			P=F=NULL;
		}else{
			if(Q==P){
				P=Q->LigaD;
				free(Q);
				P->LigaI=NULL;
			}else{
				if(Q == F){
					F = Q->LigaI;
					free(Q);
					F->LigaD=NULL;
				}else{
					T = Q->LigaI;
					R = Q->LigaD;
					T->LigaD = R;
					R->LigaI = T;
					free(Q);
				}
			}
		}
	 }
	  printf("[NULL]<->");
			     while(P != NULL){
				printf("%d<->",P->info);
				P = P->LigaD;
				}
				printf("[NULL]\n");
   }//fin else
}

void eliminarInicioD(nodo *P ,nodo *F){
if(P == NULL){
	printf("\nLA LISTA ESTA VACIA\n");
	return;
}
	else{
			Q = P;
			if(Q->LigaD != NULL){
			  P = Q->LigaD;
			  P->LigaI = NULL;
			}
				else{
				  P = NULL;
				  F = NULL;	
				}
				free(Q);
			
		printf("[NULL]<->");
	    while(P!= NULL){
		printf("%d<->",P-> info);
		P = P->LigaD;
	}
	printf("[NULL]\n");
	}

}

void eliminarUltimoD(nodo *P,nodo *F){
	if(P == NULL){
	printf("\nLA LISTA ESTA VACIA\n");
	}
 	else{
 	Q=F;
	if(P->LigaD==NULL) //solo hay un elemento
	{
		free(P);
		P=NULL;
		imprimirD(P,F,Q);
		printf("\n\n");
	}
	else if(Q->LigaI != NULL){
		F = Q->LigaI;
		F->LigaD = NULL;
	}
	 else{
			F = NULL;
			P = NULL;
    	}
	free(Q);
	printf("[NULL]<->");
	while(P!= NULL){
		printf("%d<->",P-> info);
		P = P->LigaD;
	}
	printf("[NULL]\n");
 
}
}

void eliminarAntesD(nodo *P,nodo *F,nodo *Q,int x){
	nodo *aux,*s;
	if(P ==NULL){
		printf("\nLISTA VACIA\n");
		}
	else{
	Q=P;
	printf("INTRODUCE EL ELEMENTO:");
	scanf("%d",&x);
		if((P->info==x)&&(P->LigaD==NULL)){ 
			printf("\nNO SE PUEDE BORRAR NADA\n");
		}
		else if(P->info==x){
			//es el primero
			printf("\nES EL PRIMER ELEMENTO,NO SE PUEDE ELIMINAR NADA\n");
		}
		else if(P->LigaD->info==x) //es el segundo
			{
				aux=P;
				P=P->LigaD;
				free(aux);

				printf("[NULL]<->");
			     while(P != NULL){
				printf("%d<->",P->info);
				P = P->LigaD;
				}
				printf("[NULL]\n");
			}
			else
			{
			Q=P;		
			s=Q;	
		    while(Q->info!=x && Q->LigaD!=NULL){
				s=aux;//para estar antes del auxiliar
		    	aux=Q; //para estar antes del nodo
			    Q=Q->LigaD;
		    }	    
			s->LigaD=Q;		    
		   	free(aux);
		}
	}
}
void despuesXD(nodo *P,nodo *F,nodo *Q,nodo *R,int x){
	Q=P;
	if(P==NULL)
	{
		printf("\nLA LISTA ESTA VACIA");
	}
	else
	{
		printf("INTRODUCE EL ELEMENTO:");
		scanf("%d",&x);
		while(Q->info!=x && Q->LigaD!=NULL){
			Q=Q->LigaD;
		}
		if(Q->info!=x){
			printf("\nNO SE ENCONTRO EL ELEMENTO\n");
		}
		else{
			if(P==F){ //es un elemento o es el último
				F->LigaD=construirNodoD();
				F->LigaD->LigaI=F;
				F=F->LigaD;
				printf("INTRODUCE EL DATO: ");
				scanf("%d",&F->info);
				F->LigaD=NULL;
			} //hasta aqui esstabien
			else
			{
				R=construirNodoD();
				printf("ELEMENTO A INSERTAR:");
				scanf("%d",&R->info);
				R->LigaD=Q->LigaD;
				Q->LigaD=R;
			}
			
		}
	}
}

void palindromoD(nodo *P,nodo *F,nodo *Q,nodo *R,int x) 
{ 
    if (P == NULL){
       printf("\nLISTA VACIA\n"); 
	} 
	else
	{
		if(P->info!=F->info)
		{
			printf("\nNO ES UN PALINDROMO\n");
		}
		else
		{
			Q=P;
			R=F;
			while(R->info==Q->info && R->LigaI!=Q->LigaD)
			{
				Q=Q->LigaD;
				R=R->LigaI;
			}
			if(R->info==Q->info)
				{
					printf("\nES UN PALINDROMO");
				}
				else
			printf("\nNO ES UN PALINDROMO");
				
		}
	 } 
  
    } 



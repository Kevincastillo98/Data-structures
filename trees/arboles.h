//Arboles_Binarios
typedef struct Nodo{
	int Info;
	struct Nodo *Izq;
	struct Nodo *Der;
}Nodo;
Nodo *raiz = NULL,*i = NULL,*d = NULL;

void menuArbBin();
void Carga(Nodo *);
void Imppre(Nodo *);
void Imppos( Nodo *);
void Impino( Nodo *);
void InsertarDato(int,Nodo *);
void BuscarDato(int, Nodo *);
void EliminarDato(int, Nodo *);


void menuArbBin()
{
	Nodo *raiz=(Nodo *)malloc(sizeof(Nodo));
	int opcion=0, x;
	do{
		printf("\n\n\t\tARBOLES BINARIOS\n\n");
		printf("1.CREAR UN ARBOL\n");
		printf("2.-IMPRIMIR ARBOL EN PREORDEN\n");
		printf("3.-IMPRIMIR ARBOL EN POSORDEN\n");
		printf("4.-IMPRIMIR ARBOL EN INORDEN\n");
		printf("5.INSERTAR UN ELEMENTO\n");
		printf("6.BUSCAR UN ELEMENTO\n");
		printf("7.ELIMINAR UN NODO\n");
		printf("8.SALIR\n");
		printf("\nOPCION:");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:
				Carga(raiz);
				printf("\n\n");
				system("pause");
				break;
			case 2:
				if((raiz->Info==0)||(raiz==NULL))
				{
					printf("NO EXISTE EL ARBOL\n");
				}
				else{
					printf("\nIMPRIMIR ARBOL EN PREORDEN\n");
					printf("\n\n");
					Imppre(raiz);
				}
				printf("\n\n");
				system("pause");
				break;
			case 3:
				if((raiz->Info==0)||(raiz==NULL))
				{
					printf("NO EXISTE EL ARBOL");
				}
				else{
					printf("\n\nIMPRIMIR ARBOL EN POSORDEN\n\n");
					Imppos(raiz);
				}
				system("pause");
				break;
			case 4:
				if(raiz==NULL)
				{
					printf("NO EXISTE EL ARBOL\n");
				}
				else{
					printf("\n\nIMPRIMIR ARBOL EN INRODEN\n\n");
					Impino(raiz);
				}
				system("pause");
				break;
			case 5:
				if((raiz->Info == 0)||(raiz == NULL))
				{
					printf("\nELEMENTO:");
					scanf("%d",&raiz->Info);
					raiz->Izq=NULL;
					raiz->Der=NULL;
					printf("\n%d FUE INSERTADO\n",raiz->Info);
				}
				else
				{
					printf("\nELEMENTO:");
					scanf("%d",&x);
					InsertarDato(x, raiz);
					printf("\n\n %d FUE INSERTADO\n",x);
				}
				system("pause");
				break;
			case 6:
				if((raiz->Info==0)||(raiz==NULL))
				{
					printf("\nNO EXISTE ARBOL");
				}
				else{
					printf("\nELEMENTO A BUSCAR:");
					scanf("%d",&x);
					BuscarDato(x, raiz);
				}
				system("pause");
				break;
			case 7:
				if((raiz->Info==0)||(raiz==NULL))
				{
					printf("\n\tNO EXISTE ARBOL\n");
				}
				else{
					Nodo *d= (Nodo *)malloc(sizeof(Nodo));
					Nodo *i= (Nodo *)malloc(sizeof(Nodo));
					printf("\n\nELEMENTO A ELIMINAR: ");
					scanf("%d",&x);
					if(raiz->Info==x)
					{
						if((raiz->Izq==NULL)&&(raiz->Der==NULL))
						{
							free(raiz);
							raiz=NULL;
							printf("\nEL ARBOL FUE ELIMINADO");
						}
						else{
							if(raiz->Izq!=NULL)
							{
								i=raiz;
								raiz=raiz->Izq;
								d=raiz->Der;
								if(d==NULL)
								{
									raiz->Der=i->Der;
								}
								else
								{
									while(d->Der!=NULL)
									{
										d=d->Der;
									}
									d->Der=i->Der;
								}
								free(i);
								i=NULL;
								printf("\n\n %d FUE ELIMINADO",x);
							}
							else{
								d=raiz;
								raiz=raiz->Der;
								free(d);
								d=NULL;
								printf("\n\n %d FUE ELIMINADO",x);
							}
						}
					}
					else{
						EliminarDato(x, raiz);
					}
				}
				printf("\n\n");
				system("pause");
				break;
		}
	}while(opcion != 8);
	system("pause");
}

void Carga(Nodo *nodos)
{
	int respuesta;
	printf("\nELEMENTO:");
	scanf("%d",&nodos->Info);
	printf("\n\n¿%d tiene un hijo izquierdo? (1=Si, 0=No) ",nodos->Info);
	scanf("%d",&respuesta);
	if(respuesta == 0){
		nodos->Izq = NULL;
	}
	else{
		Nodo *i = (Nodo *)malloc(sizeof(Nodo));
		nodos->Izq = i;
		Carga(i);
	}
	printf("\n\n¿ %d tiene un hijo derecho? (1=Si, 0=No) ",nodos->Info);
	scanf("%d",&respuesta);
	if(respuesta == 0){
		nodos->Der = NULL;
	}
	else{
		Nodo *d = (Nodo *)malloc(sizeof(Nodo));
		nodos->Der = d;
		Carga(d);
	}
}
void Imppre(Nodo *nodos)
{
	if(nodos != NULL)
	{
		Nodo *d = (Nodo *)malloc(sizeof(Nodo));
		Nodo *i = (Nodo *)malloc(sizeof(Nodo));
		printf("%d-",nodos->Info);
		i=nodos->Izq;
		d=nodos->Der;
		Imppre(i);
		Imppre(d);
	}
}
void Imppos(Nodo *nodos)
{
	if(nodos != NULL)
	{
		Nodo *d = (Nodo *)malloc(sizeof(Nodo));
		Nodo *i = (Nodo *)malloc(sizeof(Nodo));
		i=nodos->Izq;
		d=nodos->Der;
		Imppos(i);
		Imppos(d);
		printf("%d-",nodos->Info);
		//cout<<nodos->Info<<"-";
	}
}
void Impino(Nodo *nodos)
{
	if(nodos != NULL)
	{
		Nodo *d = (Nodo *)malloc(sizeof(Nodo));
		Nodo *i = (Nodo *)malloc(sizeof(Nodo));
		i=nodos->Izq;
		d=nodos->Der;
		Impino(i);
		printf("%d -",nodos->Info);
	//	cout<<nodos->Info<<"-";
		Impino(d);
	}
}
void InsertarDato(int x, Nodo *nodos)
{
	if(x <= nodos->Info)
	{
		if(nodos->Izq==NULL)
		{
			Nodo *i = (Nodo *)malloc(sizeof(Nodo));
			nodos->Izq=i;
			i->Info=x;
			i->Der=NULL;
			i->Izq=NULL;
		}
		else{
			i=nodos->Izq;
			InsertarDato(x, i);
		}
	}
	else
	{
		if(nodos->Der==NULL)
		{
			Nodo *d= (Nodo *)malloc(sizeof(Nodo));
			nodos->Der=d;
			d->Info=x;
			d->Der=NULL;
			d->Izq=NULL;
		}
		else{
			d=nodos->Der;
			InsertarDato(x, d);
		}
	}
}
void BuscarDato(int x, Nodo *nodos)
{
	if(x==nodos->Info)
		printf("\n\n %d Fue encontrado",x);
	else{
		if(x < nodos->Info)
		{
			if(nodos->Izq==NULL)
			{
					printf("\n\n %d No existe el dato",x);
			}
			else{
				i=nodos->Izq;
				BuscarDato(x, i);
			}
		}
		else{
			if(nodos->Der==NULL)
				printf("\n\n %d  No existe",x);
			else{
				d=nodos->Der;
				BuscarDato(x, d);
			}
		}
	}
}


void EliminarDato(int x, Nodo *nodos)
{
	d=nodos->Der;
	i=nodos->Izq;
	Nodo *b= (Nodo *)malloc(sizeof(Nodo));
	if(nodos->Info<x)
	{
		if(d->Info==x)
		{
			if(d->Izq!=NULL)
			{
				b=d->Izq;
				while(b->Der!=NULL)
				{
					b=b->Der;
				}
				b->Izq=d->Der;
				nodos->Der=d->Izq;
			}
			else{
				nodos->Der=d->Der;
			}
			free(d);
			d=NULL;
		}
		else{
			EliminarDato(x, d);
		}
	}
	else{
		if(i->Info==x)
		{
			if(i->Izq!=NULL)
			{
				b=i->Izq;
				while(b->Der!=NULL)
				{
					b=b->Der;
				}
				b->Izq=i->Der;
				nodos->Izq=i->Izq;
			}
			else{
				nodos->Izq=i->Der;
			}
			free(i);
			i=NULL;
		}
		else{
			EliminarDato(x, i);
		}
	}
	if((d!=NULL)||(i!=NULL))
	{
		printf("\n\n  %d no fue encontrado",x);
	}
	else
	{
		printf("\n\n %d fue eliminado",x);
	}
}

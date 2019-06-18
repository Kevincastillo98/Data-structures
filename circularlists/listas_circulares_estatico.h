void menu_circulares_estatico();
 void addcirc(int arreglo[],int tamanio,int i,int n);
 void eliminar1erelementocirc(int arreglo[],int tamanio,int i,int n);
 void printListcirc(int arreglo[],int tamanio,int i,int n);
 void insertariniciocirc(int arreglo[],int tamanio,int i,int n);//
 void elexcirc(int arreglo[],int tamanio,int i,int n); //
 void eliminarxcirc(int arreglo[],int tamanio,int i,int n);
 void eliminarelesiguientecirc(int arreglo[], int tamanio, int i, int n);
 void eliminareleantescirc(int arreglo[], int tamanio, int i, int n);


void menu_circulares_estatico()
{
    int arreglo[10]={0};
	int i=0,n,resp,aux;
	printf("\nLONGITUD DEL ARREGLO:");
	scanf("%d",&n);
	system("cls");
	do{
		printf("\n\nLISTAS CIRCULARES\n");
		printf("1.CREAR UNA LISTA AGREGANDO CADA ELEMENTO AL FINAL\n");
	    printf("2.ELIMINAR UN ELEMENTO DESPUES DE UNO DADO COMO REFERENCIA\n");	
		printf("3.ELIMINAR EL PRIMER ELEMENTO\n");
		printf("4.IMPRIMIR\n");
		printf("5.BUSCAR UN ELEMENTO X E IMPRIMIR LA DIRECCION DEL ELEMENTO ANTERIOR Y LA INFORMACION DEL POSTERIOR\n");
      	printf("6.BUSCAR Y ELIMINAR UN ELEMENTO\n");
      	printf("7.INSERTA UN ELEMENTO X POR EL INICIO\n");
      	printf("8.ELIMINAR UN ELEMENTO ANTES DE UNO DADO COMO REFERENCIA\n");
      	printf("9.SALIR\n");
		printf("\nOPCION:");
		scanf("%d",&resp);
		system("cls");
		switch(resp)
		{
			case 1: addcirc(arreglo,10,i,n); break;
            case 2: eliminarelesiguientecirc(arreglo,10,i,n); 
					if(n!=1) //que no sea el unico
					{
						n=n-1;
					}
					break;
			case 3: eliminar1erelementocirc(arreglo,10,i,n);n=n-1;break;
			case 4: printListcirc(arreglo,10,i,n); break;
         	case 5: elexcirc(arreglo, 10, i,n); break;
			case 6: eliminarxcirc(arreglo, 10, i,n);n=n-1; break;
         	case 7: {
         		int x;
   				int y;
				do
				{
					n=n+1;
					printf("ELEMENTO: ");
					scanf("%d",&x);
					for(i=n; i>0; i--)
					{
						arreglo[i]=arreglo[i-1];
						
					}
					arreglo[0]=x;
					for(i=0;i<n;i++)
					{
						printf("%d->",arreglo[i]);
					}
					printf("INICIO\n");
					printf("DESEA INSERTAR MAS ELEMENTOS? SI=1 NO=2:");
					scanf("%d", &y);
				}while(y==1);
				break;
			 };
			 
         	case 8: eliminareleantescirc(arreglo,10,i,n); 
			 		if(arreglo[n-1]==0)
			 		{
			 			n=n-1;
					 }
					 break;
			case 9: exit(0);
			
		}
		printf("DESEA EJECUTAR OTRA ACCION? SI=1 NO=2:");
		scanf("%d",&resp);
		system("cls");

	}while(resp==1);
}

void addcirc(int arreglo[],int tamanio,int i,int n)
{
	for(i=0;i<n;i++)
	{
		printf("ELEMENTOS:");
		scanf("%d",&arreglo[i]);
	}
	
 
}

void eliminar1erelementocirc(int arreglo[],int tamanio,int i,int n)
{
	if(arreglo[0]==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
	
		for(i=0; i<=n; i++)
		{
			arreglo[i]=arreglo[i+1];
		}
		printf("LA NUEVA LISTA ES:\n");
		i=0;
		do
		{
			printf("%d\n", arreglo[i]);
			i++;
		}while(arreglo[i]!=0);
	}
}


void printListcirc(int arreglo[],int tamanio,int i,int n)
{

   if(arreglo[0]==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
		printf("LISTA:\n");
		for(i=0;i<n;i++)
		{
			printf("%d->", arreglo[i]);
		}
		printf("INICIO\n");
	}
}


void elexcirc(int arreglo[],int tamanio,int i,int n)
{
	int b, x, aux, aux2, c=0, j;
	if(arreglo[0]==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
		printf("ELEMENTO DADO COMO REFERENCIA:");
		scanf("%d", &x);
		i=0;
		do
		{
			aux=arreglo[i];
			aux2=i;
			if(arreglo[i]==0)
			{
				c=1;
			}
			i++;
		}while(aux!=x&&c==0);
		if(c==1)
		{
			printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
		}
		else
		{
			j=0;
			while(arreglo[j]!=0)
			{
				b=j;
				j++;	
			}
			if(arreglo[0]==x)
			{
			
				printf("DIRECCION: %p\n", &b);
				printf("INFROMACION: %d\n", arreglo[1]);
			}
			else
			{
				if(arreglo[b]==x)
				{
					printf("DIRECCION: %p\n", &b-1);
					printf("INFORMACION: %d\n", arreglo[0]);
				}
				else
				{
					printf("DIRECCION: %p\n", &aux2-1);
					printf("INFORMACION: %d\n", arreglo[aux2+1]);
				}	
			}	
		}
	}
}

void eliminarxcirc(int arreglo[],int tamanio,int i,int n)
{
	int b, x, aux, aux2, c=0, j=0;
	if(arreglo[0]==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
		printf("ELEMENTO DADO COMO REFERENCIA:");
		scanf("%d", &x);
		i=0;
		do
		{
			aux=arreglo[i];
			if(arreglo[i]==0)
			{
				c=1;
			}
			i++;
		}while(aux!=x&&c==0);
		if(c==1)
		{
			printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
		}
		else
		{
			if(arreglo[0]==x && arreglo[1]==0)//unico elemento 
			{
			 arreglo[0]=0; //eliminando
			 printf("\nUNICO ELEMENTO ELIMINADO\n");
			}
			else 
			{
					for(j=i-1;j<n;j++)
					{
						arreglo[j]=arreglo[j+1];
					}
					printf("\nELEMENTO ELIMINADO CON EXITO\n");
				}
			}	
		}
	}

/*--------------------------------------------------------------------------------------------------------------------
void insertarinicio(int arreglo[], int tamanio, int i, int n)
{
	int x;
   char y;
	do
	{
		printf("Inserta la Matricula que ira al inicio: ");
		scanf("%d",&arreglo[i]);
		for(i=n; i>0; i--)
		{
			arreglo[i]=arreglo[i-1];
		}
		arreglo[0]=x;
		printf("Deseas insertar otro dato? S/N\n");
		scanf("%s", &y);
	}while(y=='S'||y=='s');
	
}
//--------------------------------------------------------------------------------------------------------------------*/
void eliminarelesiguientecirc(int arreglo[], int tamanio, int i, int n)
{

	int b=0, x, aux, aux2, c=0, j;
	if(arreglo[0]==0)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{

		printf("ELEMENTO DADO COMO REFERENCIA:");
		scanf("%d", &x);
		do
		{
			aux=arreglo[i];
			aux2=i;
			if(arreglo[i]==0)
			{
				c=1;
			}
			i++;
		}while(aux!=x&&c==0);
		if(c==1)
		{
			printf("\nELEMENTO NO EXISTE\n");
		}
		else
		{
			if(arreglo[0]==x && arreglo[1]==0) //que sea el unico
			{
				printf("\nEL ELEMENTO ES EL UNICO,NO SE PUEDE ELIMINAR\n");
			}
			else
			{
				i=0;
				do
				{
					b=i;
					i++;
				}while(arreglo[i]!=0);
				if(arreglo[b]==x)
				{
					for(j=0; j<n; j++)
					{
						arreglo[j]=arreglo[j+1];
					}
				}
				else
				{
					for(j=aux2+1; j<n; j++)
					{
						arreglo[j]=arreglo[j+1];
					}
				}
			printf("LA NUEVA LISTA ES:\n");
			i=0;
			do
			{
				printf("%d->", arreglo[i]);
				i++;
			}while(arreglo[i]!=0);
			printf("PRIMERO\n");
			}
		}
	}
}



void eliminareleantescirc(int arreglo[], int tamanio, int i, int n)
{
	
	int ref,b=0,pib,arre[10];
	if(arreglo[0]==0){
		printf("\nLISTA VACIA\n");
	}
	else{
	printf("\nELEMENTO DADO COMO REFERENCIA:");
	scanf("%i",&ref);
	for(i=0; i<n; i++){
		if(ref==arreglo[i]){
			pib=i; b=1;
		}
	}
	if(b==0){
		printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
	}
	if(b==1) {
		if(ref==arreglo[0]){
			for(i=0; i<n; i++)
			printf("EL ELEMENTO %d ES EL PRIMERO,NO SE PUEDE ELIMINAR NADA\n",arreglo[i]);
		}
		else{
			for(i=0;i<n;i++){
			arre[i]=arreglo[i]; //copiar los datos
			}
			for(i=0; i<pib-1; i++){
				arreglo[i]=arre[i];
		}
		for(i=pib-1;i<n-1;i++)
		{
			arreglo[i]=arreglo[i+1];
		}
		arreglo[n-1]=0;
		printf("\ELIMINADO CON EXITO\n");
		}
	
	}}
}


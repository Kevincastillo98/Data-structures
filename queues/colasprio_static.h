//declaracion de funciones
void insertar_prioridad(int arreglo[],int tamanio,int i,int n);
void elimina_colasprio(int arreglo[],int tamanio,int i,int n);
void imprimir_colasorio(int arreglo[],int tamanio,int i,int n);
void menu_colasprio_estatico();
//inicio de funciones
void imprimir_colasprio(int arreglo[],int tamanio,int i,int n)	
{
	if(arreglo[0]==0){
		printf("No hay lista\n");
	}
	else{
	    for(i=0; i<n; i++){
		    printf("||%d||%d||-> ",arreglo[i],i);
	    }
	    printf("NULL\n");
	}
}
void elimina_colasprio(int arreglo[],int tamanio,int i,int n)	
{
	int arre[10];
	if(arreglo[0]==0){
		printf("LA LISTA ESTA VACIA\n");
	}
	else{
		if(n==0)
		{
			printf("NO HAY NADA QUE ELIMINAR.");
		}
		else
		{
			for(i=0;i<n;i++)
				arre[i]=arreglo[i]; //igualamos la informacion
			for(i=0; i<n-1; i++)
				arreglo[i]=arre[i+1];
			printf("ELEMENTO ELIMINADO CORRECTAMENTE.\n\n");
		}
	
}
}
void insertar_prioridad(int arreglo[],int tamanio,int i,int n)
{
	int prio;
	printf("IMPORTANTE: La PRIORIDAD VA DESDE 0 HASTA %d\n",n-1);
	for(i=0; i<n; i++){
		printf("\nIngresa la prioridad: ");
		scanf("%d",&prio);
	    printf("Ingresa el valor: ");
	    scanf("%d",&arreglo[prio]);	    
	}
}

void menu_colasprio_estatico()
{
	int arreglo[10]={0};
	int i=0,n,r;
	printf("\nDe cuantos terminos va a ser el arreglo: ");
	scanf("%d",&n);
	system("cls");
	int opc;
	int k;
	  while(opc!=4)
	  {
	  	system("pause");
	  	system("cls");
	 	printf("\n\t..[    COLAS CON PRIORIDAD     ]..");
	 	printf("\n\t..[     MEMORIA ESTATICA   ]..\n\n");
	    printf(" 1. INSERTAR ELEMENTOS A LA COLA [ PUSH ]\n");
	    printf(" 2. ELIMINAR ELEMENTOS DE LA COLA [ POP ]\n");
	    printf(" 3. IMPRIMIR\n");
	    printf(" 4. SALIR\n\n");
	    printf(" SELECCIONA UNA OPCION: ");
	    scanf("%d",&opc);
	    system("cls");
	    switch(opc)
		  	{
		  		case 1: insertar_prioridad(arreglo,10,i,n);
						break;
		  		case 2: elimina_colasprio(arreglo,10,i,n);
		  				n=n-1;
				  		break;
		  		case 3: imprimir_colasprio(arreglo,10,i,n);
						break;
		  		
		  		case 4: exit(0);
		  		default: printf("\nSaliendo del programa...");
		  	}
		
	}
	}



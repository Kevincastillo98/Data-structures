int arreglo[100];
int top=-1;
void menu_pilas_estatico()
{
int i=0,n,resp,opc;


	printf("\nLONGITUD DEL ARREGLO:");
	scanf("%d",&n);
	int arreglo[n];
	system("cls");
	do
	{
		printf("\n\t\tPILAS\n");
	 	printf("\t\tMEMORIA ESTATICA\n\n");
	    printf(" 1. INGRESAR ELEMENTO [ PUSH ]\n");
	    printf(" 2. ELIMINAR ELEMENTO [ POP ]\n");
	    printf(" 3. IMPRIMIR EL CONTENIDO\n");
	    printf(" 4. SALIR\n\n");
	    printf(" SELECCIONA UNA OPCION: ");
	    scanf("%d",&resp);
	    switch(resp)
	    {
	    	 case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
		}
		printf("\nDESEA HACER OTRA ACCION? SI=1 NO=0:");
		scanf("%d",&opc);
		system("cls");

	}while(opc==1);
}

void push()
{
    int val;

    if(top==n-1)
    {
        printf("\nLA PILA ESTA LLENA\n");
    }
    else
    {
        printf("\nELEMENTO:");
        scanf("%d",&val);
        top=top+1;
        arreglo[top]=val;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nPILA VACIA\n");
    }
    else
    {
        printf("\ELEMENTO ELIMINADO %d",arreglo[top]);
        top=top-1;
    }
}

void display()
{
    int i;

    if(top==-1)
    {
        printf("\nPILA LLENA\n");
    }
    else
    {
        printf("\nLA PILA ES:\n");
        for(i=top;i>=0;--i)
            printf("-%d-\n",arreglo[i]);
    }
}






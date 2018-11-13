#include <stdio.h>

#define MAX 50
int queue_array[MAX];
int rear = - 1;
int fronta = - 1;



void menu_colas_estatico()
{
    int opcion,r;
    do{
       system("pause");
	  	system("cls");
	 	printf("\n\t\tCOLAS");
	 	printf("\n\t\tMEMORIA ESTATICA\n\n");
	    printf(" 1. INSERTAR ELEMENTOS A LA COLA [ PUSH ]\n");
	    printf(" 2. ELIMINAR ELEMENTOS DE LA COLA [ POP ]\n");
	    printf(" 3. IMPRIMIR\n");
	    printf(" 4. SALIR\n\n");
	    printf(" SELECCIONA UNA OPCION: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
            insertar();
            break;
            case 2:
            eliminar();
            break;
            case 3:
            pimprimircola();
            break;
            case 4:
            exit(1);
            break;
        } /*End of switch*/
        printf("DESEA HACER OTRA ACCION? SI=1 NO=0: ");
		scanf("%d",&r);
		system("cls");
    }while(r ==1 || opcion != 4);
} /*End of main()*/
insertar()
{
    int add_item;
    if (rear == MAX - 1)
    printf("COLA LLENA\n");
    else
    {
        if (fronta == - 1)
        /*If queue is initially empty */
        fronta = 0;
        printf("ELEMENTO: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} /*End of insert()*/

void eliminar()
{
    if (fronta == - 1 || fronta > rear)
    {
        printf("COLA VACIA\n");

    }
    else
    {
        printf("ElEMENTO ELIMINADO: %d\n", queue_array[fronta]);
        fronta = fronta + 1;
    }
} /*End of delete() */
void pimprimircola()
{
    int i;
    if (fronta == - 1)
        printf("COLA VACIA \n");
    else
    {
        printf("LA COLA ES: \n");
        for (i = fronta; i <= rear; i++)
            printf("%d->", queue_array[i]);
        printf("\n");
    }
} /*End of display() */

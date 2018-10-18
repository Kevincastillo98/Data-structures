#include <stdio.h>
#include <stdlib.h>
 
typedef struct nodopilas{
	int info;
	struct nodopilas *liga;
}nodop;
 
nodop *pil;

nodop *NuevoElem();
void pushd(int dato);
int popd(void);
void imprimirpilas(nodop *);
void menu_pilas();
/*Fin de las declaraciones*/
 
mainPilas()
{
  int opc;
  int k;
  
  while(opc!=4)
  {
  	menu_pilas();
  	scanf("%d",&opc);
  	
	switch(opc)
  	{
  		case 1: printf("ELEMENTO: ");
	  			scanf("%d", &k); 
				pushd(k);
				break;
  		case 2: popd();
  				system("pause");
		  		break;
  		case 3: imprimirpilas(pil);
  				system("pause"); 
				break;
  		
  		case 4: exit(0);
  		default: printf("\nSaliendo del programa...");
  
	  	return 0;
  	}
  }
}
 
void menu_pilas(){
 	printf("\n\t..[        PILAS         ]..");
 	printf("\n\t..[   MEMORIA DINAMICA   ]..\n\n");
    printf(" 1. INGRESAR ELEMENTO [ PUSH ]\n");
    printf(" 2. ELIMINAR ELEMENTO [ POP ]\n");
    printf(" 3. IMPRIMIR EL CONTENIDO\n");  
    printf(" 4. SALIR\n\n");
    printf(" SELECCIONA UNA OPCION: ");
}
 
 //1._Algoritmo que realiza operación push en una pila
void pushd(int dato) 
{ 
	nodop *q = NuevoElem();
	q->liga = pil;
	q->info = dato; 
	pil = q;
}
 
/*2._Algoritmo que realiza la operación pop*/ 
int popd(void) 
{ 
	nodop *q; 
	int x;
	
  	if (pil==NULL) 
	{
		printf("PILA VACIA !!\n"); 
	}
  	else{
  		
  		x = pil->info;
  		q = pil;
  		pil = pil->liga;
  		free(q);
  		printf("ELEMENTO ELIMINADO CON EXITO!!\n"); 
  		return x;
		}	
}
 
nodop *NuevoElem() //Crea un nuevo elemento y regresa un puntero
{ 
	nodop *q = (nodop *)malloc(sizeof(nodop));
  	return q;
}
 
 /*3._Algoritmo que imprime el contenido*/
void imprimirpilas(nodop *pil) //Imprime todos los datos 
{
 	if(pil==NULL)
	{ 
		printf("\nNO EXISTEN ELEMENTOS EN LA PILA");
	}
	
	else{
		
 		while(pil!=NULL)
 		{
	 		printf("-  %d  -\n", pil->info);
 			pil = pil->liga;
 		}
	}
 	printf("\n");
 
}
 

typedef struct NODOcolas{
	int INFO;
    struct NODOcolas *LIGA;
}NODOh;
 void COLAeliminaInicio();
NODOh *PP, *FF;
void COLArecorrer();
 void COLAinsertarXfinal();
 
void menu_colas(){
	int opc;
	int k;
	  while(opc!=4)
	  {
	  	system("pause");
	  	system("cls");
	 	printf("\n\t\tCOLAS");
	 	printf("\n\t\tMEMORIA DINAMICA\n\n");
	    printf(" 1. INSERTAR ELEMENTOS A LA COLA [ PUSH ]\n");
	    printf(" 2. ELIMINAR ELEMENTOS DE LA COLA [ POP ]\n");
	    printf(" 3. IMPRIMIR\n");
	    printf(" 4. SALIR\n\n");
	    printf(" SELECCIONA UNA OPCION: ");
	    scanf("%d",&opc);
	    switch(opc)
		  	{
		  		case 1: COLAinsertarXfinal();
						break;
		  		case 2: COLAeliminaInicio();
				  		break;
		  		case 3: COLArecorrer();
						break;
		  		
		  		case 4: exit(0);
		  		default: printf("\nSaliendo del programa...");
		  	}
	}
}
 
void COLArecorrer(){
	NODOh *AUX;
    
	if(PP==NULL) printf(" LISTA VACIA\n"); 
	else{
	  
    AUX=PP;
    printf("\n");
    while(AUX!=NULL){
    	printf("%d->",AUX->INFO);    
		AUX=AUX->LIGA;  	
	}
	printf("\n");
}
}
 
 void COLAinsertarXfinal() {
      
	NODOh *Q = (NODOh *) malloc (sizeof(NODOh));
 	printf("DAME EL ELEMENTO: ");
    scanf("%d",&Q->INFO);
    
    Q->LIGA=NULL;
    
    if (PP==NULL){
         PP = Q;
         FF = Q;
         }
      else{
           FF->LIGA = Q;
		   FF = Q;
      }
    	  
 }
 

 void COLAeliminaInicio(){
 	NODOh *Q;
 	
 	if(PP==NULL) printf(" LISTA VACIA\n"); 
	else{
 	
 	Q=PP;
 	PP=Q->LIGA;
 	free(Q);
 	printf("ELIMINADO CON EXITO !!!\n");
 		
 }
}
 
 

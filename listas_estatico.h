void agregar_lista_por_el_principio(int arreglo[],int tamanio,int i,int n);
void imprimir(int arreglo[],int tamanio,int i,int n);
void busquedaE(int arreglo[],int tamanio,int i,int n);
void insertar_por_el_final(int arreglo[],int tamanio,int i,int n);
void elimina_el_ultimo_elemento(int arreglo[],int tamanio,int i,int n);
void inserta_un_elemento_al_principio(int arreglo[],int tamanio,int i,int n);
void crea_una_lista_por_el_final(int arreglo[],int tamanio,int i,int n);
void elimina_el_primer_elemento(int arreglo[],int tamanio,int i,int n);
void inserta_elemento_antes_de_uno_dado_uno_como_referencia(int arreglo[],int tamanio,int i,int n);
void inserta_elemento_dado_uno_como_referencia(int arreglo[],int tamanio,int i,int n);
void elimina_elemento_antes_de_uno_dado_uno_como_referencia(int arreglo[],int tamanio,int i,int n);
void elimina_elemento_despues_de_uno_dado_uno_como_referencia(int arreglo[],int tamanio,int i,int n);

void elimina_elemento_despues_de_uno_dado_uno_como_referencia(int arreglo[],int tamanio,int i,int n){

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

		if(ref==arreglo[n-1]){
			for(i=0; i<n; i++)
			printf("%i->",arreglo[i]);
		}
		else{
		for(i=0;i<pib+1;i++){
			arre[i]=arreglo[i];
		}
		for(i=pib+2; i<n+1; i++){
			arre[i-1]=arreglo[i];
		}
		printf("\n");
		for(i=0; i<n-1;i++){
			printf("%i->",arre[i]);
		}
		  printf("NULL\n");
		}
	}}
}
void elimina_elemento_antes_de_uno_dado_uno_como_referencia(int arreglo[],int tamanio,int i,int n){

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
			printf("%i->",arreglo[i]);
		}
		else{
			for(i=0;i<pib-1;i++){
			arre[i]=arreglo[i];
		}
		for(i=pib-1; i<n+1; i++){
			arre[i]=arreglo[i+1];
		}
		printf("\n");
		for(i=0; i<n-1;i++){
			printf("%i->",arre[i]);
		}
		printf("NULL\n");
		}
	}}
}
void inserta_elemento_dado_uno_como_referencia(int arreglo[],int tamanio,int i,int n){

	int ref,agre,b=0,pib,arre[10];
	if(arreglo[0]==0){
		printf("\nLISTA VACIA\n");
	}
	else{
	if(arreglo[0]==0){
		printf("\nLISTA VACIA\n");
	}
	else{
	printf("\nELEMENTO DADO COMO REFERENCIA:");
	scanf("%i",&ref);
	for(i=0; i<n; i++){
		if(ref==arreglo[i]){
			pib=i+1; b=1;
		}
	}
	if(b==0){
		printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
	}
	if(b==1) {
		printf("ELEMENTO:");
		scanf("%i",&agre);
		for(i=0;i<pib;i++){
			arre[i]=arreglo[i];
		}
		arre[pib]=agre;
		for(i=pib+1; i<n+1; i++){
			arre[i]=arreglo[i-1];
		}
		printf("\n");
		for(i=0; i<n+1;i++){
			printf("%i->",arre[i]);
		}
		printf("NULL\n");
	}}}
}
void inserta_elemento_antes_de_uno_dado_uno_como_referencia(int arreglo[],int tamanio,int i,int n){

	int ref,agre,b=0,pib,arre[10];
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
		printf("ELEMENTO:");
		scanf("%i",&agre);
		for(i=0;i<pib;i++){
			arre[i]=arreglo[i];
		}
		arre[pib]=agre;
		for(i=pib+1; i<n+1; i++){
			arre[i]=arreglo[i-1];
		}
		printf("\n");
		for(i=0; i<n+1;i++){
			printf("%i->",arre[i]);
		}
		printf("NULL\n");
	}}
}
void elimina_el_primer_elemento(int arreglo[],int tamanio,int i,int n)	{
	int arre[10];
	if(arreglo[0]==0){
		printf("\nLISTA VACIA\n");
	}
	else{
	for(i=0; i<n-1; i++)
		arre[i]=arreglo[i+1];
	printf("\n\n");
	for(i=0; i<n-1; i++){
		printf("%i->",arre[i]);
	}
	printf("NULL\n");
}
}

void crea_una_lista_por_el_final(int arreglo[],int tamanio,int i,int n){

		for(i=n-1; i>=0; i--){
		printf("ELEMENTO:");
		scanf("%i",&arreglo[i]);
	}
	for(i=0; i<n; i++){
		printf("%i->",arreglo[i]);
	}
	printf("NULL\n");
}

void inserta_un_elemento_al_principio(int arreglo[],int tamanio,int i,int n){
	int arre[10];
	for(i=0; i<n; i++){
		arre[i+1]=arreglo[i];
	}
	printf("ELEMENTO:");
	scanf("%i",&arre[0]);
	for(i=0; i<n+1; i++){
		printf("%i->",arre[i]);
	}
	printf("NULL\n");
}

void elimina_el_ultimo_elemento(int arreglo[],int tamanio,int i,int n){
	if(arreglo[0]==0){
		printf("\nLISTA VACIA\n");
	}
	else{
	arreglo[n]=0;
	n--;
	for(i=0; i<n; i++){
		printf("%i->",arreglo[i]);
	}
	printf("NULL\n");
    }
}
void insertar_por_el_final(int arreglo[],int tamanio,int i,int n){
	if(arreglo[0]==0){
		printf("\nLISTA VACIA\n");
	}
	else{
	printf("ELEMENTO:");
	scanf("%i",&arreglo[n]);
	printf("\n");
	for(i=0;i<n+1; i++){
		printf("%i->",arreglo[i]);
	}
	printf("NULL\n");
    }
}
void busquedaE(int arreglo[],int tamanio,int i,int n){
	int a,b=0;
	if(arreglo[0]==0){
		printf("\nLISTA VACIA\n");
	}
	else{
	printf("\nELEMENTO A BUSCAR:");
	scanf("%i",&a);
	for(i=0; i<n; i++){
		if(a==arreglo[i])
		b=1;
	}
	if(b==0)
	printf("\nEL ELEMENTO NO ESTA EN LA LISTA\n");
	if(b==1)
	printf("\nEL ELEMENTO SI ESTA EN LA LISTA\n");
}
}
void imprimir(int arreglo[],int tamanio,int i,int n){
	if(arreglo[0]==0){
		printf("\nLISTA VACIA\n");
	}
	else{
	    printf("\n");
	    for(i=0; i<n; i++){
		    printf("%i->",arreglo[i]);
	    }
	    printf("NULL\n");
	}
}

void agregar_lista_por_el_principio(int arreglo[],int tamanio,int i,int n){

	for(i=0; i<n; i++){
	    printf("ELEMENTO:");
	    scanf("%i",&arreglo[i]);

	}
	printf("\n");
	for(i=0; i<n; i++){
		printf("%i->",arreglo[i]);
	}
	printf("NULL\n");
}


void menu_simples_estatico() {
	int arreglo[10]={0};
	int i=0,n,resp;
	int r;
	printf("\nLONGITUD DEL ARREGLO:");
	scanf("%i",&n);
	system("cls");
	do{
		printf("\t\tLISTAS SIMPLES\n");
		printf("\t\tMEMORIA ESTATICA\n\n");
		printf("1.CREA UNA LISTA AGREGANDO CADA NODO AL INICIO\n");
		printf("2.RECORRE  E IMPRIME EL CONTENIDO DE UNA LISTA\n");
		printf("3.BUSCAR UN ELEMENTO CON CIERTA INFORMACION\n");
		printf("4.INSERTA SOLO UN ELEMENTO AL FINAL DE UNA LISTA\n");
		printf("5.ELIMINA EL ULTIMO ELEMENTO DE LA LISTA\n");
		printf("6.INSERTA SOLO UN ELEMENTO POR EL PRINCIPIO\n");
		printf("7.CREA UNA LISTA POR EL FINAL\n");
		printf("8.BORRA UN ELEMENTO POR EL PRINCIPIO\n");
		printf("9.INSERTA UN NODO ANTES DE UNO DADO COMO REFERENCIA\n");
		printf("10.INSERTA UN NODO DESPUES DE UNO DADO COMO REFERENCIA\n");
		printf("11.ELIMINA UN NODO ANTES DE UNO DADO COMO REFERENCIA\n");
		printf("12.ELIMINA UN NODO DESPUES DE UNO DADO COMO REFERENCIA\n");
		printf("13) SALIR\n");
		printf("\nOPCION:");
		scanf("%d",&resp);
		system("cls");
		switch(resp)
		{
			case 1: agregar_lista_por_el_principio(arreglo,10,i,n);break;
			case 2: imprimir(arreglo,10,i,n);break;
			case 3: busquedaE(arreglo,10,i,n);break;
			case 4:	insertar_por_el_final(arreglo,10,i,n);break;
			case 5: elimina_el_ultimo_elemento(arreglo,10,i,n);break;
			case 6: inserta_un_elemento_al_principio(arreglo,10,i,n);break;
			case 7: crea_una_lista_por_el_final(arreglo,10,i,n);break;
			case 8:	elimina_el_primer_elemento(arreglo,10,i,n);break;
			case 9:	inserta_elemento_dado_uno_como_referencia(arreglo,10,i,n);break;
			case 10: inserta_elemento_antes_de_uno_dado_uno_como_referencia(arreglo,10,i,n);break;
			case 11: elimina_elemento_antes_de_uno_dado_uno_como_referencia(arreglo,10,i,n);break;
			case 12: elimina_elemento_despues_de_uno_dado_uno_como_referencia(arreglo,10,i,n);break;
			case 13: exit(0);break;
		}
		printf("\nDESEA HACER OTRA ACCION? SI=1 NO=2:");
		scanf("%d",&r);
		system("cls");

	}while(r==1);
}

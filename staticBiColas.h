//Bicolas Static

//Funciones prototipo
void BiColasStaticMen();
void subMenu();
void recorridoDerecha(int*);
void agregarInicio(int*);
void agregarFinal(int*);
void eliminarInicio(int*);
void eliminarFinal(int*);
int libre(int*);
void printCola(int cola[]);
void BER();
void BSR();

//imprimir la cola
void printCola(int cola[]){
	int i=0;
	
	printf("COLA\n");
	
	while( (cola[i] != -1) && ( i < 10 ) ){
		printf("%d.- %d\n",i+1, cola[i]);
		i++;
	}
	
	system("pause");
}

//Menu
void BiColasStaticMen(){
	char option;
	do{
		printf("BICOLAS\n");
		printf("1) BICOLAS DE ENTRADA RESTRINGIDA (BER)\n");
		printf("2) BICOLA DE SALIDA RESTRINGIDA (BSR)\n");
		printf("3) REGRESAR AL MENU\n");
		printf("4) SALIR DEL PROGRAMA\n");
			fflush(stdin);
			scanf("%c",&option);
			
		//Limpiar pantalla y optiones
		system("cls");
		switch ( option ){
			case '1':
				BER();
				break;
			case '2':
				BSR();
				break;
			case '3':
					return;
				break;
			case '4':
				exit(0);
				break;
		}
	}while( ( option < 49 ) || ( option > 53 ) );
}

//Submenu
void subMenu(){
	printf("1) AGREGAR ELEMENTOS A LA COLA\n");
	printf("2) ELIMINAR UN ELEMENTO DE LA COLA\n");
	printf("3) IMPRIMIR COLA\n");
	printf("4) REGRESAR MENU\n");
	printf("5) SALIR DEL PROGRAMA\n");
	printf("OPCION:");
}

//Posicion libre
int libre(int* cola){
	int i;
	for ( i = 0; i < 10; i++ ){
		if( cola[i] == -1)
			return i;
	}
	
	return -1;
}

//Desplazar a la derecha
void recorridoDerecha(int* cola){
	int index;
	int temp;
	
	for( index = libre(cola); index > 0 ; index-- ){
		cola[index] = cola[ ( (index) -1 ) ];
	}
}

//Eliminar primer elemento
void eliminarInicio(int* cola){
	//Variables
	int temp = libre(cola);
	int i=0;
	
	//Casos
	if( temp == 0 ){
		printf("NO HAY ELEMENTOS EN LA COLA\n");
		system("pause");
	}else if ( temp == 1 ){
		cola[0] = -1;
	}else{
		for ( i = 0; i < 9; i++ ){
			cola[i] = cola[i+1];
		}
		cola[9] = -1;
	}
}

//Eliminar ultimo elemento
void eliminarFinal(int* cola){
	//Variables
	int temp = libre(cola);
	
	//Casos
	if( temp == 0 ){
		printf("NO HAY ELEMENTOS EN LA COLA\n");
		system("pause");
	}else if ( temp == 1 ){
		cola[0] = -1;
	}else if( temp == -1 ){
		cola[9] = -1;
	}
	else{
		cola[temp-1] = -1;
	}
}

//Agregar por el inicio
void agregarInicio(int *cola){
	int index = libre(cola);
	int temp;
	
	if( index == -1 ){
		printf("NO HAY ESPACIO\n");
		system("pause");
	}else{
		do{
			recorridoDerecha(cola);
			printf("VALOR ENTERO:");
			scanf("%d",&temp);
		}while( temp < 0 );
		cola[0] = temp;
	}
}

//Agregar por el final
void agregarFinal(int *cola){
	int index = libre(cola);
	int temp;
	
	if( index == -1 ){
		printf("NO HAY ESPACIO\n");
		system("pause");
	}else{
		do{
			printf("VQLOR ENTERO:");
			scanf("%d",&temp);
		}while( temp < 0 );
		cola[index] = temp;
	}
}

//Entrada Restringuida
void BER(){
	//Variables
	int cola[10],i;
	char select;
	
	for( i = 0; i < 10; i++ ){
		cola[i] = -1;
	}
	
	do{
		//Titulo
		system("cls");
		printf("BICOLA DE ENTRADA RESTRINGIDA\n");
		
		//Seleccion orden de eliminacion
		printf("SELECCIONE EL ORDEN DE ELIMINACION\n");
			printf("1) POR EL PRINICPIO\n");
			printf("2) POR EL FINAL\n");
		fflush(stdin);
		scanf("%c",&select);
	}while( ( select != '1' ) && ( select != '2' ) );
	
	if ( select == '1' ){
		printf("ELIMINAR POR EL PRINICPIO\n");
			system("pause");
			
		do{
			system("cls");
			printf("BICOLAS DE ENTRADA RESTRINGIDA\n\n");
			subMenu();
				fflush(stdin);
				scanf("%c",&select);
			
			switch ( select ){
				case '1':
						agregarFinal(cola);
					break;
				case '2':
						eliminarInicio(cola);
					break;
				case '3':
						printCola(cola);
					break;
				case '5':
						exit(0);
					break;
			}
		}while( select != '4' );
	}else{
		printf("ELIMINAR ELEMENTOS POR EL FINAL\n");
			system("pause");
			
		do{
			system("cls");
			printf("BICOLA DE ENTRADA RESTRINGIDA\n\n");
			subMenu();
				fflush(stdin);
				scanf("%c",&select);
			
			switch ( select ){
				case '1':
						agregarFinal(cola);
					break;
				case '2':
						eliminarFinal(cola);
					break;
				case '3':
						printCola(cola);
					break;
				case '5':
						exit(0);
					break;
			}
		}while( select != '4' );
	}
}

//Salida Restringuida
void BSR(){
	//Variables
	int cola[10],i;
	char select;
	
	for( i = 0; i < 10; i++ ){
		cola[i] = -1;
	}
	
	do{
		//Titulo
		system("cls");
		printf("BICOLA DE SALIDA RESTRINGIDA\n");
		
		//Seleccion orden de eliminacion
		printf("SELECCIONE EL ORDEN DE INSERCION\n");
			printf("1) POR EL PRINICPIO\n");
			printf("2) POR EL FINAL\n");
		fflush(stdin);
		scanf("%c",&select);
	}while( ( select != '1' ) && ( select != '2' ) );
	
	if ( select == '1' ){
		printf("SELECCION INSERSION POR EL PRINCIPIO\n");
			system("pause");
			
		do{
			system("cls");
			printf("BICOLA DE SALIDA RESTRINGIDA\n\n");
			subMenu();
				fflush(stdin);
				scanf("%c",&select);
			
			switch ( select ){
				case '1':
						agregarInicio(cola);
					break;
				case '2':
						eliminarFinal(cola);
					break;
				case '3':
						printCola(cola);
					break;
				case '5':
						exit(0);
					break;
			}
		}while( select != '4' );
	}else{
		printf("SELECCION: INSERCION DE ELEMENTOS POR EL FINAL\n");
			system("pause");
			
		do{
			system("cls");
			printf("BICOLA DE ENTRADA RESTRINGIDA\n\n");
			subMenu();
				fflush(stdin);
				scanf("%c",&select);
			
			switch ( select ){
				case '1':
						agregarFinal(cola);
					break;
				case '2':
						eliminarFinal(cola);
					break;
				case '3':
						printCola(cola);
					break;
				case '5':
						exit(0);
					break;
			}
		}while( select != '4' );
	}
}

void menu_grafos()
{
	printf("\n\t\tGRAFOS");
 	printf("\n\t\tMEMORIA ESTATICA\n\n");
	int i,j,N,L,cont=0;
	int aux1,aux2;
	char r,resp;
	do
	{
		printf("1) CONVIERTE UNA MATRIZ INCIDENCIA A UNA DE ADYASENCIA\n\n");
		printf("CUANTAS LINEAS:");
		scanf("%d",&L);
		printf("\nCUANTOS NODOS:");
		scanf("%d",&N);
		system("cls");
		int arreglo[L][N]; //matriz de incidencia
		int adyacente[L][L]; //matriz de adyacencia
		for(i=1;i<=L;i++)
		{
			for(j=1;j<=L;j++)
			{
				adyacente[i][j]=0; //inicializamos el arreglo
			}
		}
		for(i=1;i<=L;i++)
				for(j=1;j<=N;j++)
				{
					arreglo[i][j]=0; //inicializamos el arreglo
				}


			for(i=1;i<=N;i++)
			{
				printf("\t\tLECTURA DE MATRIZ DE INCIDENCIA POR COLUMNAS\n");
				cont=0;
				aux1=0; aux2=0;
				for(j=1;j<=L;j++)
				{
					printf("TIENE DATOS EN EL ARREGLO? [%d][%d] S/N	:",j,i);
					fflush(stdin);
					r=getchar();
					//lectura de 1's
					if(r=='s'	|| r=='S')
					{
						arreglo[j][i]=1;
						if(arreglo[j][i]==1)
						{
							cont=cont+1;

							if(cont==1 ) //si llega a haber solo un 1 el nodo apunta a si mismo
							{
								aux1=j; //guardamos el primer si
								if(j==L)
								adyacente[aux1][aux1]=1;
							}
							if(cont==2)
							{
								aux2=j; //cuando contador ya sea mayor de 2 guardamos el último si
								adyacente[aux1][aux2]=1;
								adyacente[aux2][aux1]=1; //guardara 1 de ambos lados.
							}

							if(cont>=3 && arreglo[j][i]==1) //si el contador ya es mayor o igual a 3
							{
								arreglo[j][i]=0; //no puede haber más de 2 unos por columna.

							}
						}
					}
					else if(r=='n'	|| r=='N')
					{
						arreglo[j][i]=0;
					}
				}
			system("cls");
			}
			printf("\n\t\tMATRIZ DE INCIDENCIA\n");
			for(i=1;i<=L;i++)
			{
				for(j=1;j<=N;j++)
				{
					printf("||%d||",arreglo[i][j]);
				}
						printf("\n");
			}

			printf("\n\t\tMATRIZ DE ADYACENCIA\n");
			for(i=1;i<=L;i++)
			{

				for(j=1;j<=L;j++){
					printf("||%d||",adyacente[i][j]);
				}
				printf("\n");
			}
		system("pause");
		printf("DESEA REPETIR PROGRAMA S/N:");
		fflush(stdin);
		resp=getchar();
	}while(resp=='s'||resp=='S');
    system("cls");
}

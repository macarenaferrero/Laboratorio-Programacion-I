

int promediarNumeros(int operador1,int operador2)
{
	float promedioFinal;

	promedioFinal = (float)operador1/operador2;
	return promedioFinal;
}

int getInt (char mensaje[100], char mError[100], int min, int max)
{
	int ingresoDeOperador;

	printf("%s", mensaje);
	scanf("%d", &ingresoDeOperador);

	while(ingresoDeOperador>max || ingresoDeOperador<min)
	{
		printf("%s", mError);
		scanf("%d", &ingresoDeOperador);
	}
	return ingresoDeOperador;
}

int esPositivo(int operador1)
{

	int positividad;
	if(operador1>=0)
	{
		positividad=1;
	}else
	{
		positividad=0;
	}
	return positividad;
}

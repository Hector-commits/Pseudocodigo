#define TRUE 1

void ProcesoA()
{
	mensaje X;
	while(true)
	{
		/* Código previo */
		receive(buzon1,X);	/* Esperar a que el proceso B realice una acción */
		/* Código posterior */
	}
}
void ProcesoB()
{
	mensaje Y;
	while(true)
	{
		/* Realizar acción para el proceso A */
		send(buzon1,Y);	/* Avisar al proceso A */
		/* Código posterior */
	}
}
void main()
{
	crear_buzón(buzon1);
	ejecución_concurrente(procesoA, procesoB);
}
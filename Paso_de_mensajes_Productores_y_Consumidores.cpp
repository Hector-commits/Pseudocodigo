#define TRUE 1
#define N 100 //* Tamaño del buffer */

void productor()
{
	mensaje X;
	while(true)
	{
		receive(buzón_produzca,X);
		producir_dato(X);
		send(buzón_consuma,X);
	}
}
void consumidor()
{
	mensaje Y;
	while(true)
	{
		receive(buzón_consuma,Y);
		consumir_dato(Y);
		send(buzón_produzca,Y);		
	}
}
void main()
{
	int h;
	mensaje nulo;
	
	crear_buzón(buzón_consuma);
	crear_buzón(buzón_produzca);
	for(h=1; h<=N,h++)
	{
		send(buzón_produzca,nulo)
	}
	ejecución_concurrente(productor,consumidor);
}
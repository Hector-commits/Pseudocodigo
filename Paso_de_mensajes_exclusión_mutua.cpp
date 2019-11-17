#define TRUE 1
#define N 5 //* Número de procesos */

void Proceso (int i)
{
	mensaje testigo;
	while(true)
	{
		/* sección no crítica */
		receive(buzon1,testigo);
		/* sección crítica */
		send(buzon1,testigo);
		/* sección no crítica */
	}
}

void main()
{
	mensaje nulo;
	crear_buzón(buzon1);
	end(buzon1,nulo);
	ejecución_concurrente(proceso(1),.......,proceso(N));
}
#define TRUE 1
#define FALSE 0
int mesas_libres=M //* Tamaño del restaurante = M */
bool aviso_de_pago=false;
mensaje men;

void proceso_cliente()						/* Proceso cliente */
{
	while(true)								/* Los clientes vienen al restaurante sin parar */
	{
		{
		if (mesas_libres==0) 
			{
			salir();
			}
		else	
		{
			reservar();
			mesas_libres= mesas_libres - 1;
			coger_comida();
			aviso_de_pago = true;
			pagar();
			comer();
			mesas_libres= mesas_libres + 1;
			salir();
		}
	}
}
void proceso_dependiente()					/* Proceso dependiente */
{
	while(true)
	{
		if (aviso_de_pago==false)
			{
				reponer();
			}
		else	
			{
				cobrar();
				aviso_de_pago=false;
			}
	}
	
}
void main()
{
	ejecución_concurrente(proceso_cliente,proceso_dependiente);
}
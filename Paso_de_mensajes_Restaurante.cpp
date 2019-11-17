#define TRUE 1
#define FALSE 0
int mesas_libres=M //* Tamaño del restaurante = M */ /* la escritura en esta variable es sección crítica */
bool aviso_de_pago=false;
mensaje men;

void proceso_cliente()						/* Proceso cliente */
{
	while(true)								/* Los clientes vienen al restaurante sin parar */
	{
		buscar_mesa_libre();
		receive(buzón_comer,men);
		{
		if (mesas_libres==0) 
			{
			salir();
			send(buzón_comer,men);
			}
		else	
		{
			reservar();
			mesas_libres= mesas_libres - 1;
			send(buzón_comer,men);
			coger_comida();
			aviso_de_pago = true;
			pagar();
			comer();
			receive(buzón_comer,men);
			mesas_libres= mesas_libres + 1;
			send(buzón_comer,men);
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
	crear_buzón(buzón_comer);
	ejecución_concurrente(proceso_cliente,proceso_dependiente);
}
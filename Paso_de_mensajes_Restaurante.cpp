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
			receive(pagar,men);
			receive(buzón_cobrar,men);
			aviso_de_pago = true;
			send(buzón_cobrar,men);
			pagar();
			send(pagar,men);
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
		receive(buzón_cobrar,men);
		if (aviso_de_pago==false)
			{
				send(buzón_cobrar,men);
				reponer();
			}
		else	
			{
				cobrar();
				aviso_de_pago=false;
				send(buzón_cobrar,men)
			}
	}
	
}
void main()
{
	/* Creamos los buzones */
	crear_buzón(buzón_comer);
	crear_buzón(buzón_cobrar);
	crar_buzón(pagar);
	/* Inicializamos los buzones */
	send(buzón_comer,men);
	send(buzón_cobrar,men);
	send(pagar,men);
	/* Ejecutamos ambos procesos a la vez */
	ejecución_concurrente(proceso_cliente,proceso_dependiente);
}
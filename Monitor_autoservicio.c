#define TRUE 1
#define N 100							//* Capacidad del restaurante */
monitor autoservicio					//* Definición del monitor */
	condición sitio_disponible,pago_disponible;
	int contadorRestaurante, contadorColaPago;
	
	void reservar_sitio();				/* Procedimiento del monitor */
	{
		if (contadorRestaurante==N) wait_mon(sitio_disponible);
		contadorRestaurante=contadorRestaurante+1;
	}
	void salir_del_restaurante(); 		/* Procedimiento del monitor */
	{
		contadorRestaurante=contadorRestaurante-1;
		signal_mon(sitio_disponible);
	}
	void iniciar_cola_de_pago(); 		/* Procedimiento del monitor */
	{
		if (contadorColaPago==1) wait_mon(pago_disponible);
		contadorColaPago=contadorColaPago+1;
	}
	void cobro_a_cliente();	 			/* Procedimiento del monitor */
	{
		if(contadorColaPago>0)
		{
			contadorColaPago=contadorColaPago - 1;
			signal_mon(pago_disponible);
		}
	}
end monitor

void dependiente()
{
	while(TRUE)
	{
		autoservicio.cobro_a_cliente();
		reponer();
	}
}

void cliente()
{
		autoservicio.reservar_sitio();
		coger_comida();
		
		autoservicio.iniciar_cola_pago();
		
		comer();
		autoservicio.salir_del_restaurante();
}

void main()
{
	ejecución_concurrente(cliente,cliente,cliente,...,dependiente);
}

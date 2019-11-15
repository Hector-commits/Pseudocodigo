//-----------------------------------MONITOR//
#define TRUE 1
#define N 100			//* Capacidad del buffer */
monitor mon1
	condición lleno, vacio;
	int contador;
	char buffer[N]
	void escribir(int dato) /* Procedimiento del monitor */
	{
		if (contador==N) wait_mon(lleno);
		insertar_dato(buffer,dato);
		contador=contador+1;
		if (contador==1) signal_mon(vacio);
	}
	void leer(int dato); /* Procedimiento del monitor */
	{
		if (contador==0) wait_mon(vacio);
		extraer_dato(bufer, dato);
		contador=contador-1;
		if (contador==N-1) signal_mon(lleno);
	}
	{
		contador=0; /* Inicialización del monitor */
	}
end monitor

void productor()
{
	while(TRUE)
	{
		dato=producir_dato();
		mon1.escribir(dato);
	}
}

void consumidor()
{
	while(TRUE)
	{
		mon1.leer(dato);
		consumir_dato(dato);
	}
}

void main()
{
	ejecución_concurrente(productor,consumidor)
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ----- Datos de niveles -----
    int LvlActual, LvlObjetivo;
    int XPActual, XPNivel;

    // ----- Experiencia -----
    int XPDiariaMin, XPDiariaMax;
    int XP_TotalNecesaria;
    int XP_Restante;
    int NivelesFaltantes;

    // ----- Tiempo -----
    int TiempoMinMin, TiempoMaxMin;
    float TiempoMinHoras, TiempoMaxHoras;

    // ----- Opciones de Pago -----
    int CostoNivelPorMonedaVirtual;
    int MonedaVirtualEnPaquete;
    int PrecioDelPaquete;

    int MonedasNecesarias;
    int PaquetesNecesarios;
    float CostoEnDolares;

    // ----- Resultados -----
    int DiasRapido, DiasLento;
    float HorasTotalesRapido, HorasTotalesLento;

    // ===== ENTRADAS =====
    printf("Nivel actual: ");
    scanf("%d", &LvlActual);

    printf("XP actual en la barra: ");
    scanf("%d", &XPActual);

    printf("XP necesaria para subir un nivel: ");
    scanf("%d", &XPNivel);

    printf("Nivel objetivo: ");
    scanf("%d", &LvlObjetivo);

    printf("Costo de subir un nivel (moneda virtual): ");
    scanf("%d", &CostoNivelPorMonedaVirtual);

    printf("Cantidad de moneda virtual por paquete: ");
    scanf("%d", &MonedaVirtualEnPaquete);

    printf("Precio del paquete (en dolares): ");
    scanf("%d", &PrecioDelPaquete);

    printf("XP diaria minima (1 mision): ");
    scanf("%d", &XPDiariaMin);

    printf("XP diaria maxima (todas las misiones): ");
    scanf("%d", &XPDiariaMax);

    printf("Tiempo diario minimo (en minutos): ");
    scanf("%d", &TiempoMinMin);

    printf("Tiempo diario maximo (en minutos): ");
    scanf("%d", &TiempoMaxMin);

    // ===== CALCULOS =====

    // Experiencia necesaria
    NivelesFaltantes = LvlObjetivo - LvlActual;
    XP_Restante = XPNivel - XPActual;

    XP_TotalNecesaria = XP_Restante + (NivelesFaltantes - 1) * XPNivel;

    // ----- Opciones de Pago -----

    // Monedas necesarias para subir niveles completos
    MonedasNecesarias = NivelesFaltantes * CostoNivelPorMonedaVirtual;

    // Paquetes necesarios (no se pueden comprar fracciones)
    PaquetesNecesarios = MonedasNecesarias / MonedaVirtualEnPaquete;
    if (MonedasNecesarias % MonedaVirtualEnPaquete != 0)
        PaquetesNecesarios++;

    // Costo total en dolares
    CostoEnDolares = PaquetesNecesarios * PrecioDelPaquete;

    // ----- Escenarios de Tiempo -----

    // Escenario rapido (mas XP diaria)
    DiasRapido = XP_TotalNecesaria / XPDiariaMax;
    if (XP_TotalNecesaria % XPDiariaMax != 0)
        DiasRapido++;

    // Escenario lento (menos XP diaria)
    DiasLento = XP_TotalNecesaria / XPDiariaMin;
    if (XP_TotalNecesaria % XPDiariaMin != 0)
        DiasLento++;

    // Conversion de tiempo
    TiempoMinHoras = TiempoMinMin / 60.0f;
    TiempoMaxHoras = TiempoMaxMin / 60.0f;

    // Tiempo total
    HorasTotalesRapido = DiasRapido * TiempoMaxHoras;
    HorasTotalesLento = DiasLento * TiempoMinHoras;

    // ===== SALIDA =====
    printf("\n===== RESULTADOS =====\n");

    printf("Experiencia total necesaria: %d XP\n\n", XP_TotalNecesaria);

    printf("PAGO INMEDIATO:\n");
    printf("- Monedas virtuales necesarias: %d\n", MonedasNecesarias);
    printf("- Paquetes necesarios: %d\n", PaquetesNecesarios);
    printf("- Costo total aproximado: %.2f USD\n\n", CostoEnDolares);

    printf("ESCENARIO RAPIDO (todas las misiones):\n");
    printf("- Dias necesarios: %d\n", DiasRapido);
    printf("- Horas totales aproximadas: %.2f\n\n", HorasTotalesRapido);

    printf("ESCENARIO LENTO (pocas misiones):\n");
    printf("- Dias necesarios: %d\n", DiasLento);
    printf("- Horas totales aproximadas: %.2f\n", HorasTotalesLento);

    system("pause");
    return 0;
}








/*Codigo para calcular los dias y la experiencia de un juego.

#include <stdio.h>

int XPG, n, Lvl, XPD, Dia, TotalDia, TotalXP;
char Var;
int i;

int main()
{
	printf("Introduzca la experiencia necesaria para subir un nivel: \n");
	scanf("%d", &XPG);
	
	printf("Introduzca el nivel al que quiere llegar: \n");
	scanf("%d", &Lvl);
	
	printf("La cantidad de experiencia necesaria para subir de un nivel varia? (Responda con 's' de si o 'n' de no) \n");
	scanf(" %c", &Var);
	
	if (Var == 's')
	{
		printf("Introduzca el ritmo al que la cantidad de experiencia para subir de nivel cambia (Ej. Si antes era 10 y al siguiente es 20, se dice que cambia a un ritmo de 2)");
		//FALTA POR TERMINAR
	}
	
	if (Var == 'n')
	{
		printf("Cuanta experiencia puede ganar a base de misiones diarias?\n");
		scanf ("%d", &XPD);
		
		printf("Cuantos dias de la semana puedes permitirte jugar?\n");
		scanf("%d", &Dia);
		
		if (Dia < 1 || Dia > 7)
		{
			printf("Error. Una semana solo tiene 7 dias.\n");
			
			system("pause");
			return 0;
		}
		
		else
		
		//hay que utilizar un loop alguno
		
		TotalXP = 0;
		TotalDia = 0;
		
		for (i = 1; TotalXP < XPG; i++)
		{
		TotalXP = TotalXP + XPD;		
		TotalDia = i;		
		}
		
		//Esto tiene unos errores de logica gordos
		
		printf("Experiencia total acumulada: %d\n", TotalXP);
		printf("Dias necesarios para alcanzar el nivel deseado: %d\n", TotalXP);
		
		system("pause");
		return 0;
	}
}

NOTA: AGREGAR OPCION QUE CONSIDERE OPCIONES DE PAGO*/


/*
 ============================================================================
 Name        : Game_suffragetto_tp.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Game_suffragetto_tp.h"

void menu(char tab[TAM_TAB][TAM_TAB]){

	printf("¡Bienvenido al juego  SUFFRAGETTO! \n");
	int opcion=0, resp1, resp2, alea;
	srand(time(NULL));

	do
	{


		printf("		MENU PRINCIPAL\n");

		printf("1) JUGAR \n");
		printf("2) REGLAS DE JUEGO \n");
		printf("3) INSTRUCCIONES DE USO \n");
		printf("4) CREDITOS \n");
		printf("5) SALIR \n\n");
		printf("Ingrese el numero de la opcion que desea ejecutar:");
		scanf("%d",&opcion);
		switch(opcion)
			{
		case 1:




			printf("			MODO DE JUEGO\n\n");
			printf("			QUIEN EMPIEZA?\n		1 - Las Sufragistas\n		2 - Los Policias\n 		3 - Aleatorio\n");
			scanf("%d", &resp1);
			if(resp1 == 3){
				alea = rand()%10;
				if(alea % 2 == 0){
					resp1 = 1;
				}else{
					resp1 = 2;
				}
			}
			printf("			Seleccion de fichas\n		1 - Las Sufragistas\n		2 - Los Policias\n		3 - Aleatorio\n");
			scanf("%d", &resp2);
			if(resp2 == 3){
				alea = rand()%10;
				if(alea % 2 == 0){
					resp2 = 1;
				}else{
					resp2 = 2;
				}
			}
			empieza = resp1;
			Modo = resp2;
			incio_Juego(tab);

			//system("PAUSE");

			break;
		case 2:
			reglas();


			break;
		case 3:

			printf("          ----------INSTRUCCIONES PARA USO DEL PROGRAMA---------\n\n");
			printf(" -El jugador puede elegir quién inicia el juego, quién será suffragetto y quién será policía. O bien los turnos y bandos se definen de forma aleatoria.\n\n -Para mover las piezas se deben introducir las coordenadas de la pieza a mover y las de la posicion a mover.\n\n -Las coordendas del tablero van desde (a) hasta (q) para las filas y desde (A) hasta (Q) para las columnas.\n\n -El programa se encargara de advertirle de errores o movimientos invalidos.\n\n -Cada movimiento valido que usted realice, podra sera corroborado en el tablero de juego.\n\n -Al finalizar el juego, el programa indicara cual es el bando ganador y perdedor.\n\n ");

			break;
		case 4:

			printf("           -----------CREDITOS----------\n\n");
			printf("          ----------PROGRAMADORES----------\n\n");
			printf("                    Julio Fernandez\n\n                          e\n\n                      Tania Romero\n\n");

			break;
		case 5:
			printf("¡Gracias por elegir jugar Suffragetto!\nDe parte de los creadores, agradecemos su tiempo y atencion.\n");
			break;
		default:

			printf("¡Ha ingresado un valor invalido!\n");
			printf("Favor ingrese una opcion del MENU PRINCIPAL.\n");

			break;
			}
	}while(opcion!=5);
}


void reglas(void){
	printf("          ----------REGLAS DE JUEGO----------\n\n");
	printf("- PIEZAS:\n  Tenemos 21 fichas por jugador; 5 fichas violetas y 16 fichas verdes para un jugador (suffragetto), 5 fichas blancas y 16 fichas azules para el otro\n  jugador (policía). Las fichas violetas representan a los líderes del bando Suffragetto y las blancas son los inspectores del bando Policía.\n\n");
	printf("- TABLERO: \n  El tablero es de 17x17, dividido en áreas (“Arena”, “Prison”, “Hospital”, “House of Commons”, “Albert Hall”), cada una de las cuales tiene\n  un propósito específico en el desarrollo del juego.\n\n");
	printf("- OBJETIVO DEL JUEGO: \n  El objetivo de ambos jugadores es ocupar el área protegida por sus enemigos. Así, los policías desean ocupar el “Albert Hall” mientras que los suffragetto\n  desean ocupar la región “House of Commons”. De esta forma el juego finaliza cuando una de estas dos regiones es ocupada completamente, y gana\n  el jugador que ubicó 6 fichas en la región deseada. Se busca principalmente ocupar la región protegida del enemigo, pero además\n  debe protegerse la región propia.\n  Los policías no pueden entrar a la zona de “House of Commons” ni los suffragetto pueden entrar en el “Albert Hall”. Asimismo, las zonas marcadas\n  como “Hospital” y “Prison” solo podrán utilizarse para almacenar las fichas inmovilizadas (los suffragetto arrestados van a prisión\n  y los policías golpeados van al hospital).\n\n");
	printf("- MOVIMIENTOS DE LAS FICHAS:\n  1-) Movimiento simple: una de sus fichas se mueve un lugar, en cualquiera de las 8 direcciones adyacentes (vertical, horizontal y diagonales)\n      siempre que la casilla destino sea válida.\n  2-) Salto:\n      a. Una de sus fichas puede saltar sobre otra ficha (tanto enemiga como propia) para moverse un poco más lejos. Ésta puede saltar en cualquier\n         dirección (vertical, horizontal y diagonales). El salto se realiza sobre una ficha y la celda destino debe ser válida para el movimiento\n         y debe estar vacía.\n      b. Los saltos permiten inhabilitar a fichas del enemigo de la siguiente forma:\n         i.   Si un suffragetto salta en diagonal sobre un policía dentro de la “Arena”, lo inhabilita y el policía es llevado al hospital;\n         ii.  Si un líder suffragetto salta en cualquier sentido sobre un policía dentro de la “Arena”, lo inhabilita y el policía es llevado al hospital;\n         iii. Si un policía salta en diagonal sobre un suffragetto dentro de la “Arena”, lo inhabilita y el suffragetto es llevado a la prisión;\n         iv.  Si un inspector de policía salta en cualquier sentido sobre un suffragetto dentro de la “Arena”, lo inhabilita y suffragetto es llevado\n              a la prisión;\n      c. Los movimientos que se realicen fuera de la “Arena” no provocarán que los suffragetto sean arrestados o que los policías vayan al hospital.\n      d. Si tiene la posibilidad, una ficha puede hacer saltos en cadena. Se limitará la cantidad de saltos en cadena a 3.\n\n");
	printf("Las fichas que hayan llegado al “Albert Hall” o a “House of Commons” solo podrán moverse dentro de esa área. No se permite pasar el turno.\nEl jugador que logre llevar 6 de sus fichas al área oponente, será el ganador. Esta versión de Suffragetto no permite intercambios.\n");

}


void incio_Juego(char tab[TAM_TAB][TAM_TAB]){
	int ganador = 1;
	if(empieza == 1){//empiezan las sufragistas
		if(Modo == 1){//el jugador es sufragista, empieza

			do{//hacer un do while hasta que la funcion con_de_gan de un nro diferente de 1
				cond_libertad(tab);//condicion de liberacion de fichas

				tablero(tab);
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano

				tablero(tab);
				mov_cp(tab);//juega la computadora
				cond_de_Gan(&ganador);
			}while(ganador == 1);
		}else{//la computadora empieza, su pieza son las suffragistas
			do{
				cond_libertad(tab);//condicion de liberacion de fichas
				tablero(tab);
				mov_cp(tab);//juega la computadora
				cond_de_Gan(&ganador);

				tablero(tab);
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano
			}while(ganador == 1);
		}
	}else{//empiezan los policias
		if(Modo  == 1){//el jugador es sufragista
			do{
				cond_libertad(tab);//condicion de liberacion de fichas

				tablero(tab);
				mov_cp(tab);//juega la computadora
				cond_de_Gan(&ganador);

				tablero(tab);
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano

			}while(ganador == 1);
		}else{//la computadora empieza, su pieza son los policias
			do{
				cond_libertad(tab);//condicion de liberacion de fichas

				tablero(tab);
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano

				tablero(tab);
				mov_cp(tab);//juega la computadora
				cond_de_Gan(&ganador);

			}while(ganador == 1);
		}
	}
}

void mov_cp (char tab[TAM_TAB][TAM_TAB]){
	int fila, colum, k = 0;//k auxiliar que ayuda a salir del do-while
	//Modo = 2;
	srand(time(NULL));
	if(Modo  == 1){//cuando empieza es igual a 1 significa que el usuario tiene las piezas de las sufragistas por lo tanto la computadora juega con la policia
		do{
			fila = rand()%16;//busca una posicion random
			colum = rand()%16;
			if(colum > 1){
				if(colum == 2){
					if(fila > 4){
						if(tab[fila][colum] == POLICIAS || tab[fila][colum] == INSPECTORES){
							k = 1;
						}
					}
				}
				else{
					if(tab[fila][colum] == POLICIAS || tab[fila][colum] == INSPECTORES){
						k = 1;
					}
				}
			}
		}while(k == 0);
		if(tab[fila][colum] == INSPECTORES || tab[fila][colum] == POLICIAS){
			mov_cp_pol_e_ins (fila, colum, tab);
		}
	}
	if(Modo  == 2){//si la eleccion del usuario fue jugar con los policias la computadora jugara con las sufragistas
		do{
			fila = rand()%16;
			colum = rand()%16;
			if(colum < 17){
				if(colum == 16){
					if(fila < 14){
						if(tab[fila][colum] == LIDERESAS || tab[fila][colum] == SUFRAGISTAS){
							k = 1;
						}
					}
				}
				else{
					if(tab[fila][colum] == LIDERESAS || tab[fila][colum] == SUFRAGISTAS){
						k = 1;
					}
				}
			}
		}while(k == 0);


		if(tab[fila][colum] == LIDERESAS || tab[fila][colum] == SUFRAGISTAS){
			mov_cp_suf_y_lid(fila, colum, tab);
		}
	}
}

void mov_us (char tab[TAM_TAB][TAM_TAB]){
	int val = 0;
	if(Modo  == 1){//eleccion del usuario jugar con las sufragistas
		do{
			printf("Juegan las Sufragistas.\nSeleccione la pieza a mover:\nPosicion de la fila (1-17): ");
			scanf("%d", &fila);
			printf("Posicion de la columna (1-17): ");
			scanf("%d",&colum);
			if(colum > 1){
				if(colum == 16){
					if(fila < 14){
						if(tab[fila][colum] == SUFRAGISTAS || tab[fila][colum] == LIDERESAS){
							val = 1;
						}
					}
				}
				else{
					if(tab[fila][colum] == SUFRAGISTAS || tab[fila][colum] == LIDERESAS){
						val = 1;
					}
				}
			}
			else if(val == 0){
				printf("\nSeleccion invalida.\n");
			}
		}while(val == 0);

		if(tab[fila][colum] == LIDERESAS || tab[fila][colum] == SUFRAGISTAS){
			mov_lid_o_suf(fila, colum, tab);
		}
	}

	if(Modo  == 2){//eleccion del usuario jugar con los policias
		do{
			printf("Juegan los Policias.\nSeleccione la pieza a mover:\nPosicion de la fila (1-17): ");
			scanf("%d", &fila);
			printf("Posicion de la columna (1-17): ");
			scanf("%d",&colum);
			if(colum > 1){
				if(colum == 2){
					if(fila > 4){
						if(tab[fila][colum] == POLICIAS || tab[fila][colum] == INSPECTORES){
							val = 1;
						}
					}
				}
				else{
					if(tab[fila][colum] == POLICIAS || tab[fila][colum] == INSPECTORES){
						val = 1;
					}
				}
			}
			else if(val == 0){
				printf("\nSeleccion invalida.\n");
			}
		}while(val == 0);

		if(tab[fila][colum] == INSPECTORES || tab[fila][colum] == POLICIAS){
			mov_ins_o_pol(fila, colum, tab);
		}
	}
}


void funcion_comer_ins_y_pol(int * k, int *x, int *y, int columna_f, int fila_f, int fila_i, int columna_i){
	int n, n1, k_au, x_au, y_au;
	n = fila_f - fila_i;//auxiliar que identifica el sentido en el que se quiere mover en las filas
	n1 = columna_f - columna_i;//auxiliar que identifica el sentido en el que se quiere mover en las columnas
	if(tab[fila_i][columna_i] == INSPECTORES){
		//diagonales
		if(n == 2 && n1 == 2){//si la posicion fila y columna es +2 y +2 entonces
			if((fila_i + 1 == 14 && columna_i + 1 == 8) || (fila_i + 1 == 13 && columna_i + 1 == 10)){
				k_au = 0;//verifica primero si es una posicion dentro de la arena donde la pieza ya no puede comer
			}else{
				if(tab[fila_i + 1][columna_i + 1] == LIDERESAS || tab[fila_i + 1][columna_i + 1] == SUFRAGISTAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
						k_au = 1;//jugada valida
						x_au = 1;
						y_au = 1;
					}
					else{
						k_au = 0;//jugada invalida
					}
				}else if(tab[fila_i + 1][columna_i + 1] == INSPECTORES || tab[fila_i + 1][columna_i + 1] == POLICIAS){
					//verifica si es un salto sobre una ficha aliada
					k_au = 2;//jugada valida para salto sobre aliado
					x_au = 1;
					y_au = 1;
				}else if(tab[fila_i + 1][columna_i + 1] == THE_ARENA ||tab[fila_i + 1][columna_i + 1] == ' ' ||tab[fila_i + 1][columna_i + 1] == ALBERT_HALL || tab[fila_i + 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
		}
		else if(n == -2 && n1 == -2){
			if((fila_i - 1 == 14 && columna_i - 1 == 8) || (fila_i - 1 == 13 && columna_i - 1 == 10)){
				k_au = 0;
			}else{
				if(tab[fila_i - 1][columna_i - 1] == LIDERESAS || tab[fila_i - 1][columna_i - 1] == SUFRAGISTAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
						k_au = 1;//jugada valida
						x_au = -1;
						y_au = -1;
					}
					else{
						k_au = 0;
					}
				}else if(tab[fila_i - 1][columna_i - 1] == INSPECTORES || tab[fila_i - 1][columna_i - 1] == POLICIAS){
					k_au = 2;
					x_au = -1;
					y_au = -1;
				}else if(tab[fila_i - 1][columna_i - 1] == THE_ARENA ||tab[fila_i - 1][columna_i - 1] == ' ' ||tab[fila_i - 1][columna_i - 1] == ALBERT_HALL || tab[fila_i - 1][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
		}
		else if(n == 2 && n1 == -2){
			if((fila_i + 1 == 13 && columna_i - 1 == 8) || (fila_i + 1 == 14 && columna_i - 1 == 10)){
				k_au = 0;
			}else{
				if(tab[fila_i + 1][columna_i - 1] == LIDERESAS || tab[fila_i + 1][columna_i - 1] == SUFRAGISTAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
						k_au = 1;//jugada valida
						x_au = 1;
						y_au = -1;
					}
					else{
						*k = 0;//jugada invalida
					}
				}else if(tab[fila_i + 1][columna_i - 1] == INSPECTORES || tab[fila_i + 1][columna_i - 1] == POLICIAS){
					k_au = 2;
					x_au = 1;
					y_au = -1;
				}else if(tab[fila_i + 1][columna_i - 1] == THE_ARENA ||tab[fila_i + 1][columna_i - 1] == ' ' ||tab[fila_i + 1][columna_i - 1] == ALBERT_HALL || tab[fila_i + 1][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
		}
		else if(n == -2 && n1 == 2){
			if((fila_i - 1 == 13 && columna_i + 1 == 8) || (fila_i - 1 == 14 && columna_i + 1 == 10)){
				k_au = 0;
			}else{
				if(tab[fila_i - 1][columna_i + 1] == LIDERESAS || tab[fila_i - 1][columna_i + 1] == SUFRAGISTAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
						k_au = 1;//jugada valida
						x_au = -1;
						y_au = 1;
					}
					else{
						k_au = 0;//jugada invalida

					}
				}else if(tab[fila_i - 1][columna_i + 1] == INSPECTORES || tab[fila_i - 1][columna_i + 1] == POLICIAS){
					k_au = 2;
					x_au = -1;
					y_au = 1;
				}else if(tab[fila_i - 1][columna_i + 1] == THE_ARENA ||tab[fila_i - 1][columna_i + 1] == ' ' ||tab[fila_i - 1][columna_i + 1] == ALBERT_HALL || tab[fila_i - 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
		}
		//vertical y horizontal
		else if(n == 0 && n1 == 2){
			if(tab[fila_i][columna_i + 1] == LIDERESAS || tab[fila_i][columna_i + 1] == SUFRAGISTAS){
				if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
					k_au = 1;//jugada valida
					x_au = 0;
					y_au = 1;
				}
				else{
					k_au = 0;//jugada invalida
				}
			}else if(tab[fila_i][columna_i + 1] == INSPECTORES || tab[fila_i][columna_i + 1] == POLICIAS){
				k_au = 2;
				x_au = 0;
				y_au = 1;
			}else if(tab[fila_i][columna_i + 1] == THE_ARENA ||tab[fila_i][columna_i + 1] == ' ' ||tab[fila_i][columna_i + 1] == ALBERT_HALL || tab[fila_i][columna_i + 1] == COMMONS_HOUSE){
				k_au = 0;//jugada invalida
			}
		}
		else if(n == 2 && n1 == 0){
			if(tab[fila_i+1][columna_i] == LIDERESAS || tab[fila_i+1][columna_i] == SUFRAGISTAS){
				if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
					k_au = 1;//jugada valida
					x_au = 1;
					y_au = 0;
				}
				else{
					k_au = 0;//jugada invalida

				}
			}else if(tab[fila_i + 1][columna_i] == INSPECTORES || tab[fila_i + 1][columna_i] == POLICIAS){
				k_au = 2;
				x_au = 1;
				y_au = 0;
			}else if(tab[fila_i + 1][columna_i] == THE_ARENA ||tab[fila_i + 1][columna_i] == ' ' ||tab[fila_i + 1][columna_i] == ALBERT_HALL || tab[fila_i + 1][columna_i] == COMMONS_HOUSE){
				k_au = 0;//jugada invalida
			}
		}
		else if(n == 0 && n1 == -2){
			if(tab[fila_i][columna_i - 1] == LIDERESAS || tab[fila_i][columna_i - 1] == SUFRAGISTAS){
				if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
					k_au = 1;//jugada valida
					x_au = 0;
					y_au = -1;
				}
				else{
					k_au = 0;
				}
			}else if(tab[fila_i][columna_i-1] == INSPECTORES || tab[fila_i][columna_i-1] == POLICIAS){
				k_au = 2;
				x_au = 0;
				y_au = -1;
			}else if(tab[fila_i][columna_i - 1] == THE_ARENA ||tab[fila_i][columna_i - 1] == ' ' ||tab[fila_i][columna_i - 1] == ALBERT_HALL || tab[fila_i][columna_i - 1] == COMMONS_HOUSE){
				k_au = 0;//jugada invalida
			}
		}
		else if(n == -2 && n1 == 0){
			if(tab[fila_i-1][columna_i] == LIDERESAS || tab[fila_i-1][columna_i] == SUFRAGISTAS){
				if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
					k_au = 1;//jugada valida
					x_au = -1;
					y_au = 0;
				}
				else{
					k_au = 0;//jugada invalida
				}
			}else if(tab[fila_i - 1][columna_i] == INSPECTORES || tab[fila_i - 1][columna_i] == POLICIAS){
				k_au = 2;
				x_au = -1;
				y_au = 0;
			}else if(tab[fila_i - 1][columna_i] == THE_ARENA ||tab[fila_i - 1][columna_i] == ' ' ||tab[fila_i - 1][columna_i] == ALBERT_HALL || tab[fila_i - 1][columna_i] == COMMONS_HOUSE){
				k_au = 0;//jugada invalida
			}
		}
	}
	else if(tab[fila_i][columna_i] == POLICIAS){
		if(n == 2 && n1 == 2){
			if((fila_i + 1 == 14 && columna_i + 1 == 8) || (fila_i + 1 == 13 && columna_i + 1 == 10)){
				k_au = 0;//verifica primero si es una posicion dentro de la arena que puede ser valida pero no lo es
			}else{
				if(tab[fila_i + 1][columna_i + 1] == LIDERESAS || tab[fila_i + 1][columna_i + 1] == SUFRAGISTAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
						k_au =1;//jugada valida
						x_au = 1;
						y_au = 1;
					}
					else {
						k_au = 0;//jugada invalida para comer
					}
				}else if(tab[fila_i + 1][columna_i + 1] == INSPECTORES || tab[fila_i + 1][columna_i + 1] == POLICIAS){
					k_au = 2;
					x_au = 1;
					y_au = 1;
				}else if(tab[fila_i + 1][columna_i + 1] == THE_ARENA ||tab[fila_i + 1][columna_i + 1] == ' ' ||tab[fila_i + 1][columna_i + 1] == ALBERT_HALL || tab[fila_i + 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
		}
		else if(n == -2 && n1 == -2){
			if((fila_i - 1 == 14 && columna_i - 1 == 8) || (fila_i - 1 == 13 && columna_i - 1 == 10)){
				k_au = 0;
			}else{
				if(tab[fila_i - 1][columna_i - 1] == LIDERESAS || tab[fila_i - 1][columna_i - 1] == SUFRAGISTAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
						k_au = 1;//jugada valida
						x_au = -1;
						y_au = -1;
					}
					else{
						k_au = 0;
					}
				}else if(tab[fila_i - 1][columna_i - 1] == INSPECTORES || tab[fila_i - 1][columna_i - 1] == POLICIAS){
					k_au = 2;
					x_au = -1;
					y_au = -1;
				}else if(tab[fila_i - 1][columna_i - 1] == THE_ARENA ||tab[fila_i - 1][columna_i - 1] == ' ' ||tab[fila_i - 1][columna_i - 1] == ALBERT_HALL || tab[fila_i - 1][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
		}
		else if(n == 2 && n1 == -2){
			if((fila_i + 1 == 13 && columna_i - 1 == 8) || (fila_i + 1 == 14 && columna_i - 1 == 10)){
				k_au = 0;
			}else{
				if(tab[fila_i + 1][columna_i - 1] == LIDERESAS || tab[fila_i + 1][columna_i - 1] == SUFRAGISTAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' '||tab[fila_f][columna_f] == ALBERT_HALL){
						k_au = 1;//jugada valida
						x_au = 1;
						y_au = -1;
					}
					else{
						k_au = 0;
					}
				}else if(tab[fila_i + 1][columna_i - 1] == INSPECTORES || tab[fila_i + 1][columna_i - 1] == POLICIAS){
					k_au = 2;
					x_au = 1;
					y_au = -1;
				}else if(tab[fila_i + 1][columna_i - 1] == THE_ARENA ||tab[fila_i + 1][columna_i - 1] == ' ' ||tab[fila_i + 1][columna_i - 1] == ALBERT_HALL || tab[fila_i + 1][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}

		}
		else if(n == -2 && n1 == 2){
			if((fila_i - 1 == 13 && columna_i + 1 == 8) || (fila_i - 1 == 14 && columna_i + 1 == 10)){
				k_au = 0;
			}else{
				if(tab[fila_i - 1][columna_i + 1] == LIDERESAS || tab[fila_i - 1][columna_i + 1] == SUFRAGISTAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == ALBERT_HALL){
						k_au = 1;//jugada valida
						x_au = -1;
						y_au = 1;
					}
					else{
						k_au = 0;//jugada invalida
					}
				}
				else if(tab[fila_i - 1][columna_i + 1] == INSPECTORES || tab[fila_i - 1][columna_i + 1] == POLICIAS){
					k_au = 2;
					x_au = -1;
					y_au = 1;
				}else if(tab[fila_i - 1][columna_i + 1] == THE_ARENA ||tab[fila_i - 1][columna_i + 1] == ' ' ||tab[fila_i - 1][columna_i + 1] == ALBERT_HALL || tab[fila_i - 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
		}else{//si no es un salto diagonal entonces es uno horizontal o vertical
			if(n == -2 && n1 == 0){
				if(tab[fila_i - 1][columna_i] == INSPECTORES || tab[fila_i - 1][columna_i] == POLICIAS){
					k_au = 2;
					x_au = -1;
					y_au = 0;
				}else if(tab[fila_i - 1][columna_i] == THE_ARENA ||tab[fila_i - 1][columna_i] == ' ' ||tab[fila_i - 1][columna_i] == ALBERT_HALL || tab[fila_i - 1][columna_i] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
			else if(n == 2 && n1 == 0){
				if(tab[fila_i + 1][columna_i] == INSPECTORES || tab[fila_i + 1][columna_i] == POLICIAS){
					k_au = 2;
					x_au = 1;
					y_au = 0;
				}else if(tab[fila_i + 1][columna_i] == THE_ARENA ||tab[fila_i + 1][columna_i] == ' ' ||tab[fila_i + 1][columna_i] == ALBERT_HALL || tab[fila_i + 1][columna_i] == COMMONS_HOUSE){
					k_au = 0;//jugada invalida
				}
			}
			else if(n == 0 && n1 == -2){
				if(tab[fila_i][columna_i - 1] == INSPECTORES || tab[fila_i][columna_i - 1] == POLICIAS){
					k_au = 2;
					x_au = 0;
					y_au = -1;
				}
				else if(tab[fila_i][columna_i - 1] == THE_ARENA ||tab[fila_i][columna_i - 1] == ' ' ||tab[fila_i][columna_i - 1] == ALBERT_HALL || tab[fila_i][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}else if(n == 0 && n1 == 2){
				if(tab[fila_i][columna_i + 1] == INSPECTORES || tab[fila_i][columna_i + 1] == POLICIAS){
					k_au = 2;
					x_au = 0;
					y_au = 1;
				}
				else if(tab[fila_i][columna_i + 1] == THE_ARENA ||tab[fila_i][columna_i + 1] == ' ' ||tab[fila_i][columna_i + 1] == ALBERT_HALL || tab[fila_i][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
	}else{
		k_au = 0;
	}
	*k = k_au;
	*x = x_au;
	*y = y_au;

	//printf("retorna k = %d, x = %d, y = %d", k_au, x_au, y_au);

}

void piezas_comidas_sl(int *fil, int *col, char tab[TAM_TAB][TAM_TAB]){
	int x = *fil, y = *col, i, j;
	for(i = 0; i < TAM_TAB; i++){
		for(j = 0; j < TAM_TAB; j++){
			if(tab[i][j] == PRISON){
				if(tab[x][y] == LIDERESAS){
					tab[i][j] = LIDERESAS;
					tab[x][y] = THE_ARENA;
				}
				if(tab[x][y] == SUFRAGISTAS){
					tab[i][j] = SUFRAGISTAS;
					tab[x][y] = THE_ARENA;
				}

			}
		}
	}
}

void piezas_comidas_pi(int *fil, int *col, char tab[TAM_TAB][TAM_TAB]){
	int x = *fil, y = *col, i, j;
	for(i = 0; i < TAM_TAB; i++){
		for(j = 0; j < TAM_TAB; j++){
			if(tab[i][j] == HOSPITAL){
				if(tab[x][y] == INSPECTORES){
					tab[i][j] = INSPECTORES;
					tab[x][y] = THE_ARENA;
				}
				if(tab[x][y] == POLICIAS){
					tab[i][j] = POLICIAS;
					tab[x][y] = THE_ARENA;
				}
			}
		}
	}
}

void funcion_comer(int * k, int *x, int *y, int columna_f, int fila_f, int fila_i, int columna_i){
	int n, n1, k_au, x_au, y_au;
	n = fila_f - fila_i;
	n1 = columna_f - columna_i;
//	printf("\nretorna n = %d, n1 = %d\n", n, n1);

	if(tab[fila_i][columna_i] == LIDERESAS){
		if(n == 2 && n1 == 2){
			if((fila_i + 1 == 5 && columna_i + 1 == 8) || (fila_i + 1 == 4 && columna_i + 1 == 10)){
				k_au = 0;//jugada invalida
			}else{
				if(tab[fila_i + 1][columna_i + 1] == INSPECTORES || tab[fila_i + 1][columna_i + 1] == POLICIAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
						k_au = 1;//jugada valida
					}
					else{
						k_au = 0;
					}
				}if(tab[fila_i + 1][columna_i + 1] == LIDERESAS || tab[fila_i + 1][columna_i + 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = 1;
					y_au = 1;
				}
				else if(tab[fila_i + 1][columna_i + 1] == THE_ARENA ||tab[fila_i + 1][columna_i + 1] == ' ' ||tab[fila_i + 1][columna_i + 1] == ALBERT_HALL || tab[fila_i + 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
		else if(n == -2 && n1 == -2){
			if((fila_i - 1 == 5 && columna_i - 1 == 8)||(fila_i - 1 == 4 && columna_i - 1 == 10)){
				k_au = 0;//jugada invalida
			}else{
				if(tab[fila_i - 1][columna_i - 1] == INSPECTORES || tab[fila_i - 1][columna_i - 1] == POLICIAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
						k_au = 1;//jugada valida
						x_au = -1;
						y_au = -1;
					}
					else{
						k_au = 0;
					}
				}if(tab[fila_i - 1][columna_i - 1] == LIDERESAS || tab[fila_i - 1][columna_i - 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = -1;
					y_au = -1;
				}
				else if(tab[fila_i - 1][columna_i - 1] == THE_ARENA ||tab[fila_i - 1][columna_i - 1] == ' ' ||tab[fila_i - 1][columna_i - 1] == ALBERT_HALL || tab[fila_i - 1][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
		else if(n == 2 && n1 == -2){
			if((fila_i + 1 == 4 && columna_i - 1 == 8)||(fila_i + 1 == 5 && columna_i - 1 == 10)){
				k_au = 0;//jugada invalida
			}else{
				if(tab[fila_i + 1][columna_i - 1] == INSPECTORES || tab[fila_i + 1][columna_i - 1] == POLICIAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
						k_au = 1;//jugada valida
						x_au = 1;
						y_au = -1;
					}
					else{
						k_au = 0;
					}
				}if(tab[fila_i + 1][columna_i - 1] == LIDERESAS || tab[fila_i + 1][columna_i - 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = 1;
					y_au = -1;
				}else if(tab[fila_i + 1][columna_i - 1] == THE_ARENA ||tab[fila_i + 1][columna_i - 1] == ' ' ||tab[fila_i + 1][columna_i - 1] == ALBERT_HALL || tab[fila_i + 1][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
		else if(n == -2 && n1 == 2){
			if((fila_i - 1 == 4 && columna_i + 1 == 8) || (fila_i - 1 == 5 && columna_i + 1 == 10)){
				k_au = 0;//jugada invalida
			}else{
				if(tab[fila_i - 1][columna_i + 1] == INSPECTORES || tab[fila_i - 1][columna_i + 1] == POLICIAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
						k_au = 1;//jugada valida
						x_au = -1;
						y_au = 1;
					}
					else{
						k_au = 0;
					}
				}else if(tab[fila_i - 1][columna_i + 1] == LIDERESAS || tab[fila_i - 1][columna_i + 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = -1;
					y_au = 1;
				}
				else if(tab[fila_i - 1][columna_i + 1] == THE_ARENA ||tab[fila_i - 1][columna_i + 1] == ' ' ||tab[fila_i - 1][columna_i + 1] == ALBERT_HALL || tab[fila_i - 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}//vertical y horizontal
		else if(n == 0 && n1 == 2){
			if(tab[fila_i][columna_i + 1] == INSPECTORES || tab[fila_i][columna_i + 1] == POLICIAS){
				if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
					k_au = 1;//jugada valida
					x_au = 0;
					y_au = 1;
				}
				else{
					k_au = 0;
				}
			}else if(tab[fila_i][columna_i + 1] == LIDERESAS || tab[fila_i][columna_i + 1] == SUFRAGISTAS){
				k_au = 2;
				x_au = 0;
				y_au = 1;
			}
			else if(tab[fila_i][columna_i + 1] == THE_ARENA ||tab[fila_i][columna_i + 1] == ' ' ||tab[fila_i][columna_i + 1] == ALBERT_HALL || tab[fila_i][columna_i + 1] == COMMONS_HOUSE){
				k_au = 0;
			}
		}
		else if(n == 2 && n1 == 0){
			if(tab[fila_i+1][columna_i] == INSPECTORES || tab[fila_i+1][columna_i] == POLICIAS){
				if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
					k_au = 1;//jugada valida
					x_au = 1;
					y_au = 0;
				}
				else{
					k_au = 0;
				}
			}else if(tab[fila_i + 1][columna_i] == LIDERESAS || tab[fila_i + 1][columna_i] == SUFRAGISTAS){
				k_au = 2;
				x_au = 1;
				y_au = 0;
			}
			else if(tab[fila_i + 1][columna_i] == THE_ARENA ||tab[fila_i + 1][columna_i] == ' ' ||tab[fila_i + 1][columna_i] == ALBERT_HALL || tab[fila_i + 1][columna_i] == COMMONS_HOUSE){
				k_au = 0;
			}
		}
		else if(n == 0 && n1 == -2){
			if(tab[fila_i][columna_i - 1] == INSPECTORES || tab[fila_i][columna_i - 1] == POLICIAS){
				if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
					k_au = 1;//jugada valida
					x_au = 0;
					*y = -1;
				}
				else{
					k_au = 0;
				}
			}else if(tab[fila_i][columna_i - 1] == LIDERESAS || tab[fila_i][columna_i - 1] == SUFRAGISTAS){
				k_au = 2;
				x_au = 0;
				y_au = -1;
			}
			else if(tab[fila_i][columna_i - 1] == THE_ARENA ||tab[fila_i][columna_i - 1] == ' ' ||tab[fila_i][columna_i - 1] == ALBERT_HALL || tab[fila_i][columna_i - 1] == COMMONS_HOUSE){
				k_au = 0;
			}
		}
		else if(n == -2 && n1 == 0){
			if(tab[fila_i-1][columna_i] == INSPECTORES || tab[fila_i-1][columna_i] == POLICIAS){
				if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
					k_au = 1;//jugada valida
					x_au = -1;
					y_au = 0;
				}
				else{
					k_au = 0;
				}
			}else if(tab[fila_i - 1][columna_i] == LIDERESAS || tab[fila_i - 1][columna_i] == SUFRAGISTAS){
				k_au = 2;
				x_au = -1;
				y_au = 0;
			}
			else if(tab[fila_i - 1][columna_i] == THE_ARENA ||tab[fila_i - 1][columna_i] == ' ' ||tab[fila_i - 1][columna_i] == ALBERT_HALL || tab[fila_i - 1][columna_i] == COMMONS_HOUSE){
				k_au = 0;
			}
		}
	}
	else if(tab[fila_i][columna_i] == SUFRAGISTAS){

		if(n == 2 && n1 == 2){

			if((fila_i + 1 == 5 && columna_i + 1 == 8) || (fila_i + 1 == 4 && columna_i + 1 == 10)){
				k_au = 0;//jugada invalida
			}else{
				if(tab[fila_i + 1][columna_i + 1] == INSPECTORES || tab[fila_i + 1][columna_i + 1] == POLICIAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
						k_au = 1;//jugada valida
						x_au = 1;
						y_au = 1;
					}
					else{
						k_au = 0;//jugada invalida
					}
				}else if(tab[fila_i + 1][columna_i + 1] == LIDERESAS || tab[fila_i + 1][columna_i + 1] == SUFRAGISTAS){
					//printf("llega a las suff\n");
					k_au = 2;
					x_au = 1;
					y_au = 1;

				}else if(tab[fila_i + 1][columna_i + 1] == THE_ARENA ||tab[fila_i + 1][columna_i + 1] == ' ' ||tab[fila_i + 1][columna_i + 1] == ALBERT_HALL || tab[fila_i + 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
		else if(n == -2 && n1 == -2){
			if((fila_i - 1 == 5 && columna_i - 1 == 8)||(fila_i - 1 == 4 && columna_i - 1 == 10)){
				k_au = 0;//jugada invalida
			}else{
				if(tab[fila_i - 1][columna_i - 1] == INSPECTORES || tab[fila_i - 1][columna_i - 1] == POLICIAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
						k_au = 1;//jugada valida
						x_au = -1;
						y_au = -1;
					}
					else{
						k_au = 0;

					}
				}else if(tab[fila_i - 1][columna_i - 1] == LIDERESAS || tab[fila_i - 1][columna_i - 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = -1;
					y_au = -1;
				}else if(tab[fila_i - 1][columna_i - 1] == THE_ARENA ||tab[fila_i - 1][columna_i - 1] == ' ' ||tab[fila_i - 1][columna_i - 1] == ALBERT_HALL || tab[fila_i + 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
		else if(n == 2 && n1 == -2){
			if((fila_i + 1 == 4 && columna_i - 1 == 8)||(fila_i + 1 == 5 && columna_i - 1 == 10)){
				k_au = 0;//jugada invalida
			}else{
				if(tab[fila_i + 1][columna_i - 1] == INSPECTORES || tab[fila_i + 1][columna_i - 1] == POLICIAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
						k_au = 1;//jugada valida
						x_au = 1;
						y_au = -1;
					}
					else{
						k_au = 0;

					}
				}else if(tab[fila_i + 1][columna_i - 1] == LIDERESAS || tab[fila_i + 1][columna_i - 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = 1;
					y_au = -1;
				}else if(tab[fila_i + 1][columna_i - 1] == THE_ARENA ||tab[fila_i + 1][columna_i - 1] == ' ' ||tab[fila_i + 1][columna_i - 1] == ALBERT_HALL || tab[fila_i + 1][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
		else if(n == -2 && n1 == 2){
			if((fila_i - 1 == 4 && columna_i + 1 == 8) || (fila_i - 1 == 5 && columna_i + 1 == 10)){
				k_au = 0;//jugada invalida
			}else{
				if(tab[fila_i - 1][columna_i + 1] == INSPECTORES || tab[fila_i - 1][columna_i + 1] == POLICIAS){
					if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' ||tab[fila_f][columna_f] == COMMONS_HOUSE){
						k_au = 1;//jugada valida
						x_au = -1;
						y_au = 1;
					}else{
						k_au = 0;
					}
				}else if(tab[fila_i - 1][columna_i + 1] == LIDERESAS || tab[fila_i - 1][columna_i + 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = -1;
					y_au = 1;
				}else if(tab[fila_i - 1][columna_i + 1] == THE_ARENA ||tab[fila_i - 1][columna_i + 1] == ' ' ||tab[fila_i - 1][columna_i + 1] == ALBERT_HALL || tab[fila_i - 1][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
		else{//si no es un salto diagonal entonces es uno horizontal o vertical
			if(n == -2 && n1 == 0){
				if(tab[fila_i - 1][columna_i] == LIDERESAS || tab[fila_i - 1][columna_i] == SUFRAGISTAS){
					k_au = 2;
					x_au = -1;
					y_au = 0;
				}else if(tab[fila_i - 1][columna_i] == THE_ARENA ||tab[fila_i - 1][columna_i] == ' ' ||tab[fila_i - 1][columna_i] == ALBERT_HALL || tab[fila_i - 1][columna_i] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
			if(n == 2 && n1 == 0){
				if(tab[fila_i + 1][columna_i] == LIDERESAS || tab[fila_i + 1][columna_i] == SUFRAGISTAS){
					k_au = 2;
					x_au = 1;
					y_au = 0;
				}else if(tab[fila_i + 1][columna_i] == THE_ARENA ||tab[fila_i + 1][columna_i] == ' ' ||tab[fila_i + 1][columna_i] == ALBERT_HALL || tab[fila_i + 1][columna_i] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
			if(n == 0 && n1 == -2){
				if(tab[fila_i][columna_i - 1] == LIDERESAS || tab[fila_i][columna_i - 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = 0;
					y_au = -1;
				}else if(tab[fila_i][columna_i - 1] == THE_ARENA ||tab[fila_i][columna_i - 1] == ' ' ||tab[fila_i][columna_i - 1] == ALBERT_HALL || tab[fila_i][columna_i - 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}if(n == 0 && n1 == 2){
				if(tab[fila_i][columna_i + 1] == LIDERESAS || tab[fila_i][columna_i + 1] == SUFRAGISTAS){
					k_au = 2;
					x_au = 0;
					y_au = 1;
				}
				else if(tab[fila_i][columna_i + 1] == THE_ARENA ||tab[fila_i][columna_i + 1] == ' ' ||tab[fila_i][columna_i + 1] == ALBERT_HALL || tab[fila_i][columna_i + 1] == COMMONS_HOUSE){
					k_au = 0;
				}
			}
		}
	}else{
		k_au = 0;
	}
	*k = k_au;
	*x = x_au;
	*y = y_au;

	//printf("retorna k = %d, x = %d, y = %d", k_au, x_au, y_au);
}


void mov_cp_pol_e_ins (int fila, int colum, char tab[TAM_TAB][TAM_TAB]){
	int fila_i = fila, columna_i = colum, k = 0, fila_f, columna_f, aux1, aux2, x, y, fil, col;
	float dis_i = 0, dis_f = 0 ;
	srand(time(NULL));
	do{
		fila_f = rand()%17;//busca una posicion random
		columna_f = rand()%16;
		aux1 = fabs(fila_f - fila_i);
		aux2 = fabs(columna_f - columna_i);
		//si la diferencia en las filas o las columnas es 2 significa que se esta pensando
		//en comer una pieza

		if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' || tab[fila_f][columna_f] == ALBERT_HALL){
			if((aux1 == 2 && aux2 == 0) || (aux1 == 0 && aux2 == 2) || (aux1 == 2 && aux2 == 2)){
				dis_i = menor_distancia_p(&fila_i, &columna_i);// menor distancia de la casilla origen con relacion a las casillas protegidas por los contrarios
				dis_f = menor_distancia_p(&fila_f, &columna_f);// menor distancia de la casilla final con relacion a las casillas protegidas por los contrarios
				if(dis_f <= dis_i ){//verifica que las fichas se muevan en la direccion hacia las casillas protegidas por los contrarios
					funcion_comer_ins_y_pol(&k, &x, &y, columna_f, fila_f, fila_i, columna_i);
					if (k == 2) {//si retorna 2 significa que hay una aliado y por lo tanto puede saltar
						if (tab[fila_i][columna_i] == INSPECTORES) {
							tab[fila_f][columna_f] = INSPECTORES;
							if (columna_i > 4 && columna_i < 14) {
								tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
							} else if (fila_i > 11 && columna_i == 2) {	//saca a los policias del hospital
								tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
							} else {
								tab[fila_i][columna_i] = ' ';
							}
						}
						if (tab[fila_i][columna_i] == POLICIAS) {
							tab[fila_f][columna_f] = POLICIAS;
							if (columna_i > 4 && columna_i < 14) {
								tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
							} else if (fila_i > 11 && columna_i == 2) {	//saca a los policias del hospital
								tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
							} else {
								tab[fila_i][columna_i] = ' ';
							}
						}
					} else if ((columna_i > 4 && columna_i < 14)&& (columna_f > 3 && columna_f < 15)) {
						//la condicional dice que solo estando en ese rango de posiciones
						//se puede comer una pieza
						if (k == 1) {//el retorno de la funcion es k si k es 1 significa que se puede comer la pieza
							if (tab[fila_i][columna_i] == INSPECTORES) {
								tab[fila_f][columna_f] = INSPECTORES;
								if (columna_i > 4 && columna_i < 14) {
									tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
								} else if (fila_i > 11 && columna_i == 2) {	//saca a los policias del hospital
									tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
								} else {
									tab[fila_i][columna_i] = ' ';
								}
							}
							if (tab[fila_i][columna_i] == POLICIAS) {
								tab[fila_f][columna_f] = POLICIAS;
								if (columna_i > 4 && columna_i < 14) {
									tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
								} else if (fila_i > 11 && columna_i == 2) {	//saca a los policias del hospital
									tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
								} else {
									tab[fila_i][columna_i] = ' ';
								}
							}
							fil = fila_i + x;
							col = columna_i + y;
							piezas_comidas_sl(&fil, &col, tab);
						}
					}
				}
			}else if((aux1 == 1 && aux2 == 1)||(aux1 == 0 && aux2 == 1)||(aux1 == 1 && aux2 == 0)){
				dis_i = menor_distancia_p(&fila_i, &columna_i);// menor distancia de la casilla origen con relacion a las casillas protegidas por los contrarios
				dis_f = menor_distancia_p(&fila_f, &columna_f);// menor distancia de la casilla final con relacion a las casillas protegidas por los contrarios
				if (dis_f <= dis_i){//verifica que las fichas se muevan en la direccion hacia las casillas protegidas por los contrarios
					if (tab[fila_i][columna_i] == INSPECTORES) {
						tab[fila_f][columna_f] = INSPECTORES;
						if (columna_i > 4 && columna_i < 14) {
							tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
						} else if (fila_i > 11 && columna_i == 2) {	//saca a los policias del hospital
							tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
						} else {
							tab[fila_i][columna_i] = ' ';
						}
						k = 2;
					}
					if (tab[fila_i][columna_i] == POLICIAS) {
						tab[fila_f][columna_f] = POLICIAS;
						if (columna_i > 4 && columna_i < 14) {
							tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
						} else if (fila_i > 11 && columna_i == 2) {	//saca a los policias del hospital
							tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
						} else {
							tab[fila_i][columna_i] = ' ';//espacio en la zona neutral
						}
						k = 2;
					}

				}

			}
		}else{
			k = 0;
		}
	}while(k == 0);
	printf("\nLA COMPUTADORA se mueve de la fila = %d y la columna 1 = %d\n", fila, colum);
	printf("\na la fila = %d y columna = %d\n", fila_f, columna_f);

}


void mov_cp_suf_y_lid (int fila, int colum, char tab[TAM_TAB][TAM_TAB]){
	int fila_i = fila, columna_i = colum, k = 0, fila_f, columna_f, aux1, aux2, x, y, fil, col;
	float dis_i = 0, dis_f = 0 ;
	srand(time(NULL));
	do{

		fila_f = rand()%17;//busca una posicion random
		columna_f = rand()%16;
		//printf("\nLlegaaaa!!!\n, %c\n", tab[fila_f][columna_f]);
		aux1 = fabs(fila_f - fila_i);
		aux2 = fabs(columna_f - columna_i);
		//si la diferencia en las filas o las columnas es 2 significa que se esta pensando
		//en comer una pieza
		if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' || tab[fila_f][columna_f] == COMMONS_HOUSE){
			if((aux1 == 2 && aux2 ==0) || (aux1 == 0 && aux2 == 2) || (aux1 == 2 && aux2 == 2)){
				dis_i = menor_distancia_f(&fila_i, &columna_i);// menor distancia de la casilla origen con relacion a las casillas protegidas por los contrarios
				dis_f = menor_distancia_f(&fila_f, &columna_f);// menor distancia de la casilla final con relacion a las casillas protegidas por los contrarios
				if (dis_f <= dis_i){ //verifica que las fichas se muevan en la direccion hacia las casillas protegidas por los contrarios
					//verifica si se movio 2 casillas en las filas, columnas o en ambas
					funcion_comer(&k, &x, &y, columna_f, fila_f, fila_i, columna_i);
					if ((columna_i > 4 && columna_i < 14)&& (columna_f > 3 && columna_f < 15)) {
						//la condicional dice que solo estando en ese rango de posiciones
						//se puede comer una pieza
						if (k == 2) {	//verifica que se salto sobre un aliado
							if (tab[fila_i][columna_i] == LIDERESAS) {
								tab[fila_f][columna_f] = LIDERESAS;
								if (columna_i > 4 && columna_i < 14) {
									tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
								} else if (fila_i > 11 && columna_i == 2) {	//saca a las lideresas de la prision
									tab[fila_i][columna_i] = PRISON_YARD;
								} else {
									tab[fila_i][columna_i] = ' ';
								}
							}
							if (tab[fila_i][columna_i] == SUFRAGISTAS) {
								tab[fila_f][columna_f] = SUFRAGISTAS;
								if (columna_i > 4 && columna_i < 14) {
									tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
								} else if (fila_i > 11 && columna_i == 2) {	//saca a las sufragistas de la prision
									tab[fila_i][columna_i] = PRISON_YARD;
								} else {
									tab[fila_i][columna_i] = ' ';
								}
							}
						} else if (k == 1) {//el retorno de la funcion es k si k es 1 significa que se puede comer la pieza
							if (tab[fila_i][columna_i] == LIDERESAS) {
								tab[fila_f][columna_f] = LIDERESAS;
								if (columna_i > 4 && columna_i < 14) {
									tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
								} else if (fila_i > 11 && columna_i == 2) {	//saca a las lideresas de la prision
									tab[fila_i][columna_i] = PRISON_YARD;
								} else {
									tab[fila_i][columna_i] = ' ';
								}
							}
							if (tab[fila_i][columna_i] == SUFRAGISTAS) {
								tab[fila_f][columna_f] = SUFRAGISTAS;
								if (columna_i > 4 && columna_i < 14) {
									tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
								} else if (fila_i > 11 && columna_i == 2) {	//saca a las sufragistas de la prision
									tab[fila_i][columna_i] = PRISON_YARD;
								} else {
									tab[fila_i][columna_i] = ' ';
								}
							}
							fil = fila_i + x;
							col = columna_i + y;
							piezas_comidas_pi(&fil, &col, tab);
						}
					}

				}


			}else if((aux1 == 1 && aux2 == 1)||(aux1 == 0 && aux2 == 1)||(aux1 == 1 && aux2 == 0)){
				dis_i = menor_distancia_f(&fila_i, &columna_i);// menor distancia de la casilla origen con relacion a las casillas protegidas por los contrarios
				dis_f = menor_distancia_f(&fila_f, &columna_f);// menor distancia de la casiila final  con relacion a las casillas protegidas por los contrarios
				if (dis_f <= dis_i){//verifica que las fichas se muevan en la direccion hacia las casillas protegidas por los contrarios
					if (tab[fila_i][columna_i] == LIDERESAS) {
						tab[fila_f][columna_f] = LIDERESAS;
						if (columna_i > 4 && columna_i < 14) {
							tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
						} else if (fila_i > 11 && columna_i == 2) {	//saca a las lideresas de la prision
							tab[fila_i][columna_i] = PRISON_YARD;
						} else {
							tab[fila_i][columna_i] = ' ';
						}
						k = 2;
					}
					if (tab[fila_i][columna_i] == SUFRAGISTAS) {
						tab[fila_f][columna_f] = SUFRAGISTAS;
						if (columna_i > 4 && columna_i < 14) {
							tab[fila_i][columna_i] = THE_ARENA;	//deja la representacion de la arena vacia
						} else if (fila_i > 11 && columna_i == 2) {	//saca a las sufragistas de la prision
							tab[fila_i][columna_i] = PRISON_YARD;
						} else {
							tab[fila_i][columna_i] = ' ';
						}
						k = 2;
					}

				}


			}
		}else{
			//printf("\nJugada invalida!!! vuelva a elegir.\n");
			k = 0;
		}
	}while(k == 0);
	printf("\nLA COMPUTADORA se mueve de la fila = %d y la columna 1 = %d\n", fila, colum);
	printf("\na la fila = %d y columna = %d\n", fila_f, columna_f);
}

void mov_ins_o_pol(int fila, int colum, char tab[TAM_TAB][TAM_TAB]){
	int fila_i = fila, columna_i = colum, k = 0, fila_f, columna_f, aux1, aux2, x, y, fil, col;
	do{
		printf("Seleccione donde mover:\nPosicion de la fila (1-17): ");
		scanf("%d", &fila_f);
		printf("Posicion de la columna (1-17): ");
		scanf("%d",&columna_f);
		aux1 = fabs(fila_f - fila_i);
		aux2 = fabs(columna_f - columna_i);
		//si la diferencia en las filas o las columnas es 2 significa que se esta pensando
		//en comer una pieza

		if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' || tab[fila_f][columna_f] == ALBERT_HALL){
			if((aux1 == 2 &
					& aux2 == 0) || (aux1 == 0 && aux2 == 2) || (aux1 == 2 && aux2 == 2)){
				funcion_comer_ins_y_pol(&k, &x, &y, columna_f, fila_f, fila_i, columna_i);
				if((columna_i > 4 && columna_i < 14) && (columna_f > 3 && columna_f < 15)){
					//la condicional dice que solo estando en ese rango de posiciones
					//se puede comer una pieza
					if(k == 2){//si retorna 2 significa que hay una aliado y por lo tanto puede saltar
						if(tab[fila_i][columna_i] == INSPECTORES){
							tab[fila_f][columna_f] = INSPECTORES;
							if(columna_i > 4 && columna_i < 14){
								tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
							}else if(fila_i > 11 && columna_i == 2){//saca a los policias del hospital
								tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
							}else{
								tab[fila_i][columna_i] = ' ';
							}
						}
						if(tab[fila_i][columna_i] == POLICIAS){
							tab[fila_f][columna_f] = POLICIAS;
							if(columna_i > 4 && columna_i < 14){
								tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
							}else if(fila_i > 11 && columna_i == 2){//saca a los policias del hospital
								tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
							}else{
								tab[fila_i][columna_i] = ' ';
							}
						}
					}
					else if(k == 1){//el retorno de la funcion es k si k es 1 significa que se puede comer la pieza
						if(tab[fila_i][columna_i] == INSPECTORES){
							tab[fila_f][columna_f] = INSPECTORES;
							if(columna_i > 4 && columna_i < 14){
								tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
							}else if(fila_i > 11 && columna_i == 2){//saca a los policias del hospital
								tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
							}else{
								tab[fila_i][columna_i] = ' ';
							}
						}
						if(tab[fila_i][columna_i] == POLICIAS){
							tab[fila_f][columna_f] = POLICIAS;
							if(columna_i > 4 && columna_i < 14){
								tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
							}else if(fila_i > 11 && columna_i == 2){//saca a los policias del hospital
								tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
							}else{
								tab[fila_i][columna_i] = ' ';
							}
						}
						fil = fila_i + x;
						col = columna_i + y;
						piezas_comidas_sl(&fil, &col, tab);
					}
				}else if(k == 0){
					printf("Movimiento invalido.\nVuelva a seleccionar.\n");
				}
			}else if((aux1 == 1 && aux2 == 1)||(aux1 == 0 && aux2 == 1)||(aux1 == 1 && aux2 == 0)){
				if(tab[fila_i][columna_i] == INSPECTORES){
					tab[fila_f][columna_f] = INSPECTORES;
					if(columna_i > 4 && columna_i < 14){
						tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
					}else if(fila_i > 11 && columna_i == 2){//saca a los policias del hospital
						tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
					}else{
						tab[fila_i][columna_i] = ' ';
					}
					k = 2;
				}
				if(tab[fila_i][columna_i] == POLICIAS){
					tab[fila_f][columna_f] = POLICIAS;
					if(columna_i > 4 && columna_i < 14){
						tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
					}else if(fila_i > 11 && columna_i == 2){//saca a los policias del hospital
						tab[fila_i][columna_i] = HOSPITAL_GROUNDS;
					}else{
						tab[fila_i][columna_i] = ' ';//espacio en la zona neutral
					}
					k = 2;
				}
			}
		}else{
			printf("Movimiento invalido.\nVuelva a seleccionar.\n");
			k = 0;
		}
	}while(k == 0);
}

void  mov_lid_o_suf (int fila, int colum, char tab[TAM_TAB][TAM_TAB]){
	int fila_i = fila, columna_i = colum, k = 0, fila_f, columna_f, aux1, aux2, x, y, fil, col;
	do{
		printf("Seleccione donde mover:\nPosicion de la fila (1-17): ");
		scanf("%d", &fila_f);
		printf("Posicion de la columna (1-17): ");
		scanf("%d",&columna_f);
		//printf("\nLlegaaaa!!!\n, %c\n", tab[fila_f][columna_f]);
		aux1 = fabs(fila_f - fila_i);
		aux2 = fabs(columna_f - columna_i);
		//si la diferencia en las filas o las columnas es 2 significa que se esta pensando
		//en comer una pieza
		if(tab[fila_f][columna_f] == THE_ARENA || tab[fila_f][columna_f] == ' ' || tab[fila_f][columna_f] == COMMONS_HOUSE){
			if((aux1 == 2 && aux2 ==0) || (aux1 == 0 && aux2 == 2) || (aux1 == 2 && aux2 == 2)){
				//verifica si se movio 2 casillas en las filas, columnas o en ambas
				funcion_comer(&k, &x, &y, columna_f, fila_f, fila_i, columna_i);
				if ((columna_i > 4 && columna_i < 14) && (columna_f > 3 && columna_f < 15)){
					//la condicional dice que solo estando en ese rango de posiciones
					//se puede comer una pieza
					if(k == 2){//verifica que se salto sobre un aliado
						if(tab[fila_i][columna_i] == LIDERESAS){
							tab[fila_f][columna_f] = LIDERESAS;
							if(columna_i > 4 && columna_i < 14){
								tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
							}else if(fila_i > 11 && columna_i == 2){//saca a las lideresas de la prision
								tab[fila_i][columna_i] = PRISON_YARD;
							}else{
								tab[fila_i][columna_i] = ' ';
							}
						}
						if(tab[fila_i][columna_i] == SUFRAGISTAS){
							tab[fila_f][columna_f] = SUFRAGISTAS;
							if(columna_i > 4 && columna_i < 14){
								tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
							}else if(fila_i > 11 && columna_i == 2){//saca a las sufragistas de la prision
								tab[fila_i][columna_i] = PRISON_YARD;
							}else{
								tab[fila_i][columna_i] = ' ';
							}
						}
					}
					else if(k == 1){//el retorno de la funcion es k si k es 1 significa que se puede comer la pieza
						if(tab[fila_i][columna_i] == LIDERESAS){
							tab[fila_f][columna_f] = LIDERESAS;
							if(columna_i > 4 && columna_i < 14){
								tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
							}else if(fila_i > 11 && columna_i == 2){//saca a las lideresas de la prision
								tab[fila_i][columna_i] = PRISON_YARD;
							}else{
								tab[fila_i][columna_i] = ' ';
							}
						}
						if(tab[fila_i][columna_i] == SUFRAGISTAS){
							tab[fila_f][columna_f] = SUFRAGISTAS;
							if(columna_i > 4 && columna_i < 14){
								tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
							}else if(fila_i > 11 && columna_i == 2){//saca a las sufragistas de la prision
								tab[fila_i][columna_i] = PRISON_YARD;
							}else{
								tab[fila_i][columna_i] = ' ';
							}
						}
						fil = fila_i + x;
						col = columna_i + y;
						piezas_comidas_pi(&fil, &col, tab);
					} else if(k == 0){
						printf("Movimiento invalido!!! Vuelva a seleccionar.\n");

					}

				}

			}else if((aux1 == 1 && aux2 == 1)||(aux1 == 0 && aux2 == 1)||(aux1 == 1 && aux2 == 0)){
				if(tab[fila_i][columna_i] == LIDERESAS){
					tab[fila_f][columna_f] = LIDERESAS;
					if(columna_i > 4 && columna_i < 14){
						tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
					}else if(fila_i > 11 && columna_i == 2){//saca a las lideresas de la prision
						tab[fila_i][columna_i] = PRISON_YARD;
					}else{
						tab[fila_i][columna_i] = ' ';
					}
					k = 2;
				}
				if(tab[fila_i][columna_i] == SUFRAGISTAS){
					tab[fila_f][columna_f] = SUFRAGISTAS;
					if(columna_i > 4 && columna_i < 14){
						tab[fila_i][columna_i] = THE_ARENA;//deja la representacion de la arena vacia
					}else if(fila_i > 11 && columna_i == 2){//saca a las sufragistas de la prision
						tab[fila_i][columna_i] = PRISON_YARD;
					}else{
						tab[fila_i][columna_i] = ' ';
					}
					k = 2;
				}

			}
		}else{
			printf("Movimiento invalida!!! Vuelva a seleccionar.\n");
			k = 0;
		}
	}while(k == 0);
}

void liberacion(char tab[TAM_TAB][TAM_TAB]){
	int i, j, contador = 0, contador1 = 0, p = 12, s = 1;
	for(i = 0; i < TAM_TAB; i++){
		for(j = 0; j < TAM_TAB; j++){
			if(j == 1){
				if(tab[i][j] == POLICIAS && contador < 6){//busca policias en la zona del hospital
					tab[i][j] = HOSPITAL;
					tab[p++][2] = POLICIAS;//los envia a los jardines
					contador++;
				}
				if(tab[i][j] == INSPECTORES && contador < 6){
					tab[i][j] = HOSPITAL;
					tab[p++][2] = INSPECTORES;
					contador++;
				}
			}
			if((j == 2) && (0 < i && i < 5)){
				if(tab[i][j] == POLICIAS && contador < 6){
					tab[i][j] = HOSPITAL;
					tab[p++][2] = POLICIAS;
					contador++;
				}
				if(tab[i][j] == INSPECTORES && contador < 6){
					tab[i][j] = HOSPITAL;
					tab[p++][2] = INSPECTORES;
					contador++;
				}
			}
			if(j == 17){
				if(tab[i][j] == SUFRAGISTAS && contador1 < 6){//busca sufragistas en la prision
					tab[i][j] = PRISON;
					tab[s++][2] = SUFRAGISTAS;//envia la ficha a la posicion donde hay Y
					contador1++;
				}
				if(tab[i][j] == LIDERESAS && contador1 < 6){
					tab[i][j] = PRISON;
					tab[s++][2] = LIDERESAS;
					contador1++;
				}
			}if(j == 16 && (i > 13)){
				if(tab[i][j] == SUFRAGISTAS && contador1 < 6){//busca sufragistas en la prision
					tab[i][j] = PRISON;
					tab[s++][2] = SUFRAGISTAS;
					contador1++;
				}
				if(tab[i][j] == LIDERESAS && contador1 < 6){
					tab[i][j] = PRISON;
					tab[s++][2] = LIDERESAS;
					contador1++;
				}
			}
		}
	}

}

void cond_libertad(char tab[TAM_TAB][TAM_TAB]){
	int i, j, contador = 0, contador1 = 0;
	for(i = 0; i < TAM_TAB; i++){
		for(j = 0; j < TAM_TAB; j++){
			if(j == 1){
				if(tab[i][j] == POLICIAS || tab[i][j] == INSPECTORES){//cuenta cuantos policias hay en el hospital
					contador++;
				}
			}
			if((j == 2) && (0 < i || i < 5)){
				if(tab[i][j] == POLICIAS || tab[i][j] == INSPECTORES){
					contador++;
				}
			}
			if(j == 17){
				if(tab[i][j] == SUFRAGISTAS || tab[i][j] == LIDERESAS){//cuenta cuantas sufragistas hay en la prision
					contador1++;
				}
			}if(j == 16 && (i > 13 || i < 18)){
				if(tab[i][j] == SUFRAGISTAS || tab[i][j] == LIDERESAS){
					contador1++;
				}
			}
		}
	}
	int x;
	if(contador >= 12 && contador1 >= 12){//con la condicion cumplida pregunta al usuario si quiere negociar la liberacion de piezas
		printf("Negociar liberacion de piezas.\n1 - Si\n2 - No (cualquier tecla es un no)\n");
		scanf("%d", &x);
		switch(x){
		case 1:
			printf("Negociando liberacion de piezas, podra sacarlas en el sgte turno.\n");
			liberacion(tab);
			break;
		default:
			printf("Ha decidido no liberar a nadie.\n");
			break;
		}
	}
}

int cond_de_Gan(int * ganador){//la condicion de ganador es leer la matriz tablero y contar las posiciones
	int i, j, con = 0, cont = 0;
	for(i = 0; i < TAM_TAB; i++){
		for(j = 0; j < TAM_TAB; j++){
			if(tab[i][j] == ALBERT_HALL){//donde se encuentre el Albert Hall
				con++;//Sumar si no esta ocupado
			}if(tab[i][j] == COMMONS_HOUSE){//y donde se encuentre la Commons House
				cont++;
			}
		}
	}
	/*
	 * si son mayores a 0 no hace nada,
	 * pero si el auxiliar contador que cuenta cuantas posiciones del Albert Hall quedan es igual a 0 entonces ganan los policias
	 * si el cont, auxiliar contador que cuenta cuantas posiciones quedan en la Common House, si es igual a 0 ganan las sufragistas
	 */
	if(con == 0){
		printf("\n		*-*-*-**-*-*GANAN LOS POLICIAS!!!*-*-*-**-*-*");
		return *ganador = 2;
	}
	if(cont == 0){
		printf("\n		*-*-*-**-*-*GANAN LAS SUFRAGISTAS!!!*-*-*-**-*-*");
		return *ganador = 3;
	}else{//todavia no hay ganador
		return *ganador = 1;
	}
}

void inicializar_tablero(char tab[TAM_TAB][TAM_TAB]){
	int i, j;
	for(i = 0; i < TAM_TAB; i++){

		for(j = 0; j < TAM_TAB; j++){
			if(j==0 && i!=0){
				tab[i][j]='*';
			}
			else{
				if(i==0 && j!=0){
					tab[i][j] = '*';

				}
				else{
					if (i == 4 && (j == 7 || j == 11)) {
						tab[i][j]=SUFRAGISTAS;
					}
					else{
						if(i==5 && (j==5 || j==13)){
							tab[i][j]=LIDERESAS;

						}
						else{
							if(i==5 &&(j==6 || j==7 || j==11 || j==12)){
								tab[i][j]=SUFRAGISTAS;
							}
							else{
								if(i==6 &&(j==3 || j==9 || j==15)){
									tab[i][j]=LIDERESAS;
								}
								else{
									if(i==6 && ((j>=4 && j<=8)||(j>=10 && j<=14))){
										tab[i][j]=SUFRAGISTAS;

									}
									else{
										if((i==4 || i==5)&&(j>=8 && j<=10)){
											tab[i][j]=ALBERT_HALL;

										}else{
											if(i==12 &&(j==3 || j== 9 || j==15)){
												tab[i][j]=INSPECTORES;

											}
											else{
												if(i==12 &&((j>=4 && j<=8) || ( j>=10 && j<=14))){
													tab[i][j]=POLICIAS;

												}
												else{
													if(i==13 &&(j==5 || j==13)){
														tab[i][j]=INSPECTORES;

													}
													else{
														if(i==13 &&(j==6 || j==7 || j==11 || j==12)){
															tab[i][j]=POLICIAS;

														}
														else{
															if(i==14 &&(j==7 || j==11)){
																tab[i][j]=POLICIAS;

															}
															else{
																if((i==13 || i==14) && (j>=8 && j<=10)){
																	tab[i][j]=COMMONS_HOUSE;

																}
																else{
																	if(((i>=1 && i<=17) && j==1)||((i>=1 && i<=4) && j==2)){
																		tab[i][j]=HOSPITAL ;

																	}
																	else{
																		if((i>=12 && i<=17) && j==2){
																			tab[i][j]= HOSPITAL_GROUNDS;
																		}
																		else{
																			if(((i>=1 && i<=17) && j==17)||((i>=14 && i<=17) && j==16)){
																				tab[i][j]=PRISON;

																			}
																			else{
																				if((i>=1 && i<=6) && j==16){
																					tab[i][j]=PRISON_YARD;

																				}
																				else{
																					if((i>=1 && i<=17)&&(j>=5 && j<=13) && tab[i][j]!=SUFRAGISTAS && tab[i][j]!=ALBERT_HALL && tab[i][j]!=LIDERESAS && tab[i][j]!=POLICIAS && tab[i][j]!=INSPECTORES && tab[i][j]!= COMMONS_HOUSE){
																						tab[i][j]=THE_ARENA;

																					}
																					else{
																						tab[i][j]=' ';
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void tablero(char tab[TAM_TAB][TAM_TAB]){
	int i, j;

	printf("\n+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+\n");
	for(i = 0; i < TAM_TAB; i++){
		for(j = 0; j < TAM_TAB; j++){
			if(i == 0 && j > -1){
				if(j == 0){
					printf("| %2d |", j);
				}else{
					printf(" %2d |", j);
				}
			}
			else if(j == 0 && i > 0){
				printf("| %2d |", i);
			}else{
				printf(" %2c |", tab[i][j]);
			}
		}
		printf("\n+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+\n");
	}
}
float menor_distancia_p(int *inix, int *iniy){
	float aux = 100;
	int i,j;
	for (i = 4; i <= 5; i++) {
		for (j = 8; j <= 10; j++) {

			float D = sqrt(pow(i - *inix, 2) + pow(j - *iniy, 2)); //modulo de un vector
			if (D < aux) {
				aux = D;
			}
		}
	}

	return aux;

}
float menor_distancia_f(int *inix, int *iniy){
	float aux = 100;
	int i,j;
	for (i = 13; i <= 14; i++) {
		for (j = 8; j <= 10; j++) {

			float D = sqrt(pow(i - *inix, 2) + pow(j - *iniy, 2));//modulo de un vector
			if (D < aux) {
				aux = D;
			}
		}
	}

	return aux;

}

int main(void) {
	inicializar_tablero(tab);
	tablero(tab);
	menu(tab);


	return EXIT_SUCCESS;
}

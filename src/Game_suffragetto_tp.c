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
						srand(time(NULL));
						alea = rand()%100;
						if(alea % 2 == 0){
							resp1 = 1;
						}else{
							resp1 = 2;
						}
					}
					printf("			Seleccion de fichas\n		1 - Las Sufragistas\n		2 - Los Policias\n		3 - Aleatorio\n");
					scanf("%d", &resp2);
					if(resp2 == 3){
						srand(time(NULL));
						alea = rand()%100;
						if(alea % 2 == 0){
							resp2 = 1;
						}else{
							resp2 = 2;
						}
						continue;
					}
					Modo = resp1;
					empieza = resp2;
					incio_Juego(tab);
//					else if((resp1 == 1 || resp1 == 2) && (resp2 == 1 || resp2 == 2)){
//
//					}
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
	int val = 0, ganador = 1;
	if(Modo == 1){//empiezan las sufragistas
		if(empieza == 1){//el jugador es sufragista, empieza
			do{
				do{//verifica si la posicion es valida
					printf("Seleccione la pieza a mover:\nPosicion de la fila (i): ");
					scanf("%d", &fila);
					printf("Posicion de la columna (j): ");
					scanf("%d",&colum);
					if(tab[fila][colum] == SUFRAGISTAS || tab[fila][colum] == LIDERESAS){
						val = 1;
					}else{
						printf("Seleccion invalida, vuelva a seleccionar\n");
						val = 0;
					}
				}while(val == 0);
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano
				mov_cp(tab);//juega la computadora
				cond_de_Gan(&ganador);
				cond_libertad(tab);//condicion de liberacion de fichas
			}while(ganador == 1);
		}else{//la computadora empieza, su pieza son las suffragistas
			do{
				mov_cp(tab);//juega la computadora
				cond_de_Gan(&ganador);
				do{
					printf("Seleccione la pieza a mover:\nPosicion de la fila (i): ");
					scanf("%d", &fila);
					printf("Posicion de la columna (j): ");
					scanf("%d",&colum);
					if(tab[fila][colum] == POLICIAS || tab[fila][colum] == INSPECTORES){
						val = 1;
					}else{
						printf("Seleccion invalida, vuelva a seleccionar\n");
						val = 0;
					}
				}while(val == 0);
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano
				cond_libertad(tab);//condicion de liberacion de fichas
			}while(ganador == 1);
		}
	}else{//empiezan los policias
		if(empieza == 1){//el jugador es sufragista
			do{
				do{
					printf("Seleccione la pieza a mover:\nPosicion de la fila (i): ");
					scanf("%d", &fila);
					printf("Posicion de la columna (j): ");
					scanf("%d",&colum);
					if(tab[fila][colum] == POLICIAS || tab[fila][colum] == INSPECTORES){
						val = 1;
					}else{
						printf("Seleccion invalida, vuelva a seleccionar\n");
						val = 0;
					}
				}while(val == 0);
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano
				mov_cp(tab);//juega la computadora
				cond_de_Gan(&ganador);
				cond_libertad(tab);//condicion de liberacion de fichas
			}while(ganador == 1);
		}else{//la computadora empieza, su pieza son los policias
			do{
				mov_cp(tab);//juega la computadora
				cond_de_Gan(&ganador);
				do{
					printf("Seleccione la pieza a mover:\nPosicion de la fila (i): ");
					scanf("%d", &fila);
					printf("Posicion de la columna (j): ");
					scanf("%d",&colum);
					if(tab[fila][colum] == SUFRAGISTAS || tab[fila][colum] == LIDERESAS){
						val = 1;
					}else{
						printf("Seleccion invalida, vuelva a seleccionar\n");
						val = 0;
					}
				}while(val == 0);
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano
				cond_libertad(tab);//condicion de liberacion de fichas, esta condicion se determinara en el momento en que en el hospital y en la prision haya 12 piezas en cada uno
			}while(ganador == 1);
		}
	}
}

void mov_cp (char tab[TAM_TAB][TAM_TAB]){
	if(empieza == 1){//cuando empieza es igual a 1 significa que el usuario tiene las piezas de las sufragistas por lo tanto la computadora juega con la policia
		if(tab[fila][colum] == INSPECTORES){
			mov_lid_o_ins (&fila, &colum, tab);
		}if(tab[fila][colum] == POLICIAS){
			mov_suf_o_pol (&fila, &colum, tab);
		}
	}
	if(empieza == 2){//si la eleccion del usuario fue jugar con los policias la computadora jugara con las sufragistas
		if(tab[fila][colum] == LIDERESAS){
			mov_lid_o_ins(&fila, &colum, tab);
		}if(tab[fila][colum] == SUFRAGISTAS){
			mov_suf_o_pol (&fila, &colum, tab);
		}
	}
}

void mov_us (char tab[TAM_TAB][TAM_TAB]){
	if(empieza == 1){//eleccion del usuario jugar con las sufragistas
		if(tab[fila][colum] == LIDERESAS){
			mov_lid_o_ins (&fila, &colum, tab);
		}if(tab[fila][colum] == SUFRAGISTAS){
			mov_suf_o_pol (&fila, &colum, tab);
		}
	}
	if(empieza == 2){//eleccion del usuario jugar con los policias
		if(tab[fila][colum] == INSPECTORES){
			mov_lid_o_ins(&fila, &colum, tab);
		}if(tab[fila][colum] == POLICIAS){
			mov_suf_o_pol (&fila, &colum, tab);
		}
	}
}

void mov_suf_o_pol (int * x, int * y, char tab[TAM_TAB][TAM_TAB]){
	int a,b,aux1;

	if(Modo==1){// es el turno de los sufragistas
		do{
			aux1=0;
			printf("Ingrese la coordenas de la fila, a donde desea mover la fichas:\n");
			scanf("%d",&a);
			printf("Ingrese la coordenas de la columna, a donde desea mover la fichas:\n");
			scanf("%d",&b);
			if(tab[a][b]== ALBERT_HALL || tab[a][b]== HOSPITAL || tab[a][b]== PRISON ) {
				printf("MOVIMIENTO INVALIDO, vuelva a ingresar");
				aux1=1;
			}
			else{
				//(pow((*x-a),2) == 0 || pow((*x-a),2) == 1) && (pow((*y-b),2) == 0 || pow((*y-b),2) == 1)
				if((fabs(*x-a) == 0 || fabs(*x-a) == 1) && (fabs(*y-b) == 0 || fabs(*y-b) == 1)){
					if(tab[a][b]==SUFRAGISTAS || tab[a][b]==LIDERESAS || tab[a][b]==POLICIAS|| tab[a][b]==INSPECTORES ){
						printf("MOVIMIENTO INVALIDO, vuelva a ingresar");
						aux1 = 1;
					}
					else{
						if((x>=1 && x<=17)&&(y>=5 && y<=13)){
							if(((x==4 || x==5)&&(y>=8 && y<=10))||((x==14 || x==13)&&(y>=8 && y<=10))){

							}
							else{
								tab[a][b]=SUFRAGISTAS;
								tab[*x][*y]= THE_ARENA;
							}
						}
					}


				}

			}

		}while (aux1 != 0  );


	}




}

void mov_lid_o_ins (int * x, int * y, char tab[TAM_TAB][TAM_TAB]){

}

void liberacion(char tab[TAM_TAB][TAM_TAB]){

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
			printf("Negociando Liberacion de piezas, podra sacarlas en el sgte turno.\n");
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
	 * pero si con que es el auxiliar contador que cuenta cuantas posiciones del Albert Hall quedan es igual a 0 entonces ganan los policias
	 * si el cont, auxiliar contador que cuenta cuantas posiciones quedan en la Common House, si es igual a 0 ganan las sufragistas
	 */
	if(con == 0){
		printf("\n		*-*-*-**-*-*GANAN LOS POLICIAS!!!*-*-*-**-*-*");
		return 2;
	}
	if(cont == 0){
		printf("\n		*-*-*-**-*-*GANAN LAS SUFRAGISTAS!!!*-*-*-**-*-*");
		return 3;
	}else{//todavia no hay ganador
		return 1;
	}
}

void inicializar_tablero(char tab[TAM_TAB][TAM_TAB]){
	int i, j, number = 0,number1 = 0;

	for(i = 0; i < TAM_TAB; i++){

		for(j = 0; j < TAM_TAB; j++){
			if(j==0 && i!=0){

				char post1 = number + 'a';//a
				number = number + 1;

				tab[i][j]=post1;

			}
			else{
				if(i==0 && j!=0){
					char post2 = number1 + 'A';//A
					number1 = number1 + 1;

					tab[i][j] = post2;

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
	printf("\n --+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	for(i = 0; i < TAM_TAB; i++){
		for(j = 0; j < TAM_TAB; j++){

			printf(" %c |", tab[i][j]);
		}
		printf("\n --+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	}
}

int main(void) {
	inicializar_tablero(tab);
	tablero(tab);
	menu(tab);


	return EXIT_SUCCESS;
}

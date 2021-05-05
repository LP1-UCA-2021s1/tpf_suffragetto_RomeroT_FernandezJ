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
#include "Game_suffragetto_tp.h"

void menu(char tab[TAM_TAB][TAM_TAB]){
	int opcion=0, resp1, resp2, alea;
		do
		{
			//system("cls");
			printf("Bienvenido al juego  SUFFRAGETTO \n");
			printf("		MENU PRINCIPAL\n");
			printf("1) JUGAR \n");
			printf("2) REGLAS DE JUEGO \n");
			printf("3) INSTRUCCIONES DE USO \n");
			printf("4) CREDITOS \n");
			printf("5) SALIR \n\n");
			printf("Ingrese el numero de la opcion que desea ejecutar:");
			scanf("%d",&opcion);
			fflush(stdin);//limpia el buffer de entrada cuando se ingresa un valor no válido
			switch(opcion)
			{
				case 1:
					//system("cls");
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
					//system("cls");
					printf("          ----------REGLAS DE JUEGO----------\n\n");
					printf(" -Piezas: 21 fichas por jugador; 5 fichas violetas y 16 fichas verdes para un jugador (suffragetto), 5 fichas blancas y 16 fichas azules para el otro jugador (policía). Las fichas violetas representan a lo..\n\n -El objetivo de ambos jugadores es ocupar el área protegida por sus enemigos. Así, los policías desean ocupar el “Albert Hall” mientras que los suffragetto desean ocupar la región “House of Commons”. De esta forma el juego finaliza cuando una de estas dos regiones es ocupada completamente, y gana el jugador que ubicó 6.\n\n -.\n\n -.\n\n -.\n\n ");
					//system("PAUSE");
					break;
				case 3:
					//system("cls");
					printf("          ----------INSTRUCCIONES PARA USO DEL PROGRAMA---------\n\n");
					printf(" -El programa decidira al azar a quien corresponde el primer turno.\n\n -Para mover las piezas se deben introducir las coordenadas de la pieza a mover y las de la posicion a mover.\n\n -Las coordendas del tablero van del 1 al 17 para las filas y columnas.\n\n -El programa se encargara de advertirle de errores o movimientos invalidos.\n\n -Tambien se encargara de ............. si se da el caso.\n\n -Luego de cada jugada usted vera cuantas........... quedan fuera del tablero y cuantas fueron trapadas por ...........\n\n ");
					//system("PAUSE");
					break;
				case 4:
					//system("cls");
					printf("           -----------CREDITOS----------\n\n");
					printf("          ----------PROGRAMADORES----------\n\n");
					printf("                    Julio Fernandez\n\n                          e\n\n                      Tania Romero\n\n");
					//system("PAUSE");
					break;
				case 5:
					break;
				default:
					//system("cls");
					printf("Ha ingresado un valor invalido\n");
					printf("Favor ingrese una opcion del MENU PRINCIPAL\n");
					//system("PAUSE");
					break;
			}
		}while(opcion!=5);


}

void incio_Juego(char tab[TAM_TAB][TAM_TAB]){
	int ganador = 1;
	if(Modo == 1){//empiezan las sufragistas
		if(empieza == 1){//el jugador es sufragista, empieza
			do{
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
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano
				cond_libertad(tab);//condicion de liberacion de fichas
			}while(ganador == 1);
		}
	}else{//empiezan los policias
		if(empieza == 1){//el jugador es sufragista
			do{
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
				mov_us(tab);//juega el jugador sus parametros son la fila y la columna introducida
				cond_de_Gan(&ganador);//funcion que verifica si el jugador que acaba de jugar gano
				cond_libertad(tab);//condicion de liberacion de fichas, esta condicion se determinara en el momento en que en el hospital y en la prision haya 12 piezas en cada uno
			}while(ganador == 1);
		}
	}
}

void mov_cp (char tab[TAM_TAB][TAM_TAB]){
	int fila, colum, k = 0;
	empieza = 1;
	if(empieza == 1){//cuando empieza es igual a 1 significa que el usuario tiene las piezas de las sufragistas por lo tanto la computadora juega con la policia
		do{
			srand(time(NULL));//busca una posicion random
			fila = rand()%17;
			colum = rand()%17;
			if(colum > 1){
				if(colum == 2){
					if(fila > 4 || fila < 12){
						if(tab[fila][colum] == POLICIAS || tab[fila][colum] == INSPECTORES){
							k = 1;
							printf("\nfila = %d, colum = %d\n", fila, colum);
						}
					}
				}
				if(colum == 16){
					if(fila > 7 && fila < 14){
						if(tab[fila][colum] == POLICIAS || tab[fila][colum] == INSPECTORES){
							k = 1;
							printf("\nfila = %d, colum = %d\n", fila, colum);
						}
					}
				}
			}
		}while(k == 0);

		if(tab[fila][colum] == INSPECTORES){
			mov_lid_o_ins (&fila, &colum, tab);
		}if(tab[fila][colum] == POLICIAS){
			mov_suf_o_pol (&fila, &colum, tab);
		}
		k = 0;
	}
	if(empieza == 2){//si la eleccion del usuario fue jugar con los policias la computadora jugara con las sufragistas
		do{
			srand(time(NULL));
			fila = rand()%17;
			colum = rand()%17;
			if(colum > 1){
				if(colum == 2){
					if(fila > 4 || fila < 12){
						if(tab[fila][colum] == LIDERESAS || tab[fila][colum] == SUFRAGISTAS){
							k = 1;
							printf("\nfila = %d, colum = %d\n", fila, colum);
						}
					}
				}
				if(colum == 16){
					if(fila > 7 && fila < 14){
						if(tab[fila][colum] == LIDERESAS || tab[fila][colum] == SUFRAGISTAS){
							k = 1;
							printf("\nfila = %d, colum = %d\n", fila, colum);
						}
					}
				}
			}
		}while(k == 0);

		if(tab[fila][colum] == LIDERESAS){
			mov_lid_o_ins(&fila, &colum, tab);
		}if(tab[fila][colum] == SUFRAGISTAS){
			mov_suf_o_pol (&fila, &colum, tab);
		}
		k = 0;
	}
}

void mov_us (char tab[TAM_TAB][TAM_TAB]){
	int val;
	if(empieza == 1){//eleccion del usuario jugar con las sufragistas
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
		if(tab[fila][colum] == LIDERESAS){
			mov_lid_o_ins (&fila, &colum, tab);
		}if(tab[fila][colum] == SUFRAGISTAS){
			mov_suf_o_pol (&fila, &colum, tab);
		}
	}
	if(empieza == 2){//eleccion del usuario jugar con los policias
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
		if(tab[fila][colum] == INSPECTORES){
			mov_lid_o_ins(&fila, &colum, tab);
		}if(tab[fila][colum] == POLICIAS){
			mov_suf_o_pol (&fila, &colum, tab);
		}
	}
}

void mov_suf_o_pol (int * x, int * y, char tab[TAM_TAB][TAM_TAB]){
	printf("\n HASTA AQUI LLEGUE!! mov_suf_o_pol\n");

}

void mov_lid_o_ins (int * x, int * y, char tab[TAM_TAB][TAM_TAB]){
	printf("\n HASTA AQUI LLEGUE!! mov_lid_o_ins\n");
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
			if((j == 2) && (0 < i || i < 5)){
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
			}if(j == 16 && (i > 13 || i < 18)){
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

				char post1 = number + 'a';
				number = number + 1;
				tab[i][j]=post1;

			}
			else{
				if(i==0 && j!=0){
					char post2 = number1 + 'A';
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
	mov_cp(tab);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

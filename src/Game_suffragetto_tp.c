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
#include "Game_suffragetto_tp.h"

void menu(char tab[TAM_TAB][TAM_TAB]){
	int opcion=0;
	printf("¡Bienvenido al juego  SUFFRAGETTO! \n");
		do
		{

			printf("MENU PRINCIPAL\n");
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

void inicializar_tablero(char tab[TAM_TAB][TAM_TAB]){

}

void incio_Juego(char tab[TAM_TAB][TAM_TAB]){

}

void mov_cp (char tab[TAM_TAB][TAM_TAB]){

}

void mov_us (char tab[TAM_TAB][TAM_TAB]){

}

void cond_libertad(char tab[TAM_TAB][TAM_TAB]){

}

void cond_de_Gan(char tab[TAM_TAB][TAM_TAB]){

}

void tablero(char tab[TAM_TAB][TAM_TAB]){
	int i, j, x,number=0,number1=0;

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


			printf(" %c |", tab[i][j]);
		}

		printf("\n --+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	}
}
int main(void) {
	tablero(tab);
	menu(tab);

	return EXIT_SUCCESS;
}

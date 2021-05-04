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
		do
		{
			//system("cls");
			printf("Bienvenido al juego  SUFFRAGETTO \n");
			printf("MENU PRINCIPAL\n");
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

void reglas(char tab[TAM_TAB][TAM_TAB]){


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
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

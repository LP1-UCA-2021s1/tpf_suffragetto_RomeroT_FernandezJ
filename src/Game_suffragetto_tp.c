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

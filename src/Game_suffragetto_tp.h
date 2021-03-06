/*
 * Game_suffragetto_tp.h
 *
 *  Created on: 27 mar. 2021
 *      Author: lp1-2021
 */

#ifndef GAME_SUFFRAGETTO_TP_H_
#define GAME_SUFFRAGETTO_TP_H_


//tablero
#define TAM_TAB	 18
char tab[TAM_TAB][TAM_TAB];


//fichas
#define SUFRAGISTAS	 'S'
#define LIDERESAS 	'L'
#define POLICIAS 	'P'
#define INSPECTORES 	'I'

//casillas libres
#define THE_ARENA 	'-'
#define PRISON 	'R'
#define HOSPITAL 	'H'
#define COMMONS_HOUSE 	'C'
#define ALBERT_HALL 	'A'
#define PRISON_YARD 	'Y'
#define HOSPITAL_GROUNDS 	'G'

//seleccion de menu
int Modo;//seleccion de modo de juego
int empieza;//quien empieza
char ficha_J;//con cual ficha juega el usuario
int fila, colum;
//FUNCIONES
/*
 * El MENU muestra las opciones que tiene el jugador
 * 1- Jugar
 * ----> Modo de Juego:
 * ---->1- Jugador vs Jugador
 * ---->2- Jugador vs Computadora
 * ------->El jugador elige quien empieza
 * ------->1- Jugador 1.... 2- Jugador 2.... 3- Random
 * 			en caso de jugador vs computadora
 * ------->1- Jugador 1.... 2- Computadora.... 3- Random
 * 			seleccion de fichas
 * 			-->1- Sufragistas.... 2- Policias
 * 2- Reglas
 * 3- Salir
 */
void menu(char tab[TAM_TAB][TAM_TAB]);
/*
 * IMPRIME LAS REGLAS
 */
void reglas(void);
/*
 * Esta funcion INICIALIZA EL TABLERO
 * llena las casillas libres dependiendo de la ubicacion
 * coloca las fichas en su posicion inicial
 * retorna un tablero, con las pocisiones de las piezas y las regiones.
 */
void inicializar_tablero(char tab[TAM_TAB][TAM_TAB]);
/*
 * INICIO DEL JUEGO
 * recibe la seleccion del usuario para empezar el juego
 */
void incio_Juego(char tab[TAM_TAB][TAM_TAB]);
/*
 * MOVIMIENTO DE LA COMPUTADORA
 * La logica de la computadora sera de movimientos randoms
 */
void mov_cp (char tab[TAM_TAB][TAM_TAB]);
/*
 * funcion que verifica los movimientos de la computadora cuando le toca jugar con las piezas de los policias
 * tiene como parmetros la fila y columna inicial
 * retorna una nueva posicion en el tablero
 */
void mov_cp_pol_e_ins (int fila, int colum, char tab[TAM_TAB][TAM_TAB]);
/*
 * cuando a la computadora le toca jugar con las piezas de las sufragistas
 */
void mov_cp_suf_y_lid (int fila, int colum, char tab[TAM_TAB][TAM_TAB]);
/*
 * MOVIMIENTO DEL USUARIO
 * segun las reglas puede mover una ficha y avanzar una casilla en cualquier direccion por turno
 * para comer la ficha del contrario
 * Los de bajo rango solo pueden comer de manera diagonal
 * y Los de alto rango en todas las direcciones, haciendo un salto de dos casillas sobre la ficha contraria
 */
float menor_distancia_p(int * , int * );
float menor_distancia_f(int * , int * );
/*funciones que busca la menor distancia de las casillas seleccionadas
 * hacia las casillas protegidas por sus contrarios
 */
void mov_us (char tab[TAM_TAB][TAM_TAB]);
/*
 * VERIFICACION DE MOVIMIENTO DEL USUARIO CUANDO JUEGA CON LAS SUFRAGISTAS
 * una funcion que realiza los movimientos de las piezas
 * recibe como parametros la fila, la columna y el tablero
 * retorna los cambios en el tablero.
 */
void mov_lid_o_suf (int fila, int colum, char tab[TAM_TAB][TAM_TAB]);
/*
 * VERIFICACION DE MOVIMIENTO DE USUARIO CUANDO JUEGA CON LOS POLICIAS
 * en esta funcion se verifican los movimientos del usuario cuando le toca jugar con los policias o inspectores
 * sus parametros son la fila y columna iniciales introducidas de la funcion mov_us
 * en el caso de las lideresas y los inspectores que pueden comer en todas las direcciones.
 * retorna los cambios en el tablero
 */
void mov_ins_o_pol(int fila, int colum, char tab[TAM_TAB][TAM_TAB]);
/*
 * FUNCIONES DE TRANSLADOS DE PIEZAS COMIDAS
 * funcion que lleva a las piezas comidas al hospital o a la prision
 * parametros la fila y columna donde estaba la pieza comida
 * para verificar que piezas son, si son lideresas o sufragistas, inspectores o policias
 * retorna los cambios en el tablero, mostrando en los hospitales o prision cuantas piezas hay.
 */
void piezas_comidas_sl(int *fil, int *col, char tab[TAM_TAB][TAM_TAB]);

void piezas_comidas_pi(int *fil, int *col, char tab[TAM_TAB][TAM_TAB]);

/*
 * FUNCIONES DE COMER
 * esta funcion determina si es valido comer una pieza
 * recibe como parametros un auxiliar k, la fila y columna final y tb la fila y columna inicial
 * retornara un valor para k, un valor de x e y que seria donde se encuentra la pieza que va a ser comida.
 * solo se permite comer en las posiciones columna > 4 y columna < 14
 */
void funcion_comer(int * k, int *x, int *y, int columna_f, int fila_f, int fila_i, int columna_i);

void funcion_comer_ins_y_pol(int * k, int *x, int *y, int columna_f, int fila_f, int fila_i, int columna_i);
/*
 * FUNCION DE NEGOCIACION
 * Si el usuario quiere liberar fichas en esta funcion se realiza la "negociacion"
 * si hay 12 piezas en el hospital y 12 piezas en la prision cumple con la condicion,
 * 6 piezas son llevadas a los patios o terrenos.
 * retorna los cambios en el tablero.
 *
 */
void liberacion(char tab[TAM_TAB][TAM_TAB]);

/*
 * EVALUA SI SE PUEDEN LIBERAR FICHAS
 * en esta funcion se verifica si hay fichas que pueden ser liberadas
 * segun las reglas del juego, las fichas que van al hospital o a prision,
 * pueden ser liberas si en el hospital o en la prision hay 12 fichas respectivamente,
 * la funcion evalua y si se cumple esta condicion, lleva 6 fichas de cada bando a
 * los del hospital -----> Hospital Grounds
 * y los de la prision -----> Prison Yard
 *
 */
void cond_libertad(char tab[TAM_TAB][TAM_TAB]);

/*
 * CONDICION DEL GANADOR
 * parametros puntero ganador,
 * retorna el valor de ganador
 * Aquel que llegue a meter 6 fichas en
 * Casa de los Comunes ----> COMMONS_HOUSE.... en este caso imprime que "LAS SUFRAGISTAS ENTRARON A LA CASA DE LOS COMUNES, LAS SUFRAGISTAS GANAN!!! :D"
 * Albert Hall ----> ALBERT_HALL.... en este caso imprime que "LOS POLICIAS INGRESARON EN EL TEATRO ALBERT HALL, LOS POLICIAS GANAN... :("
 */
int cond_de_Gan(int * ganador);
/*
 * IMPRIME EL TABLERO
 */
void tablero(char tab[TAM_TAB][TAM_TAB]);


#endif /* GAME_SUFFRAGETTO_TP_H_ */

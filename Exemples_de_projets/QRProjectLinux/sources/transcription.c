#include <stdio.h>
#include <stdlib.h>
#include "variablesglobal.h"

int valeur_case;

int trans_taux_correction(void)
{
    valeur_case = tableau_FORMAT [0];
    valeur_masque += valeur_case*2;

    valeur_case = tableau_FORMAT [1];
    valeur_masque += valeur_case;

    return EXIT_SUCCESS;
}

int trans_masque(void)
{
    valeur_case = tableau_FORMAT [2];
    valeur_masque += valeur_case*4;

    valeur_case = tableau_FORMAT [3];
    valeur_masque += valeur_case*2;

    valeur_case = tableau_FORMAT [4];
    valeur_masque += valeur_case;

    return EXIT_SUCCESS;
}

int trans_modeencod(void)
{
    valeur_case = tableau_QR [20][20];
    valeur_modeencod += valeur_case*8;

    valeur_case = tableau_QR [20][19];
    valeur_modeencod += valeur_case*4;

    valeur_case = tableau_QR [19][20];
    valeur_modeencod += valeur_case*2;

    valeur_case = tableau_QR [19][19];
    valeur_modeencod += valeur_case;

    return EXIT_SUCCESS;
}

int trans_taillemessage(void)
{
    valeur_case = tableau_QR [18][20];
    valeur_taillemessage += valeur_case*128;

    valeur_case = tableau_QR [18][19];
    valeur_taillemessage += valeur_case*64;

    valeur_case = tableau_QR [17][20];
    valeur_taillemessage += valeur_case*32;

    valeur_case = tableau_QR [17][19];
    valeur_taillemessage += valeur_case*16;

    valeur_case = tableau_QR [16][20];
    valeur_taillemessage += valeur_case*8;

    valeur_case = tableau_QR [16][19];
    valeur_taillemessage += valeur_case*4;

    valeur_case = tableau_QR [15][20];
    valeur_taillemessage += valeur_case*2;

    valeur_case = tableau_QR [15][19];
    valeur_taillemessage += valeur_case;

    return EXIT_SUCCESS;
}

int trans_message(void)
{
    /*Octet a*/

    valeur_case = tableau_QR [14][20];
    valeur_octet_a += valeur_case*128;

    valeur_case = tableau_QR [14][19];
    valeur_octet_a += valeur_case*64;

    valeur_case = tableau_QR [13][20];
    valeur_octet_a += valeur_case*32;

    valeur_case = tableau_QR [13][19];
    valeur_octet_a += valeur_case*16;

    valeur_case = tableau_QR [12][20];
    valeur_octet_a += valeur_case*8;

    valeur_case = tableau_QR [12][19];
    valeur_octet_a += valeur_case*4;

    valeur_case = tableau_QR [11][20];
    valeur_octet_a += valeur_case*2;

    valeur_case = tableau_QR [11][19];
    valeur_octet_a += valeur_case;

    /*Octet b*/

    valeur_case = tableau_QR [10][20];
    valeur_octet_b += valeur_case*128;

    valeur_case = tableau_QR [10][19];
    valeur_octet_b += valeur_case*64;

    valeur_case = tableau_QR [9][20];
    valeur_octet_b += valeur_case*32;

    valeur_case = tableau_QR [9][19];
    valeur_octet_b += valeur_case*16;

    valeur_case = tableau_QR [9][18];
    valeur_octet_b += valeur_case*8;

    valeur_case = tableau_QR [9][17];
    valeur_octet_b += valeur_case*4;

    valeur_case = tableau_QR [10][18];
    valeur_octet_b += valeur_case*2;

    valeur_case = tableau_QR [10][17];
    valeur_octet_b += valeur_case;

    /*Octet C*/

    valeur_case = tableau_QR [11][18];
    valeur_octet_c += valeur_case*128;

    valeur_case = tableau_QR [11][17];
    valeur_octet_c += valeur_case*64;

    valeur_case = tableau_QR [12][18];
    valeur_octet_c += valeur_case*32;

    valeur_case = tableau_QR [12][17];
    valeur_octet_c += valeur_case*16;

    valeur_case = tableau_QR [13][18];
    valeur_octet_c += valeur_case*8;

    valeur_case = tableau_QR [13][17];
    valeur_octet_c += valeur_case*4;

    valeur_case = tableau_QR [14][18];
    valeur_octet_c += valeur_case*2;

    valeur_case = tableau_QR [14][17];
    valeur_octet_c += valeur_case;

    /*Octet D*/

    valeur_case = tableau_QR [15][18];
    valeur_octet_d += valeur_case*128;

    valeur_case = tableau_QR [15][17];
    valeur_octet_d += valeur_case*64;

    valeur_case = tableau_QR [16][18];
    valeur_octet_d += valeur_case*32;

    valeur_case = tableau_QR [16][17];
    valeur_octet_d += valeur_case*16;

    valeur_case = tableau_QR [17][18];
    valeur_octet_d += valeur_case*8;

    valeur_case = tableau_QR [17][17];
    valeur_octet_d += valeur_case*4;

    valeur_case = tableau_QR [18][18];
    valeur_octet_d += valeur_case*2;

    valeur_case = tableau_QR [18][17];
    valeur_octet_d += valeur_case;

    /*Octet E*/

    valeur_case = tableau_QR [19][18];
    valeur_octet_e += valeur_case*128;

    valeur_case = tableau_QR [19][17];
    valeur_octet_e += valeur_case*64;

    valeur_case = tableau_QR [20][18];
    valeur_octet_e += valeur_case*32;

    valeur_case = tableau_QR [20][17];
    valeur_octet_e += valeur_case*16;

    valeur_case = tableau_QR [20][16];
    valeur_octet_e += valeur_case*8;

    valeur_case = tableau_QR [20][15];
    valeur_octet_e += valeur_case*4;

    valeur_case = tableau_QR [19][16];
    valeur_octet_e += valeur_case*2;

    valeur_case = tableau_QR [19][15];
    valeur_octet_e += valeur_case;

    /*Octet f*/

    valeur_case = tableau_QR [18][16];
    valeur_octet_f += valeur_case*128;

    valeur_case = tableau_QR [18][15];
    valeur_octet_f += valeur_case*64;

    valeur_case = tableau_QR [17][16];
    valeur_octet_f += valeur_case*32;

    valeur_case = tableau_QR [17][15];
    valeur_octet_f += valeur_case*16;

    valeur_case = tableau_QR [16][16];
    valeur_octet_f += valeur_case*8;

    valeur_case = tableau_QR [16][15];
    valeur_octet_f += valeur_case*4;

    valeur_case = tableau_QR [15][16];
    valeur_octet_f += valeur_case*2;

    valeur_case = tableau_QR [15][15];
    valeur_octet_f += valeur_case;

    /*Octet g*/

    valeur_case = tableau_QR [14][16];
    valeur_octet_g += valeur_case*128;

    valeur_case = tableau_QR [14][15];
    valeur_octet_g += valeur_case*64;

    valeur_case = tableau_QR [13][16];
    valeur_octet_g += valeur_case*32;

    valeur_case = tableau_QR [13][15];
    valeur_octet_g += valeur_case*16;

    valeur_case = tableau_QR [12][16];
    valeur_octet_g += valeur_case*8;

    valeur_case = tableau_QR [12][15];
    valeur_octet_g += valeur_case*4;

    valeur_case = tableau_QR [11][16];
    valeur_octet_g += valeur_case*2;

    valeur_case = tableau_QR [11][15];
    valeur_octet_g += valeur_case;

    /*Octet h*/

    valeur_case = tableau_QR [10][16];
    valeur_octet_h += valeur_case*128;

    valeur_case = tableau_QR [10][15];
    valeur_octet_h += valeur_case*64;

    valeur_case = tableau_QR [9][16];
    valeur_octet_h += valeur_case*32;

    valeur_case = tableau_QR [9][15];
    valeur_octet_h += valeur_case*16;

    valeur_case = tableau_QR [9][14];
    valeur_octet_h += valeur_case*8;

    valeur_case = tableau_QR [9][13];
    valeur_octet_h += valeur_case*4;

    valeur_case = tableau_QR [10][14];
    valeur_octet_h += valeur_case*2;

    valeur_case = tableau_QR [10][13];
    valeur_octet_h += valeur_case;

    /*Octet i*/

    valeur_case = tableau_QR [11][14];
    valeur_octet_i += valeur_case*128;

    valeur_case = tableau_QR [11][13];
    valeur_octet_i += valeur_case*64;

    valeur_case = tableau_QR [12][14];
    valeur_octet_i += valeur_case*32;

    valeur_case = tableau_QR [12][13];
    valeur_octet_i += valeur_case*16;

    valeur_case = tableau_QR [13][14];
    valeur_octet_i += valeur_case*8;

    valeur_case = tableau_QR [13][13];
    valeur_octet_i += valeur_case*4;

    valeur_case = tableau_QR [14][14];
    valeur_octet_i += valeur_case*2;

    valeur_case = tableau_QR [14][13];
    valeur_octet_i += valeur_case;

    /*Octet j*/

    valeur_case = tableau_QR [15][14];
    valeur_octet_j += valeur_case*128;

    valeur_case = tableau_QR [15][13];
    valeur_octet_j += valeur_case*64;

    valeur_case = tableau_QR [16][14];
    valeur_octet_j += valeur_case*32;

    valeur_case = tableau_QR [16][13];
    valeur_octet_j += valeur_case*16;

    valeur_case = tableau_QR [17][14];
    valeur_octet_j += valeur_case*8;

    valeur_case = tableau_QR [17][13];
    valeur_octet_j += valeur_case*4;

    valeur_case = tableau_QR [18][14];
    valeur_octet_j += valeur_case*2;

    valeur_case = tableau_QR [18][13];
    valeur_octet_j += valeur_case;

    /* Octet k */

	valeur_case = tableau_QR [19] [14];
	valeur_octet_k += valeur_case*128;

	valeur_case = tableau_QR [19] [13];
	valeur_octet_k += valeur_case*64;

	valeur_case = tableau_QR [20] [14];
	valeur_octet_k += valeur_case*32;

	valeur_case = tableau_QR [20] [13];
	valeur_octet_k += valeur_case*16;

	valeur_case = tableau_QR [20] [12];
	valeur_octet_k += valeur_case*8;

	valeur_case = tableau_QR [20] [11];
	valeur_octet_k += valeur_case*4;

	valeur_case = tableau_QR [19] [12];
	valeur_octet_k += valeur_case*2;

	valeur_case = tableau_QR [19] [11];
	valeur_octet_k += valeur_case*1;

    /* Octet l */

	valeur_case = tableau_QR [18][10];
	valeur_octet_l += valeur_case*128;

	valeur_case = tableau_QR [18][9];
	valeur_octet_l += valeur_case*64;

	valeur_case = tableau_QR [17] [10];
	valeur_octet_l += valeur_case*32;

	valeur_case = tableau_QR [17][9];
	valeur_octet_l += valeur_case*16;

	valeur_case = tableau_QR [16][10];
	valeur_octet_l += valeur_case*8;

	valeur_case = tableau_QR [16][9];
	valeur_octet_l += valeur_case*4;

	valeur_case = tableau_QR [15][10];
	valeur_octet_l += valeur_case*2;

	valeur_case = tableau_QR [15][9];
	valeur_octet_l += valeur_case*1;

    /* Octet m */

	valeur_case = tableau_QR [14][12];
	valeur_octet_m += valeur_case*128;

	valeur_case = tableau_QR [14][11];
	valeur_octet_m += valeur_case*64;

	valeur_case = tableau_QR [13][12];
	valeur_octet_m += valeur_case*32;

	valeur_case = tableau_QR [13][11];
	valeur_octet_m += valeur_case*16;

	valeur_case = tableau_QR [12][12];
	valeur_octet_m += valeur_case*8;

	valeur_case = tableau_QR [12][11];
	valeur_octet_m += valeur_case*4;

	valeur_case = tableau_QR [11][12];
	valeur_octet_m += valeur_case*2;

	valeur_case = tableau_QR [11][11];
	valeur_octet_m += valeur_case*1;

    /* Octet n */

	valeur_case = tableau_QR [10][12];
	valeur_octet_n += valeur_case*128;

	valeur_case = tableau_QR [10][11];
	valeur_octet_n += valeur_case*64;

	valeur_case = tableau_QR [9][12];
	valeur_octet_n += valeur_case*32;

	valeur_case = tableau_QR [9][11];
	valeur_octet_n += valeur_case*16;

	valeur_case = tableau_QR [8][12];
	valeur_octet_n += valeur_case*8;

	valeur_case = tableau_QR [8][11];
	valeur_octet_n += valeur_case*4;

	valeur_case = tableau_QR [7][12];
	valeur_octet_n += valeur_case*2;

	valeur_case = tableau_QR [7][11];
	valeur_octet_n += valeur_case*1;

    /* Octet o */

	valeur_case = tableau_QR [5][12];
	valeur_octet_o += valeur_case*128;

	valeur_case = tableau_QR [5][11];
	valeur_octet_o += valeur_case*64;

	valeur_case = tableau_QR [4][12];
	valeur_octet_o += valeur_case*32;

	valeur_case = tableau_QR [4][11];
	valeur_octet_o += valeur_case*16;

	valeur_case = tableau_QR [3][12];
	valeur_octet_o += valeur_case*8;

	valeur_case = tableau_QR [3][11];
	valeur_octet_o += valeur_case*4;

	valeur_case = tableau_QR [2][12];
	valeur_octet_o += valeur_case*2;

	valeur_case = tableau_QR [2][11];
	valeur_octet_o += valeur_case*1;

    /* Octet p */

	valeur_case = tableau_QR [1][12];
	valeur_octet_p += valeur_case*128;

	valeur_case = tableau_QR [1][11];
	valeur_octet_p += valeur_case*64;

	valeur_case = tableau_QR [0][12];
	valeur_octet_p += valeur_case*32;

	valeur_case = tableau_QR [0][11];
	valeur_octet_p += valeur_case*16;

	valeur_case = tableau_QR [0][10];
	valeur_octet_p += valeur_case*8;

	valeur_case = tableau_QR [0][9];
	valeur_octet_p += valeur_case*4;

	valeur_case = tableau_QR [1][10];
	valeur_octet_p += valeur_case*2;

	valeur_case = tableau_QR [1][9];
	valeur_octet_p += valeur_case*1;

    /* Octet q */

	valeur_case = tableau_QR [2][10];
	valeur_octet_q += valeur_case*128;

	valeur_case = tableau_QR [2][9];
	valeur_octet_q += valeur_case*64;

	valeur_case = tableau_QR [3][10];
	valeur_octet_q += valeur_case*32;

	valeur_case = tableau_QR [3][9];
	valeur_octet_q += valeur_case*16;

	valeur_case = tableau_QR [4][10];
	valeur_octet_q += valeur_case*8;

	valeur_case = tableau_QR [4][9];
	valeur_octet_q += valeur_case*4;

	valeur_case = tableau_QR [5][10];
	valeur_octet_q += valeur_case*2;

	valeur_case = tableau_QR [5][9];
	valeur_octet_q += valeur_case*1;

	return EXIT_SUCCESS;
}

int trans_erreur (void)
{
	/* Octet erreur a */

	valeur_case = tableau_QR [9][10];
	valeur_octet_er_a += valeur_case*128;

	valeur_case = tableau_QR [9][9];
	valeur_octet_er_a += valeur_case*64;

	valeur_case = tableau_QR [10][10];
	valeur_octet_er_a += valeur_case*32;

	valeur_case = tableau_QR [10][9];
	valeur_octet_er_a += valeur_case*16;

	valeur_case = tableau_QR [11][10];
	valeur_octet_er_a += valeur_case*8;

	valeur_case = tableau_QR [11][9];
	valeur_octet_er_a += valeur_case*4;

	valeur_case = tableau_QR [12][10];
	valeur_octet_er_a += valeur_case*2;

	valeur_case = tableau_QR [12][9];
	valeur_octet_er_a += valeur_case*1;

	/* octet erreur b */

	valeur_case = tableau_QR [13][10];
	valeur_octet_er_b += valeur_case*128;

	valeur_case = tableau_QR [13][9];
	valeur_octet_er_b += valeur_case*64;

	valeur_case = tableau_QR [14][10];
	valeur_octet_er_b += valeur_case*32;

	valeur_case = tableau_QR [14][9];
	valeur_octet_er_b += valeur_case*16;

	valeur_case = tableau_QR [15][10];
	valeur_octet_er_b += valeur_case*8;

	valeur_case = tableau_QR [15][9];
	valeur_octet_er_b += valeur_case*4;

	valeur_case = tableau_QR [16][10];
	valeur_octet_er_b += valeur_case*2;

	valeur_case = tableau_QR [16][9];
	valeur_octet_er_b += valeur_case*1;

	/* octet erreur c */

	valeur_case = tableau_QR [17][10];
	valeur_octet_er_c += valeur_case*128;

	valeur_case = tableau_QR [17][9];
	valeur_octet_er_c += valeur_case*64;

	valeur_case = tableau_QR [18][10];
	valeur_octet_er_c += valeur_case*32;

	valeur_case = tableau_QR [18][9];
	valeur_octet_er_c += valeur_case*16;

	valeur_case = tableau_QR [19][10];
	valeur_octet_er_c += valeur_case*8;

	valeur_case = tableau_QR [19][9];
	valeur_octet_er_c += valeur_case*4;

	valeur_case = tableau_QR [20][10];
	valeur_octet_er_c += valeur_case*2;

	valeur_case = tableau_QR [20][9];
	valeur_octet_er_c += valeur_case*1;

	/* Octet erreur d */

	valeur_case = tableau_QR [12][8];
	valeur_octet_er_d += valeur_case*128;

	valeur_case = tableau_QR [12][7];
	valeur_octet_er_d += valeur_case*64;

	valeur_case = tableau_QR [11][8];
	valeur_octet_er_d += valeur_case*32;

	valeur_case = tableau_QR [11][7];
	valeur_octet_er_d += valeur_case*16;

	valeur_case = tableau_QR [10][8];
	valeur_octet_er_d += valeur_case*8;

	valeur_case = tableau_QR [10][7];
	valeur_octet_er_d += valeur_case*4;

	valeur_case = tableau_QR [9][8];
	valeur_octet_er_d += valeur_case*2;

	valeur_case = tableau_QR [9][7];
	valeur_octet_er_d += valeur_case*1;

	/* octet erreur e */

	valeur_case = tableau_QR [9][5];
	valeur_octet_er_e += valeur_case*128;

	valeur_case = tableau_QR [9][4];
	valeur_octet_er_e += valeur_case*64;

	valeur_case = tableau_QR [10][5];
	valeur_octet_er_e += valeur_case*32;

	valeur_case = tableau_QR [10][4];
	valeur_octet_er_e += valeur_case*16;

	valeur_case = tableau_QR [11][5];
	valeur_octet_er_e += valeur_case*8;

	valeur_case = tableau_QR [11][4];
	valeur_octet_er_e += valeur_case*4;

	valeur_case = tableau_QR [12][5];
	valeur_octet_er_e += valeur_case*2;

	valeur_case = tableau_QR [12][4];
	valeur_octet_er_e += valeur_case*1;

	/* octet erreur f */

	valeur_case = tableau_QR [12][3];
	valeur_octet_er_f += valeur_case*128;

	valeur_case = tableau_QR [12][2];
	valeur_octet_er_f += valeur_case*64;

	valeur_case = tableau_QR [11][3];
	valeur_octet_er_f += valeur_case*32;

	valeur_case = tableau_QR [11][2];
	valeur_octet_er_f += valeur_case*16;

	valeur_case = tableau_QR [10][3];
	valeur_octet_er_f += valeur_case*8;

	valeur_case = tableau_QR [10][2];
	valeur_octet_er_f += valeur_case*4;

	valeur_case = tableau_QR [9][3];
	valeur_octet_er_f += valeur_case*2;

	valeur_case = tableau_QR [9][2];
	valeur_octet_er_f += valeur_case*1;

	/* octet erreur g */

	valeur_case = tableau_QR [9][1];
	valeur_octet_er_g += valeur_case*128;

	valeur_case = tableau_QR [9][0];
	valeur_octet_er_g += valeur_case*64;

	valeur_case = tableau_QR [10][1];
	valeur_octet_er_g += valeur_case*32;

	valeur_case = tableau_QR [10][0];
	valeur_octet_er_g += valeur_case*16;

	valeur_case = tableau_QR [11][1];
	valeur_octet_er_g += valeur_case*8;

	valeur_case = tableau_QR [11][0];
	valeur_octet_er_g += valeur_case*4;

	valeur_case = tableau_QR [12][1];
	valeur_octet_er_g += valeur_case*2;

	valeur_case = tableau_QR [12][0];
	valeur_octet_er_g += valeur_case*1;

    return EXIT_SUCCESS;
}

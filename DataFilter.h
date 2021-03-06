#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  FILTERERROR            -1
#define  FILEERROR              -2
#define  OPTIONERROR            -3

#define  FILTER_ALL             0x13
#define  FILTER_GMC             0
#define  FILTER_GMF             1
#define  FILTER_EMP             2
#define  FILTER_DPLC            3
#define  FILTER_DPLF            4
#define  FILTER_FORA            5
#define  FILTER_FORAMARCA       6
#define  FILTER_FORANAOMARCA    7
#define  FILTER_CASA            8
#define  FILTER_CASAMARCA       9
#define  FILTER_CASANAOMARCA    0xA
#define  FILTER_MENOS1          0xB
#define  FILTER_MENOS2          0xC
#define  FILTER_MENOS3          0xD
#define  FILTER_MENOS4          0xE
#define  FILTER_MAIS1           0xF
#define  FILTER_MAIS2           0x10
#define  FILTER_MAIS3           0x11
#define  FILTER_MAIS4           0x12
typedef struct dadosaposta{
//Tabela inicial
float GMC;  float GMF;     float DPLC;         float DPLF;
float CASA; float EMP;     float FORA;
//Ambas marcarem e vencedor da partida
float FORAMARCA;           float CASAMARCA;
float FORANAOMARCA;        float CASANAOMARCA;
//Total de Gols da partida
float MENOS1;              float MAIS1;
float MENOS2;              float MAIS2;
float MENOS3;              float MAIS3;
float MENOS4;              float MAIS4;

FILE *file;
char *data;
int sizeData;
}DadosAposta,*PDadosAposta;

int GetBetData(PDadosAposta,char*);
float FilterBetDataById(PDadosAposta,const int);
void ReleaseBetData(PDadosAposta);
float FilterBetDataByName(PDadosAposta,char *);


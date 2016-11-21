#include <malloc.h>
#include <stdio.h>

#define  FILTERERROR            0
#define  FILEERROR              1
#define  OPTIONERROR            2

#define  FILTER_ALL             0
#define  FILTER_GMC             1
#define  FILTER_GMF             3
#define  FILTER_EMP             4
#define  FILTER_DPLC            5
#define  FILTER_DPLF            6
#define  FILTER_FORA            7
#define  FILTER_FORAMARCA       8
#define  FILTER_FORANAOMARCA    9
#define  FILTER_CASA            0xA
#define  FILTER_CASAMARCA       0xB
#define  FILTER_CASANAOMARCA    0xC
#define  FILTER_MENOS1          0xD
#define  FILTER_MENOS2          0xE
#define  FILTER_MENOS3          0xF
#define  FILTER_MENOS4          0x10
#define  FILTER_MAIS1           0x11
#define  FILTER_MAIS2           0x12
#define  FILTER_MAIS3           0x13
#define  FILTER_MAIS4           0x14
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
int FilterBetData(PDadosAposta,const int);




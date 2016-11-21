#include "datafilter.h"

char STRINGTOSEARCH[][10] = {
" ",          //GMC
" ",          //GMF
" ",          //EMP
" ",          //DPLC
" ",          //DPLF
" ",          //FORA
" ",          //FORAMARCA
" ",          //FORANAOMARCA
" ",          //CASA
" ",          //CASAMARCA
" ",          //CASANAOMARCA
" ",          //MENOS1
" ",          //MENOS2
" ",          //MENOS3
" ",          //MENOS4
" ",          //MAIS1
" ",          //MAIS2
" ",          //MAIS3
" "           //MAIS4
};
int GetBetData(PDadosAposta p,char *file){
p->file = fopen(file,"rb");
if(p->file == NULL){
    return FILEERROR;
}
fseek(p->file,0,SEEK_END);
p->sizeData = ftell(p->file);
rewind(p->file);
p->data = (char*)malloc(sizeof(char)*p->sizeData);
return fread(p->data,sizeof(char),p->sizeData,p->file);
}

int FilterBetData(PDadosAposta pda,const int option){
switch(option){
case FILTER_ALL:break;
case FILTER_CASA:break;
case FILTER_CASAMARCA:break;
case FILTER_CASANAOMARCA:break;
case FILTER_DPLC:break;
case FILTER_DPLF:break;
case FILTER_FORA:break;
case FILTER_FORANAOMARCA:break;
case FILTER_FORAMARCA:break;
case FILTER_EMP:break;
case FILTER_GMC:break;
case FILTER_GMF:break;
case FILTER_MAIS1:break;
case FILTER_MAIS2:break;
case FILTER_MAIS3:break;
case FILTER_MAIS4:break;
case FILTER_MENOS1:break;
case FILTER_MENOS2:break;
case FILTER_MENOS3:break;
case FILTER_MENOS4:break;
default:
    return OPTIONERROR;
}

return 0;
}

void ReleaseBetData(PDadosAposta o){
fclose(o->file);
free(o->data);
}

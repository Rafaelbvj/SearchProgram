#include "datafilter.h"

char STRINGTOSEARCH[][13] = {
"51-1-1.5",          //GMC
"51-2-1.5",          //GMF
"10-X",              //EMP
"46-1X",             //DPLC
"46-X2",             //DPLF
"10-2",              //FORA
"386-HY",            //FORAMARCA
"386-HN",            //FORANAOMARCA
"10-1",              //CASA
"386-AY",            //CASAMARCA
"396-AN",            //CASANAOMARCA
"56-Under-1.5",      //MENOS1
"56-Under-2.5",      //MENOS2
"56-Under-3.5",      //MENOS3
"56-Under-4.5",      //MENOS4
"56-Over-1.5",       //MAIS1
"56-Over-2.5",       //MAIS2
"56-Over-3.5",       //MAIS3
"56-Over-4.5"        //MAIS4
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

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
char Operations[15];
bool haveFound;

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

float FilterBetDataByName(PDadosAposta p , char *name){
haveFound = false;
memset(Operations,0,15);
for(int i =0;i<p->sizeData;i++){
    if(p->data[i] == '"'){
    //Searching for name results
    for(int o = i+1,pe=0;;o++,pe++){
            if(p->data[o] == '"'){
                Operations[pe] = '\0';
                i=o+1;
                break;
            }
            Operations[pe] = p->data[o];
    }
    if(haveFound == true){
        return atof(Operations);
    }
    if(strcmp(Operations,name)==0){haveFound = true;}
    }
}
return FILTERERROR;
}
float FilterBetDataById(PDadosAposta pda,const int option){

switch(option){
case FILTER_ALL:break;
case FILTER_CASA:           pda->CASA      =    FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_CASA]);          return pda->CASA;
case FILTER_CASAMARCA:      pda->CASAMARCA =    FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_CASAMARCA]);     return pda->CASAMARCA;
case FILTER_CASANAOMARCA:   pda->CASANAOMARCA = FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_CASANAOMARCA]);  return pda->CASANAOMARCA;
case FILTER_DPLC:           pda->DPLC =         FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_DPLC]);          return pda->DPLC;
case FILTER_DPLF:           pda->DPLF =         FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_DPLF]);          return pda->DPLF;
case FILTER_FORA:           pda->FORA =         FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_FORA]);          return pda->FORA;
case FILTER_FORANAOMARCA:   pda->FORANAOMARCA = FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_FORANAOMARCA]);  return pda->FORANAOMARCA;
case FILTER_FORAMARCA:      pda->FORAMARCA =    FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_FORAMARCA]);     return pda->FORAMARCA;
case FILTER_EMP:            pda->EMP   =        FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_EMP]);           return pda->EMP;
case FILTER_GMC:            pda->GMC =          FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_GMC]);           return pda->GMC;
case FILTER_GMF:            pda->GMF =          FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_GMF]);           return pda->GMF;
case FILTER_MAIS1:          pda->MAIS1 =        FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_MAIS1]);         return pda->MAIS1;
case FILTER_MAIS2:          pda->MAIS2 =        FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_MAIS2]);         return pda->MAIS2;
case FILTER_MAIS3:          pda->MAIS3 =        FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_MAIS3]);         return pda->MAIS3;
case FILTER_MAIS4:          pda->MAIS4 =        FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_MAIS4]);         return pda->MAIS4;
case FILTER_MENOS1:         pda->MENOS1 =       FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_MENOS1]);        return pda->MENOS1;
case FILTER_MENOS2:         pda->MENOS2 =       FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_MENOS2]);        return pda->MENOS2;
case FILTER_MENOS3:         pda->MENOS3 =       FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_MENOS3]);        return pda->MENOS3;
case FILTER_MENOS4:         pda->MENOS4 =       FilterBetDataByName(pda,STRINGTOSEARCH[FILTER_MENOS4]);        return pda->MENOS4;
default:
    return OPTIONERROR;
}

}
void ReleaseBetData(PDadosAposta o){
fclose(o->file);
free(o->data);
}

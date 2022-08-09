#include <stdio.h>
#include <stdlib.h>
#include "infoRegista.h"


int Compare_Keys_Regista(Type_Key_Regista a, Type_Key_Regista b){
    return strcmp(a,b);
}

void Print_Key_Regista (Type_Key_Regista t){
   printf("\nRegista:");
   printf("\n%s\t",t);   
}

void Print_Item_Regista(Type_Item_Regista t){
   printf("%3d %3s\n",t.eta,t.nazionalita);
   printf("\n\tFilm:");
   Print_Tree(t.pTree);
}

void Print_Info_Regista(Type_Info_Regista info) {
   Print_Key_Regista(info.Key);
   Print_Item_Regista(info.Item);  
}

Type_Key_Regista Read_Key_Regista(){
   Type_Key_Regista t;
   t = (Type_Key_Regista)malloc(SIZE_KEY*sizeof(char)); 
   printf("\nNome e cognome del regista (max 30 caratteri): ");
   fflush(stdin);
   while(getchar()!='\n');
   gets(t);    
   return t;
}

Type_Item_Regista Read_Item_Regista(){
   Type_Item_Regista t;
   
   printf("\nEta' del regista: ");
   scanf("%d",&t.eta);
   printf("\nNazionalita' del regista (max 30 caratteri): ");
   fflush(stdin);
   while(getchar()!='\n');
   gets(t.nazionalita); 
   t.pTree = NULL;
   return t; 
}

Type_Info_Regista Read_Info_Regista(){
   
   Type_Info_Regista info;
   
   info.Key=Read_Key_Regista();
   info.Item=Read_Item_Regista();

   return info;              
   
}

int Size_Key_Regista(){
    return (SIZE_KEY*sizeof(char));
}



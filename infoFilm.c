#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infoFilm.h"


int Compare_Keys_Film(Type_Key_Film a, Type_Key_Film b){
    return strcmp(a,b);
}


void Print_Key_Film (Type_Key_Film t){
   printf("\n\t%s\t",t);   
}

void Print_Item_Film(Type_Item_Film t){
   printf("%3f %3d\n",t.Costo,t.Anno);
}

void Print_Info_Film(Type_Info_Film info) {
   Print_Key_Film(info.Key);
   Print_Item_Film(info.Item);  
}

Type_Key_Film Read_Key_Film(){
   Type_Key_Film t;  
   t = (Type_Key_Film)malloc(SIZE_KEY*sizeof(char)); 
   printf("\nTitolo del film (max 30 caratteri): ");
   fflush(stdin);
   gets(t);    
   return t;
}

Type_Item_Film Read_Item_Film(){
   Type_Item_Film t;
   
   printf("\nCosto di produzione del film: ");
   scanf("%f",&t.Costo);
   printf("\nAnno di produzione: ");
   scanf("%d",&t.Anno);  
   return t; 
}

Type_Info_Film Read_Info_Film(){
   
   Type_Info_Film info;
   
   info.Key=Read_Key_Film();   
   info.Item=Read_Item_Film();

   return info;              
   
}

int Size_Key_Film(){
    return (SIZE_KEY*sizeof(char));
}



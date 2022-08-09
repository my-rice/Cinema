#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "bool.h"


Type_Tree Insert_Tree(Type_Tree t, Type_Info_Film info)
{
  Type_Tree Temp, Prev, Succ;  
   int GoLeft;
   Prev=NULL;
   Succ=t;
  
   while(Succ!=NULL){
      Prev=Succ;
      if(GoLeft=(Compare_Keys_Film(info.Key,Succ->Info.Key)<0))
         Succ=Succ->Left;
      else
         Succ=Succ->Right;
   }
   Temp=(Type_Tree)malloc(sizeof(Type_Node));
   Temp->Left=NULL;
   Temp->Right=NULL;
   Temp->Info=info; 
   if(Prev==NULL)
      return Temp; 
   else if(GoLeft)
      Prev->Left=Temp;
   else
      Prev->Right=Temp;
   return t;
}


void Print_Tree(Type_Tree t)
{

	if (t != NULL)
	{
		Print_Tree(t->Left);
		Print_Info_Film(t->Info);
		Print_Tree(t->Right);
	}

}

bool Is_Empty_Tree(Type_Tree t)
{
   if(t==NULL)
      return true;
   else
      return false;
}

void Save_Tree(FILE *f, Type_Tree t)
{
   if(t!=NULL){
      Save_Tree(f,t->Left);      
      fwrite(t->Info.Key,Size_Key_Film(), 1, f);
      fwrite(&(t->Info.Item),sizeof(Type_Item_Film), 1, f);
      Save_Tree(f,t->Right);      
   }                                                           
}

int Count_Tree_Nodes(Type_Tree t)
{
   if(t==NULL)
      return 0;
   else
      return 1 + Count_Tree_Nodes(t->Left) + Count_Tree_Nodes(t->Right);
}

Type_Tree Carica_Da_File_Tree(Type_Tree t, FILE *fp)
{
      int i,r;
      Type_Info_Film info;
      Type_Node *nodo_ptr=NULL;
      int cont1=0;
      int cont2=0;
      
      fread(&r,sizeof(int),1,fp);  
      for(i=0;(i<r)&&(!feof(fp));i++)
      {
           info.Key = (Type_Key_Film)malloc(Size_Key_Film());         
           fread(info.Key,Size_Key_Film(), 1, fp);
           fread(&info.Item,sizeof(Type_Item_Film), 1, fp);
           if(nodo_ptr=Search_Tree_Recursive(t,info.Key))
              cont1++;
           else{
              cont2++;
              t=Insert_Tree(t, info);
              }
      }
      printf("Sono stati caricati %d Film\n", cont2);
      if(cont1!=0) 
         printf("Non sono stati caricati %d Film\n perche' inconsistenti\n", cont1);

      return t;
}

void Salva_Su_File_Tree(Type_Tree t,FILE *fp){
      int r;
      r=Count_Tree_Nodes(t);
      fwrite(&r,sizeof(int), 1, fp);
      Save_Tree(fp,t);
      printf("Salvati i riferimenti di %d Film\n",r);
}

Type_Node *Search_Tree_Recursive(Type_Tree t,Type_Key_Film key)
{
   if((t==NULL)||(Compare_Keys_Film(key,t->Info.Key)==0))
      return t; 
   else{
      if(Compare_Keys_Film(key,t->Info.Key)>0)
         return Search_Tree_Recursive(t->Right,key);    
      else
         return Search_Tree_Recursive(t->Left,key);    
       }
}

// Funzioni richieste al candidato

//  	 	Conta_Film    (ricorsiva)
int Conta_Film(Type_Tree tree,int anno){
    if(tree==NULL){
        return 0;
    }
    if(tree->Info.Item.Anno >= anno){
        return 1 + Conta_Film(tree->Right,anno)+ Conta_Film(tree->Left,anno);
    }
    
    return Conta_Film(tree->Left,anno) + Conta_Film(tree->Right,anno);
}



#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Type_List Insert_Ordered_List(Type_List head, Type_Info_Regista info){
   Type_List Prec, Succ, Temp;

   // Ricerca della posizione di inserimento
   Prec=NULL;
   Succ=head;
   
   while((Succ!=NULL)&&(Compare_Keys_Regista(info.Key,Succ->Info.Key)>0)){
      Prec=Succ;
      Succ=Succ->Next;
   }
   
    // Allocazione ed inizializzazione del nodo per inserire Val
    Temp=(Type_List)malloc(sizeof(Type_Node_List));
    if(Temp==NULL){
       printf("Memoria: Errore nell'allocazione.");
       exit(1);
    }  
    Temp->Info=info;
    Temp->Next=Succ;
    
    // Aggiornamento dei puntatori
    if(Prec==NULL) 
       return Temp;
    else{           
       Prec->Next=Temp;
       return head;
    }
}

Type_Node_List *Search_Ordered_List(Type_List head, Type_Key_Regista key)
{
   Type_List Succ=head;
   while((Succ!=NULL)&&(Compare_Keys_Regista(key,Succ->Info.Key)>0)){
      Succ=Succ->Next;
   }
   if((Succ!=NULL)&&(Compare_Keys_Regista(Succ->Info.Key,key)==0))
      return Succ;
   else
      return NULL;
}

void Print_List(Type_List head){
   Type_List Succ=head;

   printf("\n");
   while(Succ!=NULL){
      Print_Info_Regista(Succ->Info);
      Succ=Succ->Next;
   }
   printf("\n");
}

bool Is_Empty_List(Type_List head){
   if(head==NULL)
      return true;
   else
      return false;
}
   
int Size_List(Type_List head){
    int i;
    Type_List Succ=head;
    
    for(i=0; Succ!=NULL; i++)
       Succ=Succ->Next;
    return i;
}

Type_List Carica_Da_File(Type_List l, FILE *fp){
      int i,r;
      Type_Info_Regista info;
      Type_Tree temp;
      Type_Node_List *nodo_ptr=NULL;
      int cont1=0;
      int cont2=0;

      fread(&r,sizeof(int),1,fp);  
      for(i=0; i<r; i++){
         info.Key = (Type_Key_Regista)malloc(Size_Key_Regista());         
         fread(info.Key,Size_Key_Regista(), 1, fp);
         fread(&info.Item,sizeof(Type_Item_Regista), 1, fp);
         temp = NULL;
         temp = Carica_Da_File_Tree (temp, fp);
         if(nodo_ptr=Search_Ordered_List(l,info.Key))
            cont1++;
         else{
            cont2++;
            info.Item.pTree = temp;
            l=Insert_Ordered_List(l,info);
         }
      }
      printf("\nSono stati caricati %d Registi\n", cont2);
      if(cont1!=0) 
         printf("\nNon sono stati caricati %d Registi\n perche' inconsistenti!!\n", cont1);
      system("PAUSE");
      return l;
}


void Salva_Su_File_List(Type_List list, FILE *fp){
      int r=0;
      Type_List Curr = list;
    
      r=Size_List(list);
      fwrite(&r,sizeof(int), 1, fp);
      while(Curr!=NULL){
         fwrite(Curr->Info.Key,Size_Key_Regista(), 1, fp);
         fwrite(&(Curr->Info.Item),sizeof(Type_Item_Regista), 1, fp);
         Salva_Su_File_Tree(Curr->Info.Item.pTree,fp);
         Curr=Curr->Next;
      }
      printf("Salvati su file i riferimenti di %d Registi\n",r);
      system("PAUSE");
}

void Inserisci_Film(Type_List head)
{
  Type_Node_List *nodo;
  Type_Node *nodoAlbero;
  Type_Info_Film info;
    
  Type_Key_Regista key = Read_Key_Regista();
      
  nodo = Search_Ordered_List(head,key);
  
  if (nodo==NULL)
     printf("\nInserimento non riuscito!!\n");
  else
  {
     info = Read_Info_Film();  
     nodoAlbero = Search_Tree_Recursive(nodo->Info.Item.pTree ,info.Key);
     if (nodoAlbero!=NULL)
        printf("\nInserimento non riuscito!!\n");
     else
     {
        nodo->Info.Item.pTree = Insert_Tree(nodo->Info.Item.pTree, info);
        printf("\nInserimento riuscito!!\n");
     }
  }
  
}



// Funzioni richieste al candidato
//  	Cancella_Registi    (ricorsiva)
/*
Type_List Cancella_Registi(Type_List list){
    if(list == NULL){
        return NULL;
    }
    
    if(list->Info.Item.pTree == NULL){
        Type_List m = list;
        list = list->Next;
        free(m);
        return Cancella_Registi(list);
    }
    list->Next = Cancella_Registi(list->Next);
    return list;
}
*/

int Cancella_Registi(Type_List* list){
    if((*list) == NULL){
        return 0;
    }
    
    if((*list)->Info.Item.pTree == NULL){
        Type_List m = (*list);
        (*list) = (*list)->Next;
        free(m);
        
        return 1 + Cancella_Registi(&(*list));
    }
    return Cancella_Registi(&((*list)->Next));
}

//  	Conta_Film_Archivio    (iterativa)
int Conta_Film_Archivio(Type_List list,int anno){
    Type_List m = list;
    int sum = 0;
    while(m!=NULL){
        sum += Conta_Film(m->Info.Item.pTree,anno);
        m = m->Next;
    }
    return sum;
}



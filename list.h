#include "infoRegista.h"
#include "infoFilm.h"
#include "bool.h"

#ifndef LIST_H
#define LIST_H


/*Definizione del tipo lista concatenata semplice */
struct Tag_Node_List{
                Type_Info_Regista Info;
                struct Tag_Node_List *Next;
};
typedef struct Tag_Node_List Type_Node_List;

typedef Type_Node_List *Type_List;

//Prototipi delle funzioni gi� implementate
Type_List Insert_Ordered_List(Type_List, Type_Info_Regista);
Type_Node_List *Search_Ordered_List(Type_List, Type_Key_Regista);
void Print_List(Type_List);
bool Is_Empty_List(Type_List);
int Size_List(Type_List);
Type_List Carica_Da_File(Type_List, FILE *);
void Salva_Su_File_List(Type_List, FILE *);
void Inserisci_Film(Type_List);


//  Interfaccia delle funzioni richieste al candidato
int Conta_Film_Archivio(Type_List list,int anno);
int Cancella_Registi(Type_List* list);



#endif                     

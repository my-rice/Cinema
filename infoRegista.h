#include "bool.h"
#include "tree.h"

#ifndef INFOREGISTA_H
#define INFOREGISTA_H

#define NULL_KEY -1
#define SIZE_KEY 31

/* Definizione del tipo key */
typedef char *Type_Key_Regista;

/* Definizione della struttura dell'Informazione Satellite */
struct Tag_Item_Regista {
       int eta;
       char nazionalita[31];
       Type_Tree pTree;        
};
typedef struct Tag_Item_Regista Type_Item_Regista;

/* Definizione del tipo info */
struct Tag_Info_Regista {
       Type_Key_Regista Key;
       Type_Item_Regista Item;
};
typedef struct Tag_Info_Regista Type_Info_Regista;


/* Interfacce funzionali delle funzioni per la gestione della chiave */
int Compare_Keys_Regista(Type_Key_Regista, Type_Key_Regista);

// Funzioni per la gestione del dato satellite 
void Print_Key_Regista (Type_Key_Regista);
void Print_Item_Regista(Type_Item_Regista);
void Print_Info_Regista(Type_Info_Regista);
Type_Key_Regista Read_Key_Regista();
Type_Item_Regista Read_Item_Regista();
Type_Info_Regista Read_Info_Regista();
int Size_Key_Regista();

#endif

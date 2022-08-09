#include "bool.h"

#ifndef INFOFILM_H
#define INFOFILM_H

#define NULL_KEY -1
#define SIZE_KEY 31

/* Definizione del tipo key */
typedef char *Type_Key_Film;


/* Definizione della struttura dell'Informazione Satellite */
struct Tag_Item_Film {
       float Costo;
       int Anno;           
};
typedef struct Tag_Item_Film Type_Item_Film;

/* Definizione del tipo info */
struct Tag_Info_Film{
       Type_Key_Film Key;
       Type_Item_Film Item;
};
typedef struct Tag_Info_Film Type_Info_Film;


/* Interfacce funzionali delle funzioni per la gestione della chiave */
int Compare_Keys_Film(Type_Key_Film, Type_Key_Film);

// Funzioni per la gestione del dato satellite 
void Print_Key_Film (Type_Key_Film);
void Print_Item_Film(Type_Item_Film);
void Print_Info_Film(Type_Info_Film);
Type_Key_Film Read_Key_Film();
Type_Item_Film Read_Item_Film();
Type_Info_Film Read_Info_Film();
int Size_Key_Film();

#endif

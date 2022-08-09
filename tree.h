#include "bool.h"
#include "infoFilm.h"


// Definizione dei tipi albero e nodo
#ifndef TREE_H
#define TREE_H

struct Tag_Node{
                Type_Info_Film  Info;
                struct Tag_Node *Left;
                struct Tag_Node *Right;                                
                };
typedef struct Tag_Node Type_Node;
typedef Type_Node *Type_Tree;


//  Interfaccia delle funzioni di gestione degli alberi
Type_Tree Insert_Tree(Type_Tree, Type_Info_Film);
void Print_Tree(Type_Tree);
bool Is_Empty_Tree(Type_Tree);
void Save_Tree(FILE *, Type_Tree);
int Count_Tree_Nodes(Type_Tree);
Type_Tree Carica_Da_File_Tree(Type_Tree,FILE*);
void Salva_Su_File_Tree(Type_Tree,FILE*);
Type_Node *Search_Tree_Recursive(Type_Tree ,Type_Key_Film);

//  Interfaccia delle funzioni richieste al candidato
int Conta_Film(Type_Tree tree,int anno);
#endif

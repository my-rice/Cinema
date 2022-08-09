#include <stdio.h>
#include <stdlib.h> 
#include "bool.h"
#include "tree.h"
#include "list.h"


//PROTOTIPI FUNZIONI
int menu();

int main(int argc, char *argv[])
{

      int scelta;
      int numRegisti;
      int anno, numFilm;
      Type_Info_Regista info_Regista;
      Type_Key_Regista key_Regista;
      char nomefile[31];

      FILE *fp;  
   
      Type_List list_Registi = NULL;
      
      Type_Node_List *nodo_ptr=NULL;
      Type_Node *nodo_albero=NULL;
      

      while(scelta=menu()){
         switch(scelta){
            case 1:    system("CLS");
                       printf("\n-----------------------------------------------\n");
                       printf("\n          Caricamento elenco da file\n");
                       printf("\n-----------------------------------------------\n\n");
                       printf("Digitare nome del file: ");
                       fflush(stdin);
                       while(getchar()!='\n');
                       gets(nomefile);
                       if((fp=fopen(nomefile, "rb"))==NULL) {
                          printf("Caricamento da file non riuscito\n");
                          system("PAUSE");
                       }
                       else{
                          // inserire la chiamata alla funzione di caricamento da file
                          list_Registi = Carica_Da_File(list_Registi, fp);

                           
                          fclose(fp);
                       }
                       break;
                       
           case 2:     system("CLS");
                       printf("\n-----------------------------------------------\n");
                       printf("            Salvataggio elenco su file\n");
                       printf("\n-----------------------------------------------\n");
                       printf("Digitare nome del file: ");
                       fflush(stdin);
                       while(getchar()!='\n');
                       gets(nomefile);
                       if((fp=fopen(nomefile,"wb"))==NULL){
                          printf("Salvataggio su file non riuscito\n");
                          system("PAUSE");
                       }
                       else{
                          // inserire la chiamata alla funzione di salvataggio su file
                           Salva_Su_File_List(list_Registi, fp);
 
                          fclose(fp);
                       }
                       break; 
                       
            case 3:    system("CLS");
                       printf("\n-----------------------------------------------\n");
                       printf("\n             Stampa dell'archivio\n");
                       printf("\n-----------------------------------------------\n\n");  
                       
                       // inserire la chiamata alla funzione di stampa dell'archivio
                       Print_List(list_Registi);

                       system("PAUSE");
                       break;      
                                               	                        
            case 4:    system("CLS");
                       printf("\n-----------------------------------------------\n");
                       printf("\n          Inserimento regista \n");
                       printf("\n-----------------------------------------------\n\n"); 
                       info_Regista = Read_Info_Regista();
                      
                       if(nodo_ptr=Search_Ordered_List(list_Registi, info_Regista.Key))
                          printf("\n\nL'inserimento non e' possibile: registrazione gia' presente!\n\n\n");
                       else{    
                             // inserire la chiamata alla funzione di inserimento di un regista
                             list_Registi = Insert_Ordered_List(list_Registi, info_Regista);

                       }                       
              
                       system("PAUSE");
                       break;      
                       
            case 5:    system("CLS");
                       printf("\n-----------------------------------------------\n");
                       printf("\n          Inserimento Film \n");
                       printf("\n-----------------------------------------------\n\n"); 
                      
                       // inserire la chiamata alla funzione di inserimento di un film
                         Inserisci_Film(list_Registi);

                       system("PAUSE");
                       break;                    
            
           case 6:     system("CLS");
                       printf("\n-----------------------------------------------\n");
                       printf("            Eliminazione Registi\n");
                       printf("\n-----------------------------------------------\n");
                                              
                       // inserire la chiamata alla funzione di elimanazione registi senza film
                       numRegisti = Cancella_Registi(&list_Registi);

                       printf("\nSono stati eliminati %d Registi dall'archivio\n", numRegisti);
                                              
                       system("PAUSE");
                       break;   
                       
           case 7:     system("CLS");
                       printf("\n-----------------------------------------------\n");
                       printf("            Conta film da un certo anno\n");
                       printf("\n-----------------------------------------------\n");
                       
                       printf("\nInserire l'anno: ");
                       scanf("%d", &anno);
                       
                       int numFilm;
                       // inserire la chiamata alla funzione di conta film da un certo anno
                       numFilm = Conta_Film_Archivio(list_Registi,anno);

                       printf("\n\nIl numero di film prodotti dal %d sono %d\n", anno, numFilm);
                    
                       system("PAUSE");
                       break; 
                                          
                                 
         }
      }

      system("PAUSE");  
}

int menu()
{
    int scelta;
    
    system("CLS");
    printf("---------------------------------------------------------------\n");
    printf("GESTIONE VIDEOTECA \n\n");
    printf("1. Carica da File\n");
    printf("2. Salva su File\n"); 
    printf("3. Stampa dell'Archivio \n");      
    printf("4. Inserimento Regista\n");
    printf("5. Inserimento Film \n");  
    printf("6. Eliminazione Registi\n");
    printf("7. Conta Film da un certo anno\n");    
    printf("0. EXIT\n\n");
    printf("---------------------------------------------------------------\n");
    printf("Selezionare la scelta [0-7]: ");
    scanf("%d", &scelta);
    while((scelta<0)||(scelta>7)){
       printf("ERRORE! valore non consentito\n");                        
       printf("Selezionare la scelta [0-7]: ");
       scanf("%d", &scelta);
    }
    return scelta;
}




// inserire la chiamata alla funzione di conta richiesta

# Cinema
## Exercise description
The candidate creates a program for the management of a video store. The archive contains two information: those relating to the director (type Type_Info_Regista) and those relating to a film (type Type_Info_Film).

The first information consists of:
- Name and Surname of the director (string of 30 characters). It is assumed that there cannot be two directors with the same name and surname, so this field is the key information (of type Type_Key_Regista).
- Age (whole)
- Nationality (30-character string)
- Set of films produced by the director (pointer tree)
The second information consists of:
- Title of the film (string of 30 characters), which takes on the function of key (of type Type_Key_Film)
- Cost of production (float)
- Year of production (full)

Archive management requires the implementation of the following features:
- Uploading the archive from file (functionality already provided to the candidate)
- Saving the archive on file (functionality already provided to the candidate)
- Archive printing (functionality already provided to the candidate)
- Inclusion in the archive of a director (functionality already provided to the candidate)
- Inclusion in the archive of a film related to a director already present in the archive (functionality already provided to the candidate)
- Elimination of all directors who do not have associated films (functionality required by the candidate)
- Calculation of the number of films produced from a certain year onwards (functionality required by the candidate)



## PHYSICAL DATA STRUCTURE: Description
The data structure to be used, for the implementation of the archive, is a linked list (ListaRegisti): each node contains the pointer to a binary tree (TreeFilm - one for each director), containing information relating to the films produced by the director ( the pointer is "null" if there are no films associated with the director). The linked list is ordered (in ascending order) with respect to the key field of type Type_Key_Regista; the binary tree is ordered with respect to the Type_Key_Film type key field. For an example of the data structure, refer to the following figure.


## MATERIAL PROVIDED TO THE CANDIDATE: Given Files
The candidate is provided with the following files:
- infoRegista.h: contains the definition of the Type_Info_Regista type and the prototypes of the functions for reading from the keyboard, printing and comparing Type_Info_Regista, Type_Item_Regista and Type_Key_Regista data; this file must not be modified;
- infoRegista.c: contains the implementation of the functions declared in infoRegista.h; this file must not be modified;
- infoFilm.h: contains the definition of the Type_Info_Film type and the prototypes of the functions for reading from the keyboard, printing and comparing Type_Info_Film, Type_Item_Film and Type_Key_Film data; this file must not be modified;
- infoFilm.c: contains the implementation of the functions declared in infoFilm.h; this file must not be modified;
- list.h: contains the definition of the “ListaRegisti” data structure and the prototypes of the management functions. The information present in the data structure is of the Type_Info_Regista type (present in the infoRegista.h file). This file must be integrated with the prototypes of the functions not provided to the candidate;
- list.c: contains the implementation of the functions for managing the linked list (defined in list.h); This file must be integrated with the implementation of the required functions;
- tree.h: contains the definition of the “AlberoFilm” data structure and the prototypes of the functions already provided to the candidate. The information present in the data structure is of the Type_Info_Film type (present in the infoFilm.h file). This file must be integrated with the prototypes of the functions not provided to the candidate;
- tree.c: contains the implementation of the functions for managing the binary tree (defined in tree.h). This file must be integrated with the implementation of the required functions;
- bool.h: contains the definition of a boolean type; this file must not be modified;
- managementVideoteca.c: contains a complete main for managing the archive. This file must be integrated with the calls to the required functions;
- GestioneVideoteca.exe: it is an executable of the correct program that exemplifies the functionality of the program (possibly use it to understand how the complete program must work);
- Video library: binary file that contains a set of records that can be uploaded using the upload from file function already provided to the candidate; this file must not be modified.


## WHAT IS REQUIRED FROM THE CANDIDATE: Tasks
The candidate is required to:
- create a C project using the provided files;
- modify the file tree.c, implementing the following subroutines:
- Conta_Film: the subroutine calculates the number of films, present in the tree, produced starting from a given year (including the year indicated). The function receives the tree and the year as input, and returns an integer. A recursive implementation is required.
- modify the file tree.h, integrating it with the prototypes of the required functions;
- modify the list.c file, implementing the following subroutines (for which to define an appropriate interface):
- Delete_Directors: the subroutine eliminates from the list all the directors who have no associated films and provides the number of directors deleted. A recursive implementation is required.
- Conta_Film_Archivio: the subprogram calculates the number of films, present in the archive, produced starting from a given year (including the year indicated). The function receives the list of directors and the year as input, and returns an integer. An iterative implementation is required.
- modify the list.h file, integrating it with the prototypes of the required functions;
- modify the video library management file, integrating it with calls to all the functions necessary to implement the application's functionality;
#include "syscall.h"
#ifdef CHANGED

//----------------------------------------------------------------------
// Ce test de l'appel système PutString permet de verifier sont bon fonctionnement en affichant une chaine de caratere dans la console.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/putstring
// Une fois lancer le programme affcihe la chaine "Hello world!\n".
// La première chaine a une taille inférieure a MAX_STRING_SIZE, la deuxième une atille supérieure.
//----------------------------------------------------------------------

int main()
{
    PutString("Hello from second processus\n");
    while(1);
    return 0;
}

#endif
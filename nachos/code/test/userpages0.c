#include "syscall.h"

//----------------------------------------------------------------------
// Ce test de l'appel système PutChar permet de verifier sont bon fonctionnement en affichant un charactère dans la console.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/putchar
// Une fois lancer le programme affiche les 3 premières lettres de l'alphabet une à une.
//----------------------------------------------------------------------


int main()
{
    int i,r;
    for (i = 0; i<50; i++){
        r = ForkExec("../test/makeThreads");
        if(r == -1){
            PutString("Impossible de lancer de nouveau processus!\n");
        }
    }
    return 0;
}
#include "syscall.h"

//----------------------------------------------------------------------
// Ce test de l'appel système PutChar permet de verifier sont bon fonctionnement en affichant un charactère dans la console.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/putchar
// Une fois lancer le programme affiche les 3 premières lettres de l'alphabet une à une.
//----------------------------------------------------------------------


int main()
{
    PutString("Hello from main\n");
    ForkExec("../test/putstringForFork");
    ForkExec("../test/putstringForFork");
    while(1);
    return 0;
}
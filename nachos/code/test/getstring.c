#include "syscall.h"

//----------------------------------------------------------------------
// Ce test de l'appel système GetString permet de verifier sont bon fonctionnement en saisissant une chaine de charactère dans la console.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/getstring
// Une fois lancer le programme attend une chaine de character a taper au clavier.
// Une fois saisi le programme affiche la chaine qui a été reçu.
//----------------------------------------------------------------------

int main()
{
    int c = GetString();
    PutString("chaine reçu : ");
    PutString(c);
    PutString('\n');
    return 0;
}
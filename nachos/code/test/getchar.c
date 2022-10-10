#include "syscall.h"

//----------------------------------------------------------------------
// Ce test de l'appel système GetChar permet de verifier sont bon fonctionnement en saisissant un charactère dans la console.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/getchar
// Une fois lancer le programme attend un character a taper au clavier.
// Une fois saisi le programme affiche le caractère qui a été reçu.
// Testez les caractères[a-z], le é ou à, le \0 et \n.   
// Si plus d'un caractere est saisi, seul le premier est affiché.
//----------------------------------------------------------------------

int main()
{
    char c = GetChar();
    PutString("caractère recu : ");
    PutChar(c);
    PutChar('\n');
    return 0;
}
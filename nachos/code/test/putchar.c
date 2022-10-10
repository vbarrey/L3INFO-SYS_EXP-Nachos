#include "syscall.h"

//----------------------------------------------------------------------
// Ce test de l'appel système PutChar permet de verifier sont bon fonctionnement en affichant un charactère dans la console.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/putchar
// Une fois lancer le programme affiche les 3 premières lettres de l'alphabet une à une.
//----------------------------------------------------------------------

void print(char c, int n)
{
    int i;
#if CHANGED
for (i = 0; i < n; i++) {
PutChar(c + i);
}
#endif
}
int main()
{
    print('a', 3);
    print('é', 1);
    print('\0', 1);
    print('\n', 1);
    return 0;
}
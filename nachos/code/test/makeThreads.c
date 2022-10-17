#include "syscall.h"

//----------------------------------------------------------------------
// Ce test permet de vérifier l'implémentation des threads utilisateurs.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/threadTest
// Une fois lancé, le programme lance un nouveau thread utilisateur sur lequel le programme putChar est lancé.
//----------------------------------------------------------------------

void test(void* c)
{
    PutChar('A');
    ThreadExit();
}

void testParam(void* v)
{
    //TO IMPROVE mettre testParam dans le main
    char c = *(char*)v;
    PutChar(c);
    ThreadExit();
}


int main()
{
    char c;
    ThreadCreate(test, (void*)('a'));

    c = GetChar();
    while(1);

    return 0;
}
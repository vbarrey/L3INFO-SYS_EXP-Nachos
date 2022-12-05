#include "syscall.h"

//----------------------------------------------------------------------
// Ce test permet de vérifier l'implémentation des threads utilisateurs.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/threadTest
// Une fois lancé, le programme lance un nouveau thread utilisateur sur lequel le programme putChar est lancé.
//----------------------------------------------------------------------

void test(void* c)
{
    PutString("makeThread test.\n");
    ThreadExit();
}

void testParam(void* v)
{
    char c = (char)v;
    PutChar(c);
    ThreadExit();
}


int main()
{
    int i;
    for(i=0; i<12; i++){
        ThreadCreate(test, (void*)('a'));
    }
    return 0;
}
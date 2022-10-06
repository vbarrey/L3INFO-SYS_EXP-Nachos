#include "syscall.h"

int main()
{
    char *c = GetString();
    PutString("chaine reçu : ");
    PutString(c);
    return 0;
}
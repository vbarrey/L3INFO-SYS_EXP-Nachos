#include "syscall.h"

int main()
{
    char c = GetChar();
    PutString("caractère reçu : ");
    PutChar(c);
    return 0;
}
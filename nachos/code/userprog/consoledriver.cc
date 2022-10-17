#ifdef CHANGED

#include "copyright.h"
#include "system.h"
#include "consoledriver.h"
#include "synch.h"

static Semaphore *readAvail;
static Semaphore *writeDone;
static Semaphore *lockRead;
static Semaphore *lockWrite;

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }

ConsoleDriver::ConsoleDriver(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    lockRead = new Semaphore("read operation", 1);
    lockWrite = new Semaphore("write operation", 1);
    console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, NULL);
}

ConsoleDriver::~ConsoleDriver()
{
    delete console;
    delete writeDone;
    delete readAvail;
    delete lockRead;
    delete lockWrite;
}

void ConsoleDriver::PutChar(int ch)
{
    lockWrite->P();
    console->TX (ch);
    writeDone->P ();
    lockWrite->V();
}

int ConsoleDriver::GetChar()
{
    lockRead->P();
    readAvail->P ();
    int i = console->RX ();
    lockRead->V();
    return i;
}

void ConsoleDriver::PutString(const char *s)
{
    for(int i=0; i<strlen(s); i++){
        PutChar(s[i]);
    }
}

void ConsoleDriver::GetString(char *s, int n)
{
    int i=0;
    char readedChar = GetChar();
    
    while (i<n-1 && readedChar != EOF)
    {
        s[i] = readedChar;
        if(readedChar == '\n'){
            break;
        }
        i++;
        readedChar = GetChar();      
    }
    s[i] = '\0';
}

#endif // CHANGED
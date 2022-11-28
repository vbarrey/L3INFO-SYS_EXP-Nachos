#ifdef CHANGED

#include "copyright.h"
#include "system.h"
#include "userproc.h"
#include "addrspace.h"


//----------------------------------------------------------------------
// StartUserProg
//      function used to initialize and start a process in User mode.
//----------------------------------------------------------------------
static void StartUserProg(void* schmurtz){
    schmurtz=schmurtz;
    currentThread->space->InitRegisters();
    
    machine->Run();

    
}

//----------------------------------------------------------------------
// do_ForkExec
//      Create a new Process.
//----------------------------------------------------------------------
int do_ForkExec(char* f){
    //TO CHANGE
    OpenFile *file = fileSystem->Open (f);
    AddrSpace *addrSpace;
    try{
        addrSpace = new AddrSpace(file);
    }catch(std::bad_alloc & e){
        DEBUG ('s', "Number of null\n");
        delete file;
        return -1;
    }
    delete file;
    Thread *newPrincipal = new Thread("newPrincipal");
    newPrincipal->space = addrSpace;
    accessNumProc->P();
    numProc++;
    accessNumProc->V();
    
    newPrincipal->Start(StartUserProg, NULL);
    return 0;
}




#endif //CHANGED
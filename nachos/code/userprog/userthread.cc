#ifdef CHANGED

#include "copyright.h"
#include "system.h"
#include "addrspace.h"

//----------------------------------------------------------------------
// StartUserThread
//      function used to initialize and start a thread in User mode.
//----------------------------------------------------------------------
static void StartUserThread (void* schmurtz){
    int* schmurtzInt = (int*)schmurtz;
    int f = schmurtzInt[0];
    int args = schmurtzInt[1];
    free(schmurtz);

    int i;

    for (i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);

    machine->WriteRegister (PCReg, f);
    machine->WriteRegister (4, args);

    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);

    machine->WriteRegister (StackReg, currentThread->space->AllocateUserStack());
    
    machine->Run();

    
}



//----------------------------------------------------------------------
// do_ThreadCreate
//      Create a new Thread.
//----------------------------------------------------------------------
int do_ThreadCreate(int f, int arg){
    int *args = (int*)malloc(2*sizeof(int));
    args[0] = f;
    args[1] = arg; 
    Thread *newThread = new Thread ("newThread");
    newThread->space = currentThread->space;

    newThread->Start(StartUserThread, args);

    return 0;
}


//----------------------------------------------------------------------
// do_ThreadExit
//      Exit a Thread.
//----------------------------------------------------------------------
void do_ThreadExit(void){
    currentThread->Finish();
}



#endif //CHANGED
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



#endif //CHANGED
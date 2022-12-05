#ifdef CHANGED

#include "new"
#include "pageprovider.h"
#include "machine.h"
#include "system.h"
#include <time.h>
#include <stdlib.h>


PageProvider::PageProvider(int n)
{
    numPages = n;
    physPageMap = new BitMap(n);
    accessPageMap = new Semaphore("Acces page map token", 1);
}

PageProvider::~PageProvider()
{
    delete accessPageMap;
    delete physPageMap;
}

int
PageProvider::GetEmptyPage()
{
    int page;
    accessPageMap->P();
    page = physPageMap->Find();
    memset(&machine->mainMemory[page*PageSize], 0, PageSize);
    accessPageMap->V();
    return page;
}

int
PageProvider::GetRandomEmptyPage()
{
    int r;
    srand(time(NULL));   // Initialization, should only be called once.
    accessPageMap->P();
    do{
        r = rand()%numPages;
    } while(physPageMap->Test(r));
    DEBUG('a', "CHOSE PHYS PAGE 0x%x\n", r);
    memset(&machine->mainMemory[r*PageSize], 0, PageSize);
    physPageMap->Mark(r);
    accessPageMap->V();
    return  r;
}


void
PageProvider::ReleasePage(int page)
{
    accessPageMap->P();
    physPageMap->Clear(page);
    accessPageMap->V();
}

uint
PageProvider::NumAvailablePage()
{
    int nb;
    accessPageMap->P();
    nb = physPageMap->NumClear();
    accessPageMap->V();
    return nb;
}

#endif
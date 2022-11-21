#ifdef CHANGED

#include "new"
#include "pageprovider.h"
#include <time.h>
#include <stdlib.h>


PageProvider::PageProvider(int n)
{
    numPages = n;
    physPageMap = new BitMap(n);

}

PageProvider::~PageProvider()
{
    delete physPageMap;
}

int
PageProvider::GetEmptyPage()
{
    return physPageMap->Find();
}

int
PageProvider::GetRandomEmptyPage()
{
    int r;
    srand(time(NULL));   // Initialization, should only be called once.
    do{
        r = rand()%numPages;
    } while(physPageMap->Test(r));
    DEBUG('a', "CHOSE PHYS PAGE 0x%x\n", r);
    physPageMap->Mark(r);
    return  r;
}


void
PageProvider::ReleasePage(int page)
{
    physPageMap->Clear(page);
}

int
PageProvider::NumAvailablePage()
{
    return physPageMap->NumClear();
}

#endif
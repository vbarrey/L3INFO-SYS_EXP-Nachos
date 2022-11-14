#ifdef CHANGED

#include "new"
#include "pageprovider.h"


PageProvider::PageProvider(int numPage)
{

    physPageMap = new BitMap(numPage);

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
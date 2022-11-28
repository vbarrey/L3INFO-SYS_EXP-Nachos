#ifdef CHANGED

#include "filesys.h"
#include "bitmap.h"
#include "synch.h"

    class PageProvider:public dontcopythis
{
  public:
    PageProvider (int numPage); // Create a page provider

    ~PageProvider ();              // De-allocate a page provider

    public:
        int GetEmptyPage(void);

        int GetRandomEmptyPage(void);

        void ReleasePage(int page);

        int NumAvailablePage(void);

    private:
        BitMap *physPageMap;
        Semaphore *accessPageMap;
        int numPages;
};
#endif
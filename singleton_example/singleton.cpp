#include <cassert>

template <typename T> class Singleton
{
    static T* ms_Singleton;

public:
    Singleton()
    {
        assert( !ms_Singleton );
        int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
        ms_Singleton = (T*)((int)this + offset);
    }
   ~Singleton()
        {  assert( ms_Singleton );  ms_Singleton = 0;  }
    static T& getSingleton()
        {  assert( ms_Singleton );  return ( *ms_Singleton );  }
    static T* getInstance()
        {  return ( ms_Singleton );  }
};

template <typename T> T* Singleton <T>::ms_Singleton = 0;
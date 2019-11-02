#if defined(_MSC_VER)
//  Microsoft
    #ifdef MAKEDLL
    #  define EXPORT __declspec(dllexport)
    #else
    #  define EXPORT __declspec(dllimport)
    #endif
#elif defined(__GNUC__)
//  GCC
    #ifdef MAKEDLL
    #  define EXPORT __attribute__((visibility("default")))
    #else
    #  define EXPORT
    #endif
#else
    //  do nothing and hope for the best?
    #define EXPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif
#include <atomic>
  #define FILE_LEVEL_KEEPS_COLUMN 1

extern "C" {
    #include "body.h"
  #ifdef FEATURE
    #include "feature.h"
  #endif

    static void handler(int value)
    {
        #include "inside_function.inc"
        use(value);
    }
}

namespace ns {
    #include "in_namespace.h"
}

#ifdef GUARDED
extern "C" {
  #include "guarded_body.h"
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
    #if A
        #define X (1)
    #else
        #define X (0)
    #endif
int guarded_header_decl(void);
#ifdef __cplusplus
}
#endif

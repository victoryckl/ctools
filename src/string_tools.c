#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#define strncasecmp strnicmp
#endif

const char* strstri(const char* str, const char* subStr)
{
    int len = strlen(subStr);
    if(len == 0)
    {
        return NULL;
    }

    while(*str)
    {
        if(strncasecmp(str, subStr, len) == 0)
        {
            return str;
        }
        ++str;
    }
    return NULL;
}

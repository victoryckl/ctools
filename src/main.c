#include <stdio.h>
#include <stdlib.h>


const char* strstri(const char* str, const char* subStr);

int main(int argc, char** argv)
{
    char * str = "path_to_file_name.mP4";
    char * subStr = ".mp4";
    if (strstri(str, subStr) != NULL) {
        printf("%s is in %s\n", subStr, str);
    } else {
        printf("%s is not in %s\n", subStr, str);
    }
    return 0;
}


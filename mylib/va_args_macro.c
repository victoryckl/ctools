#ifndef WIN32

#define myprint_1(fmt, ...)     printf(fmt, __VA_ARGS__)
#define myprint_2(fmt, ...)     printf(fmt, ##__VA_ARGS__)
#define myprint_3(fmt, arg...)  printf(fmt, ##arg)
 
int va_args_macro_test(void)
{
    myprint_1("%s, %s, %d\r\n", __FILE__, __FUNCTION__, __LINE__);
    myprint_2("%s, %s, %d\r\n", __FILE__, __FUNCTION__, __LINE__);
    myprint_3("%s, %s, %d\r\n", __FILE__, __FUNCTION__, __LINE__);
    return 0;
}

#endif
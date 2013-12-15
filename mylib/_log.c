#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "_log.h"

#define BUFFER_SIZE (1024 * 1)
static char db_buffer[BUFFER_SIZE];

#ifdef WIN32

#	define P_TYPE(action) action

#	define vsnprintf _vsnprintf

#else // #ifdef WIN32

#	define P_TYPE(action)

#endif //#ifdef WIN32

#define db_print(__tag, __p, __format) \
do { \
	int n = 0; \
	va_list args; \
	va_start(args, __format); \
	vsnprintf(db_buffer, BUFFER_SIZE - 1, __format, args); \
	db_buffer[BUFFER_SIZE - 1] = 0; \
	P_TYPE(__p(__tag));\
	n = __p(db_buffer); \
	va_end(args); \
	return n; \
} while (0)

int log_d(const char * format, ...)
{
	db_print("debug: ", LOGD, format);
//	return 0;
}

int log_i(const char * format, ...)
{
	db_print("info : ", LOGI, format);
}

int log_w(const char * format, ...)
{
	db_print("warn : ", LOGW, format);
}

int log_e(const char * format, ...)
{
	db_print("error: ", LOGE, format);
}

int log_v(const char * format, ...)
{
	db_print("verbose: ", LOGV, format);
}

const LOG log = 
{
	log_d,
	log_i,
	log_w,
	log_e,
	log_v,
};

//////////////////////////////////////////////////////////////////////////
//≤‚ ‘≥Ã–Ú
void testLog(void)
{
	log.d("ddddddd = %d\n", __LINE__);
	log.i("iiiiiii = %d\n", __LINE__);
	log.w("wwwwwww = %d\n", __LINE__);
	log.e("eeeeeee = %d\n", __LINE__);
	log.v("vvvvvvv = %d\n", __LINE__);
}
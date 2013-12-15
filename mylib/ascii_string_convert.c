/********************************************************************
	created:	2012/02/09
	filename: 	ascii_string_convert.c
	author:		
	
	purpose:	
*********************************************************************/

//-------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//输入："A23B45C32..."，一组规则的ascii码字串，每段一个字母两个数字
//字串的长度不定，有可能第一次为"A23B"，第二次为"45C32"
//输出：打印即可，A-->23，B-->45...

void convert_string(const char * ascii_string)
{
	static char ch1 = 0, ch2 = 0;//保存上次没有输出的
	const char * p;
	int len = 0;
	int i;
	do 
	{
		if (NULL == ascii_string) {
			printf("ascii_string is null!\n");
			break;
		}

		len = strlen(ascii_string);
		if (len <= 0) {
			printf("the length of string is zore!\n");
			break;
		}

		if (ch1) {
			if (isalpha(ch1) && isdigit(ch2)) {
				printf("%c->%c%c, ", ch1, ch2, ascii_string[0]);
				ascii_string++;
			} else if (isalpha(ch1)) {
				printf("%c->%c%c, ", ch1, ascii_string[0], ascii_string[1]);
				ascii_string+=2;
			}
			ch1 = 0;
			ch2 = 0;
		}

		len = strlen(ascii_string);
		p = ascii_string;
		for (i=0; i<len; i+=3) {
			if (isalpha(p[i]) && isdigit(p[i+1]) && isdigit(p[i+2])) {
				printf("%c->%c%c, ", p[i], p[i+1], p[i+2]);
			} else{
				ch1 = p[i];
				ch2 = p[i+1];
				break;
			}
		}

	} while (0);
}

#define TEST_CODE

#ifdef TEST_CODE

void test_string_convert(void)
{
	convert_string("A23B45C32");
	printf("\n-----------------------------\n");
	convert_string("A23B");
	convert_string("45C32");
	printf("\n-----------------------------\n");
	convert_string("A23B4");
	convert_string("5C32");
	printf("\n-----------------------------\n");
	convert_string("A23");
	convert_string("B45C32");
	printf("\n-----------------------------\n");
	convert_string("A23B45C");
	convert_string("32");
	printf("\n-----------------------------\n");
	convert_string("A23B45C3");
	convert_string("2");
	printf("\n-----------------------------\n");
	convert_string("A");
	convert_string("23B45C32");
	printf("\n-----------------------------\n");
	convert_string("A2");
	convert_string("3B45C32");
	printf("\n-----------------------------\n");
}
#endif //#ifdef TEST_CODE



//-------------------------------------------------------------------

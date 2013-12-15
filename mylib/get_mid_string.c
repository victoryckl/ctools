#include <stdlib.h>
#include <string.h>
/*
in - �����ִ�
/2011-12-03-08-42-03-733/module1_Unit1.swf
����/favicon.ico

out - ����ִ�
2011-12-03-08-42-03-73
��
�մ�

����ֵ
2011-12-03-08-42-03-73
��
NULL

*/
char * getMiddleString(const char * in, char * out)
{
	char * ret = NULL;
	char * t;

	if (in && out) {
		out[0] = 0;
		out[1] = 0;

		//Ҫ��������'/'���ִ�����������'/'������һ���ַ�
		if (in[0] == '/' && 
			(t = strchr(in + 2, '/')))
		{
			memcpy(out, in + 1, t - in - 1);
			out[t - in - 1] = 0;
			ret = out;
		}
	}

	return ret; 
}

//����
#include <stdio.h>
void testGetString(void)
{
	char * ret = NULL;
	char * in;
	char out[256];

	in = "/2011-12-03-08-42-03-733/module1_Unit1.swf";
	printf("in : %s\n", in);
	ret = getMiddleString(in, out);
	if (ret) {
		printf("out : %s\n", ret);
	} else {
		printf("out : get string failed!\n");
	}
	
	in = "/favicon.ico";
	printf("in : %s\n", in);
	ret = getMiddleString(in, out);
	if (ret) {
		printf("out : %s\n", ret);
	} else {
		printf("out : get string failed!\n");
	}
}
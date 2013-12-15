#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node * nodeptr;
typedef struct node {
	char * word;
	int count;
	nodeptr next;
} node;

#define NHASH 29989
#define MULT 31
static nodeptr bin[NHASH];

static unsigned int hash(char * p)
{
	unsigned int h = 0;
	for (; *p; p++)
		h = MULT * h + *p;
	return h % NHASH;
}

static void incword(char *s)
{
	nodeptr p;
	unsigned int h = hash(s);
	for (p = bin[h]; p != NULL; p = p->next)
	{
		if (strcmp(s, p->word) == 0)
		{
			(p->count)++;
			return;
		}
	}
	p = malloc(sizeof(node));
	p->count = 1;
	p->word = strdup(s);
	p->next = bin[h];
	bin[h] = p;
}

void testWordSort2(void)
{
	int i;
	char buf[50];
	nodeptr p;

	for (i = 0; i < NHASH; i++)
		bin[i] = NULL;
	while(gets(buf))
	{
		if ('\n' == buf[0])
		{
			break;
		}
		incword(buf);
	}
	for (i = 0; i < NHASH; i++)
		for (p = bin[i]; p != NULL; p = p->next)
			printf("%s, %d\n", p->word, p->count);
}
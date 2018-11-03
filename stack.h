#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

typedef struct tree
{
	int d;
	struct tree *l;
	struct tree *r;
}TREE;


typedef struct stack
{
	int top;
	TREE data[1024];
	
	void (*init)(struct stack *s);
	bool (*is_empty)(struct stack *s);
	int  (*push)(struct stack *s, TREE d);	
	TREE  (*pop)(struct stack *s);
}STACK;

void Init(STACK *s)
{
	if(!s)
		return;

	s->top = -1;
}

bool Is_empty(STACK *s)
{
	if(!s)
		return true;

	return (s->top < 0) ? true : false;
}

int Push(STACK *s, TREE d)
{
	if(!s)
		return -1;
	
	s->top++;
	s->data[s->top] = d;

	return 0;
}

TREE Pop(STACK *s)
{
	if(!s->is_empty(s))
		return s->data[s->top--];
}


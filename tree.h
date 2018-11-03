#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

TREE *make_tree(int *pre_start, int *pre_stop,
				int *in_start, int *in_stop)
{
	int root_v = pre_start[0];
	TREE *root = malloc(sizeof(TREE));
	root->d = root_v;
	root->l = root->r = NULL;

	if(pre_start == pre_stop)
	{
		if(in_start==in_stop && *pre_start==*in_start)
			return root;
		else
			return NULL; //exception
	}
	
	//find root node from the in-order traverse array
	int *p = in_start;
	while(p<in_stop && *p!=root_v) 
		p++;
	//check if found or not
	if(p==in_stop && *p!=root_v)
		return NULL; //excption

	int len = p - in_start;
	int *pivot = pre_start+len;
	if(len > 0)
	{
		//make left tree
		root->l = make_tree(pre_start+1, pivot,
							in_start, p-1);

	}

	if(len < pre_stop-pre_start)
	{
		//make right tree
		root->r = make_tree(pivot+1,pre_stop,
							p+1, in_stop);
	}
	
	return root;	
}
 
TREE *make_tree_api(int *pre_d, int *in_d, int n)
{
	if(!pre_d || !in_d || n<1)
		return NULL;

    return make_tree(pre_d, pre_d+n-1, in_d, in_d+n-1);	
}

void pre_traverse(TREE* root)
{
	if(!root)
		return;

	printf("%d\n", root->d);

	pre_traverse(root->l);
	pre_traverse(root->r);
}

void pre_traverse_no_recursive(TREE *root)
{
	STACK s = {
		.init = Init,
		.is_empty = Is_empty,
		.push = Push,
		.pop = Pop,	
	};

	s.init(&s);
	if(root)
	{
		s.push(&s, *root);
		while(!s.is_empty(&s))
		{	
			TREE t = s.pop(&s);
			printf("%d\n", t.d);
			
			if(t.r)
				s.push(&s, *(t.r));
			if(t.l)
				s.push(&s, *(t.l));
		}
	}

}








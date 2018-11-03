#include "tree.h"

int main(int argc, char *argv[])
{
	STACK s = {
		.init = Init,
		.is_empty = Is_empty,
		.push = Push,
		.pop = Pop,	
	};
/*
	s.init(&s);
	s.push(&s, 1);
	s.push(&s, 2);
	s.push(&s, 3);
	s.push(&s, 4);
*/
	int pre[] = {1,2,4,7,3,5,6,8};
	int in[] = {4,7,2,1,5,3,8,6};
	int len = sizeof(pre)/sizeof(pre[0]);

	TREE *root = make_tree_api(pre, in, len);
	pre_traverse(root);

	pre_traverse_no_recursive(root);
	return 0;
}


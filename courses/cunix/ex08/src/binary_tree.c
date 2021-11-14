#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_tree.h"

node_t *allocnode()
{
	node_t *node =  malloc(sizeof(node_t));

	if (!node)
	{
        	exit(1);
    	}
	else 
	{
		node->left = NULL;
    		node->right = NULL;
		node->key = NULL;
    		node->data = NULL;
	}

    	return node;
}

node_t *insert(node_t *root, char *key, void *data)
{

	if (!root)
	{
		node_t *root = allocnode();
		root->left = NULL;
		root->right = NULL;
		root->key = key;
		root->data = data;
		return root;
	}

	if (strcmp(data, root->data) >= 0)
	{
		root->left = insert(root->left,key,data);
	}
	else
	{
		root->right = insert(root->right,key,data);
	}

	return root;


}

void print_node(node_t *node)
{
	if (node)
    	{
    		printf("%s %s\n", node->key, (char*)node->data);

	
	}
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
	if (!node)
    	{
        	return;
    	}

    	visit_tree(node->left, fp);
    	fp(node); visit_tree(node->right, fp);
}

void destroy_tree(node_t *node, void (fdestroy)(node_t *root))
{
	if (node)
	{
		destroy_tree(node->left, fdestroy);
		destroy_tree(node->right, fdestroy);
		fdestroy(node);
		free(node);
	}
	else 
	{
		return;
	}
}

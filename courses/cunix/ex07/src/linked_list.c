#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>

node_t *createNode(void *data, node_t *next)
{
	node_t *node = malloc(sizeof(node_t));

   	if (!node)
    	{	
        	exit(1);
    	}

    	node->data = data;
    	node->next = next;

    	return node;
}

node_t *list_create(void *data)
{
    	return createNode(data, NULL);
}

void list_destroy(node_t **head, void(*fp)(void *data))
{
    	node_t *next;
    	node_t *temp = *head;
    	*head = NULL;

    	while (temp != NULL)
    	{
        	fp(temp->data);
        	next = temp->next;
        	free(temp);
        	temp = next;
    	}
}

void list_push(node_t *head, void *data)
{
	if (!head)
    	{
        	return;
    	}

    	node_t *current = head;
    	while (current->next)
    	{
        	current = current->next;
    	}

    	current->next = createNode(data, NULL);
}

void *list_shift(node_t **head)
{
    	if (!head || !(*head))
    	{
        	return NULL;
    	}

    	node_t *old_head = *head;
    	*head = (*head)->next;
	void *data = old_head->data;
    	free(old_head);
    	return data;
}

void list_unshift(node_t **head, void *data)
{
    	if (!head || !(*head)) return;

    	*head = createNode(data, *head);
}

void *list_remove(node_t **head, int pos)
{
    	void *data;
    	if ((*head)->next == NULL)
    	{
        	data = (*head)->data;
        	free(*head);
        	return data;
    	}

    	int i = 0;
    	node_t *temp = *head;

    	while (i != pos - 1)
    	{
        	temp = temp->next;
        	i++;
    	}

    	node_t *nextNode = temp->next->next;
    	data = temp->next->data;
   	free(temp->next);
	temp->next = nextNode;

    	return data;
}

void *list_pop(node_t **head)
{
    	void *data;
    	if ((*head)->next == NULL)
    	{
       		data = (*head)->data;
        	free(*head);
        	return data;
    	}

    	node_t *temp = *head;

    	while (temp->next->next != NULL)
    	{
        	temp = temp->next;
    	}

    	data = temp->next->data;
	free(temp->next);
	temp->next = NULL;

	return data;
}

void list_print(node_t *head)
{
    	while (head != NULL)
    	{
        	printf("%s\n", (char *)(head->data));
        	head = head->next;
    	}
}


void list_visitor(node_t *head, void (*fp)(void *data))
{
    	node_t *current = head;
    	while (current)
    	{
        	fp(current->data);
        	current = current->next;
    	}
}

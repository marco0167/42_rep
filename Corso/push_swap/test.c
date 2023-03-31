#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int a;
	struct s_node *next;
} t_node;

typedef struct s_list {
	t_node *head;
} t_list;

void add_node_back(t_node **head, int num)
{
	t_node *curr;
	t_node *new;

	curr = (*head);
	new = malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->a = num;
	new->next = NULL;
	if ((*head) == NULL)
	{
		(*head) = new;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

void print_list(t_node **head)
{
	t_node *curr;

	curr = (*head);
	while(curr != NULL)
	{
		printf("curr val: %d\n", curr->a);
		curr =  curr->next;
	}
}

int main(void)
{
	t_list list;

	list.head = NULL;
	write(1, "a\n", 2);
	add_node_back(&list.head, 1);
	write(1, "b\n", 2);
	add_node_back(&list.head, 2);
	add_node_back(&list.head, 3);
	add_node_back(&list.head, 4);
	print_list(&list.head);
}

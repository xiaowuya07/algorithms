#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node * p_next;
}node, *p_node;

p_node list_init() {
	p_node p_next = (p_node)malloc(sizeof(node));
	if (p_next == NULL) {
		printf("list_init faile, p_next is NULL\n");
		exit(1);
	}
	p_next->p_next = NULL;

	return p_next;
}

bool list_insert(p_node list, int num, int pos) {
	p_node p = list;
	for (int i = 0; i < pos; ++i) {
		if (p->p_next == NULL) {
			printf("position is out of list size!\n");
			return false;
		}
		p = p->p_next;
	}
	p_node node = (p_node)malloc(sizeof(node));
	node->data = num;
	p_node val = p->p_next;
	p->p_next = node;
	node->p_next = val;

	return true;
}

bool list_delete(p_node list, int pos) {
	p_node p = list;
	for (int i = 0; i < pos - 1; ++i) {
		if (p->p_next == NULL) {
			printf("position is out of list size!\n");
			return false;
		}
		p = p->p_next;
	}
	p_node val = p->p_next;
	p->p_next = p->p_next->p_next;

	free(val);
	return true;
}

void print_list(p_node list) {
	while (list->p_next != NULL) {
		printf(" %d ", list->p_next->data);
		list = list->p_next;
	}
	printf("\n");
}

int main(void) {

	p_node p_list = list_init();

	for (int i = 0; i < 10; ++i) {
		list_insert(p_list, i + 1, i);
	}
	print_list(p_list);

	list_delete(p_list, 4);
	print_list(p_list);


	return 0;
}
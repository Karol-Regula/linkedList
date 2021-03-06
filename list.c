#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//# include "list.c" ?
struct node {int i; struct node *next;};

void print_list(struct node *);
struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);

int main(){
    struct node *list = (struct node *) malloc(sizeof(*list));
    list->i = 55;
    list->next = 0;
    print_list(list);
    printf("\n");
    list = insert_front(list, 10);
    list = insert_front(list, 12);
    print_list(list);
    free_list(list);
    print_list(list);
    list->i = 99;
    list->next = 0;
    print_list(list);
}



void print_list(struct node * current){
    int k = 0;
    while (current->next){
	printf("List[%d] = %d\n", k, current->i);
	k++;
	current = current->next;
    }
    printf("List[%d] = %d\n", k, current->i);
}

struct node * insert_front(struct node * old, int in){
    struct node *new = (struct node *) malloc(sizeof(*new));
    new->i = in;
    new->next = old;
    return new;
}

struct node * free_list(struct node * current){
    struct node *hold;
    while(current){
	hold = current->next;
	free(current);
	current = hold;
    }
    return current;
}

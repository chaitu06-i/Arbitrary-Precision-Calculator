#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;

/* Doubly linked list structure */
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
} Dlist;

/* Prototypes */
int validate_CLA(int argc, char *argv[], char *operator);
int convert_to_list(Dlist **head, Dlist **tail, char *num);
int find_bigger(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
void delete_list(Dlist **head);
int insert_at_first(Dlist **head, Dlist **tail, data_t data);
int insert_at_last(Dlist **head, Dlist **tail, data_t data);
int compare_lists(Dlist *head1, Dlist *head2);
void print_list(Dlist *head, int sign);

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, Dlist **headRem, Dlist **tailRem);

#endif
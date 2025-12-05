/*******************************************************************************************************************************************************************
*Name : G. CHAITANYA GOWD
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
    int borrow = 0;
    int diff = 0;
    int op = find_bigger(head1, tail1, head2, tail2);

    Dlist *temp1 = NULL;
    Dlist *temp2 = NULL;

    /* Decide which number is bigger */
    if (op == 2)
    {
        temp1 = *tail2;  // bigger number
        temp2 = *tail1;
    }
    else
    {
        temp1 = *tail1;  // bigger number
        temp2 = *tail2;
    }

    /* Run a loop until both pointers reach NULL */
    while (temp1 != NULL || temp2 != NULL)
    {
        int num1 = 0, num2 = 0;

        if (temp1 != NULL)
		{
			num1 = temp1->data;
		}
        if (temp2 != NULL)
		{
			num2 = temp2->data;
		}

        /* Check borrow flag */
        if (borrow == 1)
        {
            num1 = num1 - 1;
            borrow = 0;
        }

        /* Check possibility for borrow */
        if (num1 < num2)
        {
            num1 = num1 + 10;
            borrow = 1;
        }

        /* Perform subtraction */
        diff = num1 - num2;

        /* Insert result at first of result list */
        insert_at_first(headR, tailR, diff);

        /* Traverse to previous node */
        if (temp1 != NULL)
		{
			temp1 = temp1->prev;
		}
        if (temp2 != NULL)
		{
			temp2 = temp2->prev;
		}
    }

    /* Remove leading zeros from result */
    while (*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *del = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(del);
    }

    return SUCCESS;
}

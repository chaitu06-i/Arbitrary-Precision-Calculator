/*******************************************************************************************************************************************************************
*Name : G. CHAITANYA GOWD
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	/* Step 1: Declare t1 and t2 with tail1 and tail2 */
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;

    /* Step 2: Declare carry with zero */
    int carry = 0;
    int sum, res;

    /* Step 3: Run loop till both t1 and t2 reach NULL */
    while (t1 != NULL || t2 != NULL || carry != 0)
    {
        int num1 = 0, num2 = 0;

        /* Check if t1 is not NULL */
        if (t1 != NULL)
        {
            num1 = t1->data;
        }

        /* Check if t2 is not NULL */
        if (t2 != NULL)
        {
            num2 = t2->data;
        }

        /* Step 4: Add t1->data + t2->data + carry */
        sum = num1 + num2 + carry;

        /* Step 5: Get remainder */
        res = sum % 10;

        /* Step 6: Update carry using if-else */
        if (sum >= 10)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        /* Step 7: Insert remainder at first of result list */
        insert_at_first(headR, tailR, res);

        /* Step 8: Traverse to previous node */
        if (t1 != NULL)
        {
            t1 = t1->prev;
        }
        if (t2 != NULL)
        {
            t2 = t2->prev;
        }
    }

    return SUCCESS;
}
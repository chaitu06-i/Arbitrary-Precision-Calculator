/*******************************************************************************************************************************************************************
*Name : G. CHAITANYA GOWD
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, Dlist **headRem, Dlist **tailRem)
{
	/* Definition goes here */
    /* Step 0: Check divide by zero */
    if (*head2 == NULL)
    {
        printf("Error: Division by zero not allowed.\n");
        return FAILURE;
    }

    // If divisor is 0 (special case check)
    Dlist *zero = *head2;
    int flag = 0;
    while (zero)
    {
        if (zero->data != 0)
        {
            flag = 1;
            break;
        }
        zero = zero->next;
    }
    if (flag == 0)
    {
        printf("Error: Division by zero not allowed.\n");
        return FAILURE;
    }

    /* Step 1: Initialize variables */
    Dlist *temp1 = *head1;
    Dlist *h3 = NULL, *t3 = NULL;
    // Dlist *hRem = NULL, *tRem = NULL;
    int count = 0;

    /* Step 2: Run loop till t1 reaches NULL (temp1) */
    while (temp1 != NULL)
    {
        /* Step 3: insert at last from temp1 to h3 */
        insert_at_last(&h3, &t3, temp1->data);

        /* Remove leading zeros in h3 if needed */
        while (h3 && h3->data == 0 && h3->next != NULL)
        {
            Dlist *del = h3;
            h3 = h3->next;
            h3->prev = NULL;
            free(del);
        }

        /* Step 4: Run loop to compare(head3, head2) = true and subtract */
        count = 0;
        while (compare_lists(h3, *head2) >= 0)
        {
            subtraction(&h3, &t3, head2, tail2, headRem, tailRem);
            delete_list(&h3);

            h3 = *headRem;
            t3 = *tailRem;
            *headRem = NULL;
            *tailRem = NULL;

            count++;
        }

        /* Step 5: Insert count to Result list */
        insert_at_last(headR, tailR, count);

        /* Step 6: Traverse temp1 */
        temp1 = temp1->next;
    }

    /* Step 7: Remove leading zeros in result */
    while (*headR && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *del = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(del);
    }

	/* Step 8: The remainder is h3 (could be NULL or zero). Return it via headRem/tailRem */
    *headRem = h3;
    *tailRem = t3;

    /* If no remainder nodes (NULL), ensure returned pointers are NULL */
    if (*headRem == NULL)
    {
        *tailRem = NULL;
    }
	
    return SUCCESS;
}
/*******************************************************************************************************************************************************************
*Name : G. CHAITANYA GOWD
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int carry = 0, product = 0;

    /* Result lists */
    Dlist *hR1 = NULL, *tR1 = NULL;
    Dlist *hR2 = NULL, *tR2 = NULL;
    Dlist *hR3 = NULL, *tR3 = NULL;

    int zero_count = 0;  // used to insert trailing zeros for place value

    /* Run loop till temp2 reaches NULL (outer loop) */
    while (temp2 != NULL)
    {
        /* Step 1: insert zeros to R1 based on position of temp2 */
        for (int i = 0; i < zero_count; i++)
        {
            insert_at_last(&hR1, &tR1, 0);
        }

        /* Step 2: Reset carry and temp1 pointer */
        carry = 0;
        temp1 = *tail1;

        /* Step 3: Inner loop for multiplication with temp1 */
        while (temp1 != NULL)
        {
            product = (temp1->data * temp2->data) + carry;

            int rem = product % 10;
            carry = product / 10;

            insert_at_first(&hR1, &tR1, rem);

            temp1 = temp1->prev;
        }

        /* Step 4: If carry remains after multiplication */
        if (carry != 0)
        {
            insert_at_first(&hR1, &tR1, carry);
        }

        /* Step 5: If first time, copy R1 → R2 */
        if (hR2 == NULL)
        {
            Dlist *p = hR1;
            while (p != NULL)
            {
                insert_at_last(&hR2, &tR2, p->data);
                p = p->next;
            }
        }
        else
        {
            /* Step 6: Add R1 + R2 → R3 */
            addition(&hR1, &tR1, &hR2, &tR2, &hR3, &tR3);

            /* Step 7: Delete R1 and R2 */
            delete_list(&hR1);
            delete_list(&hR2);

            /* Step 8: Assign R3 to R2 and reset R3 */
            hR2 = hR3;
            tR2 = tR3;
            hR3 = NULL;
            tR3 = NULL;
        }

        /* Step 9: Delete R1 for next iteration */
        delete_list(&hR1);
        hR1 = tR1 = NULL;

        /* Step 10: Traverse to previous node in temp2 */
        temp2 = temp2->prev;
        zero_count++;
    }

    /* Step 11: Final result stored in R2 */
    *headR = hR2;
    *tailR = tR2;

    return SUCCESS;
}


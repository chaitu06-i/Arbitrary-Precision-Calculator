/**************************************************************************************************************************************************************
 * Name : G. CHAITANYA GOWD
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/

#include "apc.h"

int main(int argc, char *argv[])
{
    /* Declare the pointers */
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;
    Dlist *headR = NULL;
    Dlist *tailR = NULL;
    Dlist *headRem = NULL;
    Dlist *tailRem = NULL;

    char operator;

    int sign1 = 1;  // +ve by default
    int sign2 = 1;
    int signR = 1;

    /* Validate command line arguments */
    if (validate_CLA(argc, argv, &operator) == FAILURE)
    {
        printf("Usage: ./calc <num1> <operator> <num2>\n");
        return FAILURE;
    }

    /* Detect sign and skip for conversion */
    char *num1_str = argv[1];
    char *num2_str = argv[3];

    if (num1_str[0] == '-')
    {
        sign1 = -1;
        num1_str++;
    }
    else if (num1_str[0] == '+')
    {
        num1_str++;
    }

    if (num2_str[0] == '-')
    {
        sign2 = -1;
        num2_str++;
    }
    else if (num2_str[0] == '+')
    {
        num2_str++;
    }

    /* Convert numbers to list */
    convert_to_list(&head1, &tail1, num1_str);
    convert_to_list(&head2, &tail2, num2_str);

    printf("Num1: ");
    print_list(head1, sign1);
    printf("\nNum2: ");
    print_list(head2, sign2);
    printf("\n");

    switch (operator)
    {
    case '+':
        /* (+A) + (+B) = +(A+B)  */
        /* (-A) + (-B) = -(A+B)  */
        /* (+A) + (-B) = A - B  */
        /* (-A) + (+B) = B - A  */
        if (sign1 == sign2)
        {
            addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            signR = sign1;
        }
        else
        {
            int bigger = find_bigger(&head1, &tail1, &head2, &tail2);
            if (bigger == 1)
            {
                subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                signR = sign1;
            }
            else if (bigger == 2)
            {
                subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                signR = sign2;
            }
            else
            {
                insert_at_first(&headR, &tailR, 0);
                signR = 1;
            }
        }
        printf("Result: ");
        print_list(headR, signR);
        printf("\n");
        break;

    case '-':
        /* A - B  => A + (-B) */
        sign2 *= -1;
        if (sign1 == sign2)
        {
            addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            signR = sign1;
        }
        else
        {
            int bigger = find_bigger(&head1, &tail1, &head2, &tail2);
            if (bigger == 1)
            {
                subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                signR = sign1;
            }
            else if (bigger == 2)
            {
                subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                signR = sign2;
            }
            else
            {
                insert_at_first(&headR, &tailR, 0);
                signR = 1;
            }
        }
        printf("Result: ");
        print_list(headR, signR);
        printf("\n");
        break;

    case 'x':
        multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        /* Sign of result = sign1 * sign2 */
        signR = sign1 * sign2;
        printf("Result: ");
        print_list(headR, signR);
        printf("\n");
        break;

    case '/':
        /* Division by zero check is inside division() */
        division(&head1, &tail1, &head2, &tail2, &headR, &tailR, &headRem, &tailRem);
        signR = sign1 * sign2;
        printf("Quotient: ");
        print_list(headR, signR);
        printf("\n");
        printf("Remainder: ");
        print_list(headRem, sign1);
        printf("\n");
        break;

    default:
        printf("Invalid operator.\n");
    }

    return 0;
}
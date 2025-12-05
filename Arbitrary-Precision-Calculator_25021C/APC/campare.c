/*******************************************************************************************************************************************************************
*Name : G. CHAITANYA GOWD
*Description		: This is Validation Part
*******************************************************************************************************************************************************************/#include "apc.h"

/* Validates CLA for correct number of arguments, operator, and number format. */
int validate_CLA(int argc, char *argv[], char *operator)
{
    if (argc != 4)
    {
        printf("Error: Invalid number of arguments.\n");
        return FAILURE;
    }

    /* Check if operator is valid */
    if (strlen(argv[2]) != 1 || (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/') )
    {
        printf("Error: Invalid operator. Use + - x /\n");
        return FAILURE;
    }
    *operator = argv[2][0];

    /* Check if numbers are valid digits (allow leading +/- sign) */
    for (int i = (argv[1][0] == '-' || argv[1][0] == '+') ? 1 : 0; argv[1][i]; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Error: First number contains invalid characters.\n");
            return FAILURE;
        }
    }

    for (int i = (argv[3][0] == '-' || argv[3][0] == '+') ? 1 : 0; argv[3][i]; i++)
    {
        if (!isdigit(argv[3][i]))
        {
            printf("Error: Second number contains invalid characters.\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}

/* Converts a numeric string into a DLL storing each digit in a node. */
int convert_to_list(Dlist **head, Dlist **tail, char *num)
{
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (insert_at_last(head, tail, num[i] - '0') == FAILURE)
        {
            printf("Error: Memory allocation failed.\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

int insert_at_last(Dlist **head, Dlist **tail, data_t data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
       return FAILURE;
    }

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
    return SUCCESS;
}

int insert_at_first(Dlist **head, Dlist **tail, data_t data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
       return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head != NULL)
    {
       (*head)->prev = new;
    }
    else
    {
        *tail = new;
    }

    *head = new;
    return SUCCESS;
}

void print_list(Dlist *head, int sign)
{
    if (sign == -1 && !(head->data == 0 && head->next == NULL))
        printf("-");

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
}

/* Function to compare two DLL numbers and return which one is bigger */
int find_bigger(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    int count1 = 0, count2 = 0;
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;

    /* Count number of nodes in head1 */
    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    /* Count number of nodes in head2 */
    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    /* Check which number has more digits */
    if (count1 > count2)
    {
        return 1;  // op1 is bigger
    }
    else if (count2 > count1)
    {
        return 2;  // op2 is bigger
    }

    /* If both have same digits, compare node by node */
    temp1 = *head1;
    temp2 = *head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            return 1;
        }
        else if (temp2->data > temp1->data)
        {
            return 2;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    /* Both are equal */
    return 0;
}

int compare_lists(Dlist *head1, Dlist *head2)
{
    int count1 = 0, count2 = 0;
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    while (temp1)
    {
        count1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
    {
        return 1;
    }
    if (count2 > count1)
    {
        return -1;
    }

    temp1 = head1;
    temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data) return 1;
        if (temp1->data < temp2->data) return -1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 0;
}

/* Function to delete the entire list */
void delete_list(Dlist **head)
{
    Dlist *temp = *head;
    while (temp != NULL)
    {
        Dlist *del = temp;
        temp = temp->next;
        free(del);
    }
    *head = NULL;
}


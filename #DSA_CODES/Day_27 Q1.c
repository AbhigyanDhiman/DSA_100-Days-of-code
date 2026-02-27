#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int i, val;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

int length(struct node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct node *head1, struct node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);
    int diff, i;

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    if(len1 > len2)
    {
        diff = len1 - len2;
        for(i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    }
    else
    {
        diff = len2 - len1;
        for(i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data == ptr2->data)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    int n, m, result;

    scanf("%d", &n);
    struct node *head1 = create(n);

    scanf("%d", &m);
    struct node *head2 = create(m);

    result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}

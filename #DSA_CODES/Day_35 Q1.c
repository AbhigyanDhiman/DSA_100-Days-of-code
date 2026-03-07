#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    int front = 0, rear = -1;

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        rear++;
        arr[rear] = x;
    }

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

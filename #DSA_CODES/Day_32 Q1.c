#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int stack[1000];
    int top = -1;

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        if(top >= 0)
            top--;
    }

    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}

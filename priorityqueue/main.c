#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue is Full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    int i;

    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void SelectionSort(int A[], int n)
{
    int i, j, k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}
int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 11);
    enqueue(&q, 13);
    enqueue(&q, 7);
    enqueue(&q, 12);
    enqueue(&q, 16);
    enqueue(&q, 9);
    enqueue(&q, 24);
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 3);
    Display(q);
    printf("\n");
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    SelectionSort(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
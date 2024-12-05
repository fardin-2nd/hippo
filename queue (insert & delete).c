#include <stdio.h>
#define N 5

int queue[N]; // Queue array
int front = -1, rear = -1; // Initialize FRONT and REAR to NULL (-1)

void qinsert(int item)
{
    // Step 1: Check for overflow
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("Overflow: Cannot insert %d, the queue is full.\n", item);
        return;
    }

    // Step 2: Update FRONT and REAR
    if (front == -1) // Queue is empty
    {
        front = 0;
        rear = 0;
    }
    else if (rear == N - 1) // Wrap around REAR to 0
    {
        rear = 0;
    }
    else // Increment REAR normally
    {
        rear = rear + 1;
    }

    // Step 3: Insert ITEM into the queue
    queue[rear] = item;
    printf("Inserted %d into the queue. FRONT = %d, REAR = %d\n", item, front, rear);
}

void qdelete()
{
    int item;

    // Step 1: Check for underflow
    if (front == -1)
    {
        printf("Underflow: The queue is empty.\n");
        return;
    }

    // Step 2: Remove the item from the queue
    item = queue[front];
    printf("Deleted %d from the queue. FRONT = %d, REAR = %d\n", item, front, rear);

    // Step 3: Update FRONT
    if (front == rear) // Queue has only one element
    {
        front = -1; // Reset to empty state
        rear = -1;
    }
    else if (front == N - 1) // Wrap FRONT around to 0
    {
        front = 0;
    }
    else // Increment FRONT normally
    {
        front = front + 1;
    }
}

void display()
{
    if (front == -1)
    {
        printf("The queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (int i = front; i < N; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    qinsert(10);
    qinsert(20);
    qinsert(30);
    qinsert(40);
    qinsert(50);
    qinsert(60); // Attempt to insert into a full queue

    display();

    qdelete();
    qdelete();
    qdelete();

    display();

    qdelete();
    qdelete();
    qdelete(); // Attempt to delete from an empty queue

    return 0;
}


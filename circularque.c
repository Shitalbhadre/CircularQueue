#include <stdio.h>
#define MAX_SIZE 5  

struct Queue {
    int arr[MAX_SIZE];  
    int front;          
    int rear;           
};

void initQueue(struct Queue* q) {
    q->front = 0;  
    q->rear = 0;   
}

int isFull(struct Queue* q) {
   
    return q->rear == MAX_SIZE;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;  
}

void enqueue(struct Queue* q) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }

    int item;
    printf("Enter the data to enqueue: ");
    scanf("%d", &item);

  q->arr[q->rear] = item; 

    q->rear++; 

    printf("Inserted %d into the queue.\n", item);
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    int removedItem = q->arr[q->front];  
    printf("Removed %d from the queue.\n", removedItem);

    q->front++; 
    printf("Front is now at position %d\n", q->front);
}

void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);  
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);  

    int choice;
    do {
        
        printf("\n1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Print (Display)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        
        switch (choice) {
            case 1:
                enqueue(&q);  
                break;
            case 2:
                dequeue(&q);  
                break;
            case 3:
                printQueue(&q);  
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);  

    return 0;
}

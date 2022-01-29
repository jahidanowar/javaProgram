package DS;

public class Queue {
    private int[] queue;
    private int front;
    private int rear;
    private int size;

    public Queue(int size) {
        this.size = size;
        queue = new int[size];
        front = 0;
        rear = -1;
    }

    public void enqueue(int data) {
        if (isFull()) {
            System.out.println("Queue is full");
            return;
        }
        queue[++rear] = data;
    }

    public void dequeue() {
        // Check if queue is empty
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        // else dequeue an item
        if (front == size - 1) {
            front = 0;
            return;
        }
        front++;
    }

    public int peek() {
        // Check if queue is empty
        if (front == rear + 1) {
            System.out.println("Queue is empty");
            return -1;
        }
        // else return front item
        return queue[front];
    }

    public boolean isEmpty() {
        return front == rear + 1;
    }

    public boolean isFull() {
        return front == 0 && rear == size - 1;
    }

    public void printQueue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        int i = front;
        while (i != rear + 1) {
            System.out.print(queue[i] + " ");
            i++;
            if (i == size) {
                i = 0;
            }
        }
        System.out.println();
    }

}

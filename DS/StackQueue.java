package DS;

import java.util.Scanner;

public class StackQueue {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        // Create a menu for the user to choose from
        System.out.println("1. Stack");
        System.out.println("2. Queue");
        System.out.println("3. Exit");
        System.out.println("Enter your choice: ");
        int choice = sc.nextInt();

        // Switch case to perform the operation
        switch (choice) {
            case 1:
                Stack stack = new Stack(10);
                stack.push(10);
                stack.push(20);
                stack.push(30);
                stack.push(40);
                stack.push(50);
                stack.printStack();
                System.out.println("\nPopped an element\n");
                stack.pop();
                stack.printStack();
                break;
            case 2:
                Queue queue = new Queue(10);
                queue.enqueue(10);
                queue.enqueue(20);
                queue.enqueue(30);
                queue.enqueue(40);
                queue.enqueue(50);
                queue.printQueue();
                System.out.println("\nDequeued an element\n");
                queue.dequeue();
                queue.printQueue();
                break;
            case 3:
                sc.close();
                System.exit(0);
            default:
                System.out.println("Invalid choice");
                break;
        }

        // System.out.println("\n---Stack---\n");
        // Queue queue = new Queue(8);
        // queue.enqueue(10);
        // queue.enqueue(13);
        // queue.enqueue(16);
        // queue.enqueue(18);
        // queue.enqueue(19);
        // queue.enqueue(20);
        // queue.printQueue();
        // queue.dequeue();
        // queue.printQueue();
        // queue.dequeue();
        // queue.printQueue();
        // queue.dequeue();
        // queue.printQueue();
        // queue.dequeue();
        // queue.printQueue();

        // System.out.println("\n---Queue---\n");
        // Stack stack = new Stack(10);
        // stack.push(10);
        // stack.push(20);
        // stack.push(30);
        // stack.push(40);
        // stack.push(40);
        // stack.pop();
        // System.out.println("Poped");
        // stack.printStack();
        // stack.pop();
        // System.out.println("Poped");
        // stack.printStack();
        // stack.push(33);
        // System.out.println("Pushed 33");
        // stack.push(44);
        // System.out.println("Pushed 44");
        // stack.printStack();
    }
}

package valueStructures;

import java.util.Scanner;

public class LinkedList {

    private Node head;
    static class Node {
        Node next;
        int value;
        public Node(int value) {
            this.value = value;
            next = null;
        }
    }

    public void print() {
        Node node = head;
        while(node != null) {
            System.out.print(node.value + "\t");
            node = node.next;
        }
    }

    private void insertFront(int new_value) {
        Node newNode = new Node(new_value);
        if (head == null) {
            head = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }

    private void insertBetween(int new_value, Node prevNode, Node nextNode) {
        Node newNode = new Node(new_value);
        if (head == null || prevNode == null) {
            head = newNode;
            return;
        }
        prevNode.next = newNode;
        newNode.next = nextNode;
    }

    private void insertEnd(int new_value) {
        Node newNode = new Node(new_value);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.next = null;
    }

    private void search(int value) {
        Node key = head;
        if (head.value == value) {
            System.out.println("Key Node: " + head.value);
            return;
        }
        while(key.value != value) {
            key = key.next;
        }
        System.out.println("Search Node value is " + key.value);
    }

    public void delete(int value) {
        Node temp = head, prev = null;
        if (temp != null && temp.value == value) {
            head = temp.next;
            return;
        }
        while(temp != null && temp.value != value) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null) return;
        prev.next = temp.next;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        LinkedList list = new LinkedList();
        list.head = new Node(s.nextInt());
        Node secondNode = new Node(s.nextInt());
        Node thirdNode = new Node(s.nextInt());

        list.head.next = secondNode;
        secondNode.next = thirdNode;
        thirdNode.next = null;
        list.print();
        System.out.println();

        System.out.println("Insert value in Front...");
        list.insertFront(s.nextInt());
        list.print();
        System.out.println();

        System.out.println("Insert value in between...");
        list.insertBetween(s.nextInt(), secondNode, thirdNode);
        list.print();
        System.out.println();

        System.out.println("Insert value at end...");
        list.insertEnd(s.nextInt());
        list.print();
        System.out.println();

        System.out.println("Search  for a value...");
        list.search(s.nextInt());
        //list.print();
        System.out.println();

        System.out.println("Delete a Node...");
        list.delete(s.nextInt());
        list.print();
        System.out.println();
    }
}

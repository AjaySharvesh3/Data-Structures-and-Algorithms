package DataStructures;

import java.util.Scanner;

public class LinkedListt {

    private Node head;
    static class Node {
        Node next;
        int data;
        public Node(int data) {
            this.data = data;
            next = null;
        }
    }

    public void print() {
        Node node = head;
        while(node != null) {
            System.out.print(node.data + "\t");
            node = node.next;
        }
    }

    private void insertFront(int new_data) {
        Node newNode = new Node(new_data);
        if (head == null) {
            head = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }

    private void insertBetween(int new_data, Node prevNode, Node nextNode) {
        Node newNode = new Node(new_data);
        if (head == null || prevNode == null) {
            head = newNode;
            return;
        }
        prevNode.next = newNode;
        newNode.next = nextNode;
    }

    private void insertEnd(int new_data) {
        Node newNode = new Node(new_data);
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

    private void search(int data) {
        Node key = head;
        if (head.data == data) {
            System.out.println("The Key Node: " + head.data);
            return;
        }
        while(key.data != data) {
            key = key.next;
        }
        System.out.println("The Search Node Data is " + key.data);
    }

    public void delete(int data) {
        Node temp = head, prev = null;
        if (temp != null && temp.data == data) {
            head = temp.next;
            return;
        }
        while(temp != null && temp.data != data) {
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

        System.out.println("Insert the Data in Front...");
        list.insertFront(s.nextInt());
        list.print();
        System.out.println();

        System.out.println("Insert the Data in between...");
        list.insertBetween(s.nextInt(), secondNode, thirdNode);
        list.print();
        System.out.println();

        System.out.println("Insert the Data at end...");
        list.insertEnd(s.nextInt());
        list.print();
        System.out.println();

        System.out.println("Search Data...");
        list.search(s.nextInt());
        //list.print();
        System.out.println();

        System.out.println("Delete Node...");
        list.delete(s.nextInt());
        list.print();
        System.out.println();
    }
}

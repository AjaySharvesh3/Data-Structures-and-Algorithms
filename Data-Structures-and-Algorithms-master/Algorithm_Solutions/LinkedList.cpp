#include <iostream>
using namespace std;
class Node {
public:
    int key;
    Node *next;
};

class LinkedList {
private:
    Node *root = nullptr;
public:
    void insert(int key);   //function to insert
    void print();           //function to print
    bool search(int key);   //function to search--- returns true or false
    void Del(int key);      //function to delete (if given key is present)
};

void LinkedList::insert(int key) {
    if(!root) {
        root = new Node;
        root->key = key;
        root->next = nullptr;
    } else {
        Node* current = root;
        while(current->next)
            current = current->next;
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = nullptr;
        current->next = newNode;
    }
}

void LinkedList::print() {
    Node* current = root;
    while(current) {
        cout << current->key << endl;
        current = current->next;
    }
}

bool LinkedList::search(int key) {
    Node* current = root;
    while(current) {
        if(current->key == key)
            return true;
        current = current->next;
    }
    return false;

}

void LinkedList::Del(int key) {
    Node* current = root;
    Node* prev = nullptr;
    while(current){
        if(current->key==key){
            if(!prev){
                delete root;
                root = current->next;
            } else {
                prev->next = current->next;
                Node* toDel = current;
                delete toDel;
            }
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    //Driver function
    int n;
    LinkedList list;
    cout << "Enter no. to be inserted | enter 0 to quit : " << endl;
    cin >> n;
    while (n) {
        list.insert(n);
        cin >> n;
    }
    cout << "Printing Linked List " << endl;
    list.print();
    cout << "Enter elements to be deleted | enter 0 to stop " << endl;
    cin >> n;
    while (n) {
        list.Del(n);
        cin >> n;
    }
    cout << "Printing after deletion " << endl;
    list.print();
    cout << "Enter no. to search | 1 indicates present " << endl;
    cin >> n;
    cout << list.search(n) << endl;
    return 0;
}

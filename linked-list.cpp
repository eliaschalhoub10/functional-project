#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at head
    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node
    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Search for a node
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Traverse the list
    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 30000; i++) {
        list.insertHead(i);
    }
    /*
    auto start = high_resolution_clock::now();
    cout << list.search(5000) << endl;
    auto end = high_resolution_clock::now();
    cout << "Time taken for search: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
    */
    auto start = high_resolution_clock::now();
    cout << list.search(5000) << endl;
    auto end = high_resolution_clock::now();
    cout << "Time taken for search: " << duration_cast<seconds>(end - start).count() << " seconds" << endl;
    
    start = high_resolution_clock::now();
    list.traverse();
    end = high_resolution_clock::now();
    cout << "Time taken for traversal: " << duration_cast<seconds>(end - start).count() << " seconds" << endl;
    
    return 0;
}

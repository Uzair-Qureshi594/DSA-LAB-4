#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == value) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int value;

    for (int i = 0; i < 5; i++) {
        cout << "Enter value   " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    list.display();

    cout << "Enter value  : ";
    cin >> value;
    list.insert(value);
    list.display();

    cout << "Enter value to delete : ";
    cin >> value;
    list.deleteNode(value);
    list.display();

    cout << "Enter value to search: ";
    cin >> value;
    if (list.search(value))
        cout << "Value found" << endl;
    else
        cout << "Value not found" << endl;

    return 0;
}

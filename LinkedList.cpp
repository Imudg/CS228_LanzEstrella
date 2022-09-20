// LinkedList.cpp

#include <stdlib.h>
#include "LinkedList.h"

// Default constructor, the list is empty to start
LinkedList::LinkedList() {
    head->data = NULL;                  // Sets data of Node "head" to NULL
    head->next = NULL;                  // Makes head node point to NULL
}

// Default destructor, must delete all nodes
LinkedList::~LinkedList() {
    Node* currNode = head;              // Sets currNode as head node            
    Node* nextNode = NULL;              // Sets nextNode as NULL

    while (currNode != NULL)            // Executes following while currNode is not NULL
    {
        currNode->next = nextNode;      // Makes currNode point to address of nextNode
        delete currNode;                // Deletes currNode
        currNode = nextNode;            // Makes nextNode the new currNode
    }
}

// Add a node containing "value" to the front
void LinkedList::InsertFront(double value) {
    Node* newNode = new Node();         // Creates a newNode
    newNode->data = value;              // Sets the data of newNode to value

    newNode->next = head;               // New node points to head of list

    head = newNode;                     // Makes newNode the head node
}

// Add a node containing "value" to position "index"
void LinkedList::Insert(double value, unsigned int index) {
    Node* tracker = head;               // Creates a new node that tracks the head node
    Node* newNode = new Node();         // Creates newNode

    newNode->data = value;              // Sets the data of newNode to value

    if (index == 0) {                   // If the index is 0...
        newNode->next = head;           // Makes newNode point to the head node
        head = newNode;                 // Makes newNode the head node
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            tracker->next = tracker;
        }
        newNode->next = newNode->next;
        tracker->next = newNode;
    }
}


// Return value at position "index"

double LinkedList::GetNode(unsigned int index) {
    Node* currNode = head;              // Sets currNode as head node

    int i = 0;                          // Creates a counter i
    while (currNode != NULL) {          // While currNode is not NULL...
        if (i == index) {               // If counter i = index...
            return (currNode->data);    // Returns data of currNode
        }
        else {
            i++;                        // Increments counter i
            currNode->next = currNode;  // Sets the new currNode as what ever node the previous currNode was pointing at
        }
    }
}   


// Return the index of the node containing "value"

unsigned int LinkedList::Search(double value) {
    Node* currNode = head;              // Sets currNode as head node

    while (currNode != NULL) {          // While currNode is not NULL...
        if (value == currNode->data) {  // If value = the data located at currNode...
            return currNode->data;      // return the data located at currNode
        }
        else {
            currNode->next = currNode;  // Sets the new currNode as what ever node the previous currNode was pointing at
        }
    }
}


// Delete the node at position "index", return the value that was there

double LinkedList::DeleteNode(unsigned int index) {
    Node* currNode = head;              // Sets currNode as head node
    Node* temp = NULL;                  // Creates a temp node set as NULl
    Node* del = NULL;

    int i = 0;                          // Creates a counter
    while (currNode != NULL) {          // While currNode is not NULL...
        if (i == index) {               // If i = index...
            currNode->next = temp;      // Stores the location that currNod is pointing to at node temp
            del = temp;                 // Sets del node as temp node
            delete currNode;            // Deletes currNode
            currNode = temp;            // Set temp node as currNode
        }
    }
    return del->data;
}

// This function reverses the order of all nodes so the first node is now the
// last and the last is now the first (and all between). So a list containing 
// (4, 0, 2, 11, 29) would be (29, 11, 2, 0, 4) after Reverse() is called.

void LinkedList::Reverse() {
    Node* currNode = head;              // Sets currNode as head node
    Node* prevNode = NULL;              // Sets prevNode as NULL
    Node* nextNode = NULL;              // sets nextNode as NULL

    while (currNode != NULL) {          // While currNode is not Null...
        nextNode = currNode->next;      // Stores the loactin of nextNode
        currNode->next = prevNode;      // Sets currNode to point to prevNode
        prevNode = currNode;            // Sets prevNode as currNode
        currNode = nextNode;            // Sets currNode as nextNode
    }
    head = prevNode;                    // Sets head Node as prevNode
}

// Return the number of nodes in the list

int LinkedList::GetLength() {
    Node* currNode = head;              // Sets currNode as head node

    int i = 0;                          // Creats a counter
    while (currNode != NULL) {          // While currNode is not NULL
        i++;                            // Incrememnt i
        currNode = currNode->next;      // Sets new currNode as the node that the previous currNode pointed to
    }
    return i;
}

#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* newn = (struct Node*) malloc(sizeof(struct Node));
    newn -> data = data;
    newn -> next = NULL;
    return newn;
}

void detectAndRemoveLoop(Node *head){
    if(!head)
        return;
    Node *fptr = head, *sptr = head;
    if(head->next->next == head){
        head->next->next = NULL;
        return;
    }
    fptr = head->next-> next;
    sptr = head->next;
    while(fptr!=sptr){
        fptr = fptr->next->next;
        sptr = sptr->next;
    }
    sptr = head;
    while(sptr->next!=fptr->next){
        fptr = fptr->next;
        sptr = sptr->next;
    }
    fptr->next = NULL;
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    struct Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
 	return 0;
}

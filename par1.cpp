#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
};
void display(Node* n){
        while (n != NULL )
        {
            cout<< n->value << " -> ";
            n = n->next;
        }
        cout<<"NULL";
        
        
    }
void insertBegin(Node** head,int newvalue){
    Node* newnode = new Node();
    newnode->value = newvalue;
    newnode->next = *head;
    *head = newnode;

}
void insertEnd(Node** head,int newvalue){
    Node* newnode = new Node();
    newnode->value = newvalue;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    
    Node* last = *head;
    while (last->next != NULL)
    {
        last=last->next;
    }

    last->next = newnode;
    

}
void insertafter(Node* previous , int newvalue){
    if (previous == NULL)
    {
        cout<<"Previous node cant be null";
    }
    Node* newnode = new Node();
    newnode->value = newvalue;

    newnode->next = previous->next;
    previous->next = newnode;
    
}
void deleteBegin(Node*& head){
    if (head->next == NULL)
    {
        cout<<"The list is empty"<<endl;
    }

    Node *oldHead = head;
    head = head->next;
    delete oldHead;
    
    
}
void deletelast(Node* head){
    Node* secondLast = head;
    Node* last = head->next;
    while (last->next !=0)
    {
        last = last->next;
        secondLast = secondLast->next;
    }
    secondLast->next = NULL;
    
}

int main(){
    Node* head =new Node();
    Node* second =new Node();
    Node* third =new Node();

    head->value = 1;
    head->next=second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;

    deletelast(head);
    display(head);


}
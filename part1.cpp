#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;
};

void printForward(Node* head){
    Node* traverse = head;
    while (traverse != nullptr)
    {
        cout<<traverse->value<<" ";
        traverse = traverse->next;
    }
    
}

void printBack(Node* tail){
    Node* traverse = tail;
    while (traverse != nullptr)
    {
        cout<<traverse->value<<endl;
        traverse = traverse->prev;
    }
    
}

void insertathead(Node*& head, int value){
    Node* New = new Node();
    New->value = value;

    head->prev = New;
    New->prev = nullptr;
    New->next = head;

    head = New;
}

void insertattail(Node*& head , int value){
Node* New = new Node();
New->value = value;

Node* traverse = head;
while (traverse->next != nullptr)
{
    traverse = traverse->next ; 
}
traverse->next = New;
New->next = nullptr;
New->prev = traverse;

}

void Deleteathead(Node*& head){
    Node* Del = head;
    head = head->next;
    head->prev = nullptr;
    
    delete Del;
}

void Delete(Node*& head , int pos){
    Node* temp = head;
    if (pos == 1)
    {
        Deleteathead(head);
        return;
    }
    
    int count = 1 ;
    while (temp->next !=nullptr && count != pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
        
    }
    temp->prev->next = temp->next;
    
    

    delete temp;
}

int length(Node* head){
    Node* N = head;
    int l=1;
    while (N->next != nullptr)
    {
        l++;
        N=N->next;
    }
    return l;
}

Node* append(Node*& head, int k){
    
    Node* newhead;
    Node* newtail;
    Node* tail = head;

    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != nullptr )
    {
        if (count == l-k)
        {
            newtail = tail;
            
        }
        if (count == l-k+1)
        {
            newhead=tail;
        }
        tail=tail->next;
        count++;
        
    }
    tail->next=head;
    newtail->next=nullptr;

    return newhead;
    
}

int main(){
    Node* head;
    Node* tail;

    //first node
    Node* node = new Node();
    node->value = 1;
    node->next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;


    //second node;similarly add new nodes
    node = new Node();
    node->value = 2;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    node = new Node();
    node->value = 3;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    node = new Node();
    node->value = 4;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    node = new Node();
    node->value = 5;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    node = new Node();
    node->value = 6;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    printForward(head);
    Node* newhead = append(head,3);
    printForward(newhead);

    
}
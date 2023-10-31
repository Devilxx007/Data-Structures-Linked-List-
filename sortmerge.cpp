#include <iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
};

void insert(Node** head,int newvalue){
    Node* temp = new Node();
    Node* ptr;
    temp->value = newvalue;
    temp->next = nullptr;

    if (*head == nullptr)
    {
        *head = temp;
    }
    else{
        ptr = *head;
        while (ptr->next !=nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        
    }

}
Node* arrayinsert(int arr[], int size){
    Node* head = nullptr;
    for (int i = 0; i <= size; i++)
    {
        insert(&head,arr[i]);
    }
    return head;
    
}

void display(Node* head){
    Node* temp = head;
    while (temp->next != nullptr)
    {
        cout<<temp->value<<"->";
        temp = temp->next;  
    }
    cout<<"NULL";
}

Node* sort(Node* head1, Node* head2){
    Node* p1=head1;
    Node* p2=head2;
    Node* Dummy = new Node();
    Node* p3 = Dummy;

    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->value > p2->value)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1!=nullptr)
    {
        p3->next = p1;
        p1=p1->next;
        p3 = p3->next;
    }

    while (p2!=nullptr)
    {
        p3->next = p2;
        p2=p2->next;
        p3 = p3->next;
    }

    return Dummy->next;
    
}


int main(){
    int a1[] = {1,3,5};
    Node* head1 = arrayinsert(a1,3);
    

    int a2[] = {2,4};
    Node* head2 = arrayinsert(a2,2);
    

    Node* newhead = sort(head1,head2);
    display(newhead);
    
}
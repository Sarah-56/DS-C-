#include <iostream>
using namespace std;
//node struct
struct node
{
    int data;
    node *next;
};
//stack class
class stack
{
    node *head;
    node *tail;
public:
    stack(){
        head = NULL;
        tail = NULL;
    }
    void push(int data){
        node *new_node = new node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
        if(tail == NULL){
            tail = new_node;
        }
    }
    void pop(){
        node *temp = head;
        head = head->next;
        cout << "Deleted element is " << temp->data << endl;
        delete temp;
    }
    void display(){
        node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void is_empty(){
        if(head == NULL){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack is not empty"<<endl;
        }
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    s.is_empty();
    return 0;
}
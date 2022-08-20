#include <iostream>
using namespace std;
//node struct
struct node
{
    int data;
    node *next;
};
//queue class
class queue
{
    node *head;
    node *tail;
public:
    queue(){
        head = NULL;
        tail = NULL;
    }
    void enqueue(int data){
        node *new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }
    void dequeue(){
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
        if(head == NULL && tail == NULL){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue is not empty"<<endl;
        }
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.display();
    q.is_empty();
    return 0;
}
#include <iostream>
using namespace std;
//node struct
struct node
{
    int data;
    node *next;
};
//linked list class
class linked_list
{
    node *head;
    node *tail;
public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }
    void insert_at_beginning(int data){
        node *new_node = new node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
        if(tail == NULL){
            tail = new_node;
        }
    }
    void insert_at_end(int data){
        node *new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }
    void insert_at_position(int pos, int data){
        node *new_node = new node;
        new_node->data = data;
        node *temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    void delete_at_beginning(){
        node *temp = head;
        head = head->next;
        delete temp;
    }
    void delete_at_end(){
        node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    void delete_at_position(int pos){
        node *temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
    void display(){
        node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void reverse(){
        node *temp = head;
        node *temp2 = NULL;
        while(temp != NULL){
            temp2 = temp->next;
            temp->next = head;
            head = temp;
            temp = temp2;
        }
    }
};
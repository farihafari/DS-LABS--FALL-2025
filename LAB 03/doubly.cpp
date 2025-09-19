#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;   // extra pointer for doubly linked list
    
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head, *tail;
    public:
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void add_node_at_end(int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else {
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;  // link back
            tail = newnode;
        }
    }
    void display(){
        Node* temp = head;
        
        while(temp->next!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<"->NULL\n";
    }
    void add_node_at_front(int val){
        Node* newnode = new Node(val);
       
        if(head != NULL){
            head->prev = newnode;
			 newnode->next = head;  // link back
        }
        head = newnode;
        if(tail==NULL) tail = newnode; // if list was empty
    }
    void delete_at_end(){
        if(head==NULL) return;
        Node* temp = head;
        Node* prev;
         while(temp->next!=NULL){
             prev = temp;
             temp = temp->next;
         }
         prev->next = NULL;
         tail = prev;
         delete temp;
         temp = NULL;
    }
    void delete_at_front(){
        if(head==NULL) return;
        Node* temp = head;
        head = head->next;
        if(head!=NULL) head->prev = NULL; // fix link
        temp->next = NULL;
        delete temp;
    }
    void search_node(int val){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == val){
                cout<< val<<" is available\n";
                break;
            }
            temp = temp->next;
        }
        
    }
    void insert_at_pos(int pos, int val){
        Node* newnode = new Node(val);
        Node* temp = head;
        Node* prev = NULL;
        for(int i=1 ; i<pos;i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = newnode;
        newnode->prev = prev;
        newnode->next = temp;
        if(temp!=NULL) temp->prev = newnode;
    }
    void delete_at_post(int pos){
        // delete the node at any position
    }
    void delete_by_value(int pos){
        // delete the node by searching the value in linked ;
    }
};

int main()
{
    DoublyLinkedList list;
    list.add_node_at_end(10);
    list.add_node_at_end(20);
    list.add_node_at_end(30);
    list.add_node_at_end(40);
    list.add_node_at_end(50);
    
    list.add_node_at_front(60);
    
    list.display();
    cout<<endl;
    
    list.delete_at_end();
    
    list.display();
    
    list.delete_at_front();
    cout<<endl;
    list.display();
    
    list.search_node(40);
    list.insert_at_pos(3, 50);
    list.display();
    
    return 0;
}

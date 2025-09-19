#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head, *tail;
    public:
    CircularLinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void add_node_at_end(int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head = newnode;
            tail = newnode;
            tail->next = head;  // circular link
        }
        else {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;  // maintain circular
        }
    }

    void display(){
        if(head==NULL) return;
        Node* temp = head;
        do {
            cout<<temp->data<<"->";
            temp = temp->next;
        } while(temp != head);
        cout<<"HEAD\n";
    }

    void add_node_at_front(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = newnode;
            tail = newnode;
            tail->next = head;
        } else {
            newnode->next = head;
            head = newnode;
            tail->next = head;  // maintain circular
        }
    }

    void delete_at_end(){
        if(head==NULL) return;
        if(head==tail){ // only one node
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }

    void delete_at_front(){
        if(head==NULL) return;
        if(head==tail){ // only one node
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void search_node(int val){
        if(head==NULL) return;
        Node* temp = head;
        do {
            if(temp->data == val){
                cout<< val<<" is available\n";
                return;
            }
            temp = temp->next;
        } while(temp != head);
    }

    void insert_at_pos(int pos, int val){
        Node* newnode = new Node(val);
        if(pos==1){
            add_node_at_front(val);
            return;
        }
        Node* temp = head;
        for(int i=1 ; i<pos-1 && temp->next!=head; i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if(temp == tail) tail = newnode;  // if inserted at end
    }

    void delete_at_post(int pos){
        // can be implemented similarly for circular
    }
    
    void delete_by_value(int val){
        // can be implemented similarly for circular
    }
};

int main()
{
    CircularLinkedList list;
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

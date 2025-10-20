#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *link;
};
Node *top= NULL;
bool isEmpty(){
	if(top==NULL){
		return true;
	}else{
		return false;
	}
}
void Push(int value){
	Node * ptr = new Node();
	ptr->data = value;
	ptr->link=top;
	top = ptr;
}
void Pop(){
	if(isEmpty()){
		cout<< "Stack is UnderFlow\n"<<" ";
	}else{
		Node *ptr = top;
		top = top->link;
		delete(ptr);
	}
}
void ShowStack(){
	if(isEmpty()){
			cout<< "Stack is Empty\n"<<" ";
	}else 
	{
			 Node *temp = top;
        cout << "Stack elements (Top to Bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->link;
        }
         cout << endl;
	}
	
}
void Top(){
	if(isEmpty()){
			cout<< "Stack is Empty\n"<<" ";
	}else{
		cout<< "Stack Top element "<< top->data;
	}
}
int main(){
Push(1);
Push(2);
Push(3);
ShowStack();
Pop();
ShowStack();
Top();
return 0;
}

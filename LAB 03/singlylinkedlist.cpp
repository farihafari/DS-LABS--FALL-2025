#include <iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* next;
		Node(int val){
			data = val;
			next = null;
		}
		
};
 class SignlyLinkedList{
 	Node* head; //start node of the list
 	Node* tail; // end node of the list
 	public:
 		SignlyLinkedList(){
 			head = tail = null;
		 }
 };


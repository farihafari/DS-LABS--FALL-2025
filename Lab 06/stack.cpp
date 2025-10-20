#include <iostream>
using namespace std;
class Stack{
	int *arr; //storing array elements
	int size; // max size of stack
	int top; //most top index 
	public:
		Stack(int n){
			size = n;
			arr = new int[size];
			top = -1;
		}
		
		void PushStack(int x){
			if(top == size-1){
				cout<< "stack is overflow\n";
				return;
			}
			arr[++top]=x;
			
		}
		int PopStack(){
			if(top == -1){
				cout<<"stack is underflow\n";
			return -1;
			}
			return arr[top--];
		}
		int PeekStack(){
			if(top == -1){
				cout<<"Empty stack\n";
			return -1;
			}
			return arr[top];
		}
		
		bool IsEmptyStack(){
			return top == -1;
		}
};
int main(){
	Stack st(4);
	st.PushStack(1);
	st.PushStack(2);
	st.PushStack(3);
	st.PushStack(4);
	
	cout<<"popped "<< st.PopStack() << "\n";
	cout<<"popped "<< st.PopStack() << "\n";
	cout<<"top Element "<<st.PeekStack() << "\n";
	cout<< " Empty " << (st.IsEmptyStack() ? "yes" : "no" )<< "\n";
}

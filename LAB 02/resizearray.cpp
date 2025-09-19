#include <iostream>
#include <string>
using namespace std;
int* ReSize(int* oldArray,int oldsize, int newsize){
	if(newsize == oldsize){
		return oldArray;
	};
	 int* newArray=new int[newsize];
	 int limit  = (oldsize<newsize) ? oldsize : newsize;
	 for(int i = 0;i<limit;i++){
	 newArray[i] = oldArray[i];
	 };
	 delete[] oldArray;
	 return newArray;
}

int main(){
	int size = 5;
	int* arr = new int[size]{1,2,3,4,5};
	cout<< "old array: ";
	for(int i = 0;i<size;i++){
		cout<<arr[i]<< " ";
	};
	cout<<endl;
	int newsize = 8;
	arr = ReSize(arr,size,newsize);
	for(int i =size;i<newsize;i++){
		cin>>arr[i];
	}
	cout<<"new array add more: ";
	for(int i =0;i<newsize;i++){
		cout<<arr[i];
	}
	cout<<endl;
	size =newsize;
	newsize = 3;
	arr = ReSize(arr,size,newsize);
	cout<<"resize the smaller: ";
	for(int i=0;i<newsize;i++){
		cout<<arr[i];
	}
	cout<<endl;
	delete[] arr;
	return 0;
}

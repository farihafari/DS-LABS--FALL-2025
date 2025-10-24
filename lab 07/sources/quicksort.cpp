#include <iostream>
using namespace std;
int partition(int arr[],int start,int end){
	int index = start-1; // index for positioning the right index for lesser element of an array
	int pivot = arr[end]; // last index as a pivot
	for(int j = start; j<end; j++){
		if(arr[j]<=pivot){
			index++;
			swap(arr[j],arr[index]);
		}
	}
	index++;
	swap(arr[end],arr[index]);
	return index;
	}
	
	void quickSort(int arr[],int start,int end){
		if(start < end){
			int pIndx = partition(arr,start,end);
			quickSort(arr,start,pIndx-1); //for left half
			quickSort(arr,pIndx+1,end);//for right half
		}
	}
	int main(){
		int arr[]={10,12,7,2,9,3,5,9};
		int size = sizeof(arr)/sizeof(arr[0]);
		quickSort(arr,0,size-1);
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return 0;
	}

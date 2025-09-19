#include <iostream>
 using namespace std;
 class Sorting{

 	public:
// 		insertion sort
// 	void InsertionSort(){
// 		int size;
// 		int arr[size];
// 		cout<<"no. of elements \n";
// 		cin>>size;
// 			cout<<" elements \n";
// 		for(int i = 0;i<size;i++){
// 			cin>>arr[i];
//		 }
//		 
//		 for(int i=1;i<size;i++){
//		 	int key = arr[i];
//		 	int j = i-1;
//		 	while(j>=0 && arr[j]>key){
//		 		arr[j+1]=arr[j];
//		 		j--;
//			 }
//			 arr[j+1]=key;
//		 }
//		cout<<"insertion sort sorted array \n";
//		for(int i=0;i<size;i++)
//		{
//			cout<<arr[i]<<" ";
//		}
//		cout<<endl;
//	 }
//	 
	 
//	 bubble sort
//void BubbleSort(){
//	int size ;
//	int arr[size];
//	cout<<" no. of elements \n";
//	cin>>size;
//	cout<<"element \n";
//	for(int i = 0;i<size;i++){
//		cin>> arr[i];
//	}
//	
//	int counter =1;
//	while(counter<size){
//		for(int i=0;i<size-counter;i++){
//			if(arr[i]>arr[i+1]){
//				int temp = arr[i];
//				arr[i]=arr[i+1];
//				arr[i+1]=temp;
//			}
//		}
//		counter++;
//	}
//	
//	cout<<"bubble sorted array \n";
//	for(int i =0;i<size;i++){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//
//}

//	selection sort
//void Selection(){
//int size ;
//	int arr[size];
//	cout<<" no. of elements \n";
//	cin>>size;
//	cout<<"element \n";
//		for(int i = 0;i<size;i++){
//		cin>> arr[i];
//	}
//	
//	for(int i=0;i<size-1;i++){
//		int minIndex=i;
//		for(int j=i+1;j<size;j++){
//			if(arr[j]<arr[minIndex]){
//				minIndex=j;
//			}
//		}
//		int temp=arr[i];
//		arr[i]=arr[minIndex];
//		arr[minIndex]=temp;
//	};
//	
//	cout<<"elements \n";
//	for(int i=0;i<size;i++){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//}
//shell sort

//void ShellSort(){
//	int size;
//	
//	cout<<" no of elements \n";
//	cin>>size; 
//	int arr[size];
//	cout<<"elements \n";
//	for(int i=0;i<size;i++){
//		cin>>arr[i];
//	}
////	start reducing gap from a far gap
//	for(int gap = size / 2; gap > 0; gap /= 2){
////		 perform insertion sort on this gap size
//		for(int j = gap; j < size; j++){
//			int temp = arr[j];
//			int res=j;
////			shift the element untill the correction location is found
//			while(res >= gap && arr[res-gap] > temp){
//				arr[res]=arr[res-gap];
//				res -=gap;
//			}
////			put temp (orignal array) into its correct location
//			arr[res]=temp;
//		}
//	}
//	
////	print array
//cout<<"shell sorted array \n";
//for(int i=0;i<size;i++){
//	cout<<arr[i]<<" ";
//}
//cout<<endl;
//};

//comb sort
void CombSort(){
	int size ;

	cout<<" no of elements \n";
	cin>>size; 
	int gap = size ; //initialize the gap with length of array
	int arr[size];
	cout<<"elements \n";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	float shrink = 1.3 ;//ideal shirnk factor
	bool swapped = true;
	while (gap>1 || swapped){
//		update gap using shrink factor
		gap = (int)(gap/shrink);
		if(gap<1){
			gap = 1; // gap at least 1 must 
		}
		swapped = false;
//		applying bubble sort for sorting 
for(int i=0;i+gap<size;i++){
	if(arr[i]>arr[i+gap]){
		int temp = arr[i];
		arr[i]=arr[i+gap];
		arr[i+gap]=temp;
	}
}
	};
	//	print array
cout<<"comb sorted array \n";
for(int i=0;i<size;i++){
	cout<<arr[i]<<" ";
}
cout<<endl;
}
 };
 int main(){
 	Sorting sort;
// 	sort.InsertionSort(); //insertion sort
 	 
// 	 sort.BubbleSort(); //bubble sort
// 	 sort.Selection();//selection
//sort.ShellSort();
sort.CombSort();
 	return 0;
 }

#include <iostream>
using namespace std;
class Searching{

	public:
		void LinearSearch(int size, int arr[],int key){
			bool found = false;
			for(int i=0;i < size; i++){
				if(arr[i]==key){
					cout<< arr[i] << " has index " << i<<" in array list";
					found = true;
				}
			}
			cout<< endl;
			if(!found){
					cout<< key << "  not found " ;
			}
		}
		void BinarySearch(int size,int arr[],int key){
			int init = 0;
			int final =size-1;
			bool found = false;
			while (init<=final){
				int mid = init+final/2;
				if(arr[mid]==key){
					cout << arr[mid] <<" has indes "<< mid;
					found = true;
					break;
				}
				else if(arr[mid]<key) {
					init = mid+1;
				}else{
					final = mid-1;
				}
			}
			if(!found){
				cout<< key << "  not found " ;	
			}
			
		}
			
			void InterpolationSearch(int size,int arr[],int key){
				int low =0;
				int high = size-1;
				bool found = false;
				while(low<=high && key>=arr[low]&& key<=arr[high]){
					if(low==high){
						if(key==arr[low]){
							cout << key<<" has the index "<< low;
							found = true;
							
						}
						break;	
					}
					
					
					int pos = low+((key-arr[low]) * (high-low))/(arr[high]-arr[low]);
					if(arr[pos]==key) {
						cout<<arr[pos] << " has the index "<< pos;
						found = true;
						break;
						}
					else if (arr[pos]<key)	{
					low = pos+1;	
					}
					else{
						high = pos-1;
					}	
					
				}
			if(!found){
					cout<< key << "  not found " ;	
			}
			}
};
int main(){
		int size;
	cout<<" size of element\n";
	cin>> size;
	int arr[size];
		cout<<"  element of array \n";
		for(int i=0;i<size; i++){
			cin>>arr[i];
		}
		int key;
			cout<<" key for find \n";
			cin>> key;
	Searching search;
//	search.LinearSearch(size,arr,key);
//search.BinarySearch(size,arr,key);
search.InterpolationSearch(size,arr,key);
}

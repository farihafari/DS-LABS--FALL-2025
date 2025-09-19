#include <iostream>

using namespace std;

//Shallow And 
//class Students{
//	public :
//		int *marks ; //pointer to heap mem
////		constructor
//		Students(int m){
//			marks = new int(m); //allocate mem
//		}
////		destructor
//		~Students(){
//			delete marks;
//		}
//		
//};

//Deep Copy 
//class Student{
//	public:
//		int *marks; //pointer to heap mem
//		
////		constructor
//Student(int m){
//	marks = new int(m);
//}
////		copy constructor
//Student(const Student& s){
//	marks  = new int(*s.marks); //allocate the new memory and value 
//	
//}
////destructor
// ~Student(){
// 	delete marks;
// }
//		
//};

//pointers 

int main (){
	
	//shallow copy object
//Students std1(87); 
//Students std2 = std1; //shallow copy constructor 
//cout<<"before chnages in object: \n";
//cout<< "std1 marks: "<<*std1.marks <<endl;
//cout<< "std2 marks: "<<*std2.marks <<endl;
//*std2.marks = 65;
//
//cout<<"\n after chnages in object: \n";
//cout<< "std1 marks: "<<*std1.marks <<endl;
//cout<< "std2 marks: "<<*std2.marks <<endl;

//Deep Copy Object
//Student s1(87); 
//Student s2 = s1; //Deep copy constructor 
//cout<<"before chnages in object: \n";
//cout<< "std1 marks: "<<*s1.marks <<endl;
//cout<< "std2 marks: "<<*s2.marks <<endl;
//*s2.marks = 65;
//
//cout<<"\n after chnages in object: \n";
//cout<< "std1 marks: "<<*s1.marks <<endl;
//cout<< "std2 marks: "<<*s2.marks <<endl;
//return 0;
	
//	int * Pvar = NULL; //delcaration of pointer
//	Pvar = new int; //dynamic memory allocation for single integer value
//	*Pvar = 100; // assigning the value of  varibale 
//	 cout << "Address of dynamic allocated integer: "<< &Pvar<<endl;
//	 cout << "value of dynamic allocated integer: "<< *Pvar<<endl;
////	 free memory
//	delete Pvar;
//	return 0;

//DMA 

// char *Grades = NULL; //Grades allocation by user
// int Num ; //no of grade
//// asking by user 
//cout << "Enter the no of Grade : ";
//cin>> Num;
//Grades = new char[Num]; //Dynamically allocating memory for Grades number
//for(int i =0;i<Num;i++){
//	cout<<"Enter The Grades: "<<i+1 << ": ";
//	cin>>Grades[i];
//}
////displaying the Grades 
//for(int i =0;i<Num;i++){
//	cout << Grades[i]<<" ";
//}
//cout<<endl;
////release Memory
//delete[] Grades;
//return 0;



}

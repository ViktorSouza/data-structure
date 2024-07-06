#include<iostream>
#include<stdlib.h>
using namespace std;

class Array{
	public:
		void push_back(int value){
			if(len+1>=capacity){
				int *newArr = (int*)malloc(capacity*sizeof(int)*2);
				for(int i = 0; i < capacity; i ++){
					newArr[i] = arr[i];
				}
				arr = newArr;
				capacity*=2;
			}
			len++;
			arr[len-1] = value;
			cout<<len-1<<":"<<arr[len-1]<< endl;

		};

		int len;
		int capacity;
		Array(){
			arr = (int*)malloc(sizeof(int)*2);
			len =0;
			capacity = 2;
		};
		int size(){
			return len;
		};
		int get(int index){
			if(index >= len){
			return -1;
			}
			int value = arr[index];
			return value;
		};
		int* arr;
};

int main(){
	Array arr;
	arr.push_back(999); 
	arr.push_back(1222);

	for(int i = 0; i < arr.size(); i++)

		cout<<i<<": "<< arr.get(i)<< endl;

	return 0;
}

#include<iostream>
#include<stdexcept>
using namespace std;


class Node{
		public:
		int value;
		Node* nextNode;
		Node(int v, Node* next){
			value = v;
			nextNode= next;
		};
		int changeNextNode(Node* node){
			nextNode = node;
			return 0;
		};
		int changeValue(int v){
			value = v;
			return 0;
		};
};

class Queue{
	public:
		size_t length;
		Node* tail;
		Node* head;
		Queue(){
			tail = NULL;
			head = NULL;
		};
		int size(){
			return length;
		};
		int peek(){
			if(head == nullptr)
				throw out_of_range("There is no element in the queue");
			return head->value;
		};
		int enqueue(int value){
			Node* newNode = new Node( value, tail);
			if(head == nullptr){
			head = newNode;};
			if(tail != NULL){
			tail->changeNextNode(newNode);			
			}
			tail = newNode;
			length++;
			return 0;
		};
		int dequeue(){
			if(head == nullptr){
				return -1;
			}
			head = head->nextNode;
			length--;
			return 0;

		};
	};

int main(){
	Queue q;
	q.enqueue(13);
	q.enqueue(19);
	cout<<q.peek();
	return 0;
}

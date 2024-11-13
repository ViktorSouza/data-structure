#include<iostream>
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
class LinkedList{
	public:
		unsigned int size;
		Node* head;
		LinkedList(){
			size = 0;
		};
		int addNode(int value,int index = -1){
			if(index == -1)
				index = size;
			//If there is no nodes, then, a head node will be added.
			if(size == 0){
				head = new Node(value,NULL);
			}else{
				Node* lastNode = head;
				for(int i = 0; i < index-1; i ++){
					lastNode = lastNode->nextNode;
				}
				//If index == size, then it's already in the last node
				if(index!= size){
					lastNode = lastNode->nextNode;
				}
				Node* newNode = new Node(value, lastNode->nextNode);
				lastNode->changeNextNode(newNode);
			}
			cout<<"Node added"<<endl;
			size++;
			return 0;
		}
		int removeNode(int index){
			Node* lastNode = head;
			for(int i = 0; i < index-1; i ++){
				lastNode = lastNode->nextNode;
			}
			Node* nodeToBeDeleted = lastNode->nextNode;
			// Here, the lastNode will point to the node after the node to be deleted.
			// lastNode -> nodeToBeDeleted -> nextNode
			// After the deletion, it's going to be
			// lastNode -> nextNode
			lastNode->changeNextNode(nodeToBeDeleted->nextNode);
			delete nodeToBeDeleted;

			return 0;
		};
		int getValue(int index){
			Node* lastNode = head;
			for(int i = 0; i < index; i ++){
				lastNode = lastNode->nextNode;
			}
			return lastNode->value;
		};
};

int main(){
	cout<<"Hey"<<endl;
	LinkedList list;
	list.addNode(02);
	cout<<"0: "<< list.getValue(0)<<endl;
	list.addNode(12);
	cout<< "1: "<<list.getValue(1)<<endl;
	list.addNode(22);
	cout<< "2: "<<list.getValue(2)<<endl;
	list.addNode(32);
	cout<< "3: "<<list.getValue(3)<<endl;
	list.addNode(42);
	cout<< "4: "<<list.getValue(4)<<endl;
	list.removeNode(2);
	cout<< "2: "<<list.getValue(2)<<endl;


	return 0;
}


#include <iostream>
#include <queue>

using namespace std;
template <class T>
class Node
{
public:
	T value;
	Node(T initialValue)
	{
		value = initialValue;
		leftChild = NULL;
		rightChild = NULL;
	};
	Node<T> *leftChild;
	Node<T> *rightChild;
	bool isLeaf()
	{
		return ((leftChild == NULL) && (rightChild == NULL));
	};
};

template <class T>
class BinarySearchTree
{
public:
	unsigned int nodeCount;
	Node<T> *root;
	BinarySearchTree(T rootValue)
	{
		root = new Node<T>(rootValue);
		nodeCount = 1;
	};

	int addValue(T value)
	{
		Node<T> *actualNode = root;
		while (!actualNode->isLeaf())
		{
			if (value < actualNode->value)
			{
				if (actualNode->leftChild == NULL)
				{
					break;
				}
				actualNode = actualNode->leftChild;
			}

			else
			{

				if (actualNode->rightChild == NULL)
				{
					break;
				}
				actualNode = actualNode->rightChild;
			}
		}

		Node<T> *newNode = new Node<T>(value);
		if (value < actualNode->value)
			actualNode->leftChild = newNode;
		else
			actualNode->rightChild = newNode;

		nodeCount++;
		return 0;
	};
	int inOrder(Node<T> *node)
	{
		if (node->leftChild != NULL)
		{
			inOrder(node->leftChild);
		}
		cout << node->value << " ";
		if (node->rightChild != NULL)
		{
			inOrder(node->rightChild);
		}
		return 0;
	};
	int transversePrint()
	{
		queue<Node<T> *> nodes;
		nodes.push(root);
		while (nodes.size())
		{
			cout << nodes.front()->value;
			cout << " ";
			if (!nodes.front()->isLeaf())
			{
				if (nodes.front()->leftChild != NULL)
				{
					nodes.push(nodes.front()->leftChild);
				}
				if (nodes.front()->rightChild != NULL)
				{
					nodes.push(nodes.front()->rightChild);
				}
			}
			nodes.pop();
		}
		return 0;
	};
	Node<T> *findNode(T value)
	{
		Node<T> *currentNode = root;
		bool isValueFound = false;
		while (!isValueFound)
		{
			if (value == currentNode->value)
			{
				isValueFound = true;
				break;
			}
			if (value < currentNode->value)
			{
				if (currentNode->leftChild == NULL)
					break;
				currentNode = currentNode->leftChild;
			}

			else
			{
				if (currentNode->rightChild == NULL)
					break;
				currentNode = currentNode->rightChild;
			}
		}

		return currentNode;
	}
	Node<T>* getParentNode(Node<T>*node){
		
	};
	int removeNode(Node<T>* node,T value)
	{
		Node<T> *nodeToBeRemoved;

		if (nodeToBeRemoved == NULL)
			return -1;
		if (nodeToBeRemoved->isLeaf())
		{
			delete nodeToBeRemoved;
			return 0;
		}
		Node<T> *substituteNode;

		if (nodeToBeRemoved->leftChild != = NULL)
		{
			substituteNode = nodeToBeRemoved->leftChild;
			while (substituteNode->rightChild != NULL)
				substituteNode = substituteNode->rightChild;
		}
		else
		{
			substituteNode = nodeToBeRemoved->rightChild;
			while (substituteNode->leftChild != NULL)
				substituteNode = substituteNode->leftChild;
		}
		nodeToBeRemoved = substituteNode;
		substituteNode
	}
};

int main()
{
	BinarySearchTree<int> numbers(5);
	numbers.addValue(10);
	numbers.addValue(8);
	numbers.addValue(3);
	numbers.addValue(18);
	numbers.addValue(22);
	numbers.addValue(-5);
	numbers.addValue(2);
	// numbers.inOrder(numbers.root);
	numbers.transversePrint();
	bool res = numbers.findNode(18);
	cout << (res ? "YES" : "NO");

	return 0;
}

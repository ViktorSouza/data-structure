#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
	vector<int> list;
	int parent(int index)
	{
		return (index - 1) / 2;
	};
	int lChild(int index)
	{
		return 2 * index + 1;
	};
	int rChild(int index)
	{
		return 2 * index + 2;
	};
	int heapify(int index)
	{
		int l = lChild(index);
		int r = rChild(index);
		int largest;

		if (l < list.size() && list[l] > list[index])
			largest = l;
		if (r < list.size() && list[r] > list[largest])
			largest = r;
		swap(largest, index);
		heapify(largest);
		return 0;
	};
	int deleteMax()
	{
		list[0] = list[list.size() - 1];
		list.pop_back();
		return 0;
		heapify(0);
	};
	int deleteKey(int value)
	{
		int index = -1;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] == value){
				index = i;
			break;
			}
		}
		if (index == -1)
			return 1;
		swap(list[index], list[list.size() - 1]);
		list.pop_back();
		while ((list[index] > list[parent(index)]) && (index != 0))
		{
			swap(list[index], list[parent(index)]);
			index = parent(index);
		}
		return 0;
	}
	int insertKey(int value)
	{
		list.push_back(value);
		int index = list.size() - 1;
		// While the heap is not correct, the new added node will "go up" until it is in the correct position
		while ((list[index] > list[parent(index)]) && (index != 0))
		{
			swap(list[index], list[parent(index)]);
			index = parent(index);
		}
		return 0;
	};
};
int main()
{
	Heap heap;
	heap.insertKey(40);
	heap.insertKey(10);

	heap.deleteMax();

	heap.insertKey(30);
	heap.insertKey(20);

	heap.deleteKey(10);
	for (int i = 0; i < heap.list.size(); i++)
	{
		cout << heap.list[i] << endl;
	}
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;

void upheapify(vector<int> &heap, int index)
{
	if(index==0)
		return;
	int parentIndex = (index-1)/2;
	if(heap[parentIndex]< heap[index])
	{
		swap(heap[parentIndex],heap[index]);
		upheapify(heap,parentIndex);
	}
	else
		return;
}

void insert(vector<int> &heap, int key)
{
	heap.push_back(key);
	upheapify(heap,heap.size()-1);
}

void print(vector<int> heap)
{
	for(int i=0;i<heap.size();i++)
		cout << heap[i]<<",";
	cout << endl;
}

void downheapify(vector<int> &heap, int index)
{
	int leftIndex = 2*index+1;
	int rightIndex = 2*index+2;
	int heapSize = heap.size();
	if(leftIndex>=heapSize and rightIndex>=heapSize)
		return;
	int indexOfLargestValue = index;
	if(leftIndex<heapSize and heap[leftIndex]>heap[indexOfLargestValue])
		indexOfLargestValue=leftIndex;
	if(rightIndex<heapSize and heap[rightIndex]>heap[indexOfLargestValue])
		indexOfLargestValue=rightIndex;
	if(indexOfLargestValue == index)
	return;
		swap(heap[indexOfLargestValue],heap[index]);
	downheapify(heap,indexOfLargestValue);
}
void deletePeek(vector<int> &heap)
{
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	downheapify(heap,0);
}

int main()
{

	vector<int> heap;
	heap.push_back(3);
	heap.push_back(6);
	heap.push_back(9);
	heap.push_back(1);
	heap.push_back(4);
	heap.push_back(7);
	// heap(heap,6);
	// heap(heap,9);
	// heap(heap,1);
	// heap(heap,4);
	// heap(heap,7);

	print(heap);

	for(int i=0;i<heap.size();i++)
	{
		upheapify(heap,i);
	}

	print(heap);

	return 0;
}
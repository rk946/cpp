#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an array of size n. The problem is to check whether the given array can represent the level order traversal of a Binary Search Tree or not.

Examples:

Input : arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}
Output : Yes
For the given arr[] the Binary Search Tree is:
         7        
       /    \       
      4     12      
     / \    /     
    3   6  8    
   /   /    \
  1   5     10

Input : arr[] = {11, 6, 13, 5, 12, 10}
Output : No
The given arr[] do not represent the level
order traversal of a BST.*/





/*Solution : 

The idea is to use a queue data structure. Every element of queue has a structure say NodeDetails which stores details of a tree node. The details are node’s data, and two variables min and max where min stores the lower limit for the node values which can be a part of the left subtree and max stores the upper limit for the node values which can be a part of the right subtree for the specified node in NodeDetails structure variable. For the 1st array value arr[0], create a NodeDetails structure having arr[0] as node’s data and min = INT_MIN and max = INT_MAX. Add this structure variable to the queue. This Node will be the root of the tree. Move to 2nd element in arr[] and then perform the following steps:

Pop NodeDetails from the queue in temp.
Check whether the current array element can be a left child of the node in temp with the help of min and temp.data values. If it can, then create a new NodeDetails structure for this new array element value with its proper ‘min’ and ‘max’ values and push it to the queue, and move to next element in arr[].
Check whether the current array element can be a right child of the node in temp with the help of max and temp.data values. If it can, then create a new NodeDetails structure for this new array element value with its proper ‘min’ and ‘max’ values and push it to the queue, and move to next element in arr[].
Repeat steps 1, 2 and 3 until there are no more elements in arr[] or there are no more elements in the queue.
Finally, if all the elements of the array have been traversed then the array represents the level order traversal of a BST, else NOT.

*/

// C++ implementation to check if the given array 
// can represent Level Order Traversal of Binary 
// Search Tree 
#include <bits/stdc++.h> 

using namespace std; 

// to store details of a node like 
// node's data, 'min' and 'max' to obtain the 
// range of values where node's left and 
// right child's should lie 
struct NodeDetails 
{ 
	int data; 
	int min, max; 
}; 

// function to check if the given array 
// can represent Level Order Traversal 
// of Binary Search Tree 
bool levelOrderIsOfBST(int arr[], int n) 
{ 
	// if tree is empty 
	if (n == 0) 
		return true; 
	
	// queue to store NodeDetails 
	queue<NodeDetails> q; 
	
	// index variable to access array elements 
	int i=0; 
	
	// node details for the 
	// root of the BST 
	NodeDetails newNode; 
	newNode.data = arr[i++]; 
	newNode.min = INT_MIN; 
	newNode.max = INT_MAX; 
	q.push(newNode); 
	
	// until there are no more elements 
	// in arr[] or queue is not empty 
	while (i != n && !q.empty())		 
	{ 
		// extracting NodeDetails of a 
		// node from the queue 
		NodeDetails temp = q.front(); 
		q.pop(); 
		
		// check whether there are more elements 
		// in the arr[] and arr[i] can be left child 
		// of 'temp.data' or not 
		if (i < n && (arr[i] < temp.data && 
					arr[i] > temp.min)) 
		{ 
			// Create NodeDetails for newNode 
			/// and add it to the queue 
			newNode.data = arr[i++]; 
			newNode.min = temp.min; 
			newNode.max = temp.data; 
			q.push(newNode);				 
		} 
		
		// check whether there are more elements 
		// in the arr[] and arr[i] can be right child 
		// of 'temp.data' or not 
		if (i < n && (arr[i] > temp.data && 
					arr[i] < temp.max)) 
		{ 
			// Create NodeDetails for newNode 
			/// and add it to the queue 
			newNode.data = arr[i++]; 
			newNode.min = temp.data; 
			newNode.max = temp.max; 
			q.push(newNode);			 
		}		 
	} 
	
	// given array represents level 
	// order traversal of BST 
	if (i == n) 
		return true; 
		
	// given array do not represent 
	// level order traversal of BST	 
	return false;		 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};	 
	int n = sizeof(arr) / sizeof(arr[0]);	 
	if (levelOrderIsOfBST(arr, n)) 
		cout << "Yes"; 
	else
		cout << "No";		 
	return 0;	 
} 

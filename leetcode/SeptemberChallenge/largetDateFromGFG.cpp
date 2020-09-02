// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the updated frequency map 
// for the array passed as argument 
map<int, int> getFrequencyMap(int arr[], int n) 
{ 
	map<int, int> hashMap; 
	for (int i = 0; i < n; i++) { 

		hashMap[arr[i]]++; 
	} 
	return hashMap; 
} 

// Function that returns true if the passed digit is present 
// in the map after decrementing it's frequency by 1 
bool hasDigit(map<int, int>* hashMap, int digit) 
{ 

	// If map contains the digit 
	if ((*hashMap)[digit]) { 

		// Decrement the frequency of the digit by 1 
		(*hashMap)[digit]--; 

		// True here indicates that the digit was found in the map 
		return true; 
	} 

	// Digit not found 
	return false; 
} 

// Function to return the maximum possible time_value in 24-Hours format 
string getMaxtime_value(int arr[], int n) 
{ 
	map<int, int> hashMap = getFrequencyMap(arr, n); 
	int i; 
	bool flag; 
	string time_value = ""; 

	flag = false; 

	// First digit of hours can be from the range [0, 2] 
	for (i = 2; i >= 0; i--) { 
		if (hasDigit(&hashMap, i)) { 
			flag = true; 
			time_value += (char)i + 48; 
			break; 
		} 
	} 

	// If no valid digit found 
	if (!flag) 
		return "-1"; 

	flag = false; 

	// If first digit of hours was chosen as 2 then 
	// the second digit of hours can be 
	// from the range [0, 3] 
	if (time_value[0] == '2') { 
		for (i = 3; i >= 0; i--) { 
			if (hasDigit(&hashMap, i)) { 
				flag = true; 
				time_value += (char)i + 48; 
				break; 
			} 
		} 
	} 

	// Else it can be from the range [0, 9] 
	else { 
		for (i = 9; i >= 0; i--) { 
			if (hasDigit(&hashMap, i)) { 
				flag = true; 
				time_value += (char)i + 48; 
				break; 
			} 
		} 
	} 
	if (!flag) 
		return "-1"; 

	// Hours and minutes separator 
	time_value += ":"; 

	flag = false; 

	// First digit of minutes can be from the range [0, 5] 
	for (i = 5; i >= 0; i--) { 
		if (hasDigit(&hashMap, i)) { 
			flag = true; 
			time_value += (char)i + 48; 
			break; 
		} 
	} 
	if (!flag) 
		return "-1"; 

	flag = false; 

	// Second digit of minutes can be from the range [0, 9] 
	for (i = 9; i >= 0; i--) { 
		if (hasDigit(&hashMap, i)) { 
			flag = true; 
			time_value += (char)i + 48; 
			break; 
		} 
	} 
	if (!flag) 
		return "-1"; 

	// Return the maximum possible time_value 
	return time_value; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2,0,6,6 }; 
	int n = sizeof(arr) / sizeof(int); 
	cout << (getMaxtime_value(arr, n)); 
	return 0; 
} 
// contributed by Arnab Kundu 

#include <bits/stdc++.h>

using namespace std;

int binary_search(int* arr, int key, int left, int right){
	while(left<=right){
		int mid = left + ((right-left)/2);
		if(arr[mid] == key){
			return mid;
		}
		if(arr[mid] > key){
			right = mid-1;
		}if(arr[mid] < key){
			left = mid+1;
		}
	}

	return -1;
}

int main(){
	int n, key;
	cout << "Enter Number Of Elements: ";
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);

	cout << "Sorted Array: " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Enter element to be found: " << endl;
	cin >> key;

	int result = binary_search(arr, key, 0, n-1);

	if(result == -1){
		cout << "Element Not Found" << endl;;
	}else {
		cout << "Element Found at Index: " << result << endl; 
	}
}
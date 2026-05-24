#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////竞赛最常用 sort  需要稳定性就 stable_sort
//vector<int> arr = {12,25,68,48,65};
//sort(arr.begin(), arr.end()); // 升序排列
//sort(arr.rbegin(), arr.rend());  //降序排列
//sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; }); // 升序排列
//
//// 快速排序
//void quicksort(int arr[], int l, int r) {
//	if (l >= r)return;
//	int left = l; int right = r;
//	int flag = arr[left];
//	while (left < right) {
//		while (left < right && arr[right] >= flag) {
//			right--;
//		}
//		if (left < right) {
//			arr[left] = arr[right];
//		}
//		while (left < right && arr[left] <= flag) {
//			left++;
//		}
//		if (left < right) {
//			arr[right] = arr[left];
//		}
//		if (left >= right) {
//			arr[left] = flag;
//		}
//	}
//	quicksort(arr, l, right - 1);
//	quicksort(arr, right + 1, r);
//}



//// 盲打快排
//void quicksort(int arr[], int l, int r) {
//	int left = l; int right = r;
//	int flag = arr[left];
//	while (left < right) {
//		while (left < right && arr[right] >= flag) {
//			right--;
//		}
//		if (left < right) {
//			arr[left] = arr[right];
//		}
//		while (left < right && arr[left] <= flag) {
//			left++;
//		}
//		if (left < right) {
//			arr[right] = arr[left];
//		}
//		if (left >= right) {
//			arr[left] = flag;
//		}
//	}
//	quicksort(arr, l, right - 1);
//	quicksort(arr, right + 1, r);
//}
//
//// 归并排序
//void merge(vector<int>& arr, int left, int mid, int right) {
//	vector<int> temp;
//	int i = left, j = mid + 1;
//	while (i <= mid && j <= right) {
//		if (arr[i] <= arr[j]) {
//			temp.push_back(arr[i++]);
//		}
//		else {
//			temp.push_back(arr[j++]);
//		}
//	}
//	while(i<=mid)temp.push_back(arr[i++]);
//	while(j<=right)temp.push_back(arr[j++]);
//	for (int i = 0; i < temp.size(); i++) {
//		arr[left + i] = temp[i];
//	}
//}
//
//void mergesort(vector<int>& arr, int left, int right) {
//	if (left >= right)return;
//	int mid = left + (right - left) / 2;
//	mergesort(arr, left, mid);
//	mergesort(arr, mid + 1, right);
//  	merge(arr, left, mid, right);
//}
//
//int main() {
//	vector<int> s = { 12,345,67,54,32 };
//	mergesort(s, 0, s.size() - 1);
//	for (auto k : s) {
//		cout << k << ' ';
//	}
//}

// 盲打归排
//void merge(vector<int>& arr, int left, int mid, int right) {
//	vector<int> temp;
//	int i = left, j = mid + 1;
//	while (i<=mid && j<=right) {
//		if (arr[i] <= arr[j]) {
//			temp.push_back(arr[i++]);
//		}
//		else {
//			temp.push_back(arr[j++]);
//		}
//	}
//	while(i<=mid)temp.push_back(arr[i++]);
//	while(j<=right)temp.push_back(arr[j++]);
//	for (int i = 0; i < temp.size(); i++) {
//		arr[left + i] = temp[i];
//	}
//}
//
//void mergesort(vector<int>& arr, int left, int right) {
//	if (left >= right) return;
//	int mid = left + (right - left) / 2;
//	mergesort(arr, left, mid);
//	mergesort(arr, mid + 1, right);
//	merge(arr, left, mid, right);
//}

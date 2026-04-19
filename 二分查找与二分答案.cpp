#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 二分查找和二分答案
// 双指针取中查找 （关键是找到分界线）
// 二分查找的模板
//左指针l -1 右指针r n 
//while (l + 1 != n) {
//	int mid = (l + r) / 2;
//	if (isBlue(arr[mid])) {      // isBlue是条件函数
//		l = mid;
//	}
//	else r = mid;
//}


// 典型二分查找(找到第一个大于5的数的下标)

//int main() {
//	int arr[7] = { 3,5,5,5,6,7,8 };
//	int l = -1, r = 7;
//	while (l + 1 != r) {
//		int mid = (l + r) / 2;
//		if (arr[mid] <= 5)l = mid;
//		else r = mid;
//	}
//	cout << r;    // 输出下标4
//	return 0;
//}


// 模板题 查找q个元素的起始位置和终止位置
//int main() {
//	int n, q; cin >> n >> q;
//	vector<int> num(n);
//	for (int i = 0; i < n; i++)cin >> num[i];
//	for (int j = 0; j < q; j++) {
//		int x; cin >> x;
//		int l = -1, r = n; int flag = 0;
//		for (int i = 0; i < n; i++) {
//			if (num[i] == x)flag = 1;
//		}
//		if (flag == 0) {
//			cout << -1 << ' ' << -1 << endl;
//			continue;
//		}
//		while (l + 1 != r) {
//			int mid = (l + r) / 2;
//			if (num[mid] < x)l = mid;
//			else r = mid;
//		}
//		cout << r << ' ';
//		int l1 = -1, r1 = n;
//		while (l1 + 1 != r1) {
//			int mid = (l1 + r1) / 2;
//			if (num[mid] > x)r1 = mid;
//			else l1 = mid;
//		}
//		cout << l1 << endl;
//	}
//	return 0;
//}

// 跳石头问题(找最小值的最大值)
//#include<iostream>
//#include<vector>
//using namespace std;
//int l, n, m;
//vector<int> num;
//
//bool check(int x) {
//	int cnt = 0;
//	int cha;
//	for (int i = 1; i < n+2; i++) {
//		cha += num[i] - num[i - 1];
//		if (cha < x) {
//			cnt++;
//		}
//		else cha = 0;
//	}
//	if (cnt <= m) return true;
//	else return false;
//}
//
//int main() {
//	cin >> l >> n >> m;
//	num.push_back(0);
//	for (int i = 0; i < n; i++) {
//		int p; cin >> p;
//		num.push_back(p);
//	}
//	num.push_back(l);
//	int le = 0, r = l+1;
//	while (le + 1 != r) {
//		int mid = (le + r) / 2;
//		if (check(mid))le = mid;
//		else r = mid;
//	}
//	cout << le;
//	return 0;
//}


// 路标设置 （找最大值的最小值）

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;

// 找最小的这种问题 一般都是右边的数可以就令r=mid;

//int l, n, k;
//vector<int> num;
//vector<int> cha;
//
//bool check(int x) {
//	int cnt = 0;
//	for (int i = 0; i < n - 1; i++) {
//		int sum = cha[i];
//		while (sum > x) {
//			cnt++;
//			sum -= x;
//		}
//	}
//	if (cnt <= k)return true;
//	else return false;
//}
//
//int main() {
//	cin >> l >> n >> k;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		num.push_back(x);
//	}
//	for (int i = 1; i < n; i++) {
//		cha.push_back(num[i] - num[i - 1]);
//	}
//	int le = 1, r = num[n - 1];  // le必须初始化为1
//	while (le + 1 != r) {
//		int mid = (le + r) / 2;
//		if (check(mid))r = mid;  //check(0)是有问题的 进函数会死循环
//		else l = mid;
//	}
//	if (check(le))cout << le;
//	else cout << r;
//	return 0;
//}











// 重塑二分世界观

// 要知道一般大部分测试点过了 少部分没过 那就是边界问题 left和right的边界问题
// 要注意是左闭右开 还是 左闭右闭 
// 边界问题很重要 right不能特别特别大 就最多大1就行 不然会有一些根本找不到的错误

// 二分查找 （分两种情况）

// 1. 需要找到确切值的位置的

// 二分模版

/*

	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)return mid;    // 最后结果一定在这里找出
		else if (nums[mid] < target)left = mid + 1;
		else right = mid - 1;
	}
	return -1

*/


// 2. 需要找边界的（此类又分为两种情况（上界和下界））

// a. 找上界 （第一个 >target 的数）

/*

	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] > target)right = mid;
		else left = mid + 1;
	}
	return left;

*/


// b.找下界（第一个 >=target 的数）

/*
	int left = 0,right = nums.size()-1;
	while(left<right){
		int mid = left+(right-left)/2;
		if(nums[mid]>=target)right = mid;
		else left = mid+1;
	}
	return left;
*/




// 二分答案（应该大多数都是两种情况）
 
// a. 找小的里面的最大值（找的思路是找到不符合的第一个 其实就是找下界 然后-1）

// 洛谷 跳石头 木材加工

// 二分模版
/*
	int left = 0, right = k + 1;  // 关于边界要考虑清楚 不一定是这个
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (!check(mid))right = mid;  // 关于这个什么时候是right要看check函数的判断
		else left = mid + 1;
	}
	cout << left - 1;  // 最后是left是第一个不满足的答案 left-1就是满足的最大的答案
*/


// b. 找大的里面的最小值（找的思路是找到符合的第一个 其实就是找下界）

// 二分模版
/*
	int left = 0,right = k+1;
	while(left<right){
		int mid = left+(right-left)/2;
		if(check(mid))right = mid;
		else left = mid+1;
	}
	cout<<left;
*/



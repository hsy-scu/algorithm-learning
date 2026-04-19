#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

// 高精度加法
//int a[505]=0, b[505]=0, c[505]=0;
//int main()
//{
//	string x, y;
//	cin >> x >> y;
//	int la = x.size();
//	int lb = y.size();
//	int lc = max(la, lb);
//	for (int i = 0; i < la; i++)
//		a[la - i - 1] = x[i] - '0';
//	for (int i = 0; i < lb; i++)
//		b[lb - i - 1] = y[i] - '0';
//	for (int i = 0; i < lc; i++)
//	{
//		c[i] += a[i] + b[i];
//		c[i + 1] = c[i] / 10;
//		c[i] = c[i] % 10;
//	}
//	if (c[lc] > 0) lc++;   
//	for (int i = lc-1; i >= 0; i--)
//	{
//		cout << c[i];
//	}
//	return 0;
//}

// 高精度减法
//int a1[500] = { 0 }, a2[500] = { 0 }, a3[500] = { 0 };
//int main()
//{
//	string x, y;
//	cin >> x >> y;
//	int lx = x.size();
//	int ly = y.size();
//	if (lx < ly || (lx == ly && x < y))
//	{
//		printf("-");
//		swap(x, y);
//		swap(lx, ly);
//	}
//	for (int i = 0; i < lx; i++)
//		a1[i] = x[lx - i - 1] - '0';
//	for (int i = 0; i < ly; i++)
//		a2[i] = y[ly - i - 1] - '0';
//	for (int i = 0; i < lx; i++)
//	{
//		if (a1[i] < a2[i])
//		{
//			a1[i] += 10;
//			a1[i + 1] -= 1;
//		}
//		a3[i] = a1[i] - a2[i];
//	}
//	int index = 0;
//	for (int i = lx-1; i >= 0; i--)
//	{
//		if (a3[i] != 0)
//		{
//			index = i;
//			break;
//		}
//	}
//	for (int i = index; i >= 0; i--)
//	{
//		cout << a3[i];
//	}
//	return 0;
//}



// 高精度*低精度
//int a1[500] = { 0 };
//int main()
//{
//	string x;
//	int y;
//	cin >> x >>y ;
//	for (int i = 0; i < x.size(); i++)
//		a1[i] = x[x.size() - i - 1] - '0';
//	for (int i = 0; i < x.size(); i++)
//		a1[i] *= y;
//	for (int i = 0; i < x.size() + 4; i++)
//	{
//		if (a1[i] >= 10)
//		{
//			a1[i + 1] += a1[i] / 10;
//			a1[i] %= 10;
//		}
//	}
//	int index = 0;
//	for (int i = x.size() + 4; i >= 0; i--)
//	{
//		if (a1[i] != 0)
//		{
//			index = i;
//			break;
//		}
//	}
//	for (int i = index; i >= 0; i--)
//	{
//		cout << a1[i];
//	}
//	return 0;
//}


// 高精度*高精度
//int a1[500] = { 0 }, a2[500] = { 0 }, a3[1000] = { 0 };
//int main()
//{
//	string x, y;
//	cin >> x >> y;
//	for (int i = 0; i < x.size(); i++)
//		a1[i] = x[x.size() - 1 - i] - '0';
//	for (int i = 0; i < y.size(); i++)
//		a2[i] = y[y.size() - 1 - i] - '0';
//	for (int i = 0; i < y.size(); i++)
//	{
//		for (int j = 0; j < y.size(); j++)
//		{
//			a3[j + i] += a1[j] * a2[i];
//			if (a3[j + i] >= 10)
//			{
//				a3[j + i + 1] += a3[j + i] / 10;
//				a3[j + i] %= 10;
//			}
//		}
//	}
//	int index = 0;
//	for (int i = x.size() + y.size() - 1; i >= 0; i--)
//	{
//		if (a3[i] != 0)
//		{
//			index = i;
//			break;
//		}
//	}
//	for (int i = index; i >= 0; i--)
//	{
//		cout << a3[i];
//	}
//	return 0;
//}


// 单精度/单精度 商是高精度数
//int main()
//{
//	int a = 0, b = 0, n;
//	cin >> a >> b >> n;
//	cout << a / b << '.';
//	int t = a % b;
//	for (int i = 0; i < n; i++)
//	{
//		t *= 10;
//		cout << t / b;
//		t %= b;
//	}
//	return 0;
//}

// 高精度/单精度 求整取余
//int main() {
//	int a[250] = { 0 };
//	int ans[250] = { 0 };
//	string s;
//	int b;
//	cin >> s >> b;
//	int n = s.size();
//	for (int i = 0; i < n; i++) {
//		a[i] = s[i]-'0';  
//	}
// 
// 
// 
//  关键处理
//	int t = 0;  // 存储余数
//	for (int i = 0; i < n; i++) {
//		t = t * 10 + a[i];  //余数更新为被除数
//		if (t >= b) {
//			ans[i] = t / b;
//			t %= b;
//		}
//		else {
//			ans[i] = 0;
//		}
//	}
//
// 
// 
//	return 0;
//}


// 高精度/高精度
//void cpy(int b[], int t[], int offset) {
//	for (int i = 1; i <= b[0]; i++) {
//		t[i + offset] = b[i];
//	}
//	t[0] = b[0] + offset;
//}
//
//bool comp(int a[], int t[]) {
//	if (a[0] != t[0])return a[0] > t[0];
//	for (int i = 1; i <= a[0]; i++) {
//		if (a[i] != t[i]) {
//			return a[i] > t[i];
//		}
//	}
//	return true;
//}
//
//void sub(int a[], int t[]) {
//	for (int i = a[0]; i >= 1; i--) {
//		if (a[i] < t[i]) {
//			a[i] += 10;
//			a[i - 1]--;
//		}
//		a[i] -= t[i];
//	}
//}
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	if (s1 == "0"||s1.size()<s2.size()) {
//		cout << 0;
//		return 0;
//	}
//	int a[250] = { 0 }, b[250] = { 0 }, c[250] = { 0 };
//	a[0] = s1.size(), b[0] = s2.size();
//	c[0] = a[0] - b[0] + 1;
//	for (int i = 1; i <= a[0]; i++) {
//		a[i] = s1[i - 1] - '0';
//	}
//	for (int i = 1; i <= b[0]; i++) {
//		b[i] = s2[i - 1] - '0';
//	}
//	int t[500] = { 0 };
//	for (int i = 1; i <= c[0]; i++) {
//		memset(t, 0, sizeof(t));  // 每次复制b到t内都需要先清空
//		cpy(b, t, i - 1);         // 将b复制到t内 并添加偏移量
//		a[0] = t[0];              // 将需要取出的a数组里面的数和t数组里面的一样大 
//		while (comp(a, t)) {      // a数组取出来的数大于t数组里面的数才要相减
//			sub(a, t);            // 将相减结果存储在a数组原位
//			c[i]++;               // 将相减次数保存在结果数组中
//		}
//	}
//	int index = 1;
//	for (int i = 1; i <= c[0]; i++) {
//		if (c[i] != 0) {
//			index = i;
//			break;
//		}
//	}
//	for (int i = index; i <= c[0]; i++) {
//		cout << c[i];
//	}
//	return 0;
//}



//string a, b;
//int aq[250], bq[250],ansq[250];
//int main() {
//	cin >> a >> b;
//	string a1 = a,b1 = b;
//	reverse(a1.begin(), a1.end());
//	reverse(b1.begin(), b1.end());
//	for (int i = 0; i < a1.size(); i++)aq[i] = a1[i]-'0';
//	for (int i = 0; i < b1.size(); i++)bq[i] = b1[i] - '0';
//	int max1 = max(a1.size(), b1.size());   // max1 相当于结果的位数
//	for (int i = 0; i < max1; i++) {
//		ansq[i] = aq[i] + bq[i];
//		ansq[i + 1] += ansq[i] / 10;
//		ansq[i] = ansq[i] % 10;
//	}
//	if (ansq[max1] > 0)max1++;
//	for (int i = max1; i >= 0; i--)cout << ansq[i];
//	return 0;
//}
//
//
//string a, b;
//int aq[250] = { 0 }, bq[250] = { 0 }, ansq[250] = {0};
//int main() {
//	string a, b; cin >> a >> b;
//	if (a < b || a.size() < b.size()){ 
//		swap(a, b); cout << '-';
//	}
//	string a1 = a,b1 = b;
//	reverse(a1.begin(), a1.end());
//	reverse(b1.begin(), b1.end());
//	for (int i = 0; i < a1.size(); i++)aq[i] = a1[i]-'0';
//	for (int i = 0; i < b1.size(); i++)bq[i] = b1[i] - '0';
//	int maxn = max(a1.size(), b1.size());
//	for (int i = 0; i < maxn; i++) {
//		if (aq[i] >= bq[i])ansq[i] = aq[i] - bq[i];
//		else {
//			aq[i + 1]--;
//			aq[i] += 10;
//			ansq[i] = aq[i] - bq[i];
//		}
//	}
//	while(ansq[maxn-1] == 0)maxn--;
//	for (int i = maxn - 1; i >= 0; i--)cout << ansq[i];
//	return 0;
//}
/*
const int N = 10010;
int a[N], b[N], c[N];
int lc;

void add() {
	for (int i = 0; i < lc; i++) {
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	if (c[lc])lc++;
}

int main() {
	string x, y;
	cin >> x >> y;
	lc = max(x.size(), y.size());
	for (int i = x.size() - 1; i >= 0; i--)a[x.size() - 1 - i] = x[i] - '0';
	for (int i = y.size() - 1; i >= 0; i--)b[y.size() - 1 - i] = y[i] - '0';
	add();
	return 0;
}
*/
/*
const int N = 10010;
int a[N] = { 1 }, b[N] = { 1 }, c[N] = { 1 }, lc = 1;

void add() {
	memset(c, 0, sizeof c);
	int jw = 0;
	for (int i = 0; i < lc; i++) {
		c[i] = a[i] + b[i] + jw;
		jw = c[i] / 10;
		c[i] %= 10;
	}
	if (jw > 0) {
		c[lc] = jw;
		lc++;
	}
	for (int i = 0; i < lc; i++) {
		a[i] = b[i];
		b[i] = c[i];
	}
}
*/
/*
const int N = 10010;
int a[N], b[N], c[N];
int lc;

bool cmp(string x, string y) {
	if (x.size() != y.size())return x.size() > y.size();
	for (int i = 0; i < x.size(); i++) {
		if (x[i] != y[i])return x[i] > y[i];
	}
	return true;
}

void sub() {
	for (int i = 0; i < lc; i++) {
		if (a[i] < b[i]) {
			// 向前找可以借位的位置
			int j = i + 1;
			while (j < lc && a[j] == 0) {
				a[j] = 9;  // 中间位变成9
				j++;
			}
			if (j < lc) {
				a[j]--;  // 最终借位位减1
				a[i] += 10;  // 当前位加10
			}
		}
		c[i] = a[i] - b[i];
	}
	while (lc>1 && c[lc-1] == 0)lc--;
	for (int i = lc-1; i >= 0; i--)cout << c[i];
}

int main() {
	string x, y;
	cin >> x >> y;
	if (!cmp(x, y)){
		swap(x, y);
		cout << '-';
	}
	lc = max(x.size(), y.size());
	for (int i = x.size()-1; i >= 0; i--) {
		a[x.size() - 1 - i] = x[i] - '0';
	}
	for (int j = y.size()-1; j >= 0; j--) {
		b[y.size() - 1 - j] = y[j] - '0';
	}
	sub();
	return 0;
}
*/
/*
const int N = 10010;
int a[N], b[N], c[N];
int lc;

void add() {
	for (int i = 0; i < lc; i++) {
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	if (c[lc] > 0)lc++;
}
int main() {
	string x, y;
	cin >> x >> y;
	lc = max(x.size(), y.size());
	for (int i = x.size() - 1; i >= 0; i--)a[x.size() - i - 1] = x[i] - '0';
	for (int i = y.size() - 1; i >= 0; i--)b[y.size() - i - 1] = y[i] - '0';
	add();
	return 0;
}
*/
/*
const int N = 10010;
int a[N], b[N], c[N], lc;

bool cmp(string x, string y) {
	if (x.size() > y.size())return true;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] < y[i])return false;
		else return true;
	}
	return true;
}

void sub() {
	for (int i = 0; i < lc; i++) {
		if (a[i] < b[i]) {
			int j = i + 1;
			while (j < lc && a[j] == 0) {
				a[j] = 9;
				j++;
			}
			if (j < lc) {
				a[i] += 10;
				a[j]--;
			}
		}
		c[i] = a[i]-b[i];
	}
	while (lc > 1 && c[lc - 1] == 0)lc--;
}

int main() {
	string x, y;
	cin >> x >> y;
	lc = max(x.size(), y.size());
	if (!cmp(x, y)) {
		swap(x, y);
		cout << '-';
	}
	for (int i = x.size() - 1; i >= 0; i--)a[x.size() - i - 1] = x[i] - '0';
	for (int i = y.size() - 1; i >= 0; i--)b[y.size() - i - 1] = y[i] - '0';
	sub();
	return 0;
}
*/
/*
const int N = 10010;
int a[N], b[N], c[N];
int la, lb, lc;

void mul() {
	for (int i = 0; i < la; i++) {
		for (int j = 0; j < lb; j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	for (int i = 0; i < lc; i++) {
		if (c[i] >= 10) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	while (c[lc] > 0) {
		c[lc + 1] = c[lc] / 10;
		c[lc] %= 10;
		lc++;
	}
	while (lc>1  && c[lc-1] == 0)lc--;
}

int main() {
	string x, y;
	cin >> x >> y;
	la = x.size(); lb = y.size(); lc = la + lb;
	for (int i = la - 1; i >= 0; i--)a[la - i - 1] = x[i] - '0';
	for (int i = lb - 1; i >= 0; i--)b[lb - i - 1] = y[i] - '0';
	mul();
	return 0;
}
*/


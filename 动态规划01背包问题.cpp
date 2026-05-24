#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<utility>
using namespace std;

// һ.�������� 01��������
// ��n����Ʒ ÿ����Ʒ�ж�Ӧ�������ͼ�ֵ ��������ܳ�������w�Ķ��� Ҫ�������װ���ܼ�ֵ����Ƕ���
// ��ά���� dp[n][w] ��ʾ��������Ϊwʱ��ǰn����Ʒ������ѡ��

//int n, w;
//vector<pair<int, int>> vawe;
//vector<vector<int>> dp;
//
//int main() {
//	cin >> n >> w;
//	dp.resize(n + 1, vector<int>(w + 1, 0));
//	vawe.resize(n + 1, { 0,0 });
//	for (int i = 1; i <= n; i++) {
//		cin >> vawe[i].first >> vawe[i].second;
//	}
//	for (int i = 1; i <= n; i++) {    // ����ÿһ����Ʒ 
//		for (int j = 0; j <= w; j++) {   // ����ÿһ����������
//			if (j < vawe[i].second)dp[i][j] = dp[i - 1][j];
//			else {
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vawe[i].second] + vawe[i].first);
//			}
//		}
//	}
//	cout << dp[n][w];
//	return 0;
//}


// ��.01 �����������⣨n����Ʒ һ������ ��������v �ɳ�������w ÿ����Ʒ����w[i] ���v[i] ��ֵva[i] �󱳰��ܷ��µĶ���������ֵ��
// �о���ʵ��һ����
// 
// ��̬�滮DP
//int n, v, w;
//vector<pair<pair<int, int>, int>> item;   // ���� ��� ��ֵ
//vector<vector<vector<int>>> dp;
//
//int main() {
//	cin >> n >> v >> w;
//
//	item.resize(n + 1, { {0,0},0 });
//	dp.resize(n + 1, vector<vector<int>>(v + 1, vector<int>(w + 1, 0)));  
//	// ����01�����ĳ�ʼ�� ÿ��������Ҫ��ʼ����1
//	// n��ʼ����1����Ϊ nΪ0ʱ�ı���Ӧ�õ���һ�� ��Ϊ������õ�i-1������� n=1��n=0������� 
//	// v��w��ʼ����1����Ϊ dp������õ�v��w 
//
//	for (int i = 1; i <= n; i++) {
//		cin >> item[i].first.first >> item[i].first.second >> item[i].second;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int v1 = 0; v1 <= v; v1++) {
//			for (int w1 = 0; w1 <= w; w1++) {
//				dp[i][v1][w1] = dp[i - 1][v1][w1];
//				if (w1 >= item[i].first.first && v1 >= item[i].first.second) {
//					dp[i][v1][w1] = max(dp[i - 1][v1][w1], dp[i - 1][v1 - item[i].first.second][w1 - item[i].first.first] + item[i].second);
//				}
//			}
//		}
//	}
//	cout << dp[n][v][w];
//	return 0;
//}


//  ���仯����dfs   
// ���仯�����ݹ��Ǵ������ϲ����� �����µ� �����Ϲ���� ���dfs������x+1 ������ʵ�ǹ鵽ans=dfs(1,v,w) ���ǣ�1��v, w������ط��� ����vw��ʾʣ���v��w
// ��һ���붯̬�滮��ͬ ��̬�滮ֱ�Ӵӿ�ʼ�ߵ���� �ߵ���n,v,w������ط� ����v��w��ʾԭ�������� ����ʣ����

//int n, v, w;
//vector<pair<pair<int, int>, int>> item;   // ���� ��� ��ֵ
//vector<vector<vector<int>>> memo;
//
//int dfs(int x, int spv, int spw) {
//	if (x > n)return 0;
//	if (memo[x][spv][spw])return memo[x][spv][spw];
//	int sum = 0;
//	if (spv < item[x].first.second || spw < item[x].first.first) {
//		sum = dfs(x + 1, spv, spw);
//	}
//	else if (spv >= item[x].first.second && spw >= item[x].first.first) {
//		sum = max(dfs(x + 1, spv, spw), dfs(x + 1, spv - item[x].first.second, spw - item[x].first.first) + item[x].second);
//	}
//	memo[x][spv][spw] = sum;
//	return sum;
//}
//
//int main() {
//	cin >> n >> v >> w;
//
//	item.resize(n + 1, { {0,0},0 });
//	memo.resize(n + 1, vector<vector<int>>(v + 1, vector<int>(w + 1, 0)));  
//
//	for (int i = 1; i <= n; i++) {
//		cin >> item[i].first.first >> item[i].first.second >> item[i].second;
//	}
//
//	int ans = dfs(1, v, w);
//	cout << ans;
//	return 0;
//}




// ��.��ȫ�������⣨��01������һ������ 01��������Ķ���ֻ��ѡһ�� ��ȫ�����������ÿһ����������������ѡ��
//  n����Ʒ һ������ ��������w  ÿ����Ʒ��ֵv[i] ����w[i] ������ֵѡ��

// ���仯����dfs
//int n, w;
//vector<pair<int, int>> item;
//vector<vector<int>> memo;
//
//int dfs(int x, int spw) {
//	if (x > n)return 0;
//	if (memo[x][spw])return memo[x][spw];
//	int sum = 0;
//	if (spw < item[x].first) {
//		sum = dfs(x + 1, spw);
//	}
//	else {
//		sum = max(dfs(x + 1, spw), dfs(x, spw + item[x].first) + item[x].second);
//		// ��ô��ʾ���ѡ���޴��� ��ʵ���Ƿ�������� һ�������һ��Ҳ��ѡ  �ڶ��������ѡ��֮��x��++ ������һ�λ��������Ʒ ��ʵ�������޴�ѡ
//	}
//	memo[x][spw] = sum;
//	return sum;
//}
//
//int main() {
//	cin >> n >> w;
//	item.resize(n + 1, { 0,0 });
//	memo.resize(n + 1, vector<int>(w + 1));
//	for (int i = 1; i <= n; i++) {
//		cin >> item[i].first >> item[i].second;
//	}
//	int ans = dfs(1, w);
//	cout << ans;
//	return 0;
//}


// ��̬�滮DP
//int n, w;
//vector<pair<int, int>> item;  // ���� ��ֵ
//vector<vector<int>> dp;
//
//int main() {
//	cin >> n >> w;
//	item.resize(n + 1, { 0,0 });
//	dp.resize(n + 1, vector<int>(w + 1, 0));
//	for (int i = 1; i <= n; i++) {
//		cin >> item[i].first >> item[i].second;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= w; j++) {
//			if (j < item[i].first) {
//				dp[i][j] = dp[i - 1][j];
//			}
//			else {
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - item[i].first] + item[i].second);
//			}
//		}
//	}
//	cout << dp[n][w];
//	return 0;
//}




// ��Ǯ�һ� ������n����� �Լ���Ǯ��c ����Դճ�c������ֽ������


// ���仯dfs
//int n, c;
//vector<int> coins;
//vector<int> memo;
//
//int dfs(int x) {
//	if (x == 0) return 0;
//	if (x < 0) return 1e9;
//	if (memo[x]) return memo[x];
//	int sum = 1e9;
//	for (int i = 1; i <= n; i++) {
//		if (x >= coins[i]) {
//			sum = min(sum, dfs(x - coins[i]) + 1);
//		}
//	}
//	memo[x] = sum;
//	return sum;  // ��һ��͵ݹ鷵�صľ��Ǵ� �� memo[c]
//}
//
//int main() {
//	cin >> n >> c;
//	coins.resize(n + 1, 0);
//	memo.resize(c+1, 0);
//	for (int i = 1; i <= n; i++) cin >> coins[i];
//	int ans = dfs(c);
//	int res = ans >= 1e9 ? -1 : ans;
//	cout << res;
//	return 0;
//}



// ��̬�滮
//int n,c;
//vector<int> coins;
//vector<int> dp;
//int main() {
//	cin >> n >> c;
//	coins.resize(n+1,0);
//	dp.resize(c+1,1e9);
//	dp[0] = 0;     // ��dp��ʼ�����������൱��dfs�����ǰ������return   ���dp[0]=0�����к�������ĸ���
//	for (int i = 1; i <= n; i++)  cin >> coins[i];
//
//	for (int i = 1; i <= c; i++) {
//		for (int j = 1; j <=n ; j++) {   // ö��ÿһ��Ӳ��
//			if (coins[j] <= i) {   // ��������� ��ѡ�� ���ڶ���ѡ�����ҵ���С��
//				dp[i] = min(dp[i], dp[i - coins[j]] + 1);    // ֻ���жϿ��Է� �����жϲ��ܷ� ���ܷŵĻ������Զ���1e9��
//			}
//		}
//	}
//	int ans = dp[c] >= 1e9 ? -1 : dp[c];
//	cout << ans;
//	return 0;
//}


// ��ȫ����д��(��ȫ����д����������ƷΪ��һ��ѭ�� Ȼ��������Ϊ�ڶ���ѭ��)
// int n, c;
// vector<int> dp;
// vector<int> num;

// int main() {
// 	cin >> n >> c;
// 	num.resize(n + 1, 0);
// 	dp.resize(c + 1, 1e9);
// 	dp[0] = 0;
// 	for (int i = 1; i <= n; i++) cin >> num[i];

// 	for (int i = 1; i <= n; i++) {   // ÿһ�����
// 		for (int j = num[i]; j <= c; j++) {   // ÿһ����Ǯ������
// 			dp[j] = min(dp[j], dp[j - num[i]] + 1);
// 		}
// 	}
// 	int ans = dp[c] >= 1e9 ? -1 : dp[c];
// 	cout << ans;
// 	return 0;
// }

// 01背包
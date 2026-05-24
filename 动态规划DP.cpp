#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<utility>
using namespace std;

// 动态规划其实是一种递推 最重要的就是要找到递推关系式
// 动态规划两大问： 最后一步是什么？   去掉最后一步（倒数第二步）问题变成了什么？ 是否存在一些递推关系？
// 一般dp数组存的就是答案


// 一.大盗阿福（n组数据 每组数据有一个店铺数m 然后有m个店铺的钱数 偷相邻两家会报警 求最多偷的钱数）


// dfs-->记忆化搜索-->逆序递推-->顺序递推-->空间优化

// 暴力dfs
//int n;
//
//void dfs(int& cnt,vector<int>& money,vector<bool>& memo,int m,int st,int& max1) {
//	for (int i = st; i < m; i++) {
//		if (cnt > max1)max1 = cnt;
//		if (memo[i])continue;
//		if (i - 1 >= 0 && memo[i - 1])continue;
//
//		memo[i] = true;
//		cnt += money[i];
//		dfs(cnt, money, memo, m, i,max1);
//		cnt -= money[i];
//		memo[i] = false;
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int m; cin >> m;
//		vector<int> money(m);
//		vector<bool>memo(m,false);
//		for (int i = 0; i < m; i++) {
//			cin >> money[i];
//		}
//		int cnt = 0;
//		int max1 = 0;
//		dfs(cnt,money,memo,m,0,max1);
//		cout << max1;
//	}
//	return 0;
//}


// 记忆化dfs
//int n, t;
//vector<int> num;
//vector<int> memo;
//
//int dfs(int x) {
//	int sum = 0;
//	if (x >= n)return 0;
//	if (memo[x])return memo[x];
//	else sum = max(dfs(x + 1), dfs(x + 2) + num[x]);  // 抢劫下一个（不抢劫这个） 或者 抢劫这一个和下两个
//	memo[x] = sum;
//	return sum;
//}
//
//int main() {
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		num.resize(n,0);
//		memo.resize(n,0);
//		for (int i = 0; i < n; i++) {
//			cin >> num[i];
//		}
//		int ans = dfs(0);
//		cout << ans << endl;
//		num.clear();
//		memo.clear();
//	}
//	return 0;
//}


// 线性DP(关键是找到状态转移方程)
// 递归的方法是先往下递 再往上归 归是产生答案的过程
//int n, t;
//vector<int> num;
//vector<int> memo;
//
//int main() {
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		num.resize(n, 0);
//		memo.resize(n, 0);
//		for (int i = 0; i < n; i++) {
//			cin >> num[i];
//		}
//
//		// 这个从下往上推的就别理解了 直接理解从上往下的DP就行
//		//  这个是从下往上推 memo[i]数组存的就是i—n可以偷盗的最大钱数 
//		//memo[n - 1] = num[n - 1];
//		//memo[n - 2] = max(num[n - 1], num[n - 2]);
//		//for (int i = n - 3; i >= 0; i--) {   // 从下往上归 直接产生答案
//		//	memo[i] = max(memo[i + 1], memo[i + 2] + num[i]);   // 这就是状态转移方程
//		//}
//		//cout << memo[0] << endl;   // memo[0]就是从第一个位置开始抢劫 抢劫的钱数最大值
//		
//
//
//		// memo[i] 存的是0-i可以偷盗的最大钱数
//		memo[0] = num[0];
//		memo[1] = max(num[0], num[1]);
//		for (int i = 0; i < n-2; i++) {
//			memo[i+2] = max(memo[i + 1], memo[i] + num[i+2]);  
//			// 这样是为了防止越界 实际上的原状态转移方程是
//			memo[i] = max(memo[i - 1], memo[i - 2] + num[i]);  // 这一位的钱数等于 max(上一次的钱也就是这一次不选 这一次的选并加上上两次的钱)
//		}
//		cout << memo[n - 1];
//		num.clear();
//		memo.clear();
//	}
//	return 0;
//}



// 空间优化版dp
//int n, t;
//vector<int> num;
//
//int main() {
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		num.resize(n,0);
//		for (int i = 0; i < n; i++) {
//			cin >> num[i];
//		}
//		int newf = 0, temp1 = 0, temp2 = 0;
//		for (int i = 0; i < n; i++) {
//			newf = max(temp1, temp2 + num[i]);  // 状态转移方程
//			temp2 = temp1;
//			temp1 = newf;
//		}
//		cout << newf << endl;
//		num.clear();
//	}
//	return 0;
//}




// 二.路径和最大 
// 记忆化dfs
//int n, m;
//vector<vector<int>> board;
//vector<vector<int>> memo;
//
//int dfs(int x1,int y1) {
//	if (x1 >= n || y1 >= n)return 0;   // 记忆化先写边界判断
//	if (memo[x1][y1])return memo[x1][y1];  // 再写直接返回
//	int sum = 0;   // 然后写间接返回
//	sum = max(dfs(x1 + 1, y1), dfs(x1 + 1, y1 + 1)) + board[x1][y1];
//	memo[x1][y1] = sum;
//	return sum;
//}
//
//int main() {
//	cin >> n;
//	memo.resize(n, vector<int>(n,0));
//	for (int i = 0; i < n; i++) {
//		vector<int>  row;
//		for (int j = 0; j <= i; j++) {
//			int x; cin >> x;
//			row.push_back(x);
//		}
//		board.push_back(row);
//		row.clear();
//	}
//	int max1 = dfs(0, 0);
//	cout << max1;
//	return 0;
//}


// 二维网格DP正推

//int n, m;
//vector<vector<int>> board;
//vector<vector<int>> memo;
//
//int main() {
//	cin >> n;
//	memo.resize(n, vector<int>(n,0));
//	board.resize(n, vector<int>(n, 0));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <= i; j++) {
//			cin >> board[i][j];
//		}
//	}
//	memo[0][0] = board[0][0];
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j <= i; j++) {
//			if (j - 1 >= 0)memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - 1]) + board[i][j];   // 这个就是状态转移方程
//  			else memo[i][j] = memo[i - 1][j] + board[i][j];  // 这个是特殊情况讨论
//		}
//	}
//	int res = 0;
//	for (int i = 0; i < n; i++) {   // 最后会得到一列的最大值 需要在这一列最大值里面找这个最大值
//		res = max(res, memo[n-1][i]);
//	}
//	cout << res;
//	return 0;
//}


// 三.不同路径 每次向下或者向右走一步 从左上走到右下
//int n, m;
//vector<vector<int>> num;
//vector<vector<int>> dp;
//
//int main() {
//	cin >> n >> m;
//	num.resize(n + 1, vector<int>(m + 1, 0));
//	dp.resize(n + 1, vector<int>(m + 1, 0));
//	for (int i = 1; i <= n; i++)dp[i][1] = 1;
//	for (int i = 1; i <= m; i++)dp[1][i] = 1;
//	for (int i = 2; i <= n; i++) {
//		for (int j = 2; j <= m; j++) {
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//		}
//	}
//	cout << dp[n][m];
//	return 0;
//}



// 四.经典问题 01背包问题
// 有n件物品 每件物品有对应的重量和价值 背包最多能承受总重w的东西 要求求出能装的总价值最大是多少

// 暴力dfs
//int n;
//int w; int zj = 0;
//vector<pair<int,int>> vawe;
//
//void dfs(int w, int value, int step) {
//
//	if (step == n) {
//		zj = max(value, zj);
//		return;
//	}
//
//	// 因为不能选所以不选
//	if(w<vawe[step].second)dfs(w, value, step + 1);
//
//	// 能选的情况 （要不要选）
//	if (w >= vawe[step].second) {
//		// 不选
//		dfs(w, value, step + 1);
//		// 选
//		dfs(w - vawe[step].second, value + vawe[step].first, step + 1);
//	}
//}
//
//int main() {
//	cin >> n >> w;
//	for (int i = 0; i < n; i++) {
//		pair<int, int> t;
//		cin >> t.first >> t.second;
//		vawe.push_back(t);
//	}
//	dfs(w,0,0);
//	cout << zj;
//}


// 记忆化搜索dfs

//int n;
//int w; 
//vector<pair<int,int>> vawe;
//vector<vector<int>> memo;
//// memo[n][spw] 表示算到从n到最后 剩余重量spw 时 的最大价值 实际上是一种倒推
//   这个思路是直接一直往下递 然后递到最下面 开始往上归 产生答案  
//// 这是用二维网格来实现记忆化操作

//int dfs(int step,int spw) {
//	int sum = 0;
//
//	if (step >= n)return 0;   // 要先判断 return 0 再判断返回原值的情况  不然会越界
//	
//	if (memo[step][spw]) return memo[step][spw];
//	// 当spw不够时只能不选
//	else if (spw < vawe[step].second)sum = dfs(step + 1, spw);
//	// 够的时候可以选可以不选  其中最大值就是这个memo需要存储的
//	else if (spw >= vawe[step].second)sum = max(dfs(step + 1, spw), dfs(step + 1, spw - vawe[step].second) + vawe[step].first);
//	memo[step][spw] = sum; 
//	return sum;
//}
//
//int main() {
//	cin >> n >> w;
//	memo.resize(n, vector<int>(w+1,0));
//	for (int i = 0; i < n; i++) {
//		pair<int, int> t;
//		cin >> t.first >> t.second;
//		vawe.push_back(t);
//	}
//	int ans = dfs(0, w);
//	cout << ans;
//}


// 动态规划DP（动态规划是顺着来 从开始到最后 一直往下慢慢整）
// dp[i][j] 表示当考虑到第i个物品 背包容量为j时的最佳组合

//int n;
//int w; 
//vector<pair<int,int>> vawe;
//vector<vector<int>> memo;
//
//int main() {
//	cin >> n >> w;
//	memo.resize(n+1, vector<int>(w + 1, 0));
//	vawe.push_back({ 0, 0 });
//	for (int i = 1; i <= n; i++) {
//		pair<int, int> t;
//		cin >> t.first >> t.second;
//		vawe.push_back(t);
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= w; j++) {
//			if (j < vawe[i].second) {
//				memo[i][j] = memo[i - 1][j];
//			}
//			else {
//				memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - vawe[i].second] + vawe[i].first);   // 前面那个是不选 后面那个是选
//				// 不选的话 该点的值为 上一个物品同一个背包容量的最佳组合
//				// 选的话   该点的值为 上一个物品并且预留够这一个物品的背包容量的最佳选择 并加上这一点的物品价值 
//			}
//		}
//	}
//	cout << memo[n][w];
//	return 0;
//}

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
//	for (int i = 1; i <= n; i++) {    // 遍历每一个物品 
//		for (int j = 0; j <= w; j++) {   // 遍历每一个背包容量
//			if (j < vawe[i].second)dp[i][j] = dp[i - 1][j];
//			else {
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vawe[i].second] + vawe[i].first);
//			}
//		}
//	}
//	cout << dp[n][w];
//	return 0;
//}


// 五.求爬楼梯最小花费（可以选择从第0层或者第1层开始上 每一层上1步或者2步 求上到顶层n的最小花费）
// 注意是爬到第n层 不是n-1层
// 

// 记忆化dfs
//int n;
//vector<int> cost;
//vector<int> memo;
//
//int dfs(int x) {
//	if (x == 0 || x == 1)return 0;
//	if (memo[x])return memo[x];
//	int sum;
//	sum = min(dfs(x - 1) + cost[x - 1], dfs(x - 2) + cost[x - 2]);
//	memo[x] = sum;
//	return sum;
//}
//
//int main() {
//	cin >> n;
//	cost.resize(n,0);
//	memo.resize(n+1,0);
//	for (int i = 0; i < n; i++) {
//		cin >> cost[i];
//	}
//	int ans = dfs(n);
//	cout << ans;
//	return 0;
//}


// 动态规划DP (其实就是找了一个递推关系)
//int n;
//vector<int> cost;
//vector<int> dp;
//
//int main() {
//	cin >> n;
//	cost.resize(n, 0);
//	dp.resize(n + 1, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> cost[i];
//	}
//	for (int i = 2; i <= n; i++) {
//		dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//	}
//	cout << dp[n];
//	return 0;
//}



// 六.经典问题——最长递增子序列
// 就是在一个数组中找到递增最长的子序列长度 
// 子序列和子数组不一样 子数组必须连续 子序列可以跳开

// 记忆化dfs
//int n;
//vector<int> num;
//vector<int> memo;
//
//int dfs(int x) {
//	int ans = 1;
//	if (memo[x])return memo[x];
//	for (int i = 0; i < x; i++) {
//		if (num[i] < num[x]) {
//			ans = max(dfs(i) + 1, ans);
//		}
//	}
//	memo[x] = ans;
//	return ans;
//}
//
//int main() {
//	cin >> n;
//	num.resize(n);
//	memo.resize(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> num[i];
//	}
//	int res = 0;
//	for (int i = 0; i < n; i++) {
//		res = max(res, dfs(i));
//	}
//	cout << res;
//	return 0;
//}


// 动态规划Dp

//int n;
//vector<int> num;
//vector<int> dp;
//int max1 = 0;
//
//int main() {
//	cin >> n;
//	num.resize(n, 0);
//	dp.resize(n, 1);
//	for (int i = 0; i < n; i++)cin >> num[i];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < i; j++) {
//			if (num[j] < num[i]) {
//				dp[i] = max(dp[i], dp[j] + 1);
//				max1 = max(dp[i], max1);
//			}
//		}
//	}
//	cout << max1;
//	return 0;
//}




// 七.零钱兑换 （给出n个面额 以及总钱数c 求可以凑出c的最少纸币数）（其实可以看做是一个完全背包问题）

 //记忆化dfs
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
//	return sum;  // 第一层就递归返回的就是答案 即 memo[c]
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



// 动态规划
//int n,c;
//vector<int> coins;
//vector<int> dp;
//int main() {
//	cin >> n >> c;
//	coins.resize(n+1,0);
//	dp.resize(c+1,1e9);
//	dp[0] = 0;     // 对dp初始化这两步就相当于dfs里面的前两步的return   这个dp[0]=0是所有后续计算的根基
//	for (int i = 1; i <= n; i++)  cin >> coins[i];
//
//	for (int i = 1; i <= c; i++) {
//		for (int j = 1; j <=n ; j++) {   // 枚举每一个硬币
//			if (coins[j] <= i) {   // 如果可以有 就选择 并在多种选择中找到最小的
//				dp[i] = min(dp[i], dp[i - coins[j]] + 1);    // 只用判断可以放 不用判断不能放 不能放的话它就自动是1e9了
//			}
//		}
//	}
//	int ans = dp[c] >= 1e9 ? -1 : dp[c];
//	cout << ans;
//	return 0;
//}


// 八.连续子数组的最大和

// 记忆化dfs
//int n;
//vector<int> num;
//vector<int> memo;
//
//int dfs(int x) {
//	if (x < 0)return 0;
//	if (memo[x] != -1)return memo[x];
//	int sum = max(num[x], dfs(x - 1) + num[x]);
//	memo[x] = sum;
//	return sum;
//}
//
//
//int main() {
//	cin >> n;
//	num.resize(n);
//	memo.resize(n,-1);
//	int sum = -101;
//	for (int i = 0; i < n; i++)cin >> num[i];
//	for (int i = 0; i < n; i++) {
//		sum = max(sum, dfs(i));
//	}
//	cout << sum;
//	return 0;
//}


// 动态规划DP
//int n;
//vector<int> num;
//vector<int> dp;
//int res = -101;
//
//int main() {
//	cin >> n;
//	num.resize(n);
//	dp.resize(n, 0);
//	for (int i = 0; i < n; i++) cin >> num[i];
//	dp[0] = num[0];
//
//	for (int i = 1; i < n; i++) {
//		dp[i] = max(num[i], num[i] + dp[i - 1]);
//		res = max(res, dp[i]);
//	}
//	cout << res;
//	return 0;
//}


// 九.整数以和拆分 求乘积最大(n>=2)


// 记忆化搜索dfs
//int n;
//vector<int> memo;
//
//int dfs(int x) {
//	if (x == 2)return 1;
//	if (memo[x] != -1) return memo[x];
//	int sum = 0;
//	for (int i = 1; i < x; i++) {
//		sum = max(max(dfs(x - i) * i, (x - i) * i), sum);
//	}
//	memo[x] = sum;
//	return sum;
//}
//
//int main() {
//	cin >> n;
//	memo.resize(n+1, -1);
//	int ans = dfs(n);
//	cout << ans;
//	return 0;
//}


// 动态规划
//int n;
//vector<int> dp;
//
//int main() {
//	cin >> n;
//	dp.resize(n + 1, 0);
//	dp[2] = 1;
//	for (int i = 3; i <= n; i++) {  // 被拆的数
//		for (int j = 1; j < i; j++) {   // 被拆成？
//			dp[i] = max(max(dp[i - j] * j, j * (i - j)), dp[i]); 
//		//  答案                要拆          不拆    在多种拆的方案中选最大          
//		}
//	}
//	cout << dp[n];
//	return 0;
//}


// 十.区间DP
// (典例)石子合并
//问题：有n堆石子排成一排，每次只能合并相邻的两堆，合并的代价为两堆石子的数量之和。求将所有石子合并成一堆的最小总代价。
// 跟那个贪心不一样 这个只能合并相邻两个



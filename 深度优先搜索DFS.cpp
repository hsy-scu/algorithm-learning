#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 深度优先搜索的关键是解决这一步应该怎么做 下一步只是参数不同
// “一条路走到底，不撞南墙不回头”
 
// 深度优先搜索基本模型
// void dfs(int step) {
//   特殊情况处理（可以直接return的情况）
//
//	 枚举每一种可能
//	 for (int i = 1; i <= n; i++) {  （这一步一般是step每一步的赋值范围）
//		这一种情况的操作方法  （一般就是给step这一步对应的东西赋值）
//		递归下一步   （dfs(step+1)）
//		回溯这一步  （把赋给step这一步的值搞掉）
//	} 
//}

//  DFS主要有三种：指数型枚举 排列型枚举 组合型枚举


// 基础问题 全排列问题
// 也用到了记录数组memo  如果num数组是任意几个数的全排列需要再存一个result数组保存每次的结果
//int n;
//void dfs(int step,vector<int>& num,vector<int>& memo) {
//	if (step == n+1) {
//		for (int i = 1; i <= n;i++) {
//			cout << num[i] << ' ';
//		}
//		cout << endl;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (memo[i] == 0) {
//			num[step] = i;
//			memo[i] = 1;
//			dfs(step + 1, num, memo);
//			memo[i] = 0;
//		}
//	}
//}
//int main() {
//	cin >> n;
//	vector<int> num(n+1);
//	vector<int> memo(n+1,0);
//	dfs(1,num,memo);
//	return 0;
//}

// 基础问题 组合问题
//   一. 遍历化搜索
//vector<int> row;
//void dfs(int st, int k, vector<int>& num) {
//	if (row.size() == k) {
//		for (auto& m : row) {
//			cout << m << ' ';
//		}
//		cout << endl; return;
//	}
//	else {
//		for (int i = st; i < num.size(); i++) {
//			row.push_back(num[i]);
//			dfs(i + 1, k, num);
//			row.pop_back();
//		}
//	}
//}
//int main() {
//	vector<int> num = { 1,4,5,8 };
//	int k; cin >> k;
//	dfs(0,k,num);
//	return 0;
//}

// 二. 选择式搜索
//vector<int> row;
//void dfs(int step, int k, vector<int>& num) {
//	if (step == num.size() && row.size()==k) {
//		for (auto& m : row) {
//			cout << m << ' ';
//		}
//		cout << endl; return;
//	}
//	if (step >= num.size())return;
//	// 选择该数
//	row.push_back(num[step]);
//	dfs(step+1, k, num);
//	row.pop_back();
//	// 不选择该数
//	dfs(step+1, k, num);
//}
//int main() {
//	vector<int> num = { 1,4,5,8 };
//	int k; cin >> k;
//	dfs(0,k,num);
//	return 0;
//}



// 经典问题 数楼梯
//int n;
//int dfs(int n) {
//	if (n == 1)return 1;
//	else if (n == 2)return 2;
//	else return dfs(n - 1) + dfs(n - 2);
//}
//int main() {
//	cin >> n;
//	cout<< dfs(n);
//	return 0;
//}

// 暴力递归dfs 炒鸡耗时 一种优化方法是——记忆化搜索
// 所谓记忆化搜索 就是把已经算过的记录下来 避免重复计算（也是一种剪枝）

//int n;
//int memo[100];
//int dfs(int n) {
//	if (memo[n]) return memo[n];  // 记忆化搜索
//	if (n == 1)memo[n] = 1;
//	else if (n == 2)memo[n] = 2;
//	else memo[n] = dfs(n - 1) + dfs(n - 2);
//	return memo[n];
//}
//int main() {
//	cin >> n;
//	cout << dfs(n);
//	return 0;
//}


// 洛谷p2089烤鸡  // 指数型枚举 选1选2还是选3
//int arr[11] = { 0 }; int he = 0;
//void dfs(int num,int st) {
//	if (he == num && st==11) {
//		for (int i = 1; i <= 10; i++) {
//			cout << arr[i] << ' ';
//		}cout << endl;
//		return;
//	}
//	if (st >= 11)return;
//
//	// 选1
//	arr[st] = 1; he += 1;
//	dfs(num, st + 1);
//	he -= 1;
//	arr[st] = 0;
//	// 选2
//	arr[st] = 2; he += 2;
//	dfs(num, st + 1);
//	he -= 2;
//	arr[st] = 0;
//	// 选3
//	arr[st] = 3; he += 3;
//	dfs(num, st + 1);
//	he -= 3;
//	arr[st] = 0;
// 
//  其实这里的选或者不选也可以用循环来写 都一样的
//  for(int i = 1;i<=3;i++){
//		arr[st] = i;he+=i;
//		dfs(num,st+1);
//		he-=i;arr[st]=0;
// }
//int main() {
//	int n; cin >> n;
//	if (n > 30)cout << 0;
//	else {
//		dfs(n,1);
//	}
//	return 0;
//}



// 洛谷p1088 火星人
//int n, k; int count1 = 0;
//vector<int> row;
//vector<int> num;
//vector<int> memo;
//void dfs(int st) {
//	if (st == n+1) {
//		count1++;
//		if (count1 == k + 1)
//		{
//			for (int i = 1; i <= n ; i++) {
//				cout << row[i] << ' ';
//			}
//			exit(0);
//		}
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!count1) {
//			i = num[st];
//		}
//		if (memo[i] == 0) {
//			row[st] = i;
//			memo[i] = 1;
//			dfs(st + 1);
//			row[st] = 0;
//			memo[i] = 0;
//		}
//	}
//}
//int main() {
//	cin >> n >> k;
//	row.resize(n + 1, 0);   // 以后用这种方法写 可以避免传参传数组看起来很麻烦
//	num.resize(n + 1);
//	memo.resize(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> num[i];
//	}
//	dfs(1);
//	return 0;
//}


// 洛谷p1149 火柴棒等式  排列型（我就是要选够三个）
//int arr[10010] = { 6,2,5,5,4,5,6,3,7,6 };
//int num[4];
//int count1 = 0; int n;
//void dfs(int x, int sum) {
//    if (sum > n)return;
//    if (x > 3) {
//        if (num[1] + num[2] == num[3] && sum == n) {
//            count1++;
//        }
//        return;
//    }
//    for (int i = 0; i <= 1000; i++) {
//        num[x] = i;
//        dfs(x + 1, sum + arr[i]);
//        num[x] = 0;
//    }
//}
//int main() {
//    scanf("%d", &n);
//    n -= 4;
//    for (int i = 10; i <= 1000; i++) {
//        arr[i] = arr[i % 10] + arr[i / 10];
//    }
//    dfs(1, 0);
//    printf("%d", count1);
//    return 0;
//}


// 洛谷p2036 PERKET 组合/指数型搜索 
// 一. 指数型搜索——依次选
//int n;
//vector<vector<int>>num;
//int min1 = 1000000000;
//void dfs(int x, int sd, int kd, int count) {
//	if (abs(sd - kd) <= min1 && count != 0) {
//		min1 = abs(sd - kd);
//	}    // 需要的目标 每次选完都比较一次 个数不确定
// 	if (x == n)return;  // 函数出口
//	for (int i = x; i < n; i++) {
//		sd *= num[i][0];
//		kd += num[i][1];
//		dfs(i + 1, sd, kd, count + 1);
//		sd /= num[i][0];
//		kd -= num[i][1];
//	}
//}
//// 指数型和排列型最本质的区别是 for循环里是（全循环）还是从（开始位置循环） 因此全排列类型需要一个memo记忆 另一个注意点是递归的出口并不一样 
//// 组合型和指数型的区别是 需要的元素个数不同 因此组合型可以以元素个数为出口 指数型只能先写一个目标 再以全元素个数为出口 当然指数型也可以写成选/不选的形式
//int main() {
//	cin >> n;
//	num.resize(n, vector<int>(2));
//	for (int i = 0; i < n; i++) {
//		cin >> num[i][0] >> num[i][1];
//	}
//	dfs(0, 1, 0, 0);
//	cout << min1;
//	return 0;
//}
// 二.指数型搜索——选或者不选
//int n; int min1 = 1000000000;
//vector<vector<int>> num;
//void dfs(int step, int sd, int kd, int count) {
//	if (step == n) {
//		if (abs(sd - kd) <= min1 && count != 0) {
//			min1 = abs(sd - kd);
//		}
//		return;
//	}
//	// 选这种配料
//	dfs(step + 1, sd * num[step][0], kd + num[step][1], count + 1);
//	// 不选
//	dfs(step + 1, sd, kd, count);
//}
//int main() {
//	cin >> n;
//	num.resize(n, vector<int>(2));
//	for (int i = 0; i < n; i++) {
//		cin >> num[i][0] >> num[i][1];
//	}
//	if (n == 1)cout << abs(num[0][0] - num[0][1]);
//	else {
//		dfs(0, 1, 0, 0);
//		cout << min1;
//	}
//	return 0;
//}


//  洛谷P1683 入门  也是一个找连通块的问题
//#include<iostream>
//#include<vector>
//using namespace std;
//int w, h;
//int x, y; int count = 1;
//vector<string> path;
//vector<vector<bool>> memo;
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//void dfs(int x, int y) {
//    for (int i = 0; i < 4; i++) {
//        int a = x + dx[i]; int b = y + dy[i];
//        if (a < 0 || b < 0 || a >= h || b >= w)continue;
//        if (memo[a][b])continue;
//        if (path[a][b] != '.')continue;
//        memo[a][b] = true;
//        count++;
//        dfs(a, b);
//
//    }
//
//}
//int main() {
//    cin >> w >> h;
//    path.resize(h);
//    memo.resize(h, vector<bool>(w, false));
//    for (int i = 0; i < h; i++) {
//        cin >> path[i];
//        for (int j = 0; j < w; j++) {
//            if (path[i][j] == '@') {
//                x = i; y = j;
//            }
//        }
//    }
//    memo[x][y] = true;
//    dfs(x, y);
//    cout << count;
//    return 0;
//}


// 洪水灌溉问题——连通块问题
//#include<iostream>
//#include<vector>
//using namespace std;
//int n, m; int count = 0;
//vector<vector<bool>> memo;
//vector<string> path;
//int dx[] = { -1,-1,0,1,1,1,0,-1 };
//int dy[] = { 0,1,1,1,0,-1,-1,-1 };
//
//void dfs(int x, int y) {
//    for (int i = 0; i < 8; i++) {
//        int a = x + dx[i], b = y + dy[i];
//        if (a < 0 || b < 0 || a >= n || b >= m)continue;
//        if (memo[a][b])continue;
//        memo[a][b] = true;
//        dfs(a, b);
//    }
//}
//int main() {
//    cin >> n >> m;
//    path.resize(n);
//    memo.resize(n, vector<bool>(m, false));
//    for (int i = 0; i < n; i++) {
//        cin >> path[i];
//        for (int j = 0; j < m; j++) {
//            if (path[i][j] == '.')memo[i][j] = true;
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (memo[i][j])continue;
//            if (path[i][j] == 'W') {
//                dfs(i, j);
//                count++;
//            }
//        }
//    }
//    cout << count;
//    return 0;
//}

// 棋盘问题
//#include<iostream>
//#include<vector>
//using namespace std;
//int n, k;
//vector<string> board;
//vector<vector<bool>> memo;
//void dfs(int x, int count, int& ans) {    // 一定要引用传参 不然ans改不了一直是0
//	if (count == k) {
//		ans++;
//		return;
//	}
//	if (x >= n)return;   //  这里的return 一定要放对位置
//	// 选这一行
//	for (int i = 0; i < n; i++) {
//		if (board[x][i] == '#' && memo[x][i] == false) {
//			memo[x][i] = true;   // 记录该位置选过
//			for (int j = x + 1; j < n; j++) {    // 记录该列选过
//				if (board[j][i] == '#')memo[j][i] = true;
//			}
//			dfs(x + 1, count + 1, ans);
//			memo[x][i] = false;   // 回溯该位置和该列
//			for (int j = x + 1; j < n; j++) {
//				if (board[j][i] == '#')memo[j][i] = false;
//			}
//		}
//	}
//	// 不选这一行
//	dfs(x + 1, count, ans);
//}
//int main() {
//	while (1) {
//		cin >> n >> k; 
//		if(n == -1 && k == -1)break;
//		board.resize(n);
//		memo.resize(n, vector<bool>(n, false));
//		int ans = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> board[i];
//			for (int j = 0; j < n; j++) {
//				if (board[i][j] == '.')memo[i][j] = true;
//			}
//		}
//		dfs(0, 0, ans);   // 引用传参！！！！！！！！
//		cout << ans << endl;
//		board.clear();   // 最好clear一下吧 让思路更清晰
//		memo.clear();
//	}
//	return 0;
//}
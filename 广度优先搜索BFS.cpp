#include<iostream>
using namespace std;
// 广度优先搜索解决的是最短路径问题 
// “一石激起千层浪” 
// DFS和BFS的区别在于时间复杂度和空间复杂度 
// DFS递归实现非常耗时间 只能用于处理小数据题目 大数据就得用DP
// BFS迭代实现基本不耗时 但是层层需要开辟空间

// 需要的前置知识
// 一.队列queue 头文件<queue>  （单向管道 先进先出）
// 1.队列里加元素 q.push(元素);
// 2.删除首元素 q.pop();
// 3.访问首元素和尾元素 q.front()   q.back()
// 4.判断非空和大小 q.empty()    q.size()
// queue 的创建 queue<自定义类型/类型> q;

 
// 二.键值对pair 头文件<utility>
// 1.pair创建及其初始化     pair<类型1，类型2> p(类型1数据，类型2数据)
// 2.pair里元素访问         p.first    p.second

// 三.二者结合运用
// pair<int,int> pi;
// queue<pi> q;        q.push({1,1})  就是往队列里放了一个坐标  q.pop()就是把这个首坐标删掉


// 经典问题--迷宫最短路径问题（二维地图 0表示能走 1表示不能走 从左上到右下寻找最短迷宫路径）

// 为什么一定要用队列： BFS问题是找相邻元素并存储 先遍历到的元素先被存储 当前层的依次遍历完之后 再按存储顺序依次取出 进行下一层讨论 
// 能够实现这样的存储与取出的数据结构就是 Queue!!！

//#include<queue>
//#include<vector>
//#include<utility>
//int n,m;
//
//vector<vector<int>> board;  // 存地图
//vector<vector<int>> dist;   // 存到这个点的步数
//vector<vector<bool>> memo;  // 记录这个点被选过没有
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//queue<pair<int, int>> q;
//
//int bfs(int x1, int y1) {
//
//	memo[x1][y1] = true;  // 让起点记录一下
// 	dist[x1][y1] = 0;     // 起点是走了0步
//	q.push({ x1,y1 });    // 把本坐标放进队列
//
//	while (!q.empty()) {  
//		auto t = q.front();   // 因为要删掉这个首元素 所以需要先保存一下
// 		q.pop();   // 删掉这个元素 因为循环条件是队列为空 所以需要给循环出口
//		for (int i = 0; i < 4; i++) {    // 从本坐标开始四个方向看看能不能走 
//
//			int a = t.first + dx[i], b = t.second + dy[i];
//
//			if (a<1 || b<1 || a>n || b>m)continue;   // 不能走的三个情况：越界 被记录过 该位置为1是障碍不能走
//			if (memo[a][b])continue;
//			if (board[a][b] != 0)continue;
//
//			memo[a][b] = true;   // 接下来是四个方向里能走的地方的处理 
//			q.push({ a,b });    // 把这个坐标放进队列
//			dist[a][b] = dist[t.first][t.second] + 1;   // 将这个点的步数存储一下
//			if (a == n && b == m)break;   // 如果到终点了 跳出这个四方向循环 下一次的情况都不符合 然后q为空 退出while大循环
//		}
//	}
//
//	return dist[n][m];
//}
//int main() {
//	cin >> n >> m;
//	board.resize(n + 1, vector<int>(m + 1,0));
//	dist.resize(n + 1, vector<int>(m + 1,0));
//	memo.resize(n + 1, vector<bool>(m + 1, false));
//	for (int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) {
//			cin >> board[i][j];
//		}
//	}
//	cout<<bfs(1, 1);
//	return 0;
//}


// 经典问题2 -- 其实也是迷宫问题（从某个坐标走到某个坐标）
//#include<iostream>
//#include<vector>
//#include<string>
//#include<queue>
//#include<utility>
//using namespace std;
//int n;
//int x1, y1, x2, y2;
//vector<string> board;
//vector<vector<int>> dist;
//vector<vector<bool>> memo;
//queue<pair<int, int>> q;
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//
//int bfs(int x, int y) {
//
//    memo[x][y] = true;
//    q.push({ x,y });
//
//    while (!q.empty()) {
//        auto t = q.front();
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            int a = t.first + dx[i], b = t.second + dy[i];
//            if (a < 0 || b < 0 || a >= n || b >= n)continue;
//            if (board[a][b] == '1')continue;
//            if (memo[a][b])continue;
//
//            memo[a][b] = true;
//            q.push({ a,b });
//            dist[a][b] = dist[t.first][t.second] + 1;
//
//            if (a == x2 && b == y2)break;
//        }
//    }
//    return dist[x2][y2];
//}
//
//int main() {
//    cin >> n;
//    board.resize(n);
//    dist.resize(n, vector<int>(n, 0));
//    memo.resize(n, vector<bool>(n, false));
//    for (int i = 0; i < n; i++) {
//        cin >> board[i];
//    }
//    cin >> x1 >> y1 >> x2 >> y2;
//    x1--; y1--; x2--; y2--;
//    cout << bfs(x1, y1);
//    return 0;
//}


// 延伸问题——多源BFS问题
// 1 . 洛谷P1332 血色先锋队（涉及多个起点 互相影响）
//#include<vector>
//#include<iostream>
//#include<queue>
//#include<utility>
//using namespace std;
//int n, m, a, b;
//queue<pair<int, int>> q;
//vector<vector<bool>> memo;
//vector<vector<int>> res;
//int dx[] = { -1,0,1,0 }; int dy[] = { 0,1,0,-1 };
//
//void bfs() {
//    while (!q.empty()) {
//        auto t = q.front();
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            int a = t.first + dx[i], b = t.second + dy[i];
//
//            if (a < 0 || b < 0 || a >= n || b >= m)continue;
//            if (memo[a][b])continue;
//
//            memo[a][b] = true;
//            q.push({ a,b });
//            res[a][b] = res[t.first][t.second] + 1;
//        }
//    }
//}
//
//int main() {
//    cin >> n >> m >> a >> b;
//    memo.resize(n, vector<bool>(m, false));
//    res.resize(n, vector<int>(m, 0));
//    // 输入的时候直接压进队列 注意把坐标从 1-based 转为 0-based
//    for (int i = 0; i < a; i++) {
//        int x, y; cin >> x >> y;
//        x--; y--;
//        q.push({ x,y });
//        memo[x][y] = true;
//    }
//    bfs();  // 其实像bfs确实不必要传参数 一般情况下传的x y坐标 就是为了memo和压入队列 其实这个可以在bfs函数之外写
//    for (int i = 0; i < b; i++) {
//        int x, y; cin >> x >> y;
//        x--; y--;
//        cout << res[x][y] << endl;
//    }
//    return 0;
//}

// 2. 洛谷P1747 好奇怪的游戏（涉及多次bfs 互不影响 其实就是多了个重置的过程）
//#include<iostream>
//#include<utility>
//#include<queue>
//#include<cstring>
//using namespace std;
//#define p first
//#define l second
//int x1, y1, x2, y2;
//int board[50][50] = { 0 };
//bool memo[50][50] = { false };
//queue<pair<int, int>> q;
//int dx[] = { 2,2,-2,-2,-2,-2,-1,-1,1,1,2,2 };
//int dy[] = { -2,2,2,-2,-1,1,-2,2,-2,2,-1,1 };
//
//
//int bfs(int x, int y) {
//
//    memo[x][y] = true;
//    q.push({ x,y });
//
//    while (!q.empty()) {
//        auto t = q.front();
//        q.pop();
//        for (int i = 0; i < 12; i++) {
//            int a = t.p + dx[i], b = t.l + dy[i];
//            if (a < 0 || b < 0 || a >= 50 || b >= 50)continue;   // 尽管没规定上界 也要写上界 不然多方向遍历很可能（一定）会越界
//            if (memo[a][b])continue;
//
//            memo[a][b] = true;
//            q.push({ a,b });
//            board[a][b] = board[t.p][t.l] + 1;
//
//            if (a == 0 && b == 0) break;
//        }
//    }
//    return board[0][0];
//}
//int main() {
//    cin >> x1 >> y1 >> x2 >> y2;
//    x1--; x2--; y1--; y2--;
//    cout << bfs(x1, y1) << endl;
//    memset(memo, false, sizeof(memo));
//    memset(board, 0, sizeof(board));
//    cout << bfs(x2, y2);
//    return 0;
//}


// 延伸问题——染色问题（类似于洪水灌溉问题）
// 洛谷P1162 填涂颜色
//#include<iostream>
//#include<utility>
//#include<vector>
//#include<queue>
//using namespace std;
//int n;
//vector<vector<int>> board;
//vector<vector<bool>> memo;
//queue<pair<int, int>> q;
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//void bfs(int x, int y) {
//    memo[x][y] = true;
//    q.push({ x,y });
//
//    while (!q.empty()) {
//        auto t = q.front();
//        q.pop();
//
//        for (int i = 0; i < 4; i++) {
//            int a = t.first + dx[i], b = t.second + dy[i];
//            if (a<0 || b<0 || a>n + 1 || b>n + 1)continue;
//            if (memo[a][b])continue;
//
//            memo[a][b] = true;
//            q.push({ a,b });
//
//        }
//    }
//}
//
//int main() {
//    cin >> n;
//    board.resize(n + 2, vector<int>(n + 2, 0));   // 这个思路相当牛逼
//    memo.resize(n + 2, vector<bool>(n + 2, false));
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cin >> board[i][j];
//            if (board[i][j] == 1)memo[i][j] = true;
//        }
//    }
//    bfs(0, 0);
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (!memo[i][j])board[i][j] = 2;
//            cout << board[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}



// 有外界干扰的迷宫问题
// 洛谷 P2895 天降陨石
//#include<iostream>
//#include<utility>
//#include<cstring>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//int dist[305][305];
//int fire[305][305];
//queue<pair<int, int>> q;
//int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
//
//int bfs(int x, int y) {
//    q.push({ x,y });
//
//    while (!q.empty()) {
//        auto p = q.front();
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            int a = p.first + dx[i], b = p.second + dy[i];
//            if (a < 0 || b < 0)continue;
//            if (dist[a][b])continue;
//            if (dist[p.first][p.second] + 1 >= fire[a][b])continue;
//
//            q.push({ a,b });
//            dist[a][b] = dist[p.first][p.second] + 1;
//
//            if (fire[a][b] == 0x3f3f3f3f)return dist[a][b];  // 如果找到一个不会被打的点 就结束 这个点一定是最小时间点
//        }
//    }
//    return -1;  // 找不到返回-1
//}
//
//int main() {
//    int n; cin >> n;
//    memset(dist, 0, sizeof(dist));
//    memset(fire, 0x3f, sizeof(fire));
//    for (int i = 0; i < n; i++) {
//        int x, y, t; cin >> x >> y >> t;
//        fire[x][y] = min(fire[x][y], t);  // 炸弹可能打到同一个位置
//        for (int j = 0; j < 4; j++) {
//            int a = x + dx[j], b = y + dy[j];
//            if (a < 0 || b < 0 || a >= 304 || b >= 304)continue;
//            fire[a][b] = min(fire[a][b], t);
//        }
//    }
//    cout << bfs(0, 0);
//    return 0;
//}



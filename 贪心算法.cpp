#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<string>
using namespace std;

// 贪心算法定义：局部最优-->全局最优
// 步骤：分解问题 贪心选择 求解子问题 合并解
// 贪心算法不考虑未来的影响 不回溯

// 贪心十大问题类型

// 一.区间问题
// （典例）有n个会议需要在会议室召开 给出若干个开始时间和结束时间 问最多安排几个不冲突的会议
//先对结束时间进行排序 优先选结束时间早的 然后判断下一个开始时间是否小于这个结束时间

//vector<pair<int,int>> num;   // 保存每一个会议的开始结束时间
//int n;   // 总共的会议数
//
//int meetings(vector<pair<int, int>>& num) {
//	int cnt = 1;  // 意思是已经选了第一个 记录当前状态
//	int last_end = num[0].second;
//	for (int i = 1; i < n; i++) {
//		if (num[i].first >= last_end) {  // 要让下一个的开始时间在上一个的后面
//			cnt++;
//			last_end = num[i].second;
//		}
//		//如果冲突了就不管了 这个num[i]就跳过
//	}
//	return cnt;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		pair<int, int> t;
//		cin >> t.first >> t.second;
//		num.push_back(t);
//	}
//	// 按结束时间升序排序
//	sort(num.begin(), num.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;});
//	int result = meetings(num);
//	cout << result;
//}
//
//
// //二.分配问题
// //（典例）分发饼干 每个孩子胃口a[i] 每块饼干大小b[i] a[i]>=b[i] 就可以满足一个孩子 问最多满足多少孩子
// //小饼干给小胃口 优先满足小胃口 不浪费
//
//int n, m;  // n个孩子 m个饼干
//vector<int> child;
//vector<int> bis;
//
//int content_num() {
//	int chi = 0, bisc = 0; // 当前要满足的孩子和当前的饼干
//
//	// 双指针贪心匹配
//	while (chi < n && bisc < m) {
//		if (bis[bisc] >= child[chi]) {
//			chi++;   // 如果当前孩子可以分这个饼干 就分 chi++
//		}
//		bisc++;  // 不管这个孩子要不要这个饼干 这个饼干都要++
//	}
//
//	return chi;
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x; child.push_back(x);
//	}
//	for (int i = 0; i < m; i++) {
//		int x; cin >> x; bis.push_back(x);
//	}
//	sort(child.begin(), child.end());
//	sort(bis.begin(), bis.end());
//
//	int ans = content_num();
//	cout << ans;
//}
//
//
//
// //三.分数背包问题
// //（典例）强盗有个能装w公斤的背包 有n个物品 给出每个物品的重量和价值 物品可以分割 问怎么能让利益最大化
// //这个是分数背包 物品可以分割 就优先拿价值密度大的
//
//int w;
//int n;
//vector<pair<int, int>> wv;  // first是重量 second是价值
//
//double max_value() {
//	double current_value = 0.0;   // 记录当前状态
//	int remine_w = w;
//	for (int i = 0; i < n; i++) {
//		if (remine_w <= 0)break;
//
//		if (wv[i].first <= remine_w) {   // 可以全拿
//			current_value += wv[i].second;
//			remine_w -= wv[i].first;
//		}
//		else {   // 只能拿部分
//			double bili = 1.0 * remine_w / wv[i].first;
//			current_value += bili * wv[i].second;
//			remine_w = 0;
//		}
//	}
//	return current_value;
//}
//
//int main() {
//	cin >> w >> n;
//	for (int i = 0; i < n; i++) {
//		pair<int, int> t;
//		cin >> t.first >> t.second;
//		wv.push_back(t);
//	}
//
//	// 按照价值密度降序排序
//	sort(wv.begin(), wv.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return 1.0*a.second / a.first > 1.0*b.second / b.first; });
//	double ans = max_value();
//	cout << ans;
//}
//
//
//// 四.哈曼夫编码-最小连接成本
//// 需要首先了解优先队列 可以是最大堆也可以是最小堆
//// 最大堆的创建 priority_queue<int> x; 只能通过 取x.top()和删x.pop() 一个一个取出 按从大到小顺序取
//// 最小堆的创建 priority_queue<int,vector<int>,greatrer<int>> x;   这个是从小到大取出
////
////（典例）最小成本连接棒材 n根不同长度的棒材连接成一根 每次连接两根 成本是两根长度和 问最小成本
//// 肯定优先连接长度短的
//
//int n;
//priority_queue<int,vector<int>,greater<int>> length;
//
//int money() {
//	int cost = 0;
//	while (length.size() > 1) {
//		int first = length.top(); length.pop();
//		int second = length.top(); length.pop();
//		cost += (first + second);
//		length.push(first + second);
//	}
//	return cost;
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		length.push(x);
//	}
//	int ans = money();
//	cout << ans;
//	return 0;
//}
//
//
// //五.股票买卖--最大利润
// //（典例）给定股票每天的价格 可以多次买卖 但必须卖了才能买 求最大利润
// //只要今天价格比昨天高 就昨天买今天卖 就相当于抓住了所有的上升阶段
//
//int n;
//vector<int> price;
//
//int max_profit() {
//	if (n < 2)return 0;
//	int total = 0;
//	for (int i = 1; i < n; i++) {
//		if (price[i] > price[i - 1])
//			total += price[i] - price[i - 1];
//	}
//	return total;
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		price.push_back(x);
//	}
//	int ans = max_profit();
//	cout << ans;
//	return 0;
//}
//
//
// //六.跳跃游戏（最少跳跃次数）
// //给定一个数组 开始时在第一个位置 每一个位置的数字代表可以跳跃的最远距离 问跳到最后一个位置的最少跳跃次数
//
//int n;
//vector<int> num;
//
//int jump() {
//	if (n <= 1)return 0;
//	int jumps = 0;
//	int current_end = 0;  // 从当前位置起跳能跳到的最远距离
//	int max_end = 0;  // 从当前位置起跳途中能到的最远距离
//	 
//	// 其实就是先找边界 在边界里找最远 到边时是再把这个最远设为边界 同时jump++
//	for (int i = 0; i < n - 1; i++) {
//		max_end = max(max_end, i + num[i]);  //更新从当前位置能跳到的最远位置
//		if (i == current_end) { 
//			jumps++;   // 如果到达跳跃边界 就必须跳一次 
//			current_end = max_end;  // 更新下一次边界
//			if (current_end >= n - 1)break;  //如果已经能到终点就提前结束
//		}
//	}
//
//	return jumps;
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		num.push_back(x);
//	}
//	int times = jump();
//	cout << times;
//	return 0;
//}
//
//
//
// //七.任务调度（单机最小等待时间）
// //有n个客户 第i个客户的服务时间为t[i] 所有客户在0时间到达 要求所有客户最短等待时间
// //时间短的客户优先 其实我觉得跟哈曼夫编码有异曲同工之妙
//
//int n;
//vector<int> times;
//
//int time_sum() {
//	int total = 0;
//	int cur_time = 0;
//	for (int i = 0; i < n; i++) {
//		total += cur_time;  // 实际上是加了当前客户的等待时间
//		cur_time += times[i];  // 更新当前时间
//	}
//	return total;
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		times.push_back(x);
//	}
//	sort(times.begin(), times.end());
//	int ans = time_sum();
//	cout << ans;
//	return 0;
//}
//
//
//
// //八.找零钱问题（贪心有效的情况）
// //给n个不同面额的硬币和一个总金额 要求用最少的硬币凑出这个总金额 每个硬币不限次使用
//int n;
//vector<int> coins;
//int amount;
//
//int min_mean() {
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		cnt += amount / coins[i];
//		amount %= coins[i];
//
//		if (amount == 0)break;
//	}
//	return amount == 0 ? cnt : -1;
//}
//
//int main() {
//	cin >> n >> amount;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		coins.push_back(x);
//	}
//	sort(coins.begin(), coins.end(), [](const int& a, const int& b) {return a > b; });
//	int ans = min_mean();
//	cout << ans;
//	return 0;
//}
//
//
//
// //九.字符串问题
// //给一个字符串非负整数 并要求移除其中k位 求移除后的最小数
//
//string num;
//int k;
//
//string maxnum() {
//	vector<char> stack;
//	for (int i = 0; i < num.size(); i++) {
//		while (k > 0 && !stack.empty() && stack.back() > num[i]) {
//			stack.pop_back();
//			k--;
//		}
//		stack.push_back(num[i]);
//	}
//
//	while (k > 0) {
//		stack.pop_back();
//		k--;
//	}
//
//	string res;
//	for (char k : stack) {
//		res.push_back(k);
//	}
//	return res;
//}
//
//int main() {
//	cin >> num >> k;
//	string ans = maxnum();
//	cout << ans;
//	return 0;
//}
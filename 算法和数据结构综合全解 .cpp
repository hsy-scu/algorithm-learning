#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;

// ！！！注意！！！
/*
	delete一个指针 这个指针不为空 需要手动置空！ 这是很多段错误的根源
*/


//  单向链表
/*

// 链表(无头节点的)
class NodeList {
private:
	struct Node {
		int data;
		Node* next;
		Node(int val) :data(val), next(nullptr) {}
	};
public:
	Node* head;
	int size;
	NodeList() :head(nullptr), size(0) {}

	// 插入元素
	// 前插法
	void insertFront(int val) {
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
		size++;
	}

	// 尾插法
	void insertBack(int val) {
		Node* newNode = new Node(val);
		if (!head)newNode = head;
		else {
			Node* temp = head;
			while (temp->next != nullptr)temp = temp->next;
			temp->next = newNode;
		}
		size++;
	}

	// 从某个元素后面开始插
	void insertIn(int index, int val) {
		if (index<0 || index>size)return;

		Node* newNode = new Node(val);
		
		if (index == 0) {
			newNode->next = head;
			head = newNode;
		}
		
		else {
			Node* temp = head;
			for (int i = 0; i < index - 1; i++)temp = temp->next;
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
	}

	// 删除元素
	// 删除头元素
	void deleteFront() {
		if (!head)return;
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}

	// 删除尾部元素
	void deleteBack() {
		if (!head)return;
		else if (!head->next) {
			delete head;
			head = nullptr;
		}
		else {
			Node* temp = head;
			while (!temp->next->next)temp = temp->next;
			delete temp->next;
			temp->next = nullptr;
		}
		size--;
	}

	// 删除值为val的所有元素
	void deleteVal(int val) {
		Node* unreal = new Node(0);
		unreal->next = head;
		Node* prev = unreal;
		Node* curr = head;
		while (curr) {
			if (curr->data == val) {
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
				size--;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
		head = unreal->next;
		delete unreal;
	}

	// 删除第k位元素
	void deleteK(int k) {
		if (k<1 || k>size)return;
		else if (k == 1) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else {
			Node* temp = head;
			for (int i = 1; i < k - 1; i++)temp = temp->next;
			Node* baocun = temp->next;
			temp->next = temp->next->next;
			delete baocun;
		}
		size--;
	}

	// 删除倒数第k位元素
	// 双指针做法 先让快指针走k步 然后快慢指针都以一个单位的速度向后走 当快指针到头时 慢指针刚好在倒数第k+1个
	void deleteDK(int k) {
		Node* unreal = new Node(0);
		unreal->next = head;
		Node* slow = unreal, * fast = unreal;

		while (k--)fast = fast->next;
		
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		Node* baocun = slow->next;
		slow->next = slow->next->next;
		delete baocun;
		size--;

		head = unreal->next;
		delete unreal;
	}

	// 打印链表
	void printList() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << ' ';
			temp = temp->next;
		}
	}

	// 双指针找中间节点
	Node* findMiddle() {
		Node* slow = head, * fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	// 双指针判断链表是否有环
	bool hasCricle() {
		Node* slow = head, * fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)return true;
		}
		return false;
	}

	// 双指针找到链表环入口
	Node* runIntocircle() {
		Node* slow = head, * fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)break;
		}
		if (!fast || !fast->next)return nullptr;
		Node* pos1 = slow;
		Node* pos2 = head;
		while (slow != head) {
			slow = slow->next;
			head = head->next;
		}
		return pos1;
	}

	// 反转链表
	// 迭代法反转链表
	Node* reverseList(Node* head) {
		Node* prev = nullptr;
		Node* curr = head;
		while (!curr) {
			Node* nextNode = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextNode;
		}
		return prev;
	}

	// 反转部分链表
	Node* reveresePart(Node* head, int left, int right) {
		if (!head || left == right)return nullptr;
		Node* unreal = new Node(0);
		unreal->next = head;
		Node* prev = unreal;
		for (int i = 0; i < left - 1; i++) prev = prev->next;
		Node* curr = prev->next;
		Node* nextNode = nullptr;
		for (int i = 0; i < right - left; i++) {
			nextNode = curr->next;
			curr->next = nextNode->next;
			nextNode->next = prev->next;
			prev->next = nextNode;
		}
		Node* newHead = unreal->next;
		delete unreal;
		return newHead;
	}

	
	// 归并排序链表
	// 合并两个有序链表
	Node* mergeTwolist(Node* l1, Node* l2)  {
		Node* unreal = new Node(0);
		Node* tail = unreal;
		while (l1 && l2) {
			if (l1->data < l2->data) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2;
		Node* newHead = unreal->next;
		delete unreal;
		return newHead;
	}
	
	// 归并实现
	Node* sortList(Node* head) {
		if (!head || !head->next)return head;
		Node* slow = head, * fast = head, * prev = nullptr;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = nullptr;

		Node* L1 = sortList(head);
		Node* L2 = sortList(slow);

		return mergeTwolist(L1, L2);
	}


	// 回文链表
	// 回文链表可以有多种思路 可以将所有数据放入vector里面然后再双指针做法
	// 这里将用一种空间复杂度O(1)的方法做(思路是把链表后半部分反转 再跟前半部分比较)

	Node* reverse(Node* head) {
		Node* prev = nullptr;
		Node* curr = head;
		while (curr) {
			Node* nextNode = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextNode;
		}
		return prev;
	}

	bool ishuiwen(Node* head) {
		if (!head || !head->next)return true;
		Node* slow = head, * fast = head, * prev = nullptr;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = nullptr;
		Node* another_head = reverse(slow);
		Node* temp = head;
		Node* another_temp = another_head;
		while (temp) {
			if (temp->data != another_temp->data) {
				another_head = reverse(another_head);
				prev->next = another_head;
				return false;
			}
			temp = temp->next;  another_temp = another_temp->next;
		}

		another_head = reverse(another_head);
		prev->next = another_head;
		return true;
	}

	// 判断两个链表是否相交 返回相交点
	Node* isxiangjiao(Node* l1, Node* l2) {
		if (!l1 || !l2)return nullptr;
		Node* p1 = l1;
		Node* p2 = l2;
		while (p1 != p2) {
			p1 = (p1 == nullptr) ? l2 : p1->next;
			p2 = (p2 == nullptr) ? l1 : p2->next;
		}
		return p1;
	}


	// 析构函数
	~NodeList() {
		Node* temp = head;
		while (temp) {
			Node* nextNode = temp->next;
			delete temp;
			temp = nextNode;
		}
	}
};

*/

// 单向循环链表
/*


// 循环链表（有头节点的）
class circleLink {
private:
	struct Node {
		int data;
		Node* next;
		Node(int val) :data(val), next(nullptr) {}
	};
	Node* head;
	Node* tail;
public:
	int size;
	circleLink() {
		head = new Node(0);
		tail = head;
		head->next = head;
		size = 0;
	}

	// 插入操作
	// 尾插法
	void insertBack(int val) {
		Node* newNode = new Node(val);
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
		size++;
	}

	// 头插法
	void insertFront(int val) {
		Node* newNode = new Node(val);
		newNode->next = head->next;
		head->next = newNode;
		if (newNode->next = head)tail = newNode; 
		size++;
	}

	// 删除操作
	void deleteLink(int val) {
		Node* p = head;
		Node* q = head->next;
		while (q != head) {
			if (q->data == val) {
				p->next = q->next;
				delete q;
				size--;
				q = p->next;
				if (p->next == head) {
					tail = p;
				}
			}
			else {
				p = q;
				q = q->next;
			}
		}
	}

	// 查询操作
	bool findLink(int val) {
		Node* p = head->next;
		while (p != head) {
			if (p->data == val)return true;
			p = p->next;
		}
		return false;
	}

	// 打印链表
	void printLink() {
		Node* p = head->next;
		while (p != head) {
			cout << p->data << ' ';
			p = p->next;
		}
		cout << endl;
	}

	~circleLink() {
		if(!head)return;
		Node* temp = head->next;
		while (temp != head) {
			head->next = temp->next;
			delete temp;
			temp = head->next;
		}
		delete head;
		head = nullptr;
	}
};

*/

// 单向循环约瑟夫问题
/*


int n, m, k;  // (n是n个人 m是从第m个开始 k是每k个出一个)

class circleLink {
private:
	struct Node {
		int data;
		Node* next;
		Node(int val) :data(val), next(nullptr) {}
	};
	Node* head;
	Node* tail;
public:
	circleLink() {
		head = nullptr;
		tail = head;
	}
	~circleLink() {
		if (!head)return;
		Node* p = head->next;
		while (p != head) {
			head->next = p->next;
			delete p;
			p = head->next;
		}
		delete head;
	}
	void createLink(int n) {
		for (int i = 1; i <= n; i++) {
			Node* newNode = new Node(i);
			if (!head) {
				head = newNode;
				tail = newNode;
				tail->next = head;
			}
			else {
				newNode->next = tail->next;
				tail->next = newNode;
				tail = newNode;
			}
		}
	}
	void joseph(int m,int k) {
		Node* p = head;
		Node* q = tail;

		for (int i = 0; i < m - 1; i++) {
			q = p;
			p = p->next;
		}

		while (1) {
			for (int i = 0; i < k - 1; i++) {
				q = p;
				p = p->next;
			}
			cout << p->data << ' ';
			if (q == p) {
				delete p;
				head = nullptr;
				tail = nullptr;
				break;
			}
			q->next = p->next;
			delete p;
			p = q->next;
		}
	}
};

int main() {
	cin >> n >> m >> k;
	circleLink link;
	link.createLink(n);
	link.joseph(m, k);
	return 0;
}

*/

// 双向链表
/*


// 双向链表
class doubleLink {
private:
	struct Node {
		int data;
		Node* prev;
		Node* next;
		Node(int val) :data(val), prev(nullptr), next(nullptr){}
	};
	Node* head;
public:
	doubleLink() {
		head = new Node(0);
	}
	~doubleLink() {
		Node* p = head;
		while (p) {
			head = p->next;
			delete p;
			p = head;
		}
	}

	// 插入元素
	void insertFront(int val) {
		Node* newNode = new Node(val);
		newNode->next = head->next;
		newNode->prev = head;
		if (head->next) {
			head->next->prev = newNode;
		}
		head->next = newNode;
	}
	
	void insertBack(int val) {
		Node* newNode = new Node(val);
		Node* p = head;
		while (p->next) p = p->next;
		p->next = newNode;
		newNode->prev = p;
	}

	// 打印链表
	void printList() {
		Node* p = head->next;
		while (p) {
			cout << p->data << ' ';
			p = p->next;
		}
	}

	// 删除元素
	void deleteVal(int val) {
		Node* p = head->next;
		while (p) {
			if (p->data == val) {
				p->prev->next = p->next;
				if (p->next != nullptr)p->next->prev = p->prev;

				Node* nextNode = p->next;
				delete p;
				p = nextNode;
			}
			else p = p->next;
		}
	}

};

*/  

// 双向循环链表    
/*

// 双向循环链表
class doubleCircleList {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;
		Node(int val)
			:data(val)
			, prev(nullptr)
			, next(nullptr)
		{}
	};
	Node* head;
public:
	doubleCircleList() {
		head = new Node(0);
		head->next = head;
		head->prev = head;
	}
	~doubleCircleList() {
		Node* p = head->next;
		while (p != head) {
			head->next = p->next;
			p->next->prev = head;
			delete p;
			p = head->next;
		}
		delete head;
		head = nullptr;
	}

	// 头插法
	void insertFront(int val) {
		Node* newNode = new Node(val);
		newNode->next = head->next;
		newNode->prev = head;
		head->next->prev = newNode;
		head->next = newNode;
	}

	// 尾插法
	void insertBack(int val) {
		Node* newNode = new Node(val);
		Node* p = head->prev;
		newNode->next = head;
		newNode->prev = p;
		p->next = newNode;
		head->prev = newNode;
	}
	
	// 删除元素
	void deleteVal(int val) {
		Node* p = head->next;
		while (p != head) {
			if (p->data == val) {
				p->prev->next = p->next;
				p->next->prev = p->prev;
				Node* baocun  = p->next;
				delete p;
				p = baocun;
			}
			else p = p->next;
		}
	}
};

*/

// stl容器list
   /*
头文件#include<list>

创建和初始化  
list<int> lst(size,val) 
list<int> lst(起始迭代器，终止迭代器)
list<int> lst(lst1) 

容量和访问
lst.size()   lst.empty() 
lst.front()  lst.back()

添加元素
头尾：lst.push_back(val)  lst.push_front(val) lst.emplace_frint(val)  lstemplace_back(val)
中间：lst.insert(迭代器，数量，val)  lst.insert(迭代器，val)   lst.insert(迭代器，插入的头迭代器，插入的尾迭代器)
需要注意的是：List的迭代器访问需要 advance() 函数
auto it = lst.begin()     advance(it,3)  就是指向第四个迭代器

删除元素
lst.pop_back()  lst.pop_front()
lst.erase(迭代器)  lst.remove(val)
lst.clear()

特殊操作
拼接操作 lst.splice(需要拼接到后面的迭代器，被拼接的东西，被拼接的东西的头迭代器，被拼接的尾迭代器) 其实截取到的是头迭代器和尾迭代器之前的内容 不算尾迭代器
排序操作 lst.sort()  lst.sort(greater<int>())
反转操作 lst.reverse()
去重操作 lst.sort() lst.unique()

*/
 
// 顺序栈
/*
class Stack {
private:
	// 栈的基本元素
	int cap;
	int* stack;
	int top;
	// 扩容
	void expand(int size) {
		int* p = new int[size];
		memcpy(p, stack, top * sizeof(int));
		delete[] stack;
		stack = p;
		cap = size;
	}
public:
	Stack(int size = 10) {
		cap = size;
		top = 0;
		stack = new int[size];
	}
	~Stack() {
		delete[] stack;
		stack = nullptr;
	}

	// 入栈
	void push(int val) {
		if (cap == top) expand(2 * cap);
		stack[top++] = val;
	}

	// 出栈
	void pop() {
		if (top == 0) throw "stack is empty !";
		top--;
	}

	// 获取栈顶元素
	int top1() const {
		if (top == 0) throw "stack is empty !";
		else return stack[top - 1];
	}

	// 判断是否为空
	bool empty() const {
		return top == 0;
	}

	// 返回栈的大小
	int size() const {
		return top;
	}

	// 返回总容量
	int cap1() const { return cap; }
};

int main() {
	Stack stack;
	cout << stack.cap1() << endl;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	for (auto& k : arr) {
		stack.push(k);
	}
	cout << stack.cap1() << endl;
	while (!stack.empty()) {
		cout << stack.top1() << ' ';
		stack.pop();
	}
	return 0;
}

*/

// stl容器stack
/*
pop()  top() push() size() empty() swap(另一个栈)
*/

// 链式栈
/*
class listStack {
private:
	struct Node {
		int data;
		Node* next;
		Node(int val = 0) :data(val), next(nullptr) {}
	};
	Node* head;
	int size;
public:
	listStack() : head(new Node()), size(0) {}
	~listStack() {
		Node* p = head;
		while (p) {
			head = head->next;
			delete p;
			p = head;
		}
	}
	// 进栈
	void push(int val) {
		Node* newNode = new Node(val);
		newNode->next = head->next;
		head->next = newNode;
		size++;
	}
	// 出栈
	void pop() {
		if (!head->next)throw "stack is empty!";
		Node* p = head->next;
		head->next = p->next;
		delete p;
		size--;
	}
	// 返回栈顶元素
	int top() {
		if (!head->next)throw "stack is empty!";
		return head->next->data;
	}
	// 返回大小
	int size1() { return size; }
	// 判断是否为空
	bool empty() { return head->next == nullptr; }
};

*/

// 栈问题：括号匹配
/*
#include<stack>
bool isVaild(string s) {
	stack<char> cs;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')cs.push(s[i]);
		else {
			if (cs.empty())return false;
			char x = cs.top();
			if ((x == '(' && s[i] == ')') || (x == '[' && s[i] == ']') || (x == '{' && s[i] == '}')) {
				cs.pop();
			}
			else return false;
		}
	}
	return cs.empty();
}
*/

// 栈问题：逆波兰表达式求解 
/*

#include<stack>
#include<string>
int res(vector<string>& nums) {
	stack<int> num;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == "+" || nums[i] == "-" || nums[i] == "*" || nums[i] == "/") {
			if (num.size() < 2)throw "stack is not true!";
			int x = num.top(); num.pop();
			int y = num.top(); num.pop();
			if (nums[i] == "+")num.push(y + x);
			else if (nums[i] == "-")num.push(y - x);
			else if (nums[i] == "*")num.push(y * x);
			else if (nums[i] == "/")num.push(y / x);
		}
		else num.push(stoi(nums[i]));
	}
	return num.top();
}

*/

// 栈问题：中缀转后缀方法
/*
#include<stack>
#include<string>

 
思路 ： 
a.数字直接压入结果
b.符号要进行优先级比较：（1） '(' 直接进栈     （2）栈为空直接进栈 
                        （3） 比较当前符号和栈顶符号优先级
							  a.当前 >  栈顶   当前符号压入栈
							  b.当前 <= 栈顶   压入结果并继续比较【当前】和【新栈顶】符号优先级 因此需要循环比较
							  比较特殊的结果就是 当前元素为')' 需要一直等到'('出现 但是需要注意括号不能压入结果
c. 优先的情况只有两种： （1） 栈顶元素为加减 当前元素为乘除
						（2） 栈顶元素为左括号 当前元素为除右括号以外任何一个
	（右括号的优先级很低 但是可以收住左括号）


bool priority(char top1, char curr) {
	
	if ((curr == '*' || curr == '/') && (top1 == '+' || top1 == '-')) {
		return true;
	}
	else if (top1 == '(' && curr != ')')return true;
	return false;
}

string midToBack(string& expr) {

	string res;
	stack<char> s;
	for (char& curr:expr) {

		// 是数字直接放入结果
		if (curr > '0' && curr < '9') {
			res.push_back(curr);
		}

		else {
			while (1) {

				// 符合优先级的直接压入符号栈 break
				if (s.empty() || curr == '('){
					s.push(curr); break;
				}

				char top1 = s.top();
				if (priority(top1, curr)) {
					s.push(curr);
					break;
				}

				// 不符合优先级的取出符号栈中的栈顶元素放入结果 当前元素先不管 留循环里下一次判断
				else {
					s.pop();
					if (top1 == '(') break; // 左括号不计入结果 只有')'才能最后删到'('  因为'('的优先级不比括号里面任何一个大 除非右括号
					res.push_back(top1);
				}

			}
		}
	}

	while (!s.empty()) {
		res.push_back(s.top());
		s.pop();
	}

	return res;
}

*/

// 环形队列(数组实现)
/*
class Queue {
private:
	int* queue;
	int size_;
	int first;
	int end;
	int cap;
	void expand(int size) {
		int* newQueue = new int[size];
		int i = 0;
		int j = first;
		for (; j != end; i++, j = (j + 1) % cap) {
			newQueue[i] = queue[j];
		}
		delete[] queue;
		queue = newQueue;
		cap = size;
		first = 0; end = i;
	}

public:
	Queue(int cap_ = 10) :first(0), end(0), size_(0), cap(cap_), queue(new int[cap]) {}
	~Queue() {
		delete[] queue;
		queue = nullptr;
	}
	// 入队
	void push(int val) {
		if ((end + 1) % cap == first)expand(2 * cap);
		queue[end] = val;
		end = (end + 1) % cap;
		size_++;
	}
	// 出队
	void pop() {
		if (end == first)throw "queue is empty";
		first = (first + 1) % cap;
		size_--;
	}
	//  访问队头元素
	int front() const {
		if (end == first)throw "queue is empty";
		return queue[first];
	}
	// 访问队尾元素
	int back() const {
		if (end == first)throw "queue is empty";
		return queue[(end - 1 + cap) % cap];
	}
	// 访问大小
	int size()const { return size_; }
	// 访问空
	bool empty()const { return first == end; }
};

*/

// 链式队列（双向循环链表实现）
/*
class ListQueue {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;
		Node(int val) :data(val), next(nullptr), prev(nullptr) {}
	};
	Node* head;
	int size;
public:
	ListQueue() {
		head = new Node(0);
		head->next = head;
		head->prev = head;
		size = 0;
	}
	~ListQueue() {
		Node* p = head->next;
		while (p != head) {
			head->next = p->next;
			p->next->prev = head;
			delete p;
			p = head->next;
		}
		delete head;
		head = nullptr;
	}
	// 入队（尾插）
	void push(int val) {
		Node* newNode = new Node(val);
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
		size++;
	}
	// 出队
	void pop() {
		if (head->next==head)throw "queue is empty";
		Node* p = head->next;
		head->next = p->next;
		p->next->prev = head;
		delete p;
		size--;
	}
	// 获取队头元素
	int front()const {
		if (head->next==head)throw "queue is empty";
		return head->next->data;
	}
	// 获取队尾元素
	int back() const {
		if (head->next==head)throw "queue is empty";
		return head->prev->data;
	}
	// 获取大小
	int size()const { return size; }
	// 判空
	bool empty()const { return head->next==head; }
};

*/

// 队列栈实现
/*

class stack_queue {
private:
	stack<int> s1;   // s1负责push数据
	stack<int> s2;   // s2是辅助 
public:
	// 入队
	void push(int val) {
		s1.push(val);
	}
	// 出队 并 返回出去的值
	int pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		if(s2.empty())throw "queue is empty";
		int val = s2.top();
		s2.pop();
		return val;
	}
	// 返回队头
	int peek() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		if(s2.empty())throw "queue is empty";
		int val = s2.top();
		return val;
	}
	// 判空
	bool empty() { return s1.empty() && s2.empty(); }
};

*/

// 栈队列实现
/*
class queue_list {
private:
	queue<int> *q1;
	queue<int> *q2;
public:
	queue_list() {
		q1 = new queue<int>;
		q2 = new queue<int>;
	}
	~queue_list() {
		delete q1; delete q2;
		q1 = nullptr;
		q2 = nullptr;
	}
	// 入栈
	void push(int val) {
		q1->push(val);
		while (!q2->empty()) {
			q1->push(q2->front());
			q2->pop();
		}
		queue<int>* p = q1;
		q1 = q2;
		q2 = p;
	}
	// 出栈并返回栈顶
	int pop() {
		int val = q2->front();
		q2->pop();
		return val;
	}
	// 查询栈顶
	int top() {
		int val = q2->front();
		return val;
	}
	// 判空
	bool empty() { return q2->empty(); }
};
*/

// 堆（分大根堆和小根堆） 优先队列实现
/*
 堆在逻辑上是一个完全二叉树 完全二叉树是指最后一排从左到右排列 满足下标i的孩子的下标为2*i+1和2*i+2
 大根堆 是指 在 0<= i <= (n-1)/2 内  arr[i]>=arr[2*i+1]和arr[2*i+2] 也就是有孩子的节点大于他的两个孩子 堆顶元素整个树里面最大的数字
 小根堆 是指 在 0<= i <= (n-1)/2 内  arr[i]<=arr[2*i+1]和arr[2*i+2] 也就是有孩子的节点小于他的两个孩子 堆顶元素为整个树里面最小的数字
 */
/*
class Priorityqueue {
private:
	vector<int> heap_;
	function<bool(const int&, const int&)> comp_;
	// 上浮操作
	void shiftUp(int index) {
		while (index > 0) {
			int father = (index - 1) / 2;
			if (comp_(heap_[father],heap_[index])) {
				swap(heap_[index], heap_[father]);
				index = father;
			}
			else break;
		}
	}
	// 下沉操作
	void shiftDown(int index) {
		int size = heap_.size();
		while (2 * index + 1 <= size - 1) {
			int left_child = 2 * index + 1;
			int right_child = 2 * index + 2;
			int high_priority = index;
			
			if (left_child < size && comp_(heap_[high_priority], heap_[left_child])) {
				high_priority = left_child;
			}
			if (right_child < size && comp_(heap_[high_priority], heap_[right_child])) {
				high_priority = right_child;
			}
			if (high_priority != index) {
				swap(heap_[index], heap_[high_priority]);
				index = high_priority;
			}
			else break;
		}
	}   
	// 初始化传入的原始数组
	void buildheap() {
		// 从最后一个非叶子节点开始 从上进行下沉
		for (int i = (heap_.size() - 2) / 2; i >= 0; i--) {
			shiftDown(i);
		}
	}
public:
	// 只初始化比较器的构造函数
	//Priorityqueue(function<bool(const int&, const int&)> comp = greater<int>()) {
	//	comp_ = comp;
	//}
	// 初始化数组和比较器的构造函数
	Priorityqueue(const vector<int>& arr,function<bool(const int&, const int&)> comp = greater<int>()) {
		comp_ = comp;
		heap_ = arr;
		buildheap();
	}

	// 判空
	bool empty()const { return heap_.empty(); }

	// 返回大小
	int size()const { return heap_.size(); }

	// 入队
	void push(int val) {
		heap_.push_back(val);
		shiftUp(heap_.size() - 1);
	}

	// 出队（并返回堆顶元素）
	void pop() {
		if (empty())throw "priority queue is empty";
		// int res = heap_[0];
		heap_[0] = move(heap_[heap_.size() - 1]);
		heap_.pop_back();
		if(!empty()) shiftDown(0);
		// return res;
	}

	// 返回堆顶
	int top()const {
		if (empty())throw "priority queue is empty";
		return heap_[0];
	}

	void printqueue() {
		for (auto k : heap_) {
			cout << k << ' ';
		}
	}
};

int main() {
	vector<int> arr = { 3,6,1,6,8,3,4,0,1,2 };
	Priorityqueue myqueue(arr);
	myqueue.printqueue();
	return 0;
}
*/

// 堆排序
/* 堆排序的思路是 1.先把数据转化为大根堆形式 此时堆顶为最大元素
				  2.接下来把堆顶元素和最末尾元素交换 最末尾元素为堆顶 再对堆顶进行下沉操作 该步操作不必理会已经交换过的最大值
				  3.经过多次操作可实现越前面的数字越小的升序排列
*/
/*
void shiftDown(int arr[], int index, int size) {
	while (2 * index + 1 <= size - 1) {
		int left_child = 2 * index + 1;
		int right_child = 2 * index + 2;
		int high = index;
		if (left_child<size && arr[left_child]>arr[high]) {
			high = left_child;
		}
		if (right_child<size && arr[right_child]>arr[high]) {
			high = right_child;
		}
		if (high != index) {
			swap(arr[high], arr[index]);
			index = high;
		}
		else break;
	}
}

void heap_sort(int arr[], int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) {
		shiftDown(arr, i, size);
	}
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		shiftDown(arr, 0, i);
	}
}
int main() {
	int arr[] = { 22,76,9,7,57,75,99 };
	heap_sort(arr, 7);
	for (int i = 0; i < 7; i++)cout << arr[i]<<' ';
	return 0;
}
*/

// 线性探测哈希表 
/*
enum State {
	STATE_UNUSE,  // 从未使用过的桶
	STATE_USING,  // 正在使用的桶
	STATE_DEL,    // 元素被删除的桶
};
struct Bucket {
	int key_;
	State state_;
	Bucket(int key = 0, State state = STATE_UNUSE) :key_(key), state_(state) {}
};

class hashTable {

private:
	Bucket* table_;  // 指向动态开辟的哈希表
	int tableSize_;  // 哈希表当前的长度
	int useBucketNum_;   // 已经使用的桶的个数
	double loadFactor_;  // 哈希表的装载因子

	static const int PRIME_SIZE = 10;  // 素数表的大小
	static int primes[PRIME_SIZE];     // 素数表
	int primeIdx_;                     // 当前使用的素数表下标

	void expand() {
		primeIdx_++;
		if (primeIdx_ == PRIME_SIZE)throw "hashmap can not expand anymore";
		Bucket* newtable = new Bucket[primes[primeIdx_]];

		for (int i = 0; i < tableSize_; i++) {
			if (table_[i].state_ == STATE_USING) {
				int index = table_[i].key_ % primes[primeIdx_];
				int k = index;
				do {
					if (newtable[k].state_ != STATE_USING) {
						newtable[k].key_ = table_[i].key_;
						newtable[k].state_ = STATE_USING;
						break;
					}
					k = (k + 1) % primes[primeIdx_];
				} while (k != index);
			}
		}
		tableSize_ = primes[primeIdx];
		delete[] table_;
		table_ = newtable;
	}

public:
	hashTable(int size = primes[0], double loadFactor = 0.75) 
		:useBucketNum_(0)
		,loadFactor_(loadFactor)
		,primeIdx_(0)
	{
		// 把用户输入的size转化为素数表中的数
		if (size != primes[0]) {
			for (; primeIdx_ < PRIME_SIZE; primeIdx_++) {
				if (size < primes[primeIdx_])break;
			}
		}
		// 如果用户传入的size太大 就取最后一个
		if (primeIdx_ == PRIME_SIZE) primeIdx_--;

		tableSize_ = primes[primeIdx_];

		table_ = new Bucket[tableSize_];
	}

	~hashTable() {
		delete[] table_;
		table_ = nullptr;
	}

	// 插入操作
	bool push(int val) {
		double nowFactor = useBucketNum_ * 1.0 / tableSize_;
		if (nowFactor > loadFactor_) {
			expand();
		}

		int index = val % tableSize_;
		int i = index;
		do {
			if (table_[i].state_ != STATE_USING) {
				table_[i].state_ = STATE_USING;
				table_[i].key_ = val;
				useBucketNum_++;
				return true;
			}
			i = (i + 1) % tableSize_;
		} while (i!=index);
		return false;
	}

	// 删除操作
	void erase(int key) {
		int index = key % tableSize_;
		int i = index;
		do {
			if (table_[i].state_ == STATE_USING && table_[i].key_==key) {
				table_[i].state_ = STATE_DEL;
				useBucketNum_--;
			}
			i = (i + 1) % tableSize_;
		} while (table_[i].state_==STATE_UNUSE || i != index);
	}

	// 查询操作
	bool find(int key) {
		int index = key % tableSize_;
		int i = index;
		do {
			if (table_[i].state_ == STATE_USING && table_[i].key_ == key) {
				return true;
			}
		} while (table_[i].state_ != STATE_UNUSE || i != index);

		return false;
	}
};

int hashTable::primes[PRIME_SIZE] = { 3,7,23,47,97,251,443,991,1471,42773 };
*/

// 链式哈希表
/*
class hashtable {
private:
	vector<list<int>> hash_table;
	double loadFactor;
	int table_size;
	int usedBucketNum_;


	static const int PRIME_NUM = 10;
	static int primes[PRIME_NUM];
	int primesIdx;

	void expand() {
		primesIdx++;
		if (primesIdx==PRIME_NUM)throw "error";
		
		usedBucketNum_ = 0;
		table_size = primes[primesIdx];
		vector<list<int>> oldtable;
		oldtable.swap(hash_table);

		for (auto list : oldtable) {
			for (auto key : list) {
				int index = key % table_size;
				if (hash_table[index].empty())usedBucketNum_++;
				hash_table[index].emplace_front(key);
			}
		}


	}

public:
	hashtable(int size = 10, double factor = 0.75)
		:usedBucketNum_(0)
		, primesIdx(0)
		, loadFactor(factor)
	{
		if (size != primes[0]) {
			for (; primesIdx < PRIME_NUM; primesIdx++) {
				if (size < primes[PRIME_NUM])break;
			}
			if (primesIdx == PRIME_NUM)primesIdx--;
		}

		table_size = primes[primesIdx];
		hash_table.resize(table_size);
	}
	// 插入操作  (同一个键值只能插入一次)
	bool insert(int key) {
		double factor = 1.0 * usedBucketNum_ / table_size;
		if (factor > loadFactor)expand();

		int index = key % table_size;
		if (hash_table[index].empty()) {
			usedBucketNum_++;
			hash_table[index].emplace_front(key);
			return true;
		}
		else {
			auto it = ::find(hash_table[index].begin(), hash_table[index].end(), key);
			if (it == hash_table[index].end()) {
				hash_table[index].emplace_front(key);
				return true;
			}
		}
		return false;
	}
	// 删除元素
	bool erase(int key) {
		int index = key % table_size;
		auto it = ::find(hash_table[index].begin(), hash_table[index].end(), key);
		if (it != hash_table[index].end()) {
			hash_table[index].erase(it);
			if (hash_table[index].empty())usedBucketNum_--;
			return true;
		}
		return false;
	}

	// 查询元素
	bool find(int key) {
		int index = key % table_size;
		auto it = ::find(hash_table[index].begin(), hash_table[index].end(), key);
		return it != hash_table[index].end();
	}
};

int hashtable::primes[PRIME_NUM] = { 3,7,23,47,97,251,443,991,1471,42773 };
  
 */

// 大数据查重——哈希方法（速度快 但 空间消耗较大）
#if 0
#include<unordered_map>   // map 是 处理键值对的数据结构
#include<unordered_set>   // set 是 处理单个键的数据结构
#include<time.h>
#include<stdlib.h>
#include<vector>

int main() {
	vector<int> vec;

	srand(time(NULL));

	for (int i = 0; i < 1000; i++) {
		vec.push_back(rand() % 1000);
	}

	// 找第一个(所有)重复出现的数字
	/*
	unordered_set<int> s1;
	int cnt = 1;
	for (int key : vec) {
		auto it = s1.find(key);
		if (it != s1.end()) {
			cout << "第"<<cnt<<"个重复的数字为：" << key << endl;
			cnt++;
			break;  // 如果不加break 就只有第一个数字 加了就是所有重复数字
		}
		else s1.insert(key);
	}
	*/

	// 统计重复数字及其出现次数
	/*
	unordered_map<int, int> m1;
	for (int key : vec) {
		// 简写法
		m1[key]++;

		// 正常写法
		auto it = m1.find(key);
		if (it == m1.end()) {
			m1.emplace(key, 1);
		}
		else it->second += 1;
	}

	for (auto p1 : m1) {
		if (p1.second > 1) {
			cout << p1.first << ":" << p1.second << endl;
		}
	}

	*/

	// 重复数字过滤掉 每一个数字只出现一次(set的去重功能)
	/*
	unordered_set<int> s1;
	for (int key : vec) {
		s1.insert(key);
	}
	*/

}

#endif

// 大数据查重——位图法（节省空间 但 空间使用率不高）（但无法统计次数）
#if 0
int main() {

	// 第一个（所有）重复数字

	vector<int> num{ 1, 4, 6, 3, 65, 3, 2, 334, 57 };
	int max1 = 0;
	for (int k : num) {
		if (max1 < k)max1 = k;
	}
	int* bitmap = new int[max1 / 32 + 1](0);
	for (int k : num) {
		int index = k / 32;
		int offset = k % 32;
		if (0 == (bitmap[index] & (1 << offset))) {     // 与运算用来查询某一位
			bitmap[index] |= (1 << offset);             // 或运算用来赋值某一位
		}
		else {
			cout << "key: " << k << " " << "重复出现" << endl;
		}
	}
	delete[] bitmap;
	return 0;
}

#endif

// 大数据查重——布隆过滤器
/*
这里只写思路 不进行具体代码实现
大概就是位图法和哈希法的综合 依然设定bitmap数组 每一个值都用多个哈希函数来映射 得到不同的val 然后让位图里面对应的位设为1
查询时就查每一个映射过来的值是否被设为1 如果没有则一定不存在 如果有那就可能存在
*/

// top k 问题——大小根堆法
/*
// 找最大的前k个元素就是构建大小为k的小根堆 依次遍历数字 如果发现比堆顶大 就把堆顶删掉 加入此数
// 找最大的前k个元素就是构建大小为k的大根堆 依次遍历数字 如果发现比堆顶小 就把堆顶删掉 加入此数


// 求前k个小的数
#include<queue>
vector<int> res(int k, vector<int> num) {
	vector<int> ans;
	priority_queue<int> maxheap;

	for (int i = 0; i < k; i++)maxheap.push(num[i]);

	for (int i = k; i < num.size(); i++) {
		if (k < maxheap.top()) {
			maxheap.pop();
			maxheap.push(num[i]);
		}
	}

	while (!maxheap.empty()) {
		ans.push_back(maxheap.top());
		maxheap.pop();
	}

	return ans;
}

// 求前k个大的数

vector<int> res(int k, vector<int> num) {
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> minheap;

	for (int i = 0; i < k; i++)minheap.push(num[i]);

	for (int i = k; i < num.size(); i++) {
		if (minheap.top() < num[i]) {
			minheap.pop();
			minheap.push(num[i]);
		}
	}

	while (!minheap.empty()) {
		ans.push_back(minheap.top());
		minheap.pop();
	}

	return ans;
}
  
// 求重复次数前k大的数以及其次数
#include<unordered_map>
vector<pair<int, int>> res1(int k, vector<int> num) {
	vector<pair<int, int>> ans;
	unordered_map<int, int> hashmap;
	for (auto k : num)hashmap[k]++;

	using type = pair<int, int>;
	using comp = function<bool(const type&, const type&)>;
	priority_queue<type, vector<type>, comp> minheap([](const type& a, const type& b) {return a.second > b.second; });

	auto it = hashmap.begin();
	for (int i = 0; i < k; it++, i++) {
		minheap.emplace(*it);
	}

	for (int i = k; i < hashmap.size(); i++) {
		if (minheap.top().second < it->second) {
			minheap.pop();
			minheap.push(*it);
		}
	}

	while (!minheap.empty()) {
		ans.push_back(minheap.top());
		minheap.pop();
	}
	return ans;
}
 
// 求重复次数前k小的数字以及次数
vector<pair<int, int>> res2(int k, vector<int> num) {
	using type = pair<int, int>;
	using comp = function<bool(const type&, const type&)>;

	vector<type> ans;
	unordered_map<int, int> map;
	for (auto k : num)map[k]++;

	priority_queue<type, vector<type>, comp> maxheap([](const type& a, const type& b) {return a.second < b.second; });

	auto it = map.begin();
	for (int i = 0; i < k; i++, it++) {
		maxheap.emplace(*it);
	}

	for (int i = k; i < map.size(); i++, it++) {
		if (maxheap.top().second > it->second) {
			maxheap.pop();
			maxheap.push(*it);
		}
	}

	while (!maxheap.empty()) {
		ans.push_back(maxheap.top());
		maxheap.pop();
	}

	return ans;
}

*/
   
// top k 问题——快排分割法
/*
int TOPk(vector<int>& num, int begin, int end) {
	int flag = num[begin];
	int i = begin;
	int j = end;

	while (i < j) {
		while (i < j && num[j]>=flag)j--;
		if (i < j){
			num[i] = num[j]; i++;
		}
		while (i < j && num[i] <= flag)i++;
		if (i < j) { num[j] = num[i]; j--; }
	}

	num[i] = flag;

	return i;
}

void sortDivide(vector<int>& num,int begin,int end,int k) {
	int pos = TOPk(num, begin, end);
	if (pos == k - 1) {
		return;
	}
	else if (pos > k - 1) {
		sortDivide(num, begin, pos - 1, k);
	}
	else sortDivide(num, pos + 1, end, k);
}
 */

// 二叉搜索树BST
/*

// BST的特点是 左孩子的值 < 父节点的值 < 右孩子的值

class BSTree {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
		Node(int data_) :data(data_), left(nullptr), right(nullptr) {}
	};
	Node* root;
	
public:
	BSTree() :root(nullptr) {}
	~BSTree() {
		if (!root) {
			queue<Node*> q1;
			q1.push(root);
			while (!q1.empty()) {
				Node* front = q1.front();
				q1.pop();
				if (front->left)q1.push(front->left);
				if (front->right)q1.push(front->right);
				delete front;
			}
		}
	}

	// 非递归插入值  
	void insert(int val) {
		if (root == nullptr) {
			root = new Node(val);
			return;
		}
		Node* parent = nullptr;
		Node* cur = root;
		while (cur) {
			if (cur->data > val) {
				parent = cur;
				cur = cur->left;
			}
			else if (cur->data < val) {
				parent = cur;
				cur = cur->right;
			}
			else return;
		}

		if (parent->data > val) {
			parent->left = new Node(val);
		}
		else {
			parent->right = new Node(val);
		}
	}

	// 递归插入值
	Node* insertplus(Node* root,int val) {
		if (!root)return new Node(val);
		if(val<root->data) root->left = insertplus(root->left, val);
		else if(val>root->data) root->right = insertplus(root->right, val);
		return root;
	}

	// 非递归删除操作 （分三种情况 删除节点无孩子 有一个孩子 有两个孩子）
	void erase(int val) {
		if (!root)return;   // 树为空

		Node* parent = nullptr;
		Node* curr = root;
		while (curr) {
			if (curr->data == val)break;
			else if (val < curr->data) {
				parent = curr;
				curr = curr->left;
			}
			else {
				parent = curr;
				curr = curr->right;
			}
		}
		if (!curr)return;    // 没有val这个值的节点

		if (curr->left != nullptr && curr->right != nullptr) {
			parent = curr;
			Node* pre = curr->left;
			while (pre->right) {
				parent = pre;
				pre = pre->right;
			}
			curr->data = pre->data;
			curr = pre;
		}

		Node* child = curr->left;
		if (child == nullptr)child = curr->right;
		if (parent == nullptr)root = child;
		else {
			if (parent->left == curr)parent->left = child;
			else parent->right = child;
		}
		delete curr;
	}

	// 递归删除操作
	Node* eraseplus(Node* root, int val) {
		if (!root)return nullptr;

		if (val < root->data){
			root->left = eraseplus(root->left, val); 
		}
		else if (val > root->data){
			root->right = eraseplus(root->right, val);
		}
		else {
			if (root->left && root->right) {
				Node* pre = root->left;
				while (pre->right) {
					pre = pre->right;
				}

				root->data = pre->data;

				root->left = eraseplus(root->left, pre->data);
			}
			else {
				Node* child = (root->left == nullptr) ? root->right : root->left;
				delete root;
				return child;
			}
		}
		return root;
	}

	// 非递归查询操作
	bool find(int val) {
		Node* curr = root;
		while (curr) {
			if (curr->data == val)return true;
			else if (val < curr->data) curr = curr->left;
			else curr = curr->right;
		}
		return false;
	}

	// 递归查询操作
	bool findplus(Node* root, int val) {
		if (!root)return false;
		if (root->data == val)return true;
		else if (val < root->data)return findplus(root->left, val);
		else return findplus(root->right, val);
	}

	// 递归前中后序遍历
	void preorder(Node* node) {
		if (node) {
			cout << node->data << ' ';
			preorder(node->left);
			preorder(node->right);
		}
	}
	void inorder(Node* node) {
		if (node) {
			preorder(node->left);
			cout << node->data << ' ';
			preorder(node->right);
		}
	}
	void backorder(Node* node) {
		if (node) {
			preorder(node->left);
			preorder(node->right);
			cout << node->data << ' ';
		}
	}

	// 非递归前中后序遍历
	void preorderplus(Node* node) {
		if (!node)return;
		stack<Node*> s1;
		s1.push(node);
		while (!s1.empty()) {
			Node* top = s1.top();
			cout << top->data << ' ';
			s1.pop();
			if(node->right) s1.push(node->right);
			if(node->left)  s1.push(node->left);
		}
		return;
	}
	void inorderplus(Node* node) {
		if (!node)return;
		stack<Node*> s1;
		Node* curr = node;
		while (!s1.empty() || curr) {
			if (curr) {
				s1.push(curr);
				curr = curr->left;
			}
			else {
				Node* top = s1.top();
				cout << top->data << ' ';
				s1.pop();
				curr = top->right;
			}
		}
	}
	void backorderplus(Node* node) {
		if (!node)return;
		stack<Node*> s1;
		stack<Node*> s2;

		s1.push(node);
		while (!s1.empty()) {
			Node* top = s1.top();
			s1.pop();
			s2.push(top);
			if (top->left)s1.push(top->left);
			if (top->right)s1.push(top->right);
		}
		while (!s2.empty()) {
			cout << s2.top()->data << ' ';
			s2.pop();
		}
	}

	// 递归求二叉树高度
	int high(Node* node) {
		if (!node)return 0;
		int left = high(node->left);
		int right = high(node->right);
		return max(left, right) + 1;
	}

	// 递归求二叉树节点个数
	int nodeNum(Node* node) {
		if (!node)return 0;
		int left = nodeNum(node->left);
		int right = nodeNum(node->right);
		return left + 1 + right;
	}  

	// 递归层序遍历
	void levelorder(Node* node) {
		int h = high(node);
		for (int i = 0; i < h; i++) {
			levelorder_(node, i);
		}
	}
	void levelorder_(Node* node, int i) {
		if (!node)return;

		if (i == 0) {
			cout << node->data << ' ';
			return;
		}

		levelorder_(node->left, i - 1);
		levelorder_(node->right, i - 1);
	}

	// 非递归层序遍历
	void levelorder(Node* node) {
		if (!node)return;
		queue<Node*> q1;
		q1.push(node);
		while (!q1.empty()) {
			Node* front = q1.front();
			q1.pop();
			cout << front->data << ' ';
			if (front->left)q1.push(front->left);
			if (front->right)q1.push(front->right);
		}
	}

	// 寻找在区间[i,j]上的所有元素 (中序遍历的应用)
	void findvalues(int i, int j, vector<int>& vec, Node* node) {
		if (!node)return;
		if (node->data > i) findvalues(i, j, vec, node->left);
		if (node->data >= i && node->data <= j)vec.push_back(node->data);
		if (node->data < j)findvalues(i, j, vec, node->right);
	}

	// 判断一棵树是否为二叉搜索树（中序遍历的应用）
	bool isBST(Node* node) {
		Node* prev = nullptr;
		return inordercheck(node, prev);
	}
	bool inordercheck(Node* node, Node* &prev) {
		if (!node)return true;

		if (!inordercheck(node->left, prev))return false;

		if (prev && node->data <= prev->data)return false;
		prev = node;

		return inordercheck(node->right, prev);
	}

	// 判断一棵树是否为子树
	bool ischild(BSTree bst1) {
		if (bst1.root == nullptr)return true;

		Node* curr = root;
		while (curr) {
			if (curr->data == bst1.root->data)break;
			else if (curr->data < bst1.root->data)curr = curr->right;
			else curr = curr->left;
		}
		if (!curr)return false;

		return ischildtree(curr, bst1.root);
	}
	bool ischildtree(Node* node1, Node* node2) {
		if (!node1 && !node2)return true;
		if (!node1)return false;
		if (!node2)return true;

		if (node1->data != node2->data)return false;
		
		return ischildtree(node1->left, node2->left) && ischildtree(node1->right, node2->right);
	}

	// 最近公共节点
	int getLAC(int val1, int val2) {
		Node* root_ = LAC(root, val1, val2);
		if (!root_)throw "error";
		else return root_->data;
	}
	Node* LAC(Node* node, int val1, int val2) {
		if (!node)return nullptr;
		if (val1 < node->data && val2 < node->data)return LAC(node->left, val1, val2);
		else if (val1 > node->data && val2 > node->data)return LAC(node->right, val1, val2);
		else return node;
	}

	// 二叉树镜像反转
	void mirror(Node* node) {
		if (!node)return;
		
		Node* tem = node->left;
		node->left = node->right;
		node->right = tem;

		mirror(node->left);
		mirror(node->right);
	}

	// 二叉树镜像对称
	bool ismirror() {
		if (!root)return true;
		return ismirror(root->left, root->right);
	}
	bool ismirror(Node* node1, Node* node2) {
		if (!node1 && !node2)return true;
		if (!node1 || !node2)return false;
		if (node1->data != node2->data)return false;
		return ismirror(node1->left, node2->right) && ismirror(node1->right, node2->left);
	}

	// 利用前序遍历和中序遍历来重建二叉树
	Node* rebuild(int pre[], int i, int j, int in[], int m, int n) {
		if (i > j || m > n)return nullptr;

		Node* node = new Node(pre[i]);
		for (int k = m; k <= n; k++) {
			node->left = rebuild(pre, i + 1, i + k - m, in, m, k - 1);
			node->right = rebuild(pre, i + k - m + 1, j, in, k + 1, n);
			return node;
		}

		return node;
	}

	// 判断一棵树是否为二叉平衡树（左子树和右子树高度差不超过1）
	bool isAVL(Node* node) {
		return checkAVL(node) != -1;
	}
	int checkAVL(Node* node) {
		if (!node)return 0;

		int left = checkAVL(node->left);
		if (left == -1)return -1;

		int right = checkAVL(node->right);
		if (right == -1)return -1;

		if (abs(left - right) > 1)return -1;

		return max(left, right) + 1;
	}

	// 找到中序遍历倒数第k个节点
	int inorderK(Node* root, int k) {
		int cnt = 0; int res = 0;
		inorderk(root, k, cnt, res);
		return res;
	}
	void inorderk(Node* node, int k, int& cnt, int& res) {
		if (!node || cnt >= k)return;

		inorderk(node->right, k, cnt, res);

		if (cnt >= k)return;

		cnt++;
		if (cnt == k) {
			res = node->data;
			return;
		}
		inorderk(node->left, k, cnt, res);
	}

};

*/

// 二叉平衡搜索树AVL
/*
// AVL相对于BST其实就是多了一个保持节点平衡的思考 
// 节点平衡其实就是任意节点的左子树和右子树高度差不超过1

class AVLTree {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
		int height;
		Node(int data_) :data(data_), left(nullptr), right(nullptr), height(1) {}
	};
	Node* root;

	int high(Node* node) {
		return (node == nullptr) ? 0 : node->height;
	}

	// 右旋转操作 以某个节点的下一个节点为轴 这个节点和他下一个节点这个线段顺时针旋转 然后返回新的根节点
	// 解决的是左孩子的左子树太高的问题
	Node* right_rotate(Node* node) {
		// 右旋转
		Node* child = node->left;
		node->left = child->right;
		child->right = node;
		// 高度更新
		node->height = max(high(node->left), high(node->right)) + 1;
		child->height = max(high(child->left), high(child->right)) + 1;

		return child;
	}

	// 左旋转操作 以某个节点的下一个节点为轴 这个节点和他下一个节点这个线段逆时针旋转 然后返回新的根节点
	// 解决的是右孩子的右子树太高的问题
	Node* left_rotate(Node* node) {
		// 左旋转
		Node* child = node->right;
		node->right = child->left;
		child->left = node;
		// 高度更新
		node->height = max(high(node->left), high(node->right)) + 1;
		child->height = max(high(child->left), high(child->right)) + 1;

		return child;
	}

	// 左平衡操作( 孩左—父右 旋转操作) 解决的是左孩子的右子树太高的问题
	Node* left_balance(Node* node) {
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}

	// 右平衡操作( 孩右—父左 旋转操作) 解决的是右孩子的左子树太高的问题
	Node* right_banlance(Node* node) {
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}

public:
	AVLTree() :root(nullptr) {}

	// 插入操作(回溯时判断是否失衡)
	Node* insert(Node* node, int val) {
		if (!node)return new Node(val);
		if (val < node->data) {
			node->left = insert(node->left, val);
			// 如果失衡 必定左失衡
			if (high(node->left) - high(node->right) > 1) {
				// 左孩子的左子树太高
				if (high(node->left->left) >= high(node->left->right)) {
					node = right_rotate(node);
				}
				// 左孩子的右子树太高
				else node = left_balance(node);
			}
		}
		else if (val > node->data) {
			node->right = insert(node->right, val);
			// 如果失衡 必定右失衡
			if (high(node->right) - high(node->left) > 1) {
				// 右孩子的右子树太高
				if (high(node->right->right) >= high(node->right->left)) {
					node = left_rotate(node);
				}
				// 右孩子的左子树太高
				else node = right_banlance(node);
			}
		}

		node->height = max(high(node->left), high(node->right)) + 1;

		return node;
	}

	// 删除操作
	Node* erase(Node* node, int val)    {
		if (!node)return nullptr;
		if (val < node->data) {
			node->left = erase(node->left, val);
			// 删除左边可能导致右边不平衡
			if (high(node->right) - high(node->left) > 1) {
				// 右孩子的右子树太高
				if (high(node->right->right) >= high(node->right->left)) {
					node = left_rotate(node);
				}
				// 右孩子的左子树太高
				else node = right_banlance(node);
			}
		}
		else if (val > node->data) {
			node->right = erase(node->right, val);
			// 删除右边可能导致左边不平衡
			if (high(node->left) - high(node->right) > 1) {
				// 左孩子的左子树太高
				if (high(node->left->left) >= high(node->left->right)) {
					node = right_rotate(node);
				}
				// 左孩子的右子树太高
				else node = left_balance(node);
			}
		}
		else {
			if (node->left && node->right) {
				// 为了避免删除后造成失衡 就根据左右子树高度来判断删前驱还是后继
				if (high(node->left) >= high(node->right)) {
					// 删前驱
					Node* pre = node->left;
					while (pre->right)pre = pre->right;
					node->data = pre->data;
					node->left = erase(node->left, pre->data);
				}
				else {
					// 删后继
					Node* next = node->right;
					while (next->right)next = next->left;
					node->data = next->data;
					node->right = erase(node->right, next->data);
				}
			}

			else {
				Node* child = node->left ? node->left : node->right;
				delete node;
				return child;
			}
		}

		node->height = max(high(node->left), high(node->right)) + 1;

		return node;
	}
};
*/

// 红黑树
/* 红黑树本质上也是一种二叉平衡搜索树 不过它的平衡是弱平衡 AVL是强平衡
   红黑树4个性质 ： 1.每个节点都有颜色 黑/红    2. root 和 nullptr 必须是黑色
	                3.不能出现两个连续的红色 父与子一定不能全红     4.从根节点到任意叶子节点的路径上黑色节点个数必须相同
	根据红黑树性质可知：任意一个节点的左右子树一定存在 ：  长树长度 <= 2*短树长度 
*/
/*
class RBTree {
private:
	enum Color {
		BLACK,
		RED
	};
	struct Node {
		int data;
		Node* left;
		Node* right;
		Node* parent;
		Color color;
		Node(int data_, Node* left_ = nullptr, Node* right_ = nullptr, Node* parent_ = nullptr, Color color_ = BLACK)
			:data(data_), left(left_), right(right_), parent(parent_), color(color_) {
		}
	};

	Node* root;

	// 返回节点颜色
	Color getcolor(Node* node) {
		return node == nullptr ? BLACK : node->color;
	}
	// 设置节点颜色
	void setcolor(Node* node, Color color_) {
		node->color = color_;
	}
	// 返回节点左孩子
	Node* left(Node* node) { return node->left; }
	// 返回节点右孩子
	Node* right(Node* node) { return node->right; }
	// 返回节点父亲
	Node* parent(Node* node) { return node->parent; }

	// 左旋转 
	void left_rotate(Node* node) {
		Node* child = node->right;
		child->parent = node->parent;
		if (!node->parent) {
			root = child;
		}
		else {
			if (node->parent->left == node)node->parent->left = child;
			else node->parent->right = child;
		}

		node->right = child->left;
		if (child->left) {
			child->left->parent = node;
		}
		child->left = node;
		node->parent = child;
	}
	// 右旋转
	void right_rotate(Node* node) {
		Node* child = node->left;
		child->parent = node->parent;
		if (!node->parent) {
			root = child;
		}
		else {
			if (node->parent->left == node)node->parent->left = child;
			else node->parent->right = child;
		}
		node->left = child->right;
		if (child->right) {
			child->right->parent = node;
		}
		child->right = node;
		node->parent = child;
	}

	// 插入旋转调整
	void adjust(Node* node) {
		while (getcolor(parent(node)) == RED) {
			if (left(parent(parent(node))) == parent(node)) {
				Node* uncle = right(parent(parent(node)));
				if (getcolor(uncle) == RED) {
					setcolor(uncle, BLACK);
					setcolor(parent(parent(node)), RED);
					setcolor(parent(node), BLACK);
					node = parent(parent(node));
				}
				else {
					if (right(parent(node)) == node) {
						node = parent(node);
						left_rotate(node);  
					}
					setcolor(parent(node), BLACK);
					setcolor(parent(parent(node)), RED);
					right_rotate(parent(parent(node)));
					break;
				}
			}
			else {
				Node* uncle = left(parent(parent(node)));
				if (getcolor(uncle) == RED) {
					setcolor(uncle, BLACK);
					setcolor(parent(parent(node)), RED);
					setcolor(parent(node), BLACK);
					node = parent(parent(node));
				}
				else {
					if (left(parent(node)) == node) {
						node = parent(node);
						right_rotate(node);
					}
					setcolor(parent(node), BLACK);
					setcolor(parent(parent(node)), RED);
					left_rotate(parent(parent(node)));
					break;
				}
			}
		}
	}

	// 删除调整
	void fix_adjust(Node* node) {
		// 节点为黑色节点 这个时候就要往叔叔节点那边借黑 色节点
		while (getcolor(node) == BLACK) {
			if (left(parent(node)) == node) {
				// 节点在左子树
				Node* brother = right(parent(node));
				if (getcolor(brother) == RED) {
					setcolor(brother, BLACK);
					setcolor(parent(node), RED);
					left_rotate(parent(node));
					brother = right(parent(node));
				}
				else {
					if (getcolor(brother->left) == BLACK && getcolor(brother->right) == BLACK) {
						setcolor(brother, RED);
						node = parent(node);
					}
					else {
						if (getcolor(brother->right) != RED) {
							setcolor(brother, RED);
							setcolor(brother->left, BLACK);
							right_rotate(brother);
							brother = right(parent(node));
						}
						Color linshi = getcolor(brother);
						setcolor(brother, getcolor(parent(node)));
						setcolor(parent(node), linshi);
						setcolor(brother->right, BLACK);
						left_rotate(parent(node));
						break;
					}
				}
			}
			else {
				// 节点在右子树
				Node* brother = left(parent(node));
				if (getcolor(brother) == RED) {
					setcolor(brother, BLACK);
					setcolor(parent(node), RED);
					right_rotate(parent(node));
					brother = left(parent(node));
				}
				else {
					if (getcolor(brother->left) == BLACK && getcolor(brother->right) == BLACK) {
						setcolor(brother, RED);
						node = parent(node);
					}
					else { 
						if (getcolor(brother->left) != RED) {
							setcolor(brother, RED);
							setcolor(brother->right, BLACK);
							left_rotate(brother);
							brother = left(parent(node));
						}
						Color linshi = getcolor(brother);
						setcolor(brother, getcolor(parent(node)));
						setcolor(parent(node), linshi);
						setcolor(brother->left, BLACK);
						right_rotate(parent(node));
						break;
					}
				}
			}
		}
		// 节点为红色节点，就直接将这个节点变为黑色节点就行
		setcolor(node, BLACK);
	}
public:
	RBTree() :root(nullptr) {}

	void insert(int val) {
		if (!root) {
			root = new Node(val);
			return;
		}
		Node* par = nullptr;
		Node* curr = root;
		while (curr) {
			if (curr->data == val)return;
			par = curr;
			if (val < curr->data)curr = curr->left;
			else curr = curr->right;
		}
		Node* node = new Node(val, nullptr, nullptr, par, RED);
		if (val < par->data)par->left = node;
		else par->right = node;

		if (getcolor(par) == RED) {
			adjust(node);
		}
	}

	void erase(int val) {
		if (!root)return;
		Node* curr = root;
		while (curr) {
			if (curr->data == val)break;
			if (val < curr->data)curr = curr->left;
			else curr = curr->right;
		}
		if (!curr)return;

		if (curr->left && curr->right) {
			Node* pre = curr->left;
			while (pre->right)pre = pre->right;
			curr->data = pre->data;
			curr = pre;
		}

		Node* child = curr->left ? curr->left : curr->right;
		if (child) {
			child->parent = curr->parent;
			if (!curr->parent)root = child;
			else {
				if (curr == curr->parent->left) {
					curr->parent->left = child;
				}
				else curr->parent->right = child;

				Color c = getcolor(curr);
				delete curr;
				if (c == BLACK) {
					fix_adjust(child);
				}
			}
		}
		else {
			if (!parent(curr)) {
				delete curr;
				root = nullptr;
				return;
			}
			else {
				if (getcolor(curr) == BLACK) {
					fix_adjust(curr);
				}
				if (left(parent(curr)) == curr) {
					curr->parent->left = nullptr;
				}
				else curr->parent->right = nullptr;
				delete curr;
			}
		}
	}
};
*/      

// 树状数组
/*
树状数组和线段树相似但代码极短 可以解决的问题也相对较少
用于高效求数列前缀和  单点修改数据  
lowbit函数表示当前节点管几个数
*/   
/*
int n;  // n是序列元素个数  m是查询次数
int tr[10005];
int lowbit(int x) { return x & -x; }
// 单点更新(在位置i上加x 相互牵连的父亲节点也会加x)
void update(int i, int x) {
	while (i <= n) {
		tr[i] += x;
		i += lowbit(i);
	}
}
// 查询前缀和
int sum(int i) {
	int res = 0;
	// 达到每查一次范围缩小一半的O(logn)时间复杂度
	while (i > 0) {
		res += tr[i];
		i -= lowbit(i);  // 这就是缩小一半
	}
	return res;
}
// 查询区域前缀和
int rangeSum(int l, int r) { return sum(r) - sum(l-1); }

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		// 建树操作
		update(i, x);
	}
	return 0;
}
*/

// 求一个序列里面逆序对的个数——树状数组典例
/*
· 第一步是将待分析数组进行离散化操作 让数据范围变小 减小空间浪费
· 第二步是建立树状数组 一开始全部为0 之后一个一个数据分析 每分析一个数据就让ans+=(比该数大的已分析过的数据个数)
· 最后返回ans就行
*/
/*
#include<unordered_map>

int n;
vector<int> tr;

int lowbit(int x) { return x & -x; }
void update(int i,int val) {
	while (i <= n) {
		tr[i] += val;
		i += lowbit(i);
	}
}
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tr[i];
		i -= lowbit(i);
	}
	return res;
}

int reverseNum(vector<int>& num) {
	// 该步为找出所有不重复元素并升序排列
	vector<int> temp = num;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	// 该步为为每一个数字赋值 实现离散化 每个大数据都用位次来表示
	unordered_map<int, int> m1;
	for (int i = 0; i < temp.size(); i++)m1[temp[i]] = i + 1;


	// 上面都是离散化预处理 接下来才会用到树状数组 
	// 树状数组中会用到 最大数n 和 tr数组 需要在此处定义
	n = temp.size();
	tr.resize(n + 1, 0);

	int ans = 0;
	// 按原数组顺序依次取出数据 判断前面比该数据大的有几个 加到ans上
	for (int i = 0; i < num.size(); i++) {
		int idx = m1[num[i]];  // 数据 -> 位次
		ans += sum(n) - sum(idx);   // ans加上（总数 - 比该数据小的数）
		update(idx, 1);  // 该位次的数据多了1 同样该节点的父节点也会多1 以此类推
	}
	return ans;
}
*/

// 线段树  
/*
·线段树其实“就是”树状数组由数组写成树的形式
·由树状数组推导不难看出 树状数组其实是由下至上推的 从一个一个数据 变成一组一组数据 最后变成一个大数据
·线段树与之相反  其实是从根节点从上至下推导的 从一个大区间 一次一次折半划分 最后变成叶子结点只剩一个数据
·由于树的特殊结构 每个节点可以储存很多信息 通常来说 树状数组可以解决的问题 线段树都能解决 但是 树状数组功能要少一点
*/
/*
// 不封装
#define ll long long
const int N = 10010;
const int INF = 0x3f3f3f3f;

struct Node {
	int left, right;
	int maxn, minn;
	ll sum;
	int lazy;
}tree[N * 4];

int a[N];   // 原数组
int n;      //  数组大小

void pushup(int node) {
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].maxn = max(tree[node * 2].maxn, tree[node * 2 + 1].maxn);
	tree[node].minn = min(tree[node * 2].minn, tree[node * 2 + 1].minn);
}

void pushdown(int node) {
	if (tree[node].lazy != 0) {
		int x = tree[node].lazy;

		tree[node * 2].sum += (ll)x * (tree[node].right - tree[node].left + 1);
		tree[node * 2].maxn += x;
		tree[node * 2].minn += x;
		tree[node * 2].lazy += x;

		tree[node * 2 + 1].sum += (ll)x * (tree[node].right - tree[node].left + 1);
		tree[node * 2 + 1].maxn += x;
		tree[node * 2 + 1].minn += x;
		tree[node * 2 + 1].lazy += x;

		tree[node].lazy = 0;
	}
}

// 根据原数组建立tree线段树
void build(int node, int left_, int right_) {
	// 建当前节点
	tree[node] = { left_,right_,0,0,0,0 };
	
	if (left_ == right_) {
		tree[node].sum = a[left_];
		tree[node].maxn = a[left_];
		tree[node].minn = a[left_];
		return;
	}

	int mid = (tree[node].left + tree[node].right) >> 1;
	build(node * 2, left_, mid);  // 建当前节点的左子树
	build(node * 2 + 1, mid + 1, right_);  // 建右子树
	pushup(node);  // 更新该节点数据
}


// 区间操作

// 区间更新 在区间内每个数据都加val
void update(int node, int left_, int right_, int val) {
	// 节点区间在left_和right_之间(也就是这个节点的区间都需要更新)（全被包含重叠）
	if (tree[node].left >= left_ && tree[node].right <= right_) {
		tree[node].sum += (ll)val * (tree[node].right - tree[node].left + 1);
		tree[node].maxn += val;
		tree[node].minn += val;
		tree[node].lazy += val;
		return;
	}

	// 部分重叠 （部分重叠一定会向左右孩子分析 因此必须先处理懒操作）
	pushdown(node);

	// 部分重叠分析的结果就是 去左边找 或者去右边找 或者两边都有一部分
	int mid = (tree[node].left + tree[node].right) >> 1;
	if (left_ <= mid)update(node * 2, left_, right_, val);
	if (right_ > mid)update(node * 2 + 1, left_, right_, val);

	pushup(node);  // 更新当前节点所有数据    
}

struct RESULT {
	ll sum;
	int maxn, minn;
};

RESULT query(int node, int left_, int right_) {
	// 如果范围全被包含
	if (tree[node].left >= left_ && tree[node].right <= right_) {
		return { tree[node].sum, tree[node].maxn, tree[node].minn };
	}

	// 如果部分重叠
	pushdown(node);

	int mid = (tree[node].left + tree[node].right) >> 1;

	// 三种情况（只在左边 只在右边 两边都有）
	if (right_ <= mid)return query(node * 2, left_, right_);
	else if (left_ > mid)return query(node * 2 + 1, left_, right_);
	else {
		RESULT leftres = query(node * 2, left_, right_);
		RESULT rightres = query(node * 2 + 1, left_, right_);

		RESULT res;
		res.sum = leftres.sum + rightres.sum;
		res.maxn = max(leftres.maxn, rightres.maxn);
		res.minn = min(leftres.minn, rightres.minn);

		return res;
	}
}

// 单点操作


// 单点更新 (pos上加val)
void upd(int node, int pos, int val) {
	if (tree[node].left == tree[node].right) {
		tree[node].maxn += val;
		tree[node].minn += val;
		tree[node].sum += val;
		return;
	}
	pushdown(node);
	int mid = (tree[node].left + tree[node].right) >> 1;
	if (pos <= mid)upd(node * 2, pos, val);
	else upd(node * 2 + 1, pos, val);
	pushup(node);
}

// 单点查询(这里举例返回最大值)
int que(int node, int pos) {
	if (tree[node].left == tree[node].right) { return tree[node].maxn; }

	pushdown(node);
	int mid = (tree[node].left, tree[node].right) >> 1;
	if (pos <= mid)return que(node * 2, pos);
	else return que(node * 2 + 1, pos);
}

*/
/*
// 封装
#define ll long long
#define node tree[nodepos]
#define nodeL tree[nodepos<<1]
#define nodeR tree[nodepos<<1|1]

class SegmentTree {
private:
	struct Node {
		int left, right;
		int maxn;
		int sum;
		int lazy;
	};
	struct RESULT {
		int sum, maxn;
	};
	int n;

	vector<Node> tree;
	vector<int> nums;


	void pushup(int nodepos) {
		node.maxn = max(nodeL.maxn, nodeR.maxn);
		node.sum = nodeL.sum + nodeR.sum;
	}
	void pushdown(int nodepos) {
		if (node.lazy != 0) {
			int x = node.lazy;

			nodeL.sum += (ll)x * (nodeL.right - nodeL.left + 1);
			nodeL.maxn += x;
			nodeL.lazy += x;

			nodeR.sum += (ll)x * (nodeR.right - nodeR.left + 1);
			nodeR.maxn += x;
			nodeR.lazy += x;

			node.lazy = 0;
		}
	}
	void build(int nodepos, int l, int r) {
		if (l == r) {
			node = { l,r,nums[l],nums[r],0 };
			return;
		}
		else node = { l,r,0,0,0 };

		int mid = (l + r) >> 1;
		build(nodepos << 1, l, mid);
		build(nodepos << 1 | 1, mid + 1, r);
		pushup(nodepos);
	}

public:
	SegmentTree(int size, const vector<int>& nums1) :n(size), nums(nums1) {
		tree.resize(4 * (n + 1));
		build(1, 1, n);
	}
	void upd(int nodepos, int l, int r, int val) {
		if (node.left >= l && node.right <= r) {
			node.sum += (ll)val * (node.right - node.left + 1);
			node.maxn += val;
			node.lazy += val;
			return;
		}
		pushdown(nodepos);
		int mid = (node.left + node.right) >> 1;
		if (l <= mid)upd(nodepos << 1, l, r, val);
		if (r > mid)upd(nodepos << 1 | 1, l, r, val);
		pushup(nodepos);
	}
	RESULT query(int nodepos, int l, int r) {
		if (node.left >= l && node.right <= r) {
			return { node.sum,node.maxn };
		}
		pushdown(nodepos);
		int mid = (node.left + node.right) >> 1;
		if (r <= mid)return query(nodepos << 1, l, r);
		else if (l > mid)return query(nodepos << 1 | 1, l, r);
		else {
			RESULT leftRes = query(nodepos << 1, l, r);
			RESULT rightRes = query(nodepos << 1 | 1, l, r);
			return { leftRes.sum + rightRes.sum, max(leftRes.maxn, rightRes.maxn) };
		}
	}
	void updpoint(int nodepos, int pos, int val) {
		if (node.left == node.right) {
			node.sum += val;
			node.maxn += val;
			return;
		}
		pushdown(nodepos);
		int mid = (node.left + node.right) >> 1;
		if (pos <= mid)updpoint(nodepos << 1, pos, val);
		else updpoint(nodepos << 1 | 1, pos, val);

		pushup(nodepos);
	}
	// 其实单点就没必要求sum了 其实都是一个值 它本身
	RESULT quepoint(int nodepos, int pos) {
		if (node.left == node.right)return { node.sum,node.maxn };
		pushdown(nodepos);
		int mid = (node.left + node.right) >> 1;
		if (pos <= mid)return quepoint(nodepos << 1, pos);
		else return quepoint(nodepos << 1 | 1, pos);
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums1(n + 1);
	for (int i = 1; i <= n; i++)cin >> nums1[i];
	SegmentTree s1(n, nums1);
	auto res = s1.query(1, 2, 5);
	cout << res.maxn << endl << res.sum;
	auto res1 = s1.quepoint(1, 2);
	cout << res1.maxn << ' ' << res1.sum;
	return 0;
}
*/


// 图论基本知识
#if 0
/*
图也是一种存储数据的结构 它和树一样有节点 但是它不分根节点
图由多个节点构成 节点到节点之间没有或者有n条途经可以相互达到
*/
/*
·有向图：节点和节点之间的路径有单向性 分出向边和入向边 顶点可以自己指向自己
·无向图：路径没有单向性 不分出向边和入向边 顶点不能指向自己
·顶点的度：在有向图中 顶点的度分入度和出度  在无向图中 不分入度出度
*/

// 图的存储结构——邻接矩阵
/*
邻接矩阵顾名思义 用矩阵来存储图 
假设图里面有编号为 1,2,3,4,…,n  的n个顶点
那么矩阵就被定义为 n*n 大小 每一行的每一个数据表示该节点到别的节点 是否有路径 或者路径权重 一开始矩阵初始化为0
例如 1节点到2节点有路径 那么【1,2】这个节点为数据1
由此可知 对于有向图来说 每一列的数据和就代表着该节点的入度 每一行的数据和就代表该节点的出度
对于无向图来说 节点不能指向自己 那么对角线数据为0 左下和右上关于对角线对称
*/

// 图的存储结构——邻接表
/*
邻接表是一种图的链式存储结构 存储方式类似于链式哈希表
思路是将每一个顶点和与它相邻的顶点放入一个数组里面 其实就是放顶点和顶点能到达的所有顶点
也就是说 一个数组数据 它包含该顶点编号 以及 该顶点能到达的所有顶点的编号（权重）
能到达的所有顶点用链表存储
实际上就是数组里面存链表的一种思维

对于有向图来说 其实邻接表存的是出度  如果想要表示入度关系 需要用逆邻接表 思路一样
对于无向图来说 不分入度出度 只要相邻就存入链表

优点：相对于邻接矩阵 它的空间利用率达到百分百
缺点：有向图入度出度不能一起表示 无向图仍然存在冗余存储 删除和添加也不方便 需要搞两次

更好的存储方式：有向图：十字链表   无向图：邻接多重表
*/

// 有向图链式存储——十字链表 无向图链式存储——邻接多重表
/*
十字链表是邻接表的一个升级 实现了既有入度链表 又有出度链表 入度和出度都能够查询到
出度链表部分不变 入度链表部分是竖向穿插 大概思路就是这样
具体操作目前无须掌握
邻接多重表也难讲 目前不用掌握
*/

#endif

// 有向图邻接表(无权)(这里的实现就用最简单的二维数组)(面向竞赛)
/*
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 10010;

vector<int> g[N];
bool memo[N];

void dfs(int vertic) {
	memo[vertic] = true;
	cout << vertic << ' ';

	for (auto k : g[vertic]) {
		if (!memo[k]) {
			dfs(k);
		}
	}
}

void bfs(int vertic) {
	queue<int> q1;
	q1.push(vertic);
	memo[vertic] = true;

	while (!q1.empty()) {
		int x = q1.front();
		q1.pop();
		cout << x << ' ';
		for (auto l : g[x]) {
			if (!memo[l]) {
				memo[l] = true;
				q1.push(l);
			}
		}
	}
}

int main() {
	int n, m;   // n个顶点 m条边 一条边两个数据 默认顶点编号就是 1~n;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int begin, end;
		cin >> begin >> end;
		g[begin].push_back(end);
		// rg[end].push_back(begin);  无向图需要双向保存
	}
	// 其实写到这里就完了 就存储完了 接下来打印一下


	// 按顶点打印全部关系
	for (int i = 1; i <= n; i++) {
		cout << i << " -> ";
		for (auto k : g[i]) {
			cout << k << ' ';
		}    
		cout << endl;
	}

	// dfs遍历（因为图可能不是连通的 所以访问一个入口可能就无法访问到所有顶点 需要循环）
	memset(memo, 0, sizeof(memo));
	for (int i = 1; i <= n; i++) {
		if(!memo[i])dfs(i);
	}

	// bfs遍历（同样需要循环）
	memset(memo, 0, sizeof(memo));
	for (int i = 1; i < n; i++) {
		if (!memo[i])bfs(i);
	}

	return 0;
}
*/

// 有向图邻接表（有权）（其实都一样）
/*
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
const int N = 10010;
vector<pair<int, int>> g[N];
bool memo[N];

int n, m;

void dfs(int vertic) {
	memo[vertic] = true;
	cout << vertic << " ";

	for (auto k : g[vertic]) {
		if (!memo[k.first]) {
			dfs(k.first);
		}
	}
}

void bfs(int vertic) {
	queue<int> q1;
	q1.push(vertic);
	memo[vertic] = true;

	while (!q1.empty()) {
		int k = q1.front(); q1.pop();
		cout << k << ' ';
		for (auto k1 : g[k]) {
			if (!memo[k1.first]) {
				q1.push(k1.first);
				memo[k1.first] = true;
			}
		}
	}


}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		g[x].push_back({ y,z });
	}

	// 直接按位遍历
	for (int i = 1; i <= n; i++) {
		cout << i << " -> ";
		for (auto pair : g[i]) {
			cout << "( " << pair.first << "," << pair.second << " )";
		}
		cout << endl;
	}

	// dfs遍历
	memset(memo, 0, sizeof(memo));
	for (int i = 1; i <= n; i++) {
		if (!memo[i])dfs(i);
	}

	// bfs遍历
	memset(memo, 0, sizeof(memo));
	for (int i = 1; i <= n; i++) {
		if (!memo[i])bfs(i);
	}

	return 0;
}
  */

// 不带权值的最小路径问题
/*
// 类型一 普通图只求距离
#include<vector>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
const int N = 10010;

vector<int> g[N];
int dist[N];
int n, m;

void bfs_shorter_path(int start) {
	queue<int> q1;
	memset(dist, -1, sizeof(dist));

	q1.push(start);
	dist[start] = 0;

	while (!q1.empty()) {
		int top = q1.front(); q1.pop();
		for (auto k : g[top]) {
			if (dist[k] == -1) {
				dist[k] = dist[top] + 1;
				q1.push(k);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
	}
	bfs_shorter_path(1);
	for (int i = 1; i <= n; i++) {
		cout << 1 << " -> " << i << " : " << dist[i] << endl;
	}
	return 0;
}

// 类型二 普通图求距离和路径
const int N = 10010;
vector<int> g[N];
int dist[N];
int pre[N];
int n, m;

void bfs_shorter_path_and_path(int start) {
	queue<int> q1;
	memset(dist, -1, sizeof(dist));
	memset(pre, -1, sizeof(pre));

	q1.push(start);
	dist[start] = 0;

	while (!q1.empty()) {
		int top = q1.front(); q1.pop();
		for (auto k : g[top]) {
			if (dist[k] == -1) {
				dist[k] = dist[top] + 1;
				q1.push(k);
				pre[k] = top;
			}
		}
	}
}

vector<int> reversePath(int target) {
	vector<int> path;
	if (dist[target] == -1)return path;

	for (int i = target; i != -1; i = pre[i]) {
		path.push_back(i);
	}
	reverse(path.begin(), path.end());
	return path;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
	}
	bfs_shorter_path_and_path(1);

	return 0;
}

// 类型三 迷宫问题最短路径(s为起点 e为终点 ·为可走 #为不可走)
vector<vector<char>> board;
int dist[50][50];
int n, m;
int sx, sy, ex, ey;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && board[x][y] != '#';
}

void bfs() {
	queue<pair<int, int>> q1;
	q1.push({ sx,sy });
	memset(dist, -1, sizeof(dist));
	dist[sx][sy] = 0;

	while (!q1.empty()) {
		auto flag = q1.front(); q1.pop();
		for (int i = 0; i < 4; i++) {
			int xx = flag.first + dx[i], yy = flag.second + dy[i];
			if (check(xx, yy) && dist[xx][yy] == -1) {
				dist[xx][yy] = dist[flag.first][flag.second] + 1;
				q1.push({ xx,yy });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	board.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 's')sx = i, sy = j;
			if (board[i][j] == 'e')ex = i, ey = j;
		}
	}
	bfs();
	cout << dist[ex][ey];
	return 0;
}
*/
 
// Dijkstra单源最短路径算法（从起点到每个点的最短路径）（带正权值）（每次确定一个最短距离，然后用它去更新别人）
/*
#include<queue>
#include<utility>
#define PII pair<int,int>
const int N = 10010;
const int INF = 0x3f3f3f3f;

vector<PII> g[N];   // 存的是[顶点，权重]
int dist[N];
int pre[N];
int n, m;

void Dijkstra(int start) {
	memset(dist, 0x3f, sizeof(dist));
	memset(pre, -1, sizeof(pre));
	dist[start] = 0;

	priority_queue<PII, vector<PII>, greater<PII>> p1;  // 存的是[距离，顶点] 
	p1.push({ 0,start });

	while (!p1.empty()) {
		auto [dis,vertic] = p1.top();
		p1.pop();

		// 一个节点可能被push两次 第一次是那一次的最小 第二次更新了一下 
		// 如果第二次更新了 那么就直接删除掉第一次push进去的就行 不用操作
		if (dis > dist[vertic])continue;

		for (auto [next,weight] : g[vertic]) {
			if (dis + weight < dist[next]) {
				dist[next] = dis + weight;
				p1.push({dist[next], next});
				pre[next] = vertic;
			}
		}
	}
}
vector<int> reversePath(int target) {
	vector<int> path;
	if (dist[target] == INF)return path;
	for (int k = target; k != -1; k = pre[k]) {
		path.push_back(k);
	}
	reverse(path.begin(), path.end());
	return path;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].push_back({ y,z });
		g[y].push_back({ x,z });  // 无向图需要加这一行 只需要加这一行
	}
	Dijkstra(1);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) {
			cout << "起始节点节点1->" << i << "不可抵达" << endl;
		}
		else {
			cout << 1 << "->" << i << "的最短路径需" << dist[i] << endl;
		}
	}
	vector<int> pa = reversePath(5);
	if(pa.empty())cout << "起始节点节点1->" << 5 << "不可抵达" << endl;
	else {
		cout << "路径：";
		for (int k : pa)cout << k << "->";
	}
	return 0;
}
*/

// Bellman-Ford 单源最短路径算法（有负权值）
/*
#include<utility>
#define PII pair<int,int>
const int N = 1010;
vector<PII> edges[N];
int dist[N];
int n, m;

bool bellmanford(int u) {
	memset(dist, 0x3f, sizeof dist);
	dist[u] = 0;
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = false;
		for (int v = 1; v <= n; v++) {
			if (dist[v] == 0x3f3f3f3f)continue;
			for (auto [vertic, weight] : edges[v]) {
				if (dist[vertic] > dist[v] + weight) {
					dist[vertic] = dist[v] + weight;
					flag = true;
				}
			}
		}
		if (flag == false)break;
	}
	return flag;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edges[x].push_back({ y,z });
	}
	return 0;
}
*/

// Floyd多源最短路径算法（动态规划思想）
/*
const int N = 510;
int dp[N][N];
int n, m;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)dp[i][j] = 0;
			else dp[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		dp[x][y] = min(dp[x][y], z);
	}
	floyd();
	return 0;
}
*/

// LCA 标准倍增算法
/*
const int N = 2020;
int dep[N];
vector<int> g[N];
int fa[N][20];

void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	fa[u][0] = p;
	for (int i = 1; i <= 19; i++) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	for (int v : g[u]) {
		if (v != p)dfs(v, u);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v])swap(u, v);
	for (int i = 19; i >= 0; i--) {
		if (dep[fa[u][i]] >= dep[v])u = fa[u][i];
	}
	if (u == v)return v;
	for (int i = 19; i >= 0; i--) {
		if (fa[u][i] != fa[v][i])u = fa[u][i], v = fa[v][i];
	}
}
*/

// 并查集
/*
并查集顾名思义 是合并和查询集合的过程 用来合并集合和查询两个元素是否在同一集合
一个典型例子就是 a和b是朋友 c和d是朋友 那么如果a和c也是朋友 那么四人皆是朋友形成朋友圈
需要合并ab 合并cd 然后合并abcd 查询a d两人在同一集合互为朋友 a e不在同一集合 不互为朋友
很简单
*/
/*
const int size_ = 9;
int parent[size_];
int rank_[size_];

int find_(int x) {    // 普通版本 用来找根节点
	while (x != parent[x])x = parent[x];
	return x;
}

int find(int x) {  // 寻找x的父节点的编号 路径优化版本 可以把途中所有的父节点全部更新为根节点
	if (x != parent[x])parent[x] = find(parent[x]);
	return parent[x];
}

void merge_(int x, int y) {   // 合并两个独立集合 统一父节点
	x = find(x);
	y = find(y);
	if (x != y)parent[x] = y; // 如果本来就在一个集合里面 那就不需要合并了
}

void merge(int x, int y) {    // 加权优化
	x = find(x); y = find(y);
	if (x == y)return;

	// 矮的树要放到高的树里面 这样才能保证树高较低
	if (rank_[x] < rank_[y])parent[x] = y;
	else if (rank_[y] < rank_[x])parent[y] = x;
	else {
		parent[y] = x;
		rank_[x]++;
	}
}


bool is_connected(int x, int y) { return find(x) == find(y); }  // 判断两个元素是否在同一集合

int main() {
	// 初始化 先让每个节点的父节点为他自己 各自为一个独立集合
	for (int i = 0; i < size_; i++) {
		parent[i] = i;
		rank_[i] = 1;  // 加权优化
	}
	return 0;
}
*/
/*
// 最终优化版本
vector<int> parent;
vector<int> high;
int n, m;

int find(int x) {
	if (x != parent[x])parent[x] = find(parent[x]);
	return parent[x];
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (high[x] < high[y])parent[x] = y;
	else if (high[y] < high[x])parent[y] = x;
	else {
		parent[x] = y;
		high[y]++;
	}
}
bool is_connect(int x, int y) {
	return find(x) == find(y);
}

int main() {
	cin >> n >> m;
	parent.resize(n + 1);
	high.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		high[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
	}
	return 0;
}
*/

// 并查集应用——最小生成树kruskal算法
/*
这个是用来实现最小代价达成各点连通 主要方法是把所有边按权重从小到大排列 依次选小的边
如果选了这个边不能形成环 那么就需要选这个边 如果能形成环就不选这个边 能不能形成环就看原先这条边的两个节点是否可以连通（根节点是否一致）
选够n-1条边就结束 如果选不出这么多 说明就不是连通图
*/
/*
#include<algorithm>
struct edge {
	int start, end, weight;
	edge(int s, int e, int w) :start(s), end(e), weight(w) {}
};
vector<edge> edges;  // 存储边
vector<int> parent;  // 存储每个点的根节点
vector<edge> res;
int n, m; // n个节点 m条边

int find(int x) {
	if (x != parent[x])parent[x] = find(parent[x]);
	return parent[x];
}
bool is_connected(int x, int y) { return find(x) == find(y); }

int main() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edges.push_back({ x, y, z });
	}
	sort(edges.begin(), edges.end(), [](auto& a, auto& b) {return a.weight < b.weight; });
	for (int i = 0; i < edges.size(); i++) {
		int a = edges[i].start;
		int b = edges[i].end;
		if (!is_connected(a, b)) {
			res.push_back({ a,b,edges[i].weight });
			parent[find(a)] = find(b);
		}
		if (res.size() == n - 1)break;
	}
	if (res.size() != n - 1)cout << "不是连通图" << endl;
	return 0;
}
*/


// 字符串算法
// BF算法——模式匹配
/*
int bfsearch(const string& ori, const string& pat) {
	int n = ori.size();
	int m = pat.size();
	if (n < m)return -1;

	for (int i = 0; i <= n-m; i++) {
		int j = 0;
		while (j < m && ori[i + j] == pat[j])j++;
		if (j == m)return i;
	}

	return -1;
}
*/

// manacher算法——最长回文子串
/*
string manacher(const string& s) {
	string t = "^#";
	for (auto k : s) {
		t += k; t += '#';
	}
	t += '$';
	int n = t.size();
	vector<int> p(n, 0);
	int center = 0; int right = 0;
	int maxLen = 0; int maxCen = 0;
	for (int i = 1; i < n - 1; i++) {
		int mirror = 2 * center - i;
		p[i] = i < right ? min(p[mirror], right - i + 1) : 1;
		while (t[i + p[i]] == t[i - p[i]])p[i]++;

		if (p[i] + i - 1 > right) {
			right = p[i] + i - 1;
			center = i;
		}
		if (p[i] > maxLen) {
			maxLen = p[i];
			maxCen = i;
		}
	}
	int start = (maxCen - maxLen + 1) >> 1;
	return s.substr(start, maxLen - 1);
 }
 */

// KMP算法——模式匹配
/*
遍历一次实现模式匹配 借助相同前后缀来实现
*/
/*
vector<int> getNext(string& s) {
	int m = s.size();
	vector<int> next(m, 0);
	int n = 0;
	int i = 1;
	while (i < m) {
		if (s[i] == s[n]) {
			next[i] = n + 1; i++; n++;
		}
		else {
			if (n == 0)next[i++] = 0;
			else n = next[n - 1];
		}
	}
	return next;
}

int KMP(string& ori, string& pat) {
	vector<int> next = getNext(pat);
	int i = 0, j = 0;
	while (i < ori.size()) {
		if (ori[i] == pat[j]) {
			i++, j++;
		}
		else {
			if (j == 0)i++;
			else j = next[j - 1];
		}
		if (j == pat.size())return i - j;
	}
	return -1;
}
*/

// 字典树
/*
// 类封装
#include<map>
class Tire {
private:
	struct Node {
		char data;
		int freqs;
		map<char, Node*> nodemap;   // map会按照key的大小升序排列
		Node(char ch, int freq) :data(ch), freqs(freq) {}
	};
	Node* root;

	void preOrder(Node* cur, string word, vector<string>& wordlist) {
		// 处理当前节点
		if (cur != root) {
			word.push_back(cur->data);
			if (cur->freqs > 0)wordlist.push_back(word);
		}
		// 处理孩子
		for (auto [char_,node_] : cur->nodemap) {
			preOrder(node_, word, wordlist);
		}
	}

public:
	Tire() {
		root = new Node('\0', 0);
	}
	void add(string& word) {
		Node* curr = root;
		for (int i = 0; i < word.size(); i++) {
			auto childfind = curr->nodemap.find(word[i]);
			if (childfind == curr->nodemap.end()) {
				Node* child = new Node(word[i],0);
				curr->nodemap.emplace(word[i], child);
				curr = child;
			}
			else {
				curr = childfind->second;
			}
		} 
		curr->freqs++;
	}
	int query(string& word) {
		Node* curr = root;
		for (int i = 0; i < word.size(); i++) {
			auto childit = curr->nodemap.find(word[i]);
			if (childit == curr->nodemap.end()) return 0;
			curr = childit->second;
		}
		return curr->freqs;
	}
	void preorder() {
		string word; vector<string> wordlist;
		preOrder(root, word, wordlist);
		for (auto k : wordlist) {
			cout << k << endl;
		}
	}
	vector<string> queryPrefix(const string& prefix) {
		Node* curr = root;
		for (int i = 0; i < prefix.size(); i++) {
			auto childit = curr->nodemap.find(prefix[i]);
			if (childit == curr->nodemap.end())return {};
			curr = childit->second;
		}
		// 此时 curr 应该指向 prefix 的最后一个字符
		vector<string> res;
		preOrder(curr, prefix.substr(0, prefix.size() - 1), res);
		return res;
	}
	void remove(const string& word) {
		Node* curr = root;
		Node* del = root;  // 从这个节点开始删除
		char delch = word[0];
		for (int i = 0; i < word.size(); i++) {
			auto childit = curr->nodemap.find(word[i]);
			if (childit == curr->nodemap.end())return;
			
			if (curr->freqs > 0 || curr->nodemap.size() > 1) {
				del = curr;
				delch = word[i];
			}
			
			curr = childit->second;
		}
		// 此时curr为word最后一个字符 该单词存在
		if (curr->nodemap.empty()) {
			// 开始删除
			Node* child = del->nodemap[delch];
			del->nodemap.erase(delch);

			queue<Node*> q1; 
			q1.push(child);

			while (!q1.empty()) {
				Node* front = q1.front(); q1.pop();
				for (auto [char_, node] : front->nodemap) {
					q1.push(node);
				}
				delete front;
			}
		}
		else curr->freqs = 0;
	}
};
*/
/*
// 不封装数组实现
const int N = 10010;
int trie[N][26];  // trie[i][j] 表示从i节点经过j字符到达的下一个节点 j是下一个节点的字符
int cnt[N];
int sum[N];   // 计算节点孩子数量 也是相同前缀的单词的数量
int tot = 0;

void insert(const string& word) {
	int p = 0;
	for (int i = 0; i < word.size(); i++) {
		int zifu = word[i] - 'a';
		if (!trie[p][zifu]) {
			trie[p][zifu] = ++tot;
		}
		p = trie[p][zifu];
		sum[p]++;
	}
	cnt[p]++;
}
 
int query(const string& word) {
	int p = 0;
	for (int i = 0; i < word.size(); i++) {
		int zifu = word[i] - 'a';
		if (!trie[p][zifu])return 0;
		p = trie[p][zifu];
	}
	return cnt[p];
}

int startWith(const string& prefix) {
	int p = 0;
	for (int i = 0; i < prefix.size(); i++) {
		int zifu = prefix[i] - 'a';
		if (!trie[p][zifu])return 0;
		p = trie[p][zifu];
	}
	return sum[p];
}
*/

// 字典树——01trie
/*
const int BIT = 31;  // 处理32位整数
const int N = 10010; // 整数个数
int trie[BIT*N][2];
int val[BIT*N];
int tot = 0;

void insert(const int& num) {
	int p = 0;
	for (int i = BIT; i >= 0; i--) {  // 从高位到低位存储 方便高位优先异或
		int idx = num >> i & 1;
		if (!trie[p][idx])trie[p][idx] = ++tot;
		p = trie[p][idx];
	}
	val[p] = num;
}

int query(const int& num) {
	int p = 0;
	int res = 0;   // 异或出来的最大值
	for (int i = BIT; i >= 0; i--) {
		int idx = num >> i & 1;
		if (trie[p][!idx]) {
			res |= 1 << i;
			p = trie[p][!idx];
		}
		else p = trie[p][!idx];
	}
	return res;
	// return val[p]
}
*/

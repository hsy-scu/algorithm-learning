#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

//// 链表的定义
//
//// 先定义节点 一个节点包含这个节点所指向的数据和下一个节点的地址
//struct Node {
//	int date;
//	Node* next;
//};
//
//// 循环遍历函数封装
//void printList(Node* point) {
//	while (point != nullptr) {
//		// 读数据
//		cout << point->date << endl;
//		// point 偏移
//		point = point->next;
//	}
//}
//
//// 递归遍历
//void printRelist(Node* point) {
//	if (point != nullptr) {
//		// 读数据
//		cout << point->date << endl;
//		// point 偏移
//		point = point->next;
//		printRelist(point);
//	}
//}
//
//// 计算节点个数
//int Node_number(Node* point) {
//	int cnt = 0;
//	while (point != nullptr) {
//		// 计数器加加
//		cnt++;
//		// point 偏移
//		point = point->next;
//	}
//	return cnt;
//}
//
//
//// 后插法插入节点
//// 因为前插法要用二级指针 所以也给后插法用一下 保持一致
//void insertNode_back(Node** head, int date, Node* newNode) {
//	Node* point = *head;
//	while (point != nullptr) {
//		if (point->date == date) {
//			newNode->next = point->next;
//			point->next = newNode;
//		}
//		// point 偏移
//		point = point->next;
//	}
//}
//
//
//// 前插法插入节点
//// 前插法需要用到二级指针 因为可能要改变头节点的指针
//void insertNode_front(Node** head, int date, Node* newNode) { 
//	Node* point = *head;   
//	if (point->date == date) {
//		newNode->next = point;  
//		*head = newNode;  // 改变头节点指针
//	}
//	else {
//		while (point->next != nullptr) {
//			if (point->next->date == date) {
//				newNode->next = point->next;
//				point->next = newNode;
//			}
//		}
//	}
//}
//
//// 删除节点
//void deleteNode(Node** head, int date) {
//	Node* point = *head;
//	if (point->date == date) {
//		*head = point->next;
//	}
//	else {
//		while (point->next != nullptr) {
//			if (point->next->date == date) {
//				point->next = point->next->next;
//			}
//			point = point->next;
//		}
//	}
//}
//
//// 查找节点并且修改节点的值
//bool searchNode(Node** head, int date) {
//	Node* point = *head;
//	while (point->next != nullptr) {
//		if (point->date == date) {
//			point->date = 99;
//			return true;
//		}
//		point = point->next;
//	}
//	return false;
//}
//
//int main() {
//	Node node1 = { 11,nullptr };
//	Node node2 = { 22,nullptr };
//	Node node3 = { 33,nullptr };
//	Node node4 = { 44,nullptr };
//	Node node5 = { 55,nullptr };
//	Node node6 = { 66,nullptr };
//	node1.next = &node2;
//	node2.next = &node3;
//	Node* head = &node1;
//	
//	// 链表的遍历
//
//	// 暴力傻逼遍历
//	cout << node1.date << endl << node1.next->date << endl << node1.next->next->date << endl;
//	cout << endl;
//
//	// 循环遍历 以及其函数封装
//	Node* point = &node1;
//	while (point != nullptr) {
//		// 读数据
//		cout << point->date << endl;
//		// point 偏移
//		point = point->next; 
//	}
//	cout << endl;
//	// 循环遍历函数封装
//	printList(head);
//	cout << endl;
//
//	// 递归遍历
//	printRelist(head);
//	cout << endl;
//
//	// 获取节点个数
//	cout<<Node_number(head)<<endl;
//	cout << endl;
//
//	// 后插法插入节点  就是在一个节点的后面插入节点
//	insertNode_back(&head, 22, &node4); // 从头节点开始找 找到22这个节点 然后把node4插入22的那个节点后面
//	// 不能连续插入两个相同的节点 不然会循环链表 你插入的这个相同的节点会指向你自己 修改其中一个的指向对象就会修改的另一个
//	printList(head);
//	cout << Node_number(head) << endl;
//	cout << endl;
//
//	// 前插法插入节点 就是在一个节点的前面插节点
//	insertNode_front(&head, 11, &node5);
//	insertNode_front(&head, 55, &node6);
//	printList(head);
//	cout << endl;
//
//	// 删除节点
//	deleteNode(&head, 55);
//	deleteNode(&head, 66);
//	printList(head);
//	cout << Node_number(head) << endl;
//	cout << endl;
//
//	// 查找节点并且修改值
//	searchNode(&head, 22);
//	printList(head);
//	cout << Node_number(head) << endl;
//}
//
//
//
//
//
// 动态链表
//struct Node {
//	int date;
//	Node* next;
//};
//
//// 打印链表
//void printRelist(Node** head) {
//	Node* point = *head;
//	if (point != nullptr) {
//		// 读数据
//		cout << point->date << endl;
//		// point 偏移
//		point = point->next;
//		printRelist(&point);
//	}
//}
//
//
//// 头部位置添加节点 向前添加
//void addFromFront(Node** head, int date) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->date = date;
//	newNode->next = nullptr;
//	if (*head == nullptr) {
//		*head = newNode;
//	}
//	else {
//		newNode->next = *head;
//		*head = newNode;
//	}
//}
//
//// 头部位置添加节点 向后添加
//void addFromBack(Node** head, int date) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->date = date;
//	newNode->next = nullptr;
//	if (*head == nullptr) {
//		*head = newNode;
//	}
//	else {
//		Node* point = *head;
//		while (point->next != nullptr) point = point->next;
//		point->next = newNode;
//	}
//}
//
//// 删除这种动态分配的元素
//void deleteNode(Node** head, int date) {
//	Node* point = *head;
//	if (point->date == date) {
//		*head = point->next;
//		free(point);
//	}
//	else {
//		while (point->next != nullptr) {
//			if (point->next->date == date) {
//				Node* deleteNode = point->next;  // 先保存一下要删的点
//				point->next = point->next->next;
//				free(deleteNode);
//			}
//			point = point->next;
//		}
//	}
//}
//
//int main() {
//	Node* head = nullptr;
//
//	// 前添加
//	//addFromFront(&head, 99);
//	//addFromFront(&head, 188);
//
//	// 后添加
//	addFromBack(&head, 23);
//	addFromBack(&head, 33);
//	addFromBack(&head, 43);
//
//	// 删除节点
//	deleteNode(&head, 33);
//
//	printRelist(&head);
//	return 0;
//}




// 循环链表
//struct Node {
//	int data;
//	Node* next;
//};
//
//void printList(Node* head){
//	if (head != nullptr) {
//		Node* point = head;
//		do {
//			cout << point->data << ' ';
//			point = point->next;
//		} while (point != head);
//	}
//}
//
//// 头插法
//void addFront(Node** head, int data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = newNode;
//	if (*head == nullptr)*head = newNode;
//	else {
//		Node* point = *head;
//		while (point->next != *head)point = point->next;
//		point->next = newNode;
//		newNode->next = *head;
//		*head = newNode;
//	}
//}
//
//// 尾插法
//void addBack(Node** head, int data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = nullptr;
//	if (*head == nullptr) {
//		*head = newNode;
//		newNode->next = *head;
//	}
//	else {
//		newNode->next = *head;
//		Node* point = *head;
//		while (point->next != *head)point = point->next;
//		point->next = newNode;
//	}
//}
//
//
//int main() {
//	Node* head = nullptr;
//	addFront(&head, 1);
//	addFront(&head, 2);
//	addFront(&head, 3);
//	addBack(&head, 4);
//	addBack(&head, 5);
//	printList(head);
//	return 0;
//}



//// 双向循环链表
//struct Node {
//	Node* prev;
//	int data;
//	Node* next;
//};
//
//// 循环遍历
//void printList(Node* point, bool if_front) {
//	if (point != nullptr) {
//		Node* cur_point = point;
//		if (if_front) {
//			do {
//				cur_point = cur_point->prev;
//				cout << cur_point->data << "<-->";
//			} while (cur_point != point);
//		}
//		else {
//			do {
//				cout << cur_point->data << "<-->";
//				cur_point = cur_point->next;
//			} while (cur_point != point);
//		}
//	}
//}
//
//// 添加数据
//void addNode(Node** head, int data, bool if_front) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->prev = newNode;
//	newNode->next = newNode;
//	if (*head == nullptr)*head = newNode;
//	else {
//		// 第一个节点
//		Node* first = *head;
//		// 最后一个节点
//		Node* fina = first->prev;
//		// 处理头节点部分
//		first->prev = newNode;
//		newNode->next = first;
//		// 处理尾节点部分
//		fina->next = newNode;
//		newNode->prev = fina;
//		// 其实以上步骤可以看做前插也可以看做尾插
//
//		// 关键在下一步要不要改变头节点
//		if (if_front) *head = newNode;
//	}
//}
//
//
//int main() {
//	Node* head = nullptr;
//	addNode(&head, 1, false);
//	addNode(&head, 2, false);
//	addNode(&head, 3, false);
//	printList(head, true);
//	cout << endl;
//	printList(head, false);
//
//	return 0;
//}



//class NodeList {
//private:
//	struct Node {
//		int data;
//		Node* next;
//		Node(int val) :data(val), next(nullptr) {}
//	};
//
//public:
//	Node* head;
//	int size;
//	// 创建初始化链表
//	NodeList() :head(nullptr), size(0) {}
//
//	// 前插法
//	void insertAtHead(int val) {
//		Node* newNode = new Node(val);
//		newNode->next = head;
//		head = newNode;
//		size++;
//	}
// 
//	// 后插法
//	void insertAtTail(int val) {
//		Node* newNode = new Node(val);
//		if (head == nullptr) {
//			head = newNode;
//		}
//		else {
//			Node* temp = head;
//			while (temp->next != nullptr)temp = temp->next;
//			temp->next = newNode;
//		}
//		size++;
//	}
// 
//	// 从某个元素后面插(第Index个元素后面)
//	void insertAtIndex(int index, int val) {
//		if (index<0 || index>size)return;
//		Node* newNode = new Node(val);
//
//		if (index == 0) {  // 相当于前插法插首个元素
//			newNode->next = head;
//			head = newNode;
//			return;
//		}
//		Node* temp = head;
//		for (int i = 0; i < index - 1; i++) {
//			temp = temp->next;
//		}
//		newNode->next = temp->next;
//		temp->next = newNode;
//		size++;
//
//	}
//
//	// 删除元素
//	// 删除头部元素
//	void deleteAtHead() {
//		if (head == nullptr)return;
//		Node* temp = head;
//		head = head->next;
//		delete temp;
//		size--;
//	}
//	//删除尾部元素
//	void deleteAtTail() {
//		if (head == nullptr)return;
//		if (head->next == nullptr) {
//			delete head;
//			head = nullptr;
//		}
//		else{
//			Node* temp = head;
//			while (temp->next->next != nullptr)temp = temp->next;
//			delete temp->next;
//			temp->next = nullptr;
//		}
//		size--;
//	}
//
//	// 遍历链表
//	void printList() {
//		Node* temp = head;
//		while (temp!= nullptr) {
//			cout << temp->data << ' ';
//			temp = temp->next;
//		}
//	}
//
//	// 双指针的一些操作
//
//	// 快慢指针找中间节点(奇数个节点就返回中间那个 偶数个返回靠右那个)
//	Node* findMiddle(Node* head) {
//		Node *slow = head, *fast = head;
//		while (fast && fast->next) {
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		return slow;
//	}
//
//	// 快慢指针判断是否为环
//	bool if_circle(Node* head) {
//		Node* slow = head, * fast = head;
//		while (fast && fast->next) {
//			slow = slow->next;
//			fast = fast->next->next;
//			if (slow == fast)return true;
//		}
//		return false;
//	}
//
//	// 找到环的入口(环可以是内部的环)（1 -> 2 -> 3 -> 4 -> 5 -> 3（5指向3形成环））
//	Node* findcircle(Node* head) {
//		Node* slow = head, * fast = head;
//		while (fast && fast->next) {
//			slow = slow->next;
//			fast = fast->next->next;
//			if (slow == fast)break;
//		}
//		if (!fast || !fast->next)return nullptr;
//
//		slow = head; // 思路就是让一个指针到相遇点 一个指针到头节点 再次相遇的点就是环入口点
//		while (slow != fast) {
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//
//	// 反转链表
//	// 迭代法翻转链表
//	Node* reverseList(Node* head) {
//		Node* prev = nullptr;
//		Node* cur = head;
//		while (cur != nullptr) {
//			Node* nextNode = cur->next; // 保存下一个节点
//			cur->next = prev; // 当前节点指向前一个节点
//			prev = cur;    // 让前一个节点为当前节点
//			cur = nextNode; // 让当前节点为下一个节点
//		}
//		return prev;  // 返回的是头节点
//	}
//	// 递归法反转链表
//	Node* reverseList1(Node* head) {
//		if (!head || !head->next)return head;
//		Node* newHead = reverseList(head->next);  // 这一步就是把head后面的所有都翻转 这个时候newHead为头 head->next为尾
//		head->next->next = head;  // 最后一个节点的下一个节点是头节点
//		head->next = nullptr;  // 让头节点后面啥也没有变成尾节点
//		return newHead;
//	}
//
//	// 反转部分链表
//	Node* reversePart(Node* head, int left, int right) {
//		if (!head || left==right)return head;
//		// 虚拟头结点
//		Node* unrealHead = new Node(0);
//		unrealHead->next = head;
//		Node* pre = unrealHead;
//		// 找到要反转部分的前一个节点
//		for (int i = 0; i < left - 1; i++) {
//			pre = pre->next;
//		}
//		// 开始反转
//		Node* cur = pre->next;
//		Node* nextNode = nullptr;
//		for (int i = 0; i < right - left; i++) {
//			nextNode = cur->next;
//			cur->next = nextNode->next;
//			nextNode->next = pre->next;
//			pre->next = nextNode;
//		}
//		// 释放内存
//		Node* newHead = unrealHead->next;
//		delete unrealHead;
//		return newHead;
//	}
//
//
//	// 链表归并排序(合并两个有序链表和归并深入)
//	// 合并两个有序链表
//	Node* mergeTwoList(Node* L1, Node* L2) {
//		Node* unrealHead = new Node(0);
//		Node* tail = unrealHead;
//		while (L1 && L2) {  // 两个链表都有节点
//			if (L1->data < L2->data) {
//				tail->next = L1;
//				L1 = L1->next;
//			}
//			else {
//				tail->next = L2;
//				L2 = L2->next;
//			}
//			tail = tail->next;
//		}
//		tail->next = L1 ? L1 : L2;  // 直接接上L1或者L2剩余的节点
//		Node* newHead = unrealHead->next;
//		delete unrealHead;
//		return newHead;
//	}
//	// 归并实现
//	Node* sortList(Node* head) {
//		if (!head || !head->next)return head;
//		// 找到中间节点
//		Node* fast = head, * slow = head, * prev = nullptr;
//		while (fast && fast->next) {
//			prev = slow;
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		// prev始终在slow前一个
//		prev->next = nullptr;  // 切断链表
//		// 逐个排序
//		Node* L1 = sortList(head);
//		Node* L2 = sortList(slow);
//		// 合并
//		return mergeTwoList(L1, L2);  
//	}
//
//	// 回文链表
//	// 回文链表可以有多种思路 可以将所有数据放入vector里面然后再双指针做法
//	// 这里将用一种空间复杂度O(1)的方法做(思路是把链表后半部分反转 再跟前半部分比较)
//	Node* reverse(Node* head) {
//		if (!head || !head->next)return head;
//		Node* prev = nullptr;
//		Node* curr = head;
//		while (curr) {
//			Node* nextNode = curr->next;
//			curr->next = prev;
//			prev = curr;
//			curr = nextNode;
//		}
//		return prev;
//	}
//	bool if_huiwen(Node* head) {
//		if (!head || !head->next) return true;
//		Node* slow = head, * fast = head->next;
//		while (fast && fast->next) {
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		Node* baocun = slow->next;
//		slow->next = nullptr;
//		Node* headA = reverse(baocun);
//		Node* temp1 = head;
//		Node* temp2 = headA;
//		while (temp2) {
//			if (temp1->data != temp2->data) {
//				headA = reverse(headA);
//				slow->next = headA;
//				return false;
//			}
//			temp1 = temp1->next;
//			temp2 = temp2->next;
//		}
//		headA = reverse(headA);
//		slow->next = headA;
//		return true;
//	}
//
//
//	// 析构函数释放内存
//	~NodeList() {
//		Node* temp = head;
//		while(temp != nullptr) {
//			Node* delNode = temp->next;
//			delete temp;
//			temp = delNode;
//		}
//	}
//};
//
//
//int main() {
//	int n; cin >> n;
//	vector<int> num(n);
//	NodeList List1;
//	for (int i = 0; i < n; i++){
//		cin >> num[i];
//		List1.insertAtHead(num[i]);
//	}
//	List1.printList();
//	cout << endl;
//	List1.head = List1.reverseList(List1.head);
//	List1.printList();
//}



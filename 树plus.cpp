#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

// 创建节点
//class TreeNode {
//public:
//	int date;
//	TreeNode* left;
//	TreeNode* right;
//
//	TreeNode(int x) :date(x), left(nullptr), right(nullptr) {}
//};
//
//// 树的操作 （创建与遍历）
//class BinaryTree {
//public:
//	TreeNode* root;
//
//	BinaryTree() :root(nullptr) {}
//
//	void createTree() {
//		root = new TreeNode(1);
//		root->left = new TreeNode(2);
//		root->right = new TreeNode(3);
//		root->left->left = new TreeNode(4);
//		root->left->right = new TreeNode(5);
//		root->right->left = new TreeNode(6);
//	}
//
//	// 递归遍历
//	void preorder(TreeNode* node) {
//		if (node == nullptr)return;
//		cout << node->date << ' ';
//		preorder(node->left);
//		preorder(node->right);
//	}
//
//	void inorder(TreeNode* node) {
//		if (node == nullptr)return;
//		inorder(node->left);
//		cout << node->date << ' ';
//		inorder(node->right);
//	}
//
//	void postorder(TreeNode* node) {
//		if (node == nullptr)return;
//		postorder(node->left);
//		postorder(node->right);
//		cout << node->date << ' ';
//	}
//
//	// 非递归前序遍历
//	void preorder() {
//		stack<TreeNode*> node;
//		node.push(root);
//		while (!node.empty()) {
//			auto t = node.top();
//			node.pop();
//
//			cout << t->date << ' ';
//			if (t->right)node.push(t->right);
//			if (t->left)node.push(t->left);
//		}
//	}
//
//	// 层序遍历
//	void levelorder() {
//		queue<TreeNode*> q;
//		q.push(root);
//		while (!q.empty()) {
//			TreeNode* node = q.front();
//			q.pop();
//			cout << node->date << ' ';
//			if(node->left)q.push(node->left);
//			if (node->right)q.push(node->right);
//		}
//	}
//
//
//	// 求树高
//	int HeightTree(TreeNode* node) {
//		if (node==nullptr)return 0;
//		else  return 1 + max(HeightTree(node->left), HeightTree(node->right));
//	}
//
//	// 求节点个数
//	int countNodes(TreeNode* node) {
//		if (node == nullptr)return 0;
//		return 1 + countNodes(node->left) + countNodes(node->right);
//	}
//
//	// 求叶子节点个数
//	int countLeaf(TreeNode* node) {
//		if (node == nullptr)return 0;
//		if (node->left == nullptr && node->right == nullptr)return 1;
//		return countLeaf(node->left) + countLeaf(node->right);
//	}
//
//	// 插入节点
//	TreeNode* insertBST(TreeNode* node, int x) {   // 在这个节点上插入 插入x为date
//		if (node == nullptr)return new TreeNode(x);
//		if (x < node->date) {
//			node->left = insertBST(node->left, x);
//		}
//		else if (x > node->date) {
//			node->right = insertBST(node->right, x);
//		}
//		return node;
//	}
//
//	// 查找节点
//	TreeNode* searchNode(TreeNode* node, int target) {
//		if (node == nullptr || node->date == target) {
//			return node;
//		}
//		else if (target < node->date) {
//			return searchNode(node->left, target);
//		}
//		else {
//			return searchNode(node->right, target);
//		}
//	}
//};
//
//
//vector<vector<int>> levelOrder(TreeNode* root) {
//	vector<vector<int>> res;
//	if (root == nullptr)return res;
//
//	queue<TreeNode*> q;
//	q.push(root);
//
//	while (!q.empty()) {
//
//		int size = q.size();
//		vector<int> level;
//
//		for (int i = 0; i < size; i++) {
//			TreeNode* node = q.front();
//			q.pop();
//			level.push_back(node->date);
//
//			if (node->left)q.push(node->left);
//			if (node->right)q.push(node->right);
//		}
//
//		res.push_back(level);
//
//	}
//	return res;
//}
//
//
//
//int main() {
//	// 二叉树
//	BinaryTree tree;
//	tree.createTree();
//
//	tree.preorder(tree.root);  // 递归前序遍历
//	cout << endl;
//
//	tree.inorder(tree.root);  // 递归中序遍历
//	cout << endl;
//
//	tree.postorder(tree.root);  // 递归后序遍历
//	cout << endl;
//
//	tree.preorder();  // 迭代前序遍历
//	cout << endl;
//
//	tree.levelorder();  // 层序遍历
//	cout << endl; 
//
//	cout << tree.HeightTree(tree.root) << ' ' << tree.countNodes(tree.root) << ' ' << tree.countLeaf(tree.root) << endl;
//
//	// 层序遍历打印
//	vector<vector<int>> ans;
//	ans = levelOrder(tree.root);
//	for (auto k : ans) {
//		for (auto l : k) {
//			cout << l << ' ';
//		}
//		cout << endl;
//	}
//
//
//	// 二叉搜索树
//	BinaryTree BST;
//
//	int arr[] = { 15,45,26,79,62,46 };
//	for (int x : arr) {
//		BST.root = tree.insertBST(BST.root, x);
//	}
//
//	BST.inorder(BST.root); 
//
//	return 0;
//}
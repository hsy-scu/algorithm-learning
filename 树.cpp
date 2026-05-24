#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

// 定义树的节点
//class TreeNode {
//public:
//	int date;
//	TreeNode* left;
//	TreeNode* right;
//
//	TreeNode(int val): date(val) {
//		left = nullptr;
//		right = nullptr;
//	}
//};
//
//// 树的操作
//class BinaryTree {
//public:
//	TreeNode* root;   // 必须是指针类型
//
//	// 刚开始树是空的
//	BinaryTree() {
//		root = nullptr;
//	}
//
//
//	// 创建树
//	void createTree() {
//		root = new TreeNode(1);  // 创建根节点
//		root->left = new TreeNode(2);
//		root->right = new TreeNode(3);
//		root->left->left = new TreeNode(4);
//		root->left->right = new TreeNode(5);
//		root->right->right = new TreeNode(6);
//	}
//
//	// 树的遍历
//
//
//	// 递归遍历
//	// 前序遍历（递归）  根 左 右
//	void preorder(TreeNode* node) {
//		if (node == nullptr)return;
//		cout << node->date << ' ';
//		preorder(node->left);
//		preorder(node->right);
//	}
//
//	// 中序遍历 左 根 右
//	void inorder(TreeNode* node) {
//		if (node == nullptr)return;
//		inorder(node->left);
//		cout << node->date << ' ';
//		inorder(node->right);
//	}
//
//	// 后序遍历 左 右 根
//	void postorder(TreeNode* node) {
//		if (node == nullptr) return;
//		postorder(node->left);
//		postorder(node->right);
//		cout << node->date << ' ';
//	}
//
//
//	// 非递归前序遍历（使用迭代方法）（需要使用栈）（栈是先进后出）
//	void preorder() {
//		if (root == nullptr)return;
//		stack<TreeNode*> s;
//		s.push(root);   // 先把根节点放入栈
//
//		while (!s.empty()) {
//			TreeNode* node = s.top();
//			s.pop();
//			cout << node->date << ' ';  // 每次打出栈顶的数据
//			if (node->right)s.push(node->right);  // 先存右孩子 考虑到栈先进后出的特征
//			if (node->left)s.push(node->left);   // 后存左孩子
//			// 其实就是每次压入两个子节点 每次压入的时候左孩子都在右孩子上面 左孩子压入一个就取出一个 右孩子一直累积 
//			// 最后就是左孩子全部取完了 然后开始从栈里面依次取出右孩子 以此实现迭代栈前序遍历
//		}
//		cout << endl;
//	}
//
//
//	// 层序遍历（就是一层一层遍历 和以上方法都不同）（需要用到队列）
//	void levelOrder() {
//		if (root == nullptr)return;
//
//		queue<TreeNode*> q;
//		q.push(root); // 先把根节点放入队列
//
//		while (!q.empty()) {
//			TreeNode* node = q.front();  // 每次取出并记忆
//			q.pop();
//			cout << node->date << ' ';
//			if (node->left)q.push(node->left);  // 先给左孩子排队
//			if (node->right)q.push(node->right);  // 后给右孩子排队
//			// 其实每一次就是压进两个子节点 之后取出的时候先取出左孩子再取出右孩子
//		}
//		cout << endl;
//	}
//
//
//	// 计算树的高度（深度）
//	int getHeight(TreeNode* node) {
//		if (node == nullptr)return 0;
//		int leftHeight = getHeight(node->left);     // 左子树高度
//		int rightHeight = getHeight(node->right);   // 右子树高度
//
//		// 返回两个树较高的那个 再加上根节点高度 1
//		return max(leftHeight, rightHeight) + 1;
//	}
//
//	// 计算节点总数
//	int countNodes(TreeNode* node) {
//		if (node == nullptr)return 0;
//
//		// 返回本节点处的总结点数 ： 本节点 + 本节点的左孩子节点数 + 本节点的右孩子节点数   
//		return 1 + countNodes(node->left) + countNodes(node->right);
//	}
//
//
//	// 查找节点（二叉搜索树BST专用）
//	TreeNode* searchBST(TreeNode* node, int target) {
//		if (node == nullptr || node->date == target) {
//			return node;  // 可能返回nullpter   也可能返回找到的node
//		}
//		if (target < node->date) {  // 如果没找到 并且它在左子树 就在左边找
//			return searchBST(node->left, target);
//		}
//		else {  //  反之 往右边找
//			return searchBST(node->right, target);
//		}
//	}
//
//	// 插入节点（二叉搜索树专用）   
//	TreeNode* insertBST(TreeNode* node, int val) {
//		
//		if (node == nullptr) {
//			return new TreeNode(val);   // 创建新的节点
//		}
//
//		if (val < node->date) {  // 如果插入的节点编号小于此根节点编号 就在此根节点左子树上插入
//			node->left = insertBST(node->left, val);
//		}
//		else if (val > node->date) {  // 否则在右子树上插入
//			node->right = insertBST(node->right, val);
//		}
//		return node;
//	}
//
//};
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
//	tree.levelOrder();  // 层序遍历
//	cout << endl;
//
//	cout << tree.getHeight(tree.root) << endl << tree.countNodes(tree.root) << endl;
//
//	// 二叉搜索树
//	BinaryTree bst;
//	bst.root = nullptr;
//	int values[] = { 50,30,70,20,40,60,80 };
//	for (int i = 0; i < 7;i++) {
//		bst.root = bst.insertBST(bst.root, values[i]);
//	}
//	bst.inorder(bst.root);  // 二叉搜索树的中序遍历是有序的 每个左元素都大于有元素 因此左根右是有序遍历
//	cout << endl;
//
//	// 查找
//	int target = 40;
//	TreeNode* result = bst.searchBST(bst.root, target);
//	if (result != nullptr)cout << "找到了" << target << endl;
//	else cout << "找不到" << target << endl;
//}
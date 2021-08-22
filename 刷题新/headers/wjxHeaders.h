#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <functional>
#include "LinkListClass.h"
#include <unordered_map>
#include <unordered_set>
#include <forward_list> //单链表
#include <list>   //双链表 更强大
#include <bitset>
#include <sstream>
#include <array>
#include <format>


using namespace std;

template<typename T>
class PrintX {
public:
	PrintX() {
		cout << x << " ";
	}
	T x;
};


template<class Key_type,class Value_type>
constexpr void printHashtable(const unordered_map<Key_type, Value_type>& hashtable)
{
	for (const auto& iter : hashtable) {
		cout << "key:" << iter.first << ",value:" << iter.second << "\n";
	}
	cout << endl;
}

template<class T>
void printVector(vector<T> const & v) {
	for (auto iter : v) {
		cout << iter << " ";
	}
	cout << endl;
}
template<class T>
void printvectorvector(const vector< vector<T> > & nums) {
	for (auto iter : nums) {
		for (auto iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	cout << endl;;
}

void printChar(char ch) {
	cout << ch << " ";
}
template<typename T>
void printstack(stack<T>& s)
{
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, int leftval, int rightval)
	{
		this->val = x;
		this->left = new TreeNode(leftval);
		this->right = new TreeNode(rightval);
	}
	TreeNode(int x, int leftval,TreeNode *rightnode) {
		this->val = x;
		this->left = new TreeNode(leftval);
		this->right = rightnode;
	}
	TreeNode(int x,  TreeNode* leftnode,int rightval) {
		this->val = x;
		this->left = leftnode;
		this->right = new TreeNode(rightval);
	}
	TreeNode(int x,TreeNode*_left,TreeNode *_right):val(x),left(_left),right(_right){}
	//int insert(int v);//919完全二叉树插入器
	
};

void recursionTree(TreeNode* root) {
	if (root == nullptr) {
		
		return;
	}
	recursionTree(root->left);
	cout << root->val << " ";
	recursionTree(root->right);

}
void recursionTree2(TreeNode* root) {//利用栈来遍历
	if (root == nullptr) {
		return;
	}
	stack<pair<TreeNode*, bool>> s;
	s.push({root,false});
	while (s.size() >0) {
		pair<TreeNode*, bool> p = s.top();
		s.pop();
		if (p.first == nullptr)
			continue;
		if (p.second == true)
			cout << p.first->val << " ";
		else {
			
			s.push({ p.first->right,false });
			s.push({ p.first->left,false });
			p.second = true;
			s.push(p);
			
		}
	}
	

}
int getTreeHeight(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int leftHeight = getTreeHeight(root->left);
	int rightHeight = getTreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
void levelOrder(TreeNode* root) {//分层遍历,利用vector存储节点
	if (root == nullptr)
		return;
	vector<TreeNode*> v;
	v.push_back(root);
	size_t cur = 0;	
	size_t last = v.size();
	while (cur < v.size()) {
		last = v.size();
		while (cur < last) {
			cout << v[cur]->val << " ";
			if (v[cur]->left)
				v.push_back(v[cur]->left);
			if (v[cur]->right)
				v.push_back(v[cur]->right);
			cur++;
		}
	}
	cout << endl;;
}
void levelOrder2(TreeNode* root) {//利用队列实现

	queue<TreeNode*> current, next;

	current.push(root);

	while (!current.empty()) {
		while (!current.empty()) {
			TreeNode* pTemp = current.front();
			cout<< pTemp->val<<" ";
			current.pop();
			if (pTemp->left)
				next.push(pTemp->left);
			if (pTemp->right)
				next.push(pTemp->right);
		}
		
		swap(current, next);
	}
	cout << endl;;

}
//输出以root为根节点中的第level层中的所有节点（从左到右），成功返回1
//失败返回0
//@param
//level为层次数，其中根节点为第0层
int PrintNodeAtLevel(TreeNode* root, int level)
{
	if (!root || level < 0)
		return 0;
	if (level == 0)
	{
		cout << root->val << "  ";
		return 1;
	}
	return PrintNodeAtLevel(root->left, level - 1) + PrintNodeAtLevel(root->right, level - 1);
}
void levelOrder3(TreeNode* root) {//

	for (int level = 0; ; level++)
	{
		if (!PrintNodeAtLevel(root, level))
			break;
		cout << endl;
	}


}

void levelOrder4(TreeNode* root) {//之字形打印

	//queue<TreeNode*> current, next;

	//current.push(root);
	//bool flag = true;
	//while (!current.empty()) {
	//	flag = !flag;
	//	while (!current.empty()) {
	//		TreeNode* pTemp = nullptr;
	//		pTemp = current.front();
	//		cout << pTemp->val << " ";
	//		current.pop();
	//		if (flag) {	
	//			if (pTemp->left)
	//				next.push(pTemp->left);
	//			if (pTemp->right)
	//				next.push(pTemp->right);
	//		}
	//		else {
	//			if (pTemp->right)
	//				next.push(pTemp->right);
	//			if (pTemp->left)
	//				next.push(pTemp->left);
	//		}
	//	}
	//	swap(current, next);
	//}
	//cout << endl;;

}


//Definition for singly - linked list. leetcode的链表结点定义
struct ListNode {
	int val;
	ListNode* next;
	ListNode() = default;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}

};


ListNode* makeList(vector<int> &v) { //利用 数组初始化单链表,返回链表头结点
	if (v.empty()) return nullptr;

	ListNode* pNew = new ListNode(v.front());
	ListNode* pTemp = pNew;


	for (size_t i = 1; i < v.size(); i++) {
		ListNode* ptest = new ListNode(v[i]);
		pNew->next = ptest;
		pNew = ptest;
	}
	pNew->next = nullptr;
	return pTemp;

}
void printNode(ListNode* temp) {
	
	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

//N叉树的LEETCODE 定义
class CNode {
public:
	int val;
	vector<CNode*> children;

	CNode() { val = 0; }

	CNode(int _val) {
		val = _val;
	}

	CNode(int _val, vector<CNode*> _children) {
		val = _val;
		children = _children;
	}
};
//带随机指针的 链表 leetcode 138
class RandomNode {
public:
	int val;
	RandomNode* next;
	RandomNode* random;

	RandomNode(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
//图的相邻接表 数据结构
struct GraphNode {
	int val;//图顶点值
	vector<GraphNode*> neighbors;//相邻顶点指针数组
	GraphNode(int x) :val(x) {}
};

struct TrieNode {
	TrieNode* child[26];
	bool isend;
	TrieNode() :isend(false) {
		memset(child, 0, sizeof(TrieNode*) * 26);
	}
};
#include <iostream>
// #include "array/FindMiniRotate153.cpp"
// #include "heap/KthLargest215.cpp"
#include <stack>
#include <vector>
#include <set>
#include <array>
// #include "array/15.cpp"
// #include "define.h"
#include "linklist/LinkCircle2_142.cpp"
using namespace std;

void HeapSortCore(vector<int>& arr, int cur, int size) {
	while(cur * 2 < size) {
		int idx = cur * 2;
		if (idx + 1 < size && arr[idx] < arr[idx + 1]) {
			idx += 1;
		}
		if (arr[cur] < arr[idx]) {
			swap(arr[cur], arr[idx]);
			cur = idx;
		} else {
			break;
		}
	}
}

void HeapSort(vector<int>& arr) {
	// 第一次整理
	for (int i = (arr.size() - 1) / 2; i >= 1; i--) {
		HeapSortCore(arr, i, arr.size());
	}
	// 排好第一次之后，需要
	// 弹出来最后一个
	for (int i = arr.size() - 1; i > 1; i--) {
		swap(arr[1], arr[i]);
		HeapSortCore(arr, 1, i);
	}
	return ;
}

// class Singleton {
// public:
//     //  获取此类的 唯一静态实例
//     static Singleton & getInstance() {
//         return instance;
//     }

//     //  公有函数部分
//     void func_print_1() {
//         cout << "1" << endl;
//     }

// private:
//     //  私有化 默认构造函数 拷贝构造函数 析构函数
//     //  即 禁止对 class singleton 的类外构造和拷贝
//     Singleton() {
//         //  构造部分
//     };
//     Singleton(Singleton &b) {
//         //  此函数无用 因为已经私有化
//         //  相当于禁止了拷贝构造
//     };
//     ~Singleton() {
//         //  析构部分
//     };

// 	static Singleton instance;
// };
// Singleton Singleton::instance;


int Char2Int(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return c - 'a' + 10;
}

char Int2Char(int n) {
	if (n >= 0 && n <= 9) {
		return '0' + n;
	}
	return 'a' + n - 10;
}

string addSum(const string& num1, const string& num2) {
	if (num1.empty()) {
		return num2;
	}
	if (num2.empty()) {
		return num1;
	}
	int n1_len = num1.size() - 1;
	int n2_len = num2.size() - 1;
	int flag = 0;
	string result;
	while(n1_len >= 0 || n2_len >= 0) {
		int sum = 0;
		if (n1_len >= 0) {
			sum += Char2Int(num1[n1_len]);
			n1_len--;
		}
		if (n2_len >= 0) {
			sum += Char2Int(num2[n2_len]);
			n2_len--;
		}
		sum += flag;
		int left = sum % 36;
		flag = sum / 36;
		result += Int2Char(left);
	}
	if (flag == 1) {
		result += '1';
	}
	reverse(result.begin(), result.end());

	return result;
}

class Cmp {
  public:
    bool operator()(ListNode* l1, ListNode* l2) const {
		return l1->val > l2->val;
	}
};

void testfunc(TreeNode* root) {
	cout << "a:" << root;
	root = (TreeNode*)0x123;
	cout << "b:" << root;
}

void Split(string str, vector<string>& token, string deli) {
	string::size_type last_pos = str.find_first_not_of(deli, 0);
	string::size_type pos = str.find_first_of(deli, last_pos);
	while(pos != string::npos || last_pos != string::npos) {
		token.push_back(str.substr(last_pos, pos - last_pos));
		last_pos = str.find_first_not_of(deli, pos);
		pos = str.find_first_of(deli, last_pos);
	}
	return ;
}

int main() {
	Solution s;
	ListNode n1(3);
	ListNode n2(2);
	ListNode n3(0);
	ListNode n4(-4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	s.detectCycle(&n1);
	// s.jump(a);
}
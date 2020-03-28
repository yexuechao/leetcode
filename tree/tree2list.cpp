/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include "../define.h"
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNode = NULL;//指向双向链表的尾结点
        ConvertNode(pRootOfTree, &pLastNode);

        TreeNode* pHead = pLastNode;
        while (pHead != NULL&&pHead->left != NULL)//找到头结点，返回
            pHead = pHead->left;

        return pHead;
    }

    void ConvertNode(TreeNode* pNode, TreeNode** pLastNode)
    {
        if (pNode == NULL)
            return;

        TreeNode* pCur = pNode;
        if (pCur->left != NULL)
            ConvertNode(pCur->left, pLastNode);
        //走到这，当前结点的左子树已经转换好了，pLastNode指向左子树中的最后一个结点

        //用pLastNode指向已经转换好的链表的最后一个结点
        pCur->left = *pLastNode;
        if (*pLastNode != NULL)
            (*pLastNode)->right = pCur;

        //将pLastNode指向当前结点
        *pLastNode = pCur;
        if (pCur->right != NULL)
            ConvertNode(pCur->right, pLastNode);
    }

};
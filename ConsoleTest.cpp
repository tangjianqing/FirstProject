// ConsoleTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECUER_NO_WARNINGS
#include <stdio.h>


struct TreeNode
{
    int value;
    TreeNode* leftNode;
    TreeNode* rightNode;
};

void InsertNode(TreeNode* topNode, int newValue)
{
    if (topNode->value <= newValue)
    {
        if (topNode->rightNode != NULL)
        {
            InsertNode(topNode->rightNode, newValue);
        }
        else
        {
            TreeNode* node = new TreeNode();
            node->value = newValue;
            topNode->rightNode = node;
        }
    }
    else
    {
        if (topNode->leftNode != NULL)
        {
            InsertNode(topNode->leftNode, newValue);
        }
        else
        {
            TreeNode* node = new TreeNode();
            node->value = newValue;
            topNode->leftNode = node;
        }
    }
}

void PrintTree(TreeNode* topNode)
{
    TreeNode* current = NULL;
    if (topNode->leftNode != NULL)
    {
        PrintTree(topNode->leftNode);
    }
    printf("%d\n", topNode->value);
    if (topNode->rightNode != NULL)
    {
        PrintTree(topNode->rightNode);
    }
}


TreeNode* CreateNodeList(int a[],int len)
{
    TreeNode* topNode = NULL;
    TreeNode* newNode = NULL;
    for (int i = 0; i < len; i++)
    {
        TreeNode* newNode = new TreeNode();
        newNode->value = a[i];

        if (topNode==NULL)
        {
            topNode= newNode;
        }
        else
        {
            InsertNode(topNode, a[i]);
        }
    }
    return topNode;
}

int* HalfSplitSort(int a[], int start, int end)
{
    int temp = 0;
    if (end - 1 > start)
    {
        int halfInde = (end - start) / 2;
        for (int i = 0; i <= halfInde; i++)
        {
            if (a[start + i] > a[end - i])
            {
                temp = a[start + i];
                a[start + i] = a[end - i];
                a[end - i] = temp;
            }
        }
        a = HalfSplitSort(a, start, halfInde);
        a = HalfSplitSort(a, halfInde + 1, end);
        return a;
    }
    else
    {
        return a;
    }
}

int main()
{
    printf("Hello World!\n");
    int a[] = { 5,8,3 };
    HalfSplitSort(a, 0, 2);
    int s = sizeof(a)/sizeof(int);
    TreeNode* tr=CreateNodeList(a,s);
    PrintTree(tr);
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

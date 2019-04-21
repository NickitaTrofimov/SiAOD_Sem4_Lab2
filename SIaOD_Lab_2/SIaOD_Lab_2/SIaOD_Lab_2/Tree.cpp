#include <iostream>
#include <stdlib.h>

using namespace std;

struct tnode {
	int number;          // ��������� �� ������ (�����)
	int count;
	int counter = 0;
	struct tnode *left;  // ����� �������
	struct tnode *right; // ������ �������
};

struct tnode * addnode(int x, tnode *tree)
{
	if (tree == NULL)
	{ // ���� ������ �� �������, ������� ������
		tree = new tnode; // ������� ���� ������� ������
		tree->number = x;   // �������� �������� ����
		tree->left = NULL;
		tree->right = NULL; // ����� ���� �������������� �������
		tree->count = 1; // ������� ������������� ��������� ��������
		tree->counter++; // ���������� ����� �������������
	}
	else  if (x < tree->number)   // ���� �������� ������ ���� �������� - ��������� �����
	{
		tree->left = addnode(x, tree->left);
		tree->counter++;
	}
	else    // ����� ��������� ������
	{
		tree->right = addnode(x, tree->right);
		tree->counter++;
	}
	return(tree);
}

void checkprint(struct tnode *tree, int n) 
{ 
	int i; 
	if (tree) 
	{
		checkprint(tree->right, n + 3);
		for (i = 0; i < n; i++)
		putchar(' ');
		cout << tree->number << endl;
		checkprint(tree->left, n + 3); 
	} 
}

void main()
{
	setlocale(LC_ALL, "Russian");

	struct tnode *root;
	int number;
	root = NULL;

	cout << "������� �������� ����� (����� ����� = '0')" << endl;
	do {
		cin >> number;
		if (number != 0)
			root = addnode(number, root);
	} while (number != 0);
	cout << endl;

	int n = root->counter;
	checkprint(root, n);

	cout << endl;
	cout << "������� �������� ������������ ���� ";
	cin >> number;
	cout << endl;
	
	addnode(number, root);

	cout << endl;

	n = root->counter;
	checkprint(root, n);

	system("pause");
}
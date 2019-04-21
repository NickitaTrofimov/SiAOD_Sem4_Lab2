#include <iostream>
#include <stdlib.h>

using namespace std;

struct tnode {
	int number;          // указатель на строку (слово)
	int count;
	int counter = 0;
	struct tnode *left;  // левый потомок
	struct tnode *right; // правый потомок
};

struct tnode * addnode(int x, tnode *tree)
{
	if (tree == NULL)
	{ // Если дерево не создано, создаем корень
		tree = new tnode; // создаем узел выделяя память
		tree->number = x;   // передаем значение узла
		tree->left = NULL;
		tree->right = NULL; // ветви узла инициализируем пустыми
		tree->count = 1; // счетчик повторяющихся введенных значений
		tree->counter++; // количество узлов инкреминируем
	}
	else  if (x < tree->number)   // если значение меньше узла родителя - добавляем влево
	{
		tree->left = addnode(x, tree->left);
		tree->counter++;
	}
	else    // иначе добавляем вправо
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

	cout << "Введите значения узлов (конец ввода = '0')" << endl;
	do {
		cin >> number;
		if (number != 0)
			root = addnode(number, root);
	} while (number != 0);
	cout << endl;

	int n = root->counter;
	checkprint(root, n);

	cout << endl;
	cout << "Введите значение добавляемого узла ";
	cin >> number;
	cout << endl;
	
	addnode(number, root);

	cout << endl;

	n = root->counter;
	checkprint(root, n);

	system("pause");
}
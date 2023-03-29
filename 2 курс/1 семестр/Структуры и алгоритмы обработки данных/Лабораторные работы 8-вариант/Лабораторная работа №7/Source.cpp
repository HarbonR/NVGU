#include <iostream>

class Tree
{
private:
	struct tree_t
	{
		int key;
		tree_t* left;
		tree_t* right;
	};
	tree_t* tree;
	void insert(int key, tree_t* root) // Добавить узел
	{
		if (key < root->key)
		{
			if (root->left == nullptr)
			{
				root->left = new tree_t;
				root->left->key = key;
				root->left->left = nullptr;
				root->left->right = nullptr;
			}
			else
				insert(key, root->left);
		}
		else
		{
			if (root->right == nullptr)
			{
				root->right = new tree_t;
				root->right->key = key;
				root->right->left = nullptr;
				root->right->right = nullptr;
			}
			else
				insert(key, root->right);
		}
	}
	void inorderPrint(tree_t* root) // Симметричный обход
	{
		if (root != nullptr)
		{
			inorderPrint(root->left);
			std::cout << root->key << ',';
			inorderPrint(root->right);
		}
	}
	void postOrderPrint(tree_t* root) // Обход слева
	{
		if (root != NULL) {
			inorderPrint(root->left);
			inorderPrint(root->right);
			std::cout << root->key << ',';
		}
	}
	void preOrderPrint(tree_t* root) // Обход справа
	{
		if (root != NULL) {
			std::cout << root->key << ',';
			inorderPrint(root->left);
			inorderPrint(root->right);
		}
	}
	void deleteTree(tree_t* root) {
		if (root != nullptr)
		{
			deleteTree(root->left);
			deleteTree(root->right);
			delete root;
		}
	}
public:
	Tree()
	{
		tree = nullptr;
	}
	void insert(int key) // Добавить узел
	{
		if (tree == nullptr)
		{
			tree = new tree_t;
			tree->key = key;
			tree->left = nullptr;
			tree->right = nullptr;
		}
		else
			insert(key, tree);
	}
	void inorderPrint() // Симметричный обход
	{
		inorderPrint(tree);
	}
	void postOrderPrint() // Обход слева
	{
		postOrderPrint(tree);
	}
	void preOrderPrint() // Обход справа
	{
		preOrderPrint(tree);
	}
	void deleteTree() 
	{
		deleteTree(tree);
		tree = nullptr;
	}
	~Tree()
	{
		if (tree != nullptr)
			deleteTree();
	}
};


int main()
{
	Tree tree;
	int intArray[12] = { 54, 101, 27, 14, 17, 18, 54, 91, 72, 76, 75, 102 };
	for (int i = 0; i < 12; i++)
	{
		tree.insert(intArray[i]);
	}
	tree.inorderPrint();
	std::cout << '\n';
	system("pause");
	return 0;
}
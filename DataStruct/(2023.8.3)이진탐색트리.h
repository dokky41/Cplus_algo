#include <iostream>






#pragma region ���� Ž�� Ʈ�� (BST)
// ������ Ű�� ���� ���Ҹ� ����, ����, �˻��ϴµ�
// ȿ������ Ʈ���Դϴ�.

struct Node
{
	int data;
	// Node�� ����Ű�� ������ ���� 2��
	Node* left;
	Node* right;
};

Node* Insert(Node* root, int data)
{

	// root��尡 nullptr�̶��?
	if (root == nullptr)
	{
		root = new Node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (root->data >= data)// else if root�� data���� �۴ٸ�?
	{
		root->left = Insert(root->left, data);
	}
	else // else root�� data���� ũ�ٸ�?
	{
		root->right = Insert(root->right, data);
	}

	// �ּڰ� ����
	return root;
}

int FindMax(Node* root)
{
	if (!root)
	{
		std::cout << "���� �����Ͱ� �������� �ʽ��ϴ�." << std::endl;
		return 0xcccccccc;
	}

	if (root->right == nullptr)
	{
		return root->data;
	}
	else
	{
		return FindMax(root->right);
	}
}

int FindMin(Node* root)
{
	if (!root)
	{
		std::cout << "���� �����Ͱ� �������� �ʽ��ϴ�." << std::endl;
		return 0xcccccccc;
	}

	if (root->left == nullptr)
	{
		return root->data;
	}
	else
	{
		return FindMin(root->left);
	}
}

struct Node* minValueNode(Node* node)
{
	Node* currentNode = node;

	while (currentNode && currentNode->left == nullptr)
	{
		currentNode = currentNode->left;
	}

	return currentNode;
}


Node* DeleteNode(Node* root, int key)
{
	// ��尡 ���� ���
	if (root == nullptr)
	{
		std::cout << "���� �����Ͱ� �������� �ʽ��ϴ�." << std::endl;
		return nullptr;
	}


	if (key < root->data)  // 1) �����ϰ��� �ϴ� ���Ұ� ���� ����� ���ʿ� ���� Ʈ���� ���� ���
	{
		root->left = DeleteNode(root->left, key);
	}
	else if (key > root->data)  // 2) �����ϰ��� �ϴ� ���Ұ� ���� ����� ������ ���� Ʈ���� ���� ���
	{
		root->right = DeleteNode(root->right, key);
	}
	else     // 3) �����ϰ��� �ϴ� ���Ұ� ���� ��忡 ���� ���
	{
		struct Node* temp;

		if (root->left == nullptr)
		{
			temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr)
		{
			temp = root->left;
			delete root;
			return temp;
		}

		//�ڽ� ��尡 �� �� �ִ� ���
		temp = minValueNode(root->right);

		// ������ Node�� �����͸� �ٲߴϴ�.
		root->data = temp->data;

		// ��带 �����մϴ�.
		root->right = DeleteNode(root->right, temp->data);

	}

	return root;
}


#pragma endregion



int main()
{
	Node* root = nullptr;

	root = Insert(root, 10);
	root = Insert(root, 5);
	root = Insert(root, 3);

	DeleteNode(root, 3);

	std::cout << FindMax(root) << std::endl;
	std::cout << FindMin(root) << std::endl;


	return 0;
}
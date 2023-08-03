#include <iostream>






#pragma region 이진 탐색 트리 (BST)
	// 임의의 키를 가진 원소를 삽입, 삭제, 검색하는데
	// 효율적인 트리입니다.

struct Node
{
	int data;
	// Node를 가리키는 포인터 변수 2개
	Node* left;
	Node* right;
};

Node* Insert(Node * root, int data)
{
	
	// root노드가 nullptr이라면?
	if (root == nullptr)
	{
		root = new Node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (root->data >= data)// else if root의 data보다 작다면?
	{
		root->left = Insert(root->left, data);
	}
	else // else root의 data보다 크다면?
	{
		root->right = Insert(root->right, data);
	}

	// 주솟값 리턴
	return root;
}

int FindMax(Node* root)
{
	if(!root)
	{
		std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
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
		std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
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

Node * DeleteNode(Node * root ,int key)
{
	if (root == nullptr)
	{
		std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
		return nullptr;
	}

	if (key < root->data)
	{
		root->left = DeleteNode(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = DeleteNode(root->right, key);
	}

	delete root;

	return root;
}


#pragma endregion



int main()
{
	Node* root = nullptr;
	
	root = Insert(root, 10);
	root = Insert(root, 5);
	root = Insert(root, 3);

	std::cout << FindMax(root) << std::endl;
	std::cout << FindMin(root) << std::endl;


	return 0;
}
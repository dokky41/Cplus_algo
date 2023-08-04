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

Node* Insert(Node* root, int data)
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
	if (!root)
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
	// 노드가 없는 경우
	if (root == nullptr)
	{
		std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
		return nullptr;
	}


	if (key < root->data)  // 1) 삭제하고자 하는 원소가 현재 노드의 왼쪽에 서브 트리에 있을 경우
	{
		root->left = DeleteNode(root->left, key);
	}
	else if (key > root->data)  // 2) 삭제하고자 하는 원소가 현재 노드의 오른쪽 서브 트리에 있을 경우
	{
		root->right = DeleteNode(root->right, key);
	}
	else     // 3) 삭제하고자 하는 원소가 현재 노드에 있을 경우
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

		//자식 노드가 두 개 있는 경우
		temp = minValueNode(root->right);

		// 삭제할 Node의 데이터를 바꿉니다.
		root->data = temp->data;

		// 노드를 삭제합니다.
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
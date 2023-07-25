#include <iostream>

#pragma region 트리 (TREE)
// 그래프의 일종으로 정점과 간선을 
// 이용하여 데이터의 배치 형태를 추상화한 자료구조입니다.

struct Node
{
	int data;
	Node* left;
	Node* right;
};

#pragma endregion

Node* CreateNode(int data, Node* leftChild, Node* rightChild)
{
	// 새로운 노드 생성
	Node* newNode = new Node;

	// 노드의 data값을 저장합니다.
	newNode->data = data;

	// 노드의 leftChild값을 설정합니다.
	newNode->left = leftChild;

	// 노드의 rightChild값을 설정합니다.
	newNode->right = rightChild;

	// 노드의 주솟값을 반환합니다.
	return newNode;
}

// 전위 순회
void Preorder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		std::cout << node->data << " ";
		Preorder(node->left);
		Preorder(node->right);
	}
}

// 중위 순회
void Inorder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		Inorder(node->left);
		std::cout << node->data << " ";
		Inorder(node->right);
	}
}



// 후위 순회
void Postorder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		Postorder(node->left);
		Postorder(node->right);
		std::cout << node->data << " ";
	}
}



int main()
{
	// 트리의 순회
	Node* node7 = CreateNode(7, nullptr, nullptr);
	Node* node6 = CreateNode(6, nullptr, nullptr);
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);
	Node* node3 = CreateNode(3, node6, node7);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);


	//Preorder(node1);
	//std::cout << std::endl;
	//
	//Inorder(node1);
	//std::cout << std::endl;
	//
	//Postorder(node1);






	return 0;
}
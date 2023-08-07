#include <iostream>

#pragma region ���� ���� ����Ʈ
// �ܼ� ���� ����Ʈ���� ������ ��尡 
// ����Ʈ�� ù ��° ��带 ����Ű�� ����Ʈ ������
// �������� ���� ����Ʈ�Դϴ�.

struct Node
{
	int data;
	Node* next;
};

class CircleLinkedList
{
private:
	int count;


public:
	CircleLinkedList()
	{
		count = 1;
	};


	Node* Push_Front(Node* head, int data)
	{
		// 1. ���ο� ��带 �����մϴ�.
		Node* newNode = new Node;

		// 2. ���ο� ����� data ���� �����մϴ�.
		newNode->data = data;

		// 3. if(���࿡ head�� nullptr�̶��?)
		if (head == nullptr)
		{
			// head �����ʹ� ���ο� ����� �ּҸ� �����մϴ�.
			head = newNode;

			// ���ο� ����� next�� �ڱ� �ڽ��� �����Ѿ� �մϴ�.
			newNode->next = head;
		}
		else
		{
			// ���ο� ����� next�� head->next�� ����Ű�� �մϴ�.
			newNode->next = head->next;

			// head�� next�� ���ο� ��带 ����Ű�� �մϴ�.
			head->next = newNode;
		}

		return head;
	}

	Node* Push_Back(Node* head, int data)
	{
		// 1. ���ο� ��带 �����մϴ�.
		Node* newNode = new Node;

		// 2. ���ο� ����� data ���� �����մϴ�.
		newNode->data = data;

		// 3. if(���࿡ head�� nullptr�̶��?)
		if (head == nullptr)
		{
			// head �����ʹ� ���ο� ����� �ּҸ� �����մϴ�.
			head = newNode;
			// ���ο� ����� next�� �ڱ� �ڽ��� �����Ѿ� �մϴ�.
			newNode->next = head;
		}
		else // 4. 
		{
			// ���ο� ����� next�� head�� next ������ �����մϴ�.
			newNode->next = head->next;
			// head ����� next�� ���ο� ����� �ּҸ� ����ŵ�ϴ�.
			head->next = newNode;
			// head �����Ϳ� ���ο� ����� �ּҸ� �����մϴ�.
			head = newNode;
		}

		return head;
	}

	void Information(Node* head)
	{
		if (head == nullptr)
		{
			return;
		}

		Node* currentNode = head->next;

		while (currentNode != head)
		{
			std::cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}

		std::cout << currentNode->data << std::endl;
	}

};



#pragma endregion



int main()
{
	CircleLinkedList List;

	Node* head = nullptr;

	head = List.Push_Front(head, 20);
	head = List.Push_Front(head, 10);
	head = List.Push_Back(head, 30);

	List.Information(head);

	return 0;
}
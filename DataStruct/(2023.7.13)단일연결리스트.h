#include <iostream>

struct NODE
{
	int data;
	NODE* next;
};

class LinkedList
{
private:
	NODE* head;
	NODE* tail;

	int size;

public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;

		size = 0;
	}

	void Push_Front(int data)
	{
		// 1. 새로운 노드 생성
		NODE* newNode = new NODE;
		// 2. 새로운 노드의 data값을 저장합니다.
		newNode->data = data;
		// 3. 새로운 노드의 next 값은 NULL로 저장합니다
		newNode->next = NULL;

		// if(head==nullptr)
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}

		size++;
	}

	void Push_Back(int data)
	{
		// 1. 새로운 노드 생성
		NODE* newNode = new NODE;
		// 2. 새로운 노드의 data값을 저장합니다.
		newNode->data = data;
		// 3. 새로운 노드의 next 값은 NULL로 저장합니다
		newNode->next = NULL;

		// if(head==nullptr)
		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}

		size++;
	}


	int Size()
	{
		return size;
	}

	void PrintList() {

		NODE* node = head;

		std::cout << "연결리스트 목록 = ( ";

		while (node != nullptr) {

			std::cout << node->data << " ";
			node = node->next;
		}
		std::cout << ")" << std::endl;

	}


	~LinkedList()
	{
	
	}
};

int main()
{
	LinkedList list;

	list.Push_Back(20);
	list.Push_Front(10);

	std::cout << list.Size() << std::endl;

	//list.PrintList();

	std::cout << std::endl;


	return 0;
}
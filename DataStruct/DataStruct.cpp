#include <iostream>


struct NODE
{
	int data;
	NODE* next;
	NODE* prev;
};

template <typename T>
class DoubleLinkedList
{
private:
	NODE* head;
	NODE* tail;

public:
	DoubleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	
	}

	void Push_Front(T data)
	{
		NODE* newNode = new NODE;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	
	}

	void Push_Back(T data)
	{
		NODE* newNode = new NODE;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;

		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	
	}

	void pop_Front()
	{
		if (head == nullptr)
		{
			return;
		}
		else {
			NODE* removePtr = head;

			head = head->next;

			head->prev = nullptr;

			delete removePtr;
		}
	}

	void pop_Back()
	{
		if (head == nullptr)
		{
			return;
		}
		else 
		{
			NODE* removePtr = tail;

			tail = tail->prev;

			tail->next = nullptr;

			delete removePtr;
		}
	}


	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			NODE* node = head;
			head = node->next;
			head->prev = nullptr;
			delete node;
		}
	}

};

int main()
{
	DoubleLinkedList<int> list;
	



	return 0;
}
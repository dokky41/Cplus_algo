#include <iostream>

// 1. ��� �����
struct NODE
{
	int data;
	NODE* next;


};

void AddNode(NODE* target, int data)
{
	// 1.��� ����
	NODE* newNode = new NODE;

	// 2.���ο� ����� data���� ����
	newNode->data = data;

	// 3.���ο� ����� next �����Ϳ� ���� ����� ���� �ּҸ� �����մϴ�. (NewNode->next = target�� next)
	newNode->next = target->next;

	// 4. ���� ����� ���� �ּҿ� ���ο� ����� �ּҸ� �����մϴ�.   (target->next = ���ο� ���)
	target->next = newNode;
}

void RemoveNode(NODE* target)
{
	//1. ������ ����� �ּҸ� ������ ������
	NODE* deletePtr = target->next;

	//2. target ����� Next�� �����Ǵ� ����� ���� �ּҷ� ����Ű�� �մϴ�.
	target->next = deletePtr->next;

	//3. �ش� ��� ����
	delete(deletePtr);

}

void ReleaseNode(NODE* target)
{
	NODE* curPtr = target;

	while (curPtr != nullptr)
	{
		NODE* nextPtr = curPtr->next;
		delete(curPtr);
		curPtr = nextPtr;
	}

}


void ShowNode(NODE* targetPtr)
{
	// ��ȸ�� ������
	//1. ��ȸ�� �����Ϳ� dummy�� �ּҸ� ����
	NODE* currentPtr = targetPtr;

	//2. ��ȸ�� �����Ͱ� nullptr�� �ƴ϶�� �ݺ��ϵ��� �����Ѵ�.
	//3. ��ȸ�� �����͸� ��� �����Ѵ�. (= ��ȸ�� �����Ϳ� next �����͸� �����Ѵ�)
	//4. ���� ��ȸ�� �����ͷ� ���� ����Ѵ�.
	while (currentPtr != nullptr)
	{
		currentPtr = currentPtr->next;

		if (currentPtr != nullptr)
		{
			std::cout << currentPtr->data << std::endl;
		}
	}

}


int main()
{

#pragma region ���� ���� ����Ʈ

	// ���� ���� ����Ʈ
	/*
	//          [dummy ���]
	NODE * dummy = new NODE;
	//          [node1 ���]
	NODE * node1 = new NODE;
	//          [node2 ���]
	NODE * node2 = new NODE;



	// 1. dummy�� next ������ <- node1�� ���� �ּҸ� ����
	dummy->next = node1;

	// 2. node1�� data���� 10���� �ʱ�ȭ
	node1->data = 10;

	// 3. node1�� next ������ <- node2�� ���� �ּҸ� ����
	node1->next = node2;

	// 4. node2�� data���� 20���� �ʱ�ȭ
	node2->data = 20;

	// 5. node2�� next ������ <- nullptr ����
	node2->next = nullptr;


	// ��ȸ�� ������
	//1. ��ȸ�� �����Ϳ� dummy�� �ּҸ� ����
	NODE* currentPtr =  dummy;

	//2. ��ȸ�� �����Ͱ� nullptr�� �ƴ϶�� �ݺ��ϵ��� �����Ѵ�.
	//3. ��ȸ�� �����͸� ��� �����Ѵ�. (= ��ȸ�� �����Ϳ� next �����͸� �����Ѵ�)
	//4. ���� ��ȸ�� �����ͷ� ���� ����Ѵ�.
	while (currentPtr != nullptr)
	{
		currentPtr = currentPtr->next;

		if(currentPtr != nullptr)
		{
			std::cout << currentPtr->data << std::endl;
		}
	}

	delete dummy;
	delete node1;
	delete node2;
	*/

	// ���� ���� ����Ʈ (�Լ�)
	NODE* dummy = new NODE;

	dummy->next = nullptr;

	AddNode(dummy, 10);
	AddNode(dummy, 20);
	AddNode(dummy, 30);

	RemoveNode(dummy->next);

	ShowNode(dummy);

	ReleaseNode(dummy);

#pragma endregion





}
#include <iostream>

// 1. 노드 만들기
struct NODE
{
	int data;
	NODE* next;


};

void AddNode(NODE* target, int data)
{
	// 1.노드 생성
	NODE* newNode = new NODE;

	// 2.새로운 노드의 data값을 저장
	newNode->data = data;

	// 3.새로운 노드의 next 포인터에 이전 노드의 다음 주소를 저장합니다. (NewNode->next = target의 next)
	newNode->next = target->next;

	// 4. 이전 노드의 다음 주소에 새로운 노드의 주소를 저장합니다.   (target->next = 새로운 노드)
	target->next = newNode;
}

void RemoveNode(NODE* target)
{
	//1. 삭제할 노드의 주소를 저장할 포인터
	NODE* deletePtr = target->next;

	//2. target 노드의 Next를 삭제되는 노드의 다음 주소로 가리키게 합니다.
	target->next = deletePtr->next;

	//3. 해당 노드 삭제
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
	// 순회용 포인터
	//1. 순회용 포인터에 dummy의 주소를 저장
	NODE* currentPtr = targetPtr;

	//2. 순회용 포인터가 nullptr이 아니라면 반복하도록 설정한다.
	//3. 순회용 포인터를 계속 갱신한다. (= 순회용 포인터에 next 포인터를 저장한다)
	//4. 현재 순회용 포인터로 값을 출력한다.
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

#pragma region 단일 연결 리스트

	// 단일 연결 리스트
	/*
	//          [dummy 노드]
	NODE * dummy = new NODE;
	//          [node1 노드]
	NODE * node1 = new NODE;
	//          [node2 노드]
	NODE * node2 = new NODE;



	// 1. dummy의 next 포인터 <- node1의 시작 주소를 저장
	dummy->next = node1;

	// 2. node1의 data변수 10으로 초기화
	node1->data = 10;

	// 3. node1의 next 포인터 <- node2의 시작 주소를 저장
	node1->next = node2;

	// 4. node2의 data변수 20으로 초기화
	node2->data = 20;

	// 5. node2의 next 포인터 <- nullptr 저장
	node2->next = nullptr;


	// 순회용 포인터
	//1. 순회용 포인터에 dummy의 주소를 저장
	NODE* currentPtr =  dummy;

	//2. 순회용 포인터가 nullptr이 아니라면 반복하도록 설정한다.
	//3. 순회용 포인터를 계속 갱신한다. (= 순회용 포인터에 next 포인터를 저장한다)
	//4. 현재 순회용 포인터로 값을 출력한다.
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

	// 단일 연결 리스트 (함수)
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
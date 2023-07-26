#include <iostream>

#define SIZE 8

class MAX_HEAP
{
private:
	int heapArray[SIZE];
	int index;


public:
	MAX_HEAP()
	{
		index = 0;

		for (int i = 0; i < SIZE; i++)
		{
			heapArray[i] = NULL;
		}
	}

	void Insert(int data)
	{
		if (index >= SIZE - 1)
		{
			std::cout << "힙이 가득 찼습니다." << std::endl;
			return;
		}

		heapArray[++index] = data;

		int child = index;
		int parent = index / 2;

		while (child > 1)
		{
			if (heapArray[parent] < heapArray[child])
			{
				std::swap(heapArray[parent], heapArray[child]);
			}

			child = parent;
			parent = child / 2;

		}


	}

	int& Delete()
	{
		// 1. 임시 변수 <- heap의 제일 꼭대기에 있는 값을 저장합니다.
		int result = heapArray[1];

		// 2. Heap이 비어있다면 함수를 바로 반환합니다.
		if (index == 0)
		{
			std::cout << "힙이 비어있습니다." << std::endl;
			return;
		}

		// 3. index값을 가리키는 배열의 값을 첫 번째 배열의 값으로 넣어주면 됩니다.
		heapArray[1] = heapArray[index];

		// 4. index로 가리키는 배열의 값을 초기화합니다.
		// 5. index를 감소 시킵니다.
		heapArray[index--] = NULL;

		// 6. 부모 변수 <- 1넣기
		int parent = 1;

		// 7. 반복문을 선언합니다. (부모 변수 * 2 <= index)
		while (parent * 2 <= index)
		{
			int child = parent * 2;

			if (heapArray[child] < heapArray[child + 1])
			{
				child++;
			}

			if (heapArray[child] < heapArray[parent])
			{
				break;
			}

			std::swap(heapArray[child], heapArray[parent]);
			parent = child;
		}

		return result;
	}

	void Show()
	{
		for (const int& element : heapArray)
			std::cout << element << " ";
	};
};




int main()
{

#pragma region 힙
	// 여러 값들 중에서 최댓값 혹은 최솟값을
	// 빠르게 찾아내기 위한 자료구조입니다.

	// 최대 힙
	// 부모 노드의 키 값이 자식 노드의 키 값보다
	// 크거나 같은 완전 이진 트리

	MAX_HEAP heap;

	heap.Insert(10);
	heap.Insert(20);


	heap.Show();


#pragma endregion





	return 0;
}
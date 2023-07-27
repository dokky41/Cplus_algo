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
			std::cout << "���� ���� á���ϴ�." << std::endl;
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
		// 1. �ӽ� ���� <- heap�� ���� ����⿡ �ִ� ���� �����մϴ�.
		int result = heapArray[1];

		// 2. Heap�� ����ִٸ� �Լ��� �ٷ� ��ȯ�մϴ�.
		if (index <= 0)
		{
			std::cout << "���� ����ֽ��ϴ�." << std::endl;
			exit(1);
		}

		// 3. index���� ����Ű�� �迭�� ���� ù ��° �迭�� ������ �־��ָ� �˴ϴ�.
		heapArray[1] = heapArray[index];

		// 4. index�� ����Ű�� �迭�� ���� �ʱ�ȭ�մϴ�.
		// 5. index�� ���� ��ŵ�ϴ�.
		heapArray[index--] = NULL;

		// 6. �θ� ���� <- 1�ֱ�
		int parent = 1;

		// 7. �ݺ����� �����մϴ�. (�θ� ���� * 2 <= index)
		while (parent * 2 <= index)
		{
			int child = parent * 2;

			// ������ �ڽ� ��尡 Ŭ ��
			if (heapArray[child] < heapArray[child + 1])
			{
				child++;
			}

			// �θ��� ��� Key ���� ũ�ٸ� �ݺ����� �����մϴ�.
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

#pragma region ��
	// ���� ���� �߿��� �ִ� Ȥ�� �ּڰ���
	// ������ ã�Ƴ��� ���� �ڷᱸ���Դϴ�.

	// �ִ� ��
	// �θ� ����� Ű ���� �ڽ� ����� Ű ������
	// ũ�ų� ���� ���� ���� Ʈ��

	MAX_HEAP heap;

	heap.Insert(10);
	heap.Insert(20);
	heap.Insert(30);

	std::cout << heap.Delete() << std::endl;
	std::cout << "----------------" << std::endl;

	heap.Show();


#pragma endregion





	return 0;
}
#include <iostream>

#define SIZE 5


template <typename T>
class LinearQueue
{
private:
	T array[SIZE];
	int front;
	int rear;
	int size;

public:
	LinearQueue()
	{
		front = 0;
		rear = 0;
		size = 0;
	}

	bool Empty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFull()
	{
		if (SIZE <= rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	void Push(T data)
	{

		if (IsFull())
		{
			std::cout << "QUEUE�� ���� á���ϴ�." << std::endl;
			exit(1);
		}

		array[rear++] = data;

		size++;
	}

	void Pop()
	{
		if (Empty())
		{
			std::cout << "QUEUE�� ��� �ֽ��ϴ�." << std::endl;
			exit(1);
		}

		array[front++] = NULL;

		size--;
	}

	int& Size()
	{
		return  size;
	}

	T& Front()
	{
		return array[front];
	}

	T& Back()
	{
		return array[rear - 1];
	}



};


int main()
{

#pragma region ���� ť
	// �迭�� ������ �� �����Ͱ� �����Ǿ�
	// �����͸� �������� �ʱ�ȭ���� ������
	// ���� �����Ͱ� �ִ� �迭�� �ڸ��� �� �̻�
	// �ٸ� ���� �� �� ���� ������ Queue�Դϴ�.
	// FIFO
	LinearQueue<int> queue;

	queue.Push(10);
	queue.Push(20);
	queue.Push(30);
	queue.Push(40);
	queue.Push(50);

	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();


	std::cout << queue.Size() << std::endl;
	std::cout << queue.Front() << std::endl;
	std::cout << queue.Back() << std::endl;


#pragma endregion




	return 0;
}
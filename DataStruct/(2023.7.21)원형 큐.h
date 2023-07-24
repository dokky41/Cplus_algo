#include <iostream>

#define SIZE 4

template <typename T>
class CircleQueue
{
private:
	T buffer[SIZE] = { 0, };
	int front;
	int rear;

public:
	CircleQueue()
	{
		front = SIZE - 1;
		rear = SIZE - 1;
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
		if (front == (rear + 1) % SIZE)
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
		else
		{
			rear = (rear + 1) % SIZE;
			buffer[rear] = data;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			std::cout << "QUEUE�� ��� �ֽ��ϴ�." << std::endl;
			exit(1);
		}
		else
		{
			front = (front + 1) % SIZE;
			buffer[front] = NULL;
		}
	}

	T& Front()
	{
		return buffer[(front + 1) % SIZE];
	}

	T& Back()
	{
		return buffer[rear];
	}



};

int main()
{

#pragma region ���� ť
	// ���������δ� ���� ������ ������ ������,
	// ť�� �������� ������ ������ ������ ť�Դϴ�.

	CircleQueue<int> cicleQueue;

	cicleQueue.Push(10);
	cicleQueue.Push(20);
	cicleQueue.Push(30);

	cicleQueue.Pop();
	cicleQueue.Pop();
	cicleQueue.Pop();

	cicleQueue.Push(999);

	std::cout << cicleQueue.Front() << std::endl;
	std::cout << cicleQueue.Back() << std::endl;


#pragma endregion




	return 0;
}
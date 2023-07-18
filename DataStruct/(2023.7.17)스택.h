//#include <iostream>
//#include <stack>
//
//#define SIZE 5
//
//template <typename T>
//class STACK
//{
//private:
//	int top;
//	T buffer[SIZE];
//
//public:
//	STACK()
//	{
//		buffer[SIZE] = NULL;
//		top = -1;
//	}
//
//
//
//	bool Empty()
//	{
//		// ��������� true �ƴϸ� false
//		if (top <= -1)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//
//	}
//
//	bool IsFull()
//	{
//		// ������ true �ƴϸ� false
//		if (SIZE - 1 <= top)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//
//	}
//
//	void Push(T data)
//	{
//		if (IsFull())
//		{
//			std::cout << " STACK�� �����Ͱ� ���� á���ϴ�." << std::endl;
//			exit(1);
//		}
//		else
//		{
//			buffer[++top] = data;
//		}
//	}
//
//	T Pop()
//	{
//		if (Empty())
//		{
//			std::cout << " STACK�� �����Ͱ� ����ֽ��ϴ�. " << std::endl;
//			exit(1);
//		}
//		else
//		{
//			return buffer[top--];
//		}
//
//	}
//
//	T Top()
//	{
//		if (Empty())
//		{
//			return 0;
//		}
//		else
//		{
//			return buffer[top];
//		}
//	}
//
//
//	~STACK() {}
//
//};
//
//
//int main()
//{
//	STACK<int> intStack;
//
//	intStack.Push(10);
//	intStack.Push(20);
//	intStack.Push(30);
//	intStack.Push(40);
//
//	while (!intStack.Empty())
//	{
//		std::cout << intStack.Top() << std::endl;
//		intStack.Pop();
//	}
//
//	intStack.Pop();
//
//	while (1)
//	{
//	}
//
//
//
//	return 0;
//}
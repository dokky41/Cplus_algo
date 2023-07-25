#include <iostream>

#define SIZE 5

class Component
{
private:
	float x;
	float y;
	int* count;

public:
	// �⺻ ������
	Component()
	{
		count = new int;
		x = 10;
		y = 20;
	};

	// ���� ������
	Component(Component& other)
	{
		std::cout << "���� ������" << std::endl;

		this->x = other.x;
		this->y = other.y;

		// ��������
		other.count = new int;
	}

	// �̵� ������
	Component(Component&& other)
	{
		std::cout << "�̵� ������" << std::endl;
		this->x = other.x;
		this->y = other.y;
		this->count = other.count;

		other.count = nullptr;

	}


};

int main()
{

#pragma region ��������
	// �� ��° �ڷ���� �����Ͽ� �� ��(����)��
	// �ڷ��� ���Ͽ� ������ ��ġ�� ������ ��
	// �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ�
	// �����ϴ� �˰����Դϴ�.

	// ������ ���� �� �ִ� �ӽð���
	//int array[SIZE] = { 5,8,6,1,2 };
	//int temp = 0;
	//
	//for (int i = 1; i < SIZE; i++)
	//{
	//	temp = array[i];
	//	for (int j = i-1; j >= 0; j--)
	//	{
	//		if (array[j] > array[j+1])
	//		{
	//			array[j + 1] = array[j];
	//			array[j] = temp;
	//		}
	//	}
	//}
	//
	//for (const int & element : array)
	//{
	//	std::cout << element << " ";
	//}




#pragma endregion

#pragma region �̵� ������
	// ���� ��ü�� �ּ� �� ���� ���ο� ������Ʈ��
	// �������� ������Ű�� �������Դϴ�.

	Component component1;

	Component component2 = component1;
	Component component3{ std::move(component1) };


#pragma endregion







	return 0;
}
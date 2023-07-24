#include <iostream>

#define SIZE 5

class Component
{
private:
	float x;
	float y;
	int * count;

public:
	// 기본 생성자
	Component()
	{
		count = new int;
		x = 10;
		y = 20;
	};

	// 복사 생성자
	Component(Component & other)
	{
		std::cout << "복사 생성자" << std::endl;

		this->x = other.x;
		this->y = other.y;

		// 깊은복사
		other.count = new int;
	}

	// 이동 생성자
	Component(Component&& other)
	{
		std::cout << "이동 생성자" << std::endl;
		this->x = other.x;
		this->y = other.y;
		this->count = other.count;

		other.count = nullptr;
	
	}


};

int main()
{

#pragma region 삽입정렬
	// 두 번째 자료부터 시작하여 그 앞(왼쪽)의
	// 자료들과 비교하여 삽입할 위치를 지정한 후
	// 자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여
	// 정렬하는 알고리즘입니다.

	// 정수를 받을 수 있는 임시공간
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

#pragma region 이동 생성자
	// 기존 객체의 주소 및 값을 새로운 오브젝트에
	// 소유권을 이전시키는 생성자입니다.

	Component component1;
	
	Component component2 = component1;
	Component component3{ std::move(component1) };


#pragma endregion







	return 0;
}
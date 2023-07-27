#include <iostream>

#define SIZE 10

int quickArray[SIZE] = { 4,1,2,3,9,7,8,6,10,5 };

void QuickSort(int data[],int right,int left)
{
	int pivot = 0;

	while (right < left)
	{
		for (int i = 1; i < SIZE; i++)
		{
			if (quickArray[i] > quickArray[pivot])
			{
				left = quickArray[i];
				break;
			}
		}

		for (int j = SIZE-1; j > left; j--)
		{
			if (quickArray[j] > quickArray[pivot])
			{
				right = quickArray[j];
				break;
			}
		}
	}

}


int main()
{

#pragma region 계수 정렬
	// 데이터의 값을 직접 비교하지 않고, 단순하게 각 숫자가 
	// 몇 개 있는지 갯수를 세어 저장한 다음 정렬하는 알고리즘입니다.

	//int numbers[SIZE] = { 1,3,3,4,5,5,5,1,2,2 };
	//int cntArray[5] = { 0, };
	//
	//for (int i = 0; i < SIZE; i++)
	//{
	//	cntArray[numbers[i]-1]++;
	//}
	//
	//for (int j = 0; j < 5; j++)
	//{
	//	std::cout << cntArray[j] << " ";
	//}


#pragma endregion

#pragma region 퀵 정렬
	// 기준점을 획득한 다음 해당 기준점을 기준으로 배열을 나누고 
	// 한 쪽에는 기준점보다 작은 항목들이 위치하고 다른 쪽에는 기준점보다 큰 항목들이 위치한다.

	// 나뉘어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여,
	// 모든 배열이 기본 배열(요소가 하나뿐인 배열)이 될 때까지 반복하는 알고리즘입니다.

	// left는 pivot 값보다 큰 값을 찾는다
	// right는 pivot값보다 작은 값을 찾는다

#pragma endregion

	int numbers[SIZE] = { 5,3,8,4,9,2,1,6,7 };
	int pivot = 0;
	int right=SIZE, left=1;
	
	

	return 0;
}
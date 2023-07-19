#include <iostream>
#include <limits.h>

#define SIZE 5

int main()
{

#pragma region �ð� ���⵵
	// ��ǻ�� ���α׷��� �Է� ���� ���� ���� �ð��� 
	// ������踦 ��Ÿ���� ô���Դϴ�.

	// Big-O ǥ���
	// '�Է°��� ��ȭ�� ���� ������ ������ ��,
	// ���� Ƚ���� ���� �ð��� �󸶸�ŭ �ɸ��� �� ��Ÿ���� ô���Դϴ�.
	// 
	// �־��� ��츦 ����ϹǷ�, ���α׷��� ����Ǵ� ��������
	// �ҿ�Ǵ� �־��� �ð����� ����� �� �ֱ� �����Դϴ�.

	// O(1) ��� �ð����⵵ 
	/*
	// �Է� ���� �����ϴ��� �ð��� �þ�� �ʴ� ���⵵�Դϴ�.

	// ex) �迭�� �ε��� ����
	// int buffer[100];
	// buffer[50] = 10;
	// std::cout << buffer[50] << std::endl;
	*/

	// O(n) ���� �ð� ���⵵
	/*
		�Է°��� �����Կ� ���� �ð� ���� ���� ������
		�����ϴ� �ð� ���⵵�Դϴ�.

		for(int i=0; i<�Է°�(N); i++
		{

		}


	*/

	// O(log n) �α� �ð� ���⵵
	/*
		�Է� �������� ũ�Ⱑ Ŀ������ ó�� �ð��� �α�(log) ��ŭ
		ª������ �ð� ���⵵

	*/

	// O(n^2) 2�� �ð� ���⵵
	/*
	// �Է°��� �����Կ� ���� �ð��� n�� ��������
	// ������ �����ϴ� �ð� ���⵵�Դϴ�.

	ex) for(int i=0; i< n; i++)
		{
			for(int j=0; j<n; j++)
			{

			}
		}


	*/

	// O(2n) ���� �޼��� �ð� ���⵵ (��ȿ������)
	/*
		ex) ����Լ� ( �Ǻ���ġ ���� )

	*/


#pragma endregion

#pragma region ��ǰ ����
	// ���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰����Դϴ�.

	// �ð� ���⵵ O(n^2)



	// ���� ���� �� ���
	// int sortBuffer[SIZE] = { 7,4,5,1,3 };
	// int num = 0;
	// int n = 0;
	// 
	// std::cin >> n; //�ݺ�Ƚ�� n-1 
	// 				
	// for (int i = 0; i < n-1; i++)
	// {
	// 	for (int j = 0; j < n-1-i;  j++)
	// 	{
	// 		if (sortBuffer[j] > sortBuffer[j + 1])
	// 		{
	// 			num = sortBuffer[j+1];
	// 			sortBuffer[j + 1] = sortBuffer[j];
	// 			sortBuffer[j] = num;
	// 		}
	// 	}
	// }
	// 
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	std::cout << sortBuffer[i] << " ";
	// }

	//���
	//int sortBuffer[SIZE] = {7,4,5,1,3};
	//
	//for (int i = 0; i < SIZE; i++)
	//{
	//	for (int j = 0; j < SIZE - i - 1; j++)
	//	{
	//		if (sortBuffer[j] > sortBuffer[j + 1])
	//		{
	//			std::swap(sortBuffer[j], sortBuffer[j + 1]);
	//		}
	//	}
	//}
	//
	//for (int i = 0; i < SIZE; i++)
	//{
	//	std::cout << sortBuffer[i] << " ";
	//}


#pragma endregion

#pragma region ���� ����
	// ���ĵ��� ���� �����͵鿡 ���� 
	// ���� ���� �����͸� ã�Ƽ� ���� ���� �����Ϳ� ��ȯ�ϴ� �˰����Դϴ�.

	// �ð����⵵ (O(n^2))

	//int selectBuffer[SIZE] = { 6,2,11,4,3 };
	//int num = 0;
	//
	//for (int i = 0; i < SIZE; i++)
	//{
	//	for (int j = i + 1; j < SIZE; j++)
	//	{
	//		if (selectBuffer[j] < selectBuffer[i])
	//		{
	//			num = selectBuffer[i];
	//			selectBuffer[i] = selectBuffer[j];
	//			selectBuffer[j] = num;
	//		}
	//	}
	//
	//}
	//
	//for (int k = 0; k < SIZE; k++)
	//{
	//	std::cout << selectBuffer[k] << " ";
	//}
	//
	//std::cout << std::endl;


	// ����
	int selectBuffer[SIZE] = { 6,2,11,4,3 };


	for (int i = 0; i < SIZE; i++)
	{
		// �ּڰ�
		int min = selectBuffer[i];

		// select ����
		int select = i;

		for (int j = i + 1; j < SIZE; j++)
		{
			if (min > selectBuffer[j])
			{
				min = selectBuffer[j];
				select = j;
			}
		}

		std::swap(selectBuffer[i], selectBuffer[select]);

	}


	for (auto& element : selectBuffer)
	{
		std::cout << element << " ";
	}

#pragma endregion




	return 0;
}
#include <iostream>
#include <vector>

#pragma region �׷���
// ������ �������� �̷���� �ڷᱸ���Դϴ�.

// ����(Vertex) : ��带 �ǹ��ϸ�, �� ��忡�� ������ ����˴ϴ�.

// ����(Edge) : ��ũ��� �ϸ�, ��尣�� ���踦 ��Ÿ���ϴ�.

// ����(degree) : ������ �׷������� �ϳ��� ������ ������ ������ ��

// ���� ����(out-degree) : ���� �׷������� ���Ǹ� , �� ��忡�� �ܺη� ���ϴ� ������ ��

// ���� ����(in-degree) : ���� �׷������� ���Ǹ�, �ܺ� ��忡�� ������ ������ ��



#pragma endregion


int main()
{

#pragma region ���� ��� 
	// �׷����� ���� ���踦 ������ �迭�� ��Ÿ���� ����Դϴ�.

	// ���� : �� ���� ���� ���� ������ ��ȸ�� ��
	//			O(1)�� �ð� ���⵵�� �ɸ��ϴ�.

	// ���� : 2���� �迭�� �ʿ��ϱ⿡ �ʿ� �̻��� ������ ����մϴ�.
	//        ��� ������ ���� ������ ������ �����ؾ��ϹǷ�, O(n^2)�� �ð� ���⵵�� �ɸ��ϴ�.

	//int buffer[4][4] = { 0, };
	//
	//int vertex = 0;
	//int edge = 0;
	//int x = 0, y = 0;
	//
	//// 1. vertex�� edge ���� �Է��մϴ�.
	//std::cout << "vertex�� �Է����ּ���. " << std::endl;
	//std::cin >> vertex;
	//
	//std::cout << "edge�� �Է����ּ���. " << std::endl;
	//std::cin >> edge;
	//
	//std::cout << "--------------------------------" << std::endl;
	//
	//// 2. edge��ŭ �ݺ��ϸ鼭 x�� y���� �Է� �� �� �ֵ��� �����մϴ�.
	//for (int i = 0; i < edge; i++)
	//{
	//	std::cout << "x,y�� ���� �Է����ּ���." << std::endl;
	//	std::cin >> x >> y;
	//	buffer[x][y] = 1;
	//	buffer[y][x] = 1;
	//}
	//
	//std::cout << std::endl;
	//
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		std::cout << buffer[i][j] << " ";
	//	}
	//
	//	std::cout << std::endl;
	//}


#pragma endregion


#pragma region ���� ����Ʈ
	// �׷����� ���� ���踦 vector�� �迭(vector<int> data[])�� ��Ÿ���� �迭�Դϴ�.

	// ���� : �ʿ��� ������ŭ ����ϱ� ������ ���� ���� �����ϴ�.
	// ���� : Ư�� �� ���� ����Ǿ����� Ȯ���Ϸ��� ������Ŀ� ���� �ð��� �����ɸ��ϴ�.

	int node = 0;
	int edge = 0;
	int x = 0, y = 0;

	//1. vertex�� edge ���� �Է��մϴ�.
	std::cout << "node�� �Է����ּ���. " << std::endl;
	std::cin >> node;

	std::cout << "edge�� �Է����ּ���. " << std::endl;
	std::cin >> edge;

	std::vector<int> data[4];

	for (int i = 0; i < edge; i++)
	{
		std::cout << "x,y�� ���� �Է����ּ���." << std::endl;
		std::cin >> x >> y;

		std::cout << " ------------------------  " << std::endl;

		data[x].push_back(y);
		data[y].push_back(x);
	}

	for (int i = 0; i < edge; i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			std::cout << data[i][j] << " ";

		}
		std::cout << std::endl;
	}

#pragma endregion




	return 0;
}
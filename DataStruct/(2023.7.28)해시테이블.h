#include <iostream>

#define SIZE 10

//int quickArray[SIZE] = { 4,1,2,3,9,7,8,6,10,5 };

void QuickSort(int data[], int start, int end)
{
	// ���Ұ� 1�� ���� ���
	//if (start >= end) return;
	//
	//int pivot = start;
	//int left = start + 1;
	//int right = end;
	//
	//while (left <= right)
	//{
	//	
	//	// left�� end���� �۰ų� ���ٸ� �ݺ�
	//	// ���ʿ� �ִ� left������ pivot�� ���մϴ�.
	//	while (quickArray[left] < quickArray[pivot] && left <= end)
	//	{
	//		left++;
	//	}
	//
	//	// right�� start���� ũ�ٸ� �ݺ�
	//	// �����ʿ� �ִ� right ������ pivot�� ���մϴ�.
	//	while (quickArray[right] > quickArray[pivot] && right > start)
	//	{
	//		right--;
	//	}
	//
	//	// if ���ʰ� �������� �������� ��
	//	if (left > right)  
	//	{
	//		std::swap(quickArray[right], quickArray[pivot]);
	//	}
	//	else { // right�� left���� ��ȯ�մϴ�.
	//		std::swap(quickArray[right], quickArray[left]);
	//	}
	//
	//}
	//
	//QuickSort(data, start, right-1);
	//QuickSort(data, right+1, end);


}

struct Node
{
	int key;
	int value;
	Node* next;
};

struct Bucket
{
	Node* head;
	int count;
};


class HashTable
{
private:
	Bucket bucket[5];
	int bucketSize = 5;

public:
	HashTable()
	{
		for (int i = 0; i < 5; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	Node* CreateNode(int key, int value)
	{
		// 1. ���ο� ��带 �����մϴ�.
		Node* newNode = new Node;

		// 2. ���ο� ����� key���� �����մϴ�.
		newNode->key = key;

		// 3. ���ο� ����� value ���� �����մϴ�.
		newNode->value = value;

		// 4. ���ο� ����� next�� ���� �ʱ�ȭ�մϴ�.
		newNode->next = nullptr;

		// 5. ���ο� ����� �ּ� ���� ��ȯ�մϴ�.
		return newNode;
	}

	int HashFunction(int key) //Ű �� ��ȯ �Լ�
	{
		int result = 0;

		result = key % 5;

		return result;
	}

	void Insert(int key, int value)
	{
		// �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunction(key);

		// ���ο� ��带 �����մϴ�.
		Node* newNode = CreateNode(key, value);

		// ��尡 1 �� �� �������� �ʴ´ٸ�
		if (bucket[hashIndex].count == 0)
		{
			// 1. bucket[hashIndex]�� head�����Ϳ� ���ο� ����� �ּڰ��� �����մϴ�.
			bucket[hashIndex].head = newNode;

			// 2. bucket[hashIndex]�� count ������ ���� �����մϴ�.
			bucket[hashIndex].count++;
		}
		else // ��尡 1�� �� �����Ѵٸ�
		{
			// 1. newNode�� next�� bucket[hashIndex]�� head�� ���� �־��ݴϴ�.
			newNode->next = bucket[hashIndex].head;

			// 2.  bucket[hashIndex].head�� ��� ���� ������ node�� ���� �ּҸ� ����Ű���� �����մϴ�.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex]�� count ������ ���� �����մϴ�.
			bucket[hashIndex].count++;

		}

	}

	void Remove(int key)
	{
		// �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunction(key);

		// Node�� Ž���� �� �ִ� ��ȸ�� ������ ���� ���� <- �� bucket�� head���� �����մϴ�.
		Node* currentPtr = bucket[hashIndex].head;

		Node* traceNode = nullptr;

		// currentPtr�� nullptr�̶�� �Լ��� �����մϴ�.
		if (currentPtr == nullptr)
		{
			std::cout << "���� ��尡 �������� �ʽ��ϴ�." << std::endl;
			return;
		}

		// currentPtr�� �̿��� ���� ã���� �ϴ� key���� ã���� ��
		while (currentPtr)
		{
			if (key == currentPtr->key)
			{
				//���� �����ϰ��� �ϴ� key�� head�� �ִ� �����...
				if (currentPtr == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentPtr->next;
				}
				else
				{
					traceNode->next = currentPtr->next;
				}

				// �� bucket�� count���� ���ҽ�ŵ�ϴ�.
				bucket[hashIndex].count--;

				//�޸𸮸� �����մϴ�.
				delete currentPtr;

				return;
			}

			// �ش��ϴ� KEY�� ���ٸ� ���� NODE�� �ּҸ� �����մϴ�.
			traceNode = currentPtr;
			currentPtr = currentPtr->next;
		}

	}

	void Search(int key)
	{
		// �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunction(key);

		// Node�� Ž���� �� �ִ� ��ȸ�� ������ ���� ���� <- �� bucket�� head���� �����մϴ�.
		Node* currentPtr = bucket[hashIndex].head;

		// currentPtr�� nullptr�̶�� �Լ��� �����մϴ�.
		if (currentPtr == nullptr)
		{
			std::cout << "ã���� �ϴ� ��尡 �������� �ʽ��ϴ�." << std::endl;
			return;
		}

		// currentPtr�� �̿��� ���� ã���� �ϴ� key���� ã���� ��
		while (currentPtr)
		{
			if (key == currentPtr->key)
			{
				std::cout << "Key : " << currentPtr->key << " Value : " << currentPtr->value << std::endl;
				return;
			}

			// �ش��ϴ� KEY�� ���ٸ� ���� NODE�� �ּҸ� �����մϴ�.
			currentPtr = currentPtr->next;
		}

		std::cout << "ã���� �ϴ� KEY�� �������� �ʽ��ϴ�." << std::endl;
	}


	void Show()
	{


		for (int i = 0; i < 5; i++)
		{
			Node* node = bucket[i].head;

			if (node == nullptr)
			{
				break;
			}

			for (int j = 0; j < bucket[i].count; j++)
			{
				std::cout << node->value << " ";
				node = node->next;
			}
			std::cout << std::endl;
		}
	}


};



int main()
{

#pragma region �� ����
	// �������� ȹ���� ���� �ش� �������� �������� �迭�� ������ 
	// �� �ʿ��� ���������� ���� �׸���� ��ġ�ϰ� �ٸ� �ʿ��� ���������� ū �׸���� ��ġ�Ѵ�.


	// �������� ���� �迭�� ���� ��������� �� ������ ȣ���Ͽ�,
	// ��� �迭�� �⺻ �迭(��Ұ� �ϳ����� �迭)�� �� ������ �ݺ��ϴ� �˰����Դϴ�.

	//QuickSort(quickArray, 0, 9);
	//
	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << quickArray[i] << " ";
	//}
#pragma endregion

#pragma region �ؽ� ���̺�
	// (Key, Value)�� �����͸� �����ϴ� �ڷᱸ�� �� �ϳ���
	// ������ �����͸� �˻��� �� �ִ� �ڷᱸ���Դϴ�.

	// �ؽ� ���̺��� ��� �ð� ���⵵�� O(1)�Դϴ�.


	// �ؽ� �浹�� �ذ��ϴ� ���

	// ü�̴� ���
	// �� �ؽ� ��Ŷ�� ���Ḯ��Ʈ�� �����ϴ� ����Դϴ�.
	HashTable hashTable;

	hashTable.Insert(5, 555);
	hashTable.Insert(10, 111);

	//hashTable.Remove(10);

	//hashTable.Search(10);

	hashTable.Show();


	// �ؽ� �浹 �߻� �� ������ �ؽ� ���� �ش��ϴ� �����͵��� 
	// ���Ḯ��Ʈ�� �����Ͽ� �����մϴ�.

	// ���� �ּҹ�
	/*
	// �浹 �߻� �� �� ���Ͽ� �����͸� �����ϴ� ����Դϴ�.
	// �� ��Ŷ�� ��� ������ ���� ���� ���� ����� �޶����ϴ�.

	// ���� Ž�� : �浹�߻� �� �տ��� ���� ���ʴ�� �� ��Ŷ��
	// ã�� ���� �����ϴ� ����Դϴ�.

	// ���� Ž�� : �浹�߻� �� 2^2, 2^3 ��ŭ ������ �� ��Ŷ�� ã��
	// ���� �����ϴ� ����Դϴ�.

	// ���� �ؽ� : �ؽ� ���� �ѹ� �� �ؽ� �Լ��� �־� �ٸ� �ؽð���
	// �����ϴ� ����Դϴ�.
	*/



#pragma endregion





	return 0;
}
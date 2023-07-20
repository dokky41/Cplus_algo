#include <iostream>

template <typename T>
class VECTOR
{
private:
	int capacity;
	int size;

	T* array;

public:
	VECTOR()
	{
		capacity = 1;
		array = new T[size];
	}

	void Push_Back(T data)
	{
		if (size >= capacity)
		{
			capacity *= 2;

			ReSize(capacity);
		}

		array[size++] = data;
	}


	void Pop_Back()
	{
		if (size <= 0)
		{
			return;
		}
		array[--size] = NULL;
	}


	//			 size��
	void Resize(int size)
	{
		// capacity�� ���ο� size ���� �����Ѵ�.
		capacity = size;

		// ���ο� ������ ������ �����ؼ� ���Ӱ� ������� 
		// �޸� ������ ����Ű���� �����մϴ�.
		T* tempArray = new T[size];

		// ���ο� �޸� ������ ���� �ʱ�ȭ�մϴ�.
		for (int i = 0; i < size; i++)
		{
			tempArray[i] = NULL;
		}

		// ���� �迭�� �ִ� ���� �����ؼ� ���ο� �迭�� �־��ݴϴ�.
		for (int i = 0; i < this->size; i++)
		{
			tempArray[i] = array[i];
		}

		// array�� �޸� �ּҸ� ����
		delete(array);

		// array�� ���� �Ҵ��� �޸��� ���� �ּҸ� �����մϴ�
		array = tempArray;

	}

	int Size()
	{
		return size;
	}

	// ������ �����ε� [ ]
	T& operator [ ] (const int& value)
	{
		return array[value];
	}

	~VECTOR()
	{
		delete(array);
	}

};

int main()
{




	return 0;
}
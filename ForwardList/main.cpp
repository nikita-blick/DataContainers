#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
int Element::count = 0;

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{            
		                   // ����������� �� ���������
		Head = nullptr;   // ���� ������ ����, �� ��� ������ ��������� �� 0.
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "FLDestructor:\t" << this << endl;
	}


	//    Adding elements:
	void push_front(int Data)
	{
		// 1) ������� ������� � ��������� � ���� ����������� �������� 
		Element* New = new Element(Data);

		// 2) ����������� �����, ��������� ������� � ������ ������
		New->pNext = Head;

		// 3) ��������� ������ �� ����� ������� (���������� ����� ������� � ������)
		Head = New;

	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
	}

	//				Removing elements:
	void pop_front()
	{
		//1) ���������� ����� ���������� ��������:
		Element* Erased = Head;
		//2) ��������� ��������� ������� �� ������:
		Head = Head->pNext;
		//3) ������� ��������� ������� �� ������:
		delete Erased;
	}

	void pop_back()
	{
		if (Head == nullptr || Head->pNext == nullptr)return pop_front();
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}

	void insert(int Data, int Index)
	{
		if (Index == 0)return push_front(Data);
		if (Index >= Element::count)return push_back(Data);
		//1) ������� �� ������� �������� (������� ����� �����������)
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;
		//2) ������� ����������� �������:
		Element* New = new Element(Data);
		//3) �������������� ����� ������� � ��� ���������� �������:
		New->pNext = Temp->pNext;
		//4) �������������� ���������� ������� � ������:
		Temp->pNext = New;
	}


	//   Methods:
	void print()const
	{
		Element* Temp = Head;     //Temp - ��� ��������. �������� - ��� ���������, ��� ������ �������� ����� ���������� �������� ��������� ������. 
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		Temp;	//��������� 'Temp';
		//Temp->;	//������� 'Temp';
		cout << "���������� ��������� ������: " << Element::count << endl;
	}
};


#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK

	//Element element = 5;

	int n;
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
		//list.push_front(rand() % 100);
	}
	//list.push_back(123);
	list.print();
	int index;
	int value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	list.insert(value, index);
	list.print();
#endif // BASE_CHECK

	ForwardList list1;
	list1.push_back(0);
	list1.push_back(1);
	list1.push_back(1);
	list1.push_back(2);
	list1.print();

	ForwardList list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(8);
	list2.push_back(13);
	list2.push_back(21);
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();

	int index;
	int value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	list1.insert(value, index);
	list1.print();
}
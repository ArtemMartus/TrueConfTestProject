#include "Resources.h"

int main()
{
	std::srand((uint)std::time(0));							// ������������� ���������� ��������������� �����
	std::vector<int> v1 = std::vector<int>(ARRAY_SIZE);
	std::map<int, int> m1 = std::map<int, int>();

	InitilizeContainers(&v1, &m1);							// �-��� ���������� ����������� �������

#ifdef _DEBUG
	auto backupV1 = v1;										// ����� ����������� ��� ����� ������� ������� 
	auto backupM1 = m1;
#endif

	DeleteVectorItems(&v1);									// �������� 1..15 ��������� �� �����������
	DeleteMapItems(&m1);

#ifdef _DEBUG
	auto backupV2 = v1;										// ����� ����������� ��� ����� ������� ������� 
	auto backupM2 = m1;
#endif


	int similarItems = Syncronize(&v1, &m1);				// ������������� �����������  -> int ������� ��������� ���������������� 

	std::cout << "similar " << similarItems << std::endl;

#ifdef _DEBUG
	for (auto i = v1.begin(); i !=v1.end(); i++) {
		
		std::cout << (*i) << "\t";
	}
	

	for (auto i = m1.begin(); i != m1.end(); i++) {
		std::cout << (*i).second << std::endl;                
	}
#endif

	system("pause");
}

int GetRandomNumber(int max)							// �-��� ��������� ��������������� ����� [1;max] 
{
	int rnd = std::rand() % max + 1;
	return  rnd == 0 ? GetRandomNumber(max) : rnd;
}

void InitilizeContainers(std::vector<int>*v, std::map<int, int>*m)
{
	for (int i = 0; i < ARRAY_SIZE; i++) {
		(*v)[i] = GetRandomNumber(9);				// � ������� ��������������� ����� ��� ARRAY_SIZE ������� ������������� ��������� [] ����� ������� �-��� push_back
		(*m)[i] = GetRandomNumber(9);
	}
}

void DeleteVectorItems(std::vector<int>*v)
{
	std::vector<int> nV;
	int itemsToDelete = GetRandomNumber(15) % ARRAY_SIZE;
	int deletedItems = 0;

	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (deletedItems < itemsToDelete && GetRandomNumber(1) == 1)
			deletedItems++;
		else
			nV.push_back((*v)[i]);

	}

	v->empty();
	*v = nV;
}

void DeleteMapItems(std::map<int, int>*m)
{

	int itemsToDelete = GetRandomNumber(15) % ARRAY_SIZE;
	int deletedItems = 0;
	int currentMapIndex = 0;
	std::map<int,int> nM;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (deletedItems < itemsToDelete && GetRandomNumber(1) == 1)
			deletedItems++;
		else
			nM[currentMapIndex++] = (*m)[i];

	}
	m->empty();
	*m = nM;

}

int Syncronize(std::vector<int>* v, std::map<int, int> * m)
{
	int sync_count = 0;

	auto vI = (*v).begin();
	auto vM = (*m).begin();

	std::map<int, int> nM;
	std::vector<int> nV;

	
	do {
		if (vI == v->end() || vM == m->end())
			break;

		if ((*vM).second == (*vI)) {
			nM.insert(*vM);
			nV.push_back(*vI);
			sync_count++;
		}


		vI++;
		vM++;
	} while (true);

	m->empty();
	*m = nM;

	v->empty();
	*v = nV;

	return sync_count;
}
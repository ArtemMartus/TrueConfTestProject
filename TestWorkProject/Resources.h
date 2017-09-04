#pragma once
#define uint unsigned int
#define ARRAY_SIZE 0xfffff

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <map>
#include <vector>
#include <string>

//1.��������� ���������� ������� �� 1 �� 9 �������� �����������
//vector[i] � map[i];


int GetRandomNumber(int max);
void InitilizeContainers(std::vector<int>*v, std::map<int, int>*m);

//2.������� ��������� ����� ���������(�� ����� 15) � ������
//����������;

void DeleteVectorItems(std::vector<int>*v);
void DeleteMapItems(std::map<int,int>*m);

//3.����� ����� �������� �������������, ����� � vector � map
//�������� ������ ��������� � ����� ����������� ��������
//(��������� �� �������).

int Syncronize(std::vector<int>* v, std::map<int, int> * m);
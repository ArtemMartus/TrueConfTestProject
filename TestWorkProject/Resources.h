#pragma once
#define uint unsigned int
#define ARRAY_SIZE 0xfffff

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <map>
#include <vector>
#include <string>

//1.заполнить случайными числами от 1 до 9 значения контейнеров
//vector[i] и map[i];


int GetRandomNumber(int max);
void InitilizeContainers(std::vector<int>*v, std::map<int, int>*m);

//2.удалить случайное число элементов(не более 15) в каждом
//контейнере;

void DeleteVectorItems(std::vector<int>*v);
void DeleteMapItems(std::map<int,int>*m);

//3.после этого провести синхронизацию, чтобы в vector и map
//остались только имеющиеся в обоих контейнерах элементы
//(дубликаты не удалять).

int Syncronize(std::vector<int>* v, std::map<int, int> * m);
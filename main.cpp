#include "stdio.h"
#include "locale.h"
#include <iostream>

using namespace std;

#pragma once

const int N = 10; //выбираем число дисков. Можно определить это константой, можно сделать это число вводимым с клавиатуры

int numoffree(int a[]) {    //функция, возвращающая номер самого левого свободного (равного нулю) места
	int num = 0;     
	while ((a[num] > 0)&&(a[num]<=N))      //если массив полностью забит, то вернётся 8
		num++;
	return num;
}

void change(int a1[], int a2[]) {    //функция, которая в словестном описании называется действием "1-2" (с 1 штыря на 2 или наоборот)
	bool flag = 0;
	if (numoffree(a1) == 0) {
		a1[0] = a2[numoffree(a2) - 1];
		a2[numoffree(a2) - 1] = 0;
		flag = 1;
	}
	if (flag == 0)
		if (numoffree(a2) == 0) {
		a2[0] = a1[numoffree(a1) - 1];
		a1[numoffree(a1) - 1] = 0;
		flag = 1;
		}
	if (flag == 0)
		if (a1[numoffree(a1) - 1] < a2[numoffree(a2) - 1]) {
		a2[numoffree(a2)] = a1[numoffree(a1) - 1];          
		a1[numoffree(a1) - 1] = 0;
		flag = 1;
		}
	if (flag == 0)
		if (a1[numoffree(a1) - 1] > a2[numoffree(a2) - 1]) {
		a1[numoffree(a1)] = a2[numoffree(a2) - 1];
		a2[numoffree(a2) - 1] = 0;
		}
}

bool equal(int a1[N], int a2[N]) {
	bool flag = 1;
	for (int i = 0; i < N; i++)
		if (a1[i] != a2[i])
			flag = 0;
	return flag;
}

void main() {               //основная функция - сама программа
	setlocale(LC_CTYPE, "Russian");
	int a1[N], a2[N], a3[N];  //создаём 3 массива (штыря) размером N
	int a[N];                 //вспомогательный массив, с которым потом будем сравнивать второй и третий
	for (int i = 0; i < N; i++) {
		a1[i] = N - i; //вводим данные в первый массив. Число 8 - самый большой и самый нижний диск (самый первый в массиве), 1 - самый малый
		a2[i] = 0;     //второй и третий массивы заполняем нулями (элемент равен 0 <=> диска на этой позиции нет)
		a3[i] = 0;
		a[i] = N - i;     //вспомогательный заполняем как первый
	}
	cout << "a1" << endl;
	for (int i = 0; i < N; i++)
		cout << a1[i];
	cout << endl;
	cout << "a2" << endl;
	for (int i = 0; i < N; i++)
		cout << a2[i];
	cout << endl;
	cout << "a3" << endl;
	for (int i = 0; i < N; i++)
		cout << a3[i];
	cout << endl;
	bool flag = 0;          //флаг, при поднятии которого должна остановиться программа (задача будет решена)
	if (N % 2 == 0) {
		while (flag == 0) {
			change(a1, a2);
			if (equal(a, a2) == 1)
				flag = 1;
			if (equal(a, a3) == 1)
				flag = 1;
			if (flag == 0) {
				change(a1, a3);
				if (equal(a, a2) == 1)
					flag = 1;
				if (equal(a, a3) == 1)
					flag = 1;
			}
			if (flag == 0) {
				change(a2, a3);
				if (equal(a, a2) == 1)
					flag = 1;
				if (equal(a, a3) == 1)
					flag = 1;
			}
		}
	}
	if (N % 2 == 1) {
		while (flag == 0) {
			change(a1, a3);
			if (equal(a, a2) == 1)
				flag = 1;
			if (equal(a, a3) == 1)
				flag = 1;
			if (flag == 0) {
				change(a1, a2);
				if (equal(a, a2) == 1)
					flag = 1;
				if (equal(a, a3) == 1)
					flag = 1;
			}
			if (flag == 0) {
				change(a2, a3);
				if (equal(a, a2) == 1)
					flag = 1;
				if (equal(a, a3) == 1)
					flag = 1;
			}
		}
	}
	cout << "a1" << endl;
	for (int i = 0; i < N; i++)
		cout << a1[i];
	cout << endl;
	cout << "a2" << endl;
	for (int i = 0; i < N; i++)
		cout << a2[i];
	cout << endl;
	cout << "a3" << endl;
	for (int i = 0; i < N; i++)
		cout << a3[i];

}

// NineNumberGame.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

int swap(int index1, int index2); //交換位置並回傳0的位置引數
void PrintArray();
void rotate(int choice, int ZeroPosi);
int NumberArray[9] = { 1,2,3,8,0,4,7,6,5 };
//int NumberArray[9] = { 8,5,0,7,6,1,3,2,4 };
void Reset();
int GetNumberPosi(int number);
int GetBlock(int number);
int main()
{
	srand((unsigned int)time(NULL));
	Reset();
	int ZeroPosition = GetNumberPosi(0);
	PrintArray();
	//調整1
	if (ZeroPosition == 0)
		ZeroPosition = swap(ZeroPosition, 1);
	if (NumberArray[0] != 1) {
		int OnePosition = GetNumberPosi(1);
		if (OnePosition != 4 && ZeroPosition != 4) {//兩個都不在中間
			while (NumberArray[0] != 1) {
				rotate(5, ZeroPosition);
			}
		}
		else if (OnePosition == 4) {//1在中間
			rotate(GetBlock(0), ZeroPosition);
			PrintArray();
			while (NumberArray[0] != 1) {
				rotate(5, ZeroPosition);
			}
		}
		else {
			if (OnePosition != 1) {
				ZeroPosition = swap(1, ZeroPosition);
			}
			else {
				ZeroPosition = swap(5, ZeroPosition);
			}
			while (NumberArray[0] != 1) {
				rotate(5, ZeroPosition);
			}
		}
	}

	PrintArray();
	//調整2
	ZeroPosition = GetNumberPosi(0);
	if (ZeroPosition == 1)
		ZeroPosition = swap(ZeroPosition, 2);
	PrintArray();
	if (NumberArray[1] != 2) {
		int TwoPosition = GetNumberPosi(2);
		if (ZeroPosition != 3 && ZeroPosition != 6 && TwoPosition != 3 && TwoPosition != 6) {
			while (NumberArray[1] != 2) {
				rotate(6, ZeroPosition);
			}
		}
		else if ((ZeroPosition == 3||ZeroPosition == 6 )&& TwoPosition>2) {
			ZeroPosition = swap(ZeroPosition, ZeroPosition+1);

			while (NumberArray[8] != 2) { //2移到最右下
				rotate(7, ZeroPosition);
			}
			PrintArray();
			while (NumberArray[1] != 2) { //2移到2位置
				rotate(6, ZeroPosition);
			}
			PrintArray();
		}
		else if ((ZeroPosition == 3 || ZeroPosition == 6) && TwoPosition<3) {
			ZeroPosition = swap(ZeroPosition, ZeroPosition + 1);
			while (NumberArray[1] != 2) { //2移到2位置
				rotate(6, ZeroPosition);
			}
			PrintArray();
		}
		else if ((TwoPosition == 3 || TwoPosition == 6) && ZeroPosition<3) {
			
			ZeroPosition = swap(ZeroPosition, ZeroPosition + 3);
			while (NumberArray[8] != 2) { //2移到最右下
				rotate(7, ZeroPosition);
			}
			PrintArray();
			while (NumberArray[1] != 2) { //2移到2位置
				rotate(6, ZeroPosition);
			}
			PrintArray();
		}
		else if ((TwoPosition == 3 || TwoPosition == 6) && ZeroPosition>2) {

			if (NumberArray[8]==0) {
				ZeroPosition = swap(ZeroPosition, ZeroPosition - 3);
			}
			while (NumberArray[8] != 2) { //2移到最右下
				rotate(7, ZeroPosition);
			}
			PrintArray();
			while (NumberArray[1] != 2) { //2移到2位置
				rotate(6, ZeroPosition);
			}
			PrintArray();
		}
		else {
		
			cout << "!!!";
		}
	}
	PrintArray();
	//調整3
	if (ZeroPosition == 2)
		ZeroPosition = swap(ZeroPosition, 5);
	PrintArray();
	if (NumberArray[2] != 3) {
		int ThreePosition = GetNumberPosi(3);
		if (NumberArray[8] == 0) {
			ZeroPosition = swap(ZeroPosition, ZeroPosition-3);
			PrintArray();
		}
		while (NumberArray[8] != 3) { //3移到最右下
			rotate(7, ZeroPosition);
		}
		PrintArray();
		//移動0到中間
		if (ZeroPosition > 5)
			ZeroPosition = swap(ZeroPosition, ZeroPosition - 3);
		PrintArray();
		if (ZeroPosition == 3)
			ZeroPosition = swap(ZeroPosition, ZeroPosition + 1);
		PrintArray();
		if (ZeroPosition == 5)
			ZeroPosition = swap(ZeroPosition, ZeroPosition - 1);
		PrintArray();
		ZeroPosition = swap(ZeroPosition, ZeroPosition - 3);//0往上移
		PrintArray();
		while (NumberArray[5] != 2) { //2移到最右中
			rotate(2, ZeroPosition);
		}
		ZeroPosition = swap(ZeroPosition, ZeroPosition + 3);
		while (NumberArray[1] != 2) { 
			rotate(6, ZeroPosition);
			PrintArray();
		}
		PrintArray();


	}
	PrintArray();

	//調整4
	
	if (NumberArray[5] == 0) {
		ZeroPosition = swap(ZeroPosition, ZeroPosition + 3);
	}
	if (NumberArray[5] != 4) {
		
		int FourPosition = GetNumberPosi(4);

		while (NumberArray[5] != 4) { //4移到右中
			rotate(7, ZeroPosition);
		}		
	}
	PrintArray();

	//調整5

	if (NumberArray[8] == 0) {
		ZeroPosition = swap(ZeroPosition, ZeroPosition -1);
	}
	PrintArray();
	if (NumberArray[8] != 5) {
		
		while (NumberArray[6] != 5) { 
			rotate(3, ZeroPosition);
		}
		PrintArray();
		if (NumberArray[7] == 0) {
			ZeroPosition = swap(ZeroPosition, ZeroPosition - 3);
		}
		while (NumberArray[7] != 4) {
			rotate(4, ZeroPosition);
		}
		PrintArray();

		if (NumberArray[5] == 0) {
			ZeroPosition = swap(ZeroPosition, ZeroPosition - 1);
		}
		while (NumberArray[5] != 4) {
			rotate(7, ZeroPosition);
		}
	}
	PrintArray();

	//調整6


	if (ZeroPosition == 7) {
		ZeroPosition = swap(ZeroPosition, ZeroPosition - 3);
	}
	if (ZeroPosition == 3) {
		ZeroPosition = swap(ZeroPosition, ZeroPosition + 1);
	}
	if (ZeroPosition == 6) {
		ZeroPosition = swap(ZeroPosition, ZeroPosition - 3);
		ZeroPosition = swap(ZeroPosition, ZeroPosition + 1);
	}

	while (NumberArray[7] != 6) { 
		rotate(3, ZeroPosition);
	}
	

	PrintArray();




	
    return 0;
}

void Reset() {
	int index1 = 1;
	int index2 = 4;
	int count = 0;
	while (count!=100) { //換100次

		if (abs(index1 - index2) == 3 || (abs(index1 - index2) == 1 && (index1 / 3 == index2 / 3))) {
			index2 = swap(index1, index2);
			count++;			
		}
		index1 = rand() % 9;
	}
	PrintArray();
}

int GetNumberPosi(int number) {
	for (int i = 0;i<9; i++) {
		if (NumberArray[i] == number)
			return i;
	}
}
int GetBlock(int number) {
	int NumberPosi = GetNumberPosi(number);
	if (NumberPosi == 0|| NumberPosi == 1 || NumberPosi == 3)
		return 1;
	if (NumberPosi == 2 || NumberPosi == 4 || NumberPosi == 5)
		return 2;
	if (NumberPosi == 6 || NumberPosi == 7)
		return 3;
	if (NumberPosi == 8)
		return 4;
	
}

int swap(int index1,int index2) {

	if (index1 < 9 && index2 < 9 && index2 >= 0 && index2 >= 0) {	//檢查引數
		if (NumberArray[index1] == 0 || NumberArray[index2] == 0) { //檢查交換的是不是0
			if (abs(index1-index2)==3 || (abs(index1 - index2) == 1&&(index1 / 3== index2 / 3))) {//檢查交換位置	

				int temp = NumberArray[index1];
				NumberArray[index1] = NumberArray[index2];
				NumberArray[index2] = temp;		
				//PrintArray();
				return NumberArray[index2] == 0 ? index2: index1;
			}
			else 
				return -1;			
		}
		else		
			return -1;		
	}
	else
		return -1;
}

void PrintArray() {
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0)
			cout << endl;	
		cout << NumberArray[i]<<"\t";					
	}
	cout << endl;
}

void rotate(int choice,int ZeroPosi) {
		
	int StartPosition=0;
	int IndexList[4];
	switch (choice)
	{
		case 1:
		{
			int IndexList1[4] = { 0,1,4,3 };
			for (int i = 0; i < 4; i++) {
				if (IndexList1[i] == ZeroPosi)
					StartPosition = i;
			}
			for (int i = 0; i < 4; i++) 
				swap(IndexList1[(StartPosition + i) % 4], IndexList1[(StartPosition + i + 1) % 4]);
			break;
		}
		case 2:
		{

			int IndexList2[4] = { 1,2,5,4 };
			for (int i = 0; i < 4; i++) {
				if (IndexList2[i] == ZeroPosi)
					StartPosition = i;
			}

			for (int i = 0; i < 4; i++)
				swap(IndexList2[(StartPosition + i) % 4], IndexList2[(StartPosition + i + 1) % 4]);
			break;
		}
		case 3:
		{
			int IndexList3[4] = { 3,4,7,6 };
			for (int i = 0; i < 4; i++) {
				if (IndexList3[i] == ZeroPosi)
					StartPosition = i;
			}

			for (int i = 0; i < 4; i++)
				 swap(IndexList3[(StartPosition + i) % 4], IndexList3[(StartPosition + i + 1) % 4]);
			break;
		}
		case 4:
		{
			int IndexList4[4] = { 4,5,8,7 };
			for (int i = 0; i < 4; i++) {
				if (IndexList4[i] == ZeroPosi)
					StartPosition = i;
			}

			for (int i = 0; i < 4; i++)
				swap(IndexList4[(StartPosition + i) % 4], IndexList4[(StartPosition + i + 1) % 4]);
			break;
		}
		case 5:
		{
			int IndexList5[8] = { 0,1,2,5,8,7,6,3 };
			for (int i = 0; i < 8; i++) {
				if (IndexList5[i] == ZeroPosi)
					StartPosition = i;
			}

			for (int i = 0; i < 8; i++)
				swap(IndexList5[(StartPosition + i) % 8], IndexList5[(StartPosition + i + 1) % 8]);
			break;
		}
		case 6:
		{
			int IndexList6[6] = { 1,2,5,8,7,4 };
			for (int i = 0; i < 6; i++) {
				if (IndexList6[i] == ZeroPosi)
					StartPosition = i;
			}

			for (int i = 0; i < 6; i++)
				swap(IndexList6[(StartPosition + i) % 6], IndexList6[(StartPosition + i + 1) % 6]);
			break;
		}
		case 7:
		{
			int IndexList7[6] = { 3,4,5,8,7,6 };
			for (int i = 0; i < 6; i++) {
				if (IndexList7[i] == ZeroPosi)
					StartPosition = i;
			}

			for (int i = 0; i < 6; i++)
				swap(IndexList7[(StartPosition + i) % 6], IndexList7[(StartPosition + i + 1) % 6]);
			break;
		}
	}

}
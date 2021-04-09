#pragma once
#ifndef QUEUESTACKRINGBUFFER
#define QUEUESTACKRINGBUFFER

/// @brief �������
struct Queue
{
	int* Data;
	int Length;
	int Size;
	int Head;
	int Tail;
};
/// @brief				�������� �������
/// @param queueBuffer	�����, ��� ������� ������������ �������� 
void CreateQueue(Queue* queueBuffer);

/// @brief				����������� � ��������
/// @param queueBuffer	�����, ��� ������� ������������ ��������  
/// @param data			������
void Enqueue(Queue* queueBuffer,int data);

/// @brief				��������
/// @param queueBuffer	�����, ��� ������� ������������ ��������  
/// @return				������ ��������
int Dequeue(Queue* queueBuffer);

/// @brief				�������� ������
/// @param queueBuffer	�����, ��� ������� ������������ ��������  
void RemoveQueue(Queue* queueBuffer);
#endif // QUEUESTACKRINGBUFFER
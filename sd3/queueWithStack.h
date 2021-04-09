#pragma once
#ifndef H_QUEUE_WITH_STACK
#define H_QUEUE_WITH_STACK

#include "stack.h"

/// @breif			������� �� ������ ���� ������
struct QueueWithStack
{
	Stack* MainStack;
	Stack* SecendoryStack;	/// @todo SecEndory ???
	int Size;
};

/// @breif			������������� �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
void Init(QueueWithStack* queue);

/// @breif			���������� �������� � �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
/// @param value	�������� ������ ��������	
/// 
/// @retval true	��� �������� ����������
/// @retval false	������ ��������� ������
/// 
/// @return		��������� ����������
bool Enqueue(QueueWithStack* queue, int value);

/// @breif			�������� �������� �� �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
/// @param value	�������� ���������� ��������	
/// 
/// @retval true	��� �������� ����������
/// @retval false	��� ���������� ��������� � ������� 
/// 
/// @return			��������� ����������
bool Dequeue(QueueWithStack* queue, int& value);

/// @breif			�������� �������� �������� � ����������� �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
/// @param value	�������� ��������	
/// @param position	������� ������� ��������
/// 
/// @retval true	��� �������� ����������
/// @retval false	����� �� ������� �������
/// 
/// @return			��������� ����������
bool GetValue(QueueWithStack* queue, int& value, int position);

/// @breif			�������� �������� �������� � ����������� �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
void Clear(QueueWithStack* queue);
#endif // !H_QUEUE_WITH_STACK

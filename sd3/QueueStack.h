#pragma once
#ifndef H_QUEUESTACK
#define H_QUEUESTACK

#include "stack.h"

/// @breif			������� �� ������ ���� ������
struct QueueStack
{
	Stack* firstStack;	/// @todo � ������� �����
	Stack* secondStack;
	int Size;
};

/// @breif			������������� �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
void Init(QueueStack* QueueStack);

/// @breif			���������� �������� � �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
/// @param value	�������� ������ ��������	
/// 
/// @retval true	��� �������� ����������
/// @retval false	������ ��������� ������
/// 
/// @return		��������� ����������
bool Enqueue(QueueStack* QueueStack, int value);

/// @breif �������� �������� �� �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
/// @param value	�������� ���������� ��������	
/// 
/// @retval true	��� �������� ����������
/// @retval false	��� ���������� ��������� � ������� 
/// 
/// @return	��������� ����������
bool Dequeue(QueueStack* QueueStack);

/// @breif			�������� �������� �������� � ����������� �������
/// 
/// @param queue	�������, ��� ������� ������������ �������� 
void Clear(QueueStack* QueueStack);
#endif // !H_QUEUE_WITH_STACK

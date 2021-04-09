#pragma once
#ifndef STACK
#define STACK

/// @brief ����
struct Stack
{
	int BufferCapacity = 8;
	int* Buffer ;
	int Top = 1;
};

/// @brief	�������� �����
///
/// @param stack	����, ��� ������� ������������ �������� 
void CreateStack(Stack* stack);

/// @brief	��������� ��������
///
/// @param stack	����, ��� ������� ������������ �������� 
/// @param data		������
void Push(Stack* stack, int data);

/// @brief	�������� ��� ��������
///
/// @param stack	����, ��� ������� ������������ �������� 
/// @return			���������� ��������
int StackTop(Stack* stack);

/// @brief	�������� ��������
///
/// @param stack	����, ��� ������� ������������ ��������  
/// @return			���������� ��������
bool Pop(Stack* stack, int& value);

/// @brief	�������� 
///
/// @param stack	����, ��� ������� ������������ ��������
void �learStack(Stack* stack);
#endif	// ifndef STACK
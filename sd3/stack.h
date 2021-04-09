#pragma once
#ifndef STACK
#define STACK

/// @brief стек
struct Stack
{
	int BufferCapacity = 8;
	int* Buffer ;
	int Top = 1;
};

/// @brief	создание стека
///
/// @param stack	стек, над которым производится действие 
void CreateStack(Stack* stack);

/// @brief	добвление элемента
///
/// @param stack	стек, над которым производится действие 
/// @param data		данные
void Push(Stack* stack, int data);

/// @brief	показать без удаления
///
/// @param stack	стек, над которым производится действие 
/// @return			возращение значения
int StackTop(Stack* stack);

/// @brief	удаление элемента
///
/// @param stack	стек, над которым производится действие  
/// @return			возращение значения
bool Pop(Stack* stack, int& value);

/// @brief	отчистка 
///
/// @param stack	стек, над которым производится действие
void СlearStack(Stack* stack);
#endif	// ifndef STACK
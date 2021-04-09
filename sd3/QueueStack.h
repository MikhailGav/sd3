#pragma once
#ifndef H_QUEUESTACK
#define H_QUEUESTACK

#include "stack.h"

/// @breif			Очередь на основе двух стеков
struct QueueStack
{
	Stack* firstStack;	/// @todo С большой буквы
	Stack* secondStack;
	int Size;
};

/// @breif			Инициализация очереди
/// 
/// @param queue	Очередь, над которым производится действие 
void Init(QueueStack* QueueStack);

/// @breif			Добавление элемента в очередь
/// 
/// @param queue	Очередь, над которым производится действие 
/// @param value	Значение нового элемента	
/// 
/// @retval true	При успешном выполнении
/// @retval false	Ошибка выделения памяти
/// 
/// @return		Результат выполнения
bool Enqueue(QueueStack* QueueStack, int value);

/// @breif Удаление элемента из очереди
/// 
/// @param queue	Очередь, над которым производится действие 
/// @param value	Значение удаленного элемента	
/// 
/// @retval true	При успешном выполнении
/// @retval false	При отсутствие элементов в очереди 
/// 
/// @return	Результат выполнения
bool Dequeue(QueueStack* QueueStack);

/// @breif			Получить значение элемента в определнной позиции
/// 
/// @param queue	Очередь, над которым производится действие 
void Clear(QueueStack* QueueStack);
#endif // !H_QUEUE_WITH_STACK

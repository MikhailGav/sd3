#pragma once
#ifndef H_QUEUE_WITH_STACK
#define H_QUEUE_WITH_STACK

#include "stack.h"

/// @breif			Очередь на основе двух стеков
struct QueueWithStack
{
	Stack* MainStack;
	Stack* SecendoryStack;	/// @todo SecEndory ???
	int Size;
};

/// @breif			Инициализация очереди
/// 
/// @param queue	Очередь, над которым производится действие 
void Init(QueueWithStack* queue);

/// @breif			Добавление элемента в очередь
/// 
/// @param queue	Очередь, над которым производится действие 
/// @param value	Значение нового элемента	
/// 
/// @retval true	При успешном выполнении
/// @retval false	Ошибка выделения памяти
/// 
/// @return		Результат выполнения
bool Enqueue(QueueWithStack* queue, int value);

/// @breif			Удаление элемента из очереди
/// 
/// @param queue	Очередь, над которым производится действие 
/// @param value	Значение удаленного элемента	
/// 
/// @retval true	При успешном выполнении
/// @retval false	При отсутствие элементов в очереди 
/// 
/// @return			Результат выполнения
bool Dequeue(QueueWithStack* queue, int& value);

/// @breif			Получить значение элемента в определнной позиции
/// 
/// @param queue	Очередь, над которым производится действие 
/// @param value	Значение элемента	
/// @param position	Позиция нужного элемента
/// 
/// @retval true	При успешном выполнении
/// @retval false	Выход за пределы очереди
/// 
/// @return			Результат выполнения
bool GetValue(QueueWithStack* queue, int& value, int position);

/// @breif			Получить значение элемента в определнной позиции
/// 
/// @param queue	Очередь, над которым производится действие 
void Clear(QueueWithStack* queue);
#endif // !H_QUEUE_WITH_STACK

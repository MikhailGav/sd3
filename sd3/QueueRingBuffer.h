#pragma once
#ifndef QUEUESTACKRINGBUFFER
#define QUEUESTACKRINGBUFFER

/// @brief очередь
struct Queue
{
	int* Data;
	int Length;
	int Size;
	int Head;
	int Tail;
};
/// @brief				создание очереди
/// @param queueBuffer	буфер, над которым производится действие 
void CreateQueue(Queue* queueBuffer);

/// @brief				добавленеие в очереедь
/// @param queueBuffer	буфер, над которым производится действия  
/// @param data			данные
void Enqueue(Queue* queueBuffer,int data);

/// @brief				удаление
/// @param queueBuffer	буфер, над которым производится действия  
/// @return				возрат значения
int Dequeue(Queue* queueBuffer);

/// @brief				отчсичка памяти
/// @param queueBuffer	буфер, над которым производится действия  
void RemoveQueue(Queue* queueBuffer);
#endif // QUEUESTACKRINGBUFFER
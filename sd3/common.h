#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#include "RingBuffer.h"
#include "stack.h"
#include "QueueRingBuffer.h"
#include "QueueStack.h"

#include <string.h>
/// @brief главное меню
void ShowMainMenu();

/// @brief меню для стека
void ShowMenuStack();

/// @brief меню для кольцевого буфера
void ShowMenuRingBuffer();

/// @brief меню для очереди
void ShowMenuQueue();

/// @brief проверка на корректный ввод
/// @return	результат проверки
int GetInteger();

/// @brief Функция для работы с кольцевом буфером
///
/// @param ringbuffer 		буфер, над которым производится действие 
/// @param isOccupiedSpace	занятое место 
void ServeRingBuffer(Ringbuffer* ringbuffer, bool isOccupiedSpace);

/// @brief функция для работы с стеком
/// @param stack	стек, над которым производится действие 
void  ServeStack(Stack* stack);

/// @brief функция для работы с очередью на двух стеках
/// @param queueSack	стек, над которым производится действие 
void ServeQueueStack(QueueStack* queueSack);

/// @brief функция для работы с очередью на кольцевом буфере
/// @param queueBuffer			буфер, над которым производится действие 
/// @param isCreateRingBuffer	переменная на проерку создание буфера
void ServeQueueBuffer(Queue* queueBuffer, bool isCreateRingBuffer);

#endif	// ifndef __COMMON_H__
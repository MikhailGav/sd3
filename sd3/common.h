#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#include "RingBuffer.h"
#include "stack.h"
#include "QueueRingBuffer.h"
#include "QueueStack.h"

#include <string.h>
/// @brief ������� ����
void ShowMainMenu();

/// @brief ���� ��� �����
void ShowMenuStack();

/// @brief ���� ��� ���������� ������
void ShowMenuRingBuffer();

/// @brief ���� ��� �������
void ShowMenuQueue();

/// @brief �������� �� ���������� ����
/// @return	��������� ��������
int GetInteger();

/// @brief ������� ��� ������ � ��������� �������
///
/// @param ringbuffer 		�����, ��� ������� ������������ �������� 
/// @param isOccupiedSpace	������� ����� 
void ServeRingBuffer(Ringbuffer* ringbuffer, bool isOccupiedSpace);

/// @brief ������� ��� ������ � ������
/// @param stack	����, ��� ������� ������������ �������� 
void  ServeStack(Stack* stack);

/// @brief ������� ��� ������ � �������� �� ���� ������
/// @param queueSack	����, ��� ������� ������������ �������� 
void ServeQueueStack(QueueStack* queueSack);

/// @brief ������� ��� ������ � �������� �� ��������� ������
/// @param queueBuffer			�����, ��� ������� ������������ �������� 
/// @param isCreateRingBuffer	���������� �� ������� �������� ������
void ServeQueueBuffer(Queue* queueBuffer, bool isCreateRingBuffer);

#endif	// ifndef __COMMON_H__
#include "common.h"
#include "RingBuffer.h"

#include <iostream>
using namespace std;

void ShowMainMenu()
{
	system("cls");
	cout << "1) ����\n";
	cout << "2) ��������� �����\n";
	cout << "3) ������� �� ���� �����\n";
    cout << "4) ������� �� ���� ���������� ������\n";
	cout << "0) ����� �� ���������\n";
}

void ShowMenuStack()
{
    system("cls");
	cout << "\t1) �������� ������� � ���� " << endl;
	cout << "\t2) ��������� �������� �������� ����� ��� ��� ��������" << endl;
	cout << "\t3) �������� �������� �� �����" << endl;
	cout << "\t0) ��������� � ������� ����" << endl;
}

void ShowMenuRingBuffer()
{
    system("cls");
	cout << " \t1) ������� ���������� ��������� �����" << endl;
	cout << "\t2) ������� ���������� ������� ����� " << endl;
	cout << "\t3) ������� ���������� �������� � �����" << endl;
	cout << "\t4) �������, ��������� ������� �� ������" << endl;
}

void ShowMenuQueue()
{
    system("cls");
    cout << "1) �������� ������� � �������\n";
    cout << "2) �������� ������� �� �������\n";
    cout << "0) ����� � ������� ����\n";
}

int GetInteger()
{
    int input;
    bool isValid = false;   
    while (!isValid)
    {
        cin >> input;
        if (cin.fail())
        {
            cout << "������� ���������� ������" << endl;
            cout << "������� ����� " << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            isValid = true;
        }
    }
    return input;
}


enum MenuRingBuffer
{
    FreePlace = 1,
    OccupiedPlace,
    AddElem,
    GetElem,
    Exit = 0 
};


void ServeRingBuffer(Ringbuffer* ringbuffer, bool isOccupiedSpace)
{
    int countRingBuffer; /// @todo ?
    do
    {
        ShowMenuRingBuffer();
        cout << "\t�������� ����� ���� ";
        countRingBuffer = GetInteger();
        switch (countRingBuffer)
        {
            case MenuRingBuffer::FreePlace:
            {
                cout << "\t" << GetFreeSpace(ringbuffer) << endl;
                system("pause");
                break;
            }
            case MenuRingBuffer::OccupiedPlace:
            {
                if (isOccupiedSpace)
                {
                    cout << "0";
                    system("pause");
                    break;
                }
                cout << "\t" << GetOccupiedSpace(ringbuffer) << endl;
                system("pause");
                break;
            }
            case MenuRingBuffer::AddElem:
            {
                int value;
                cout << "\t������ ��������  ";
                value = GetInteger();
                AddRingBuffer(ringbuffer, value);
                system("pause");
                break;
            }
            case MenuRingBuffer::GetElem:
            {
                if (ringbuffer->OccupiedSpace < 0)
                {
                    cout << "������ ����� ����" << endl;
                    system("pause");
                    break;
                }
                cout << "\t" << Get(ringbuffer, isOccupiedSpace) << endl;
                system("pause");
                break;
            }
            default:
            {
                system("cls");
                break;
            }
        }
    } while (countRingBuffer != 0);
}

enum MenuStack
{
    AddStack    = 1,
    StackWithTop,
    Remove,
};

void ServeStack(Stack* stack)
{
    int countStack;
    do
    {
        ShowMenuStack();
        cout << "\t�������� ����� ���� ";
        countStack = GetInteger();
        switch (countStack)
        {
            case MenuStack::AddStack:
            {
                int Data;
                cout << "\t������� ������� ����� ";
                Data = GetInteger();
                Push( stack, Data);
                system("pause");
                break;
            }
            case MenuStack::StackWithTop:
            {
                if (StackTop(stack) == 1)
                {
                    cout << "\t������"<<endl;
                    system("pause");
                    break;
                }
                cout << "\t" << StackTop(stack) << endl;
                system("pause");
                break;
            }
            case MenuStack::Remove:
            {
                int value = 1000;
                if (stack->Top <= 1)
                {
                    cout << "\t������"<<endl;
                    system("pause");
                    break;
                }    
                Pop(stack, value);
                cout << "\t������� ������ " << value << endl;
                system("pause");
                break;
            }
            default:
            {
                system("cls");
                break;
            }
        }
    } while (countStack != 0);
}

enum MenuQueueWithBuffer
{
    AddQueue    =1,
    RemoveElementQueue,
};

void ServeQueueBuffer(Queue* queueBuffer, bool isOccupiedSpace)
{
    int countQueueBuffer;
    do
    {
        ShowMenuQueue();
        countQueueBuffer = GetInteger();
        switch (countQueueBuffer)
        {
            case MenuQueueWithBuffer::AddQueue:
            { 
                cout << "\t������� ������ ";
                int value;
                value = GetInteger();
                Enqueue(queueBuffer, value);
                cout << "\t������� ��������"<<endl;
                system("pause");
                break;
            }
            case MenuQueueWithBuffer::RemoveElementQueue:
            {
                if (queueBuffer->Length <= 0)
                {
                    cout << "\t������� �����" << endl;
                    system("pause");
                    break;
                }
                int temp = 0;
                temp = Dequeue(queueBuffer);
                cout << temp << endl;
                system("pause");
                break;
            }
            default:
            {
                system("cls");
                break;
            }
        }
    } while (countQueueBuffer != 0);
}

enum MenuQueueStack
{
    Add     = 1,
    RemoveQueueStack
};

void ServeQueueStack(QueueStack* queueSack) 
{
    int countQueueStack;
    do
    {
        ShowMenuQueue();
        countQueueStack = GetInteger();
        switch (countQueueStack)
        {
            case MenuQueueStack::Add:
            {
                int value = GetInteger();

                if (!Enqueue(queueSack, value))
                {
                    cout << "������";
                }
                break;
            }
            case MenuQueueStack::RemoveQueueStack:
            {
                int value;
                if (!Dequeue(queueSack))
                {
                    cout << "������"<<endl;
                    system("pause");
                    break;
                }
                break;
            }
        }
        cout << endl;
    } while (countQueueStack != 0);
   
}


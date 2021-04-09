#include "common.h"
#include "RingBuffer.h"

#include <iostream>
using namespace std;

void ShowMainMenu()
{
	system("cls");
	cout << "1) Стэк\n";
	cout << "2) Кольцевой буфер\n";
	cout << "3) Очередь на базе стэка\n";
    cout << "4) Очередь на базе кольцевого буфера\n";
	cout << "0) Выйти из программы\n";
}

void ShowMenuStack()
{
    system("cls");
	cout << "\t1) добавить элемент в стек " << endl;
	cout << "\t2) Получение верхнего элемента стека без его удаления" << endl;
	cout << "\t3) Удаление элемента из стека" << endl;
	cout << "\t0) вернуться в главное меню" << endl;
}

void ShowMenuRingBuffer()
{
    system("cls");
	cout << " \t1) Функция возвращает свободное место" << endl;
	cout << "\t2) Функция возвращает занятое место " << endl;
	cout << "\t3) Функция добавления элемента в буфер" << endl;
	cout << "\t4) Функция, достающая элемент из буфера" << endl;
}

void ShowMenuQueue()
{
    system("cls");
    cout << "1) Добавить элемент в очередь\n";
    cout << "2) Вытащить элемент из очереди\n";
    cout << "0) Выйти в главное меню\n";
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
            cout << "Введите пожалуйста заново" << endl;
            cout << "Введите число " << endl;
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
        cout << "\tвыберите номер меню ";
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
                cout << "\tведите значение  ";
                value = GetInteger();
                AddRingBuffer(ringbuffer, value);
                system("pause");
                break;
            }
            case MenuRingBuffer::GetElem:
            {
                if (ringbuffer->OccupiedSpace < 0)
                {
                    cout << "ошибка буфер пуст" << endl;
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
        cout << "\tвыберите номер меню ";
        countStack = GetInteger();
        switch (countStack)
        {
            case MenuStack::AddStack:
            {
                int Data;
                cout << "\tведдите элемент стека ";
                Data = GetInteger();
                Push( stack, Data);
                system("pause");
                break;
            }
            case MenuStack::StackWithTop:
            {
                if (StackTop(stack) == 1)
                {
                    cout << "\tошибка"<<endl;
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
                    cout << "\tошибка"<<endl;
                    system("pause");
                    break;
                }    
                Pop(stack, value);
                cout << "\tэлемент удален " << value << endl;
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
                cout << "\tвведите элмент ";
                int value;
                value = GetInteger();
                Enqueue(queueBuffer, value);
                cout << "\tэлемент вставлен"<<endl;
                system("pause");
                break;
            }
            case MenuQueueWithBuffer::RemoveElementQueue:
            {
                if (queueBuffer->Length <= 0)
                {
                    cout << "\tочередь пуста" << endl;
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
                    cout << "ошибка";
                }
                break;
            }
            case MenuQueueStack::RemoveQueueStack:
            {
                int value;
                if (!Dequeue(queueSack))
                {
                    cout << "ошибка"<<endl;
                    system("pause");
                    break;
                }
                break;
            }
        }
        cout << endl;
    } while (countQueueStack != 0);
   
}


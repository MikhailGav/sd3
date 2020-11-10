#include "stack.h"
#include "RingBuffer.h"
#include "Security.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Stack* stack = new Stack;
    Ringbuffer* ringbuffer = new Ringbuffer;
    int result = 0;
    bool isCreateStack = true;


    do
    {
        cout << "=============================================================" << endl;
        cout << "1 стек" << endl;
        cout << "2 курговой буфер" << endl;
        cout << "=============================================================" << endl;
       // cout << endl;
        cout << "выберите номер меню ";
        result = Security(0, 9, "  ");
        switch (result)
        {
            case 1:
            {
                cout << endl;
                cout <<" \t1) создать стек" << endl;
                cout << "\t2) добавить элемент в стек " << endl;
                cout << "\t3) Получение верхнего элемента стека без его удаления"<<endl;
                cout << "\t4) Удаление элемента из стека" << endl;
                cout << "\t5) очистка памяти стека " << endl;
                int count = 0;
                cout << "\tвыберите номер меню ";
                count = Security(0, 5, "  ");
                switch (count)
                {
                     case 1:
                     {
                         if (isCreateStack != true)
                         {
                             cout << "\tcтек уже инциализирован "<<endl;
                             system("pause");
                             break;
                         }
                         int data;
                         cout << "\tведдите элемент стека ";
                         stack->top = 0;
                         cin >> data;
                         CreateStack(stack, data);
                         cout << "\tстек создан" << endl;
                         isCreateStack = false;
                         system("pause");
                         break;
                     }
                     case 2:
                     {
                         if (isCreateStack)
                         {
                             cout <<"\tошибка!!! стек не создан" <<endl;
                             system("pause");
                             break;
                         }
                         int data;
                         cout << "\tведдите элемент стека ";
                         cin >> data;
                         Push(stack, data);
                         cout <<"\tэлемент вставлен"<<endl;
                         system("pause");
                         break;
                     }
                     case 3:
                     {
                         if (isCreateStack)
                         {
                             cout << "\tошибка!!! стек не создан" << endl;
                             system("pause");
                             break;
                         }
                         cout<<"\t"<<StackTop(stack)<<endl;
                         system("pause");
                         break;
                     }
                     case 4:
                     {
                         if (isCreateStack)
                         {
                             cout << "\tошибка!!! стек не создан" << endl;
                             system("pause");
                             break;
                         }
                         Remove(stack);
                         cout << "элемент удален"<<endl;
                         system("pause");
                         break;
                     }
                     case 5:
                     {
                         if (isCreateStack)
                         {
                             cout << "\tошибка!!! стек не создан" << endl;
                             system("pause");
                             break;
                         }
                         СlearStack(stack, isCreateStack);
                         if (stack->top == 0)
                         {
                             isCreateStack = true;
                         }
                         system("pause");
                         break;
                     }
                }
                break;
            }
            case 2:
            {
              
                cout << endl;
                cout << " \t1) Функция возвращает свободное место" << endl;
                cout << "\t2) Функция возвращает занятое место " << endl;
                cout << "\t3) Функция добавления элемента в буфер" << endl;
                cout << "\t4) Функция, достающая элемент из буфера" << endl;
                int count = 0;
                cout << "\tвыберите номер меню ";
                count = Security(0, 5, "  ");
                switch (count)
                {
                    case 1:
                    {
                        cout << "\t" << GetFreeSpace(ringbuffer)<<endl;
                        system("pause");
                        break;
                    }
                    case 2:
                    {
                        cout << "\t" << GetOccupiedSpace(ringbuffer)<<endl;
                        system("pause");
                        break;
                    }
                    case 3:
                    {
                        int value;
                        cout <<"\tведите значение" ;
                        cin >> value;
                        Add(ringbuffer, value);
                        system("pause");
                        break;
                    }
                    case 4:
                    {
                        cout<< "\t" <<Get(ringbuffer)<<endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }
        }
        if (result > 0)
        {
            system("cls");
        }
    } while (result != 0);
   
    

}

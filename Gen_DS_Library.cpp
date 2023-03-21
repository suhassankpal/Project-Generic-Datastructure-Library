//=========================================================================================================================
//
// ********************This Program Contains Generic Code for all types of datastructure as follow************************
//
//=========================================================================================================================
//
//                1. Singly linear linked list
//                2. Singly circular linked list
//                3. Doubly linked list
//                4. Doubly circular linked list
//                5. Stack Implementation using linked list
//                6. Queue Implementation using linked list
//
//=========================================================================================================================

#include <iostream>
using namespace std;

//======================================================================================
//
// THIS IS GENERIC LINKED LIST OF TYPE T
//
//======================================================================================

template <class T> // we create a single  class to work with different data types using template<T>.
struct nodeS
{
    T data;
    struct nodeS *next;
};

//=======================================================================================
//
// THIS IS GENERIC Doubly linkedList OF TYPE T
//
//=======================================================================================

template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

//=========================================================================================
//
// Class Name  :  SinglyLL (Singly Linked_List)
// Description : This Class represents singly linear linked list
//
//=========================================================================================

template <class T>
class SinglyLL
{
private: // here we use private Access Specifier
    struct nodeS<T> *Head;
    int Count;

public: // here we use public Access Specifier
    SinglyLL();

    void InsertFirst(T No);
    void InsertLast(T No);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T No, int pos);
    void DeleteAtPos(int pos);

    void Display();
    int CountNode();

    int SearchFirstOccurance(T No);
    int SearchLastOccurance(T No);
    T AdditionOfAllElement();
    T LargestElement();
    T SmallestElement();
};

//==================================================================================================
//
// Class Name  :  DoublyLL(Doubly Linked_List)
// Description : This Class represents Doubly linear linked list
//
//==================================================================================================
template <class T>
class DoublyLL
{
private:
    struct nodeD<T> *Head;
    int Count;

public:
    DoublyLL();

    void InsertFirst(T No);
    void InsertLast(T No);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T No, int pos);
    void DeleteAtPos(int pos);

    void Display();
    int CountNode();

    int SearchFirstOccurance(T No);
    int SearchLastOccurance(T No);
    T AdditionOfAllElement();
    T LargestElement();
    T SmallestElement();
};

//=======================================================================================
//
//
//  Class Name  :  SinglyCL (Singly Circular Linked-List)
//  Description :  This Class represents Generic Singly Circular linked list
//
//
//=======================================================================================
template <class T>
class SinglyCL
{
private:
    struct nodeS<T> *Head;
    struct nodeS<T> *Tail;

    int Count;

public:
    SinglyCL();

    void InsertFirst(T No);
    void InsertLast(T No);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T No, int pos);
    void DeleteAtPos(int pos);

    void Display();
    int CountNode();
};

//==================================================================================================
//
// Class Name  :  DoublyCL (Doubly Circular Linked_list)
// Description : This Class represents Doubly Circular linked list
//
//==================================================================================================

template <class T>
class DoublyCL
{
private:
    struct nodeD<T> *Head;
    struct nodeD<T> *Tail;
    int Count;

public:
    DoublyCL();
    void InsertFirst(T No);
    void InsertLast(T No);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T No, int iPos);
    void DeleteAtPos(int iPos);

    void Display();
    int CountNode();
};

//====================================================================================================
//
//
//  Class Name  :  Stack
//  Description :  This Class represents Generic Stack implementation by using linked list
//
//
//====================================================================================================

template <class T>
class Stack
{
private:
    struct nodeS<T> *Head;
    int Count;

public:
    Stack();
    bool isStackEmpty();
    void Push(T No);
    T Pop();
    void Display();
    int CountNode();
};

//====================================================================================================
//
//  Class Name  :  Queue
//  Description :  This Class represents Generic Queue implementation by using linked list
//
//====================================================================================================

template <class T>
class Queue
{
private:
    struct nodeS<T> *Head;
    int Count;

public:
    Queue();
    bool isQueueEmpty();
    void Enqueue(T No);
    T Dequeue();
    void Display();
    int CountNode();
};

//=========================================================================
//
//
// Class Name       :   SinglyLL
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class SinglyLL
//
// Returns          :   NONE
//
//
//=========================================================================

template <class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

//=======================================================================================
//
//
// Function Name    :   InsertFirst()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   NONE
//
//
//=======================================================================================

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }

    Count++;
}

//============================================================================
//
//
// Function Name    :   InsertLast()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertLast Function Add New Node At End Of LinkedList
//
// Returns          :   NONE
//
//
//============================================================================

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct nodeS<T> *Temp = Head;

        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = newn;
    }

    Count++;
}

//================================================================================================
//
//
// Function Name    :   DeleteFirst()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList
//
// Returns          :   NONE
//
//
//================================================================================================

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (Head->next == NULL)
    {
        Head = NULL;
    }
    else
    {
        struct nodeS<T> *Temp = Head;

        Head = Temp->next; // Head = Head->next;
        delete (Temp);
    }

    Count--;
}

//=========================================================================================
//
//
// Function Name    :   DeleteLast()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   DeleteLast Function Remove The Node At End Of The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================================

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (Head->next == NULL)
    {
        Head = NULL;
    }
    else
    {
        struct nodeS<T> *Temp = Head;

        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }

        delete (Temp->next);
        Temp->next = NULL;
    }

    Count--;
}

//======================================================================================================
//
//
// Function Name    :   InsertAtPos()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No, Generic Pos
// Description      :   Insert At Position Function Add New Node At Given Position In The LinkedList
//
// Returns          :   NONE
//
//
//=======================================================================================================

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int pos)
{
    if ((pos < 1) || pos > (Count + 1))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == (Count + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct nodeS<T> *newn = new struct nodeS<T>;

        newn->data = No;
        newn->next = NULL;

        struct nodeS<T> *Temp = Head;
        int i = 1;

        while (i < (pos - 1))
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        Temp->next = newn;

        Count++;
    }
}

//==========================================================================================================
//
//
// Function Name    :   DeleteAtPos()
// Function Date    :   27 Dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic Pos
// Description      :   Delete At Position Function Remove Existing Node from given Position In The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================================================

template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    if ((pos < 1) || pos > Count)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == (Count + 1))
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> *Temp1 = Head;
        int i = 1;

        while (i < (pos - 1))
        {
            Temp1 = Temp1->next;
            i++;
        }

        struct nodeS<T> *Temp2 = Temp1->next;

        Temp1->next = Temp2->next;

        delete (Temp2);

        Count--;
    }
}

//============================================================================
//
//
// Function Name    :   Display()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Display Function Display all The Nodes In LinkedList
//
// Returns          :   NONE
//
//
//=============================================================================

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeS<T> *Temp = Head;

    while (Temp != NULL)
    {
        cout << "|" << Temp->data << "|->";
        Temp = Temp->next;
    }

    cout << "NULL" << endl;
}

//================================================================================================
//
//
// Function Name    :   Count()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Count Function Count Number Of Nodes In LinkedList
//
// Returns          :   Return Number Of Nodes In LinkedList
//
//================================================================================================

template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

//=======================================================================================
//
//
// Function Name    :   SearchFirstOccurance()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   integer
//
//
//=======================================================================================

template <class T>
int SinglyLL<T>::SearchFirstOccurance(T No)
{
    int ipos = 0;
    int iCnt = 1;

    struct nodeS<T> *Temp = Head;

    while (Temp != NULL)
    {
        if (Temp->data == No)
        {
            ipos = iCnt;
            break;
        }
        Temp = Temp->next;
        iCnt++;
    }

    return ipos;
}

//=======================================================================================
//
//
// Function Name    :   SearchLastOccurance()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   integer
//
//
//=======================================================================================

template <class T>
int SinglyLL<T>::SearchLastOccurance(T No)
{
    int ipos = 0;
    int iCnt = 1;

    struct nodeS<T> *Temp = Head;

    while (Temp != NULL)
    {
        if (Temp->data == No)
        {
            ipos = iCnt;
        }

        Temp = Temp->next;
        iCnt++;
    }

    return ipos;
}

//=======================================================================================
//
//
// Function Name    :   AdditionOfAllElement()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   Generic No
//
//
//=======================================================================================

template <class T>
T SinglyLL<T>::AdditionOfAllElement()
{
    T Sum = 0;

    struct nodeS<T> *Temp = Head;

    while (Temp != NULL)
    {
        Sum = Sum + Temp->data;

        Temp = Temp->next;
    }

    return Sum;
}

//=======================================================================================
//
//
// Function Name    :   LargestElement()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   Generic No
//
//
//=======================================================================================

template <class T>
T SinglyLL<T>::LargestElement()
{
    struct nodeS<T> *Temp = Head;
    T Max = Temp->data;

    while (Temp != NULL)
    {
        if (Max < Temp->data)
        {
            Max = Temp->data;
        }

        Temp = Temp->next;
    }

    return Max;
}

//=======================================================================================
//
//
// Function Name    :   SmallestElement()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   Generic No
//
//
//=======================================================================================

template <class T>
T SinglyLL<T>::SmallestElement()
{
    struct nodeS<T> *Temp = Head;
    T Min = Temp->data;

    while (Temp != NULL)
    {
        if (Min > Temp->data)
        {
            Min = Temp->data;
        }

        Temp = Temp->next;
    }

    return Min;
}

//=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================

template <class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count = 0;
}

//=======================================================================================
//
//
// Function Name    :   InsertFirst()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   NONE
//
//
//=======================================================================================

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        newn->next->prev = newn;
        Head = newn;
    }

    Count++;
}

//============================================================================
//
//
// Function Name    :   InsertLast()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertLast Function Add New Node At End Of LinkedList
//
// Returns          :   NONE
//
//
//============================================================================

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct nodeD<T> *Temp = Head;

        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = newn;
        newn->prev = Temp;
    }

    Count++;
}

//================================================================================================
//
//
// Function Name    :   DeleteFirst()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList
//
// Returns          :   NONE
//
//
//================================================================================================

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (Head->next == NULL)
    {
        delete (Head);
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete (Head->prev);
        Head->prev = NULL;
    }

    Count--;
}

//=========================================================================================
//
//
// Function Name    :   DeleteLast()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   DeleteLast Function Remove The Node At End Of The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================================

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (Head->next == NULL)
    {
        delete (Head);
        Head = NULL;
    }
    else
    {
        struct nodeD<T> *Temp = Head;

        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }

        delete (Temp->next);
        Temp->next = NULL;
    }

    Count--;
}

//======================================================================================================
//
//
// Function Name    :   InsertAtPos()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No, Generic Pos
// Description      :   Insert At Position Function Add New Node At Given Position In The LinkedList
//
// Returns          :   NONE
//
//
//=======================================================================================================

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int pos)
{
    if (pos < 1 || pos > (Count + 1))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == (Count + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct nodeD<T> *newn = new struct nodeD<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeD<T> *Temp = Head;
        int i = 1;

        while (i < (pos - 1))
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        newn->next->prev = newn;

        newn->prev = Temp;
        Temp->next = newn;

        Count++;
    }
}

//==========================================================================================================
//
//
// Function Name    :   DeleteAtPos()
// Function Date    :   27 Dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic Pos
// Description      :   Delete At Position Function Remove Existing Node from given Position In The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================================================

template <class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > Count)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> *Temp = Head;
        int i = 1;

        while (i < (pos - 1))
        {
            Temp = Temp->next;
            i++;
        }

        Temp->next = Temp->next->next;
        delete (Temp->next->prev);

        Temp->next->prev = Temp;

        Count--;
    }
}

//============================================================================
//
//
// Function Name    :   Display()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Display Function Display all The Nodes In LinkedList
//
// Returns          :   NONE
//
//
//=============================================================================

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeD<T> *Temp = Head;

    cout << "NULL<=|";

    while (Temp != NULL)
    {
        cout << "|" << Temp->data << "|<=>";
        Temp = Temp->next;
    }

    cout << "NULL" << endl;
}

//================================================================================================
//
//
// Function Name    :   CountNode()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Count Function Count Number Of Nodes In LinkedList
//
// Returns          :   Return Number Of Nodes In LinkedList
//
//================================================================================================

template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

//=======================================================================================
//
//
// Function Name    :   SearchFirstOccurance()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   integer
//
//
//=======================================================================================

template <class T>
int DoublyLL<T>::SearchFirstOccurance(T No) // 1  2   3   4   5   6   7   8   9   10
{
    int ipos = 0;
    int iCnt = 1;

    struct node<T> *Temp = Head;

    while (Temp != NULL)
    {
        if (Temp->data == No)
        {
            ipos = iCnt;
            break;
        }
        Temp = Temp->next;
        iCnt++;
    }

    return ipos;
}

//=======================================================================================
//
//
// Function Name    :   SearchLastOccurance()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   integer
//
//
//=======================================================================================

template <class T>
int DoublyLL<T>::SearchLastOccurance(T No)
{
    int ipos = 0;
    int iCnt = 1;

    struct node<T> *End = Head;

    while (End->next != NULL)
    {

        End = End->next;
    }

    while (End != NULL)
    {
        if (End->data == No)
        {
            ipos = iCnt;
            break;
        }

        iCnt++;
        End = End->prev;
    }

    int TotalNode = CountNode();

    return (TotalNode - ipos + 1);
}

//=======================================================================================
//
//
// Function Name    :   AdditionOfAllElement()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   Generic No
//
//
//=======================================================================================

template <class T>
T DoublyLL<T>::AdditionOfAllElement()
{
    T Sum = 0;

    struct node<T> *Temp = Head;

    while (Temp != NULL)
    {
        Sum = Sum + Temp->data;

        Temp = Temp->next;
    }

    return Sum;
}

//=======================================================================================
//
//
// Function Name    :   LargestElement()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   Generic No
//
//
//=======================================================================================

template <class T>
T DoublyLL<T>::LargestElement()
{
    struct node<T> *Temp = Head;
    T Max = Temp->data;

    while (Temp != NULL)
    {
        if (Max < Temp->data)
        {
            Max = Temp->data;
        }

        Temp = Temp->next;
    }

    return Max;
}

//=======================================================================================
//
//
// Function Name    :   SmallestElement()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   Generic No
//
//
//=======================================================================================

template <class T>
T DoublyLL<T>::SmallestElement()
{
    struct node<T> *Temp = Head;
    T Min = Temp->data;

    while (Temp != NULL)
    {
        if (Min > Temp->data)
        {
            Min = Temp->data;
        }

        Temp = Temp->next;
    }

    return Min;
}

//=========================================================================
//
//
// Class Name       :   SinglyCL
// Function Date    :   28 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class SinglyCL
//
// Returns          :   NONE
//
//
//=========================================================================

template <class T>
SinglyCL<T>::SinglyCL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

//=======================================================================================
//
//
// Function Name    :   InsertFirst()
// Function Date    :   28 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   NONE
//
//
//=======================================================================================

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }

    Tail->next = Head;
    Count++;
}

//============================================================================
//
//
// Function Name    :   InsertLast()
// Function Date    :   28 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertLast Function Add New Node At End Of LinkedList
//
// Returns          :   NONE
//
//
//============================================================================

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }

    Tail->next = Head;
    Count++;
}

//================================================================================================
//
//
// Function Name    :   DeleteFirst()
// Function Date    :   28 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList
//
// Returns          :   NONE
//
//
//================================================================================================

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (Head == NULL && Tail == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (Head == Tail)
    {
        delete (Head);

        Head = NULL;
        Tail = NULL;

        Count--;
    }
    else
    {
        Head = Head->next;
        delete (Tail->next);

        Tail->next = Head;
        Count--;
    }
}

//=========================================================================================
//
//
// Function Name    :   DeleteLast()
// Function Date    :   28 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   DeleteLast Function Remove The Node At End Of The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================================

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (Head == NULL && Tail == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (Head == Tail)
    {
        delete (Head);

        Head = NULL;
        Tail = NULL;

        Count--;
    }
    else
    {
        struct nodeS<T> *Temp = Head;

        while (Temp->next->next != Tail->next) //(Temp->next->next != Head)
        {
            Temp = Temp->next;
        }

        delete (Temp->next); // delete(Tail)
        Tail = Temp;

        Tail->next = Head;
        Count--;
    }
}

//======================================================================================================
//
//
// Function Name    :   InsertAtPos()
// Function Date    :   28 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No, Generic Pos
// Description      :   Insert At Position Function Add New Node At Given Position In The LinkedList
//
// Returns          :   NONE
//
//
//=======================================================================================================

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int pos)
{
    if (pos < 1 || pos > (Count + 1))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == (Count + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct nodeS<T> *newn = new struct nodeS<T>;

        newn->data = No;
        newn->next = NULL;

        struct nodeS<T> *Temp = Head;
        int i = 1;

        while (i < (pos - 1))
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        Temp->next = newn;

        Count++;
    }
}

//==========================================================================================================
//
//
// Function Name    :   DeleteAtPos()
// Function Date    :   28 Dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic Pos
// Description      :   Delete At Position Function Remove Existing Node from given Position In The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================================================

template <class T>
void SinglyCL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > (Count))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == (Count))
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> *Temp1 = Head;
        int i = 1;

        while (i < (pos - 1))
        {
            Temp1 = Temp1->next;
            i++;
        }

        struct nodeS<T> *Temp2 = Temp1->next;

        Temp1->next = Temp2->next;
        delete (Temp2);

        Count--;
    }
}

//============================================================================
//
//
// Function Name    :   Display()
// Function Date    :   28 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Display Function Display all The Nodes In LinkedList
//
// Returns          :   NONE
//
//
//=============================================================================

template <class T>
void SinglyCL<T>::Display()
{
    struct nodeS<T> *Temp = Head;

    do
    {
        cout << "|" << Temp->data << "|->";
        Temp = Temp->next;

    } while (Temp != Tail->next);

    cout << endl;
}

//================================================================================================
//
//
// Function Name    :   CountNode()
// Function Date    :   28 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Count Function Count Number Of Nodes In LinkedList
//
// Returns          :   Return Number Of Nodes In LinkedList
//
//================================================================================================

template <class T>
int SinglyCL<T>::CountNode()
{
    return Count;
}

//=========================================================================
//
//
// Class Name       :   DoublyCL
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyCL
//
// Returns          :   NONE
//
//
//=========================================================================

template <class T>
DoublyCL<T>::DoublyCL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

//=======================================================================================
//
//
// Function Name    :   InsertFirst()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList
//
// Returns          :   NONE
//
//
//=======================================================================================

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        newn->next->prev = newn;
        Head = newn;
    }

    Head->prev = Tail;
    Tail->next = Head;
    Count++;
}

//============================================================================
//
//
// Function Name    :   InsertLast()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   InsertLast Function Add New Node At End Of LinkedList
//
// Returns          :   NONE
//
//
//============================================================================

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }

    Head->prev = Tail;
    Tail->next = Head;
    Count++;
}

//================================================================================================
//
//
// Function Name    :   DeleteFirst()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList
//
// Returns          :   NONE
//
//
//================================================================================================

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Head == Tail)
    {
        delete (Head);
        Head = NULL;
        Tail = NULL;

        Count--;
    }
    else
    {
        Head = Head->next;
        delete (Head->prev);

        Head->prev = Tail;
        Tail->next = Head;
        Count--;
    }
}

//=========================================================================================
//
//
// Function Name    :   DeleteLast()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   DeleteLast Function Remove The Node At End Of The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================================

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Head->next == Head)
    {
        delete (Head);
        Head = NULL;
        Tail = NULL;

        Count--;
    }
    else
    {
        Tail = Tail->prev;
        delete (Tail->next);

        Head->prev = Tail;
        Tail->next = Head;
        Count--;
    }
}

//======================================================================================================
//
//
// Function Name    :   InsertAtPos()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No, Generic Pos
// Description      :   Insert At Position Function Add New Node At Given Position In The LinkedList
//
// Returns          :   NONE
//
//
//=======================================================================================================

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int pos)
{
    if ((pos < 1) || (pos > (Count + 1)))
    {
        cout << "Invalid positon" << endl;
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == (Count + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct nodeD<T> *newn = new struct nodeD<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeD<T> *Temp = Head;
        int i = 1;

        while (i < (pos - 1))
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        newn->next->prev = newn;

        newn->prev = Temp;
        Temp->next = newn;

        Count++;
    }
}

//==========================================================================================================
//
//
// Function Name    :   DeleteAtPos()
// Function Date    :   27 Dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic Pos
// Description      :   Delete At Position Function Remove Existing Node from given Position In The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================================================

template <class T>
void DoublyCL<T>::DeleteAtPos(int pos)
{
    if ((pos < 1) || (pos > (Count)))
    {
        cout << "Invalid positon" << endl;
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == (Count))
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> *Temp = Head;
        int i = 1;

        while (i < (pos - 1))
        {
            Temp = Temp->next;
            i++;
        }

        Temp->next = Temp->next->next;
        delete (Temp->next->prev);

        Temp->next->prev = Temp;
        Count--;
    }
}

//============================================================================
//
//
// Function Name    :   Display()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Display Function Display all The Nodes In LinkedList
//
// Returns          :   NONE
//
//
//=============================================================================

template <class T>
void DoublyCL<T>::Display()
{
    struct nodeD<T> *Temp = Head;

    do
    {
        cout << "|" << Temp->data << "|<=>";
        Temp = Temp->next;

    } while (Temp != Tail->next);

    cout << endl;
}

//================================================================================================
//
//
// Function Name    :   Count()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Count Function Count Number Of Nodes In LinkedList
//
// Returns          :   Return Number Of Nodes In LinkedList
//
//================================================================================================

template <class T>
int DoublyCL<T>::CountNode()
{
    return Count;
}

//=========================================================================
//
//
// Class Name       :   Stack
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class Stack
//
// Returns          :   NONE
//
//
//=========================================================================

template <class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

//=======================================================================================
//
//
// Function Name    :   isStackEmpty()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   isStackEmpty Function tell us stack is empty or not
//
// Returns          :   boolean value ture or false
//
//
//=======================================================================================

template <class T>
bool Stack<T>::isStackEmpty()
{
    if (Head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//=======================================================================================
//
//
// Function Name    :   Push()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   Push Function insert element in a stack
//
// Returns          :   NONE
//
//
//=======================================================================================

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = No;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct nodeS<T> *Temp = Head;

        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = newn;
    }

    cout << " Gets pushed in the stack succesfully" << endl;
    Count++;
}

//=======================================================================================
//
//
// Function Name    :   Pop()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   Pop Function remove last elements of stack (Stack follow LIFO-LAST IN FIRST OUT)
//
// Returns          :   NONE
//
//
//=======================================================================================

template <class T>
T Stack<T>::Pop()
{
    T value = 0;

    if (Head == NULL)
    {
        cout << " Unable to pop the element as stack is empty" << endl;
        return -1;
    }
    else if (Head->next == NULL)
    {
        value = Head->data;
        Head = NULL;

        Count--;
        return value;
    }
    else
    {
        struct nodeS<T> *Temp = Head;

        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }

        value = Temp->next->data;
        delete (Temp->next);
        Temp->next = NULL;

        Count--;
        return value;
    }

    cout << "Poped elements succesfully" << endl;
}

//============================================================================
//
//
// Function Name    :   Display()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Display Function Display all The elements from the stack
//
// Returns          :   NONE
//
//
//=============================================================================

template <class T>
void Stack<T>::Display()
{
    struct nodeS<T> *Temp = Head;

    while (Temp != NULL)
    {
        cout << Temp->data << "|->";
        Temp = Temp->next;
    }

    cout << "NULL" << endl;
}

//================================================================================================
//
//
// Function Name    :   CountNode()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Count Function Count Number Of elements from the stack
//
// Returns          :   Return Number Of elements from the stack
//
//================================================================================================

template <class T>
int Stack<T>::CountNode()
{
    return Count;
}

//=========================================================================
//
//
// Class Name       :   Queue
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class Queue
//
// Returns          :   NONE
//
//
//=========================================================================

template <class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

//=======================================================================================
//
//
// Function Name    :   isQueueEmpty()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   isQueueEmpty Function tell us queue is empty or not
//
// Returns          :   boolean value ture or false
//
//
//=======================================================================================

template <class T>
bool Queue<T>::isQueueEmpty()
{
    if (Head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//=======================================================================================
//
//
// Function Name    :   Enqueue()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   Generic No
// Description      :   Enqueue Function insert element in a queue
//
// Returns          :   NONE
//
//
//=======================================================================================

template <class T>
void Queue<T>::Enqueue(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = No;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct nodeS<T> *Temp = Head;

        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = newn;
    }

    Count++;
}

//=======================================================================================
//
//
// Function Name    :   Dequeue()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   NONE
// Description      :   Dequeue Function remove first elements from queue (Queue follow FIRST IN FIRST OUT)
//
// Returns          :   NONE
//
//
//=======================================================================================

template <class T>
T Queue<T>::Dequeue()
{
    int value = 0;

    if (Head == NULL)
    {
        cout << "Unable to remove elements because stack is empty" << endl;
        return -1;
    }
    else if (Head->next == NULL)
    {
        value = Head->data;
        delete (Head);
        Head = NULL;
        Count--;
        return value;
    }
    else
    {
        struct nodeS<T> *Temp = Head;
        value = Head->data;
        Head = Temp->next; // Head=Head->next;
        delete (Temp);
        Count--;

        return value;
    }
}

//============================================================================
//
//
// Function Name    :   Display()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Display Function Display all The elements from the Queue
//
// Returns          :   NONE
//
//
//=============================================================================

template <class T>
void Queue<T>::Display()
{
    struct nodeS<T> *Temp = Head;

    while (Temp != NULL)
    {
        cout << "|" << Temp->data << "|->";
        Temp = Temp->next;
    }

    cout << "NULL" << endl;
}

//================================================================================================
//
//
// Function Name    :   CountNode()
// Function Date    :   27 dec 2022
// Function Author  :   Suhas Dilip Sankpal
// Parameters       :   None
// Description      :   Count Function Count Number Of elements from the queue
//
// Returns          :   Return Number Of elements from the queue
//
//================================================================================================

template <class T>
int Queue<T>::CountNode()
{
    return Count;
}

//====================================================================================================
//
// Function Name   :   Entry Point Function
//
//====================================================================================================

int main()
{

    return 0;
}
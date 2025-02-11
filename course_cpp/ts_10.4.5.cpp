#include <iostream>
#include <cmath>

typedef struct
{
    char author[50]; // автор
    char title[100]; // заголовок
    short year;      // год издания
} BOOK;

struct Node
{
public:
    BOOK data;
    Node *next;

public:
    Node(BOOK data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct OneLinkedList
{
public:
    Node *head, *tail;

public:
    OneLinkedList()
    {
        this->head = this->tail = NULL;
    }

    ~OneLinkedList()
    {
        while (head != NULL)
            pop_front();
    }

    void pop_front()
    {
        if (head == NULL)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node *node = head;
        head = node->next;
        delete node;
    }

    void push_back(BOOK data)
    {
        Node *node = new Node(data);
        if (head == NULL)
            head = node;
        if (tail != NULL)
            tail->next = node;
        tail = node;
    }

    void push_front(BOOK data)
    {
        Node *node = new Node(data);
        node->next = head;
        head = node;
        if (tail == NULL)
            tail = node;
    }

    void pop_back()
    {
        if (tail == NULL)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node *node = head;
        for (; node->next != tail; node = node->next)
            ;

        node->next = NULL;
        delete tail;
        tail = node;
    }

    Node *getAt(int k)
    {
        if (k < 0)
            return NULL;

        Node *node = head;
        int n = 0;
        while (node && n != k && node->next)
        {
            node = node->next;
            n++;
        }

        return (n == k) ? node : NULL;
    }

    void insert(int k, BOOK data)
    {
        Node *left = getAt(k);
        if (left == NULL)
            return;

        Node *right = left->next;
        Node *node = new Node(data);

        left->next = node;
        node->next = right;
        if (right == NULL)
            tail = node;
    }

    void erase(int k)
    {
        if (k < 0)
            return;
        if (k == 0)
        {
            pop_front();
            return;
        }

        Node *left = getAt(k - 1);
        Node *node = left->next;
        if (node == NULL)
            return;

        Node *right = node->next;
        left->next = right;
        if (node == tail)
            tail = left;
        delete node;
    }
};

int module_id = -1;

namespace params
{
    int global_result = 0;
}

namespace triangle
{
    double square(int a, int b, int c)
    {
        module_id;
        ::module_id;
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
}

namespace params
{
    typedef union
    {
        int res_int;
        double res_dbl;
    } RESULT;
}

int main(void)
{
    using namespace std;
    OneLinkedList lib;

    lib.push_back({"Пушкин А.С.", "Пиковая дама", 2007});
    lib.push_back({"Тургенев И.С.", "Муму", 2011});
    lib.push_back({"Толстой А.Н.", "Аэлита", 1995});
    lib.push_back({"Балакирев С.М.", "Моя жизнь, мои достижения", 2045});

    char msg[] = "hello";
    int count = 0;
    int &lnk = count;
    char *ptr = msg;

    auto lmd_5 = [ptr](int step)
    { *ptr += step; };

    auto lmd_1 = [msg, count, lnk, ptr]()
    { return count + 1; };

    auto lmd_3 = [&count](int step)
    { count += step; };

    auto lmd_4 = [&lnk](int step)
    { lnk += step; };

    auto lmd_2 = [=]()
    { std::cout << msg; };

    //__assertion_tests(lib);    // эту строчку не убирать (должна стоять перед return 0)
    return 0;
}
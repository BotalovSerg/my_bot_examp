#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Object
{
    int data{0};
    std::shared_ptr<Object> next{nullptr};

public:
    Object(int d) : data(d), next(nullptr) {}

    int get_data() const { return data; }
    std::shared_ptr<Object> &get_next() { return next; }
    void set_next(const std::shared_ptr<Object> &n) { next = n; }
};

using shared_obj_ptr = std::shared_ptr<Object>;

class Stack
{
    shared_obj_ptr top{nullptr};

public:
    // Получить текущий верхний элемент
    shared_obj_ptr get_top() const { return top; }

    // Добавление элемента в стек
    void push(int data)
    {
        auto node = std::make_shared<Object>(data);
        node->set_next(top);
        top = node;
    }

    // Удаление верхнего элемента и возврат его
    shared_obj_ptr pop()
    {
        if (!top)
            return nullptr;
        auto ptr = top;
        top = top->get_next();
        return ptr;
    }

    // Конструктор копирования (глубокое копирование)
    Stack(const Stack &other)
    {
        // Собираем все элементы из другого стека в временный контейнер
        std::vector<int> values;
        for (auto p = other.top; p != nullptr; p = p->get_next())
        {
            values.push_back(p->get_data());
        }
        // Восстанавливаем стек в обратном порядке, чтобы сохранить исходный порядок
        for (auto it = values.rbegin(); it != values.rend(); ++it)
        {
            push(*it);
        }
    }

    // Оператор присваивания (глубокое копирование)
    Stack &operator=(const Stack &other)
    {
        if (this != &other)
        {
            // Очистка текущего стека
            while (pop())
                ;
            // Копирование элементов из другого стека
            std::vector<int> values;
            for (auto p = other.top; p != nullptr; p = p->get_next())
            {
                values.push_back(p->get_data());
            }
            for (auto it = values.rbegin(); it != values.rend(); ++it)
            {
                push(*it);
            }
        }
        return *this;
    }

    // Конструктор по умолчанию
    Stack() = default;

    // Деструктор - автоматический благодаря smart pointers

    // Оператор += для добавления элемента сверху
    Stack &operator+=(int value)
    {
        push(value);
        return *this;
    }

    // Префиксный -- для удаления верхнего элемента
    Stack &operator--()
    {
        pop();
        return *this;
    }

    // Постфиксный -- для удаления верхнего элемента
    Stack operator--(int)
    {
        Stack temp(*this);
        pop();
        return temp;
    }
};

// Демонстрация использования
int main()
{
    Stack s1, s2;

    s1.push(10);
    s1.push(-5);

    s2 = s1; // копирование стека s1 в s2

    s2 += 7; // добавление элемента 7 сверху стека s2

    --s2; // удаление верхнего элемента из s2 (префикс)

    s2--; // удаление верхнего элемента из s2 (постфикс)

    // Вывод содержимого стеков
    std::cout << "s1: ";
    auto p1 = s1.get_top();
    while (p1)
    {
        std::cout << p1->get_data() << " ";
        p1 = p1->get_next();
    }

    std::cout << "\ns2: ";
    auto p2 = s2.get_top();
    while (p2)
    {
        std::cout << p2->get_data() << " ";
        p2 = p2->get_next();
    }

    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <string>

struct PhoneBookItem
{
    std::string fio;          // ФИО контакта
    std::string phone_number; // номер телефона

    PhoneBookItem() = default;
    PhoneBookItem(std::string fio, std::string phone_number)
        : fio(fio), phone_number(phone_number)
    {
    }
};

class PhoneBook
{
    enum
    {
        max_phone_book = 100 // максимальная емкость телефонной книжки
    };
    PhoneBookItem *phone_book{nullptr}; // массив из записей
    size_t count{0};                    // количество записей в телефонной книжке

public:
    PhoneBook()
    {
        phone_book = new PhoneBookItem[max_phone_book];
    }

    PhoneBook(const PhoneBook &other) // Конструктор копирования
        : count(other.count)
    {
        phone_book = new PhoneBookItem[max_phone_book];
        for (size_t i = 0; i < count; ++i)
            phone_book[i] = other.phone_book[i];
    }

    ~PhoneBook() { delete[] phone_book; }

    const PhoneBookItem *get_phone_book() const
    {
        return phone_book;
    }

    size_t get_count() const { return count; }

    bool append(const PhoneBookItem &item)
    {
        if (count < max_phone_book)
        {
            phone_book[count++] = item;
            return true;
        }
        return false;
    }

    PhoneBook operator+(const PhoneBookItem &item) const
    {
        PhoneBook newPhoneBook = *this; // Создаем новый объект на основе текущего
        newPhoneBook.append(item);      // Добавляем новый элемент
        return newPhoneBook;            // Возвращаем новый объект
    }

    PhoneBook &operator=(const PhoneBook &other)
    {
        if (this != &other) // Проверка на самоприсваивание
        {
            delete[] this->phone_book;
            this->count = other.count;
            this->phone_book = new PhoneBookItem[max_phone_book];
            for (size_t i = 0; i < count; i++)
            {
                this->phone_book[i] = other.phone_book[i];
            }
        }
        return *this;
    }
};

int main()
{
    PhoneBook phone_lst;

    phone_lst.append(PhoneBookItem("А. Дзюба", "+71237694401"));
    phone_lst.append(PhoneBookItem("П. Гагарина", "+79234694105"));
    phone_lst.append(PhoneBookItem("О. Бузова", "+79041563055"));
    phone_lst.append(PhoneBookItem("Тимати", "+79121000000"));

    // Выводим содержимое телефонной книжки для проверки
    for (size_t i = 0; i < phone_lst.get_count(); ++i)
    {
        const auto &item = phone_lst.get_phone_book()[i];
        std::cout << item.fio << ": " << item.phone_number << std::endl;
    }

    return 0;
}
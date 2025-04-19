#include <iostream>

class StudentMarks
{
    enum
    {
        max_length = 100
    };
    short marks[max_length]{0};
    int count{0};

public:
    StudentMarks(short *ms, int total)
    {
        count = (total > max_length) ? max_length : total;

        for (int i = 0; i < count; ++i)
            marks[i] = ms[i];
    }
    StudentMarks operator+(const StudentMarks &obj)
    {
        int new_count = this->get_count() + obj.get_count();
        short new_marks[new_count]{0};
        for (int i = 0; i < this->count; i++)
        {
            new_marks[i] = this->marks[i];
        }
        for (int i = this->count, j = 0; i < new_count; i++, j++)
        {
            new_marks[i] = obj.marks[j];
        }
        return StudentMarks(new_marks, new_count);
    }
    StudentMarks operator+(int mark)
    {
        int new_count = this->count + 1;
        short new_marks[new_count]{0};
        for (int i = 0; i < this->count; i++)
        {
            new_marks[i] = this->marks[i];
        }
        new_marks[new_count - 1] = mark;
        return StudentMarks(new_marks, new_count);
    }

    const short *get_marks() const { return marks; }
    int get_count() const { return count; }
};

int main(void)
{
    short m[] = {2, 2, 3, 2, 3};
    short k[] = {5, 4, 2};
    StudentMarks marks_1(m, sizeof(m) / sizeof(*m));
    StudentMarks marks_2(k, sizeof(k) / sizeof(*k));
    StudentMarks res_1 = marks_1 + marks_2;
    StudentMarks res_2 = marks_1 + 4;
    return 0;
}
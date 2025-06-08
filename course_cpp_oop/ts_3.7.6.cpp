#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class ExtensionFilter
{
public:
    // Конструктор принимает строку с расширениями, разделёнными '|'
    ExtensionFilter(const std::string &extensions_str)
    {
        parseExtensions(extensions_str);
    }

    // Оператор вызова для фильтрации массива файлов
    int operator()(const std::string *lst, int size_lst, std::string *flt_lst, int max_count) const
    {
        int count = 0;
        for (int i = 0; i < size_lst; ++i)
        {
            if (count >= max_count)
            {
                break; // достигли лимита
            }
            if (hasExtension(lst[i]))
            {
                flt_lst[count] = lst[i];
                ++count;
            }
        }
        return count;
    }

private:
    std::vector<std::string> extensions;

    void parseExtensions(const std::string &extensions_str)
    {
        std::stringstream ss(extensions_str);
        std::string ext;
        while (std::getline(ss, ext, '|'))
        {
            // Удаляем возможные пробелы
            ext.erase(std::remove_if(ext.begin(), ext.end(), ::isspace), ext.end());
            // Приводим к нижнему регистру для сравнения
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
            extensions.push_back(ext);
        }
    }

    bool hasExtension(const std::string &filename) const
    {
        size_t dot_pos = filename.find_last_of('.');
        if (dot_pos == std::string::npos || dot_pos == filename.length() - 1)
        {
            return false; // нет расширения
        }
        std::string file_ext = filename.substr(dot_pos + 1);
        // Приводим к нижнему регистру для сравнения
        std::transform(file_ext.begin(), file_ext.end(), file_ext.begin(), ::tolower);
        return std::find(extensions.begin(), extensions.end(), file_ext) != extensions.end();
    }
};

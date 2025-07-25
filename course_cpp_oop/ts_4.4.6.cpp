#include <iostream>
#include <string>

enum request_method
{
    method_get = 1,
    method_post = 2,
    method_put = 3,
    method_delete = 4
};

struct Request
{
    request_method method{method_get};
    std::string url;
    std::string data;
};

class GenericView
{ // базовый класс для обработки запросов
protected:
    enum
    {
        total_methods = 3
    };
    request_method methods[total_methods] = {method_get, method_post, method_put}; // массив допустимых методов
public:
    virtual std::string get(const Request &request)
    {
        return request.data;
    }
    virtual std::string post(const Request &request)
    {
        return request.data;
    }
    virtual std::string put(const Request &request)
    {
        return request.data;
    }
    virtual std::string del(const Request &request)
    {
        return request.data;
    }
};

class DetailView : public GenericView
{
    std::string empty_result{""};
    bool is_method_exists(request_method method)
    {
        for (int i = 0; i < total_methods; i++)
        {
            if (methods[i] == method)
            {
                return true;
            }
        }
        return false;
    }

public:
    virtual std::string get(const Request &request)
    {
        return request.url;
    }
    const std::string render_request(const Request &request)
    {
        if (!is_method_exists(request.method))
        {
            return empty_result;
        }

        switch (request.method)
        {
        case method_get:
            return get(request);
        case method_post:
            return post(request);
        case method_put:
            return put(request);
        case method_delete:
            return del(request);
        default:
            return empty_result;
        }
    }
};

int main(void)
{
    DetailView dw;
    Request request{
        method_get,
        std::string{"https://proproprogs.ru/cpp_oop/cpp-oop-virtualnye-virtual-metody-funkcii"},
        std::string{"<h1>Заголовок</h1>"},
    };
    std::string res = dw.render_request(request);

    return 0;
}
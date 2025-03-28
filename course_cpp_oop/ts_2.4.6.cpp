#include <iostream>
#include <string>

class Notebook
{
    std::string model;
    std::string cpu_model;
    unsigned memory{0};
    unsigned disk_volume{0};

public:
    void set_data(const std::string &model, const std::string &cpu, unsigned memory, unsigned disk)
    {
        this->model = model;
        this->cpu_model = cpu;
        this->memory = memory;
        this->disk_volume = disk_volume;
    }
    std::string &get_model()
    {
        return model;
    }
    std::string &get_cpu()
    {
        return cpu_model;
    }
    void get_info(unsigned &memory, unsigned &disk_volume)
    {
        memory = this->memory;
        disk_volume = this->disk_volume;
    }
    Notebook(const std::string &model = "", const std::string &cpu = "", unsigned memory = 0, unsigned disk = 0) : model(model), cpu_model(cpu), memory(memory), disk_volume(disk) {}
    Notebook(const char *model) : model{model}, cpu_model{""}, memory{0}, disk_volume{0} {}
};

int main(void)
{
    Notebook note("HP", "Core i7", 16000, 512);
    return 0;
}
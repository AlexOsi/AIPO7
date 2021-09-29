#pragma once
#include <utility>
#include <vector>
#include <string>
const std::vector<std::string> FIRSTNAME = { "Vasiliy", "Ivan", "Igor", "Nikita", "Vladimir", "Petr", "Danil", "Oleg", "Anton", "Sergey", "Dmitriy", "Alexey" };
const std::vector<std::string> SECONDNAME = { "Smirnov", "Ivanov", "Kozlov", "Volkov", "Morozov", "Sidorov", "Novikov", "Tarasov", "Sorokin", "Romanov", "Fomin" };
const std::vector<std::string> CLOTHINGSIZE = { "XXS", "XS", "S", "M", "L", "XL", "XXL", "XXXL" };
const int SIZEF = FIRSTNAME.size();
const int SIZEC = SECONDNAME.size();
const int SIZECS = CLOTHINGSIZE.size();


struct Employee {
    Employee() {} ;
    Employee(int i, std::string f, std::string s, int a, std::string c, int sh, int d, int sal)
            :id(i), firstName(std::move(f)), secondName(std::move(s)), age(a), clothingSize(std::move(c)), shoeSize(sh), daysWorked(d), salary(sal)
    {}

    std::string firstName, secondName, clothingSize;
    int id{}, age{}, shoeSize{}, salary{}, daysWorked{};
};
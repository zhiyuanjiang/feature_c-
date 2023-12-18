/*
*   结构化绑定
*   将指定的名称绑定到初始化对象的子对象or元素，能绑定数组对象、类似元组的类型、成员变量
*/

#include <iostream>
#include <tuple>
#include <map>

/*
* 1 绑定数组对象
*/
void bind_array() {
    int a[2] = {1, 2};
    // 绑定的变量名的作用域是整个函数
    auto [x, y] = a;
    std::cout << "a[0]:" << x << " a[1]:" << y << std::endl;
    // 引用绑定
    auto& [rx, ry] = a;
    std::cout << "a[0]:" << rx << " a[1]:" << ry << std::endl;
    rx = 2;
    std::cout << "a[0]:" << a[0] << " a[1]:" << a[1] << std::endl;
}

/*
*  2 绑定类似元组的类型
*/
void bind_tuple_like_type() {
    std::tuple<int, double> t{1, 2.35};
    auto [x, y] = t;
    std::cout << "tp0:" << x << " tp1:" << y << std::endl;
}

/*
* 2 绑定成员变量
*/ 
struct People {
    int _age;
    std::string _sex;
    People(int age, std::string sex) : _age(age), _sex(sex) {}
};

void bind_data_members() {
    People stu{10, "man"};
    auto [age, sex] = stu;
    std::cout << "age:" << age << " sex:" << sex << std::endl;
}

void test_map() {
    std::map<int, std::string> mp{
        {2, "zhi"}, {3, "yuan"}
    };
    for(auto& [_, val] : mp){
        std::cout << val << std::endl;
    }
}

int main() {
    // bind_array();
    // bind_tuple_like_type();
    // bind_data_members();
    test_map();
    return 0;
}
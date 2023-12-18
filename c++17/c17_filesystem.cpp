/*
*   std::filesystem 提供对文件操作的一系列方法
*/

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path p1("/home/jzy/test/test");
    if(p1.has_parent_path()){
        std::cout << "parent path: " << p1.parent_path() << std::endl;
    }
    for(auto& tmp : p1){
        std::cout << "iter: " << tmp << " ";
    }
    std::cout << std::endl;
    if(!fs::exists(p1)){
        fs::create_directory(p1);
    }
    fs::path old_path("/home/jzy/test/test.txt");
    fs::path new_path("/home/jzy/test/test");
    if(!fs::exists(new_path))
        fs::copy(old_path, new_path);
    fs::remove_all(new_path);
    std::cout << "pwd: " << fs::current_path() << std::endl;
    // 获取目录下所有文件
    std::cout << "all path: " << std::endl;
    for(auto& p : fs::directory_iterator{fs::current_path()}){
        std::cout << p << std::endl;
        if(fs::is_directory(p)){
            std::cout << "directory" << std::endl;
        }else if(fs::is_regular_file(p)){
            std::cout << "file" << std::endl;
        }
    }
    return 0;
}
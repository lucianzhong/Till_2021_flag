

#include "docker.hpp"
#include <iostream>
 

// Docker 的本质是使用 LXC 实现类似虚拟机的功能，进而节省的硬件资源提供给用户更多的计算资源。本项目将 C++ 与 Linux 的 Namespace 及 Control Group 技术相结合，实现一个简易 Docker 容器
// https://blog.csdn.net/BJUT_bluecat/article/details/92443153

// https://www.cnblogs.com/luosongchao/p/3680312.html 
// https://blog.csdn.net/yangkuanqaz85988/article/details/52403726 进程栈
// https://blog.csdn.net/hty46565/article/details/79934205 namespace

int main(int argc, char** argv)
{
    std::cout << "start docker..." << std::endl;
    bluecat::docker_info doc_info;
    doc_info.hostname = "蓝猫的docker";
    doc_info.root_dir="./";
    bluecat::bluecat_docker mydocker(doc_info);
    mydocker.start();                  // 启动容器
    std::cout << "stop docker..." << std::endl;
    return 0;
}
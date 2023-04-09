#include <iostream>

using namespace std;

void setguid(unsigned short uid){ std::cout << "In setguid function, uid = " << uid << std::endl; };
void setuid(unsigned short uid){ std::cout << "In setuid function, uid = " << uid << std::endl; };
void grant_privs(unsigned short uid){

    std::cout << "In grant_privs, uid = " << uid << std::endl;
    setguid(uid);
    setuid(uid);
}

int become_user(int uid){

    std::cout << "In become_user, uid = " << uid << std::endl;
    if (uid == 0){
        fprintf(stderr, "mounting as root is not allowed\n");
        return -1;
    }
    grant_privs(uid);
    return 0;
}

int main(){
    int uid;
    std::cout << "Your ID?" << std::endl;
    std::cin >> uid;
    std::cout << "In main, uid = " << uid << std::endl;
    try {
        if (become_user(uid)){
            throw -1;
        }

    } catch (int e){
        std::cout << "In main, uid = " << uid << " leads to exception!" << std::endl;
    }
    return 0;
}
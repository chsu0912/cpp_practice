#include <iostream>

using namespace std;

#define GET_U32(p) ((p)? (uint32_t) *((uint32_t*)(p)) : 0)

inline uint32_t get_u32(void * p){
    return p ? (uint32_t) *((uint32_t * ) p) : 0;
}                   

int main(){
    
    int * x; 
    int * y;
    int * z;

    (get_u32(x++) == GET_U32(x++)) ? std::cout << "Yes" : std::cout << "No" << std::endl;
    (get_u32(y++) == GET_U32(++y)) ? std::cout << "Yes" : std::cout << "No" << std::endl;
    (get_u32(z) == GET_U32(z)) ? std::cout << "Yes" : std::cout << "No" << std::endl;
    
    std::cout << "get_u32(z) == " << get_u32(z) << std::endl;
    std::cout << "GET_U32(z) == " << GET_U32(z) << std::endl;
}

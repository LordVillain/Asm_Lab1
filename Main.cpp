#include <iostream>
#include <iomanip>

int main() {
    __int16 A1 = 0;
    __int16 A2 = 0;
    __int16 A3 = 0;
    __int16 B1 = 0;
    __int16 B2 = 0;
    __int16 B3 = 0;
    __int16 C1 = 0;
    __int16 C2 = 0;
    __int16 C3 = 0;


    std::cout << "A1: ";
    std::cin >> A1;
    std::cout << "A2: ";
    std::cin >> A2;
    std::cout << "A3: ";
    std::cin >> A3;
    std::cout << "B1: ";
    std::cin >> B1;
    std::cout << "B2: ";
    std::cin >> B2;
    std::cout << "B3: ";
    std::cin >> B3;

    _asm 
    {
        mov ax, A1
        mov bx, A2
        mov cx, A3
        mov dx, B1
        mov si, B2
        mov di, B3

        add ax, dx
        adc bx, si
        adc cx, di

        mov C1, ax
        mov C2, bx
        mov C3, cx
    }

    std::cout << "C1: " << C1 << std::endl;
    std::cout << "C2: " << C2 << std::endl;
    std::cout << "C3: " << C3 << std::endl;

    

    std::cout << "C1: " << std::setw(4) << std::setfill('0') << std::hex << C1 << std::endl;
    std::cout << "C2: " << std::setw(4) << std::setfill('0') << std::hex << C2 << std::endl;
    std::cout << "C3: " << std::setw(4) << std::setfill('0') << std::hex << C3 << std::endl;

    __int64 result = C1 + (static_cast<__int64>(C2) << 16) + (static_cast<__int64>(C3) << 32);

    std::cout << "Full number in 10 c/c: " << result << std::endl;

    return 0;
}







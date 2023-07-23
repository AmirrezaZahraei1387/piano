#include <iostream>
#include <windows.h>
#include <string>

using SoundPattern = std::string;
using SoundEffect = char;
constexpr int maxValueEnter{9};
constexpr int minValueEnter{1};

struct soundEffect{
    int duration{};
    int frequency{};
};


constexpr soundEffect sounds[9]{
        {800, 300},
        {300, 500},
        {300, 800},
        {100, 300},
        {400, 500},
        {900, 100},
        {400, 200},
        {200, 600},
        {500, 200},
};

void run(SoundPattern& pattern){

    int index{};

    for(SoundEffect effect: pattern){
        index = static_cast<int>(effect) - 49; // it will convert the number in character into a int
        if (index>= minValueEnter-1 && index<= maxValueEnter-1)
            Beep(sounds[index].frequency, sounds[index].duration);
    }
}

void getPattern(SoundPattern& variable) {
    std::cout << "please enter numbers among 1 to 9:";
    std::getline(std::cin, variable);
}

int main() {
    SoundPattern p{};
    getPattern(p);
    run(p);

    return 0;
}

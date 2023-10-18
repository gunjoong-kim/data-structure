#include "IntMaxHeap.hpp"
#include "time.h"

int main()
{
	std::srand(std::time(nullptr));
	IntMaxHeap test;

    // 배열을 무작위 값으로 초기화
    for (int i = 0; i < 100; i++) {
        test.insert(std::rand() % 100); // 0부터 99 사이의 무작위 정수
    }
	test.print();

	while (!test.is_empty())
	{
		std::cout << test.top() << " ";
		test.remove();
	}
	std::cout << "\n";
}
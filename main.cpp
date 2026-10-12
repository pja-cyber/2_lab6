#include "holiday.h"
#include <array>

namespace Parkjooae2649017
{
    void printHolidayArray(const holiday a[], const int n)
    {
        for (int i=0; i <n; ++i)
            std::cout<<a[i];
        std::cout << std::endl;
    }
}

int main()
{
    const int n{4};
    using namespace Parkjooae2649017;
    holiday a[n];
    a[0] = holiday{"Christmas", {12,25}, false};
    a[1].setName("Newyear day"); a[1].setDate({1,1}); a[1].setParkingEnforcement(false);
    a[2].input();
    std::cin >>a[3];

    printHolidayArray(a, n);

    std::array<holiday, n>arr;
    for (int i=0; i <arr.size(); ++i)
        arr.at(i) =a[i];
    for (const auto& arri : arr)
        arri.print();

    return 0;
}
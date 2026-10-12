#pragma once
#include "dayOfYear.h"

namespace Parkjooae2649017
{
    class holiday
    {
        dayofyear date{};
        bool parkingEnforcement{};
        
    public:
        holiday(dayofyear d = dayofyear{1,1}, bool p = false)
            : date{d}, parkingEnforcement{p}
        { }
        holiday(int m, int d, bool p)
            : date(m,d), parkingEnforcement{p}
        {}
   
        void print() const
        {
            date.print();
            if (parkingEnforcement)
                std::cout << "Parking laws will be enforced. \n";
            else
                std::cout << "Parking laws will NOT ne enforced";
        }
        const dayofyear& getDate() const {return date;}
        void setDate(const dayofyear& d) { date =d;}

    };
}



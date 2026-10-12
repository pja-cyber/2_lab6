#pragma once
#include "dayOfYear.h"
#include <string>

namespace Parkjooae2649017
{
    class holiday
    {
        std::string name;
        dayofyear date{};
        bool parkingEnforcement{};
        
    public:
        holiday(const std::string& n = "no name yet", dayofyear d = dayofyear{1,1}, bool p = false)
            : name{n}, date{d}, parkingEnforcement{p}
        { }
        // holiday(int m, int d, bool p)
        //     : date(m,d), parkingEnforcement{p}
        // {}
   
        void print() const
        {
            std::cout<< name << " : ";
            date.print();
            if (parkingEnforcement)
                std::cout << "Parking laws will be enforced. \n";
            else
                std::cout << "Parking laws will NOT ne enforced\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const holiday& h)
        {
            os<< h.name <<": ";
            os << h.date;
            if (h.parkingEnforcement)
                os << "Parking laws will be enforced. \n";
            else
                os <<  "Parking laws will NOT ne enforced\n";
            return os;
        }

        friend std::istream& operator>>(std::istream& is, holiday& h)
        {
            std::cout << "Enter holiday name: ";
            std::getline(is>>std::ws, h.name);
            is >> h.date;
            std::cout << "Enter parking law enforcement (1(T) or 0(F)) : ";
            is >> h.parkingEnforcement; 
            return is;
        }

        void input()
        {
            std::cout<< "Enter a name of holiday: ";
            std::getline(std::cin >> std::ws, name);
            date.input();
            std::cout<< "Enter parking law enforcement (1(T) or 0(F)) : ";
            std::cin >> parkingEnforcement;
        }

        const std::string& getName() const{return name;}
        const dayofyear& getDate() const {return date;}
        void setDate(const dayofyear& d) { date =d;}
        void setName(const std::string& n) {name = n;}
        void setParkingEnforcement(bool p){ parkingEnforcement=p;}

    };
}



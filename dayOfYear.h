#pragma once //헤더가드

#include <iostream>

// namespace Parkjooae2649017
// {
//     class dayofyear
//     {
//         public:
//         operator++(){}
//     };
// }

namespace Parkjooae2649017
{
// -네임스페이스 지정자 예: std::cout << "Enter your id: ";

    class dayofyear
    {
        int month{};
        int day{};
        void testmonth()
        {
            if ((month<1)||(month>12))
            {
                std::cout<< "Invalid month value!\n";
                std::exit(1);
            }
        }
        void testday()
        {
            if ((day<1)||(day>31))
            {
                std::cout<<"Invalid day value!\n";
                std::exit(1);
            }
        }

    public:
    //constructor 
        dayofyear (int m =1 , int d =1): month{m}, day{d}
        {
            testmonth();
            testday();
        }
        void input()
        {
            std::cout<<"Enter the month:";
            std::cin >> month; testmonth();
            std::cout<<"Enter the day: ";
            std::cin >>day; testday();
        }

        friend std::istream& operator>>(std::istream& is, dayofyear& d)
        {
            std::cout<<"Enter the month:";
            is >> d.month; d.testmonth();
            std::cout<<"Enter the day: ";
            is >> d.day; d.testday();
            return is;
        }
        void setmonth(int m) { month= m; testmonth();}
        void setday(int d) { day=d; testday();}
        void print() const
        {
            switch (month)
            {
            case 1: std::cout <<"Jan. "; break;
            case 2: std::cout <<"Feb. "; break;
            case 3: std::cout <<"Mar. "; break;
            case 4: std::cout <<"Apr. "; break;
            case 5: std::cout <<"May. "; break;
            case 6: std::cout <<"Jun. "; break;
            case 7: std::cout <<"Jul. "; break;
            case 8: std::cout <<"Aug. "; break;
            case 9: std::cout <<"Sep. "; break;
            case 10: std::cout <<"Oct. "; break;
            case 11: std::cout <<"Nov. "; break;
            case 12: std::cout <<"Dec. "; break;
            } std::cout<< day <<"\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const dayofyear& d)
        {
             switch (d.month)
            {
            case 1: os <<"Jan. "; break;
            case 2: os <<"Feb. "; break;
            case 3: os <<"Mar. "; break;
            case 4: os <<"Apr. "; break;
            case 5: os <<"May. "; break;
            case 6: os <<"Jun. "; break;
            case 7: os <<"Jul. "; break;
            case 8: os <<"Aug. "; break;
            case 9: os <<"Sep. "; break;
            case 10: os <<"Oct. "; break;
            case 11: os <<"Nov. "; break;
            case 12: os <<"Dec. "; break;
            } os<< d.day <<"\n";
            return os;
        }

        int getmonth() const {return month;}
        int getday() const {return day;}

        dayofyear operator++()
        {
            ++day;
            if (day>31)
            {
                ++month;
                if(month>12) month-=12;
                day-=31;
            }
            return dayofyear{month,day};

        }//전위

        dayofyear operator++(int)
        {
            dayofyear temp{month, day};
            int m{month};
            int d{day+1};
            if (d>31)
            {
                ++month;
                if(month>12) month-=12;
                day-=31;
            }
            return temp;
        }

        friend bool operator==(const dayofyear& d1, const dayofyear& d2)
        {
            return d1.month == d2.month && d1.day==d2.day;
        }
        friend dayofyear operator+(const dayofyear& d1, const dayofyear& d2)
        {//month:1~12,day:1~31
            return dayofyear{d1.month + d2.month, d1.day+ d2.day};
        }

    };
}

// using 지시자는 cpp파일에서는 영역 { block } 안에서 사용, 헤더파일엔 using 지시자는 사용하지 않고 네임스페이스 지정자를 사용합니다.
// -using 지시자 예: { using namespace std; cout << "Enter your id: "; }


// 2. 클래스명.h: 클래스 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상)
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
// public 멤버함수 정의
// -input: 표준스트림입력으로 멤버변수들 입력, test함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴
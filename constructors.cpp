#include"infarth.hh"
#include<iostream>
#include<stdexcept>
#include<exception>
#include<string>

using II=InfiniteArthmetic::Integer;

II::Integer()
{
    number = '0';
    length = 1;
    sign = '+';
}

II::Integer( const std::string& s)
{

    if (s[0] != '-')
    {
        sign = '+';
        length = s.size();
        number = s;
    }
    else
    {
        sign = '-';
        length = s.size() - 1;
        number = s;
        number.erase(0, 1);
    }
}

II::Integer(const Integer &other)
{
    this->sign = other.sign;
    this->length = other.length;
    this->number = other.number;
}
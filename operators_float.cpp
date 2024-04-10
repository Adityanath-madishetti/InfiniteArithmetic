#include"infarth.hh"
#include<iostream>
#include<stdexcept>
#include<exception>
#include<string>

using IF=InfiniteArthmetic::Float;

IF& IF:: operator=(const Float& other)
{
     this->decimal_index=other.decimal_index;
     this->fracpart=other.fracpart;
     this->intpart=other.intpart;
     this->sign=other.sign;
     return *this;
}
std::ostream& InfiniteArthmetic::operator<<(std::ostream& cp, const Float&obj)
{
    if(obj.sign=='+')
    {
        cp<<removeLeadingZeros(obj.intpart)<<'.'<<obj.fracpart;
    }
    else
    {
           cp<<obj.sign<<removeLeadingZeros(obj.intpart)<<'.'<<obj.fracpart;
    }
    return cp;
}

IF IF::operator+(const Float & other) const
{
 Float tempnum1(*this);
 Float tempnum2(other);
 Float result; 

 set_intpart(tempnum1.intpart,tempnum2.intpart);//appending 0s to allign acc to rules of addition
 set_fracpart(tempnum1.fracpart,tempnum2.fracpart);

 int final_decimal_place_from_back=(tempnum1.fracpart).size();
 //as length of decimal after appending sufficient trailing 0s should not change upon
 //addition

 InfiniteArthmetic::Integer temporary_integer1(tempnum1.intpart+tempnum1.fracpart);
//making number ready for addition
 temporary_integer1.sign=tempnum1.sign;//giving it sign 
 temporary_integer1.length=temporary_integer1.number.size();


 InfiniteArthmetic::Integer temporary_integer2(tempnum2.intpart+tempnum2.fracpart);
 temporary_integer2.sign=tempnum2.sign;
 temporary_integer2.length=temporary_integer2.number.size();

 InfiniteArthmetic::Integer temporary_integer_result=temporary_integer1+temporary_integer2;
//adding them after alligning
 Integer ZERO("0");
 if(temporary_integer_result==ZERO)
 {
  
    temporary_integer_result.sign='+';
    Float temp("0.0");
    return temp;
 }
 Float final_result;
 final_result.intpart="";
 final_result.fracpart="";
 int iterator=0;
//seperating decimal and integer parts from the integer representation based on decimal
//position stored earlier
for(;iterator<no_of_digits(temporary_integer_result)-final_decimal_place_from_back;iterator++)
{
      final_result.intpart+=temporary_integer_result.number[iterator];
}
for(;iterator<no_of_digits(temporary_integer_result);iterator++)
{
    final_result.fracpart+=temporary_integer_result.number[iterator];
}

final_result.sign=temporary_integer_result.sign;//giving final result its sign
final_result.intpart=removeLeadingZeros(final_result.intpart);//removing leading os so that 
//it decreases time consumption in any complex calculation
final_result.decimal_index=final_result.intpart.size();
return final_result;
}
std::istream& InfiniteArthmetic::operator>>(std::istream&ci ,  Float& obj)
{
    std::string temporary;
    std::cin>>temporary;
    Float tempobj(temporary);
    obj=tempobj;
    return ci;

}










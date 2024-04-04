#include "infarth.hh"
#include<iostream>
#include<string>
#include <stdexcept>
InfiniteArthmetic::Integer ZERO("0"); 
///------------------------------------------------------------------------------------
int in(char character)
{
    return int(character);
}


int add(char top,char below)
{
    int value=(top - zero)+(in(below)-zero);
    return value;
}
int remake(std::string&s1,std::string&s2)
{
   
               int lens1=s1.size();
               int lens2=s2.size();
               
               if(lens1>lens2)
               {
                  int diff=lens1-lens2;
                  for(int i=1;i<=diff+1;i++)
                  {
                    s2='0'+s2;
                  }
                  s1='0'+s1;
               }else if(lens1<lens2)
               {
                int diff=lens2-lens1;
                  for(int i=1;i<=diff+1;i++)
                  {
                    s1='0'+s1;
                  }
                  s2='0'+s2;
               }else{
                s1='0'+s1;
                s2='0'+s2;
               }

}
std::string removeLeadingZeros(const std::string& str) 
{   
       
    size_t pos = str.find_first_not_of('0'); // Find the position of the first non-zero digit

    // If there are leading zeros, remove them
    if (pos != std::string::npos) {
        return str.substr(pos); // Extract substring starting from the first non-zero digit
    }

    // If the entire string consists of zeros, return "0"
    return "0";
}

InfiniteArthmetic::Integer InfiniteArthmetic::MagnitudeCompare(const Integer one, const Integer two)
{
  if (one.number.size() > two.number.size())
  {
    return one;
  }
  else if (one.number.size() < two.number.size())
  {
    return two;
  }
  else
  {
    if (one.number > two.number)
    {
      return one;
    }
    else
    {
      return two;
    }
    return one;
  }
 }

//------------------------------------------------------------------------------
using  II=InfiniteArthmetic:: Integer;

II InfiniteArthmetic::Integer::parse(const std::string& s)
 {
          Integer temp(s);
          return temp;
 }

II& II::operator=(const Integer& other)
          {
                   this->sign=other.sign;
                   this->number=other.number;
                   this->length=other.length;
          }

 
II InfiniteArthmetic::compliment(const std::string& number,const std::string& string_for_digits)
{
   //number<=other----------> digits
     std::string temp=number;
     int diff=string_for_digits.size()-number.size();
      for(int i=1;i<=diff;i++)
      {
         temp='0'+temp;
      }
   Integer comp;
   comp.sign='+';
   Integer One("1");
   comp.number="";

       for(int i=0;i<string_for_digits.size();i++)
       {
           comp.number+=(char)('0'+('9'-temp[i]));
       }
      comp=comp+One;
      comp.number=removeLeadingZeros(comp.number);
      comp.length=comp.number.size();
      //std::cout<<comp.number<<std::endl;
       
                     return comp;                             
}






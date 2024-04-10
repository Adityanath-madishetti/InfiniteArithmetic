#include"infarth.hh"
#include<iostream>
#include<stdexcept>
#include<exception>
#include<string>

using II=InfiniteArthmetic::Integer;
using IF=InfiniteArthmetic::Float;

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

IF::Float()
{
    sign = '+';
    intpart = "0";
    fracpart = "0";
    decimal_index = 1;
}

IF::Float(const std::string& obj)
{
       std::string s;
       
       s=removeLeadingZeros(obj);
       //also ensures to fill with "0" if intpart kis empty;
          if(s[0]!='-')
          {
            
            sign = '+';
            intpart="";
            int i=0;
            int decimal_counter=0;
            while(s[i]!='.' and i<s.size())
            {
                 intpart=intpart+s[i];  
                 i++; 
            }
            
            if(s[i]=='.')
            {
                decimal_index=i;
                decimal_counter++;
                i++;

            }
            fracpart="";
            while(i<=s.size()-1)
            {
                fracpart=fracpart+s[i];
                i++;
            }
             if(decimal_counter==0)
             {
                fracpart=fracpart+'0';
                decimal_index=s.size();
             }
          }
          else{
            
            sign='-';
            std::string tempstring=s;
            tempstring.erase(0,1);//this strips negative sign from tempstring
         
            intpart="";
            int i=0;
            int decimal_counter=0;
            while(tempstring[i]!='.' and i<tempstring.size())
            {
                 intpart=intpart+tempstring[i];   
                 i++;
            }
            if(tempstring[i]=='.')
            {
                decimal_index=i;
                decimal_counter++;
                i++;
            }
            fracpart="";
            while(i<=tempstring.size()-1)
            {
                fracpart=fracpart+tempstring[i];
                i++;
            }
             if(decimal_counter==0)
             {
                fracpart=fracpart+'0';
                decimal_index=tempstring.size();
             }
            
          }
}

IF::Float(const Float& other)
{
    this->sign=other.sign;
    this->intpart=other.intpart;
    this->fracpart=other.fracpart;
    this->decimal_index=other.decimal_index;
}



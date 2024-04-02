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

//---------------------------------------------------------------------
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

 


std::ostream& InfiniteArthmetic:: operator<<(std::ostream& cp,const   Integer& other) 
 {
       II temp;
       temp=other;
   //                  size_t pos = other.number.find_first_not_of('0'); 
   //                  // Find the position of the first non-zero digit

   //  // If there are leading zeros, remove them
   //  if (pos == std::string::npos) {
   //    exit(1);
   //      temp.number= other.number.substr(pos); 
   //      //Extract substring starting from the first non-zero digit
   //  }
               

             if(other.sign=='+')
             {
               cp<<temp.number;
               return cp;
             }
             else{
               cp<<other.sign<<temp.number;
               return cp;
             }
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
II InfiniteArthmetic::Integer::operator+(const Integer& other) const 
  {
       std::string num1=number;
       std::string num2=other.number;

          if( this->sign=='+' and other.sign=='+')
      {
                remake(num1,num2);
                //std::cout<<num1<<std::endl<<num2<<std::endl;
                int IndexCounter=num1.size()-1;
                int result[num1.size()];
                int carrier=0;
            for(;IndexCounter>=0;IndexCounter--)
            {
                int figure=add(num1[IndexCounter],num2[IndexCounter]);
                result[IndexCounter]=(figure+carrier)%10;
                carrier=(figure+carrier)/10;
            }
               

               II answer;
                answer.number="";//it has null chracter in it dont worry
               
               answer.sign='+';
                int i;
                if(result[0]==0)
                {
                           i=1;
                }else{
                   i=0;
                }
               
                 for( ;i<num1.size();i++)
                 {
                      //  std::cout<<result[i];
                         answer.number=answer.number+(char)('0'+result[i]);
                     
                 }
               //  std::cout<<std::endl;
               answer.number=removeLeadingZeros(answer.number);
                 answer.length=(answer.number).size();
                // answer.number[num1.size()-1]='\0'; //redundant ,but if some thing goes wrong then uncomment
                // std::cout<<answer<<std::endl;
                //std::cout<<answer.number<<std::endl;
                 return answer;

      }
       else  if(this->sign =='-' and other.sign=='-')
        {
                 II tempnum1(*this) ;
                 II tempnum2(other);
                 tempnum1.sign='+';
                 tempnum2.sign='+';
                 II answer(tempnum1+tempnum2);
                 answer.sign='-';
                 answer.number=removeLeadingZeros(answer.number);
                 answer.length=answer.number.size();
                 return answer ;
        }
        else
        {
          //std::cout<<"hi"<<std::endl;
            II big;
            II small;
            II result;
            
             if(this->number.size()>other.number.size())
             { 
                big=*this;
                small=other;
                          std::cout<<"hi1"<<std::endl;


             }else if(this->number.size()<other.number.size())
             {
                big=other;
                small=*this;
                          //std::cout<<"hi2"<<std::endl;

             }
 /*equal digits  */ else
            {
                 if(this->number>other.number)
                 {
                  big=*this;
                  small=other;
                 }else if(this->number<other.number)
                 {
                   big=other;
                   small=*this;  
                 }else{

                              return Integer("0");
                 }
             }
                II temp1=big;
                temp1.sign='+';
                II temp2=small;
                temp2.sign='+';
               result=temp1-temp2;
              result.sign=big.sign;
              result.number=removeLeadingZeros(result.number);
           result.length=(result.number).size();
              return result;

                          
        }
         

  }


InfiniteArthmetic::Integer II:: operator-(const Integer&other) const 
{
               
              // std::cout<<"i am in"<<std::endl;
               std::cout<<this->sign<<other.sign<<std::endl;
              //return ZERO;
      if(!(other.sign==this->sign))
           {       
                   //   std::cout<<"i am in  diff signs"<<std::endl;
                II  num1=*this;
                II num2=other;
                num1.sign='+';
                num2.sign='+';
                   II result = num1+num2;
                   result.sign=this->sign;
                   result.number=removeLeadingZeros(result.number);
                   return result;
           }
           
      else  if(this->sign=='+' and other.sign=='+')
       {
            //final step before returning is set sign of result
           // std::cout<<"i am in + +"<<std::endl;
              II result;
              II big;
              II small;
            char final_sign;
           if(this->number.size()>other.number.size())
             { 
                big=*this;
                small=other;
                final_sign='+';

             }
            else if(this->number.size()<other.number.size())
             {
                big=other;
                small=*this;
                final_sign='-';
             }
            else
            { 
               
                  if(this->number>other.number)
                 {
                  big=*this;
                  small=other;
                  final_sign='+';
                 }
                 else if(this->number<other.number)
                 {
                   big=other;
                   small=*this;  
                   final_sign='-';
                 }
                 else
                 {
                              return Integer("0");
                 }
           }
          // std::cout<<small.number<<std::endl;
            small=compliment(small.number,big.number);
            big.sign='+';
            small.sign='+';
            result=big+small;
            //std::cout<<result.number<<std::endl;
            //result.number[0]=result.number
            result.sign=final_sign;
            result.number[0]='0';
            result.number=removeLeadingZeros(result.number);
            return result;
           // II new=comp()
      } else
      {
            //  std::cout<<"i am in - -"<<std::endl;
              II result;
              II big;
              II small;
            char final_sign;
           if(this->length>other.length)
             { 
                big=*this;
                small=other;
                final_sign='-';

             }
            else if(this->length<other.length)
             {
                big=other;
                small=*this;
                final_sign='+';
             }
            else
            { 
                  if(this->number>other.number)
                 {
                  big=*this;
                  small=other;
                  final_sign='-';
                 }
                 else if(this->number<other.number)
                 {
                   big=other;
                   small=*this;  
                   final_sign='+';
                 }
                 else
                 {
                              return Integer("0");
                 }
           }
          // std::cout<<small.number<<std::endl;
            small=compliment(small.number,big.number);
            big.sign='+';
            small.sign='+';
            result=big+small;

            //std::cout<<result.number<<std::endl;
            //result.number[0]=result.number
            result.sign=final_sign;
           result.number[0]='0';// you need to remove leading 1 so make it 0 and remove
            result.number=removeLeadingZeros(result.number);
            return result;            
      }
    //  return Integer("0");
}



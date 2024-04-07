#include"infarth.hh"
#include<iostream>
#include<stdexcept>
#include<exception>
#include<string>

using II= InfiniteArthmetic::Integer;
std::ostream& InfiniteArthmetic:: operator<<(std::ostream& cp,const   Integer& other) 
 {
       II temp;
       temp=other;
               

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




bool II::operator>( const Integer& other)
 {
    if(this->sign=='+' and other.sign=='-')
    {
          return true;
    }else if(this->sign=='-' and other.sign=='+')
    {
       return false;
    }
    
    else if( this->sign=='+' and other.sign=='+')
    {
                 if(this->number.size()>other.number.size())
                 {
                  return true;
                 }else if(this->number.size()<other.number.size())
                 {
                  return false;
                 }
                 else
                 {
                              if(this->number>other.number)
                              {
                                return true;
                              }else{
                                false;
                              }
                 }
                 
    }
 }
bool II::operator==( const Integer& other)
 {
                if((this->number==other.number) and (this->sign==other.sign))
                {
                   return true;
                }
                else{
                  return false;
                }
 }

bool II::operator!=( const Integer& other)
 {
     return !(*this==other);
  
 }

  bool II::operator<( const Integer& other)
  {
     return (!((*this==other) or (*this>other)));
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
                }
                else
                {
                   i=0;
                }
               
                 for( ;i<num1.size();i++)
                 {
                     
                         answer.number=answer.number+(char)('0'+result[i]);
                     
                 }
          
                 answer.number=removeLeadingZeros(answer.number);
                 answer.length=(answer.number).size();
                
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
          
            II big;
            II small;
            II result;
            
             if(this->number.size()>other.number.size())
             { 
                big=*this;
                small=other;
                          


             }else if(this->number.size()<other.number.size())
             {
                big=other;
                small=*this;
                          
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
                 }
                 else{

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
               
              
      if(!(other.sign==this->sign))
           {       
                   
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
          
            small=compliment(small.number,big.number);
            big.sign='+';
            small.sign='+';
            result=big+small;
          
            result.sign=final_sign;
            result.number[0]='0';
            result.number=removeLeadingZeros(result.number);
            return result;
          
      } else
      {
           
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
       
            small=compliment(small.number,big.number);
            big.sign='+';
            small.sign='+';
            result=big+small;

            
            result.sign=final_sign;
           result.number[0]='0';// you need to remove leading 1 so make it 0 and remove
            result.number=removeLeadingZeros(result.number);
            return result;            
      }
 
}

InfiniteArthmetic::Integer II::operator*(const Integer& other) const 
{
                       //lets decide sign first
                       char final_sign;
                       if(other.sign==this->sign)
                       {
                         final_sign='+';
                       }else
                       {
                        final_sign='-';
                       }
                           if(other.number=="0" or this->number=="0")
                           {
                              return Integer("0");
                           }
                       //sign decision done
                             //for multiplication run loop from last to index=1
                             //then append the last index o multiplication separately
                      Integer total("0");
                           total.sign='+';
                           total.length=(total.number).size();
                           int zero_counter=0;
                         
                           for(int j=this->number.size()-1;j>=0;j--)
                        {   
                        
                             Integer temp;
                            temp.sign='+';
                            temp.number="";
                           int  carrier=0;
                        
                           for(int i=(other.number).size()-1;i>=1;i--)
                           {     

                                 int figure=((other.number[i]-'0')*(this->number[j]-'0'));
                                 figure+=carrier;
                                 carrier=figure/10;
                                 temp.number=((char)('0'+(figure%10)))+temp.number;
                           }
                         
                               int figure = ((other.number[0]-'0')*(this->number[j]-'0'));
                                figure+=carrier;
                                while(figure!=0)
                                {
                                  int digit=figure%10;
                                  char digit_character=(char)(digit+'0');
                                  temp.number=digit_character+temp.number;
                                  figure/=10;
                                }
                          

                                for(int k=1;k<=zero_counter;k++)
                                {
                              
                                  temp.number=temp.number+'0';
                                }
                                zero_counter++;
                              
                            total=total+temp;
                            total.length=total.number.size();//may be redudant
                        }
                      total.sign=final_sign;
                      total.number=removeLeadingZeros(total.number);
                      total.length=total.number.size();
                      return total;
}
  
std::istream& InfiniteArthmetic::operator>>(std::istream&cp,  Integer&input_object)
  {
    std::string temporary;
      cp>>temporary;
      II temp(temporary);
      input_object=temp;
      return cp;
  } 
  II& II::operator+=(Integer& other)
  {
          *this=*this+other;
          return *this;
  }
  II& II::operator++()
  {
       Integer one("1");
       *this=*this+one;
       this->length=this->number.size();
       return *this;
  }

II II::operator/(const Integer& other)
{
  char finalsign;
  Integer ZERO("0");
  Integer One("1");
  if (!(this->sign == other.sign))
  {
    finalsign = '-';
  }
  else
  {
    finalsign = '+';
  }

  Integer Dividend(*this);
  Integer Divisor(other);
  Dividend.sign='+';
  Divisor.sign='+';


  if (Divisor.number == "0")
  {
    throw std::runtime_error("division by zero is not possible");
  }
  else if (Dividend < Divisor)
  {
    std::cout<<"hi"<<std::endl;
    return ZERO;
  }
  else if (Dividend == Divisor)
  {
    One.sign = finalsign;
    return One;
  }
  
     int  L_I=Dividend.number.size()-1;
     int p_i=0; 
     Integer itm;
     itm.sign='+';
     itm.number="";
     Integer quotient;
     quotient.number="";
     
     while (p_i<=L_I)
     {
             Integer multiplier("0");
             multiplier.sign='+';
             itm.number=itm.number+Dividend.number[p_i];
             itm.sign='+';
             itm.number=removeLeadingZeros(itm.number);
             while(itm>(Divisor*multiplier) or itm==(Divisor*multiplier))
             {
                 multiplier=multiplier+One;
             }
             multiplier=multiplier-One;
             quotient.number=quotient.number+multiplier.number;
             itm=itm-(Divisor*multiplier);
             p_i++;
     }

   quotient.number=removeLeadingZeros(quotient.number);
   quotient.sign=finalsign;
   quotient.length=quotient.number.size();
   return quotient;
}
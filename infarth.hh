#ifndef MY_HEADER
#define MY_HEADER
#include<string>
#include<iostream>
#define zero 48

 
int in(char character);
int add(char top,char below);
int remake(std::string&s1,std::string&s2);
std::string removeLeadingZeros(const std::string& str) ;
namespace InfiniteArthmetic
{
    class Integer
    {
        private:
         char sign;
         std::string number ;
         int length; // not including sign
        public:
           Integer()
           {
             number='0';
             length=1;
             sign='+';
           }

           Integer( const std::string& s)
           {
               
               if(s[0]!='-')
               {
                 sign='+';
                 length=s.size();
                 number=s;
               }else{
                sign='-';
                length=s.size()-1;
                  number=s;
                  number.erase(0,1);
               }
           }

           Integer( const Integer& other)
           {
                   this->sign=other.sign;
                   this->length=other.length;
                   this->number=other.number;       
           }
         friend    Integer compliment(const  std::string&,const std::string&) ;
         friend std::ostream& operator<<(std::ostream&,  const Integer&);
         friend  std::istream& operator>>(std::istream&,  Integer&);

         static  Integer parse(const std::string& s);
         Integer& operator=(const Integer& other);
         Integer operator+(const Integer& other) const;
         Integer operator-(const Integer&other) const ;
         Integer operator*( const Integer& other) const;
         Integer operator/(const Integer& other);
         bool operator>( const Integer& other);
         bool operator<(const Integer& other);
         bool operator!=(const Integer& other);
         bool operator==(const Integer& other);
         int  no_of_digits(const Integer& number);
    
                          
    };
    std::ostream& operator<<(std::ostream&,const  Integer&);
    std::istream& operator>>(std::istream&,  Integer&);
    Integer compliment(const std::string&,const std::string& ) ;

}
#endif
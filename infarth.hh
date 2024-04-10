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
  class Float;
    class Integer
    {
        private:
         char sign;
         std::string number ;
         int length; // not including sign
        public:
           Integer();
           Integer( const std::string& s);
           Integer( const Integer& other);
          
        friend class Float;
         friend Integer compliment(const  std::string&,const std::string&) ;
         friend std::ostream& operator<<(std::ostream&,  const Integer&);
         friend std::istream& operator>>(std::istream&,  Integer&);
         friend Integer MagnitudeCompare(const Integer,const Integer);
         friend  int     no_of_digits( const Integer& );


         static  Integer parse(const std::string& );
         Integer& operator=(const Integer&);
         Integer operator+(const Integer& ) const;
         Integer operator-(const Integer&) const ;
         Integer operator*( const Integer&) const;
         Integer operator/(const Integer& )const;
         bool    operator>( const Integer& )const ;
         bool    operator<(const Integer& )const;
         bool    operator!=(const Integer& )const;
         bool    operator==(const Integer& )const;
         
         Integer& operator+=(Integer& );
         Integer&  operator++();
         
    
                          
    };
    std::ostream& operator<<(std::ostream&,const  Integer&);
    std::istream& operator>>(std::istream&,  Integer&);
    Integer compliment(const std::string&,const std::string& ) ;
    Integer MagnitudeCompare(const Integer,const Integer);
    int     no_of_digits( const Integer& );

        
    class Float
    {
      private :
       char sign;
       std::string  intpart;
       std::string fracpart;
       int decimal_index;

      public:
       Float();
       Float(const std::string &s);
       Float(const Float&other );

       friend std::istream& operator>>(std::istream& ,  Float&);
       friend std::ostream& operator<<(std::ostream&  ,const Float&);

       //operators
      Float& operator=(const Float&); 
      static  Float parse(const std::string& );
      Float operator+(const Float &) const;
    };
    void set_intpart(std::string&  ,std::string& );
    void set_fracpart(std::string&,std::string&);
    std::ostream& operator<<(std::ostream&  ,const Float&);
    std::istream& operator>>(std::istream& ,  Float&);

}
#endif
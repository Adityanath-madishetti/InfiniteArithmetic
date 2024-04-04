#include<iostream>
#include"infarth.hh"
#include<string>

int main()
{
    using  II=InfiniteArthmetic:: Integer;
    // II num1("123");
    // II num2("-0");
    // II num3("1000");
    // std::cout<<num1*num2<<std::endl;
    // std::cout<<num1*num1<<std::endl;
    // std::cout<<num1*num3<<std::endl;
    // II num4;
    // std::cin>>num4;
    // std::cout<<num4<<std::endl;
    // std::cout<<num4+num3<<std::endl;
    II largenum1;
    II largenum2;
    std::cin>>largenum1>>largenum2;
    std::cout<<largenum1+largenum2<<std::endl;
    std::cout<<largenum1*largenum2<<std::endl;
    std::cout<<largenum1-largenum2<<std::endl;
// if(largenum1>largenum2)
// {
//      std::cout<<"num1 is big"<<std::endl;
// }else{

//      std::cout<<"num2 is big"<<std::endl;
// }
// II num1("123");
// II num2("134");
// II num3("-234");
// II num4("-546");
// II num5("123");
// if((num1<num4) and (num2>num3) and (num1==num5))
// {
//          std::cout<<"succesful"<<std::endl;
// }else{
//     std::cout<<"failure"<<std::endl;
// }




}
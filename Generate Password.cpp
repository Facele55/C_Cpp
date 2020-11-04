#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main () {

    srand(time(0));
    char password[]= {'1','2','3','4','5','6','7','8','9','0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','v','u','w','x','y','z',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','V','U','W','X','Y','Z','@','!','_','%','/','$','&','*','+','='};
    
    for (int i=0; i<15; i++)   //length  of password
     cout<<password[rand() % 46];
    cout<<endl;
return 0;
}
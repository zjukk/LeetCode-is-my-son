    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <vector>

    using namespace std;
    
    string intToRoman(int num) {
       string res;
       for (int i = 3; i >=0; i--) {
           int j = num/pow(10,i);
           switch (j){
               case 0:
               break;

           }
       } 
    }
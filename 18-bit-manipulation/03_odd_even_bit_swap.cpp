//Let me explain the code in detail. The code is designed to swap the odd and even bits of an integer.
// maine kya kiya hai ki maine odd bits ko extract kiya hai using the mask 0x55555555 and even bits ko extract kiya hai using the mask 0xAAAAAAAA.
// phir maine odd bits ko left shift kiya hai by 1 position aur even bits ko right shift kiya hai by 1 position. Finally, maine odd bits aur even bits ko bitwise OR kiya hai to get the final result. The code is executed for n times, where n is the number of integers for which we want to perform the odd-even bit swap. The input is taken from the user, and the output is printed to the console.  

//0x55555555 binary -> 01010101010101010101010101010101 saari odd bits set hain aur saari even bits unset hain
//0xAAAAAAAA binary -> 10101010101010101010101010101010 saari even bits set hain aur saari odd bits unset hain



#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int odd_bit = (n & 0x55555555) << 1;
    int even_bit = (n & 0xAAAAAAAA) >> 1;
    int val = odd_bit | even_bit;
    cout<<val<<" "<<endl;

    return 0;    
}
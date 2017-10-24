// Time which is O(No of bits)
#include <iostream>
#include <stdio.h>
using namespace std;
int countBits(int n){
    
    int count=0;
    while(n>0){
        count += (n&1);
        n = n>>1;
    }
    return count;
    
}
int countBitsFast(int n){
    
    int count=0;
    while(n){
        count++;
        n = n & (n-1);
    }
    return count;
}

//XOR swapping 
    a = a^b;
    b = a^b;
    a = a^b;
//Code to get ith Bit, Set ith Bit and Clear ith Bit efficently using masks.
    int getIthBit(int n,int i){
    return (n & (1<<i))!=0?1:0;
}

//Change ith bit of no to 1
void setIthBit(int &n,int i){
    int mask = 1<<i;
    n = (n|mask);
    
}
//Clear the ith bit of no to 0
void clearBit(int &n,int i){
    int mask = ~(1<<i);
    n = n & mask;
}
int main(){
	int n;
    cin>>n;
    int x = countBits(n);
    cout<<x;
}
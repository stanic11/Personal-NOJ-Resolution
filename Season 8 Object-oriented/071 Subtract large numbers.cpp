#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
/*
Write a program to implement number1 - number2.
The number of digits of the two numbers is nearly one hundred. 
You need to consider the case of positive and negative numbers.
This source is able to be simplified in theoretically.
*/
/*
However,I am lazy xdddd.
You can use some function to simplified the code.
Bug known:The array may be out of bounds while using"for"
*/
using namespace std;
void LargeNumberMinus(string,string);
string AlignDigit(string,string,int,int);

int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    LargeNumberMinus(str1,str2);
    system("pause");
    return 0;    
}

void LargeNumberMinus(string Arr1,string Arr2)
{
    
    int LengthOfArr1 = Arr1.length();
    int LengthOfArr2 = Arr2.length();
    int Maxlength = max(LengthOfArr1,LengthOfArr2);
    int Minlength = min(LengthOfArr1,LengthOfArr2);

    char *res = new char [Maxlength]; //Using array "res" to lay in the result.
    string MaxArray,MinArray;
    
    if(Arr1[0]=='-'&&Arr2[0]=='-')
    {   //While both numbers are negative.
        //Aligning the digit.
        if(LengthOfArr1>LengthOfArr2) Arr2 = AlignDigit(Arr2,Arr1,LengthOfArr2,LengthOfArr1);
        else Arr1 = AlignDigit(Arr1,Arr2,LengthOfArr1,LengthOfArr2);
        //
        if(Arr1.compare(Arr2)>0) MaxArray = Arr1,MinArray = Arr2;
        else MaxArray = Arr2,MinArray = Arr1;
        //
        for(int i = Maxlength-1;i>=0;i--)
        {
            if(MaxArray[i]>=MinArray[i]) res[i] = MaxArray[i]-MinArray[i] + 48;
            else if(MaxArray[i]<MinArray[i]) 
            {
                res[i] = MaxArray[i] + 10 - MinArray[i] + 48;
                MaxArray[i-1] -= 1;
            }
        }
            if(Arr1.compare(Arr2)>0||res[1]=='0') printf("-");
            for(int i = 1;i<Maxlength;i++) printf("%c",res[i]);
    }
    else if(Arr1[0]=='-'&&Arr2[0]!='-') 
    {   //While number one is negatiive and number two is positive.
        //Aligning the digit.
        if(LengthOfArr1 - 1 < LengthOfArr2) Arr1 = AlignDigit(Arr1,Arr2,LengthOfArr1,LengthOfArr2);
        else if (LengthOfArr1 == LengthOfArr2) Arr1 = AlignDigit(Arr1,Arr2,LengthOfArr1,LengthOfArr2);
        else Arr2 = AlignDigit(Arr2,Arr1,LengthOfArr2,LengthOfArr1);
        //
        if(LengthOfArr1==LengthOfArr2) 
        {   
            Arr2.insert(Arr2.begin()+0,1,'0');
            Maxlength++;
        }
        for(int i = Maxlength - 1;i>=0;i--)
        {
            if(Arr1[i]+Arr2[i]-48<='9'&&Arr1[i]+Arr2[i]-48>'0') res[i] = Arr1[i]+Arr2[i] - 48;
            else if(Arr1[i]+Arr2[i]-48>'9')
            {
                res[i] = Arr1[i]+Arr2[i]-48-10;
                res[i-1]++;
            }
        }
        printf("-");
        for(int i = 1;i<Maxlength;i++) printf("%c",res[i]);
    }
    else if(Arr1[0]!='-'&&Arr2[0]=='-') 
    {   //While number one is positive and number two is negative.
        //Aligning the digit.
        if(LengthOfArr1==LengthOfArr2) Arr2[0]='0';
        else if (LengthOfArr1>LengthOfArr2) Arr2=AlignDigit(Arr2,Arr1,Minlength,Maxlength);
        else if (LengthOfArr2>LengthOfArr1) Arr1 = AlignDigit(Arr1,Arr2,Minlength,Maxlength);
        //
        for(int i = Maxlength - 1;i>=0;i--)
        {
            if(Arr1[i]+Arr2[i]-48<='9'&&Arr1[i]+Arr2[i]-48>'0') res[i] = Arr1[i]+Arr2[i] - 48;
            else if(Arr1[i]+Arr2[i]-48>'9')
            {
                res[i] = Arr1[i]+Arr2[i]-48-10;
                res[i-1]++;
            }
        }
        for(int i = 0;i<Maxlength;i++) printf("%c",res[i]);
    }
    else if(Arr1[0]!='-'&&Arr2[0]!='-') 
    {
        //While both numbers are positive.
        if(LengthOfArr1<LengthOfArr2) Arr1 = AlignDigit(Arr1,Arr2,Minlength,Maxlength);
        else Arr2 = AlignDigit(Arr2,Arr1,Minlength,Maxlength);
        //
        if(Arr1.compare(Arr2)>0) MaxArray = Arr1,MinArray = Arr2;
        else MaxArray = Arr2,MinArray = Arr1;
        //
        for(int i = Maxlength-1;i>=0;i--)
        {
            if(MaxArray[i]>=MinArray[i]) res[i] = MaxArray[i]-MinArray[i] + 48;
            else if(MaxArray[i]<MinArray[i]) 
            {
                res[i] = MaxArray[i] + 10 - MinArray[i] + 48;
                MaxArray[i-1] -= 1;
            }
        }
            if(Arr1.compare(Arr2)<0) printf("-");
            for(int i = 0;i<Maxlength;i++) printf("%c",res[i]);
    }
}

string AlignDigit(string Array1,string Array2,int Minlength,int Maxlength)
{
    if(Array1[0]=='-') 
    {
        if(Minlength!=Maxlength) Array1.insert(Array1.begin()+1,Maxlength-Minlength,'0');
        else if(Array2[0]!='-') Array1.insert(Array1.begin()+1,1,'0');
    }
    if(Array1[0]!='-') Array1.insert(Array1.begin()+0,Maxlength-Minlength,'0');
    return Array1;
}

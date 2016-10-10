#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int divisor(int num)
{
    int div=0;
    for (int i=1;i<sqrt(num);i++)
    {
        if(num%i==0)
        {
            div=div+2;
        }
    }
    if (sqrt(num)*sqrt(num)==num)
    {
        div=div+1;
    }
    return div;
}
int main()
{
  //  cout<<divisor(1)<<endl;
    int bulb=4;
    int number=0;
    if (bulb==0)
        cout<<0;
    vector<int> state(bulb,0);
    vector<int>::iterator iter;
    for(int i=0;i<bulb;i++)
    {
        int div=divisor(i+1);
        if(div%2==1)
            number++;
    }
    cout<<number;
}

#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
    int a[4]={0,1,2,3};
    vector<int> nums(a,a+4);
    vector<int>::iterator iterb=nums.begin();
    vector<int>::iterator itere=nums.end();
    int i=0,j=*(itere-1);
    if(nums.size()==0)
        return 110;
    if(nums[i]!=0||j<(nums.size()-1))
    {
        cout<<101<<endl;
        return 0;
    }
    while(i<j-2)
    {
        if((j+i)/2<nums[(j+i)/2])
            j=nums[(j+i)/2];
        else if((j+i)/2==nums[(j+i)/2])
            i=nums[(j+i)/2];
    }
    if(nums[i+1]==j-1)
    {
        cout<<j+1;
        return 0;
    }
    cout<<i<<j<<endl<<(i+j)/2<<endl;
    return 0;
}

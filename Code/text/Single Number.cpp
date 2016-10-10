#include<iostream>
#include<vector>
using namespace std;
int findlocation(int num)
{
  //  return num&(~num + 1);
  int ind=0;
  while(((num&1)==0)&&(ind<8*sizeof(int)))
  {
      num =num >>1;
      ++ind;
  }
  return ind;
}

bool judge(int num, int index)
{
    num=num>>(index);
    return (num & 1);
}
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> num(2,0);
        if(nums.size()<2)
        {
            return num;
        }
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            result^=nums[i];
        }
        int ind=findlocation(result);
        for (int i=0;i<nums.size();i++)
        {
            if(judge(nums[i],ind))
                num[0]^=nums[i];
            else
                num[1]^=nums[i];
        }
        return num;
    }




int main()
{
    vector<int> num;
    int input=1;
    while(input!=0){
        cin>>input;
        num.push_back(input);
    }
    vector<int> res;
    res=singleNumber(num);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<"  ";
    }
    return 0;
}

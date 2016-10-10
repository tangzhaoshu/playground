#include<iostream>
#include<vector>
using namespace std;
unsigned int findlocation(int num)
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

bool judge(int num,unsigned int index)
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

vector<int> singleNumber1(vector<int> nums) {
        vector<int> res(2,0);
        int result = nums[0];
        for(int i=1;i<nums.size();i++){
            result = result^nums[i];
        }
        res[0] = 0;
        res[1] = 0;
        int n = result & (~(result-1));
        for(int i=0;i<nums.size();i++){
            if((n & nums[i])!=0){
                res[0] = res[0] ^ nums[i];
            }else {
                res[1] = res[1] ^ nums[i];
            }
        }
        return res;
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
    res=singleNumber1(num);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<"  ";
    }
    return 0;
}
1193730082,587035181,-814709193,1676831308,-511259610,284593787,-2058511940,1970250135,-814709193,-1435587299,1308886332,-1435587299,1676831308,1403943960,-421534159,-528369977,-2058511940,1636287980,-1874234027,197290672,1976318504,-511259610,1308886332,336663447,1636287980,197290672,1970250135,1976318504,959128864,284593787,-528369977,-1874234027,587035181,-421534159,-786223891,933046536,959112204,336663447,933046536,959112204,1193730082,-786223891

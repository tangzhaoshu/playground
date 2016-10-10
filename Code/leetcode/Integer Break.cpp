#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int number=2;
    vector<int> pronum;
    pronum.push_back(1);
    if (number<2)
    {
        cout<<"ÊäÈë´íÎó"<<endl;
        return 0;
    }
    int rest=number;
    int result=1;
    int flag=1;
    while (rest!=0)
    {
        if(rest==2&&flag==1)
        {
            result=1;
            cout<<result<<endl;
            return 0;
        }
        else if((rest==3||rest==4)&&flag==1)
        {
            rest=rest-2;
            result=result*2;
            flag++;
        }
        else if(flag!=1&&(rest==1||rest==2||rest==4||rest==3))
        {
            result=result*rest;
            cout<<result<<endl;
            return 0;
        }
        else
        {
            rest=rest-3;
            result=result*3;
            flag++;
        }
    }
    return 0;
}

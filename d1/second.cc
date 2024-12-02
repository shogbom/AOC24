#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main()
{
    int in;
    ifstream file("list");
    vector<int> left;
    vector<int> right;
    bool leftcheck = true;

    while (file >> in)
    {
        if (leftcheck)
        {
            left.push_back(in);
            leftcheck = !leftcheck;
        }
        else
        {
            right.push_back(in);
            leftcheck = !leftcheck;
        }
    }
    unsigned int sim{0};
    unsigned int times{0};
    for(unsigned int i{0}; i < left.size(); i++){
        times = 0;
        for(unsigned int k{0}; k < right.size(); k++){
            if(left[i] == right[k]){
                times++;
            }
        }
        sim += left[i] * times;
    }
    cout << sim << endl;
    file.close();
}
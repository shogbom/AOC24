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

    unsigned distance{0};

    while ((!left.empty() && !right.empty()))
    {
        int smallestleft{INT_MAX};
        unsigned int leftpos{0};
        int smallestright{INT_MAX};
        unsigned int rightpos{0};

        for (unsigned int i{0}; i < left.size(); i++)
        {
            if (smallestleft > left[i])
            {
                smallestleft = left[i];
                leftpos = i;
            }
        }

        for (unsigned int i{0}; i < right.size(); i++)
        {
            if (smallestright > right[i])
            {
                smallestright = right[i];
                rightpos = i;
            }
        }

        distance += smallestleft > smallestright ? smallestleft - smallestright : smallestright - smallestleft;
        right.erase(right.begin() + rightpos);                
        left.erase(left.begin() + leftpos);

    }
    cout << distance  << endl;
    file.close();
}
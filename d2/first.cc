#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using std::abs;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::stoi;
using std::string;
using std::vector;
using std::ofstream;
using std::stringstream;

bool safe(vector<int> reps);

int main()
{
    string in;
    ifstream file("list");
    ofstream out("out");
    
    vector<vector<int>> data;

    while (getline(file, in))
    {
        int splitting{0};
        vector<int> temp;
        stringstream splidded(in);
        while(splidded >> splitting){
            temp.push_back(splitting);
        }
        data.push_back(temp);
    }
    
    for(vector<int> kuk : data){
        for(int i : kuk){
            out << i << " ";
        }
        out << endl;
    }



    unsigned int rep{0};
    for (unsigned int y{0}; y < data.size(); y++)
    {
        if (safe(data[y]))
        {
            rep++;
        }
    }
    cout << rep << endl;
    file.close();
}

bool safe(vector<int> reps)
{
    bool increasing{false};
    bool decresing{false};
    for (unsigned int x{0}; (x + 1) < reps.size(); x++)
    {
        int diff = reps[x] - reps[x + 1];
        if ((abs(diff) > 3) || (abs(diff) <= 0))
        {
            return false;
        }
        if (diff > 0)
        {
            increasing = true;
        }
        else if (diff < 0)
        {
            decresing = true;
        }
    }
    if(increasing && decresing){
        return false;
    }
    return true;
}
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

int x(vector<string> , unsigned int x, unsigned int y);



int main()
{
    ifstream file("list");
    string in;
    vector<string> data;

    while(getline(file, in)){
        data.push_back(in);
    }

    int count{0};
    for(unsigned int i{0}; i < data.size(); ++i){
        for(unsigned int ii{0}; ii < data[i].length(); ii++){
            //if((data[i][ii] == 'X') || (data[i][ii] == 'S')){
                count += x(data, i, ii);
            //}
        }
    }
    cout << count << endl;
}

int x(vector<string>, unsigned int x, unsigned int y)
{
    return 0;
}

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
    int counta{0};

    while(getline(file, in)){
        data.push_back(in);
    }

    int count{0};
    for(unsigned int i{0}; i < data.size(); ++i){
        for(unsigned int ii{0}; ii < data[i].length(); ii++){
            if((data[i][ii] == 'A')){
                counta++;
                count += x(data, i, ii);
            }
        }
    }
    cout << counta << endl;
    cout << count << endl;
    file.close();
}

int x(vector<string> data, unsigned int x, unsigned int y)
{
    string temp1{""}, temp2{""};

    if(((x-1) < data.size()) && ((y-1) < data[x-1].length()) && ((x+1) < data.size()) && ((y+1) < data[x+1].length()) && ((y-1) < data[x+1].length()) && ((y+1) < data[x+1].length())){ // readable perfection.
        temp1 += data[x-1][y-1];
        temp1 += data[x][y];
        temp1 += data[x+1][y+1];

        temp2 += data[x - 1][y + 1];
        temp2 += data[x][y];
        temp2 += data[x+1][y-1];
        
    }

    if( ((temp1 == "MAS") || (temp1 == "SAM")) && ((temp2 == "MAS")|| (temp2 == "SAM"))){ // dubble if for ease of debug.

        return 1;
    } else {
        cout << temp1 << endl;
        cout << temp2 << endl;
        cout << x << "  " << y << endl;
        return 0;
    }
}


//1796 e too low. tydligen inte ****.
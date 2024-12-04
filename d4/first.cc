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

int forward(vector<string> , unsigned int x, unsigned int y);
int rightdiag(vector<string> , unsigned int x, unsigned int y);
int leftdiag(vector<string> , unsigned int x, unsigned int y);
int down(vector<string> , unsigned int x, unsigned int y);
int valid(string);


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
            if((data[i][ii] == 'X') || (data[i][ii] == 'S')){
                count += forward(data, i, ii);
                count += rightdiag(data, i, ii);
                count += leftdiag(data, i, ii);
                count += down(data, i, ii);
            }
        }
    }
    cout << count << endl;
    file.close();
}

int forward(vector<string> data, unsigned int x, unsigned int y)
{
    string temp;
    for(unsigned int i{y}; (i < data[x].length()) && (i < 4 + y); i++){
        temp += data[x][i];
    }
    return valid(temp);
}

int rightdiag(vector<string> data, unsigned int x, unsigned int y)
{
    string temp;
    int count{0};
    while((x < data.size()) && (y < data[x].length()) && count < 4){
        temp += data[x][y];
        x++;
        y++;
        count++;
    }

    return valid(temp);
}

int leftdiag(vector<string> data, unsigned int x, unsigned int y)
{
    string temp;
    int count{0};
    while((x < data.size()) && (y < data[x].length()) && count < 4){
        temp += data[x][y];
        x++;
        y--;
        count++;
    }

    return valid(temp);
}

int down(vector<string> data, unsigned int x, unsigned int y)
{
    string temp;
    for(unsigned int i{x}; (i < data.size()) && i < 4 + x; i++){
        temp += data[i][y];
    }
    return valid(temp);
}

int valid(string temp){
    if((temp == "XMAS") || (temp == "SAMX")){
        return 1;
    } else {
        return 0;
    }
}
//2375 för lågt 
//2379 för högt
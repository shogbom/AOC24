#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <regex>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::ofstream;
using std::regex;
using std::regex_replace;
using std::regex_search;
using std::smatch;
using std::stoi;

int execute(string op);

int main(){
    string in;
    ifstream file("list");
    string data;

    while (getline(file, in))
    {
        data.append(in);
    }

    vector<string> splided;
    regex reg(R"(mul\(\d+,\d+\))");
    smatch match;
    match.suffix().first;
    while(regex_search(data, match, reg)){
        for(string k : match){
            splided.push_back(k);
        }
        data = match.suffix().str();
    }

    unsigned int sum{0};
    for(string op : splided){
            sum += execute(op);
    }
    cout << sum << endl;
}

int execute(string op){
        string buildingfirst;
        unsigned int i{4};
        for( ; i < op.size() ; i++){
            if(op[i] != ','){
                buildingfirst += op[i];
            } else {
                i++;
                break;
            }
        }
        string buildingsecond;
        for( ; i < op.size() ; i++){
            if(op[i] != ')'){
                buildingsecond += op[i];
            } else {
                break;
            }
        }
        return stoi(buildingsecond) * stoi(buildingfirst);
}
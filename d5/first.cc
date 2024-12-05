#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isValid(const vector<int> &update, const vector<pair<int, int>> &rules);

int main()
{
    vector<pair<int, int>> rules;
    vector<vector<int>> updates;
    ifstream file("list");
    string line;
    bool readingRules = true;

    while (getline(file, line))
    {
        if (line.empty())
        {
            readingRules = false;
            continue;
        }
        else if (readingRules)
        {
            /*
            bool first;
            int left{0};
            string processing{""};
            for(unsigned int x{0}; x < line.length(); ++x){
                if(first == true){
                    if(line[x] == '|'){
                        left = stoi(processing);
                        first = false;
                        processing = "";
                    } else {
                        processing += line[x];
                    }
                } else{
                    processing += line[x];
                }
            }
            pair<int, int> temp{left, stoi(processing)};
            rules.push_back(temp);
    */
            unsigned int border = line.find('|');
            int x = stoi(line.substr(0, border));
            int y = stoi(line.substr(border + 1));
            pair<int, int> temp{x , y};
            rules.push_back(temp);
    
        }
        else
        {
            vector<int> update;
            stringstream lineStream(line);
            string page;
            while (getline(lineStream, page, ','))
            {
                update.push_back(stoi(page));
            }
            updates.push_back(update);
        }
    }
    file.close();
    int sum{0};
    for (vector<int> update : updates)
    {
        if (isValid(update, rules))
        {
            sum += update[update.size() / 2];
        }
    }
    cout << sum << endl;
}

bool isValid(const vector<int> &update, const vector<pair<int, int>> &rules)
{
    unordered_map<int, int> pagePositions;
    for (unsigned int i = 0; i < update.size(); ++i)
    {
        pagePositions[update[i]] = i;
    }

    for (const auto &rule : rules)
    {
        int x = rule.first;
        int y = rule.second;
        if (pagePositions.count(x) && pagePositions.count(y))
        {
            if (pagePositions[x] >= pagePositions[y])
            {
                return false;
            }
        }
    }

    return true;
}
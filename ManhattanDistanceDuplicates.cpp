#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    string line;
    int rows;
    int distance;
    
    typedef pair<int, int> COORD;
    typedef map<int, vector<COORD>> MAP;
    MAP m;
    
    getline(cin, line);
    stringstream(line) >> rows;
    //cout << rows << "\n";
    
    for(int i=0; i<rows; i++)
    {
        int j=0;

        getline(cin, line);
        
        stringstream sstream(line);
        
        while(!sstream.eof())
        {
            int num;
            sstream >> num;
            //cout << num << " ";
            m[num].push_back({j,i});
            j++;
            sstream >> ws;
        }
        //cout << "\n";
    }
    getline(cin, line);
    stringstream(line) >> distance;
    //cout << distance << "\n";

    for(MAP::iterator it=m.begin(); it!=m.end(); it++)
    {
        vector<COORD> v = it->second;
        
        for(int i=0; i<v.size()-1; i++)
        {
            for(int j=i+1; j<v.size(); j++)
            {
                COORD pt1 = v[i]; 
                COORD pt2 = v[j];
                
                if(abs(v[i].first-v[j].first) + abs(v[i].second-v[j].second) <= distance )
                {
                    cout << "YES";    
                    return 0;
                }
            }
        }
    }
    
    cout << "NO";
    
return 0;
}
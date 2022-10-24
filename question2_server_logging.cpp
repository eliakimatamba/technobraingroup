
/*
Given a server log file with a 1000 lines in the format below, write a function that returns the 10 IP addresses tha accessed
the server the most often.

1657628632, /index.html, 156.34.23.65

It is a csv file.
The first column is a timestamp, the second column is a URL, the third column is the IP address.
The goal is to find the IP addresses that accessed the server the most, regardless of which URL they accessed.

*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/// @brief 
/// This function   returns the number of IP addresses that accessed the server
/// the most recently accessed address of 
void server_most_logger()
{
    
    ifstream in("file.csv");
    string line, ip;
    map<string, int> count;
    int maxCount = 0;
    while (getline(in, line))
    {
        istringstream iss(line);
        getline(iss, line, ',');
        getline(iss, line, ',');
        getline(iss, ip, ',');
        if (++count[ip] > maxCount)
            maxCount = count[ip];
    }
    vector<string> mostIps;
    for (auto &p : count)
        if (p.second == maxCount)
            mostIps.push_back(p.first);
    sort(mostIps.begin(), mostIps.end());
    for (auto &ip : mostIps)
        cout << ip << '\n';
}

int main()
{
    server_most_logger();

    return 0;
}
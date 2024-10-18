/*

Given a server log file with a 1000 lines in the format below, write a function that returns the 10 IP addresses that accessed
the server the most often.

1657628632, /index.html, 156.34.23.65

It is a csv file.
The first column is a timestamp, the second column is a URL, the third column is the IP address.
The goal is to find the IP addresses that accessed the server the most, regardless of which URL they accessed.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Record {
    int timestamp;
    string url;
    string ip;
};

// This function will take a server log file as input and return a vector of the top 10 IP addresses
// that accessed the server the most.
vector<string> getTop10IPs(char* filename) {
    ifstream file(filename);
    vector<Record> records;
    vector<string> top10;
    map<string, int> counts;

    // Parse the CSV file and store the data in the records vector
    string line;
    while (getline(file, line)) {
        Record record;
        int firstComma = line.find(',');
        int secondComma = line.find(',', firstComma + 1);
        record.timestamp = stoi(line.substr(0, firstComma));
        record.url = line.substr(firstComma + 2, secondComma - firstComma - 3);
        record.ip = line.substr(secondComma + 2);
        records.push_back(record);
    }

    // Count the number of times each IP address appears in the records vector
    for (int i = 0; i < records.size(); i++) {
        string ip = records[i].ip;
        if (counts.find(ip) == counts.end()) {
            counts[ip] = 1;
        }
        else {
            counts[ip]++;
        }
    }

    // Sort the counts in reverse order (largest to smallest)
    vector<pair<string, int>> sortedCounts;
    for (auto it = counts.begin(); it != counts.end(); it++) {
        sortedCounts.push_back(make_pair(it->first, it->second));
    }
    sort(sortedCounts.begin(), sortedCounts.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    // Add the top 10 IP addresses to the top10 vector
    for (int i = 0; i < 10; i++) {
        top10.push_back(sortedCounts[i].first);
    }

    return top10;
}

int main() {
    // Test the getTop10IPs function
    vector<string> top10 = getTop10IPs("file.csv");
    for (int i = 0; i < top10.size(); i++) {
        cout << top10[i] << endl;
    }
}

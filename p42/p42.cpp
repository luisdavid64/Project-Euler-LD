#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//Memoize the triangles
vector<int> triangles;
//Calculates a triangle number
void calculateTriangle(int n) {
    triangles[n] = (0.5*n*(n+1));
}

//Parses the file
vector<string> parse(string const contents) {
    vector<string> words;
    string accumulator = "";
    for(int i =0; i < contents.length(); i++) {
        if(contents[i] == ',') {
            words.push_back(accumulator);
            accumulator = "";
            continue;
        }
        if(contents[i] == '\"') {
            continue;
        }
        accumulator += contents[i];
    }
    return words;
}

vector<string> readFile() {

    ifstream fd;
    fd.open("./words.txt");
    string contents;
    if(fd.is_open()) {
        fd >> contents;
        return parse(contents);
    } else {
        cerr << "Error: File not found";
    }
}

/*Calculates the integer value of string
  Investigate if there is a reduce function
*/
int wordVal(string const str) {
    int val = 0;
    for(char c : str) {
        val += c - 'A' + 1;
    }
    return val;
}

int solve() {
    vector<string> words = readFile();
    int max = 0;
    int count = 0;
    for(int i =0; i<=20; i++) {
        triangles.push_back(0);
    }
    for(auto const &word : words) {
        int num = wordVal(word); 
        int i = 0;
        while(num > triangles[i]) {
            if(i > max) {
                calculateTriangle(i);
                max++;
            } else {
                i++;
            }
        }
        if(num == triangles[i]) {
            count+= 1;
        }
    }

    return count;
}

int main() {
    cout << solve() << endl;
    return 0;
}
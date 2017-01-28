#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class VersionCompare {
public:
    int compareVersion(string version1, string version2){
        float v1 = stof(version1);
        float v2 = stof(version2);
        if (v1 < v2) return -1;
        else if (v1 > v2) return 1;
        else return 0;
    }
};


int main (int argc, const char* argv[]){
    cout << "compare version output" << (VersionCompare()).compareVersion("1.2", "2.1") << "\n";
    return 0;
}

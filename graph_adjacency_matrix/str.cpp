#include <iostream> 
#include <sstream> 
using namespace std;

int main()
{
    int num = 10;
    string word = "hello";
    ostringstream oss;
    oss << num << " " << word;
    string result = oss.str();
    cout << result << endl;
    return 0;
}

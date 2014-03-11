#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string buf;
void push(int a) {

}
int main(int argc, char const *argv[]) {
    getline(cin,buf);
    istringstream strIn(buf);
    int a;
    while (strIn >> a) {
        push(a);
    }
    return 0;
}
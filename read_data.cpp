#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

auto read_ints(string filename)
{
    ifstream input(filename, ifstream::binary);
    vector<int> out;
    int i;

    while(input.read(reinterpret_cast<char*>(&i), sizeof(int)))
        out.push_back(i);

    return out;
}

int main(){
    auto v = read_ints("D:\\shlday\\sh600000.day");
    cout << "Read " << v.size() << "ints: " << endl;

    int x = 0;
    float f = 0;
    for(int i = 0; i < v.size(); ++i){
        int j = i-5;
        if( (j > 0) && (j % 8 == 0)){ // float number
            f = v[i];
            cout << "float: " << f << endl;
        } 
        else{
            x = v[i];
            cout << "int: " << x << endl;
        }
    }
    

    return 0;
}




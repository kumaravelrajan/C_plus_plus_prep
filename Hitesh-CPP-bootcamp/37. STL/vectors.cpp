#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {

    vector<int> int_vector; 
    vector<string> string_vector = {"apple", "orange", "tiger", "lion"};

    int_vector.push_back(1);
    int_vector.push_back(2);
    int_vector.push_back(3);
    int_vector.push_back(4);
    int_vector.push_back(5);

    for(int i = 6; i < 10; ++i){
        int_vector.push_back(i);
    }

    cout << "int_vector.size() = " << int_vector.size() << endl;
    cout << "int_vector.capacity() = " << int_vector.capacity() << endl;
    cout << "int_vector.max_size() = " << int_vector.max_size() << endl;
    cout << "int_vector.empty() = " << int_vector.empty() << endl;

    cout << "int_vector = ";

    for(int num : int_vector){
        cout << num << " ";
    }

    cout << endl;



	return 0;

}
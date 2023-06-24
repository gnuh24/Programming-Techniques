#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("strE.txt"); // Thay "filename.txt" bằng tên file của bạn
    int count = 0;
    string line;

    while (getline(file, line)) {
        count++;
    }

    cout << "Số dòng trong file là: " << count << endl;

    file.close();
    return 0;
}
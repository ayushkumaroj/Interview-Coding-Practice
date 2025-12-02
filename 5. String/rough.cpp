#include<iostream>
using namespace std;
#include<sstream>
#include<string>

int main(){
    string bio = "My name is Ayush Kumar";
    stringstream ss(bio);
    string token;

    while(ss >> token){
        cout<<token<<" "<<endl;
    }
}
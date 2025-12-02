#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

bool ValidAnagram(string s, string t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if(s == t){
        return true;
    }else{
        return false;
    }
}
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>

int stringPair(vector<string>&arr){
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n-1; i++){
        string word = arr[i];
        reverse(word.begin(), word.end());

        for(int j=i+1; j<n; j++){
            if(arr[j] == word){
                count++;
            }
        }
    }

    return count;
}

int stringPair(vector<string>&arr){
    int n = arr.size();
    int count = 0;

    unordered_set<string>s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    for(int i=0; i<n; i++){
        string word = arr[i];
        reverse(word.begin(), word.end());

        if(word == arr[i]){
            continue;
        }

        if(s.find(word) != s.end()){
            count++;
            s.erase(arr[i]);
        }
    }

}

int stringPair(vector<string>&arr){
    int n = arr.size();
    int count = 0;

    unordered_set<string>s;
    for(int i=0; i<n; i++){
        string word = arr[i];
        reverse(word.begin(), word.end());

        if(s.find(word) != s.end()){
            count++;
        }
        else{
            s.insert(arr[i]);
        }
    }

    return count;
}
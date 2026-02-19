#include<iostream>
using namespace std;
#include<vector>

void generatePermutations(string currentPermutation, vector<char>&characters, vector<int>&frequency, int totalLength){
    //Step 1: If Permutation is complete print it
    if(currentPermutation.length() == totalLength){
        cout<<currentPermutation<<endl;
        return;
    }

    //step 2: Try each character in lexicographiccal Ordeer
    for(int i=0; i<characters.size(); i++){
        //Step 3: Check if this character is still valid
        if(frequency[i] > 0){
            //step 4: use this character
            frequency[i]--;

            generatePermutations(
                currentPermutation + characters[i],
                characters,
                frequency,
                totalLength
            );

            //Backtrack
            frequency[i]++;
        }
    }
}

int main(){
    string inputString;
    cout<<"Enter Input String: ";
    cin>>inputString;

    vector<char>characters;
    vector<int>frequency;

    for(int i=0; i<inputString.size(); i++){
        if( i == 0 || inputString[i] != inputString[i-1]){
            characters.push_back(inputString[i]);
            frequency.push_back(1);
        }
        else{
            frequency.back();
            frequency[frequency.size()-1]++;
        }
    }

    generatePermutations(
        "",
        characters,
        frequency,
        inputString.length()
    );

    return 0;
}
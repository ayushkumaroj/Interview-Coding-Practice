#include<iostream>
using namespace std;

void generateString(string currentString, int currentLength, int totalLength, int usedA, int usedB, int usedC, int maxA, int maxB, int maxC){
    if(currentLength == totalLength){
        cout<<currentString<<endl;
        return;
    }

    if(usedA < maxA){
        generateString(currentString+'A', currentLength+1, totalLength, usedA+1, usedB, usedC, maxA, maxB, maxC);
    }

    if(usedB < maxB){
        generateString(currentString+'B', currentLength+1, totalLength, usedA, usedB+1, usedC, maxA, maxB, maxC);
    }

    if(usedC < maxC){
        generateString(currentString+'C', currentLength+1, totalLength, usedA, usedB, usedC+1, maxA, maxB, maxC);
    }
}


int main(){
    int stringLength;
    int maxA, maxB, maxC;

    cout<<"Enter String Length: ";
    cin>>stringLength;
    cout<<"Enter max value of A,B,C: ";
    cin>> maxA >> maxB >> maxC;

    generateString("",0,stringLength,0,0,0,maxA,maxB,maxC);
    return 0;
}
#include<iostream>
using namespace std;
#include<vector>

void arrangeBalls(
    string currentArrangement,
    int usedA, 
    int usedB,
    int usedC,
    int totalA,
    int totalB,
    int totalC,
    char lastBall
){
    //step1: If all balls are used, print arrangement
    if(usedA == totalA && usedB == totalB && usedC == totalC){
        cout<<currentArrangement<<endl;
        return;
    }

    //Step 2: Try to place 'A'
    if(usedA < totalA){
        if(lastBall != 'A'){
            arrangeBalls(
            currentArrangement + 'A',
            usedA+1,
            usedB,
            usedC,
            totalA,
            totalB,
            totalC,
            'A'
            );
        }
    }

    // Step 3: Try to place 'B'
    if(usedB < totalB){
        if(lastBall != 'B'){
            arrangeBalls(
            currentArrangement+'B',
            usedA,
            usedB+1,
            usedC,
            totalA,
            totalB,
            totalC,
            'B'
            );
        }
    }

    //Step 4: Try to place 'C'
    if(usedC < totalC){
        if(lastBall != 'C'){
            arrangeBalls(
                currentArrangement+'C',
                usedA,
                usedB,
                usedC+1,
                totalA,
                totalB,
                totalC,
                'C'
            );
        }
    }
}


int main(){
    int countA;
    int countB;
    int countC;
    cout<<"Enter count value of A,B,C: ";
    cin>>countA >> countB >> countC;

    arrangeBalls(
        "", //Empty arrangement
        0,0,0, //used A,B,C
        countA,
        countB,
        countC,
        '#' //No previous balls

    );

    return 0;
}
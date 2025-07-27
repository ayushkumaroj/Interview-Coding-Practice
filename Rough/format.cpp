#include<iostream>
using namespace std;
#include<vector>

int RainWaterTrap(vector<int>height){
    int n = height.size();
    int trappedWater = 0;
    
    for(int i=0; i<n; i++){

        int leftMaxLine = 0;
        for(int j=0; j<=i; j++){
            leftMaxLine = max(leftMaxLine, height[j]);
        }

        int rightMaxLine = 0;
        for(int j=i; j<n; j++){
            rightMaxLine = max(rightMaxLine, height[j]);
        }

        int minHeight = min(leftMaxLine, rightMaxLine);
        trappedWater = trappedWater + (minHeight - height[i]);
        cout<<"The trapped water is: "<<" "<<trappedWater<<endl;

    }

    cout<<trappedWater;

}

int main(){
    vector<int>height{4,2,0,3,2,5};
    
    
    
    RainWaterTrap(height);
}
#include<iostream>
#include<vector>
using namespace std;
vector<int> arregloPrimos(){
    vector<int> arrPrimos;
    arrPrimos.push_back(2);
    for(int i = 3; i<10000;i++){
        for(int j = 0;j<arrPrimos.size();j++){
            if(i%arrPrimos[j] == 0){
                break;
            }
            if(j==arrPrimos.size()-1){
                arrPrimos.push_back(i);
            }
        }
    }
    return arrPrimos;
}
int main(){
    int n;
    vector<int> arrPrimos = arregloPrimos();
    while (true)
    {
        cin>>n;
        if(n == 0) break;
        int total = 0, cantPermutacion=0;
        for (size_t j = 0; j < arrPrimos.size(); j++)
        {
            int i = j;
            total = 0;
            while(i<arrPrimos.size()){
                total+=arrPrimos[i];
                if(total==n){
                    total = 0;
                    cantPermutacion++;
                    break;
                }
                if(total>n){
                    total = 0;
                    break;
                }
                i++;
            }
        }
        cout<<cantPermutacion<<endl;
        
    }
    
    return 0;
}
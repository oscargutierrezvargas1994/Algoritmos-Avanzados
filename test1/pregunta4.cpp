#include<iostream>
#include<vector>
using namespace std;
vector<int> arregloPrimos(){
    vector<int> arrPrimos;
    arrPrimos.push_back(2);
    for(int i = 3; i<100000;i++){
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

int metodoMatematico(int n,vector<int> lista){
    int ultimo=1,cant = 0;
    vector<int> aux;
    for(int i = 0;i<lista.size();i++){
        int tmp = lista[i];
        if(n==1){
            break;
        }
        if(n%tmp==0){
            n/=tmp;
            if(ultimo == tmp){
                cant++;
                i--;
            }else{
                aux.push_back(cant+1);
                ultimo = tmp;
                cant = 1;
                i--;
            }
        }
    }
    aux.push_back(cant+1);
    int total=1;
    for (size_t i = 0; i < aux.size(); i++)
    {
        total*=aux[i];
    }
    return total;
}


int getCantDivisores(int n){
    int x = 0;
    for(int i=1;i<=n;i++){
        if(n%i == 0){
            x++;
        }
    }
    return x;
}
int main(){
    int numCasos,limiteInf,limiteSup;
    cin>>numCasos;
    vector<int> primos = arregloPrimos();
    // metodoMatematico(1000,primos);
    while (numCasos-->0)
    {
        cin>>limiteInf>>limiteSup;
        int maxDivisores = 0;
        int numero = 0;
        for(int i = limiteInf;i<=limiteSup;i++){
            int tmpDiv = metodoMatematico(i,primos);
            if(tmpDiv>maxDivisores){
                numero = i;
                maxDivisores = tmpDiv;
            }
        }
        cout<<"Between "<<limiteInf<<" and "<<limiteSup<<", "<<numero<<" has a maximum of "<<maxDivisores<<" divisors."<<endl;
    }
    
    return 0;
}
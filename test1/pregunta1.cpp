#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;
vector<string> miSplit(string a,char lim){
    vector<string> lista;
    string aux="";
    for (size_t i = 0; i < a.length(); i++){
        char tmp = a[i];
        if(tmp == lim){
            lista.push_back(aux);
            aux = "";
        }else{
            aux+=tmp;
        } 
    }
    lista.push_back(aux);
    return lista;
}

// int reducir(int nominador,int denominador){
// 	if(denominador==1){
// 		cout <<nominador<<"/"<<denominador;
// 	}else{
// 	int b=2;
// 	while(b<=nominador){
// 		if(denominador%b==0 && nominador%b==0){
// 			denominador=denominador/b;
// 			nominador=nominador/b;
// 		}else{
// 		b++;
// 		}
// 	}
// 	cout << nominador << "/"<<denominador<<endl;
// 	}
// 	return 0;
// }

int mcd(int a,int b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int main(){
    int j,cont=1;
    while (true)
    {
        cin>>j;
        if(j == -1){
            break;
        }
        string aux;
        cin>>aux;
        vector<string> prueba = miSplit(aux,'.');
        int k = prueba[1].length() - j;
        string x = "0.";
        x +=prueba[1];
        double decimal = stof(x);
        double a = pow(10,k+j)*(decimal);
        double b = pow(10,k)*decimal;
        int numerador = round(a-b);
        int denominador = pow(10,k+j) - pow(10,k);
        int res = mcd(numerador,denominador);
        numerador/=res;
        denominador/=res;
        cout<<"Case "<<cont<<": "<<numerador<<"/"<<denominador<<endl;
        cont++;
    }
    return 0;
}
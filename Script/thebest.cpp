// Primero compilarlo con:
//   g++ -std=c++11 -o cargar cargar.cpp


#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//void mostrar_fitness(double vector[60000],int ejecuciones);
void cargar_fitness(double fitness[10000][30], std::string archivo,int ejecuciones, int k);
void guardarFitnessProm(double fitnessProm[10000][30], int ejecuciones, int k);
void mejorfitness(double fitness[10000][30], int k);

int main(){
    double fitnessProm[60000];
    int n;
    int ejecuciones;
    std::string gen, ext=".xg", archivo;

    std::cout << "Ingresar nombre del documento, sin extension"<< std::endl;
    std::cin >> gen;

    std::cout << "Ingresar cantidad de documentos"<< std::endl;
    std::cin >> n;

    std::cout << "Ingresar cantidad de generaciones"<< std::endl;
    std::cin >> ejecuciones;

    double fitness[10000][30];

    // //for(int i=0;i<ejecuciones;i++) fitnessProm[i]=0;
        for(int i=0;i<ejecuciones;i++){
            for(int j=0; j < n ; j++){
                fitness[i][j]=0;
            }
        }

    for(int k=1;k<n+1;k++){
        archivo=gen+std::to_string(k)+ext;
        //std::cout << archivo << std::endl;
        cargar_fitness(fitness,archivo, ejecuciones, k);
    }


    mejorfitness(fitness, n);
    //mostrar_fitness(fitnessProm, ejecuciones);
    //guardarFitnessProm(fitness, ejecuciones, n);

    return 0;
}

void cargar_fitness(double fitness[10000][30], std::string archivo, int ejecuciones, int k){
    std::fstream fin;
    double x,y,z,l,m;
    fin.open(archivo.c_str());
    for(int j=0;j<ejecuciones;j++){
        fin >> x >> y >> fitness[j][k-1] >> l >> m;
        //std::cout << fitness[j][k-1]<<std::endl;
    }
    fin.close();
}

void mostrar_fitness(double fitnessProm[60000],int ejecuciones){
    for(int i=0;i<ejecuciones;i++){
        std::cout << fitnessProm[i]<<std::endl;
    }
}
void guardarFitnessProm(double fitnessProm[10000][30], int ejecuciones, int k){
    std::fstream fout;
    fout.open("FitnessMatriz.txt", std::ios::out);

    for(int i=0;i<ejecuciones;i++){
        for(int j=0; j<k; j++){
                fout<< fitnessProm[i][j]<< " ";
        }
    fout<< std::endl;
    }
    fout.close();
}

void mejorfitness(double fitness[10000][30], int k){
    double mejorvalor;
    int stats;
    mejorvalor = fitness[0][0];
    for(int i=0 ; i < k; i++){
        if(fitness[9999][i]< mejorvalor) {
            mejorvalor=fitness[9999][i];
            stats = i;    
        }
    }
    std::cout<<"El mejor valor es: "<< mejorvalor << std::endl;
    std::cout<<"Y corresponde al archivo: "<< stats+1 << std::endl;
}

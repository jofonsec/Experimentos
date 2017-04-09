// Primero compilarlo con:
//   g++ -std=c++11 -o cargar cargar.cpp


#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void mostrar_fitness(double vector[60000],int ejecuciones);
void cargar_fitness(double fitness[60000], std::string archivo,int ejecuciones);
void guardarFitnessProm(double fitnessProm[60000],int ejecuciones);

int main(){
    double fitnessProm[60000];
    int n;
    int ejecuciones;
    std::string gen, ext=".xg", archivo;
    double fitness[60000];

    std::cout << "Ingresar nombre del documento, sin extension"<< std::endl;
    std::cin >> gen;

    std::cout << "Ingresar cantidad de documentos a promediar"<< std::endl;
    std::cin >> n;

    std::cout << "Ingresar cantidad de generaciones"<< std::endl;
    std::cin >> ejecuciones;


    for(int i=0;i<ejecuciones;i++) fitnessProm[i]=0;

    for(int k=1;k<n+1;k++){
    archivo=gen+std::to_string(k)+ext;
    //std::cout << archivo << std::endl;

    for(int j=0;j<ejecuciones;j++){fitness[j]=0;}

    cargar_fitness(fitness,archivo, ejecuciones);

    for(int i=0;i<ejecuciones;i++) {fitnessProm[i] = fitnessProm[i] + fitness[i];}
    }

    for(int i=0;i<ejecuciones;i++) {fitnessProm[i] = fitnessProm[i]/n;}

    mostrar_fitness(fitnessProm, ejecuciones);
    guardarFitnessProm(fitnessProm, ejecuciones);

    return 0;
}

void cargar_fitness(double fitness[60000], std::string archivo, int ejecuciones){
    std::fstream fin;
    double x,y,z,l,m;
    fin.open(archivo.c_str());
    for(int j=0;j<ejecuciones;j++){
        fin >> x >> y >> fitness[j] >> l >> m;
        //std::cout << fitness[j]<<std::endl;
    }
    fin.close();
}

void mostrar_fitness(double fitnessProm[60000],int ejecuciones){
    for(int i=0;i<ejecuciones;i++){
        std::cout << fitnessProm[i]<<std::endl;
    }
}
void guardarFitnessProm(double fitnessProm[60000], int ejecuciones){
    std::fstream fout;
    fout.open("FitnessProm.txt", std::ios::out);

    for(int i=0;i<ejecuciones;i++){
    fout<< fitnessProm[i]<< std::endl;
    }
    fout.close();
}

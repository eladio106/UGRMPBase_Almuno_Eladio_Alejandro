/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/** 
 * @file Kmer.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 24 October 2023, 14:00
 */
#include <string>
#include "Kmer.h"
    
using namespace std;

//Constructor por parámetros que construye un objeto de longitud k
//Con los MISSING_NUCLEOTIDE

Kmer::Kmer(int k){

    if(k<=0){
        throw invalid_argument(string("Kmer(int k): ") + 
                    "invalid length" + tostring(k));
    }
    this ->_text=string(k,MISSING_NUCELOTIDE)
}

//Constructor por parámetros que construye un objeto mediante el paso de un string
Kmer::Kmer(const string& text){
    
    if(text.size()<1){
        throw invalid_argument(string("Kmer(int k): ") + 
                    "invalid length" + tostring(k));
    }
    this ->_text=string(text.size()),text)
}


//Método que use el metodo creado dentro de nuestro sistema llamado size()
int Kmer::getK() const {
    
    return size();
}

//Método que use el metoro creado dentro de nuestro sistema llamado size()
int Kmer::size() const {
    
    return _text.size();
}

//Método típico toString() que devuelve una cadena
string Kmer::toString() const{
    string 
    return ;
}

//Método típico que devuelve una posición de la cadena _text de nuestro objeto kmer
//Protegido
const char& Kmer::at(int index) const{

    if(index<0||index>k-1){
        throw out_of_range(string("Kmer(int index): ") + 
                    "invalid position" + tostring(index));
    }


}


/**
     * @brief Gets a reference to the character (nucleotide) at the given 
     * position.
     * Modifier method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * index is not in the range from 0 to k-1 (both included).
     * @return A reference to the character at the given position
     */
    char& at(int index);
 

//Método típico que devuelve una posición de la cadena _text de nuestro objeto kmer
//Protegido
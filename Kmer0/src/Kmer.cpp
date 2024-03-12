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

//Método que use el metodo creado dentro de nuestro sistema llamado size()
int Kmer::size() const {
    
    return _text.size();
}

//Método típico toString() que devuelve una cadena
string Kmer::toString() const{
    
    string _kmer;
    
    _kmer = _text;
    return _kmer;
}

//Método típico que devuelve una posición de la cadena _text de nuestro objeto kmer
//Protegido
const char& Kmer::at(int index) const{

    if(index<0||index>k-1){
        throw out_of_range(string("Kmer(int index): ") + 
                    "invalid position" + tostring(index));
    }

    return text[index];
}

//Método típico que devuelve una posición de la cadena _text de nuestro objeto kmer
//Sin proteger

    char& at(int index){

        if(index<0||index>k-1){
            throw out_of_range(string("Kmer(int index): ") + 
                       "invalid position" + tostring(index));
        }

        return _text[index];
    };
 
//Método que normaliza el string de kmer que ya teniamos
    void normalize(const std::string& validNucleotides){
        bool correct=false;
        toupper(_text[]);
        
        
        for(int i=0; i<size();i++) {
            if(IsValidNucleotide(_text[i],nucleotides){
                for(int j=0; j<size();j++){
                    if(_text[i]==validNucleotides[j]){
                        correct=true;
                    }
                }
            if(!correct) _text[i]=MISSING_NUCELOTIDE;
            correct=false;
        }
    };

    
//Método que devuelve complementario el string de kmer que ya teniamos (normalizado)
    Kmer complementary(const string& nucleotides, const string& complementaryNucleotides) const{
        
         if(nucleotides.size()!=complementaryNucleotides.size()){
        throw out_of_range(string("Kmer(nucleotides.size()): ") + 
                    "invalid inputs size" + tostring(complementaryNucleotides.size()));
    }
         
         Kmer kmer_complementary(size());
         
        for(int i=0; i<size();i++) {
            if(IsValidNucleotide(_text[i],nucleotides)){
                for(int j=0; j<size();j++){
                    if(_text[i]==nucleotides[j]){
                        kmer_complementary[i]=complementaryNucleotides[j];
                    }
                }
        }
        
        return kmer_complementary[];
    };
    
    
 bool IsValidNucleotide(char nucleotide, const std::string& validNucleotides){
    bool valid=false;
    
        for(int i=0; i<size();i++){
            if(nucleotide==validNucleotides[i]){
                correct=true;
            }
        }
    
    return valid; 
 };
    
//Metodo que convierte los nucleotidos en minúscula a mayúscula
void ToUpper(Kmer& kmer){
    toupper(kmer);
    
};

//Metodo que convierte los nucleotidos en mayúscula a minúscula
void ToLower(Kmer& kmer){
    tolower(kmer);
    
};
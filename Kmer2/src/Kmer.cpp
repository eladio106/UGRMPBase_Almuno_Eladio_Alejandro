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

#include "Kmer.h"
    
using namespace std;

//Constructor por parámetros que construye un objeto de longitud k
//Con los MISSING_NUCLEOTIDE

Kmer::Kmer(int k){
    if (k<=0){
        throw invalid_argument(string("Kmer (int k): invalid length"));
    }  
        this -> _text = string (k, MISSING_NUCLEOTIDE);
    
}

//Constructor por parámetros que construye un objeto mediante el paso de un string
Kmer::Kmer(const string& text){
    if (text.size()<1)
        throw invalid_argument(string("Kmer (const string& text) :invalid text length"));
    this ->_text = text;
}


 //Método que use el metodo creado dentro de nuestro sistema llamado size()
int Kmer::getK() const { 
    return size();
}   

//Método que devuelve la longitud de los kmers
int Kmer::size() const {
    return _text.size();
}

//Método típico toString() que devuelve una cadena
string Kmer::toString() const{
    return this->_text;
}


//Método típico que devuelve una posición de la cadena _text de nuestro objeto kmer
//Protegido
const char& Kmer::at(int index) const{

    if(index<0||index>_text.size()-1){
        throw out_of_range(string("Kmer(int index): invalid position"));
    }
    
    const char k = _text[index];
    return k;
}

//Método típico que devuelve una posición de la cadena _text de nuestro objeto kmer
//Sin proteger 
    char& Kmer::at(int index){
        if(index<0||index> _text.size()-1){
            throw out_of_range(string("Kmer(int index): invalid position"));
        }

        return _text[index];
    };
    
    void Kmer::toUpper(){
       for (int i=0; i<this->_text.size(); i++)
        putchar(toupper(this->_text[i]));
        
    }
    
    void Kmer::toLower(){
        for (int i=0; i<this->_text.size(); i++)
        putchar(tolower(this->_text[i]));
        
    }
    
//Método que normaliza el string de kmer que ya teniamos
    void Kmer::normalize(const std::string& validNucleotides){
        bool correct = false;
        toUpper();
        
        
        for(int i=0; i<size(); i++){
            if(IsValidNucleotide(this->_text[i], validNucleotides)){
                for(int j=0; j<size();j++){
                    if(this->_text[i]==validNucleotides[j]){
                        correct=true;
                    }
                }
            if(!correct) this->_text[i]= MISSING_NUCLEOTIDE;
            correct=false;
            }
        }
    }
    
    
    Kmer Kmer::complementary(const string& nucleotides, 
                     const string& complementaryNucleotides) const{
    
        if(nucleotides.size()!=complementaryNucleotides.size()){
            throw out_of_range(string("Kmer(nucleotides.size()): invalid inputs size"));
        }
        
        //Construimos un kmer complementario que será el que hagamos complementario
        Kmer kmer_complementary;
        //kmer_complementary((int)_text.size());
         
        for(int i=0; i<this->_text.size();i++) {
            if(IsValidNucleotide(this->_text[i],nucleotides)){
                for(int j=0; j<nucleotides.size();j++){
                    if(this->_text[i]==nucleotides[j]){
                        kmer_complementary.at(i)=complementaryNucleotides[j];
                    }
                }
            }
        }
        return kmer_complementary;
    }
    
    bool IsValidNucleotide(char nucleotide, const std::string& validNucleotides){
    bool valid=false;
    
        for(int i=0; i<validNucleotides.size();i++){
            if(nucleotide==validNucleotides[i]){
                valid=true;
            }
        }
    
    return valid; 
 }
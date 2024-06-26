/*
 * Metodología de la Programación: Kmer1
 * Curso 2023/2024
 */

/** 
 * @file KmerFreq.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 27 de octubre de 2023, 11:03
 */

#include "KmerFreq.h"

using namespace std;

KmerFreq::KmerFreq(){
    _kmer;       
    _frequency=0;
    
}

Kmer KmerFreq::getKmer(){
    
    return this->_kmer;
}

int KmerFreq::getFrequency(){
    
    return this->_frequency;
}


void KmerFreq::setKmer(Kmer kmer){
    
    this->_kmer = kmer;
}

void KmerFreq::setFrequency(int frequency){
    if(frequency<0){
        throw invalid_argument(string("Frequency: invalid number" + frequency));
    }
        this->_frequency = frequency;
    
}

string KmerFreq::toString(){
    string result;
    
    result = this->_kmer.toString() + " " + string(_frequency);
    
    return result;
    
}
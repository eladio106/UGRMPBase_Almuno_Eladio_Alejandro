/*
 * Metodología de la Programación: Kmer2
 * Curso 2023/2024
 */

/** 
 * @file Profile.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */


#include "Profile.h"

using namespace std;

const string Profile::MAGIC_STRING_T="MP-KMER-T-1.0";

Profile::Profile(){
    
    this ->_profileId = "unknown"
    this ->_vectorKmerFreq[0].setKmer(2);  
    this ->_size++;
}

Profile::Profile(int size){
    
    if(size<0||size>DIM_VECTOR_KMER_FREQ)
        throw out_of_range(string("Kmer(int index): invalid size"));
       
    this ->_profileId = "unknown";
    
    for(int i=0; i<size; i++){
        this ->_vectorKmerFreq[i].setKmer(Kmer(2));  
    }
    this-> _size = size;
}

string Profile::getProfileId() const{
    return this->& _profileId;
}

void Profile::setProfileId(string id){
    this->_profileId = id;
    
}

const KmerFreq Profile::at(int index) const{

    if(index<0|| index>this->_size){
        throw out_of_range(string("Kmer(int index): invalid position"));
    }
    
    const KmerFreq k = _vectorKmerFreq[index];
    return KmerFreq;
}

KmerFreq Profile::at(int index){
        if(index<0||index> this->_size){
            throw out_of_range(string("Kmer(int index): invalid position"));
        }

        return this->_vectorKmerFreq[index];
    };
    
int Profile::getSize(){
    return this->_size;
}

static const int Profile::getCapacity(){
    return this->DIM_VECTOR_KMER_FREQ;
}

int Profile::findKmer(Kmer kmer, int initialPos, int finalPos){
    int resultado=-1;
    for (int i = initialPos; i <= finalPos; ++i) {
        if (this->_vectorKmerFreq.getKmer().toString() == kmer.toString()) {
            resultado=i;
            i=finalPos;
        }
    }
    return resultado;
}

int Profile::findKmer(Kmer kmer){
    int resultado=-1;
    for (int i = 0; i <= this->_vectorKmerFreq[0].getKmer().size()-1 ; ++i) {
        if (this->_vectorKmerFreq[i].getKmer() == kmer.toString()) {
            resultado=i;
            i=finalPos;
        }
    }
    return resultado;
}

std::string Profile::toString(){
    string resultado;
    
    resultado= this->_profileId + "\n" + this->_size + "\n";
            for(int i=0; i<this->_size; i++){
                resultado += _vectorKmerFreq[i].toString(); + " ";
            }
            
}

void Profile::sort(){
    for(int i=0; i<this->_size-1; i++){
        if(this->_vectorKmerFreq[i].getFrequency()<_vectorKmerFreq[i+1].getFrequency()){
            swap(&_vectorKmerFreq[i], _size, i, i+1);
        }
    }
}
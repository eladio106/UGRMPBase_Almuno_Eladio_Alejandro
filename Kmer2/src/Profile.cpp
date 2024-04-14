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
        if (this->_vectorKmerFreq[i].getKmer().toString() == kmer.toString()) {
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
            i=this->_vectorKmerFreq[0].getKmer().size()-1;
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

void Profile::save(const char &fileName[]) const{
    
    ofstream file(fileName[]);
    
    if(!file.is_open)
        throw std::ios_base::failure
    
    fileName[0]<< this->_profileId;
    
    for(int i=1; i<=this->_size;i++){
        
        fileName[i] << _vectorKmerFreq[i-1];
    }
    
    file.close();
}


void Profile::load(char &fileName[]){
    
    ifstream file(fileName[]);
    
    if(!file.is_open)
        throw std::ios_base::failure;
                
    if(_size>fileName[] || fileName[]<0){
        throw out_of_range(string("Profile(int _size): invalid capacity"));
    }
    
    if (fileName != MAGIC_STRING_T){
        throw invalid_argument(string("Profile(string MAGIC_STRING_T): invalid magic string"));
    }
    
    
    getline(fileName[0], _profileId);
    
    for(int i=1; i<this->_size;i++){
        
        getline(fileName[i],_vectorKmerFreq[i-1]);
    }
    
    file.close();
}

void Profile::normalize(string validNucleotides){
    
    for(int i=0; i<_size; i++){
        for(int j=0; j<_vectorKmerFreq[i].getKmer().size();j++){
            _vectorKmerFreq[i].getKmer().toUpper();
            if(! IsValidNucleotide(_vectorKmerFreq[i].getKmer().at(j),validNucleotides)){
                _vectorKmerFreq[i].getKmer().at(j) = _vectorKmerFreq[i].getKmer().MISSING_NUCLEOTIDE;
            }    
        }
    }
    
    for(int i=0; i<_size; i++){//Compara si hay Kmers iguales
        for(int j= i+1; j<_size; j++){
            if(_vectorKmerFreq[i].getKmer().toString() == _vectorKmerFreq[i].getKmer().toString()){
                _vectorKmerFreq[i].setFrequency(_vectorKmerFreq[i].getFrequency() + _vectorKmerFreq[j].getFrequency());
                deletePos(j);
            }
        }
    }    
}

void Profile::deletePos(int pos){
    
    for(int i=pos; i<_size-1; i++){
        _vectorKmerFreq[i]=_vectorKmerFreq[i+1];
    }
    _vectorKmerFreq[nElements-1].setFrequency(0);
    _vectorKmerFreq[_size-1].setKmer(_vectorKmerFreq[_size-1].getKmer().MISSING_NUCLEOTIDE);
    _size--;
}

void Profile::zip(bool deleteMissing=false, int lowerBound=0){
    
    
    for(int i=0; i<_size-1; i++){
        if(_vectorKmerFreq[i].getFrequency()== lowerBound) deleteMissing=true;
        for(int j=0; j<_vectorKmerFreq[i].getKmer().size(); j++){
            if(_vectorKmerFreq[i].getKmer().at(j)== _vectorKmerFreq[i].getKmer().MISSING_NUCLEOTIDE) deleteMissing=true;
        }
        
        if(deleteMissing){
            for(int k=i; k<_size-1; k++){
                _vectorKmerFreq[k]=_vectorKmerFreq[k+1];
            }      
            
            _vectorKmerFreq[_size-1].setFrequency(0);
            _vectorKmerFreq[_size-1].setKmer(_vectorKmerFreq[_size-1].getKmer().MISSING_NUCLEOTIDE);
            _size--;
            
            deleteMissing=false;
        }
    }
    
}
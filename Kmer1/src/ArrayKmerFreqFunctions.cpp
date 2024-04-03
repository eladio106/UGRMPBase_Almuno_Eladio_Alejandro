/*
 * Metodología de la Programación: Kmer1
 * Curso 2023/2024
 */

/** 
 * @file ArrayKmerFreqFunctions.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 27 October 2023, 12:00
 */


#include "ArrayKmerFreqFunctions.h"


/**
 * @brief Reads the number of used elements and the elements of an array of
 * KmerFreq
 * @param array An array where the elements will be stored. Output parameter
 * @param dim The capacity of the array. Input parameter
 * @param nElements The number of elements used by the array. Note that this
 * integer could be modified in this function. Output parameter
*/
void ReadArrayKmerFreq(KmerFreq array[], const int dim, int nElements){
    
    if(nElements>dim) nElements=dim;
    if(nElements<0) nElements=0;
    
    for(int i=0; i<nElements; i++){
        array[i].getKmer();
        array[i].getFrequency();
    }
}

void PrintArrayKmerFreq(KmerFreq array[], int nElements){
    
    for(int i=0; i<nElements; i++){
        cout<<nElements<<"  ";
        for(int j=0; j<array[i].getKmer().size(); j++){
            cout<<array[j].getKmer().toString();
        }
    }            
}

void SwapElementsArrayKmerFreq(KmerFreq array[], int nElements, int first,
                int second){
    swap(array[first], array[second]);
}

int FindKmerInArrayKmerFreq(KmerFreq array[], Kmer kmer,
        int initialPos, int finalPos){
    int resultado=-1;
    for (int i = initialPos; i <= finalPos; ++i) {
        if (array[i].getKmer().toString() == kmer.toString()) {
            resultado=i;
        }
    }
    return resultado;
}

void SortArrayKmerFreq(KmerFreq array[], int nElements){
    for(int i=0; i<nElements-1; i++){
        if(array[i].getFrequency()<array[i+1].getFrequency()){
            SwapElementsArrayKmerFreq(&array[i], nElements, i, i+1);
        }
    }
}

void NormalizeArrayKmerFreq(KmerFreq array[], int nElements, 
        std::string validNucleotides){
    
    for(int i=0; i<nElements; i++){
        for(int j=0; j<array[i].getKmer().size();j++){
            array[i].getKmer().toUpper();
            if(! IsValidNucleotide(array[i].getKmer().at(j),validNucleotides)){
                array[i].getKmer().at(j) = array[i].getKmer().MISSING_NUCLEOTIDE;
            }    
        }
    }
    
    for(int i=0; i<nElements; i++){//Compara si hay Kmers iguales
        for(int j= i+1; j<nElements; j++){
            if(array[i].getKmer().toString() == array[j].getKmer().toString()){
                array[i].setFrequency(array[i].getFrequency() + array[j].getFrequency());
                DeletePosArrayKmerFreq(&array[i], nElements, j);
            }
        }
    }
}

void DeletePosArrayKmerFreq(KmerFreq array[], int nElements, int pos){
    
    for(int i=pos; i<nElements-1; i++){
        array[i]=array[i+1];
    }
    array[nElements-1].setFrequency(0);
    array[nElements-1].setKmer(array[nElements-1].getKmer().MISSING_NUCLEOTIDE);
    nElements--;
}



void ZipArrayKmerFreq(KmerFreq array[], int nElements, 
        bool deleteMissing, int lowerBound){
    
    
    for(int i=0; i<nElements-1; i++){
        if(array[i].getFrequency()== lowerBound) deleteMissing=true;
        for(int j=0; j<array[i].getKmer().size(); j++){
            if(array[i].getKmer().at(j)== array[i].getKmer().MISSING_NUCLEOTIDE) deleteMissing=true;
        }
        
        if(deleteMissing){
            for(int k=i; k<nElements-1; k++){
                array[k]=array[k+1];
            }      
            
            array[nElements-1].setFrequency(0);
            array[nElements-1].setKmer(array[nElements-1].getKmer().MISSING_NUCLEOTIDE);
            nElements--;
            
            deleteMissing=false;
        }
    }
    
}
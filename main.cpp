//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923
//                                                             //
//-------------------------------------------------------------//

#include <iostream>
#include "SparseMatrix.h"
#include <fstream>
#include <vector>

int main(){
    SparseMatrix *matriz = new SparseMatrix(5, 5);
    
    matriz->insert(1, 1, 13.5);
    matriz->insert(2, 4, 0);
    matriz->insert(5, 3, 13.5);
    matriz->insert(5,3, 13.5);
}
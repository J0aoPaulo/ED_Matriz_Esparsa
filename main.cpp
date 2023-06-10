//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923             //
//                                                             //
//-------------------------------------------------------------//

#include <iostream>
#include "SparseMatrix.h"
#include <fstream>
#include <vector>

SparseMatrix* readSparseMatrix(const std::string& arquivo_matrix) {
   std::ifstream input_arquivo(arquivo_matrix);

   if(!input_arquivo.is_open()) {
      std::cout << "Erro ao abrir o arquivo de entrada, tente novamente." << std::endl;
      return nullptr;
   }

   int numLin, numCol;
   input_arquivo >> numLin >> numCol;

   SparseMatrix* read_matrix = new SparseMatrix(numLin, numCol);

   int lin, col;
   double value;
   while (input_arquivo >> lin >> col >> value) {
      read_matrix->insert(lin, col, value);
   }
   
   input_arquivo.close();

   return read_matrix;
}

SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B) {
   SparseMatrix* sumMatrix = new SparseMatrix(A->getLin(), A->getCol());

   if(A->getLin() == B->getLin() && A->getCol() == B->getCol()) {
      for (int i = 1; i <= A->getLin(); i++) {
         for (int j = 1; j <= B->getCol(); j++) {
            sumMatrix->insert(i, j, A->get(i, j) + B->get(i, j));
         }
      }
   } else {
      std::cout << "*Nao eh permitido a soma de duas matrizes de tamanhos diferentes*";
      std::cout << "Dica: Se voce tentar somar duas matrizes esparsas de tamanhos diferentes, nao havera uma correspondencia exata entre os elementos das matrizes. As dimensoes diferentes implicam que nao ha elementos correspondentes em todas as posicoes. Portanto, a operacao de soma nao faz sentido nesse contexto.";
      return nullptr;
   }
   return sumMatrix;
}

std::string matrixExist(std::vector<SparseMatrix*> vector_matrix) {
   if(vector_matrix.empty()) {
      throw std::runtime_error("\n*Nao foi encontrada nenhuma matriz para ser manipulada.*");
   }
   return "\n--- Verificando se matriz existe... ---\n\n--- Matriz verificada e existente! ---\n";
}

int main() {
   // desalocar endereços de memoria
   // complexidade relatorio insert
   std::vector<SparseMatrix*> vec_matrix;
   std::string arquivo_matriz = "matrix.txt";
   int it = 0; // pode melhorar 
   
   int resposta;
   while (resposta != 4) {
      std::cout << "\n ------ Menu de criacao e manipulacao de Matriz Esparsa ------\n";
      std::cout << "\n ----- Selecione uma das alternativas abaixo -----\n";
      std::cout << "1. Criar uma matriz.\n";
      std::cout << "2. Inserir elementos na sua matriz.\n";
      std::cout << "3. Imprimir matriz(es).\n";
      std::cout << "4. Somar matrizes.\n";
      std::cout << "5. Multiplicar matrizes. *em andamento*\n";
      std::cout << "6. Sair. *digite 5 para sair*\n";
      std::cout << "digite sua resposta: ";
      std::cin >> resposta;

      switch (resposta) {
         case 1: {
            int numLin, numCol;
            cout << "\nInforme o numero de linhas da sua matriz: ";
            cin >> numLin;
            cout << "Agora informe o numero de colunas da sua matriz: ";
            cin >> numCol;

            if(numLin == 0 || numCol == 0) {
               cout << "\n-- Matriz invalida, por favor tente novamente. --\n";
               cout << "\nDica: A definicao de uma matriz requer pelo menos uma linha e uma coluna para ter algum tipo de conteudo. Uma matriz sem elementos nao faz sentido, pois nao existem dados para armazenar ou acessar.\n";
               break;
            }
            SparseMatrix *sparseMatrix = new SparseMatrix(numLin, numCol);
            vec_matrix.push_back(sparseMatrix);

            cout << "\n--- Matriz criada com sucesso! ---\n";
            break;
         }
         case 2: {
            try { // captura de exceção
               std::cout << matrixExist(vec_matrix);
            } catch(const std::runtime_error& e) {
               std::cout << e.what() << std::endl; // descricao da exceção
               break; // Interrompe o case 3 se a matriz não existir
            }

            int lin, col;
            double value;
            std::cout << "\nDigite a linha que voce ira inserir: ";
            cin >> lin;
            std::cout << "Digite a coluna que voce ira inserir: ";
            std::cin >> col;
            std::cout << "Digite o valor que voce quer inserir na sua matriz: ";
            std::cin >> value;
            vec_matrix[it]->insert(lin, col, value);
            std::cout << "\n--- Elementos inseridos com sucesso na matriz! ---\n";
            it++; // pode ser melhorado || quebra galho
            break;
         }
         case 3: {
            try { // captura de exceção
               std::cout << matrixExist(vec_matrix);
            } catch(const std::runtime_error& e) {
               std::cout << e.what() << std::endl; // descricao da exceção
               break; // Interrompe o case 3 se a matriz não existir
            }

            int x; // variavel com nome fodase,sera mudada depois
            cout << "\nVoce deseja imprimir somente uma matriz ou todas?\n";
            cout << "1. Imprima somente uma.\n";
            cout << "2. Imprima todas as matrizes disponiveis.\n";
            cout << "3. Voltar para o menu.\n";
            cout << "digite sua resposta: ";
            cin >> x;

            if(x == 1) {
               int escolha;
               cout << "Qual matriz voce deseja imprimir? (escolha por ordem de criacao)\n";
               cout << "Matriz: ";
               cin >> escolha;

               if(escolha >= 0 && escolha <= vec_matrix.size()) {
                  // Escolha é diminuida em 1 para entrar nos padroes de indice do vector.
                  escolha--; 
                  std::cout << "\n";
                  vec_matrix[escolha]->print();
               } else {
                  std::cout << "*Matriz invalida ou inexistente.*\n";
               }
               break;
            } else if(x == 2) { 
               std::cout << "\n";
               for (auto &&matrix : vec_matrix) {
                  matrix->print();
                  std::cout << "\n";
               }
               break;
            } else 
               break;
         }
         case 4: {
            try { // captura de exceção
               std::cout << matrixExist(vec_matrix);
            } catch(const std::runtime_error& e) {
               std::cout << e.what() << std::endl; // descricao da exceção
               break; // Interrompe o case 3 se a matriz não existir
            }

            int indexM1, indexM2;
            std::cout << "\n--- Escolha as matrizes que deseja somar ---\n";
            std::cout << "Matriz 01: ";
            cin >> indexM1;
            indexM1--;
            std::cout << "\nMatriz 02: ";
            std::cin >> indexM2;
            indexM2--;
            SparseMatrix* matrizSomada = sum(vec_matrix[indexM1], vec_matrix[indexM2]);
            if(matrizSomada != nullptr) {
               std::cout << "\n";
               matrizSomada->print();
            }
         }
         case 5: {
            break;
         }
      }
   }
}
// SparseMatrix* matrizLida = readSparseMatrix("matrix.txt");
            // matrizLida->print();
            // break;

#include <iostream>
#include "MatrixFactory.h"

int main() {
    int n;
    std::cout << "inserisci numero di matrici (una o due)" << std::endl;
    std::cin >> n;
    if (n != 1 && n != 2) {
        std::cout << "tipo non corretto" << std::endl;
        std::cerr << std::endl;
    } else if (n == 1) {
        int num;
        int num1;
        std::string tipo;
        std::cout << "int o float" << std::endl;
        std::cin >> tipo;
        if (tipo.compare("int") != 00 && tipo.compare("float") != 00) {
            std::cout << "tipo non corretto" << std::endl;
            std::cerr << std::endl;
        } else {
            std::cout << "inserisci righe" << std::endl;
            std::cin >> num;
            std::cout << "inserisci colonne" << std::endl;
            std::cin >> num1;
            if (tipo.compare("int") == 00) {
                MatrixFactory *factory_0 = new MatrixFactory();
                MatrixTemplate<int> *matrix_0 = factory_0->creatematrix(num, num1);
                int x = 0;
                int y = 0;
                while (x < num) {
                    while (y < num1) {
                        std::cout << "inserisci numero" << std::endl;
                        int m;
                        std::cin >> m;
                        matrix_0->insert(m, x, y);
                        y++;
                    }
                    y = 0;
                    x++;
                }
                matrix_0->print();
                std::string stringa;
                std::cout << "trasposta,selezione" << std::endl;
                std::cin >> stringa;
                if (stringa.compare("trasposta") == 00) {
                    matrix_0->trasposta();
                } else if (stringa.compare("selezione") == 00) {
                    std::cout << "seleziona riga" << std::endl;
                    int s;
                    std::cin >> s;
                    std::cout << "seleziona colonna" << std::endl;
                    int p;
                    std::cin >> p;
                    matrix_0->selection(matrix_0, s, p);
                } else {
                    std::cout << "non in menù" << std::endl;
                    std::cerr << std::endl;
                }
            } else if (tipo.compare("float") == 00) {
                MatrixFactory *factory_0 = new MatrixFactory();
                MatrixTemplate<float> *matrix_0 = factory_0->creatematrix1(num, num1);
                int x = 0;
                int y = 0;
                while (x < num) {
                    while (y < num1) {
                        std::cout << "inserisci numero" << std::endl;
                        float m;
                        std::cin >> m;
                        matrix_0->insert(m, x, y);
                        y++;
                    }
                    y = 0;
                    x++;
                }
                matrix_0->print();
                std::cout << "trasposta,selezione " << std::endl;
                std::string stringa1;
                std::cin >> stringa1;
                if (stringa1.compare("trasposta") == 00) {
                    matrix_0->trasposta();
                } else if (stringa1.compare("selezione ") == 00) {
                    std::cout << "seleziona riga" << std::endl;
                    int s;
                    std::cin >> s;
                    std::cout << "seleziona colonna" << std::endl;
                    int p;
                    std::cin >> p;
                    matrix_0->selection( s, p);
                } else {
                    std::cout << "non in menù" << std::endl;
                    std::cerr << std::endl;
                }

            }
        }
    } else if (n == 2) {
        int num;
        int num1;
        int num2;
        int num3;
        std::string tipo;
        std::cout << "int o float" << std::endl;
        std::cin >> tipo;
        if (tipo.compare("int") != 00 && tipo.compare("float") != 00) {
            std::cout << "tipo non corretto" << std::endl;
            std::cerr << std::endl;
        } else {
            std::cout << "inserisci righe prima matrice" << std::endl;
            std::cin >> num;
            std::cout << "inserisci righe seconda matrice" << std::endl;
            std::cin >> num1;
            std::cout << "inserisci colonne prima matrice" << std::endl;
            std::cin >> num2;
            std::cout << "inserisci colonne seconda matrice" << std::endl;
            std::cin >> num3;
            if (tipo.compare("int") == 00) {
                MatrixFactory *factory_1 = new MatrixFactory();
                MatrixTemplate<int> *matrix_1 = factory_1->creatematrix(num, num2);
                MatrixFactory *factory_2 = new MatrixFactory();
                MatrixTemplate<int> *matrix_2 = factory_2->creatematrix(num1, num3);
                int x = 0;
                int y = 0;
                while (x < num) {
                    while (y < num2) {
                        std::cout << "inserisci numero" << std::endl;
                        int m;
                        std::cin >> m;
                        matrix_1->insert(m, x, y);
                        y++;
                    }
                    y = 0;
                    x++;
                }
                matrix_1->print();
                int z = 0;
                int w = 0;
                while (z < num1) {
                    while (w < num3) {
                        std::cout << "inserisci numero" << std::endl;
                        int m;
                        std::cin >> m;
                        matrix_2->insert(m, z, w);
                        w++;
                    }
                    w = 0;
                    z++;
                }
                matrix_2->print();
                std::cout << "traspostauno,traspostadue,prodotto,selezioneuno,selezionedue" << std::endl;
                std::string stringa;
                std::cin >> stringa;
                if (stringa.compare("traspostauno") == 00) {
                    matrix_1->trasposta();
                } else if (stringa.compare("traspostadue") == 00) {
                    matrix_2->trasposta();
                } else if (stringa.compare("selezioneuno") == 00) {
                    std::cout << "seleziona riga" << std::endl;
                    int s;
                    std::cin >> s;
                    std::cout << "seleziona colonna" << std::endl;
                    int p;
                    std::cin >> p;
                    matrix_1->selection( s, p);
                } else if (stringa.compare("selezionedue") == 00) {
                    std::cout << "seleziona riga" << std::endl;
                    int s;
                    std::cin >> s;
                    std::cout << "seleziona colonna" << std::endl;
                    int p;
                    std::cin >> p;
                    matrix_2->selection( s, p);
                } else if (stringa.compare("prodotto") == 00) {
                    matrix_1->product( matrix_2);
                } else {
                    std::cout << "non in menù" << std::endl;
                    std::cerr << std::endl;
                }

            } else if (tipo.compare("float") == 00) {
                MatrixFactory *factory_1 = new MatrixFactory();
                MatrixTemplate<float> *matrix_1 = factory_1->creatematrix1(num, num2);
                MatrixFactory *factory_2 = new MatrixFactory();
                MatrixTemplate<float> *matrix_2 = factory_2->creatematrix1(num1, num3);
                int z = 0;
                int w = 0;
                while (z < num) {
                    while (w < num2) {
                        std::cout << "inserisci numero" << std::endl;
                        float m;
                        std::cin >> m;
                        matrix_1->insert(m, z, w);
                        w++;
                    }
                    w = 0;
                    z++;
                }
                matrix_1->print();
                int x = 0;
                int y = 0;
                while (x < num1) {
                    while (y < num3) {
                        std::cout << "inserisci numero" << std::endl;
                        float m;
                        std::cin >> m;
                        matrix_2->insert(m, x, y);
                        y++;
                    }
                    y = 0;
                    x++;
                }
                matrix_2->print();
                std::cout << "traspostauno,traspostadue,prodotto,selezioneuno,selezionedue" << std::endl;
                std::string stringa1;
                std::cin >> stringa1;
                if (stringa1.compare("traspostauno") == 00) {
                    matrix_1->trasposta();
                } else if (stringa1.compare("traspostadue") == 00) {
                    matrix_2->trasposta();
                } else if (stringa1.compare("selezioneuno") == 00) {
                    std::cout << "seleziona riga" << std::endl;
                    int s;
                    std::cin >> s;
                    std::cout << "seleziona colonna" << std::endl;
                    int p;
                    std::cin >> p;
                    matrix_1->selection( s, p);
                } else if (stringa1.compare("selezionedue") == 00) {
                    std::cout << "seleziona riga" << std::endl;
                    int s;
                    std::cin >> s;
                    std::cout << "seleziona colonna" << std::endl;
                    int p;
                    std::cin >> p;
                    matrix_2->selection( s, p);
                } else if (stringa1.compare("prodotto") == 00) {
                    matrix_1->product( matrix_2);
                } else {
                    std::cout << "non in menù" << std::endl;
                    std::cerr << std::endl;
                }

            }
        }
    }

}



#include <iostream>
#include <vector>

/*  Formulae:
        T(n) = n(n+1)/2
        P(n) = n(3n-1)/2
        H(n) = n(2n-1)
    Observation: 
        H(n) = 2T(n)
        T(n) is a subset of H(n), so we can simply look for the case where H(n) = P(k)
        Therefore, we check: 2n(2n-1) = k(3k-1)
*/

using namespace std;

//Practice for C++ Class inheritance

class FunctionFormula {
    public:
        FunctionFormula(int i): n(i) {}; 
        int current = 0;
        int n =0;
        virtual void next() {
        };
};

class Hexagonal : public FunctionFormula {

    public: 
    Hexagonal(int i) : FunctionFormula(i) {current = n*(2*n-1);};
    void next() {
       this->n++;
       this->current = n*(2*n-1);
    }
};

class Pentagonal : public FunctionFormula {
   public:
    Pentagonal(int i) : FunctionFormula(i) {current = n*(3*n-1)/2;};
    void next() {
       this->n++;
       this->current = n*(3*n-1)/2;
    }
};

int solve() {
    int n = 166;
    int k = 144;
    int val =  0;
    while(true) {
        val = ((2*n*(2*n-1)) - (k*(3*k-1)));
        if(val < 0) {
            ++n;
        } else if (val > 0) {
            ++k;
        } else {
            return (n*(2*n-1));
        }
    }
    return 0;
}


int main() {
    cout << solve() << endl;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            // marking as false
            for (int i = p * p; i <= n; i += p){
                prime[i] = false;
            }
        }
    }
    
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    
    vector<int> res = sieve(n);
    for(auto ele : res){
        cout << ele << ' ';
    }
    return 0;
}

/*
  The Sieve of Eratosthenes efficiently finds all primes up to n by repeatedly marking multiples of each prime as non-prime, starting from 2. 
  This avoids redundant checks and quickly filters out all composite numbers.

  Step By Step Implementations:
    Initialize a Boolean array prime[0..n] and set all entries to true, except for 0 and 1 (which are not primes).
    Start from 2, the smallest prime number.
    For each number p from 2 up to √n:
       -> If p is marked as prime(true):
       -> Mark all multiples of p as not prime(false), starting from p * p (since smaller multiples have already been marked by smaller primes).
    After the loop ends, all the remaining true entries in prime represent prime numbers.

    Time Complexity : O(n*log(log(n))). For each prime number, we mark its multiples, which takes around n/p steps. 
                                        The total time is proportional to n*(1/2 + 1/3 + 1/5 + ....).
    This sum over primes grows slowly and is approximately O(n*log(log(n))) making the algorithm very efficient.
    Auxiliary Space : O(n)
*/
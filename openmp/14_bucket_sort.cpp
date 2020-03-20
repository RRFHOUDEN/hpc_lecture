#include <iostream>
#include <cstdlib>

int main() {
  int n = 50;
  int range = 5;
  int *key = new int [n];
  for (int i=0; i<n; i++) {
    key[i] = rand() % range;
    std::cout << key[i] << " ";
  }
  std::cout << std::endl;              

  int *bucket = new int [range];
  for (int i=0; i<range; i++) {
    bucket[i] = 0;
  }
  for (int i=0; i<n; i++) {
    bucket[key[i]]++;
  }
  for (int i=0, j=0; i<range; i++) {
    for (; bucket[i]>0; bucket[i]--) {
      key[j++] = i;
    }
  }

  for (int i=0; i<n; i++) {
    std::cout << key[i] << " ";
  }
  std::cout << std::endl;
  delete[] bucket;
  delete[] key;
}

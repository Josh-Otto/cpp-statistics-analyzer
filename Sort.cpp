#include "sort.h"
#include <algorithm> // for std::swap

using namespace std;

// Hoare's Algorithm
// ------------------ SORTING METHOD ------------------ 
void quickSort(vector<double>& numbers,int one,int two)
{
      if(one >= two) return;

      double pivot = numbers[(one + two) / 2]; // integer division (makes sure the interator exists)
      int a = one; //interator one
      int b = two; //interator two

      while(a <= b)
      {
            while(numbers[a] < pivot) a++; // starts left
            while(numbers[b] > pivot) b--; // starts right

            if(a <= b) // if both interators are in the right positions: SWAP
            {
                  swap(numbers[a],numbers[b]);
                  a++;
                  b--;
            }
      }

      // RECURSIVE
      quickSort(numbers,one,b);
      quickSort(numbers,a,two);
}
// There are some processes that need to be executed. Amount of a load that process causes on a server that runs it, is being represented by a single integer. Total load caused on a server is the sum of the loads of all the processes that run on that server. You have at your disposal two servers, on which mentioned processes can be run. Your goal is to distribute given processes between those two servers in the way that, absolute difference of their loads will be minimized.

// Write a function that, given an array A of N integers, of which represents loads caused by successive processes, the function should return the minimum absolute difference of server loads.

// For example, given array A such that:
//   A[0] = 1
//   A[1] = 2
//   A[2] = 3
//   A[3] = 4
//   A[4] = 5

// your function should return 1. We can distribute the processes with loads 1, 2, 4 to the first server and 3, 5 to the second one, so that their total loads will be 7 and 8, respectively, and the difference of their loads will be equal to 1.

// Assume that:
// N is an integer within the range [1..1,000]
// the sum of the elements of array A does not exceed 100,000

// In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.


#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A)
{
  // Put your solution here
  cerr << "Tip: Use cerr to write debug messages on the output tab.";
  
  sort(A.begin(), A.end());
  
  int a = 0, b = 0;
  for(int i = A.size()-1; i >= 0; i--){
    if(b > a) a += A[i];
    else b += A[i];
  }
  
  return abs(a-b);
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  cout << solution(toIntVector(AS));
}

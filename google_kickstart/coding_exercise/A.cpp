// You are given an array A representing heights of students. All the students are asked to stand in rows. The students arrive by one, sequentially (as their heights appear in A). For the i-th student, if there is a row in which all the students are taller than A[i], the student will stand in one of such rows. If there is no such row, the student will create a new row. Your task is to find the minimum number of rows created.

// Write a function that, given a non-empty array A containing N integers, denoting the heights of the students, returns the minimum number of rows created.

// For example, given A = [5, 4, 3, 6, 1], the function should return 2.
// Students will arrive in sequential order from A[0] to A[N−1]. So, the first student will have height = 5, the second student will have height = 4, and so on.

// For the first student, there is no row, so the student will create a new row.
// Row1 = [5]
// For the second student, all the students in Row1 have height greater than 4. So, the student will stand in Row1.
// Row1 = [5, 4]
// Similarly, for the third student, all the students in Row1 have height greater than 3. So, the student will stand in Row1.
// Row1 = [5, 4, 3]
// For the fourth student, there is no row in which all the students have height greater than 6. So, the student will create a new row.
// Row1 = [5, 4, 3]
// Row2 = [6]
// For the fifth student, all the students in Row1 and Row2 have height greater than 1. So, the student can stand in either of the two rows.
// Row1 = [5, 4, 3, 1]
// Row2 = [6]
// Since two rows are created, the function should return 2.
// Assume that:

// N is an integer within the range [1..1,000]
// each element of array A is an integer within the range [1..10,000]
// In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment


#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A)
{
  // Your solution goes here.
  int max = -1;
  int row = 0;
  for(int i = 0; i < A.size(); i++){
    if(A[i] > max) { 
      row++;
      max = A[i];
    }
  }
  return row; 
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
  vector<int> A = toIntVector(AS);
  cout << solution(A);
}

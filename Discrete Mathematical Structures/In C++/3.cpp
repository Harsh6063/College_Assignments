#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements in a vector
void swap(vector<int>& nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

// Function to generate all permutations with repetition
void generatePermutationsWithRepetition(vector<int>& nums, vector<int>& perm, int length) {
  // If permutation is complete, print it
  if (perm.size() == length) {
    for (int num : perm) {
      cout << num << " ";
    }
    cout << endl;
    return;
  }

  // Generate permutations recursively
  for (int i = 0; i < nums.size(); i++) {
    perm.push_back(nums[i]);
    generatePermutationsWithRepetition(nums, perm, length);
    perm.pop_back();
  }
}

// Function to generate all permutations without repetition
void generatePermutationsWithoutRepetition(vector<int>& nums, vector<int>& perm, vector<bool>& used) {
  // If permutation is complete, print it
  if (perm.size() == nums.size()) {
    for (int num : perm) {
      cout << num << " ";
    }
    cout << endl;
    return;
  }

  // Generate permutations recursively
  for (int i = 0; i < nums.size(); i++) {
    if (!used[i]) {
      used[i] = true;
      perm.push_back(nums[i]);
      generatePermutationsWithoutRepetition(nums, perm, used);
      perm.pop_back();
      used[i] = false;
    }
  }
}

// Function to generate all permutations (with or without repetition)
void generatePermutations(vector<int>& nums, bool withRepetition) {
  vector<int> perm;
  vector<bool> used(nums.size(), false);

  if (withRepetition) {
    // Generate permutations with repetition
    generatePermutationsWithRepetition(nums, perm, nums.size());
  } else {
    // Generate permutations without repetition
    generatePermutationsWithoutRepetition(nums, perm, used);
  }
}

int main() {
  // Create a vector of numbers
  vector<int> nums = {1, 2, 3};

  // Generate and print all permutations with repetition
  cout << "Permutations with repetition:" << endl;
  generatePermutations(nums, true);

  // Generate and print all permutations without repetition
  cout << "Permutations without repetition:" << endl;
  generatePermutations(nums, false);

  return 0;
}

// 2559. Count Vowel Strings in Ranges

/*You are given a 0-indexed array of strings words and a 2D array of integers queries.
Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
*/

/*Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

*/

// Approach: Store count till each string and return score[r]-score[l]

#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

vector<int> vowel(vector<string> words, vector<vector<int>> queries) {
    // this function returns which string starts and ends with a vowel
    for(int i=0; i<words.size(); i++) {
        if(words[i][words[i].begin()]=='a' )
    }
}
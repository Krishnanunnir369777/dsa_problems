#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool func1(string s, string goal) {               //O(n^2)
        if (s.length() != goal.length()) return false;
        int length = s.length();

        // Try all possible rotations of the string
        for (int rotationCount = 0; rotationCount < length; ++rotationCount) {
            // Perform one rotation
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) return true;
        }
        return false;
}
bool func2(string s, string goal) {               O(n)
        // Check if the lengths are different
        if (s.length() != goal.length()) return false;

        // Create a new string by concatenating 's' with itself
        string doubledString = s + s;

        // Use find to search for 'goal' in 'doubledString'
        // If find returns an index that is less than the
        // length of doubledString, 'goal' is a substring
        return doubledString.find(goal) < doubledString.length();
    }
int main(){
    string s="abcde";
    string goal="cdeab";
    cout<<func1(s,goal);
}
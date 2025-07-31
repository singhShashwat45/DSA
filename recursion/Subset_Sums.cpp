geeksforgeeks
Courses
Tutorials
Practice
Jobs
S
51

Search...



Upgrade to Premium for Doubt Support across all your problems and courses.

Explore Premium
Redirection Icon
Refresh

Time (IST)	Status	Marks	Lang	Test Cases	Code
2024-08-19 11:17:48	Correct	
4
cpp	1115 / 1115	View
C++ (12)



        



Custom Input
class Solution {
  public:
    void func(vector<int> arr, int n, vector<int>&ans, int ind, int sum){
        
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        func(arr, n, ans, ind+1,sum+arr[ind]);

        func(arr, n, ans, ind+1, sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        func(arr,n, ans,0,0);
        return ans;
    }
};
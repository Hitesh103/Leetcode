class Solution {
public:

    void findCombination(int ind,vector<int>& candidates, int target,vector<vector<int>>& ans, vector<int>& ds){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        // Pick the element
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            findCombination(ind,candidates,target-candidates[ind],ans,ds);
            ds.pop_back();
        }

        // Not pick the element
        findCombination(ind+1,candidates,target,ans,ds);

        }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,candidates,target,ans,ds);
        return ans;
    }
};
class Solution {
public:
    vector<int> pivotArray(vector<int>& n, int pivot) {
            
        vector<int>left,right;
        int freq=0;
        for(int i=0;i<n.size();i++)
        {
            if(n[i]<pivot)
                left.push_back(n[i]);
            else if(n[i]>pivot)
                right.push_back(n[i]);
            else
                freq++;
        }
        for(int i=0;i<freq;i++)
            left.push_back(pivot);
        
        for(int i=0;i<right.size();i++)
            left.push_back(right[i]);
        return left;
    
    
    }
    
};
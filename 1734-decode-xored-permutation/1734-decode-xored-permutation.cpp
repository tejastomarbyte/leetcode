class Solution {
public:
    int xorallel(int n) // XOR of all elements from 1 to N 
    { 
        switch (n & 3) 
        { 
            case 0: 
                return n; 
            case 1: 
                return 1; 
            case 2: 
                return n + 1; 
            case 3: 
                return 0; 
        } 
        return 0;
    }
    vector<int> decode(vector<int>& encoded) {
          vector<int> arr; 
        int n = encoded.size() + 1;
        int xor_all = xorallel(n); 
        int xor_adjacent = 0; 

        for (int i = 0; i < n - 1; i += 2) { 
            xor_adjacent = xor_adjacent ^ encoded[i]; 
        } 
        int last_element = xor_all ^ xor_adjacent; 
        arr.push_back(last_element); 

        for (int i = n - 2; i >= 0; i--) { 
            last_element = encoded[i] ^ last_element; 
            arr.push_back(last_element); 
        } 

        return vector<int>(arr.rbegin(), arr.rend()); 
    }
    
};
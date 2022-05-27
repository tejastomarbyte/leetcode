class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1==0 ||num2==0)return 0;
        return countOperations(abs(num1-num2),min(num1,num2))+1;

    }
};
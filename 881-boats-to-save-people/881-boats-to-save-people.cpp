class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size(),cs=0,boats=0;
        int i=0,j=n-1;
        
        while(i<=j){
            boats++;
            
            if(people[i]+people[j]<=limit){
                i++;
            }
            j--;
        }

        return boats;
    }
};
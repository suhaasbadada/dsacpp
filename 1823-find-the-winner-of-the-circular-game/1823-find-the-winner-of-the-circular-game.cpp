class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n,1); // 1 -> alive, 0 -> dead

	int i=0,ptr=0,dead=0;

	if(k==1){
	    return n;
	}

	while(dead!=n-1){

		if(v[i]==1){
			
			i=(i+1)%n;
			ptr++;

			if((ptr+1)%k==0){
				while(v[i]==0){
					i=(i+1)%n;
				}
				v[i]=0;
				ptr=0;
				dead++;
				i=(i+1)%n;
			}
		}else{
			i=(i+1)%n;			
		}
	}
	
	int ind;
	for(i=0;i<n;i++){
	    if(v[i]==1){
	       ind=i+1;
	       break;
	    }
	}
	return ind;
    }
};
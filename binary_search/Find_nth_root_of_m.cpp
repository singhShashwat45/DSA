class Solution {
  public:
    
    int solve(int mid, int n, int m){
	    long long int ans = 1;
	    for(int i=1;i<=n;i++){
	        ans*=mid;
	        if(ans>m) return 2;
	    }
	    if(ans==m) return 1;
	    return 0;
	    
	}
    
    int nthRoot(int n, int m) {
        int low = 1;
        int high = m;
        while(low<= high){
            int mid = low + (high - low) / 2;
            if(1 == solve(mid, n, m)){
                return mid;
            }
            else if(0 == solve(mid, n, m)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
        
    }
};
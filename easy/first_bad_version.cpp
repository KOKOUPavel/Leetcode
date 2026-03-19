class Solution {
public:
    int firstBadVersion(int a) {
        long long int l=1,h=a,m,n;
        while(l<=h){
            m=(l+h)/2;
            if(isBadVersion(m)){
                n=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return n;
    }
};
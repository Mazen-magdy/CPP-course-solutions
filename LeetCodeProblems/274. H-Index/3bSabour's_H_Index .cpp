class Solution {
public:
    int hIndex(vector<int>& citations) {
        std :: sort(citations.begin(),citations.end());
        int i,h=0 , s=citations.size();
        for(i=s-1 ;i>=0;i--)
        {
            if(citations[i]>h)          // بندور على اكبر عدد من الابحاث اتقبل على الاقل    
            h++;                        //     نفس العدد ده مرة
        }                               
        return h; 
    }
};
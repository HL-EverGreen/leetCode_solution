class Solution {
public:
    string multiply(string num1, string num2) { //multiply
        int n1_size=num1.size(), n2_size=num2.size();
        string sum(n1_size+n2_size,'0');
        
        for(int i=n1_size-1;i>=0;i--){
            int carry=0;
            for(int j=n2_size-1;j>=0;j--){
                int tmp=(sum[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
                sum[i+j+1]=tmp%10+'0';
                carry=tmp/10;
            }
            sum[i]=carry+'0';
        }
        for(int i=0;i<n1_size+n2_size;i++)
            if(sum[i]!='0') return sum.substr(i);
        return "0";
    }
};
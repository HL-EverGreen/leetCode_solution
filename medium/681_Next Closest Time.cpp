class Solution {
public:
    int scale[4]={600,60,10,1};
    string nextClosestTime(string time) { //string
        size_t pos=time.find(':');
        int cur_time=stoi(time.substr(0,pos))*60+stoi(time.substr(pos+1));
        string res="0000";
        for(int i=1,digit=0;i<=1440 && digit<4;i++){
            int nor_time=(cur_time+i)%1440;
            for(digit=0;digit<4;digit++){
                res[digit]='0'+nor_time/scale[digit];
                nor_time%=scale[digit];
                if(time.find(res[digit])==string::npos) break;
            }
        }
        return res.substr(0,2)+':'+res.substr(2,2);
    }
};
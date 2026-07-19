class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> time(speed.size(),0);
        vector<pair<int,float>> fl;
        for(int i=0;i<speed.size();i++){
            time[i]=(float)(target-position[i])/speed[i];
            fl.push_back({position[i],time[i]});
        }
        sort(fl.begin(),fl.end());
        int fleet=0;
        float curTime=0;
        for(int i=fl.size()-1;i>=0;i--){
            if(curTime==0){
                curTime=fl[i].second;
                fleet++;
            } else if(curTime<fl[i].second){
                curTime=fl[i].second;
                fleet++;
            }
        }
        return fleet;
    }
};

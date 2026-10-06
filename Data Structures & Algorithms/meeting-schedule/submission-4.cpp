/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0) return true;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start<b.start;
        });
        Interval* curr=new Interval(intervals[0].start, intervals[0].end);
        for(int i=1;i<intervals.size();i++){
            if(curr->end>intervals[i].start){
                return false;
            } else{
                curr=new Interval(intervals[i].start, intervals[i].end);
            }
        }
        return true;
    }
};

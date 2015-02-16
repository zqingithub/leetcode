# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e
import copy
class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        Out=[]
        i=0
        for i in range(0,len(intervals)):
            if intervals[i].start<newInterval.start:
                Out.append(copy.copy(intervals[i]))
            else:
                break
        else:
            if len(intervals)!=0:
                i+=1
        intervals.insert(i,newInterval)
        for k in range(i,len(intervals)):
            if len(Out)==0 or Out[-1].end<intervals[k].start:
                Out.append(copy.copy(intervals[k]))
            else:
                if intervals[k].end>Out[-1].end:
                    Out[-1].end=intervals[k].end
        return Out

print Solution().insert([], Interval(5,7))
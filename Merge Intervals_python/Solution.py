# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e
import copy
class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        intervals.sort(cmp=Solution.Cmp)
        Out=[]
        for temp in intervals:
            if len(Out)==0 or temp.start>Out[-1].end:
                Out.append(copy.copy(temp))
            else:
                if Out[-1].end<temp.end:
                    Out[-1].end=temp.end
        return Out
    @staticmethod
    def Cmp(A,B):
        return A.start-B.start
    
    